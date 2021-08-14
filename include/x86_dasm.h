/*

    This file is part of x86_dasm.

    x86_dasm is a compact x86-64 disassembling library
    
    Copyright 2014 / the`janitor / < email: base64dec(dGhlLmphbml0b3JAcHJvdG9ubWFpbC5jb20=) >

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

*/
#ifndef _DASM_H_
#define _DASM_H_

#include "types.h"
#include "x86_dasm_tables.h"

#include <limits.h>

#ifdef __cplusplus
    extern "C" {
#endif

/* 
    #define X86_DASM_DEBUG      : enable debug output
    #define X86_DASM_NOFMT      : disable all formatting/strings
    #define X86_DASM_NLE        : if not on a little-endian system
*/

#define BIT_MASK(__TYPE__, __ONE_COUNT__) \
    ((__TYPE__) (-((__ONE_COUNT__) != 0))) \
    & (((__TYPE__) -1) >> ((sizeof(__TYPE__) * CHAR_BIT) - (__ONE_COUNT__)))

/****************************************************************************

    x86 registers

****************************************************************************/

enum 
{
    /* 64-bit general-purpose registers */
    X86_REG_RAX = 0,
    X86_REG_RCX,
    X86_REG_RDX,    
    X86_REG_RBX,
    X86_REG_RSP,    
    X86_REG_RBP,    
    X86_REG_RSI,
    X86_REG_RDI,
    X86_REG_R8, 
    X86_REG_R9,     
    X86_REG_R10,    
    X86_REG_R11,
    X86_REG_R12,    
    X86_REG_R13,    
    X86_REG_R14,    
    X86_REG_R15,
    X86_REG_RIP,

    /* 32-bit general-purpose registers */
    X86_REG_EAX,    
    X86_REG_ECX,    
    X86_REG_EDX,    
    X86_REG_EBX,
    X86_REG_ESP,    
    X86_REG_EBP,    
    X86_REG_ESI,    
    X86_REG_EDI,
    X86_REG_R8D,    
    X86_REG_R9D,    
    X86_REG_R10D,
    X86_REG_R11D,
    X86_REG_R12D,   
    X86_REG_R13D,   
    X86_REG_R14D,   
    X86_REG_R15D,
    X86_REG_EIP,

    /* 16-bit general-purpose registers */
    X86_REG_AX,     
    X86_REG_CX,     
    X86_REG_DX,     
    X86_REG_BX,
    X86_REG_SP,     
    X86_REG_BP, 
    X86_REG_SI,     
    X86_REG_DI,
    X86_REG_R8W,    
    X86_REG_R9W,    
    X86_REG_R10W,
    X86_REG_R11W,
    X86_REG_R12W,   
    X86_REG_R13W,   
    X86_REG_R14W,   
    X86_REG_R15W,

    /* 8-bit general-purpose registers */
    X86_REG_AL, 
    X86_REG_CL,     
    X86_REG_DL,     
    X86_REG_BL,
    X86_REG_AH, /* not addressable in REX prefix instruction forms */       
    X86_REG_CH, /* not addressable in REX prefix instruction forms */       
    X86_REG_DH, /* not addressable in REX prefix instruction forms */       
    X86_REG_BH, /* not addressable in REX prefix instruction forms */
    X86_REG_SPL,    /* only addressable in REX prefix instruction forms */  
    X86_REG_BPL,    /* only addressable in REX prefix instruction forms */  
    X86_REG_SIL,    /* only addressable in REX prefix instruction forms */  
    X86_REG_DIL,    /* only addressable in REX prefix instruction forms */
    X86_REG_R8L,    
    X86_REG_R9L,    
    X86_REG_R10L,
    X86_REG_R11L,
    X86_REG_R12L,   
    X86_REG_R13L,   
    X86_REG_R14L,   
    X86_REG_R15L,

    /* segment registers */
    X86_REG_ES, /* ignored in long 64-bit mode */
    X86_REG_CS,
    X86_REG_SS, /* ignored in long 64-bit mode */
    X86_REG_DS, /* ignored in long 64-bit mode */
    X86_REG_FS,
    X86_REG_GS,

    /* FPU x87 registers, FPR0-FPR7 */
    X86_REG_ST0,
    X86_REG_ST1,    
    X86_REG_ST2,    
    X86_REG_ST3,
    X86_REG_ST4,    
    X86_REG_ST5,    
    X86_REG_ST6,    
    X86_REG_ST7, 

    /* MMX registers */
    X86_REG_MM0,    
    X86_REG_MM1,
    X86_REG_MM2,    
    X86_REG_MM3,
    X86_REG_MM4,    
    X86_REG_MM5,    
    X86_REG_MM6,    
    X86_REG_MM7,

    /* XMM registers */
    X86_REG_XMM0,
    X86_REG_XMM1,
    X86_REG_XMM2,   
    X86_REG_XMM3,
    X86_REG_XMM4,
    X86_REG_XMM5,
    X86_REG_XMM6,
    X86_REG_XMM7,
    X86_REG_XMM8,
    X86_REG_XMM9,
    X86_REG_XMM10,
    X86_REG_XMM11,
    X86_REG_XMM12,  
    X86_REG_XMM13,  
    X86_REG_XMM14,  
    X86_REG_XMM15,
    X86_REG_XMM16, /* AVX-512 */
    X86_REG_XMM17, /* AVX-512 */
    X86_REG_XMM18, /* AVX-512 */
    X86_REG_XMM19, /* AVX-512 */
    X86_REG_XMM20, /* AVX-512 */
    X86_REG_XMM21, /* AVX-512 */
    X86_REG_XMM22, /* AVX-512 */
    X86_REG_XMM23, /* AVX-512 */
    X86_REG_XMM24, /* AVX-512 */
    X86_REG_XMM25, /* AVX-512 */
    X86_REG_XMM26, /* AVX-512 */
    X86_REG_XMM27, /* AVX-512 */
    X86_REG_XMM28, /* AVX-512 */
    X86_REG_XMM29, /* AVX-512 */
    X86_REG_XMM30, /* AVX-512 */
    X86_REG_XMM31, /* AVX-512 */

    /* YMM registers */
    X86_REG_YMM0,
    X86_REG_YMM1,
    X86_REG_YMM2,   
    X86_REG_YMM3,
    X86_REG_YMM4,
    X86_REG_YMM5,
    X86_REG_YMM6,
    X86_REG_YMM7,
    X86_REG_YMM8,
    X86_REG_YMM9,
    X86_REG_YMM10,
    X86_REG_YMM11,
    X86_REG_YMM12,  
    X86_REG_YMM13,  
    X86_REG_YMM14,  
    X86_REG_YMM15,
    X86_REG_YMM16, /* AVX-512 */
    X86_REG_YMM17, /* AVX-512 */
    X86_REG_YMM18, /* AVX-512 */
    X86_REG_YMM19, /* AVX-512 */
    X86_REG_YMM20, /* AVX-512 */
    X86_REG_YMM21, /* AVX-512 */
    X86_REG_YMM22, /* AVX-512 */
    X86_REG_YMM23, /* AVX-512 */
    X86_REG_YMM24, /* AVX-512 */
    X86_REG_YMM25, /* AVX-512 */
    X86_REG_YMM26, /* AVX-512 */
    X86_REG_YMM27, /* AVX-512 */
    X86_REG_YMM28, /* AVX-512 */
    X86_REG_YMM29, /* AVX-512 */
    X86_REG_YMM30, /* AVX-512 */
    X86_REG_YMM31, /* AVX-512 */

    /* ZMM registers */
    X86_REG_ZMM0,
    X86_REG_ZMM1,
    X86_REG_ZMM2,   
    X86_REG_ZMM3,
    X86_REG_ZMM4,
    X86_REG_ZMM5,
    X86_REG_ZMM6,
    X86_REG_ZMM7,
    X86_REG_ZMM8,
    X86_REG_ZMM9,
    X86_REG_ZMM10,
    X86_REG_ZMM11,
    X86_REG_ZMM12,  
    X86_REG_ZMM13,  
    X86_REG_ZMM14,  
    X86_REG_ZMM15,
    X86_REG_ZMM16, /* AVX-512 */
    X86_REG_ZMM17, /* AVX-512 */
    X86_REG_ZMM18, /* AVX-512 */
    X86_REG_ZMM19, /* AVX-512 */
    X86_REG_ZMM20, /* AVX-512 */
    X86_REG_ZMM21, /* AVX-512 */
    X86_REG_ZMM22, /* AVX-512 */
    X86_REG_ZMM23, /* AVX-512 */
    X86_REG_ZMM24, /* AVX-512 */
    X86_REG_ZMM25, /* AVX-512 */
    X86_REG_ZMM26, /* AVX-512 */
    X86_REG_ZMM27, /* AVX-512 */
    X86_REG_ZMM28, /* AVX-512 */
    X86_REG_ZMM29, /* AVX-512 */
    X86_REG_ZMM30, /* AVX-512 */
    X86_REG_ZMM31, /* AVX-512 */

    /* debug registers */
    X86_REG_DR0,
    X86_REG_DR1,    
    X86_REG_DR2,    
    X86_REG_DR3,
    X86_REG_DR4,    
    X86_REG_DR5,    
    X86_REG_DR6,
    X86_REG_DR7,
    X86_REG_DR8,    /* reserved: undefined opcode (#UD) exception */    
    X86_REG_DR9,    /* reserved: undefined opcode (#UD) exception */
    X86_REG_DR10,   /* reserved: undefined opcode (#UD) exception */
    X86_REG_DR11,   /* reserved: undefined opcode (#UD) exception */
    X86_REG_DR12,   /* reserved: undefined opcode (#UD) exception */
    X86_REG_DR13,   /* reserved: undefined opcode (#UD) exception */
    X86_REG_DR14,   /* reserved: undefined opcode (#UD) exception */
    X86_REG_DR15,   /* reserved: undefined opcode (#UD) exception */

    /* control registers */
    X86_REG_CR0,    
    X86_REG_CR1,    /* reserved: undefined opcode (#UD) exception */    
    X86_REG_CR2,    
    X86_REG_CR3,
    X86_REG_CR4,    
    X86_REG_CR5,    /* reserved: undefined opcode (#UD) exception */    
    X86_REG_CR6,    /* reserved: undefined opcode (#UD) exception */    
    X86_REG_CR7,    /* reserved: undefined opcode (#UD) exception */
    X86_REG_CR8,
    X86_REG_CR9,    /* reserved: undefined opcode (#UD) exception */
    X86_REG_CR10,   /* reserved: undefined opcode (#UD) exception */
    X86_REG_CR11,   /* reserved: undefined opcode (#UD) exception */
    X86_REG_CR12,   /* reserved: undefined opcode (#UD) exception */     
    X86_REG_CR13,   /* reserved: undefined opcode (#UD) exception */
    X86_REG_CR14,   /* reserved: undefined opcode (#UD) exception */    
    X86_REG_CR15,   /* reserved: undefined opcode (#UD) exception */

    /* used only internally! */
    X86_REG_GPR,
    X86_REG_NONE /* invalid or not present */
};

/****************************************************************************

    x86 instruction sets

****************************************************************************/

enum
{
    X86_ISET_NONE = 0,
    X86_ISET_GP,    /* general-purpose instructions */
    X86_ISET_BMI1,  /* bit manipulation instructions */
    X86_ISET_BMI2,  
    X86_ISET_FPU,   /* floating-point unit (x87 co-processor) instructions */
    X86_ISET_MMX,   /* single instruction, multiple data (SIMD) instructions */
    X86_ISET_SSE,   
    X86_ISET_SSE2,
    X86_ISET_SSE3,  
    X86_ISET_SSSE3,
    X86_ISET_SSE4,  
    X86_ISET_SSE41, 
    X86_ISET_SSE42, 
    X86_ISET_SSE4A, 
    X86_ISET_AESNI, /* advanced encryption standard new instructions */
    X86_ISET_VMX,   /* intel virtual-machine extension instructions */
    X86_ISET_SVM,   /* amd secure virtual machine instructions */
    X86_ISET_FMA,   /* fused multiply add (fma) instructions */
    X86_ISET_FMA4,
    X86_ISET_F16C,
    X86_ISET_PCLMULQDQ,
    X86_ISET_ADX,
    X86_ISET_AVX,   /* advanced vector extension instructions */
    X86_ISET_AVX2,  
    X86_ISET_AVX512,
    X86_ISET_XOP,
    X86_ISET_3DNOW,
    X86_ISET_TSX,
    X86_ISET_CET, /* control-flow enforcement technology */
    X86_ISET_UNKNOWN
};

/****************************************************************************

    x86 mnemonics

****************************************************************************/

enum
{
    X86_MN_INVALID = 0,

    X86_MN_AAA,
    X86_MN_AAD,
    X86_MN_AAM,
    X86_MN_AAS,
    X86_MN_ADC,
    X86_MN_ADCX,
    X86_MN_ADD,
    X86_MN_ADDPD,
    X86_MN_ADDPS,
    X86_MN_ADDSD,
    X86_MN_ADDSS,
    X86_MN_ADDSUBPD,
    X86_MN_ADDSUBPS,
    X86_MN_ADOX,
    X86_MN_ADX,
    X86_MN_AESDEC,
    X86_MN_AESDECLAST,
    X86_MN_AESENC,
    X86_MN_AESENCLAST,
    X86_MN_AESIMC,
    X86_MN_AESKEYGEN,
    X86_MN_AESKEYGENASSIST,
    X86_MN_AMX,
    X86_MN_AND,
    X86_MN_ANDN,
    X86_MN_ANDNPD,
    X86_MN_ANDNPS,
    X86_MN_ANDPD,
    X86_MN_ANDPS,
    X86_MN_ARPL,
    X86_MN_BEXTR,
    X86_MN_BLENDPD,
    X86_MN_BLENDPS,
    X86_MN_BLENDVPD,
    X86_MN_BLENDVPS,
    X86_MN_BLSI,
    X86_MN_BLSMSK,
    X86_MN_BLSR,
    X86_MN_BOUND,
    X86_MN_BROADCASTF128,
    X86_MN_BROADCASTI128,
    X86_MN_BROADCASTSD, 
    X86_MN_BROADCASTSS,
    X86_MN_BSF,
    X86_MN_BSR,
    X86_MN_BSWAP,
    X86_MN_BT,
    X86_MN_BTC,
    X86_MN_BTR,
    X86_MN_BTS,
    X86_MN_BZHI,
    X86_MN_CALL,
    X86_MN_CALLF,
    X86_MN_CBW,
    X86_MN_CDQ,
    X86_MN_CDQE,
    X86_MN_CLAC,
    X86_MN_CLC,
    X86_MN_CLD,
    X86_MN_CLFLUSH,
    X86_MN_CLGI,
    X86_MN_CLI,
    X86_MN_CLTS,
    X86_MN_CMC,
    X86_MN_CMOVA,
    X86_MN_CMOVNC,
    X86_MN_CMOVC,
    X86_MN_CMOVNA,
    X86_MN_CMOVZ,
    X86_MN_CMOVG,
    X86_MN_CMOVNL,
    X86_MN_CMOVL,
    X86_MN_CMOVNG,
    X86_MN_CMOVNZ,
    X86_MN_CMOVNO,
    X86_MN_CMOVNP,
    X86_MN_CMOVNS,
    X86_MN_CMOVO,
    X86_MN_CMOVP,
    X86_MN_CMOVPO,
    X86_MN_CMOVS,
    X86_MN_CMP,
    X86_MN_CMPPD,
    X86_MN_CMPPS,
    X86_MN_CMPS,
    X86_MN_CMPSB,
    X86_MN_CMPSW,
    X86_MN_CMPSQ,
    X86_MN_CMPSD,
    X86_MN_CMPSS,
    X86_MN_CMPXCHG,
    X86_MN_CMPXCHG16B,
    X86_MN_CMPXCHG8B,
    X86_MN_COMISD,
    X86_MN_COMISS,
    X86_MN_CPUID,
    X86_MN_CQO,
    X86_MN_CRC32,
    X86_MN_CVTDQ2PD,
    X86_MN_CVTDQ2PS,
    X86_MN_CVTPD2DQ,
    X86_MN_CVTPD2PI,
    X86_MN_CVTPD2PS,
    X86_MN_CVTPH2PS,
    X86_MN_CVTPI2PD,
    X86_MN_CVTPI2PS,
    X86_MN_CVTPS2DQ,
    X86_MN_CVTPS2PD,
    X86_MN_CVTPS2PH,
    X86_MN_CVTPS2PI,
    X86_MN_CVTSD2SI,
    X86_MN_CVTSD2SS,
    X86_MN_CVTSI2SD,
    X86_MN_CVTSI2SS,
    X86_MN_CVTSS2SD,
    X86_MN_CVTSS2SI,
    X86_MN_CVTTPD2DQ,
    X86_MN_CVTTPD2PI,
    X86_MN_CVTTPS2DQ,
    X86_MN_CVTTPS2PI,
    X86_MN_CVTTSD2SI,
    X86_MN_CVTTSS2SI,
    X86_MN_CWD,
    X86_MN_CWDE,
    X86_MN_DAA,
    X86_MN_DAS,
    X86_MN_DEC,
    X86_MN_DIV,
    X86_MN_DIVPD,
    X86_MN_DIVPS,
    X86_MN_DIVSD,
    X86_MN_DIVSS,
    X86_MN_DPPD,
    X86_MN_DPPS,
    X86_MN_EMMS,
    X86_MN_ENTER,
    X86_MN_ENDBR32,
    X86_MN_ENDBR64,
    X86_MN_EXTRACTF128,
    X86_MN_EXTRACTI128,
    X86_MN_EXTRACTPS,
    X86_MN_EXTRQ,
    X86_MN_F2XM1,
    X86_MN_FABS,
    X86_MN_FADD,
    X86_MN_FADDP,
    X86_MN_FBLD,
    X86_MN_FBSTP,
    X86_MN_FCHS,
    X86_MN_FCLEX,
    X86_MN_FCMOVB,
    X86_MN_FCMOVBE,
    X86_MN_FCMOVE,
    X86_MN_FCMOVNB,
    X86_MN_FCMOVNBE,
    X86_MN_FCMOVNE,
    X86_MN_FCMOVNU,
    X86_MN_FCMOVU,
    X86_MN_FCOM,
    X86_MN_FCOM2,
    X86_MN_FCOMI,
    X86_MN_FCOMIP,
    X86_MN_FCOMP,
    X86_MN_FCOMP3,
    X86_MN_FCOMP5,
    X86_MN_FCOMPP,
    X86_MN_FCOS,
    X86_MN_FDECSTP,
    X86_MN_FDIV,
    X86_MN_FDIVP,
    X86_MN_FDIVR,
    X86_MN_FDIVRP,
    X86_MN_FEMMS,
    X86_MN_FFREE,
    X86_MN_FIADD,
    X86_MN_FICOM,
    X86_MN_FICOMP,
    X86_MN_FIDIV,
    X86_MN_FIDIVR,
    X86_MN_FILD,
    X86_MN_FIMUL,
    X86_MN_FINCSTP,
    X86_MN_FINIT,
    X86_MN_FIST,
    X86_MN_FISTP,
    X86_MN_FISTTP,
    X86_MN_FISUB,
    X86_MN_FISUBR,
    X86_MN_FLD,
    X86_MN_FLD1,
    X86_MN_FLDCW,
    X86_MN_FLDENV,
    X86_MN_FLDL2E,
    X86_MN_FLDL2T,
    X86_MN_FLDLG2,
    X86_MN_FLDLN2,
    X86_MN_FLDPI,
    X86_MN_FLDZ,
    X86_MN_FMADDPD,
    X86_MN_FMADD132PD,
    X86_MN_FMADD132PS,
    X86_MN_FMADD132SD,
    X86_MN_FMADD132SS,
    X86_MN_FMADD213PD,
    X86_MN_FMADD213PS,
    X86_MN_FMADD213SD,
    X86_MN_FMADD213SS,
    X86_MN_FMADD231PD,
    X86_MN_FMADD231PS,
    X86_MN_FMADD231SD,
    X86_MN_FMADD231SS,
    X86_MN_FMADDSUB132PD,
    X86_MN_FMADDSUB132PS,
    X86_MN_FMADDSUB213PD,
    X86_MN_FMADDSUB213PS,
    X86_MN_FMADDSUB231PD,
    X86_MN_FMADDSUB231PS,
    X86_MN_FMSUB132PD,
    X86_MN_FMSUB132PS,
    X86_MN_FMSUB132SD,
    X86_MN_FMSUB132SS,
    X86_MN_FMSUB213PD,
    X86_MN_FMSUB213PS,
    X86_MN_FMSUB213SD,
    X86_MN_FMSUB213SS,
    X86_MN_FMSUB231PD,
    X86_MN_FMSUB231PS,
    X86_MN_FMSUB231SD,
    X86_MN_FMSUB231SS,
    X86_MN_FMSUBADD132PD,
    X86_MN_FMSUBADD132PS,
    X86_MN_FMSUBADD213PD,
    X86_MN_FMSUBADD213PS,
    X86_MN_FMSUBADD231PD,
    X86_MN_FMSUBADD231PS,
    X86_MN_FMUL,
    X86_MN_FMULP,
    X86_MN_FNCLEX,
    X86_MN_FNDISI,
    X86_MN_FNENI,
    X86_MN_FNINIT,
    X86_MN_FNMADD132PD,
    X86_MN_FNMADD132PS,
    X86_MN_FNMADD132SD,
    X86_MN_FNMADD132SS,
    X86_MN_FNMADD213PD,
    X86_MN_FNMADD213PS,
    X86_MN_FNMADD213SD,
    X86_MN_FNMADD213SS,
    X86_MN_FNMADD231PD,
    X86_MN_FNMADD231PS,
    X86_MN_FNMADD231SD,
    X86_MN_FNMADD231SS,
    X86_MN_FNMSUB132PD,
    X86_MN_FNMSUB132PS,
    X86_MN_FNMSUB132SD,
    X86_MN_FNMSUB132SS,
    X86_MN_FNMSUB213PD,
    X86_MN_FNMSUB213PS,
    X86_MN_FNMSUB213SD,
    X86_MN_FNMSUB213SS,
    X86_MN_FNMSUB231PD,
    X86_MN_FNMSUB231PS,
    X86_MN_FNMSUB231SD,
    X86_MN_FNMSUB231SS,
    X86_MN_FNOP,
    X86_MN_FNSAVE,
    X86_MN_FNSETPM,
    X86_MN_FNSTCW,
    X86_MN_FNSTENV,
    X86_MN_FNSTSW,
    X86_MN_FPATAN,
    X86_MN_FPREM,
    X86_MN_FPREM1,
    X86_MN_FPTAN,
    X86_MN_FRNDINT,
    X86_MN_FRSTOR,
    X86_MN_FSAVE,
    X86_MN_FSCALE,
    X86_MN_FSIN,
    X86_MN_FSINCOS,
    X86_MN_FSQRT,
    X86_MN_FST,
    X86_MN_FSTCW,
    X86_MN_FSTENV,
    X86_MN_FSTP,
    X86_MN_FSTP1,
    X86_MN_FSTP8,
    X86_MN_FSTP9,
    X86_MN_FSTSW,
    X86_MN_FSUB,
    X86_MN_FSUBP,
    X86_MN_FSUBR,
    X86_MN_FSUBRP,
    X86_MN_FTST,
    X86_MN_FUCOM,
    X86_MN_FUCOMI,
    X86_MN_FUCOMIP,
    X86_MN_FUCOMP,
    X86_MN_FUCOMPP,
    X86_MN_FWAIT,
    X86_MN_FXAM,
    X86_MN_FXCH,
    X86_MN_FXRSTOR,
    X86_MN_FXRSTOR64,
    X86_MN_FXSAVE,
    X86_MN_FXSAVE64,
    X86_MN_FXTRACT,
    X86_MN_FYL2X,
    X86_MN_FYL2XP1,
    X86_MN_GATHERDD,
    X86_MN_GATHERDPD,   
    X86_MN_GATHERDPS,
    X86_MN_GATHERDQ,
    X86_MN_GATHERQD,
    X86_MN_GATHERQPD,
    X86_MN_GATHERQPS,   
    X86_MN_GATHERQQ,
    X86_MN_GETSEC,
    X86_MN_HADDPD,
    X86_MN_HADDPS,
    X86_MN_HINTNOP,
    X86_MN_HLT,
    X86_MN_HSUBPD,
    X86_MN_HSUBPS,
    X86_MN_ICEBP,
    X86_MN_IDIV,
    X86_MN_IMUL,
    X86_MN_IN,
    X86_MN_INC,
    X86_MN_INS,
    X86_MN_INSB,
    X86_MN_INSW,
    X86_MN_INSD,
    X86_MN_INSERTF128,
    X86_MN_INSERTI128,
    X86_MN_INSERTPS,
    X86_MN_INSERTQ,
    X86_MN_INT,
    X86_MN_INT3,
    X86_MN_INTO,
    X86_MN_INVD,
    X86_MN_INVEPT,
    X86_MN_INVLPG,
    X86_MN_INVLPGA,
    X86_MN_INVPCID,
    X86_MN_INVVPID,
    X86_MN_IRET,
    X86_MN_IRETW,
    X86_MN_IRETD,
    X86_MN_IRETQ,
    X86_MN_JA,
    X86_MN_JC,
    X86_MN_JNG,
    X86_MN_JZ,
    X86_MN_JG,
    X86_MN_JNL,
    X86_MN_JL,
    X86_MN_JNA,
    X86_MN_JMP,
    X86_MN_JMPF,
    X86_MN_JNC,
    X86_MN_JNZ,
    X86_MN_JNO,
    X86_MN_JNP,
    X86_MN_JNS,
    X86_MN_JO,
    X86_MN_JP,
    X86_MN_JS,
    X86_MN_JCXZ,
    X86_MN_JECXZ,
    X86_MN_JRCXZ,
    X86_MN_LAHF,
    X86_MN_LAR,
    X86_MN_LDDQU,
    X86_MN_LDMXCSR,
    X86_MN_LDS,
    X86_MN_LEA,
    X86_MN_LEAVE,
    X86_MN_LES,
    X86_MN_LFENCE,
    X86_MN_LFS,
    X86_MN_LGDT,
    X86_MN_LGS,
    X86_MN_LIDT,
    X86_MN_LLDT,
    X86_MN_LMSW,
    X86_MN_LODS,
    X86_MN_LODSB,
    X86_MN_LODSW,
    X86_MN_LODSD,
    X86_MN_LODSQ,
    X86_MN_LOOP,
    X86_MN_LOOPZ,
    X86_MN_LOOPNZ,
    X86_MN_LSL,
    X86_MN_LSS,
    X86_MN_LTR,
    X86_MN_LZCNT,
    X86_MN_MASKMOVDQU,
    X86_MN_MASKMOVPD,
    X86_MN_MASKMOVPS,
    X86_MN_MASKMOVQ,
    X86_MN_MAXPD,
    X86_MN_MAXPS,
    X86_MN_MAXSD,
    X86_MN_MAXSS,
    X86_MN_MFENCE,
    X86_MN_MINPD,
    X86_MN_MINPS,
    X86_MN_MINSD,
    X86_MN_MINSS,
    X86_MN_MONITOR,
    X86_MN_MOV,
    X86_MN_MOVAPD,
    X86_MN_MOVAPS,
    X86_MN_MOVBE,
    X86_MN_MOVD,
    X86_MN_MOVDDUP,
    X86_MN_MOVDQ2Q,
    X86_MN_MOVDQA,
    X86_MN_MOVDQU,
    X86_MN_MOVHLPS,
    X86_MN_MOVHPD,
    X86_MN_MOVHPS,
    X86_MN_MOVLHPS,
    X86_MN_MOVLPD,
    X86_MN_MOVLPS,
    X86_MN_MOVMSKPD,
    X86_MN_MOVMSKPS,
    X86_MN_MOVNTDQ,
    X86_MN_MOVNTDQA,
    X86_MN_MOVNTI,
    X86_MN_MOVNTPD,
    X86_MN_MOVNTSS,
    X86_MN_MOVNTSD,
    X86_MN_MOVNTPS,
    X86_MN_MOVNTQ,
    X86_MN_MOVQ,
    X86_MN_MOVQ2DQ,
    X86_MN_MOVS,
    X86_MN_MOVSB,
    X86_MN_MOVSW,
    X86_MN_MOVSD,
    X86_MN_MOVSQ,
    X86_MN_MOVSHDUP,
    X86_MN_MOVSLDUP,
    X86_MN_MOVSS,
    X86_MN_MOVSX,
    X86_MN_MOVSXD,
    X86_MN_MOVUPD,
    X86_MN_MOVUPS,
    X86_MN_MOVZX,
    X86_MN_MPSADBW,
    X86_MN_MUL,
    X86_MN_MULPD,
    X86_MN_MULPS,
    X86_MN_MULSD,
    X86_MN_MULSS,
    X86_MN_MULX,
    X86_MN_MWAIT,
    X86_MN_NEG,
    X86_MN_NOP,
    X86_MN_NOT,
    X86_MN_OR,
    X86_MN_ORPD,
    X86_MN_ORPS,
    X86_MN_OUT,
    X86_MN_OUTS,
    X86_MN_OUTSB,
    X86_MN_OUTSW,
    X86_MN_OUTSD,
    X86_MN_PABSB,
    X86_MN_PABSD,
    X86_MN_PABSW,
    X86_MN_PACKSSDB,
    X86_MN_PACKSSDW,
    X86_MN_PACKSSWB,
    X86_MN_PACKUSDB,
    X86_MN_PACKUSDW,
    X86_MN_PACKUSWB,
    X86_MN_PADDB,
    X86_MN_PADDD,
    X86_MN_PADDQ,
    X86_MN_PADDSB,
    X86_MN_PADDSW,
    X86_MN_PADDUSB,
    X86_MN_PADDUSW,
    X86_MN_PADDW,
    X86_MN_PALIGNR,
    X86_MN_PAND,
    X86_MN_PANDN,
    X86_MN_PAUSE,
    X86_MN_PAVGB,
    X86_MN_PAVGW,
    X86_MN_PBLENDD,
    X86_MN_PBLENDVB,
    X86_MN_PBLENDW,
    X86_MN_PBROADCASTB,
    X86_MN_PBROADCASTD,
    X86_MN_PBROADCASTQ,
    X86_MN_PBROADCASTW,
    X86_MN_PCLMULQDQ,
    X86_MN_PCMPEQB,
    X86_MN_PCMPEQD,
    X86_MN_PCMPEQQ,
    X86_MN_PCMPEQW,
    X86_MN_PCMPESTRI,
    X86_MN_PCMPESTRM,
    X86_MN_PCMPGTB,
    X86_MN_PCMPGTD,
    X86_MN_PCMPGTQ,
    X86_MN_PCMPGTW,
    X86_MN_PCMPISTRI,
    X86_MN_PCMPISTRM,
    X86_MN_PDEP,
    X86_MN_PERM2F128,
    X86_MN_PERM2I128,
    X86_MN_PERMD,
    X86_MN_PERMILPD,
    X86_MN_PERMILPS,
    X86_MN_PERMPD,
    X86_MN_PERMPS,
    X86_MN_PERMQ,
    X86_MN_PEXT,
    X86_MN_PEXTRB,
    X86_MN_PEXTRD,
    X86_MN_PEXTRQ,
    X86_MN_PEXTRW,
    X86_MN_PFRCPIT2,
    X86_MN_PHADDD,
    X86_MN_PHADDSW,
    X86_MN_PHADDW,
    X86_MN_PHMINPOSUW,
    X86_MN_PHSUBD,
    X86_MN_PHSUBSW,
    X86_MN_PHSUBW,
    X86_MN_PINSRB,
    X86_MN_PINSRD,
    X86_MN_PINSRQ,
    X86_MN_PINSRW,
    X86_MN_PMADDUBSW,
    X86_MN_PMADDWD,
    X86_MN_PMADDWS,
    X86_MN_PMASKMOVD,
    X86_MN_PMASKMOVQ,   
    X86_MN_PMAXSB,
    X86_MN_PMAXSD,
    X86_MN_PMAXSW,
    X86_MN_PMAXUB,
    X86_MN_PMAXUD,
    X86_MN_PMAXUW,
    X86_MN_PMINS,
    X86_MN_PMINSB,
    X86_MN_PMINSD,
    X86_MN_PMINSW,
    X86_MN_PMINUB,
    X86_MN_PMINUD,
    X86_MN_PMINUW,
    X86_MN_PMOVMSKB,
    X86_MN_PMOVSX,
    X86_MN_PMOVSXBD,
    X86_MN_PMOVSXBQ,    
    X86_MN_PMOVSXBW,    
    X86_MN_PMOVSXDQ,
    X86_MN_PMOVSXWD,    
    X86_MN_PMOVSXWQ,
    X86_MN_PMOVZX,
    X86_MN_PMOVZXBD,
    X86_MN_PMOVZXBQ,    
    X86_MN_PMOVZXBW,    
    X86_MN_PMOVZXDQ,
    X86_MN_PMOVZXWD,    
    X86_MN_PMOVZXWQ,
    X86_MN_PMUL,
    X86_MN_PMULDQ,
    X86_MN_PMULHRSW,
    X86_MN_PMULHUW,
    X86_MN_PMULHW,
    X86_MN_PMULLD,
    X86_MN_PMULLW,
    X86_MN_PMULUDQ,
    X86_MN_POP,
    X86_MN_POPA,
    X86_MN_POPAD,
    X86_MN_POPCNT,
    X86_MN_POPF,
    X86_MN_POPFD,
    X86_MN_POPFQ,
    X86_MN_POR,
    X86_MN_PREFETCH,
    X86_MN_PREFETCHWT1,
    X86_MN_PREFETCHW,
    X86_MN_PREFETCHT0,
    X86_MN_PREFETCHT1,
    X86_MN_PREFETCHT2,
    X86_MN_PREFETCHNTA,
    X86_MN_PSADBW,
    X86_MN_PSHUFB,
    X86_MN_PSHUFD,
    X86_MN_PSHUFHW,
    X86_MN_PSHUFLW,
    X86_MN_PSHUFW,
    X86_MN_PSIGN,
    X86_MN_PSIGNB,
    X86_MN_PSIGND,
    X86_MN_PSIGNW,
    X86_MN_PSLLD,
    X86_MN_PSLLDQ,
    X86_MN_PSLLQ,
    X86_MN_PSLLVD,
    X86_MN_PSLLVQ,
    X86_MN_PSLLW,
    X86_MN_PSRAD,
    X86_MN_PSRAVD,
    X86_MN_PSRAW,
    X86_MN_PSRLD,
    X86_MN_PSRLDQ,
    X86_MN_PSRLQ,
    X86_MN_PSRLVD,
    X86_MN_PSRLVQ,
    X86_MN_PSRLW,
    X86_MN_PSUB,
    X86_MN_PSUBB,
    X86_MN_PSUBD,
    X86_MN_PSUBQ,
    X86_MN_PSUBSB,
    X86_MN_PSUBSW,
    X86_MN_PSUBUSB,
    X86_MN_PSUBUSW,
    X86_MN_PSUBW,
    X86_MN_PTEST,
    X86_MN_PTWRITE,
    X86_MN_PUNPCKHBW,
    X86_MN_PUNPCKHDQ,
    X86_MN_PUNPCKHQDQ,
    X86_MN_PUNPCKHWD,
    X86_MN_PUNPCKLBW,
    X86_MN_PUNPCKLDQ,
    X86_MN_PUNPCKLQDQ,
    X86_MN_PUNPCKLWD,
    X86_MN_PUSH,
    X86_MN_PUSHA,
    X86_MN_PUSHAD,
    X86_MN_PUSHF,
    X86_MN_PUSHFD,
    X86_MN_PUSHFQ,
    X86_MN_PXOR,
    X86_MN_RCL,
    X86_MN_RCPPS,
    X86_MN_RCPSS,
    X86_MN_RCR,
    X86_MN_RDFSBASE,
    X86_MN_RDGSBASE,
    X86_MN_RDMSR,
    X86_MN_RDPMC,
    X86_MN_RDRAND,
    X86_MN_RDSEED,
    X86_MN_RDSSPD,
    X86_MN_RDSSPQ,
    X86_MN_RDTSC,
    X86_MN_RDTSCP,
    X86_MN_RETF,
    X86_MN_RETN,
    X86_MN_ROL,
    X86_MN_ROR,
    X86_MN_RORX,
    X86_MN_ROUND,
    X86_MN_ROUNDPD,
    X86_MN_ROUNDPS,
    X86_MN_ROUNDSD,
    X86_MN_ROUNDSS,
    X86_MN_RSM,
    X86_MN_RSQRTPS,
    X86_MN_RSQRTSS,
    X86_MN_SAHF,
    X86_MN_SAL,
    X86_MN_SALC,
    X86_MN_SAR,
    X86_MN_SARX,
    X86_MN_SBB,
    X86_MN_SCAS,
    X86_MN_SCASB,
    X86_MN_SCASW,
    X86_MN_SCASD,
    X86_MN_SCASQ,
    X86_MN_SETA,
    X86_MN_SETC,
    X86_MN_SETNC,
    X86_MN_SETZ,
    X86_MN_SETG,
    X86_MN_SETNG,
    X86_MN_SETL,
    X86_MN_SETNL,
    X86_MN_SETNA,
    X86_MN_SETNZ,
    X86_MN_SETNO,
    X86_MN_SETNP,
    X86_MN_SETNS,
    X86_MN_SETO,
    X86_MN_SETP,
    X86_MN_SETPO,
    X86_MN_SETS,
    X86_MN_SFENCE,
    X86_MN_SGDT,
    X86_MN_SHL,
    X86_MN_SHLD,
    X86_MN_SHLX,
    X86_MN_SHR,
    X86_MN_SHRD,
    X86_MN_SHRX,
    X86_MN_SHUFPD,
    X86_MN_SHUFPS,
    X86_MN_SIDT,
    X86_MN_SKINIT,
    X86_MN_SLDT,
    X86_MN_SMSW,
    X86_MN_SQRT,
    X86_MN_SQRTPD,
    X86_MN_SQRTPS,
    X86_MN_SQRTSD,
    X86_MN_SQRTSS,
    X86_MN_STAC,
    X86_MN_STC,
    X86_MN_STD,
    X86_MN_STGI,
    X86_MN_STI,
    X86_MN_STMXCSR,
    X86_MN_STOS,
    X86_MN_STOSB,
    X86_MN_STOSW,
    X86_MN_STOSD,
    X86_MN_STOSQ,
    X86_MN_STR,
    X86_MN_SUB,
    X86_MN_SUBPD,
    X86_MN_SUBPS,
    X86_MN_SUBSD,
    X86_MN_SUBSS,
    X86_MN_SWAPGS,
    X86_MN_SYSCALL,
    X86_MN_SYSENTER,
    X86_MN_SYSEXIT,
    X86_MN_SYSRET,
    X86_MN_TEST,
    X86_MN_TESTPD,
    X86_MN_TESTPS,
    X86_MN_TZCNT,
    X86_MN_UCOMISD,
    X86_MN_UCOMISS,
    X86_MN_UD,
    X86_MN_UD1,
    X86_MN_UD2,
    X86_MN_UNPCKHPD,
    X86_MN_UNPCKHPS,
    X86_MN_UNPCKLPD,
    X86_MN_UNPCKLPS,
    X86_MN_VERR,
    X86_MN_VERW,
    X86_MN_VMCALL,
    X86_MN_VMCLEAR,
    X86_MN_VMFUNC,
    X86_MN_VMLAUNCH,
    X86_MN_VMLOAD,
    X86_MN_VMPTRLD,
    X86_MN_VMPTRST,
    X86_MN_VMREAD,
    X86_MN_VMRESUME,
    X86_MN_VMRUN,
    X86_MN_VMSAVE,
    X86_MN_VMWRITE,
    X86_MN_VMXOFF,
    X86_MN_VMXON,
    X86_MN_WAIT,
    X86_MN_WBINVD,
    X86_MN_WRFSBASE,
    X86_MN_WRGSBASE,
    X86_MN_WRMSR,
    X86_MN_XADD,
    X86_MN_XCHG,
    X86_MN_XEND,
    X86_MN_XGETBV,
    X86_MN_XLAT,
    X86_MN_XOR,
    X86_MN_XORPD,
    X86_MN_XORPS,
    X86_MN_XORSS,
    X86_MN_XRSTOR,
    X86_MN_XRSTOR64,
    X86_MN_XRSTORS,
    X86_MN_XRSTORS64,
    X86_MN_XSAVE,
    X86_MN_XSAVE64,
    X86_MN_XSAVEC,
    X86_MN_XSAVEC64,
    X86_MN_XSAVES,
    X86_MN_XSAVES64,
    X86_MN_XSAVEOPT,
    X86_MN_XSAVEOPT64,
    X86_MN_XSETBV,
    X86_MN_XTEST,
    /* XOP */
    X86_MN_VPMACSSWW,
    X86_MN_VPMACSSWD,
    X86_MN_VPMACSSDQL,
    X86_MN_VPMACSSDD,
    X86_MN_VPMACSSDQH,
    X86_MN_VPMACSWW,
    X86_MN_VPMACSWD,
    X86_MN_VPMACSDQL,
    X86_MN_VPMACSDD,
    X86_MN_VPMACSDQH,
    X86_MN_VPMADCSSWD,
    X86_MN_VPMADCSWD,
    X86_MN_VPROTB,
    X86_MN_VPROTW,
    X86_MN_VPROTD,
    X86_MN_VPROTQ,
    X86_MN_VPCOMB,
    X86_MN_VPCOMW,
    X86_MN_VPCOMD,
    X86_MN_VPCOMQ,
    X86_MN_VPCOMUB,
    X86_MN_VPCOMUW,
    X86_MN_VPCOMUD,
    X86_MN_VPCOMUQ,
    X86_MN_VPPERM,
    X86_MN_VPCMOV,
    X86_MN_VFRCZPS,
    X86_MN_VFRCZPD,
    X86_MN_VFRCZSS,
    X86_MN_VFRCZSD,
    X86_MN_VPHADDBW,
    X86_MN_VPHADDBD,
    X86_MN_VPHADDBQ,
    X86_MN_VPHADDWD,
    X86_MN_VPHADDWQ,
    X86_MN_VPHADDDQ,
    X86_MN_VPHADDUBWD,
    X86_MN_VPHADDUBD,
    X86_MN_VPHADDUBQ,
    X86_MN_VPHADDUWD,
    X86_MN_VPHADDUWQ,
    X86_MN_VPHADDUDQ,
    X86_MN_VPHSUBBW,
    X86_MN_VPHSUBWD,
    X86_MN_VPHSUBDQ,
    X86_MN_VZEROUPPER,
    X86_MN_VZEROALL,
    X86_MN_BLCFILL,
    X86_MN_BLSFILL,
    X86_MN_BLCS,
    X86_MN_TZMSK,
    X86_MN_BLCIC,
    X86_MN_BLCSIC,
    X86_MN_T1MSKC,
    X86_MN_BLCMSK,
    X86_MN_LLWPCB,
    X86_MN_SLWPCB,
    X86_MN_VPSHLB,
    X86_MN_VPSHLW,
    X86_MN_VPSHLD,
    X86_MN_VPSHLQ,
    X86_MN_VPSHAB,
    X86_MN_VPSHAW,
    X86_MN_VPSHAD,
    X86_MN_VPSHAQ,
    X86_MN_LWPINS,
    X86_MN_LWPVAL,
    /* 3DNow */
    X86_MN_PFCMPGE,
    X86_MN_PI2FW,
    X86_MN_PI2FD,
    X86_MN_PF2IW,
    X86_MN_PF2ID,
    X86_MN_PFNACC,
    X86_MN_PFPNACC,
    X86_MN_PFMIN,
    X86_MN_PFRCP,
    X86_MN_PFRSQRT,
    X86_MN_PFSUB,
    X86_MN_PFADD,
    X86_MN_PFCMPGT,
    X86_MN_PFMAX,
    X86_MN_PFRCPIT1,
    X86_MN_PFRSQIT1,
    X86_MN_PFSUBR,
    X86_MN_PFACC,
    X86_MN_PFCMPEQ,
    X86_MN_PFMUL,
    X86_MN_PMULHRW,
    X86_MN_PSWAPD,
    X86_MN_PAVGUSB,
    X86_MN_FFREEP,
    X86_MN_FXCH4,
    X86_MN_FSTDW,
    X86_MN_FSTSG,
    X86_MN_FXCH7,
    /* FMA4 */
    X86_MN_FMADDSUBPS,
    X86_MN_FMADDSUBPD,
    X86_MN_FMSUBADDPS,
    X86_MN_FMSUBADDPD,
    X86_MN_FMADDPS,
    X86_MN_FMADDSS,
    X86_MN_FMADDSD, 
    X86_MN_FMSUBPS,
    X86_MN_FMSUBPD,
    X86_MN_FMSUBSS,
    X86_MN_FMSUBSD,
    X86_MN_FNMADDPS,
    X86_MN_FNMADDPD,
    X86_MN_FNMADDSS,
    X86_MN_FNMADDSD,
    X86_MN_FNMSUBPS,
    X86_MN_FNMSUBPD,
    X86_MN_FNMSUBSS,
    X86_MN_FNMSUBSD,
    /* TSX */
    X86_MN_XBEGIN,
    X86_MN_XABORT,
    /* CET */
    X86_MN_WRUSSD,
    X86_MN_WRUSSQ,
    X86_MN_WRSSD,
    X86_MN_WRSSQ,
    X86_MN_INCSSPD,
    X86_MN_INCSSPQ,
    X86_MN_SAVEPREVSSP,
    X86_MN_RSTORSSP,
    X86_MN_CLRSSBSY,
    X86_MN_SETSSBSY
};

/***************************************************************************/

enum 
{
    X86_FLAG_NA = 0,    /* flag not affected */
    X86_FLAG_T,         /* flag tested */
    X86_FLAG_M,         /* flag modified */
    X86_FLAG_TM,        /* flag tested and modified */
    X86_FLAG_CLR,       /* flag cleared */
    X86_FLAG_SET        /* flag set */
};

enum
{
    /* dasm mode */
    X86_DMODE_16BIT = 0,    /* real mode / virtual 8086 mode (16-bit) */
    X86_DMODE_32BIT,        /* protected mode / long compatibility mode (32-bit) */
    X86_DMODE_64BIT,        /* long mode (64-bit) */

    /* operand size */
    X86_OSIZE_16BIT = 0,
    X86_OSIZE_32BIT,
    X86_OSIZE_64BIT,

    /* addressing size */
    X86_ASIZE_16BIT = 0,
    X86_ASIZE_32BIT,
    X86_ASIZE_64BIT,

    /* operand type */
    X86_OPTYPE_NONE = 0,    /* operand invalid */
    X86_OPTYPE_REG,         /* register */
    X86_OPTYPE_IMM,         /* immediate */
    X86_OPTYPE_MEXPR,       /* memory expression: base+index*scale+disp */
    X86_OPTYPE_MOFFS,       /* memory offset: A0-A3 */
    X86_OPTYPE_ABS,         /* absolute address: jmp far seg:offset */
    X86_OPTYPE_REL,         /* relative to rIP */

    /* operand size (effective) */
    X86_OPSIZE_NONE = 0,
    X86_OPSIZE_BYTE,        /* 1 bytes  (8 bit) */
    X86_OPSIZE_WORD,        /* 2 bytes  (16 bit) */
    X86_OPSIZE_DWORD,       /* 4 bytes  (32 bit) */
    X86_OPSIZE_FWORD,       /* 6 bytes  (48 bit) */
    X86_OPSIZE_QWORD,       /* 8 bytes  (64 bit) */
    X86_OPSIZE_TWORD,       /* 10 bytes (80 bit) */
    X86_OPSIZE_OWORD,       /* 16 bytes (128 bit) */
    X86_OPSIZE_YWORD,       /* 32 bytes (256 bit) */
    X86_OPSIZE_ZWORD,       /* 64 bytes (512 bit) */

    /* addressing size */
    X86_ASIZE_NONE = 0,
    X86_ASIZE_WORD,         /* 2 bytes  (16 bit) */
    X86_ASIZE_DWORD,        /* 4 bytes  (32 bit) */
    X86_ASIZE_QWORD,        /* 8 bytes  (64 bit) */

    /* displacement size */
    X86_DISP_NONE = 0,      /* no displacement */
    X86_DISP_8,             /* byte displacement */
    X86_DISP_16,            /* word displacement */
    X86_DISP_32             /* dword displacement */
};

typedef union 
{ 
    uint8_t     u8;
    uint16_t    u16;
    uint32_t    u32;
    uint64_t    u64;
    int8_t      s8;
    int16_t     s16; 
    int32_t     s32;
    int64_t     s64;

} data_type;

typedef data_type x86_reg;

typedef struct
{

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

    char str[64];

#endif

    uint8_t type;       /* X86_OPTYPE_ */
    uint8_t size;       /* X86_OPSIZE_ */
    uint8_t size_orig;  /* X86_OPSIZE_, orig. before fixes/sign-extension */
    uint8_t asize;      /* X86_ASIZE_ */
    uint8_t seg;        /* X86_REG_ES/DS/SS/FS/GS/CS */
    uint8_t pos;        /* position of IMM/REL/MOFFS/DISP in buffer */

    union 
    {
        /* X86_OPTYPE_ABS */
        struct
        {
            uint16_t seg;
            data_type offs;

        } abs;

        /* X86_OPTYPE_REG */
        uint8_t reg;            /* X86_REG_ */

        /* X86_OPTYPE_MEXPR */
        struct
        {
            uint8_t scale;      /* 1, 2, 4, 8 */
            uint8_t index;      /* X86_REG_ */
            uint8_t base;       /* X86_REG_ */
            uint8_t disp_size;  /* X86_DISP_ */
            data_type disp;

        } mexpr;

        /* X86_OPTYPE_IMM */
        /* X86_OPTYPE_MOFFS */
        /* X86_OPTYPE_REL */
        data_type data;
    };

} x86_operand_t;

typedef struct
{
    uint8_t buffer[32]; /* buffer to disasm */

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

    char inst_str[128]; /* full formatted instruction */
    char mnem_str[32];  /* mnemonic string */

#endif

    union 
    {
        uint8_t pos;    /* position in buffer (cursor) */
        uint8_t len;    /* instruction lenght */
    };
    
    uint8_t dmode;      /* X86_DMODE_ */
    uint8_t osize;      /* X86_OSIZE_ */
    uint8_t asize;      /* X86_ASIZE_ */
    uint8_t iset;       /* X86_ISET_ */
    uint16_t mnem;      /* X86_MN_ */

    uint8_t modrm;
    uint8_t sib;
    uint8_t vsib_base;

    /* prefixes */
    uint8_t pfx_rex;
    uint8_t pfx_last;
    uint8_t pfx_seg;
    uint8_t pfx_mandatory;

    union 
    {
        uint8_t pfx_vex[3];
        uint8_t pfx_xop[3];
    };

    /* positions in buffer */
    uint8_t pos_modrm : 4;
    uint8_t pos_sib : 4;
    uint8_t pos_rex : 4;
    uint8_t pos_opcode : 4;

    /* count of operand-size ovverride prefixes */
    uint8_t pfx_c_osize : 4;
    
    /* prefixes present */
    uint8_t pfx_p_rex : 1;
    uint8_t pfx_p_seg : 1;
    uint8_t pfx_p_osize : 1;
    uint8_t pfx_p_asize : 1;
    uint8_t pfx_p_lock : 1;
    uint8_t pfx_p_rep : 1;
    uint8_t pfx_p_repne : 1;
    uint8_t pfx_p_vex2b : 1;
    uint8_t pfx_p_vex3b : 1;
    uint8_t pfx_p_evex : 1;
    uint8_t pfx_p_xop : 1;

    /* bytes present */
    uint8_t p_modrm : 1;
    uint8_t p_sib : 1;
    uint8_t p_vsib : 1;

    /* current table link */
    const x86_table_link_t* table_link;
    
    /* operands */
    x86_operand_t operands[4];

    /* EFLAGS */
    x86_eflags_t eflags;

    /* current instruction pointer */
    x86_reg rip;

    /* destination instruction pointer (for relative inst.) */
    x86_reg dest_rip;

} x86_dasm_context_t;

typedef struct
{
    x86_reg rax;
    x86_reg rcx;
    x86_reg rdx;
    x86_reg rbx;
    x86_reg rsp;
    x86_reg rbp;
    x86_reg rsi;
    x86_reg rdi;

    /* 64-bit mode only */
    x86_reg r8;
    x86_reg r9;
    x86_reg r10;
    x86_reg r11;
    x86_reg r12;
    x86_reg r13;
    x86_reg r14;
    x86_reg r15;

    x86_reg rip;

    /* base address of the segments, -- not the segment selector! -- */
    x86_reg es;
    x86_reg cs;
    x86_reg ss;
    x86_reg ds;
    x86_reg fs;
    x86_reg gs;

} x86_regs_t;

/* utility functions */
void x86_set_buffer(x86_dasm_context_t* x86_dctx, void* code);

void x86_set_ip(x86_dasm_context_t* x86_dctx, uint64_t ip);

void x86_set_dmode(x86_dasm_context_t* x86_dctx, int dmode);

bool_t x86_is_jmp(x86_dasm_context_t* x86_dctx);

bool_t x86_is_jmpcc(x86_dasm_context_t* x86_dctx);

bool_t x86_is_ret(x86_dasm_context_t* x86_dctx);

bool_t x86_resolve_rip(x86_dasm_context_t* x86_dctx, ulong_t i, uint64_t* addr);

uint64_t x86_resolve_op(x86_dasm_context_t* x86_dctx, x86_regs_t* regs, ulong_t i);

/* disassembling function */
int x86_dasm(x86_dasm_context_t* x86_dctx);

#ifdef __cplusplus
    }
#endif

#endif //_DASM_H_