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
#ifndef _DASM_TABLES_H_
#define _DASM_TABLES_H_

#include "types.h"

/* 
    #define X86_DASM_DEBUG      : enable debug output
    #define X86_DASM_NOFMT      : disable all formatting/strings
    #define X86_DASM_NLE        : if not on a little-endian system
*/

#ifdef __cplusplus
    extern "C" {
#endif

/****************************************************************************

    Instruction format

****************************************************************************/

/* 
    the total number of bytes in an instruction encoding must be less than
    or equal to 15
*/
#define MAX_INST_LENGTH 15

#define ESCAPE_OPCODE_2B    0x0f
#define ESCAPE_OPCODE_3B_1  0x38
#define ESCAPE_OPCODE_3B_2  0x3a

/*
    MODRM byte

    bits 0-2: rm  (rex.b, vex.b, xop.b extend this field to 4 bits)
    bits 3-5: reg (rex.r, vex.r, xop.r extend this field to 4 bits)
    bits 6-7: mod
*/
#define MODRM_RM(b)         ((b >> 0) & 7)
#define MODRM_REG(b)        ((b >> 3) & 7)
#define MODRM_MOD(b)        ((b >> 6) & 3)

/*
    SIB byte

    bits 0-2: base  (rex.b extends this field to 4 bits)
    bits 3-5: index (rex.x extends this field to 4 bits)
    bits 6-7: scale (00 = 1, 01 = 2, 10 = 4, 11 = 8)

    effective_address = scale * index + base + disp8/16/32
*/
#define SIB_BASE(b)         ((b >> 0) & 7)
#define SIB_INDEX(b)        ((b >> 3) & 7)
#define SIB_SCALE(b)        ((b >> 6) & 3)

/*
    REX byte

    bit 0: b (msb extension of modrm.rm or sib.base or opcode reg field)
    bit 1: x (msb extension of sib.index)
    bit 2: r (msb extension of modrm.reg)
    bit 3: w (0 = default operand size, 1 = 64-bit operand size)
*/
#define REX_PREFIX(b)       (((b >> 4) & 0x0f) == 4)
#define _REX_B(b)           ((b >> 0) & 1)
#define _REX_X(b)           ((b >> 1) & 1)
#define _REX_R(b)           ((b >> 2) & 1)
#define _REX_W(b)           ((b >> 3) & 1)

/*
    VEX 2-byte
*/
#define _VEX_2B_PP(b)       ((b >> 0) & 3)
#define _VEX_2B_L(b)        ((b >> 2) & 1)
#define _VEX_2B_VVVV(b)     ((~(b >> 3)) & 0x0f)
#define _VEX_2B_R(b)        ((~(b >> 7)) & 1)

#define VEX_2B_PM(b)        (MODRM_MOD(b) == 3) /* LDS must have modrm.mod = !11b */

/*
    VEX 3-byte
*/
#define _VEX_3B_MMMMM(b)    ((b >> 0) & 0x1f)
#define _VEX_3B_B(b)        ((~(b >> 5)) & 1)
#define _VEX_3B_X(b)        ((~(b >> 6)) & 1)
#define _VEX_3B_R(b)        ((~(b >> 7)) & 1)

#define _VEX_3B_PP(b)       ((b >> 0) & 3)
#define _VEX_3B_L(b)        ((b >> 2) & 1)
#define _VEX_3B_VVVV(b)     ((~(b >> 3)) & 0x0f)
#define _VEX_3B_W(b)        ((b >> 7) & 1)

#define VEX_3B_PM(b)        (MODRM_MOD(b) == 3) /* LES must have modrm.mod = !11b */

/*
    XOP
*/
#define _XOP_MMMMM(b)       ((b >> 0) & 0x1f)
#define _XOP_B(b)           ((~(b >> 5)) & 1)
#define _XOP_X(b)           ((~(b >> 6)) & 1)
#define _XOP_R(b)           ((~(b >> 7)) & 1)

#define _XOP_PP(b)          ((b >> 0) & 3)
#define _XOP_L(b)           ((b >> 2) & 1)
#define _XOP_VVVV(b)        ((~(b >> 3)) & 0x0f)
#define _XOP_W(b)           ((b >> 7) & 1)

#define XOP_PM(b)           (MODRM_MOD(b) == 3)
#define XOP_VALID(b)        (_XOP_MMMMM(b) > 7 && _XOP_MMMMM(b) < 11)

/*
    EVEX
*/
#define _EVEX_B(b)          ((~(b >> 5)) & 1)
#define _EVEX_X(b)          ((~(b >> 6)) & 1) 
#define _EVEX_R(b)          ((~(b >> 7)) & 1)
#define _EVEX_RR(b)         ((~(b >> 4)) & 1) /* R' */
#define _EVEX_MM(b)         ((b >> 0) & 3)

#define _EVEX_PP(b)         ((b >> 0) & 3)
#define _EVEX_W(b)          ((b >> 7) & 1)
#define _EVEX_VVVV(b)       ((~(b >> 3)) & 0x0f)

#define _EVEX_Z(b)          ((b >> 7) & 1) 
#define _EVEX_LL(b)         ((b >> 6) & 1) /* L' */
#define _EVEX_L(b)          ((b >> 5) & 1) 
#define _EVEX_BB(b)         ((b >> 4) & 1)
#define _EVEX_VV(b)         ((~(b >> 3)) & 1) /* V' */
#define _EVEX_AAA(b)        ((b >> 0) & 7)

#define EVEX_P0(b)          (((b >> 2) & 3) == 0) /* check on P0, else #UD */
#define EVEX_P1(b)          (((b >> 2) & 1) == 1) /* check on P1, else #UD */
#define EVEX_PM(b)          (MODRM_MOD(b) == 3) /* BOUND must have modrm.mod = !11b */


/*
    prefixes
*/
#define PREFIX_OSIZE        0x66 /* operand-size override */
#define PREFIX_ASIZE        0x67 /* address-size override */
#define PREFIX_SEGOVRD_CS   0x2e /* segment override, ignored in 64-bit mode */
#define PREFIX_SEGOVRD_DS   0x3e /* segment override, ignored in 64-bit mode */
#define PREFIX_SEGOVRD_ES   0x26 /* segment override, ignored in 64-bit mode */
#define PREFIX_SEGOVRD_FS   0x64 /* segment override */
#define PREFIX_SEGOVRD_GS   0x65 /* segment override */
#define PREFIX_SEGOVRD_SS   0x36 /* segment override, ignored in 64-bit mode */
#define PREFIX_LOCK         0xf0 /* lock rw atomically */
#define PREFIX_REPNE        0xf2
#define PREFIX_REP          0xf3
#define PREFIX_BRT          0x2e /* branch taken (hint), only with jcc */
#define PREFIX_BRNT         0x3e /* branch not taken (hint), only with jcc */
#define PREFIX_VEX_3B       0xc4
#define PREFIX_VEX_2B       0xc5
#define PREFIX_EVEX         0x62
#define PREFIX_XOP          0x8f

/****************************************************************************

    addressing methods

    Intel 64 and IA-32 Architectures Software Developer�s Manual, Volume 2 
    Order Number: 325383-055US
    June 2015

****************************************************************************/

enum
{
    AM_NONE = 0,

/* 
    direct address: the instruction has no ModR/M byte; the address of the 
    operand is encoded in the instruction. No base register, index register, 
    or scaling factor can be applied (for example, far JMP (EA)).
*/
    AM_A,

/* 
    the VEX.vvvv field of the VEX prefix selects a general purpose register. 
*/
    AM_B,

/* 
    the reg field of the ModR/M byte selects a control register 
    (for example, MOV (0F20, 0F22)).
*/
    AM_C,

/* 
    the reg field of the ModR/M byte selects a debug register 
    (for example, MOV (0F21, 0F23)). 
*/
    AM_D,       

/* 
    a ModR/M byte follows the opcode and specifies the operand. The operand 
    is either a general-purpose register or a memory address. If it is a 
    memory address, the address is computed from a segment register and any 
    of the following values: a base register, an index register, a scaling 
    factor, a displacement.
*/
    AM_E,           

/* 
    EFLAGS/RFLAGS register 
*/
    AM_F,

/* 
    the reg field of the ModR/M byte selects a general register 
    (for example, AX (000)).
*/
    AM_G,   

/* 
    the VEX.vvvv field of the VEX prefix selects a 128-bit XMM register or a 
    256-bit YMM register, determined by operand type. For legacy SSE 
    encodings this operand does not exist, changing the instruction to
    destructive form.
*/
    AM_H,

/* 
    immediate data: the operand value is encoded in subsequent bytes of the 
    instruction.
*/
    AM_I,

/* 
    the instruction contains a relative offset to be added to the instruction 
    pointer register (for example, JMP (0E9), LOOP).
*/
    AM_J,   

/*
    the upper 4 bits of the 8-bit immediate selects a 128-bit XMM register or 
    a 256-bit YMM register, determined by operand type. 
    (the MSB is ignored in 32-bit mode)
*/
    AM_L,   

/* 
    the ModR/M byte may refer only to memory (for example, BOUND, LES, LDS, 
    LSS, LFS, LGS, CMPXCHG8B).
*/
    AM_M,   

/* 
    the R/M field of the ModR/M byte selects a packed-quadword, 
    MMX technology register.
*/
    AM_N,       

/* 
    the instruction has no ModR/M byte. The offset of the operand is coded as 
    a word or double word (depending on address size attribute) in the 
    instruction. No base register, index register, or scaling factor can be 
    applied (for example, MOV (A0�A3)).
*/
    AM_O,       

/* 
    the reg field of the ModR/M byte selects a packed quadword 
    MMX technology register.
*/
    AM_P,       

/* 
    a ModR/M byte follows the opcode and specifies the operand. The operand 
    is either an MMX technology register or a memory address. If it is a 
    memory address, the address is computed from a segment register and any 
    of the following values: a base register, an index register, a scaling 
    factor, and a displacement.
*/
    AM_Q,

/* 
    the R/M field of the ModR/M byte may refer only to a general register 
    (for example, MOV (0F20-0F23)).
*/
    AM_R,

/* 
    the reg field of the ModR/M byte selects a segment register 
    (for example, MOV (8C,8E)).
*/
    AM_S,

/* 
    the R/M field of the ModR/M byte selects a 128-bit XMM register or a 
    256-bit YMM register, determined by operand type.
*/
    AM_U,

/*
    the reg field of the ModR/M byte selects a 128-bit XMM register or a 
    256-bit YMM register, determined by operand type.
*/
    AM_V,

/* 
    a ModR/M byte follows the opcode and specifies the operand. The operand 
    is either a 128-bit XMM register, a 256-bit YMM register (determined by 
    operand type), or a memory address. If it is a memory address, the 
    address is computed from a segment register and any of the following 
    values: a base register, an index register, a scaling factor, and a 
    displacement.
*/
    AM_W,       

/* 
    memory addressed by the DS:rSI register pair (for example, MOVS, CMPS, 
    OUTS, or LODS).
*/
    AM_X,

/* 
    memory addressed by the ES:rDI register pair (for example, MOVS, CMPS, 
    INS, STOS, or SCAS).
*/
    AM_Y,

/* 
    implicit immediate data of value 1 
*/
    AM_I1,

/* 
    implicit immediate data of value 3 
*/
    AM_I3,          

/* 
    register RAX/EAX/AX depending on the operand's size attribute
    (no REX.B extension) 
*/
    AM_rAX,
    AM_rCX,
    AM_rDX,
    AM_rBX,
    AM_rSP,
    AM_rBP,
    AM_rSI,
    AM_rDI,

/* 
    register RAX/EAX/AX, R8/R8D/R8W depending on the operand's size 
    attribute (with REX.B extension) 

    when any REX prefix is used, SPL, BPL, SIL and DIL are used. 
    otherwise, without any REX prefix AH, CH, DH and BH are used. 
*/
    AM_rAX_r8,
    AM_rCX_r9,
    AM_rDX_r10,
    AM_rBX_r11, 
    AM_rSP_r12,
    AM_rBP_r13,
    AM_rSI_r14,
    AM_rDI_r15,

/* 
    register ST(0), FPU/x87 extension 
*/
    AM_ST0,     
    AM_ST1,     
    AM_ST2, 
    AM_ST3, 
    AM_ST4, 
    AM_ST5, 
    AM_ST6, 
    AM_ST7, 

/* 
    register CS/DS/ES/... segment registers 
*/
    AM_ES,  
    AM_CS,
    AM_SS,  
    AM_DS,
    AM_FS,
    AM_GS,

    AM_MAX
};

/****************************************************************************

    operand types

    Intel 64 and IA-32 Architectures Software Developer�s Manual, Volume 2 
    Order Number: 325383-055US
    June 2015

****************************************************************************/

enum 
{
    OT_NONE = 0,

/* 
    two one-word operands in memory or two double-word operands in memory, 
    depending on operand-size attribute (used only by the BOUND instruction).
*/
    OT_A,

/* 
    byte, regardless of operand-size attribute. 
*/
    OT_B,

/*  
    byte or word, depending on operand-size attribute.

    OT_C,
*/
    
/* 
    doubleword, regardless of operand-size attribute.
*/
    OT_D,

/* 
    double-quadword, regardless of operand-size attribute. 
*/
    OT_DQ,

/* 
    32-bit, 48-bit, or 80-bit pointer, depending on operand-size attribute.
*/
    OT_P,

/* 
    128-bit or 256-bit packed double-precision floating-point data.
*/
    OT_PD,

/* 
    quadword MMX technology register (for example: mm0).
*/
    OT_PI,  

/* 
    128-bit or 256-bit packed single-precision floating-point data.
*/
    OT_PS,  

/* 
    quadword, regardless of operand-size attribute.
*/
    OT_Q,

/* 
    quad-quadword (256-bits), regardless of operand-size attribute.
*/
    OT_QQ,

/* 
    6-byte or 10-byte pseudo-descriptor.
*/
    OT_S,

/* 
    scalar element of a 128-bit double-precision floating data.
*/
    OT_SD,

/* 
    scalar element of a 128-bit single-precision floating data.
*/
    OT_SS,

/* 
    doubleword integer register (for example: eax).
*/
    OT_SI,

/* 
    10-byte data, regardless of operand-size attribute.
    tbyte, dt
*/
    OT_T,   

/* 
    word, doubleword or quadword (in 64-bit mode), depending on operand-size 
    attribute.
*/
    OT_V,

/* 
    word, regardless of operand-size attribute. 
*/
    OT_W,

/* 
    dq or qq based on the operand-size attribute.
*/
    OT_X,

/* 
    doubleword or quadword (in 64-bit mode), depending on operand-size 
    attribute.
*/
    OT_Y,

/* 
    word for 16-bit operand-size or doubleword for 32 or 64-bit operand-size.   
*/
    OT_Z,

/* 
    64- or 128-bit depending on VEX.L   
*/
    OT_OQ,

    OT_MAX
};

/****************************************************************************

    operands

****************************************************************************/

#define O_NONE          AM_NONE, OT_NONE

/*
    general-purpose register operands
*/
#define O_AL            AM_rAX,         OT_B
#define O_CL            AM_rCX,         OT_B
#define O_AX            AM_rAX,         OT_W
#define O_DX            AM_rDX,         OT_W
#define O_eAX           AM_rAX,         OT_Z
#define O_eCX           AM_rCX,         OT_Z
#define O_eDX           AM_rDX,         OT_Z
#define O_eBX           AM_rBX,         OT_Z
#define O_eSP           AM_rSP,         OT_Z
#define O_eBP           AM_rBP,         OT_Z
#define O_eSI           AM_rSI,         OT_Z
#define O_eDI           AM_rDI,         OT_Z
#define O_rAX           AM_rAX,         OT_V
#define O_rDX           AM_rDX,         OT_V
#define O_rAX_r8        AM_rAX_r8,      OT_V
#define O_rCX_r9        AM_rCX_r9,      OT_V
#define O_rDX_r10       AM_rDX_r10,     OT_V
#define O_rBX_r11       AM_rBX_r11,     OT_V
#define O_rSP_r12       AM_rSP_r12,     OT_V
#define O_rBP_r13       AM_rBP_r13,     OT_V
#define O_rSI_r14       AM_rSI_r14,     OT_V
#define O_rDI_r15       AM_rDI_r15,     OT_V
#define O_AL_r8L        AM_rAX_r8,      OT_B
#define O_CL_r9L        AM_rCX_r9,      OT_B
#define O_DL_r10L       AM_rDX_r10,     OT_B
#define O_BL_r11L       AM_rBX_r11,     OT_B
#define O_AH_r12L       AM_rSP_r12,     OT_B
#define O_CH_r13L       AM_rBP_r13,     OT_B
#define O_DH_r14L       AM_rSI_r14,     OT_B
#define O_BH_r15L       AM_rDI_r15,     OT_B

/*
    segment register operands
*/
#define O_ES            AM_ES,          OT_NONE
#define O_CS            AM_CS,          OT_NONE
#define O_SS            AM_SS,          OT_NONE
#define O_DS            AM_DS,          OT_NONE
#define O_FS            AM_FS,          OT_NONE
#define O_GS            AM_GS,          OT_NONE

/*
    FPU register operands
*/
#define O_ST0           AM_ST0,         OT_NONE
#define O_ST1           AM_ST1,         OT_NONE
#define O_ST2           AM_ST2,         OT_NONE
#define O_ST3           AM_ST3,         OT_NONE
#define O_ST4           AM_ST4,         OT_NONE
#define O_ST5           AM_ST5,         OT_NONE
#define O_ST6           AM_ST6,         OT_NONE
#define O_ST7           AM_ST7,         OT_NONE

#define O_Ap            AM_A,           OT_P
#define O_By            AM_B,           OT_Y
#define O_Cy            AM_C,           OT_Y
#define O_Dy            AM_D,           OT_Y
#define O_Eb            AM_E,           OT_B
#define O_Ed            AM_E,           OT_D
#define O_Ep            AM_E,           OT_P
#define O_Ev            AM_E,           OT_V
#define O_Ew            AM_E,           OT_W
#define O_Ey            AM_E,           OT_Y
#define O_Fv            AM_F,           OT_V
#define O_Gb            AM_G,           OT_B
#define O_Gd            AM_G,           OT_D
#define O_Gv            AM_G,           OT_V
#define O_Gw            AM_G,           OT_W
#define O_Gy            AM_G,           OT_Y
#define O_Gz            AM_G,           OT_Z
#define O_Gq            AM_G,           OT_Q
#define O_Hdq           AM_H,           OT_DQ
#define O_Hpd           AM_H,           OT_PD
#define O_Hps           AM_H,           OT_PS
#define O_Hq            AM_H,           OT_Q
#define O_Hqq           AM_H,           OT_QQ
#define O_Hsd           AM_H,           OT_SD
#define O_Hss           AM_H,           OT_SS
#define O_Hx            AM_H,           OT_X
#define O_I1            AM_I1,          OT_B
#define O_I3            AM_I3,          OT_B
#define O_Ib            AM_I,           OT_B
#define O_Id            AM_I,           OT_D
#define O_Iv            AM_I,           OT_V
#define O_Iw            AM_I,           OT_W
#define O_Iz            AM_I,           OT_Z
#define O_Jb            AM_J,           OT_B
#define O_Jz            AM_J,           OT_Z
#define O_Lx            AM_L,           OT_X
#define O_Lss           AM_L,           OT_SS
#define O_M             AM_M,           OT_NONE
#define O_Ma            AM_M,           OT_A
#define O_Mb            AM_M,           OT_B
#define O_Md            AM_M,           OT_D
#define O_Mdq           AM_M,           OT_DQ
#define O_Mp            AM_M,           OT_P
#define O_Mpd           AM_M,           OT_PD
#define O_Mps           AM_M,           OT_PS
#define O_Mq            AM_M,           OT_Q
#define O_Moq           AM_M,           OT_OQ
#define O_Ms            AM_M,           OT_S
#define O_Mt            AM_M,           OT_T
#define O_Mv            AM_M,           OT_V
#define O_Mw            AM_M,           OT_W
#define O_Mx            AM_M,           OT_X
#define O_My            AM_M,           OT_Y
#define O_Nq            AM_N,           OT_Q
#define O_Ob            AM_O,           OT_B
#define O_Ov            AM_O,           OT_V
#define O_Ppi           AM_P,           OT_PI
#define O_Pq            AM_P,           OT_Q
#define O_Py            AM_P,           OT_Y
#define O_Qd            AM_Q,           OT_D
#define O_Qpi           AM_Q,           OT_PI
#define O_Qq            AM_Q,           OT_Q
#define O_Rd            AM_R,           OT_D
#define O_Rb            AM_R,           OT_B
#define O_Rw            AM_R,           OT_W
#define O_Rq            AM_R,           OT_Q
#define O_Ry            AM_R,           OT_Y
#define O_Rdq           AM_R,           OT_DQ
#define O_Rv            AM_R,           OT_V
#define O_Ry            AM_R,           OT_Y
#define O_Sw            AM_S,           OT_W
#define O_Udq           AM_U,           OT_DQ
#define O_Upd           AM_U,           OT_PD
#define O_Ups           AM_U,           OT_PS
#define O_Uq            AM_U,           OT_Q
#define O_Ux            AM_U,           OT_X
#define O_Uss           AM_U,           OT_SS
#define O_Vdq           AM_V,           OT_DQ
#define O_Vpd           AM_V,           OT_PD
#define O_Vpi           AM_V,           OT_PI
#define O_Vps           AM_V,           OT_PS
#define O_Vq            AM_V,           OT_Q
#define O_Vqq           AM_V,           OT_QQ
#define O_Vsd           AM_V,           OT_SD
#define O_Vss           AM_V,           OT_SS
#define O_Vx            AM_V,           OT_X
#define O_Vy            AM_V,           OT_Y
#define O_Wd            AM_W,           OT_D
#define O_Wdq           AM_W,           OT_DQ
#define O_Wpd           AM_W,           OT_PD
#define O_Wpi           AM_W,           OT_PI
#define O_Wps           AM_W,           OT_PS
#define O_Wq            AM_W,           OT_Q
#define O_Woq           AM_W,           OT_OQ
#define O_Wqq           AM_W,           OT_QQ
#define O_Wsd           AM_W,           OT_SD
#define O_Wss           AM_W,           OT_SS
#define O_Wx            AM_W,           OT_X
#define O_Xb            AM_X,           OT_B
#define O_Xv            AM_X,           OT_V
#define O_Xz            AM_X,           OT_Z
#define O_Yb            AM_Y,           OT_B
#define O_Yv            AM_Y,           OT_V
#define O_Yz            AM_Y,           OT_Z

/****************************************************************************

    property flags

****************************************************************************/

enum
{
    PF_NONE = 0,

/* 
    the instruction is invalid or not encodable in 64-bit mode. 40 through 
    4F (single-byte INC and DEC) are REX prefix combinations when in 64-bit 
    mode (use FE/FF Grp 4 and 5 for INC and DEC).
*/
    PF_I64 = (1 << 0),

/*
    instruction is only available when in 64-bit mode.
*/
    PF_O64 = (1 << 1),

/*
    the operand size is forced to a 64-bit operand size when in 64-bit mode 
    (prefixes that change operand size are ignored for this instruction in 
    64-bit mode).

*/
    PF_F64 = (1 << 2),

/*
    when in 64-bit mode, instruction defaults to 64-bit operand size and 
    cannot encode 32-bit operand size.
*/
    PF_D64 = (1 << 3),

/*
    can accept a LOCK prefix.
*/
    PF_LOCK = (1 << 4),

/*
    can accept a REP prefix.
*/
    PF_REP = (1 << 5),

/*
    can accept a REP prefix.
*/
    PF_REPE_REPNE = (1 << 6),

/*
    can accept VEX prefix.
*/
    PF_VEX = (1 << 7),

/*
    can only accept a 128-bit VEX prefix.
*/
    PF_VEX128 = (1 << 8),

/*
    can only accept a 256-bit VEX prefix.
*/
    PF_VEX256 = (1 << 9),

/*
    requires VEX prefix.
*/
    PF_OVEX = (1 << 10),

/*
    last byte encodes a sse/vex condition code
*/
    PF_CC = (1 << 11),

/*
    last byte encodes a xop condition code
*/
    PF_XOPCC = (1 << 12),

/*
    the instruction has prefixes N/A
*/
    PF_PFXNA = (1 << 13),

/*
    the instruction supports vectored sib vm32x (AVX2+)
*/
    PF_VSIB_X = (1 << 14),

/*
    the instruction supports vectored sib vm32y (AVX2+)
*/
    PF_VSIB_Y = (1 << 15),

/*
    the instruction supports vectored sib vm32z (AVX2+)
*/
    PF_VSIB_Z = (1 << 16),

/*
    the instruction supports vectored sib vm32x/y/z based on L (AVX2+)
*/
    PF_VSIB_L = (1 << 17),

/*
    sign-extension for imm8/16/32
*/
    PF_SIGN = (1 << 18)

};

/****************************************************************************

    table indexes and lookup methods

****************************************************************************/

#define TABLE_ID(i) TABLE_ID_##i
#define TABLE_LOOKUP_METHOD(i) TABLE_LM_##i

enum
{
    /* addressing size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_LOOKUP_METHOD(ASIZE) = 0, 

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_LOOKUP_METHOD(OSIZE),

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_LOOKUP_METHOD(OSIZE_VEX),

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_LOOKUP_METHOD(OSIZE_XOP),

    /* dasm mode:  0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_LOOKUP_METHOD(DMODE),

    /* modr/m byte reg/nnn field */
    TABLE_LOOKUP_METHOD(MODRM_REG),

    /* modr/m byte r/m field */
    TABLE_LOOKUP_METHOD(MODRM_RM),  

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_LOOKUP_METHOD(MODRM_MOD), 

    /* modr/m byte:  index = modr/m byte - C0h */
    TABLE_LOOKUP_METHOD(FPU),

    /* last immediate byte is the opcode */
    TABLE_LOOKUP_METHOD(3DNOW),

    /* byte */
    TABLE_LOOKUP_METHOD(BYTE)
};

enum
{
    /* 1-byte table ids */
    TABLE_ID(1B) = 0,
    TABLE_ID(60),
    TABLE_ID(61),
    TABLE_ID(63),
    TABLE_ID(6D),
    TABLE_ID(6F),
    TABLE_ID(80),
    TABLE_ID(81),
    TABLE_ID(82),
    TABLE_ID(83),
    TABLE_ID(8F),
    TABLE_ID(98),
    TABLE_ID(99),
    TABLE_ID(9C),
    TABLE_ID(9D),
    TABLE_ID(A5),
    TABLE_ID(A7),
    TABLE_ID(AB),
    TABLE_ID(AD),
    TABLE_ID(AF),
    TABLE_ID(C0),
    TABLE_ID(C1),
    TABLE_ID(C6),
    TABLE_ID(C7),
    TABLE_ID(CF),
    TABLE_ID(D0),
    TABLE_ID(D1),
    TABLE_ID(D2),
    TABLE_ID(D3),
    TABLE_ID(D8),
    TABLE_ID(D9),
    TABLE_ID(DA),
    TABLE_ID(DB),
    TABLE_ID(DC),
    TABLE_ID(DD),
    TABLE_ID(DE),
    TABLE_ID(DF),
    TABLE_ID(E3),
    TABLE_ID(F6),
    TABLE_ID(F7),
    TABLE_ID(FE),
    TABLE_ID(FF),
    TABLE_ID(D8_MOD_N11),
    TABLE_ID(D8_MOD_11),
    TABLE_ID(D9_MOD_N11),
    TABLE_ID(D9_MOD_11),
    TABLE_ID(DA_MOD_N11),
    TABLE_ID(DA_MOD_11),
    TABLE_ID(DB_MOD_N11),
    TABLE_ID(DB_MOD_11),
    TABLE_ID(DC_MOD_N11),
    TABLE_ID(DC_MOD_11),
    TABLE_ID(DD_MOD_N11),
    TABLE_ID(DD_MOD_11),
    TABLE_ID(DE_MOD_N11),
    TABLE_ID(DE_MOD_11),
    TABLE_ID(DF_MOD_N11),
    TABLE_ID(DF_MOD_11),

    /* 2-byte table ids */
    TABLE_ID(0F),
    TABLE_ID(0F_00),
    TABLE_ID(0F_01),
    TABLE_ID(0F_0D),
    TABLE_ID(0F_0F), /* 3DNow! */
    TABLE_ID(0F_12),
    TABLE_ID(0F_16),
    TABLE_ID(0F_18),
    TABLE_ID(0F_19),
    TABLE_ID(0F_1C),
    TABLE_ID(0F_1D),
    TABLE_ID(0F_1E),
    TABLE_ID(0F_1F),
    TABLE_ID(0F_6E),
    TABLE_ID(0F_71),
    TABLE_ID(0F_71_REG2),
    TABLE_ID(0F_71_REG4),
    TABLE_ID(0F_71_REG6),
    TABLE_ID(0F_72),
    TABLE_ID(0F_72_REG2),
    TABLE_ID(0F_72_REG4), 
    TABLE_ID(0F_72_REG6),
    TABLE_ID(0F_73),
    TABLE_ID(0F_73_REG2),
    TABLE_ID(0F_73_REG6),
    TABLE_ID(0F_7E),
    TABLE_ID(0F_AE),
    TABLE_ID(0F_B9),
    TABLE_ID(0F_BA),
    TABLE_ID(0F_C4),
    TABLE_ID(0F_C7),
    TABLE_ID(0F_00_REG0),
    TABLE_ID(0F_00_REG1),
    TABLE_ID(0F_01_REG0),
    TABLE_ID(0F_01_REG1),
    TABLE_ID(0F_01_REG2),
    TABLE_ID(0F_01_REG3),
    TABLE_ID(0F_01_REG4),
    TABLE_ID(0F_01_REG7),
    TABLE_ID(0F_01_REG0_RM),
    TABLE_ID(0F_01_REG1_RM),
    TABLE_ID(0F_01_REG2_RM),
    TABLE_ID(0F_01_REG3_RM),
    TABLE_ID(0F_01_REG7_RM),
    TABLE_ID(0F_18_REG0),
    TABLE_ID(0F_18_REG1),
    TABLE_ID(0F_18_REG2),
    TABLE_ID(0F_18_REG3),
    TABLE_ID(0F_AE_REG0),
    TABLE_ID(0F_AE_REG1),
    TABLE_ID(0F_AE_REG2),
    TABLE_ID(0F_AE_REG3),
    TABLE_ID(0F_AE_REG4),
    TABLE_ID(0F_AE_REG5),
    TABLE_ID(0F_AE_REG6),
    TABLE_ID(0F_AE_REG7),
    TABLE_ID(0F_C7_REG1),
    TABLE_ID(0F_C7_REG3),
    TABLE_ID(0F_C7_REG4),
    TABLE_ID(0F_C7_REG5),
    TABLE_ID(0F_C7_REG6),
    TABLE_ID(0F_C7_REG7),
    TABLE_ID(66_0F),
    TABLE_ID(66_0F_19),
    TABLE_ID(66_0F_1C),
    TABLE_ID(66_0F_1D),
    TABLE_ID(66_0F_1E),
    TABLE_ID(66_0F_1F),
    TABLE_ID(66_0F_6E),
    TABLE_ID(66_0F_71),
    TABLE_ID(66_0F_71_REG2),
    TABLE_ID(66_0F_71_REG4),
    TABLE_ID(66_0F_71_REG6),
    TABLE_ID(66_0F_72),
    TABLE_ID(66_0F_72_REG2),
    TABLE_ID(66_0F_72_REG4),
    TABLE_ID(66_0F_72_REG6),
    TABLE_ID(66_0F_73),
    TABLE_ID(66_0F_73_REG2),
    TABLE_ID(66_0F_73_REG3),
    TABLE_ID(66_0F_73_REG6),
    TABLE_ID(66_0F_73_REG7),
    TABLE_ID(66_0F_78),
    TABLE_ID(66_0F_7E),
    TABLE_ID(66_0F_AE),
    TABLE_ID(66_0F_C4),
    TABLE_ID(66_0F_C7), 
    TABLE_ID(66_0F_C7_REG6),
    TABLE_ID(F3_0F),
    TABLE_ID(F3_0F_01),
    TABLE_ID(F3_0F_01_REG5),
    TABLE_ID(F3_0F_01_REG5_RM),
    TABLE_ID(F3_0F_19),
    TABLE_ID(F3_0F_1C),
    TABLE_ID(F3_0F_1D),
    TABLE_ID(F3_0F_1E),
    TABLE_ID(F3_0F_1E_REG1),
    TABLE_ID(F3_0F_1E_REG7_RM),
    TABLE_ID(F3_0F_1F),
    TABLE_ID(F3_0F_71),
    TABLE_ID(F3_0F_72),
    TABLE_ID(F3_0F_73),
    TABLE_ID(F3_0F_AE),
    TABLE_ID(F3_0F_AE_REG5),
    TABLE_ID(F3_0F_C7),
    TABLE_ID(F3_0F_C7_REG6),
    TABLE_ID(F3_0F_C7_REG7),
    TABLE_ID(F2_0F),
    TABLE_ID(F2_0F_19),
    TABLE_ID(F2_0F_1C),
    TABLE_ID(F2_0F_1D),
    TABLE_ID(F2_0F_1E),
    TABLE_ID(F2_0F_1F),
    TABLE_ID(F2_0F_71),
    TABLE_ID(F2_0F_72),
    TABLE_ID(F2_0F_73),
    TABLE_ID(F2_0F_AE),

    /* 3-byte table ids */
    TABLE_ID(0F_38),
    TABLE_ID(0F_38_F3),
    TABLE_ID(0F_38_F6),
    TABLE_ID(0F_3A),
    TABLE_ID(66_0F_38),
    TABLE_ID(66_0F_38_20),
    TABLE_ID(66_0F_38_21),
    TABLE_ID(66_0F_38_22),
    TABLE_ID(66_0F_38_23),
    TABLE_ID(66_0F_38_24),
    TABLE_ID(66_0F_38_25),
    TABLE_ID(66_0F_38_30),
    TABLE_ID(66_0F_38_31),
    TABLE_ID(66_0F_38_32),
    TABLE_ID(66_0F_38_33),
    TABLE_ID(66_0F_38_34),
    TABLE_ID(66_0F_38_35),
    TABLE_ID(66_0F_38_45),
    TABLE_ID(66_0F_38_47),
    TABLE_ID(66_0F_38_8C),
    TABLE_ID(66_0F_38_8E),
    TABLE_ID(66_0F_38_90),
    TABLE_ID(66_0F_38_91),
    TABLE_ID(66_0F_38_92),
    TABLE_ID(66_0F_38_93),
    TABLE_ID(66_0F_38_96),
    TABLE_ID(66_0F_38_97),
    TABLE_ID(66_0F_38_98),
    TABLE_ID(66_0F_38_99),
    TABLE_ID(66_0F_38_9A),
    TABLE_ID(66_0F_38_9B),
    TABLE_ID(66_0F_38_9C),
    TABLE_ID(66_0F_38_9D),
    TABLE_ID(66_0F_38_9E),
    TABLE_ID(66_0F_38_9F),
    TABLE_ID(66_0F_38_A6),
    TABLE_ID(66_0F_38_A7),
    TABLE_ID(66_0F_38_A8),
    TABLE_ID(66_0F_38_A9),
    TABLE_ID(66_0F_38_AA),
    TABLE_ID(66_0F_38_AB),
    TABLE_ID(66_0F_38_AC),
    TABLE_ID(66_0F_38_AD),
    TABLE_ID(66_0F_38_AE),
    TABLE_ID(66_0F_38_AF),
    TABLE_ID(66_0F_38_B6),
    TABLE_ID(66_0F_38_B7),
    TABLE_ID(66_0F_38_B8),
    TABLE_ID(66_0F_38_B9),
    TABLE_ID(66_0F_38_BA),
    TABLE_ID(66_0F_38_BB),
    TABLE_ID(66_0F_38_BC),
    TABLE_ID(66_0F_38_BD),
    TABLE_ID(66_0F_38_BE),
    TABLE_ID(66_0F_38_BF),
    TABLE_ID(66_0F_38_F5),
    TABLE_ID(66_0F_3A),
    TABLE_ID(66_0F_3A_14),
    TABLE_ID(66_0F_3A_15),
    TABLE_ID(66_0F_3A_16),
    TABLE_ID(66_0F_3A_20),
    TABLE_ID(66_0F_3A_21),
    TABLE_ID(66_0F_3A_22),
    TABLE_ID(F3_0F_38),
    TABLE_ID(F3_0F_3A),
    TABLE_ID(F2_0F_38),
    TABLE_ID(F2_0F_3A),

    /* XOP */
    TABLE_ID(XOP_8),
    TABLE_ID(XOP_8_A2),
    TABLE_ID(XOP_8_A3),
    TABLE_ID(XOP_9), 
    TABLE_ID(XOP_9_1),
    TABLE_ID(XOP_9_2),
    TABLE_ID(XOP_9_12),
    TABLE_ID(XOP_9_90), 
    TABLE_ID(XOP_9_91),
    TABLE_ID(XOP_9_92),
    TABLE_ID(XOP_9_93),
    TABLE_ID(XOP_9_94),
    TABLE_ID(XOP_9_95),
    TABLE_ID(XOP_9_96),
    TABLE_ID(XOP_9_97),
    TABLE_ID(XOP_9_98),
    TABLE_ID(XOP_9_99),
    TABLE_ID(XOP_9_9A),
    TABLE_ID(XOP_9_9B), 
    TABLE_ID(XOP_A),
    TABLE_ID(XOP_A_12),

    /* FMA4 */
    TABLE_ID(66_0F_3A_69),

    TABLE_ID(66_0F_3A_5C),
    TABLE_ID(66_0F_3A_5D),
    TABLE_ID(66_0F_3A_5E),
    TABLE_ID(66_0F_3A_5F),
    TABLE_ID(66_0F_3A_68),
    TABLE_ID(66_0F_3A_6A),
    TABLE_ID(66_0F_3A_6B),
    TABLE_ID(66_0F_3A_6C),
    TABLE_ID(66_0F_3A_6D),
    TABLE_ID(66_0F_3A_6E),
    TABLE_ID(66_0F_3A_6F),
    TABLE_ID(66_0F_3A_78),
    TABLE_ID(66_0F_3A_79),
    TABLE_ID(66_0F_3A_7A),
    TABLE_ID(66_0F_3A_7B),
    TABLE_ID(66_0F_3A_7C),
    TABLE_ID(66_0F_3A_7D),
    TABLE_ID(66_0F_3A_7E),
    TABLE_ID(66_0F_3A_7F),

    /* do not use to dereference! */
    TABLE_ID(NONE)
};

/****************************************************************************

    table structs

****************************************************************************/

typedef struct
{
    uint8_t am; /* addressing method */
    uint8_t ot; /* operand type */

} x86_table_operand_t;

typedef struct
{
    uint16_t                table_id;       /* table id */
    uint8_t                 iset;           /* instruction set */
    uint16_t                mnem_id;        /* mnemonic id */

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

    char*                   mnem_str;       /* mnemonic string */

#endif

    uint32_t                properties;     /* properties */
    x86_table_operand_t     operands[4];    /* operands */
    
} x86_table_entry_t;

typedef struct
{

#if defined(X86_DASM_DEBUG)

    char*                   table_name;

#endif

    const x86_table_entry_t*    table;
    uint8_t                     lookup_method;

} x86_table_link_t;

/****************************************************************************

    macro acrobatics to overload the OP() macro

****************************************************************************/

#define EXPAND(x) x
#define OPERAND(x) {x}

#define OP_0 { \
    OPERAND(O_NONE), \
    OPERAND(O_NONE), \
    OPERAND(O_NONE), \
    OPERAND(O_NONE) }

#define OP_1(_1) { \
    OPERAND(O_##_1), \
    OPERAND(O_NONE), \
    OPERAND(O_NONE), \
    OPERAND(O_NONE) }

#define OP_2(_1, _2) { \
    OPERAND(O_##_1), \
    OPERAND(O_##_2), \
    OPERAND(O_NONE), \
    OPERAND(O_NONE) }

#define OP_3(_1, _2, _3) { \
    OPERAND(O_##_1), \
    OPERAND(O_##_2), \
    OPERAND(O_##_3), \
    OPERAND(O_NONE) }

#define OP_4(_1, _2, _3, _4) { \
    OPERAND(O_##_1), \
    OPERAND(O_##_2), \
    OPERAND(O_##_3), \
    OPERAND(O_##_4) }

#define PP_NARG(...) EXPAND(PP_NARG_(__VA_ARGS__, PP_RSEQ_N()))
#define PP_NARG_(...) EXPAND(PP_ARG_N(__VA_ARGS__))
#define PP_ARG_N(_1, _2, _3, _4, N, ...) N
#define PP_RSEQ_N() 4, 3, 2, 1, 0

#define OP_(N) OP_##N
#define OP_EVAL(N) OP_(N)

#define OP(...) \
    EXPAND(OP_EVAL(EXPAND(PP_NARG(__VA_ARGS__)))(__VA_ARGS__))

/****************************************************************************

    table macros

****************************************************************************/

#define TABLE_NAME(_1) table_##_1 

#define TABLE_BEGIN(_1) \
    static const x86_table_entry_t TABLE_NAME(_1)[] = {

#define TABLE_END(_1) \
    };

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

#define TABLE_ENTRY(_1, _2, _3, _4, _5) { \
    /* table id  */         TABLE_ID(NONE), \
    /* instruction set */   _4, \
    /* mnemonic id */       _2, \
    /* mnemonic string */   _1, \
    /* properties */        _3, \
    /* operands */          _5, }   

#define TABLE_ENTRY_INVALID() { \
    /* table id  */         TABLE_ID(NONE), \
    /* instruction set */   X86_ISET_NONE, \
    /* mnemonic id */       X86_MN_INVALID, \
    /* mnemonic string */   NULL, \
    /* properties */        PF_NONE, \
    /* operands */          OP_0 }

#define TABLE_ENTRY_ESCAPE(_1) { \
    /* table id  */         TABLE_ID(_1), \
    /* instruction set */   X86_ISET_NONE, \
    /* mnemonic id */       X86_MN_INVALID, \
    /* mnemonic string */   NULL, \
    /* properties */        PF_NONE, \
    /* operands */          OP_0 }

#else

#define TABLE_ENTRY(_1, _2, _3, _4, _5) { \
    /* table id  */         TABLE_ID(NONE), \
    /* instruction set */   _4, \
    /* mnemonic id */       _2, \
    /* properties */        _3, \
    /* operands */          _5, }   

#define TABLE_ENTRY_INVALID() { \
    /* table id  */         TABLE_ID(NONE), \
    /* instruction set */   X86_ISET_NONE, \
    /* mnemonic id */       X86_MN_INVALID, \
    /* properties */        PF_NONE, \
    /* operands */          OP_0 }

#define TABLE_ENTRY_ESCAPE(_1) { \
    /* table id  */         TABLE_ID(_1), \
    /* instruction set */   X86_ISET_NONE, \
    /* mnemonic id */       X86_MN_INVALID, \
    /* properties */        PF_NONE, \
    /* operands */          OP_0 }

#endif

#if defined(X86_DASM_DEBUG)

#define TABLE_LINK(_1, _2) { \
    /* table_name */        #_1, \
    /* table */             TABLE_NAME(_1), \
    /* lookup method */     TABLE_LOOKUP_METHOD(_2) }

#else

#define TABLE_LINK(_1, _2) { \
    /* table */             TABLE_NAME(_1), \
    /* lookup method */     TABLE_LOOKUP_METHOD(_2) }

#endif

#define EFLAGS_ENTRY(_1, _2, _3, _4, _5, _6, _7, _8) \
    { X86_FLAG_##_1, X86_FLAG_##_2, X86_FLAG_##_3, X86_FLAG_##_4, \
      X86_FLAG_##_5, X86_FLAG_##_6, X86_FLAG_##_7, X86_FLAG_##_8 }

/****************************************************************************

    declarations / exports

****************************************************************************/

typedef struct
{
    uint8_t o : 3; /* overflow flag */
    uint8_t d : 3; /* direction flag */
    uint8_t i : 3; /* interrupt flag */
    uint8_t s : 3; /* sign flag */
    uint8_t z : 3; /* zero flag */
    uint8_t a : 3; /* aux carry flag */
    uint8_t p : 3; /* parity flag */
    uint8_t c : 3; /* carry flag */

} x86_eflags_t;

extern const x86_table_link_t x86_table_links[];
extern const x86_eflags_t x86_eflags_table[];

x86_eflags_t x86_eflags_get(uint16_t mnem);

#ifdef __cplusplus
    }
#endif

#endif //_DASM_H_