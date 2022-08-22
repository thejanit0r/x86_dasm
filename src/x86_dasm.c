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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#include "x86_dasm.h"

#define dbg_print(msg, ...)             \
    do {                                \
        printf(msg, ## __VA_ARGS__);    \
    } while(false)

#if defined(X86_DASM_DEBUG)

    #define dbg_msg(msg, ...) \
        dbg_print("[*] %s: " msg "\n", __FUNCTION__, ##__VA_ARGS__) 

    #define dbg_err(msg, ...) \
        dbg_print("[!] %s: " msg "\n", __FUNCTION__, ##__VA_ARGS__) 

#else

    #define dbg_msg(msg, ...)
    #define dbg_err(msg, ...)

#endif 

#if 0
    #define strcpy      <define function>
    #define strcat      <define function>
    #define strstr      <define function>
    #define strncat     <define function>
    #define strchr      <define function>
    #define sprintf     <define function>
    #define memset      <define function>
    #define memcpy      <define function>
#endif

/****************************************************************************

    shortcuts

****************************************************************************/

#define REX_B               _REX_B(x86_dctx->pfx_rex)
#define REX_X               _REX_X(x86_dctx->pfx_rex)
#define REX_R               _REX_R(x86_dctx->pfx_rex)
#define REX_W               _REX_W(x86_dctx->pfx_rex)

#define VEX_2B_PP           _VEX_2B_PP(x86_dctx->pfx_vex[0])
#define VEX_2B_L            _VEX_2B_L(x86_dctx->pfx_vex[0])
#define VEX_2B_VVVV         _VEX_2B_VVVV(x86_dctx->pfx_vex[0])
#define VEX_2B_R            _VEX_2B_R(x86_dctx->pfx_vex[0])

#define VEX_3B_MMMMM        _VEX_3B_MMMMM(x86_dctx->pfx_vex[0])
#define VEX_3B_B            _VEX_3B_B(x86_dctx->pfx_vex[0])
#define VEX_3B_X            _VEX_3B_X(x86_dctx->pfx_vex[0])
#define VEX_3B_R            _VEX_3B_R(x86_dctx->pfx_vex[0])
#define VEX_3B_PP           _VEX_3B_PP(x86_dctx->pfx_vex[1])
#define VEX_3B_L            _VEX_3B_L(x86_dctx->pfx_vex[1])
#define VEX_3B_VVVV         _VEX_3B_VVVV(x86_dctx->pfx_vex[1])
#define VEX_3B_W            _VEX_3B_W(x86_dctx->pfx_vex[1])

#define XOP_MMMMM           _XOP_MMMMM(x86_dctx->pfx_xop[0])
#define XOP_B               _XOP_B(x86_dctx->pfx_xop[0])
#define XOP_X               _XOP_X(x86_dctx->pfx_xop[0])
#define XOP_R               _XOP_R(x86_dctx->pfx_xop[0])
#define XOP_PP              _XOP_PP(x86_dctx->pfx_xop[1])
#define XOP_L               _XOP_L(x86_dctx->pfx_xop[1])
#define XOP_VVVV            _XOP_VVVV(x86_dctx->pfx_xop[1])
#define XOP_W               _XOP_W(x86_dctx->pfx_xop[1])

#define EVEX_B              _EVEX_B(x86_dctx->pfx_vex[0])
#define EVEX_X              _EVEX_X(x86_dctx->pfx_vex[0])
#define EVEX_R              _EVEX_R(x86_dctx->pfx_vex[0])
#define EVEX_RR             _EVEX_RR(x86_dctx->pfx_vex[0])
#define EVEX_MM             _EVEX_MM(x86_dctx->pfx_vex[0])
#define EVEX_PP             _EVEX_PP(x86_dctx->pfx_vex[1])
#define EVEX_W              _EVEX_W(x86_dctx->pfx_vex[1])
#define EVEX_VVVV           _EVEX_VVVV(x86_dctx->pfx_vex[1])
#define EVEX_Z              _EVEX_Z(x86_dctx->pfx_vex[2])
#define EVEX_LL             _EVEX_LL(x86_dctx->pfx_vex[2])
#define EVEX_L              _EVEX_L(x86_dctx->pfx_vex[2])
#define EVEX_BB             _EVEX_BB(x86_dctx->pfx_vex[2])
#define EVEX_VV             _EVEX_VV(x86_dctx->pfx_vex[2])
#define EVEX_AAA            _EVEX_AAA(x86_dctx->pfx_vex[2])

/****************************************************************************

    tables and vars

****************************************************************************/

static const x86_table_link_t* const vex_links[4][4] = 
{
    {
    /* pp: 00    */ &x86_table_links[TABLE_ID(0F)],
                    &x86_table_links[TABLE_ID(0F)], 
                    &x86_table_links[TABLE_ID(0F_38)], 
                    &x86_table_links[TABLE_ID(0F_3A)]
    },
    {
    /* pp: 01 66 */ &x86_table_links[TABLE_ID(66_0F)],
                    &x86_table_links[TABLE_ID(66_0F)], 
                    &x86_table_links[TABLE_ID(66_0F_38)], 
                    &x86_table_links[TABLE_ID(66_0F_3A)]
    },
    {
    /* pp: 10 F3 */ &x86_table_links[TABLE_ID(F3_0F)],
                    &x86_table_links[TABLE_ID(F3_0F)], 
                    &x86_table_links[TABLE_ID(F3_0F_38)], 
                    &x86_table_links[TABLE_ID(F3_0F_3A)]
    },
    {
    /* pp: 11 F2 */ &x86_table_links[TABLE_ID(F2_0F)],
                    &x86_table_links[TABLE_ID(F2_0F)], 
                    &x86_table_links[TABLE_ID(F2_0F_38)], 
                    &x86_table_links[TABLE_ID(F2_0F_3A)]
    }
};

static const x86_table_link_t* const xop_links[4][4] = 
{
    {
    /* pp: 00    */ &x86_table_links[TABLE_ID(XOP_8)],
                    &x86_table_links[TABLE_ID(XOP_9)], 
                    &x86_table_links[TABLE_ID(XOP_A)],
                    NULL
    },
    {
    /* pp: 01 66 */ &x86_table_links[TABLE_ID(XOP_8)],
                    &x86_table_links[TABLE_ID(XOP_9)], 
                    &x86_table_links[TABLE_ID(XOP_A)],
                    NULL
    },
    {
    /* pp: 10 F3 */ &x86_table_links[TABLE_ID(XOP_8)],
                    &x86_table_links[TABLE_ID(XOP_9)], 
                    &x86_table_links[TABLE_ID(XOP_A)],
                    NULL
    },
    {
    /* pp: 11 F2 */ &x86_table_links[TABLE_ID(XOP_8)],
                    &x86_table_links[TABLE_ID(XOP_9)], 
                    &x86_table_links[TABLE_ID(XOP_A)],
                    NULL
    }
};

/* effective address, addressing size 16-bit */
static const uint8_t ea_asize16[8][2] =
{
    /* 0 */ {X86_REG_BX, X86_REG_SI},
    /* 1 */ {X86_REG_BX, X86_REG_DI},
    /* 2 */ {X86_REG_BP, X86_REG_SI},
    /* 3 */ {X86_REG_BP, X86_REG_DI},
    /* 4 */ {X86_REG_SI, X86_REG_NONE},
    /* 5 */ {X86_REG_DI, X86_REG_NONE},
    /* 6 */ {X86_REG_BP, X86_REG_NONE},
    /* 7 */ {X86_REG_BX, X86_REG_NONE}
};

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

/* registers strings, same order as defined in the enum */
static const char* const regs_str[] =
{
    "rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi", "r8", 
    "r9", "r10", "r11", "r12", "r13", "r14", "r15", "rip",

    "eax", "ecx", "edx", "ebx","esp", "ebp", "esi", "edi",
    "r8d", "r9d", "r10d", "r11d", "r12d", "r13d", "r14d", "r15d", "eip",

    "ax", "cx", "dx", "bx", "sp", "bp", "si", "di",
    "r8w", "r9w", "r10w", "r11w", "r12w", "r13w", "r14w", "r15w",

    "al", "cl", "dl", "bl", "ah", "ch", "dh", "bh",
    "spl", "bpl", "sil", "dil", "r8l", "r9l", "r10l", "r11l", "r12l",   
    "r13l", "r14l", "r15l",

    "es", "cs", "ss", "ds", "fs", "gs",

    "st0", "st1", "st2", "st3", "st4", "st5", "st6", "st7", 

    "mm0", "mm1", "mm2", "mm3", "mm4", "mm5", "mm6", "mm7",

    "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7",
    "xmm8", "xmm9", "xmm10", "xmm11", "xmm12", "xmm13", "xmm14", "xmm15",
    "xmm16", "xmm17", "xmm18", "xmm19", "xmm20", "xmm21", "xmm22", "xmm23",
    "xmm24", "xmm25", "xmm26", "xmm27", "xmm28", "xmm29", "xmm30", "xmm31",

    "ymm0", "ymm1", "ymm2", "ymm3", "ymm4", "ymm5", "ymm6", "ymm7",
    "ymm8", "ymm9", "ymm10", "ymm11", "ymm12", "ymm13", "ymm14", "ymm15",
    "ymm16", "ymm17", "ymm18", "ymm19", "ymm20", "ymm21", "ymm22", "ymm23",
    "ymm24", "ymm25", "ymm26", "ymm27", "ymm28", "ymm29", "ymm30", "ymm31",

    "zmm0", "zmm1", "zmm2", "zmm3", "zmm4", "zmm5", "zmm6", "zmm7",
    "zmm8", "zmm9", "zmm10", "zmm11", "zmm12", "zmm13", "zmm14", "zmm15",
    "zmm16", "zmm17", "zmm18", "zmm19", "zmm20", "zmm21", "zmm22", "zmm23",
    "zmm24", "zmm25", "zmm26", "zmm27", "zmm28", "zmm29", "zmm30", "zmm31",

    "dr0", "dr1", "dr2", "dr3", "dr4", "dr5", "dr6", "dr7",
    "dr8", "dr9", "dr10", "dr11", "dr12", "dr13", "dr14", "dr15",

    "cr0", "cr1", "cr2", "cr3", "cr4", "cr5", "cr6", "cr7",
    "cr8", "cr9", "cr10", "cr11", "cr12", "cr13", "cr14", "cr15"
};

/* operand size strings, used for memory pointers */
static const char* const opsize_str[] =
{
    "", "byte", "word", "dword", "fword", "qword", "tword",
    "oword", "yword", "zword"
};

static
const char* const
get_opsize_str(uint8_t a)
{
    return opsize_str[a];
}

#endif

/****************************************************************************

    decoding functions

****************************************************************************/

static 
uint8_t
get_uint8(x86_dasm_context_t* x86_dctx, int i)
{
    return (i == -1 ? x86_dctx->buffer[x86_dctx->pos++] : x86_dctx->buffer[i]);
}

static 
uint16_t
get_uint16(x86_dasm_context_t* x86_dctx, int i)
{
    uint16_t r;

    uint8_t* p = (i == -1 ? 
        &x86_dctx->buffer[x86_dctx->pos] : 
        &x86_dctx->buffer[i]);

#if defined(X86_DASM_NLE)

    r = 0;
    r |= ((uint16_t)p[0]);
    r |= (((uint16_t)p[1]) << 8);

#else

    r = *(uint16_t *)p;

#endif

    /* update the position in the buffer */
    if(i == -1) 
    {
        x86_dctx->pos += sizeof(uint16_t);
    }

    return r;
}

static 
uint32_t
get_uint32(x86_dasm_context_t* x86_dctx, int i)
{
    uint32_t r;

    uint8_t* p = (i == -1 ? 
        &x86_dctx->buffer[x86_dctx->pos] : 
        &x86_dctx->buffer[i]);

#if defined(X86_DASM_NLE)

    r = 0;
    r |= ((uint32_t)p[0]);
    r |= (((uint32_t)p[1]) << 8);
    r |= (((uint32_t)p[2]) << 16);
    r |= (((uint32_t)p[3]) << 24);

#else

    r = *(uint32_t *)p;

#endif

    /* update the position in the buffer */
    if(i == -1) 
    {
        x86_dctx->pos += sizeof(uint32_t);
    }

    return r;
}

static 
uint64_t
get_uint64(x86_dasm_context_t* x86_dctx, int i)
{
    uint64_t r;

    uint8_t* p = (i == -1 ? 
        &x86_dctx->buffer[x86_dctx->pos] : 
        &x86_dctx->buffer[i]);

#if defined(X86_DASM_NLE)

    r = 0;
    r |= ((uint64_t)p[0]);
    r |= (((uint64_t)p[1]) << 8);
    r |= (((uint64_t)p[2]) << 16);
    r |= (((uint64_t)p[3]) << 24);
    r |= (((uint64_t)p[4]) << 32);
    r |= (((uint64_t)p[5]) << 40);
    r |= (((uint64_t)p[6]) << 48);
    r |= (((uint64_t)p[7]) << 56);

#else

    r = *(uint64_t *)p;

#endif

    /* update the position in the buffer */
    if(i == -1) 
    {
        x86_dctx->pos += sizeof(uint64_t);
    }

    return r;
}

/***************************************************************************/

static int decode_modrm_mod_rm(x86_dasm_context_t* x86_dctx, 
    x86_operand_t* op, uint8_t base_reg);

/***************************************************************************/

static 
uint8_t
get_modrm(x86_dasm_context_t* x86_dctx)
{
    if(!x86_dctx->p_modrm)
    {
        x86_dctx->p_modrm = true;
        x86_dctx->pos_modrm = x86_dctx->pos;
        x86_dctx->modrm = get_uint8(x86_dctx, -1);
    }

    return x86_dctx->modrm;
}

static 
uint8_t
get_sib(x86_dasm_context_t* x86_dctx)
{
    if(!x86_dctx->p_sib)
    {
        x86_dctx->p_sib = true;
        x86_dctx->pos_sib = x86_dctx->pos;
        x86_dctx->sib = get_uint8(x86_dctx, -1);
    }

    return x86_dctx->sib;
}

static 
void
check_modrm_mod_rm(x86_dasm_context_t* x86_dctx, const x86_table_entry_t* te)
{
    x86_operand_t tmp;

    /* check all the operands (currently max 4) */
    for(int i = 0; i < 4; i++)
    {
        memset(&tmp, 0, sizeof(tmp));

        tmp.size = X86_OPSIZE_BYTE;
        tmp.reg = 0;

        switch(te->operands[i].am)
        {
            case AM_E:
            case AM_M:
            case AM_N:
            case AM_Q:
            case AM_R:
            case AM_U:
            case AM_W:
                /* get the modrm byte in advance */
                get_modrm(x86_dctx);
                decode_modrm_mod_rm(x86_dctx, &tmp, X86_REG_GPR);
                return;

            default:
                break;
            
        }
    }
}

static 
void
check_modrm_reg(x86_dasm_context_t* x86_dctx, const x86_table_entry_t* te)
{
    /* check all the operands (currently max 4) */
    for(int i = 0; i < 4; i++)
    {
        switch(te->operands[i].am)
        {
            case AM_C:
            case AM_D:
            case AM_G:
            case AM_P:
            case AM_S:
            case AM_V:
                /* get the modrm byte in advance */
                get_modrm(x86_dctx);
                return;

            default:
                break;  
        }
    }
}

static 
uint8_t
get_osize(x86_dasm_context_t* x86_dctx, uint16_t flags)
{
    /*
        D (default) field of the code-segment (CS) is assumed to be 32-bit 
        for protected mode / compatibility mode and 16-bit for real mode /
        virtual 8086 mode
    */

    /* operand-size override prefix present */
    uint8_t p = x86_dctx->pfx_p_osize;

    switch(x86_dctx->dmode)
    {
        case X86_DMODE_16BIT:

            /* assumed default operand size: 16 bit */
            x86_dctx->osize = (p ? X86_OSIZE_32BIT : X86_OSIZE_16BIT);
            break;

        case X86_DMODE_32BIT:

            /* assumed default operand size: 32 bit */
            x86_dctx->osize = (p ? X86_OSIZE_16BIT : X86_OSIZE_32BIT);
            break;

        case X86_DMODE_64BIT:

            if(flags & PF_F64)
            {
                /* operand size forced to 64-bit */
                x86_dctx->osize = X86_OSIZE_64BIT;
            }
            else
            {
                if( (REX_W) || 
                    (x86_dctx->pfx_p_vex3b && VEX_3B_W) ||
                    (x86_dctx->pfx_p_evex && EVEX_W) ||
                    (x86_dctx->pfx_p_xop && XOP_W) )
                {
                    /* if rex.w = 1 then prefix 66h is ignored, or vex.w=1 */
                    x86_dctx->osize = X86_OSIZE_64BIT;
                }
                else
                {
                    if(flags & PF_D64)
                    {
                        /* 
                            default operand size is 64 bit and cannot encode 
                            32-bit operand size 
                        */  
                        x86_dctx->osize = (p ? X86_OSIZE_16BIT : X86_OSIZE_64BIT);
                    }
                    else
                    {
                        /* default operand size: 32 bit*/
                        x86_dctx->osize = (p ? X86_OSIZE_16BIT : X86_OSIZE_32BIT);
                    }
                }
            }

            break;

        default:
            break;
    }

    dbg_msg("%i", x86_dctx->osize);

    return x86_dctx->osize;
}

static 
uint8_t
get_asize(x86_dasm_context_t* x86_dctx)
{
    /*
        D (default) field of the code-segment (CS) is assumed to be 32-bit 
        for protected mode / compatibility mode and 16-bit for real mode /
        virtual 8086 mode
    */

    /* address-size override prefix present */
    uint8_t p = x86_dctx->pfx_p_asize;

    switch(x86_dctx->dmode)
    {
        case X86_DMODE_16BIT:

            /* assumed default address size: 16 bit */
            x86_dctx->asize = (p ? X86_ASIZE_32BIT : X86_ASIZE_16BIT);
            break;

        case X86_DMODE_32BIT:

            /* assumed default address size: 32 bit */
            x86_dctx->asize = (p ? X86_ASIZE_16BIT : X86_ASIZE_32BIT);
            break;

        case X86_DMODE_64BIT:

            /* assumed default address size: 64 bit */
            x86_dctx->asize = (p ? X86_OSIZE_32BIT : X86_OSIZE_64BIT);
            break;

        default:
            break;
    }

    dbg_msg("%i", x86_dctx->asize);

    return x86_dctx->asize;
}

static 
int
decode_prefixes(x86_dasm_context_t* x86_dctx)
{
    int i;

    uint8_t* b = &x86_dctx->buffer[0];
    
    /* loop only until max instruction length */
    for(i = 0; i < MAX_INST_LENGTH; i++)
    {
        /* check for REX prefix separately */
        if(REX_PREFIX(b[i]))
        {
            if(x86_dctx->dmode == X86_DMODE_64BIT)
            {
                x86_dctx->pfx_last = b[i];
                x86_dctx->pfx_rex = b[i];
                x86_dctx->pos_rex = i;
                x86_dctx->pfx_p_rex = true;
            }
            else
            {
                /* 
                    not in long mode, so the opcode must be an inc/dec 
                    instruction and we are done decoding prefixes 
                */
                goto decode_prefixes_done;
            }
        }
        else
        {
            /* check for all the other prefixes */
            switch(b[i])
            {
                case PREFIX_OSIZE:

                    x86_dctx->pfx_last = b[i];
                    x86_dctx->pfx_c_osize++;
                    x86_dctx->pfx_p_osize = true;
                    
                    /* 
                        if the prefixes F2h, F3h are present, then it seems 
                        that the prefix 66h is ignored and between F2h and
                        F3h the one that comes later has precedence
                    */
                    if( x86_dctx->pfx_mandatory != PREFIX_REPNE &&
                        x86_dctx->pfx_mandatory != PREFIX_REP)
                    {
                        x86_dctx->pfx_mandatory = b[i];
                    }

                    break;
                    
                case PREFIX_ASIZE:
                    x86_dctx->pfx_last = b[i];
                    x86_dctx->pfx_p_asize = true;
                    break;

                case PREFIX_SEGOVRD_CS:

                    x86_dctx->pfx_seg = X86_REG_CS;

                    goto decode_prefixes_1;

                case PREFIX_SEGOVRD_DS:

                    x86_dctx->pfx_seg = X86_REG_DS;

                    goto decode_prefixes_1;

                case PREFIX_SEGOVRD_ES:

                    x86_dctx->pfx_seg = X86_REG_ES;

                    goto decode_prefixes_1;

                case PREFIX_SEGOVRD_SS:

                    x86_dctx->pfx_seg = X86_REG_SS;

decode_prefixes_1:

                    /* these segment override pfxs are ignored in long mode */
                    if(x86_dctx->dmode != X86_DMODE_64BIT)
                    {
                        /* last segment override prefix wins */
                        x86_dctx->pfx_last = b[i];
                        x86_dctx->pfx_p_seg = true;
                    }

                    break;

                case PREFIX_SEGOVRD_FS:

                    x86_dctx->pfx_seg = X86_REG_FS;

                    goto decode_prefixes_2;

                case PREFIX_SEGOVRD_GS:

                    x86_dctx->pfx_seg = X86_REG_GS;

decode_prefixes_2:

                    /* last segment override prefix wins */
                    x86_dctx->pfx_last = b[i];
                    x86_dctx->pfx_p_seg = true;
                    break;

                case PREFIX_LOCK:
                    x86_dctx->pfx_last = b[i];
                    x86_dctx->pfx_p_lock = true;
                    break;

                case PREFIX_REPNE:
                    x86_dctx->pfx_last = b[i];
                    x86_dctx->pfx_mandatory = b[i];
                    x86_dctx->pfx_p_repne = true;
                    break;

                case PREFIX_REP:
                    x86_dctx->pfx_last = b[i];
                    x86_dctx->pfx_mandatory = b[i];
                    x86_dctx->pfx_p_rep = true;
                    break;
                
                default:

                    goto decode_prefixes_done;
            }
        }
    }

    dbg_err("instruction's size exceeded the limit!");
    return -1;

decode_prefixes_done:

    /*
        REX prefix
    */
    if(x86_dctx->dmode == X86_DMODE_64BIT)
    {
        /* 
            REX prefix is only valid in long mode (64-bit mode) and if used, 
            the REX prefix byte must immediately precede the opcode byte or 
            the escape opcode byte (0FH). When a REX prefix is used in 
            conjunction with an instruction containing a mandatory prefix, 
            the mandatory prefix must come before the REX so the REX prefix 
            can be immediately preceding the opcode or the escape byte. Other 
            placements are ignored. The instruction-size limit of 15 bytes 
            still applies to instructions with a REX prefix.
        */
        if(!REX_PREFIX(x86_dctx->pfx_last))
        {
            /* ignore it */
            x86_dctx->pfx_rex = 0;
            x86_dctx->pos_rex = 0;
            x86_dctx->pfx_p_rex = false;
        }
    }

    /*
        VEX, EVEX, XOP prefixes
    */
    if(b[i] == PREFIX_VEX_3B && (x86_dctx->dmode == X86_DMODE_64BIT || 
        VEX_3B_PM(b[i+1])))
    {
        if( i > (MAX_INST_LENGTH - 5) || 
            x86_dctx->pfx_p_osize || x86_dctx->pfx_p_rex ||
            x86_dctx->pfx_p_lock || x86_dctx->pfx_p_rep ||
            x86_dctx->pfx_p_repne )
        {
            /* 
                any VEX-encoded instruction with a REX, LOCK, 66H, F2H, 
                or F3H prefix preceding VEX will #UD
            */
            dbg_err("VEX-encoded instruction will #UD!");
            return -1;
        }
        else
        {
            dbg_msg("VEX3B");

            x86_dctx->pfx_vex[0] = b[i+1]; /* P0 */
            x86_dctx->pfx_vex[1] = b[i+2]; /* P1 */
            x86_dctx->pfx_p_vex3b = true;

            /* check if the m-mmmm value is invalid */
            if(VEX_3B_MMMMM == 0 || VEX_3B_MMMMM > 3)
            {
                dbg_err("VEX-encoded instruction will #UD!");
                return -1;
            }

            x86_dctx->table_link = vex_links[VEX_3B_PP][VEX_3B_MMMMM];

            /* update the position */
            i += 3;
        }
    }
    else
    if(b[i] == PREFIX_VEX_2B && (x86_dctx->dmode == X86_DMODE_64BIT || VEX_2B_PM(b[i+1])))
    {
        if( i > (MAX_INST_LENGTH - 4) || 
            x86_dctx->pfx_p_osize || x86_dctx->pfx_p_rex ||
            x86_dctx->pfx_p_lock || x86_dctx->pfx_p_rep ||
            x86_dctx->pfx_p_repne )
        {
            /* 
                any VEX-encoded instruction with a REX, LOCK, 66H, F2H, 
                or F3H prefix preceding VEX will #UD
            */
            dbg_err("VEX-encoded instruction will #UD!");

            return -1;
        }
        else
        {
            dbg_msg("VEX2B");

            x86_dctx->pfx_vex[0] = b[i+1]; /* P0 */
            x86_dctx->pfx_p_vex2b = true;

            x86_dctx->table_link = vex_links[VEX_2B_PP][1];

            /* update the position */
            i += 2;
        }
    }
    else
    if(b[i] == PREFIX_EVEX && (x86_dctx->dmode == X86_DMODE_64BIT || EVEX_PM(b[i+1])))
    {
        /* 
            currently dont support EVEX prefix until better 
            documentation is released...and I stop being lazy
        */
        dbg_err("EVEX currently not supported!");
        return -1;

        if( i > (MAX_INST_LENGTH - 6) || 
            x86_dctx->pfx_p_osize || x86_dctx->pfx_p_rex ||
            x86_dctx->pfx_p_lock || x86_dctx->pfx_p_rep ||
            x86_dctx->pfx_p_repne )
        {
            /* 
                any VEX-encoded instruction with a REX, LOCK, 66H, F2H, 
                or F3H prefix preceding VEX will #UD
            */
            dbg_err("VEX-encoded instruction will #UD!");
            return -1;
        }
        else
        {
            if(EVEX_P0(b[i+1]) && EVEX_P1(b[i+2]))
            {
                dbg_msg("EVEX");

                x86_dctx->pfx_vex[0] = b[i+1]; /* P0 */
                x86_dctx->pfx_vex[1] = b[i+2]; /* P1 */
                x86_dctx->pfx_vex[2] = b[i+3]; /* P2 */
                x86_dctx->pfx_p_evex = true;

                x86_dctx->table_link = vex_links[EVEX_PP][EVEX_MM];

                /* update the position */
                i += 4;
            }
        }
    }
    else
    if(b[i] == PREFIX_XOP && (x86_dctx->dmode == X86_DMODE_64BIT || XOP_PM(b[i+1])) && XOP_VALID(b[i+1]))
    {
        if( i > (MAX_INST_LENGTH - 5) || 
            x86_dctx->pfx_p_osize || x86_dctx->pfx_p_rex ||
            x86_dctx->pfx_p_lock || x86_dctx->pfx_p_rep ||
            x86_dctx->pfx_p_repne )
        {
            /* 
                any XOP-encoded instruction with a REX, LOCK, 66H, F2H, 
                or F3H prefix preceding VEX will #UD
            */
            dbg_err("XOP-encoded instruction will #UD!");
            return -1;
        }
        else
        {
            dbg_msg("XOP");

            x86_dctx->pfx_xop[0] = b[i+1]; /* P0 */
            x86_dctx->pfx_xop[1] = b[i+2]; /* P1 */
            x86_dctx->pfx_p_xop = true;

            /* check if the pp value is invalid */
            if(XOP_PP != 0)
            {
                dbg_err("XOP-encoded instruction will #UD!");
                return -1;
            }

            x86_dctx->table_link = xop_links[XOP_PP][XOP_MMMMM - 8];

            /* update the position */
            i += 3;
        }
    }
    else
    if(b[i] == ESCAPE_OPCODE_2B)
    {
        /* later on we will decide if it really is a mandatory prefix or not */
        switch(x86_dctx->pfx_mandatory)
        {
            case PREFIX_OSIZE:          
                x86_dctx->table_link = &x86_table_links[TABLE_ID(66_0F)];
                break;

            case PREFIX_REP:
                x86_dctx->table_link = &x86_table_links[TABLE_ID(F3_0F)];
                break;

            case PREFIX_REPNE:
                x86_dctx->table_link = &x86_table_links[TABLE_ID(F2_0F)];
                break;

            default:
                x86_dctx->table_link = &x86_table_links[TABLE_ID(0F)];
                break;
        }

        /* update the position */
        i++;
    }
    else
    {
        /* one-byte table */
        x86_dctx->pfx_mandatory = 0;
        x86_dctx->table_link = &x86_table_links[TABLE_ID(1B)];
    }

    /* update the position in the buffer */
    x86_dctx->pos = i;
    x86_dctx->pos_opcode = x86_dctx->pos;

    dbg_msg(
        "\n"
        "\t pfx_seg         : %02Xh\n"
        "\t pfx_rex         : %02Xh\n"
        "\t pfx_last        : %02Xh\n"
        "\t pfx_mandatory   : %02Xh\n"
        "\t pfx_vex         : %02Xh, %02Xh\n"
        "\t pfx_p_osize     : %i\n"
        "\t x86_dctx->pos   : %i\n",
        x86_dctx->pfx_seg,
        x86_dctx->pfx_rex,
        x86_dctx->pfx_last,
        x86_dctx->pfx_mandatory,
        x86_dctx->pfx_vex[0],
        x86_dctx->pfx_vex[1],
        x86_dctx->pfx_p_osize,
        x86_dctx->pos );

    return i;
}

static 
int
decode_opcode(x86_dasm_context_t* x86_dctx, const x86_table_entry_t** te_out)
{
    int done = false;

    uint8_t j = 0;
    uint8_t* b = &x86_dctx->buffer[0];

    /* needed to decode 3DNow! instructions */
    x86_operand_t op;
    
    const x86_table_link_t* link = x86_dctx->table_link; 
    const x86_table_entry_t* te = link->table;

    /* loop until we have a valid instruction entry */
    while(!done)
    {
        dbg_msg("table: %s, method: %i", 
            link->table_name, link->lookup_method);

        switch(link->lookup_method)
        {
            case TABLE_LOOKUP_METHOD(BYTE):

                dbg_msg("opcode: %02X", b[x86_dctx->pos]);

                /* current byte is an opcode */
                if(te[b[x86_dctx->pos]].table_id == TABLE_ID(NONE))
                {
                    /* get the instruction */
                    te = &te[b[x86_dctx->pos]];
                    done = true;
                }
                else
                {
                    /* get the new table link */
                    link = &x86_table_links[te[b[x86_dctx->pos]].table_id];
                    te = link->table;
                }

                /* update the position */
                x86_dctx->pos++;
                break;

            case TABLE_LOOKUP_METHOD(3DNOW):

                /* decode the modr/m and sib (if present) */
                decode_modrm_mod_rm(x86_dctx, &op, X86_REG_MM0);

                /* now the current byte is the opcode */
                te = &te[b[x86_dctx->pos]];
                done = true;

                /* restore */
                x86_dctx->pos_opcode = x86_dctx->pos;
                x86_dctx->pos++;
                break;

            case TABLE_LOOKUP_METHOD(OSIZE):

                /* 
                    recalculate the actual operand size by taking into 
                    account also the following instruction's property flags: 
                    D64 and F64
                */
                j = x86_dctx->osize;
                j = get_osize(x86_dctx, te[j].properties);

                goto decode_opcode_1;

            case TABLE_LOOKUP_METHOD(ASIZE):

                j = get_asize(x86_dctx);

                goto decode_opcode_1;

            case TABLE_LOOKUP_METHOD(DMODE):

                j = x86_dctx->dmode;

                goto decode_opcode_1;

            case TABLE_LOOKUP_METHOD(FPU):

                /* current byte is modrm */
                j = get_modrm(x86_dctx) - 0xC0;

                goto decode_opcode_1;

            case TABLE_LOOKUP_METHOD(OSIZE_XOP):

                /* sanity check */
                if(x86_dctx->pfx_p_xop == false)
                {
                    dbg_err("XOP prefix missing!");
                    return -1;
                }

                j = XOP_W;
                
                goto decode_opcode_1;

            case TABLE_LOOKUP_METHOD(OSIZE_VEX):

                /* sanity check */
                if( x86_dctx->pfx_p_vex3b == false &&
                    x86_dctx->pfx_p_evex == false )
                {
                    dbg_err("VEX prefix missing!");
                    return -1;
                }

                j = (x86_dctx->pfx_p_vex3b ? VEX_3B_W : j);
                j = (x86_dctx->pfx_p_evex ? EVEX_W : j);

                goto decode_opcode_1;

            case TABLE_LOOKUP_METHOD(MODRM_MOD):

                /* current byte is modrm */
                j = MODRM_MOD(get_modrm(x86_dctx)) == 3 ? 1 : 0;

                dbg_msg("MODRM_MOD %02X -> %i", get_modrm(x86_dctx), j);

                goto decode_opcode_1;

            case TABLE_LOOKUP_METHOD(MODRM_RM):

                /* current byte is modrm */
                j = MODRM_RM(get_modrm(x86_dctx));

                dbg_msg("MODRM_RM %02X -> %i", get_modrm(x86_dctx), j);

                goto decode_opcode_1;

            case TABLE_LOOKUP_METHOD(MODRM_REG):

                /* current byte is modrm */
                j = MODRM_REG(get_modrm(x86_dctx));

                dbg_msg("MODRM_REG %02X -> %i", get_modrm(x86_dctx), j);

decode_opcode_1:

                if(te[j].table_id == TABLE_ID(NONE))
                {
                    /* get the instruction */
                    te = &te[j];
                    done = true;
                }
                else
                {
                    /* get the new table link */
                    link = &x86_table_links[te[j].table_id];
                    te = link->table;
                }

                break;

            default:
                dbg_err("undefined lookup method!");
                return -1;
        }
    }

    *te_out = te;

    x86_dctx->iset = te->iset;
    x86_dctx->mnem = te->mnem_id;

    /* check if the instruction supports vectored sib */
    if( (te->properties & PF_VSIB_X) != 0 || 
        (te->properties & PF_VSIB_Y) != 0 ||
        (te->properties & PF_VSIB_Z) != 0 ||
        (te->properties & PF_VSIB_L) != 0 )
    {
        x86_dctx->p_vsib = true;

        if((te->properties & PF_VSIB_X) != 0)
        {
            x86_dctx->vsib_base = X86_REG_XMM0;
        }
        else
        if((te->properties & PF_VSIB_Y) != 0)
        {
            x86_dctx->vsib_base = X86_REG_YMM0;
        }
        else
        if((te->properties & PF_VSIB_Z) != 0)
        {
            x86_dctx->vsib_base = X86_REG_ZMM0;
        }
        else
        {
            x86_dctx->vsib_base = X86_REG_NONE;
        }
    }

    /* remove prefixes because they are used as mandatory */
    /* this was made to resolve the jcc bug, a 66 prefix on a jcc mods the osize */
    if((te->properties & PF_PFXNA) == 0)
    {
        switch(x86_dctx->pfx_mandatory)
        {
            case PREFIX_OSIZE:
                x86_dctx->pfx_p_osize = false;
                break;

            case PREFIX_REP:
                x86_dctx->pfx_p_rep = false;
                break;

            case PREFIX_REPNE:
                x86_dctx->pfx_p_repne = false;
                break;

            default:
                break;
        }
    }

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

    if(x86_dctx->mnem != X86_MN_INVALID)
    {
        /* copy the mnemonic string */
        strcpy(x86_dctx->mnem_str, te->mnem_str);
    
        dbg_msg("%s", te->mnem_str);
    }

#endif

    check_modrm_mod_rm(x86_dctx, te);
    check_modrm_reg(x86_dctx, te);

    return 0;
}

#define decode_imm(ctx, op)     decode_data(ctx, op, X86_OPTYPE_IMM)
#define decode_rel(ctx, op)     decode_data(ctx, op, X86_OPTYPE_REL)
#define decode_moffs(ctx, op)   decode_data(ctx, op, X86_OPTYPE_MOFFS)

static 
int
decode_data(x86_dasm_context_t* x86_dctx, x86_operand_t* op, uint8_t type)
{
    uint8_t size = op->size;
    int32_t rel = 0;

    op->type = type;
    op->pos = x86_dctx->pos;

    /* offset type needs to be decoded by addressing size */
    if(op->type == X86_OPTYPE_MOFFS)
    {
        switch(x86_dctx->asize)
        {
            case X86_ASIZE_16BIT: 
                op->asize = X86_ASIZE_WORD; size = X86_OPSIZE_WORD; 
                break;

            case X86_ASIZE_32BIT: 
                op->asize = X86_ASIZE_DWORD; size = X86_OPSIZE_DWORD; 
                break;

            case X86_ASIZE_64BIT: 
                op->asize = X86_ASIZE_QWORD; size = X86_OPSIZE_QWORD; 
                break;

            default:
                break;
        }
    }

    /* get/read the data */
    switch(size)
    {
        case X86_OPSIZE_BYTE: 
            op->data.u8 = get_uint8(x86_dctx, -1);
            rel = op->data.s8;
            break;

        case X86_OPSIZE_WORD:
            op->data.u16 = get_uint16(x86_dctx, -1);
            rel = op->data.s16;
            break;

        case X86_OPSIZE_DWORD:
            op->data.u32 = get_uint32(x86_dctx, -1);
            rel = op->data.s32;
            break;

        case X86_OPSIZE_QWORD:
            op->data.u64 = get_uint64(x86_dctx, -1);
            break;

        default:
            dbg_err("undefined opsize for imm!");
            return -1;
    }

    /* compute the destination address for relative operands */
    if(op->type == X86_OPTYPE_REL)
    {
        /* instruction length */
        uint8_t len = x86_dctx->len;

        if(x86_dctx->dmode == X86_DMODE_64BIT)
        {
            /* operand size ignored (66h) */
            x86_dctx->dest_rip.u64 = (x86_dctx->rip.u64 + len) + rel;
        }
        else
        {
            /* X86_DMODE_32BIT and X86_DMODE_16BIT */
            x86_dctx->dest_rip.u32 = (x86_dctx->rip.u32 + len) + rel;
            
            if(x86_dctx->osize == X86_OSIZE_16BIT)
            {
                x86_dctx->dest_rip.u32 &= 0xffff;
            }
        }
    }

    return 0;
}

static 
int
decode_gpr(x86_dasm_context_t* x86_dctx, uint8_t opsize, uint8_t reg, uint8_t* result)
{
    /* by default assume invalid register */
    *result = X86_REG_NONE;

    switch(opsize)
    {
        case X86_OPSIZE_BYTE:

            if(x86_dctx->dmode == X86_DMODE_64BIT && x86_dctx->pfx_p_rex)
            {
                /* 
                    SPL, BPL, SIL, DIL only addressable in long mode  
                    instead of AH, CH, DH, BH   
                */
                *result = (reg > 3 ? X86_REG_SPL + reg-4 : X86_REG_AL + reg);
            }
            else
            {
                *result = (X86_REG_AL + reg);
            }

            break;

        case X86_OPSIZE_WORD:   *result = (X86_REG_AX + reg); break;
        case X86_OPSIZE_DWORD:  *result = (X86_REG_EAX + reg); break;
        case X86_OPSIZE_QWORD:  *result = (X86_REG_RAX + reg); break;

        default:
            dbg_err("undefined opsize for gpr!");
            return -1;
    }

    return 0;
}

static 
int
decode_reg(x86_dasm_context_t* x86_dctx, x86_operand_t* op, uint8_t base_reg, uint8_t reg)
{
    op->type = X86_OPTYPE_REG;
    op->reg = X86_REG_NONE;

    switch(base_reg)
    {
        case X86_REG_DR0:

            /* valid debug register: DR0-DR7 */
            if(reg > 7)
            {
                dbg_err("invalid debug register!");
                return -1;
            }
            
            goto decode_reg_1;

        case X86_REG_CR0:

            /* valid control register: CR0, CR2-CR4, CR8 */
            if(!(reg == 0 || (reg > 1 && reg < 5) || reg == 8))
            {
                dbg_err("invalid control register!");
                return -1;
            }

            goto decode_reg_1;

        case X86_REG_ES:

            /* valid segment register */
            if((reg & 7) == 6 || (reg & 7) == 7)
            {
                dbg_err("invalid segment register!");
                return -1;
            }

            goto decode_reg_1;

        case X86_REG_XMM0:
        case X86_REG_YMM0:
        case X86_REG_ZMM0:

decode_reg_1:

            /* add reg to base_reg like an offset */
            op->reg = base_reg + reg;
            break;

        case X86_REG_ST0:
        case X86_REG_MM0:   
            /* valid mmx register: MM0-MM7, even with extension */
            op->reg = base_reg + (reg & 7); 
            break;

        case X86_REG_GPR:
            return decode_gpr(x86_dctx, op->size, reg, &op->reg);

        default:
            dbg_err("invalid base register!");
            return -1;
    }

    return 0;
}

static 
void
decode_sib(x86_dasm_context_t* x86_dctx, x86_operand_t* op)
{
    uint8_t i = 0;

    uint8_t base = SIB_BASE(get_sib(x86_dctx));
    uint8_t index = SIB_INDEX(get_sib(x86_dctx));
    uint8_t mod = MODRM_MOD(get_modrm(x86_dctx));

    dbg_msg("base: %i, index: %i, mod: %i", base, index, mod);

    /* scaling factor is 2^(sib.scale) */
    op->mexpr.scale = 1 << SIB_SCALE(get_sib(x86_dctx));

    if(x86_dctx->dmode == X86_DMODE_64BIT)
    {
        /*
            in long mode the REX.X/VEX.X/XOP.X fields extend the SIB.I field, 
            the REX.B/VEX.B/XOP.B fields extend the SIB.B field, and 
            currently there can be no REX prefix if a VEX prefix is 
            present (result is #UD)
        */
        if(x86_dctx->pfx_p_rex)
        {
            base |= (REX_B << 3);
            index |= (REX_X << 3);
        }
        else
        if(x86_dctx->pfx_p_vex3b)
        {
            base |= (VEX_3B_B << 3);
            index |= (VEX_3B_X << 3);
        }
        else 
        if(x86_dctx->pfx_p_evex)
        {
            base |= (EVEX_B << 3);
            index |= (EVEX_X << 3);

            /* 
                need to check if instruction supports VSIB:
            
                index |= (VEX_EVEX_X(x86_dctx->pfx_vex[0]) << 3);
                index |= (VEX_EVEX_VV(x86_dctx->pfx_vex[2]) << 4);

                [X/Y/ZMM0*scale+base]
            */
        }
        else
        if(x86_dctx->pfx_p_xop)
        {
            base |= (XOP_B << 3);
            index |= (XOP_X << 3);
        }
    }

    /* check for vectored sib support */
    if(x86_dctx->p_vsib)
    {
        /* 
            VSIB = Vector SIB

            Specific AVX2 instructions utilize a vectorized form of 
            indexed register-indirect addressing called vector SIB (VSIB) 
            addressing. In contrast to the standard indexed 
            register-indirect address mode, which generates a single 
            effective address to access a single memory operand, VSIB 
            addressing generates an array of effective addresses which 
            is used to access data from multiple memory locations in
            a single operation.
        */
        if(x86_dctx->vsib_base == X86_REG_NONE)
        {
            /* the reg size depends on the L field */
            if(op->size == X86_OPSIZE_ZWORD)
            {
                i = X86_REG_ZMM0;
            }
            else
            if(op->size == X86_OPSIZE_YWORD)
            {
                i = X86_REG_YMM0;
            }
            else
            {
                i = X86_REG_XMM0;
            }
        }
        else
        {
            i = x86_dctx->vsib_base;
        }
    }

    /* effective address depends on addressing size */
    switch(x86_dctx->asize)
    {
        case X86_ASIZE_32BIT:

            op->mexpr.base = X86_REG_EAX + base;
            op->mexpr.index = (x86_dctx->p_vsib ? i : X86_REG_EAX) + index;

            goto decode_sib_1;

        case X86_ASIZE_64BIT:

            op->mexpr.base = X86_REG_RAX + base;
            op->mexpr.index = (x86_dctx->p_vsib ? i : X86_REG_RAX) + index;

decode_sib_1:

            if( op->mexpr.index == X86_REG_ESP ||
                op->mexpr.index == X86_REG_RSP )
            {
                /* no index register is encoded */
                op->mexpr.index = X86_REG_NONE;
            }

            if( op->mexpr.base == X86_REG_EBP || 
                op->mexpr.base == X86_REG_R13D ||
                op->mexpr.base == X86_REG_RBP || 
                op->mexpr.base == X86_REG_R13 )
            {
                switch(mod)
                {
                    case 0:
                        op->mexpr.base = X86_REG_NONE;
                        op->mexpr.disp_size = X86_DISP_32; 
                        break;

                    /* base preserved */
                    /* if EVEX, X86_DISP_8 * N */
                    case 1: op->mexpr.disp_size = X86_DISP_8; break; 
                    case 2: op->mexpr.disp_size = X86_DISP_32; break;

                    default:
                        break;
                }
            }

            break;

        default:
            break;
    }
}

static 
int
decode_modrm_reg(x86_dasm_context_t* x86_dctx, x86_operand_t* op, uint8_t base_reg)
{
    uint8_t reg = MODRM_REG(get_modrm(x86_dctx));

    dbg_msg("reg: %i", reg);

    if(x86_dctx->dmode == X86_DMODE_64BIT && base_reg != X86_REG_ES)
    {
        /*
            in long mode the REX.R/VEX.R/XOP.R fields extend the MODRM.REG 
            field, and currently there can be no REX prefix if a VEX prefix 
            is present (result is #UD)
        */
        if(x86_dctx->pfx_p_rex)
        {
            reg |= (REX_R << 3);
        }
        else
        if(x86_dctx->pfx_p_vex2b)
        {
            /* VEX2B.R is like REX.R */
            reg |= (VEX_2B_R << 3);
        }
        else
        if(x86_dctx->pfx_p_vex3b)
        {
            /* VEX3B.R is like REX.R */
            reg |= (VEX_3B_R << 3);
        }
        else
        if(x86_dctx->pfx_p_evex)
        {
            /* EVEX.R': combine with EVEX.R and ModR/M.reg  */
            reg |= (EVEX_R << 3);
            reg |= (EVEX_RR << 4);
        }
        else
        if(x86_dctx->pfx_p_xop)
        {
            /* XOP.R is like REX.R */
            reg |= (XOP_R << 3);
        }
    }
    
    return decode_reg(x86_dctx, op, base_reg, reg);
}

static 
int
decode_modrm_mod_rm(x86_dasm_context_t* x86_dctx, x86_operand_t* op, uint8_t base_reg)
{
    uint8_t mod = MODRM_MOD(get_modrm(x86_dctx));
    uint8_t rm = MODRM_RM(get_modrm(x86_dctx));

    dbg_msg("mod: %i, rm: %i", mod, rm);

    if(x86_dctx->dmode == X86_DMODE_64BIT)
    {
        /*
            in long mode the REX.B/VEX.B/XOP.B fields extend the MODRM.RM 
            field, and currently there can be no REX prefix if a VEX prefix 
            is present (result is #UD)
        */
        if(x86_dctx->pfx_p_rex)
        {
            rm |= (REX_B << 3);
        }
        else
        if(x86_dctx->pfx_p_vex3b)
        {
            rm |= (VEX_3B_B << 3);
        }
        else
        if(x86_dctx->pfx_p_evex)
        {
            rm |= (EVEX_B << 3);

            /* if register-direct then EVEX.X also extends r/m */
            if(mod == 3)
            {
                rm |= (EVEX_X << 4);
            }
        }
        else
        if(x86_dctx->pfx_p_xop)
        {
            rm |= (XOP_B << 3);
        }
    }
    
    /* mod = 11b, register-direct addressing mode */
    if(mod == 3)
    {
        /* register: GPR/MMX/XMM/YMM/ZMM */
        return decode_reg(x86_dctx, op, base_reg, rm);
    }

    /* mod = !11b, register-indirect addressing */
    op->type = X86_OPTYPE_MEXPR;
    op->mexpr.base = X86_REG_NONE;
    op->mexpr.index = X86_REG_NONE;
    op->mexpr.disp_size = X86_DISP_NONE;
    op->mexpr.scale = 1;

    /* effective address depends on addressing size */
    switch(x86_dctx->asize)
    {
        case X86_ASIZE_16BIT:

            /* REX.B/VEX.B/XOP.B is ignored */
            rm &= 7;

            op->mexpr.base = ea_asize16[rm][0];
            op->mexpr.index = ea_asize16[rm][1];
            
            if(mod == 0 && rm == 6)
            {
                op->mexpr.base = X86_REG_NONE;
                op->mexpr.disp_size = X86_DISP_16;
            }
            else
            {
                op->mexpr.disp_size = (mod == 1 ? X86_DISP_8 : op->mexpr.disp_size);
                op->mexpr.disp_size = (mod == 2 ? X86_DISP_16 : op->mexpr.disp_size);
            }

            break;

        case X86_ASIZE_32BIT:

            op->mexpr.base = X86_REG_EAX + rm;

            /* REX.B/VEX.B/XOP.B is ignored */
            if(mod == 0 && (rm & 7) == 5)
            {
                if(x86_dctx->dmode == X86_DMODE_64BIT)
                {
                    /*
                        RIP-relative addressing is enabled by 64-bit mode, 
                        not by a 64-bit address-size. The use of the 
                        address-size prefix does not disable RIP-relative 
                        addressing. The effect of the address-size prefix is 
                        to truncate and zero-extend the computed effective 
                        address to 32 bits.
                    */
                    op->mexpr.base = X86_REG_EIP;
                }
                else
                {
                    op->mexpr.base = X86_REG_NONE;
                }
                
                op->mexpr.disp_size = X86_DISP_32;
            }

            goto decode_modrm_mod_rm_1;

        case X86_ASIZE_64BIT:

            op->mexpr.base = X86_REG_RAX + rm;

            /* REX.B/VEX.B/XOP.B is ignored */
            if(mod == 0 && (rm & 7) == 5)
            {
                op->mexpr.base = X86_REG_RIP;
                op->mexpr.disp_size = X86_DISP_32;
            }

decode_modrm_mod_rm_1:
            
            /* if EVEX, X86_DISP_8 * N */
            op->mexpr.disp_size = (mod == 1 ? X86_DISP_8 : op->mexpr.disp_size); 
            op->mexpr.disp_size = (mod == 2 ? X86_DISP_32 : op->mexpr.disp_size);

            /* REX.B/VEX.B/XOP.B is ignored */
            if((rm & 7) == 4)
            {
                /* SIB byte follows the ModR/M byte */
                decode_sib(x86_dctx, op);
            }

            break;

        default:
            break;
    
    }

    /* used to consume or peek the data in the buffer */
    int disp_offset = -1;

    /* save the displacement position */
    op->pos = x86_dctx->pos;

    if(x86_dctx->p_sib)
    {
        if(x86_dctx->pos != x86_dctx->pos_sib + 1)
        {
            op->pos = disp_offset = x86_dctx->pos_sib + 1;
        }
    }
    else
    if(x86_dctx->p_modrm)
    {
        if(x86_dctx->pos != x86_dctx->pos_modrm + 1)
        {
            op->pos = disp_offset = x86_dctx->pos_modrm + 1;
        }
    }

    /* get the displacement */
    switch(op->mexpr.disp_size)
    {
        case X86_DISP_8:
            op->mexpr.disp.u8 = get_uint8(x86_dctx, disp_offset); 
            break;

        case X86_DISP_16: 
            op->mexpr.disp.u16 = get_uint16(x86_dctx, disp_offset); 
            break;

        case X86_DISP_32: 
            op->mexpr.disp.u32 = get_uint32(x86_dctx, disp_offset); 
            break;

        default:
            break;
    }

    return 0;
}

static 
int
decode_opsize(x86_dasm_context_t* x86_dctx, const x86_table_entry_t* te, int i)
{
    x86_operand_t* op = &x86_dctx->operands[i];

    /* decode the operand type */
    switch(te->operands[i].ot)
    {
        case OT_NONE:
            /* no operand type */
            op->size = X86_OPSIZE_NONE;
            break;

        case OT_B:
            /* byte, regardless of osize */
            op->size = X86_OPSIZE_BYTE;
            break;

        case OT_S:
            /* 6-byte or 10-byte pseudo-descriptor */
            switch(x86_dctx->osize)
            {
                case X86_OSIZE_64BIT:
                    op->size = X86_OPSIZE_TWORD;
                    break;

                default:
                    op->size = X86_OPSIZE_FWORD;
                    break;
            }

            break;

        case OT_D:
            /* doubleword, regardless of osize */
        case OT_SI:
            /* doubleword integer register (eax,...) */
            op->size = X86_OPSIZE_DWORD;
            break;

        case OT_DQ:
            /* double-quadword, regardless of osize */
            op->size = X86_OPSIZE_OWORD;
            break;

        case OT_P:
            /* 32-bit, 48-bit, or 80-bit ptr, depending on osize */
            switch(x86_dctx->osize)
            {
                case X86_OSIZE_16BIT:
                    op->size = X86_OPSIZE_DWORD;
                    break;
                case X86_OSIZE_32BIT:
                    op->size = X86_OPSIZE_FWORD;
                    break;
                case X86_OSIZE_64BIT:
                    op->size = X86_OPSIZE_TWORD;
                    break;

                default:
                    break;
            }
            
            break;

        case OT_PS:
            /* 128-bit or 256-bit packed single floating-point */
        case OT_PD:
            /* 128-bit or 256-bit packed double floating-point */
        case OT_X:
            /* dq or qq based on the osize */
            if( (x86_dctx->pfx_p_vex2b && VEX_2B_L) ||
                (x86_dctx->pfx_p_vex3b && VEX_3B_L) ||
                (x86_dctx->pfx_p_xop && XOP_L) )
            {
                /* L: vector length (0: 128-bit, 1: 256-bit) */
                op->size = X86_OPSIZE_YWORD;
            }
            else
            {
                /* default assume L=0 (128-bit) */
                op->size = X86_OPSIZE_OWORD;
            }

            break;

        case OT_PI:
            /* quadword mmx technology register */
            op->size = X86_OPSIZE_QWORD;
            break;

        case OT_Q:
            /* quadword, regardless of osize */
            op->size = X86_OPSIZE_QWORD;
            break;

        case OT_OQ:
            /* 64- or 128-bit depending on VEX.L */
            if( (x86_dctx->pfx_p_vex2b && VEX_2B_L) ||
                (x86_dctx->pfx_p_vex3b && VEX_3B_L) ||
                (x86_dctx->pfx_p_xop && XOP_L) )
            {
                op->size = X86_OPSIZE_OWORD;
            }
            else
            {
                /* default assume L=0 (64-bit) */
                op->size = X86_OPSIZE_QWORD;
            }

            break;

        case OT_QQ:
            /* quad-quadword, regardless of osize */
            op->size = X86_OPSIZE_YWORD;
            break;

        case OT_SD:
            /* scalar element of a 128-bit double floating-point */
        case OT_SS:
            /* scalar element of a 128-bit single floating-point */
            op->size = X86_OPSIZE_OWORD;
            break;

        case OT_V:
            /* word, dword or qword (in 64-bit mode), depending on osize */
            switch(x86_dctx->osize)
            {
                case X86_OSIZE_16BIT:
                    op->size = X86_OPSIZE_WORD;
                    break;
                case X86_OSIZE_32BIT:
                    op->size = X86_OPSIZE_DWORD;
                    break;
                case X86_OSIZE_64BIT:
                    op->size = X86_OPSIZE_QWORD;
                    break;

                default:
                    break;
            }
            
            break;

        case OT_T:
            /* tbyte, regardless of osize */
            op->size = X86_OPSIZE_TWORD;
            break;

        case OT_W:
            /* word, regardless of osize */
            op->size = X86_OPSIZE_WORD;
            break;

        case OT_Y:
            /* dword or qword (in 64-bit mode), depending on osize */
            switch(x86_dctx->osize)
            {
                case X86_OSIZE_64BIT:
                    op->size = X86_OPSIZE_QWORD;
                    break;

                default:
                    op->size = X86_OPSIZE_DWORD;
                    break;
            }

            break;

        case OT_A: 
            /* bound r16, m16&16 / bound r32, m32&32 */
        case OT_Z:
            /* word for 16-bit osize or dword for 32 or 64-bit osize */
            switch(x86_dctx->osize)
            {
                case X86_OSIZE_16BIT:
                    op->size = X86_OPSIZE_WORD;
                    break;

                default:
                    op->size = X86_OPSIZE_DWORD;
                    break;
            }

            break;

        default:
            dbg_err("undefined operand type!");
            return -1;
    }

    dbg_msg("%s", get_opsize_str(op->size));

    return 0;
}

static 
int
decode_optype(x86_dasm_context_t* x86_dctx, const x86_table_entry_t* te, int i)
{
    uint8_t j, x;
    
    x86_operand_t* op = &x86_dctx->operands[i];

    /* default init */
    op->seg = X86_REG_DS;
    op->type = X86_OPTYPE_NONE;

    /* check for segment prefix override */
    if(x86_dctx->pfx_p_seg)
    {
        op->seg = x86_dctx->pfx_seg;
    }

    /* decode the addressing method */
    switch(te->operands[i].am)
    {
        case AM_NONE:
            /* no addressing method */
            op->type = X86_OPTYPE_NONE;
            break;

        case AM_A:
            /* 
                direct address: the instruction has no ModR/M byte; the 
                address of the operand is encoded in the instruction. No base 
                register, index register, or scaling factor can be applied 
                
                EA 1E277072 3300 -> JMP FAR 0033:7270271E
            */
            op->type = X86_OPTYPE_ABS;
            op->pos = x86_dctx->pos;

            switch(op->size)
            {
                case X86_OPSIZE_DWORD:
                    op->abs.offs.u16 = get_uint16(x86_dctx, -1);
                    break;
                case X86_OPSIZE_FWORD:
                    op->abs.offs.u32 = get_uint32(x86_dctx, -1);
                    break;
                case X86_OPSIZE_TWORD:
                    op->abs.offs.u64 = get_uint64(x86_dctx, -1);
                    break;
                default:
                    break;
            }

            op->abs.seg = get_uint16(x86_dctx, -1);

            break;

        case AM_B:
            /* 
                the VEX.vvvv field of the VEX prefix selects a general 
                purpose register
            */
            if( x86_dctx->pfx_p_vex2b || x86_dctx->pfx_p_vex3b || 
                x86_dctx->pfx_p_evex || x86_dctx->pfx_p_xop )
            {
                j = 0;
                j = (x86_dctx->pfx_p_vex2b ? VEX_2B_VVVV : j);
                j = (x86_dctx->pfx_p_vex3b ? VEX_3B_VVVV : j);
                j = (x86_dctx->pfx_p_evex ? EVEX_VVVV : j);
                j = (x86_dctx->pfx_p_xop ? XOP_VVVV : j);

                return decode_reg(x86_dctx, op, X86_REG_GPR, j);
            }
            else
            {
                dbg_err("VEX/XOP prefix missing!");
                return -1;
            }

        case AM_C:
            /* the reg field of the ModR/M byte selects a control register */
            return decode_modrm_reg(x86_dctx, op, X86_REG_CR0);

        case AM_D:
            /* the reg field of the ModR/M byte selects a debug register */
            return decode_modrm_reg(x86_dctx, op, X86_REG_DR0);

        case AM_E:
            /* 
                a ModR/M byte follows the opcode and specifies the operand. 
                The operand is either a general-purpose register or a memory 
                address. If it is a memory address, the address is computed 
                from a segment register and any of the following values: a 
                base register, an index register, a scaling factor, a 
                displacement
            */
            return decode_modrm_mod_rm(x86_dctx, op, X86_REG_GPR);

        case AM_F:
            /* EFLAGS/RFLAGS register */
            op->type = X86_OPTYPE_NONE;
            break;

        case AM_G:
            /* the reg field of the ModR/M byte selects a general register */
            return decode_modrm_reg(x86_dctx, op, X86_REG_GPR);

        case AM_H:
            /*
                the VEX.vvvv field of the VEX prefix selects a 128-bit XMM 
                register or a 256-bit YMM register, determined by operand 
                type. For legacy SSE encodings this operand does not exist, 
                changing the instruction to destructive form
            */
            if(x86_dctx->pfx_p_vex2b || x86_dctx->pfx_p_vex3b || x86_dctx->pfx_p_xop)
            {
                j = 0;
                j = (x86_dctx->pfx_p_vex2b ? VEX_2B_VVVV : j);
                j = (x86_dctx->pfx_p_vex3b ? VEX_3B_VVVV : j);
                j = (x86_dctx->pfx_p_xop ? XOP_VVVV : j);

                /* operand size defined by VEX.L field */
                x = (op->size == X86_OPSIZE_YWORD ? X86_REG_YMM0 : X86_REG_XMM0);

                return decode_reg(x86_dctx, op, x, j);
            }

            /* legacy encoding: ignore the operand */

            break;

        case AM_I:
            /*
                immediate data: the operand value is encoded in subsequent 
                bytes of the instruction
            */
            return decode_imm(x86_dctx, op);

        case AM_J:
            /*
                the instruction contains a relative offset to be added to the 
                instruction pointer register
            */
            return decode_rel(x86_dctx, op);

        case AM_L:
            /*
                the upper 4 bits of the 8-bit immediate selects a 128-bit XMM 
                register or a 256-bit YMM register, determined by operand 
                type (the MSB is ignored in 32-bit mode)
            */
            j = (get_uint8(x86_dctx, -1) >> 4) & 0x0f;

            /* ignore the MSB in 32-bit mode */
            j = (x86_dctx->dmode == X86_DMODE_64BIT ? j : j & 7);

            /* operand size defined by VEX.L field */
            x = (op->size == X86_OPSIZE_YWORD ? X86_REG_YMM0 : X86_REG_XMM0);

            return decode_reg(x86_dctx, op, x, j);

        case AM_M:
            /*
                the ModR/M byte may refer only to memory (for example, 
                BOUND, LES, LDS, LSS, LFS, LGS, CMPXCHG8B)
            */
            if(MODRM_MOD(get_modrm(x86_dctx)) == 3)
            {
                dbg_err("the ModR/M byte may refer only to memory!");
                return -1;
            }

            return decode_modrm_mod_rm(x86_dctx, op, X86_REG_GPR);

        case AM_N:
            /*
                the R/M field of the ModR/M byte selects a packed-quadword, 
                MMX technology register
            */
            if(MODRM_MOD(get_modrm(x86_dctx)) != 3)
            {
                dbg_err(
                    "the R/M field of the ModR/M byte may refer only "
                    "to a MMX technology register!");

                return -1;
            }

            return decode_modrm_mod_rm(x86_dctx, op, X86_REG_MM0);

        case AM_O:
            /*
                the instruction has no ModR/M byte. The offset of the operand 
                is coded as a word or double word (depending on address size 
                attribute) in the instruction. No base register, index 
                register, or scaling factor can be applied 
            */
            return decode_moffs(x86_dctx, op);

        case AM_P:
            /*
                the reg field of the ModR/M byte selects a packed quadword 
                MMX technology register
            */
            return decode_modrm_reg(x86_dctx, op, X86_REG_MM0);

        case AM_Q:
            /* 
                a ModR/M byte follows the opcode and specifies the operand. 
                The operand is either a MMX technology register or a memory 
                address. If it is a memory address, the address is computed 
                from a segment register and any of the following values: a 
                base register, an index register, a scaling factor, a 
                displacement
            */
            return decode_modrm_mod_rm(x86_dctx, op, X86_REG_MM0);

        case AM_R:
            /*
                the R/M field of the ModR/M byte may refer only to a 
                general register
            */
            if(MODRM_MOD(get_modrm(x86_dctx)) != 3)
            {
                dbg_err(
                    "the R/M field of the ModR/M byte may refer only "
                    "to a general register!");

                return -1;
            }

            return decode_modrm_mod_rm(x86_dctx, op, X86_REG_GPR);

        case AM_S:
            /* the reg field of the ModR/M byte selects a segment register */
            return decode_modrm_reg(x86_dctx, op, X86_REG_ES);

        case AM_U:
            /*
                the R/M field of the ModR/M byte selects a 128-bit XMM 
                register or a 256-bit YMM register, determined by operand 
                type
            */
            if(MODRM_MOD(get_modrm(x86_dctx)) != 3)
            {
                dbg_err(
                    "the R/M field of the ModR/M byte may refer only "
                    "to a XMM or YMM register!");

                return -1;
            }

            /* operand size defined by VEX.L field */
            j = (op->size == X86_OPSIZE_YWORD ? X86_REG_YMM0 : X86_REG_XMM0);

            return decode_modrm_mod_rm(x86_dctx, op, j);

        case AM_V:
            /*
                the reg field of the ModR/M byte selects a 128-bit XMM 
                register or a 256-bit YMM register, determined by operand 
                type
            */

            /* operand size defined by VEX.L field */
            j = (op->size == X86_OPSIZE_YWORD ? X86_REG_YMM0 : X86_REG_XMM0);

            return decode_modrm_reg(x86_dctx, op, j);

        case AM_W:
            /*
                a ModR/M byte follows the opcode and specifies the operand. 
                The operand is either a 128-bit XMM register, a 256-bit YMM 
                register (determined by operand type), or a memory address. 
                If it is a memory address, the address is computed from a 
                segment register and any of the following values: a base 
                register, an index register, a scaling factor, and a 
                displacement
            */

            /* operand size defined by VEX.L field */
            j = (op->size == X86_OPSIZE_YWORD ? X86_REG_YMM0 : X86_REG_XMM0);

            return decode_modrm_mod_rm(x86_dctx, op, j);

        case AM_X:
            /*
                memory addressed by the DS:rSI register pair;
                DS can be overridden by a segment prefix!
            */
            op->type = X86_OPTYPE_MEXPR;
            op->seg = (x86_dctx->pfx_p_seg ? x86_dctx->pfx_seg : X86_REG_DS);

            op->mexpr.index = X86_REG_NONE;
            op->mexpr.disp_size = X86_DISP_NONE;
            op->mexpr.scale = 1;

            switch(x86_dctx->asize)
            {
                case X86_ASIZE_16BIT: op->mexpr.base = X86_REG_SI; break;
                case X86_ASIZE_32BIT: op->mexpr.base = X86_REG_ESI; break;
                case X86_ASIZE_64BIT: op->mexpr.base = X86_REG_RSI; break;
                
                default:
                    break;
            }

            break;

        case AM_Y:
            /*
                memory addressed by the ES:rDI register pair;
                ES cannot be overridden by a segment prefix!
            */
            op->type = X86_OPTYPE_MEXPR;
            op->seg = X86_REG_ES;

            op->mexpr.index = X86_REG_NONE;
            op->mexpr.disp_size = X86_DISP_NONE;
            op->mexpr.scale = 1;

            switch(x86_dctx->asize)
            {
                case X86_ASIZE_16BIT: op->mexpr.base = X86_REG_DI; break;
                case X86_ASIZE_32BIT: op->mexpr.base = X86_REG_EDI; break;
                case X86_ASIZE_64BIT: op->mexpr.base = X86_REG_RDI; break;
                
                default:
                    break;
            }

            break;

        case AM_I1:
            /* implicit immediate data of value 1 */
            op->type = X86_OPTYPE_IMM;
            op->data.u8 = 1;
            break;

        case AM_I3:
            /* implicit immediate data of value 3 */
            op->type = X86_OPTYPE_IMM;
            op->data.u8 = 3;
            break;

        case AM_rAX:
        case AM_rCX:
        case AM_rDX:
        case AM_rBX:
        case AM_rSP:
        case AM_rBP:
        case AM_rSI:
        case AM_rDI:
            /* 
                general-purpose register depending on the operand's size 
                attribute (no REX.B extension) 
            */
            j = te->operands[i].am - AM_rAX;

            return decode_reg(x86_dctx, op, X86_REG_GPR, j);

        case AM_rAX_r8:
        case AM_rCX_r9:
        case AM_rDX_r10:
        case AM_rBX_r11:
        case AM_rSP_r12:
        case AM_rBP_r13:
        case AM_rSI_r14:
        case AM_rDI_r15:
            /* 
                general-purpose register depending on the operand's size 
                attribute (with REX.B extension) 
            */
            j = te->operands[i].am - AM_rAX_r8;

            if(x86_dctx->dmode == X86_DMODE_64BIT && x86_dctx->pfx_p_rex)
            {
                j |= (REX_B << 3);
            }

            return decode_reg(x86_dctx, op, X86_REG_GPR, j);

        case AM_ST0:        
        case AM_ST1:        
        case AM_ST2:    
        case AM_ST3:    
        case AM_ST4:    
        case AM_ST5:    
        case AM_ST6:    
        case AM_ST7:
            /* floating-point registers ST(x) */
            j = te->operands[i].am - AM_ST0;
            
            return decode_reg(x86_dctx, op, X86_REG_ST0, j);

        case AM_ES: 
        case AM_CS:
        case AM_SS: 
        case AM_DS:
        case AM_FS:
        case AM_GS:
            /* segment registers */
            j = te->operands[i].am - AM_ES;
            
            return decode_reg(x86_dctx, op, X86_REG_ES, j);

        default:
            dbg_err("undefined addressing method!");
            return -1;
    }

    return 0;
}

static 
int
decode_fix(x86_dasm_context_t* x86_dctx)
{
    x86_operand_t* op = &x86_dctx->operands[0];

    /* check if the base reg is a stack reg -> def. seg is ss */
    for(int i = 0; i < 4; i++)
    {
        if(op[i].type == X86_OPTYPE_MEXPR)
        {
            if( op[i].mexpr.base == X86_REG_SP || 
                op[i].mexpr.base == X86_REG_BP ||
                op[i].mexpr.base == X86_REG_ESP ||
                op[i].mexpr.base == X86_REG_EBP ||
                op[i].mexpr.base == X86_REG_RSP ||
                op[i].mexpr.base == X86_REG_RBP )
            {
                op[i].seg = X86_REG_SS;
            }
        }
    }

    /* check for mov CR8,reg / mov reg, CR8 using LOCK prefix */
    if(x86_dctx->mnem == X86_MN_MOV && x86_dctx->pfx_p_lock)
    {
        if( op[0].type == X86_OPTYPE_REG && 
            op[1].type == X86_OPTYPE_REG )
        {
            if(op[0].reg >= X86_REG_CR0 && op[0].reg <= X86_REG_CR15)
            {
                op[0].reg = X86_REG_CR8;
            }
            else
            if(op[1].reg >= X86_REG_CR0 && op[1].reg <= X86_REG_CR15)
            {
                op[1].reg = X86_REG_CR8;
            }
        }
    }

    /* fix for mov []. seg */
    if(x86_dctx->mnem == X86_MN_MOV)
    {
        if( op[0].type == X86_OPTYPE_MEXPR && 
            op[1].type == X86_OPTYPE_REG )
        {
            if(op[1].reg >= X86_REG_ES && op[1].reg <= X86_REG_GS)
            {
                op[0].size = X86_OPSIZE_WORD;
            }
        }
    }

    /* fix emms, vzeroupper, vzeroall */
    if( x86_dctx->mnem == X86_MN_EMMS &&
        (x86_dctx->pfx_p_vex2b || x86_dctx->pfx_p_vex3b) )
    {
        if(VEX_2B_L || VEX_3B_L)
        {
            /* 256-bit */
            x86_dctx->mnem = X86_MN_VZEROALL;

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

            strcpy(x86_dctx->mnem_str, "zeroall");

#endif

        }
        else
        {
            /* 128-bit */
            x86_dctx->mnem = X86_MN_VZEROUPPER;

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

            strcpy(x86_dctx->mnem_str, "zeroupper");

#endif

        }
    }

    /* fix xsaveopt */
    if( x86_dctx->mnem == X86_MN_XSAVEOPT && 
        x86_dctx->dmode == X86_DMODE_64BIT && REX_W )
    {
            x86_dctx->mnem = X86_MN_XSAVEOPT64;

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

            strcpy(x86_dctx->mnem_str, "xsaveopt64");

#endif

    }

    /* fix xrstor */
    if( x86_dctx->mnem == X86_MN_XRSTOR && 
        x86_dctx->dmode == X86_DMODE_64BIT && REX_W )
    {
            x86_dctx->mnem = X86_MN_XRSTOR64;

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

            strcpy(x86_dctx->mnem_str, "xrstor64");

#endif

    }

    /* fix xsave */
    if( x86_dctx->mnem == X86_MN_XSAVE && 
        x86_dctx->dmode == X86_DMODE_64BIT && REX_W )
    {
            x86_dctx->mnem = X86_MN_XSAVE64;

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

            strcpy(x86_dctx->mnem_str, "xsave64");

#endif

    }

    /* fix fxsave */
    if( x86_dctx->mnem == X86_MN_FXSAVE && 
        x86_dctx->dmode == X86_DMODE_64BIT && REX_W )
    {
            x86_dctx->mnem = X86_MN_FXSAVE64;

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

            strcpy(x86_dctx->mnem_str, "fxsave64");

#endif

    }

    /* fix fxrstor */
    if( x86_dctx->mnem == X86_MN_FXRSTOR && 
        x86_dctx->dmode == X86_DMODE_64BIT && REX_W )
    {
            x86_dctx->mnem = X86_MN_FXRSTOR64;

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

            strcpy(x86_dctx->mnem_str, "fxrstor64");

#endif

    }

    /* fix nop or pause */
    if( x86_dctx->mnem == X86_MN_XCHG &&
        x86_dctx->pfx_p_rex == false &&
        x86_dctx->buffer[x86_dctx->pos_opcode] == 0x90 )
    {
        if(x86_dctx->pfx_p_rep)
        {
            x86_dctx->mnem = X86_MN_PAUSE;

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

            strcpy(x86_dctx->mnem_str, "pause");

#endif

        }
        else
        {
            x86_dctx->mnem = X86_MN_NOP;

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

            strcpy(x86_dctx->mnem_str, "nop");

#endif

        }

        /* erase the operands */
        op[0].type = X86_OPTYPE_NONE;
        op[1].type = X86_OPTYPE_NONE;
    }

    /* fix immediate sign extensions */
    if(x86_dctx->iset == X86_ISET_GP)
    {
        /* should be valid for any GP instruction */

        int i;
        uint8_t tos = X86_OPSIZE_NONE; /* target operand size */

        if(x86_dctx->mnem == X86_MN_PUSH && op[0].type == X86_OPTYPE_IMM)
        {
            // 6A ib PUSH imm8 
            // 68 iw PUSH imm16 
            // 68 id PUSH imm32 

            /*
                Stack-address size. Outside of 64-bit mode, the B flag in 
                the current stack-segment descriptor determines the size of 
                the stack pointer (16 or 32 bits); in 64-bit mode, the size 
                of the stack pointer is always 64 bits.

                If the source operand is an immediate of size less than the 
                operand size, a sign-extended value is pushed on the stack
            */

            i = 0;

            switch(x86_dctx->osize)
            {
                case X86_OSIZE_16BIT:

                    /* byte */
                    if(op[0].size < X86_OPSIZE_WORD)
                    {
                        op[0].size_orig = op[0].size;
                        op[0].size = tos = X86_OPSIZE_WORD;
                    }
                    break;

                case X86_OSIZE_32BIT:

                    /* byte, word */
                    if(op[0].size < X86_OPSIZE_DWORD)
                    {
                        op[0].size_orig = op[0].size;
                        op[0].size = tos = X86_OPSIZE_DWORD;
                    }
                    break;

                case X86_OSIZE_64BIT:

                    /* byte, word, dword */
                    if(op[0].size < X86_OPSIZE_QWORD)
                    {
                        op[0].size_orig = op[0].size;
                        op[0].size = tos = X86_OPSIZE_QWORD;
                    }
                    break;

                default:
                    break;
            }
        }
        else
        {
            /* loop through the operands and sign-extend imms */
            for(i = 1; i < 4; i++)
            {
                if( op[i].type == X86_OPTYPE_IMM && 
                    op[i].size != op[i-1].size )
                {
                    /* update the op-size */
                    op[i].size_orig = op[i].size;
                    op[i].size = op[i-1].size;

                    tos = op[i-1].size;
                    break;
                }
            }
        }

        /* time to fix */
        if(tos != X86_OPSIZE_NONE)
        {
            switch(tos)
            {
                case X86_OPSIZE_QWORD:

                    switch(op[i].size_orig)
                    {
                        case X86_OPSIZE_DWORD:
                            op[i].data.s64 = op[i].data.s32;
                            break;

                        case X86_OPSIZE_WORD:
                            op[i].data.s64 = op[i].data.s16;
                            break;

                        case X86_OPSIZE_BYTE:
                            op[i].data.s64 = op[i].data.s8;
                            break;

                        default:
                            break;
                    }

                    break;

                case X86_OPSIZE_DWORD:

                    switch(op[i].size_orig)
                    {
                        case X86_OPSIZE_WORD:
                            op[i].data.s32 = op[i].data.s16;
                            break;

                        case X86_OPSIZE_BYTE:
                            op[i].data.s32 = op[i].data.s8;
                            break;

                        default:
                            break;
                    }

                    break;

                case X86_OPSIZE_WORD:

                    switch(op[i].size_orig)
                    {
                        case X86_OPSIZE_BYTE:
                            op[i].data.s16 = op[i].data.s8;
                            break;

                        default:
                            break;
                    }

                    break;

                default:
                    break;
            }
        }
    }

    /* get the EFLAGS */
    x86_dctx->eflags = x86_eflags_get(x86_dctx->mnem);

    return 0;
}

static 
int
decode_operand(x86_dasm_context_t* x86_dctx, const x86_table_entry_t* te, int i)
{
    /* it's necessary to decode the operand size first... */
    decode_opsize(x86_dctx, te, i);

    /* ...and then the operand type */
    return decode_optype(x86_dctx, te, i);
}

static 
void
decode_clear(x86_dasm_context_t* x86_dctx)
{
    x86_operand_t* op = &x86_dctx->operands[0];

    x86_dctx->pos = 0;
    x86_dctx->mnem = X86_MN_INVALID;

    x86_dctx->pos_modrm = 0;
    x86_dctx->pos_sib = 0;
    x86_dctx->pos_rex = 0;
    x86_dctx->pos_opcode = 0;

    x86_dctx->pfx_rex = 0;
    x86_dctx->pfx_last = 0;
    x86_dctx->pfx_seg = 0;
    x86_dctx->pfx_mandatory = 0;

    x86_dctx->pfx_c_osize = 0;
    x86_dctx->pfx_p_rex = false;
    x86_dctx->pfx_p_seg = false;
    x86_dctx->pfx_p_osize = false;
    x86_dctx->pfx_p_asize = false;
    x86_dctx->pfx_p_lock = false;
    x86_dctx->pfx_p_rep = false;
    x86_dctx->pfx_p_repne = false;
    x86_dctx->pfx_p_vex2b = false;
    x86_dctx->pfx_p_vex3b = false;
    x86_dctx->pfx_p_xop = false;
    x86_dctx->pfx_p_evex = false;
    x86_dctx->p_vsib = false;
    x86_dctx->vsib_base = X86_REG_NONE;

    x86_dctx->p_modrm = false;
    x86_dctx->p_sib = false;

    x86_dctx->dest_rip.u64 = 0;

    /* set all the flags to X86_FLAG_NA */
    memset(&x86_dctx->eflags, 0, sizeof(x86_dctx->eflags));

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

    memset(x86_dctx->inst_str, 0, sizeof(x86_dctx->inst_str));
    memset(x86_dctx->mnem_str, 0, sizeof(x86_dctx->mnem_str));

#endif

    /* clear the operands */
    for(int i = 0; i < 4; i++)
    {
        memset(&op[i], 0, sizeof(op[i]));

        op[i].type = X86_OPTYPE_NONE;
        op[i].size = X86_OPSIZE_NONE;
        op[i].size_orig = X86_OPSIZE_NONE;
        op[i].asize = X86_ASIZE_NONE;
    }
}

/****************************************************************************

    exported utility functions

****************************************************************************/

void
x86_set_dmode(x86_dasm_context_t* x86_dctx, int dmode)
{
    x86_dctx->dmode = dmode;
}

void
x86_set_ip(x86_dasm_context_t* x86_dctx, uint64_t ip)
{
    x86_dctx->rip.u64 = ip;
}

void
x86_set_buffer(x86_dasm_context_t* x86_dctx, void* code)
{
    /* 16 is max instruction len */
    memcpy(x86_dctx->buffer, code, 16);
}

bool_t
x86_is_jmp(x86_dasm_context_t* x86_dctx)
{
    return (x86_dctx->mnem == X86_MN_JMP || x86_dctx->mnem == X86_MN_JMPF);
}

bool_t
x86_is_jmpcc(x86_dasm_context_t* x86_dctx)
{
    switch(x86_dctx->mnem)
    {
        case X86_MN_JA:
        case X86_MN_JC:
        case X86_MN_JNG:
        case X86_MN_JZ:
        case X86_MN_JG:
        case X86_MN_JNL:
        case X86_MN_JL:
        case X86_MN_JNA:
        case X86_MN_JNC:
        case X86_MN_JNZ:
        case X86_MN_JNO:
        case X86_MN_JNP:
        case X86_MN_JNS:
        case X86_MN_JO:
        case X86_MN_JP:
        case X86_MN_JS:
        case X86_MN_JCXZ:
        case X86_MN_JECXZ:
        case X86_MN_JRCXZ:
            return true;

        default:
            return false;
    }
}

bool_t
x86_is_ret(x86_dasm_context_t* x86_dctx)
{
    switch(x86_dctx->mnem)
    {
        case X86_MN_IRET:
        case X86_MN_IRETW:
        case X86_MN_IRETD:
        case X86_MN_IRETQ:
        case X86_MN_RETN:
        case X86_MN_RETF:
            return true;

        default:
            return false;
    }
}

bool_t
x86_resolve_rip(x86_dasm_context_t* x86_dctx, ulong_t i, uint64_t* out)
{
    x86_operand_t* op = &x86_dctx->operands[i];

    /* check if it's a memory expression */
    if(op->type != X86_OPTYPE_MEXPR)
    {
        return false;
    }

    if(op->mexpr.base != X86_REG_RIP && op->mexpr.base != X86_REG_EIP)
    {
        return false;
    }

    /* compute the address */
    *out = x86_dctx->rip.u64 + x86_dctx->len + op->mexpr.disp.s32;

    if(op->mexpr.base == X86_REG_EIP)
    {
        /* truncate and zero extend */
        *out &= BIT_MASK(uint64_t, 32);
    }

    return true;
}

static uint64_t
x86_resolve_reg(uint8_t reg, x86_regs_t* regs)
{
    int i = 0;

    uint64_t result;
    uint64_t mask;

    /* build mask and get index */
    if(reg >= X86_REG_RAX && reg <= X86_REG_RIP)
    {
        mask = BIT_MASK(uint64_t, 64);

        /* compute register index */
        i = reg - X86_REG_RAX;
    }
    else
    if(reg >= X86_REG_EAX && reg <= X86_REG_EIP)
    {
        mask = BIT_MASK(uint64_t, 32);

        /* compute register index */
        i = reg - X86_REG_EAX;
    }
    else
    if(reg >= X86_REG_AX && reg <= X86_REG_R15W)
    {
        mask = BIT_MASK(uint64_t, 16);

        /* compute register index */
        i = reg - X86_REG_AX;
    }
    else
    if(reg >= X86_REG_AL && reg <= X86_REG_R15L)
    {
        mask = BIT_MASK(uint64_t, 8);

        /* compute register index */
        i = reg - X86_REG_AL;

        if(reg > X86_REG_BH)
        {
            i -= 4;
        }
    }
    else
    {
        mask = 0;
    }

    /* get the reg value */
    result = (*((x86_reg *)regs + i)).u64;
    result &= mask;

    return result;
}

uint64_t
x86_resolve_op(x86_dasm_context_t* x86_dctx, x86_regs_t* regs, ulong_t i)
{
    uint64_t result;

    x86_operand_t* op = &x86_dctx->operands[i];

    /* init */
    result = 0;

    /* memory expression */
    if(op->type == X86_OPTYPE_MEXPR)
    {
        result = *((uint64_t *)&regs->es + (op->seg - X86_REG_ES));

        /* check if there is a base register */
        if(op->mexpr.base != X86_REG_NONE)
        {
            result += x86_resolve_reg(op->mexpr.base, regs);
        }

        /* check if there is an index register */
        if(op->mexpr.index != X86_REG_NONE)
        {
            result += (x86_resolve_reg(op->mexpr.index, regs) * op->mexpr.scale);
        }

        /* check if there is a displacement */
        if(op->mexpr.disp_size != X86_DISP_NONE)
        {
            switch(op->mexpr.disp_size)
            {
                case X86_DISP_8: 
                    result += op->mexpr.disp.s8;
                    break;
                case X86_DISP_16:
                    result += op->mexpr.disp.s16;
                    break;
                case X86_DISP_32:
                    result += op->mexpr.disp.s32;
                    break;
                default: 
                    break;
            }
        }
    }
    else
    /* memory offset */
    if(op->type == X86_OPTYPE_MOFFS)
    {
        result = *((uint64_t *)&regs->es + (op->seg - X86_REG_ES));

        switch(op->asize)
        {
            case X86_ASIZE_WORD:
                result += op->data.u16; 
                break;
            case X86_ASIZE_DWORD:
                result += op->data.u32; 
                break;
            case X86_ASIZE_QWORD:
                result += op->data.u64; 
                break;
            default: 
                dbg_msg("invalid moffs asize!");
                break;
        }
    }
    else
    /* register */
    if(op->type == X86_OPTYPE_REG)
    {
        result += x86_resolve_reg(op->reg, regs);
    }
    else
    /* relative address */
    if(op->type == X86_OPTYPE_REL)
    {
        result = x86_dctx->dest_rip.u64;
    }
    else
    /* immediate */
    if(op->type == X86_OPTYPE_IMM)
    {
        switch(op->size)
        {
            case X86_OPSIZE_BYTE: 
                result = op->data.u8; 
                break;
            case X86_OPSIZE_WORD:
                result = op->data.u16; 
                break;
            case X86_OPSIZE_DWORD:
                result = op->data.u32; 
                break;
            case X86_OPSIZE_QWORD:
                result = op->data.u64; 
                break;
            default: 
                break;
        }
    }

    return result;
}

/****************************************************************************

    formatting functions

****************************************************************************/

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

static 
void
format_operand(x86_dasm_context_t* x86_dctx, int i)
{
    char tmp[32], *fmt;

    int64_t j = 0;
    uint64_t u = 0;
    
    x86_operand_t* op = &x86_dctx->operands[i];

    dbg_msg("type=%i", op->type);

    /* clear the tmp buffer */
    memset(tmp, 0, sizeof(tmp));

    switch(op->type)
    {
        case X86_OPTYPE_REG:
            /* copy the register name */
            strcat(op->str, regs_str[op->reg]);
            break;

        case X86_OPTYPE_IMM:

            switch(op->size)
            {
                case X86_OPSIZE_BYTE: 
                    fmt = "%" PRIX8; u = op->data.u8; 
                    break;
                case X86_OPSIZE_WORD:
                    fmt = "%" PRIX16; u = op->data.u16; 
                    break;
                case X86_OPSIZE_DWORD:
                    fmt = "%" PRIX32; u = op->data.u32; 
                    break;
                case X86_OPSIZE_QWORD:
                    fmt = "%" PRIX64; u = op->data.u64; 
                    break;
                default: 
                    fmt = "%" PRIX32;
                    break;
            }

            /* format the string and append it */
            sprintf(tmp, fmt, u);

            if( (tmp[0] >= 'A' && tmp[0] <= 'F') ||
                (tmp[0] >= 'a' && tmp[0] <= 'f') )
            {
                strcat(op->str, "0");
            }

            strcat(op->str, tmp);
            break;

        case X86_OPTYPE_MEXPR:

            /* far jmp and call */
            if( x86_dctx->mnem == X86_MN_JMPF ||
                x86_dctx->mnem == X86_MN_CALLF )
            {
                strcat(op->str, "far ");
            }

            /* format segment prefix */
            if(op->size != X86_OPSIZE_NONE)
            {
                sprintf(tmp, "%s ptr %s:", 
                    get_opsize_str(op->size), regs_str[op->seg]);
            }
            else
            {
                sprintf(tmp, "%s:", regs_str[op->seg]);
            }
            
            strcat(op->str, tmp);
            strcat(op->str, "[");

            /* check if there is a base register */
            if(op->mexpr.base != X86_REG_NONE)
            {
                strcat(op->str, regs_str[op->mexpr.base]);
            }

            /* check if there is an index register */
            if(op->mexpr.index != X86_REG_NONE)
            {
                if(op->mexpr.base != X86_REG_NONE)
                {
                    strcat(op->str, "+");
                }

                strcat(op->str, regs_str[op->mexpr.index]);

                if(op->mexpr.scale > 1)
                {
                    strcat(op->str, "*");

                    if(op->mexpr.scale == 2) strcat(op->str, "2");
                    if(op->mexpr.scale == 4) strcat(op->str, "4");
                    if(op->mexpr.scale == 8) strcat(op->str, "8");
                }
            }

            /* check if there is a displacement */
            if(op->mexpr.disp_size != X86_DISP_NONE)
            {
                switch(op->mexpr.disp_size)
                {
                    case X86_DISP_8: 
                        j = op->mexpr.disp.s8;
                        fmt = (j < 0 ? "-%" PRIX8 : "+%" PRIX8); 
                        break;
                    case X86_DISP_16:
                        j = op->mexpr.disp.s16;
                        fmt = (j < 0 ? "-%" PRIX16 : "+%" PRIX16);
                        break;
                    case X86_DISP_32:
                        j = op->mexpr.disp.s32;
                        fmt = (j < 0 ? "-%" PRIX32 : "+%" PRIX32);
                        break;
                    default: 
                        break;
                }

                /* check if there is only disp */
                if( op->mexpr.base == X86_REG_NONE && 
                    op->mexpr.index == X86_REG_NONE )
                {
                    /* skip the sign */
                    fmt++;
                    
                    if(j == 0) 
                    {
                        /* example: mov dword ptr fs:[0], eax */
                        strcpy(tmp, "0");
                    }
                    else 
                    {
                        sprintf(tmp, fmt, j);
                    }

                    if( (tmp[0] >= 'A' && tmp[0] <= 'F') ||
                        (tmp[0] >= 'a' && tmp[0] <= 'f') )
                    {
                        strcat(op->str, "0");
                    }

                    strcat(op->str, tmp);
                }
                else
                {
                    if(j != 0)
                    {
                        sprintf(tmp, fmt, (j < 0 ? -j : j));

                        if( (tmp[1] >= 'A' && tmp[1] <= 'F') ||
                            (tmp[1] >= 'a' && tmp[1] <= 'f') )
                        {
                            strcat(op->str, (j < 0 ? "-0" : "+0"));
                            strcat(op->str, &tmp[1]);
                        }
                        else
                        {
                            strcat(op->str, tmp);
                        }
                    }   
                }
            }

            strcat(op->str, "]");
            break;

        case X86_OPTYPE_ABS:

            /* copy the code segment */
            sprintf(op->str, "far %" PRIX16 ":", op->abs.seg);

            switch(op->size)
            {
                case X86_OPSIZE_DWORD: 
                    u = op->abs.offs.u16; fmt = "%" PRIX16; 
                    break;
                case X86_OPSIZE_FWORD:
                    u = op->abs.offs.u32; fmt = "%" PRIX32;
                    break;
                case X86_OPSIZE_TWORD:
                    u = op->abs.offs.u64; fmt = "%" PRIX64;
                    break;
                default: 
                    fmt = "%" PRIX32;
                    break;
            }

            /* format the string and append it */
            sprintf(tmp, fmt, u);

            if( (tmp[0] >= 'A' && tmp[0] <= 'F') ||
                (tmp[0] >= 'a' && tmp[0] <= 'f') )
            {
                strcat(op->str, "0");
            }

            strcat(op->str, tmp);
            break;

        case X86_OPTYPE_MOFFS:

            /* format segment prefix */
            if(op->size != X86_OPSIZE_NONE)
            {
                sprintf(tmp, "%s ptr %s:", 
                    get_opsize_str(op->size), regs_str[op->seg]);
            }
            else
            {
                sprintf(tmp, "%s:", regs_str[op->seg]);
            }
            
            strcat(op->str, tmp);
            strcat(op->str, "[");

            switch(op->asize)
            {
                case X86_ASIZE_WORD:
                    fmt = "%" PRIX16; u = op->data.u16; 
                    break;
                case X86_ASIZE_DWORD:
                    fmt = "%" PRIX32; u = op->data.u32; 
                    break;
                case X86_ASIZE_QWORD:
                    fmt = "%" PRIX64; u = op->data.u64; 
                    break;
                default: 
                    fmt = "%" PRIX32;
                    break;
            }

            /* format the string and append it */
            sprintf(tmp, fmt, u);

            if( (tmp[0] >= 'A' && tmp[0] <= 'F') ||
                (tmp[0] >= 'a' && tmp[0] <= 'f') )
            {
                strcat(op->str, "0");
            }

            strcat(op->str, tmp);
            strcat(op->str, "]");
            break;

        case X86_OPTYPE_REL:

            sprintf(tmp, "%s %" PRIX64, 
                (op->size == X86_OPSIZE_BYTE ? "short" : "near"), 
                x86_dctx->dest_rip.u64);

            strcat(op->str, tmp);
            break;

        default:
            break;
    }
}

static 
int
format_instruction(x86_dasm_context_t* x86_dctx, const x86_table_entry_t* te)
{
    char tmp[128];

    /* clear the tmp buffer */
    memset(tmp, 0, sizeof(tmp));

    /* check if the instruction is lock-able */
    if(x86_dctx->pfx_p_lock && te->properties & PF_LOCK)
    {
        strcat(tmp, "lock ");
    }
    else
    if(x86_dctx->pfx_p_rep && te->properties & PF_REP)
    {
        strcat(tmp, "rep ");
    }
    else
    if(x86_dctx->pfx_p_rep && te->properties & PF_REPE_REPNE)
    {
        strcat(tmp, "repe ");
    }
    else
    if(x86_dctx->pfx_p_repne && te->properties & PF_REPE_REPNE)
    {
        strcat(tmp, "repne ");
    }

    /* if there is a VEX prefix then add 'v' before the mnemonic */
    if(x86_dctx->pfx_p_vex2b || x86_dctx->pfx_p_vex3b)
    {
        if( x86_dctx->iset != X86_ISET_BMI2 && 
            x86_dctx->iset != X86_ISET_BMI1 )
        {
            strcat(tmp, "v");
        }
    }

    /* fix condition codes */
    if(te->properties & PF_CC || te->properties & PF_XOPCC)
    {
        char* p;
        char* s = NULL;
        uint8_t j = 0;
        size_t t = 0;

        char* cc_str[] = 
        {
            /* SSE and AVX */
            "eq", "lt", "le", "unord", "neq", "nlt", "nle", "ord",

            /* AVX */
            "eq_uq", "nge", "ngt", "false", "neq_oq", "ge", "gt",
            "true", "eq_os", "lt_oq", "le_oq", "unord_s", "neq_us",
            "nlt_uq", "ord_s", "eq_us", "nge_uq", "ngt_uq", "false_os",
            "neq_os", "ge_oq", "gt_oq", "true_us"
        };

        char* xopcc_str[] = 
        {
            "lt", "le", "gt", "ge", "eq", "neq", "false", "true"
        };

        /* get the last operand (immediate) */
        for(int i = 0; i < 4; i++)
        {
            if(x86_dctx->operands[i].type == X86_OPTYPE_IMM)
            {
                j = x86_dctx->operands[i].data.u8;
            }
        }

        /* get the wildcard position */
        p = strchr(x86_dctx->mnem_str, '*');
        t = p - x86_dctx->mnem_str;

        if(te->properties & PF_CC)
        {
            if(!(x86_dctx->pfx_p_vex2b || x86_dctx->pfx_p_vex3b))
            {
                j &= 7;
            }

            if(j < countof(cc_str))
            {
                s = cc_str[j];
            }
            else
            {
                dbg_err("Invalid condition code (SSE/AVX)");
                return -1;
            }
        }
        else
        if(te->properties & PF_XOPCC)
        {
            if(j < countof(xopcc_str))
            {
                s = xopcc_str[j];
            }
            else
            {
                dbg_err("Invalid condition code (XOP)");
                return -1;
            }
        }

        strncat(tmp, x86_dctx->mnem_str, t);
        strcat(tmp, s);
        strcat(tmp, p + 1);
    }
    else
    {
        /* copy the instruction mnemonic */
        strcat(tmp, x86_dctx->mnem_str);
    }

    /* append space only if there are operands */
    if(x86_dctx->operands[0].type != X86_OPTYPE_NONE)
    {
        strcat(tmp, " ");
    }

    /* append the formatted operands */
    for(int i = 0; i < 4; i++)
    {
        if(x86_dctx->operands[i].type != X86_OPTYPE_NONE)
        {
            if( x86_dctx->operands[i].type == X86_OPTYPE_IMM && 
                (te->properties & PF_CC || te->properties & PF_XOPCC) )
            {
                /* ignore the condition code immediate */
            }
            else
            {
                if(i > 0)
                {
                    strcat(tmp, ", ");
                }

                strcat(tmp, x86_dctx->operands[i].str);
            }
        }
    }

    strcpy(x86_dctx->inst_str, tmp);

    return 0;
}

#endif

/****************************************************************************

    entrypoint

****************************************************************************/

/*

    x86-64 legacy instruction format:

         #       0,1   1,2,3      0,1    0,1   0,1,2,4    0,1,2,4
    +----------+-----+--------+--------+-----+----------+---------+
    | prefixes | REX | OPCODE | MODR/M | SIB |   DISP   |   IMM   |
    +----------+-----+--------+--------+-----+----------+---------+

    note: in 64-bit mode, in some cases disp or imm can be 8 bytes
    (for example check mov: A0-A3 and B8)


    VEX/XOP instruction format:
        
         #          2,3          1        1      0,1   0,1,2,4    0,1
    +----------+-------------+--------+--------+-----+----------+-----+
    | SEG, 67h | VEX2B/VEX3B | OPCODE | MODR/M | SIB |   DISP   | IMM |
    +----------+-------------+--------+--------+-----+----------+-----+

    
    
    3DNow! instruction format:

         2            1          1      0,1,2,4           1
    +----------+-------------+--------+----------+----------------+
    | 0Fh 0Fh  |   MODR/M    |  SIB   |   DISP   | 3DNow!_suffix  |
    +----------+-------------+--------+----------+----------------+

*/

int
x86_dasm(x86_dasm_context_t* x86_dctx)
{
    const x86_table_entry_t* te;

    /* clear the dasm context */
    decode_clear(x86_dctx);

    /* function parses the prefixes (until opcode, excluded) */
    if(decode_prefixes(x86_dctx) < 0)
    {
        dbg_err("failed to decode the prefixes!");
        return -1;
    }

    /* determine the addressing size */
    get_asize(x86_dctx);

    /* determine the operand size */
    get_osize(x86_dctx, 0);

    /* function parses the opcode(s) */
    if(decode_opcode(x86_dctx, &te) < 0)
    {
        dbg_err("failed to decode the opcode!");
        return -1;
    }

    /* validate the instruction */

    if(te->mnem_id == X86_MN_INVALID)
    {
        dbg_err("invalid opcode!");
        return -1;
    }

    if(x86_dctx->dmode == X86_DMODE_64BIT && te->properties & PF_I64)
    {
        dbg_err("opcode is invalid in 64-bit mode!");
        return -1;
    }

    if(x86_dctx->dmode != X86_DMODE_64BIT && te->properties & PF_O64)
    {
        dbg_err("opcode is only valid in 64-bit mode!");
        return -1;
    }

    if( !x86_dctx->pfx_p_vex2b && 
        !x86_dctx->pfx_p_vex3b && te->properties & PF_OVEX )
    {
        dbg_err("opcode requires a VEX prefix!");
        return -1;
    }

    if(x86_dctx->pfx_p_vex2b || x86_dctx->pfx_p_vex3b) 
    {
        uint8_t j = 0;

        j = (x86_dctx->pfx_p_vex2b ? VEX_2B_L : j);
        j = (x86_dctx->pfx_p_vex3b ? VEX_3B_L : j);

        if( (te->properties & PF_VEX128 && j) ||
            (te->properties & PF_VEX256 && !j) )
        {
            dbg_err("invalid vector length!");
            return -1;
        }
    }

    /* calculate the operand size */
    get_osize(x86_dctx, te->properties);

    /* decode the operands (currently max 4) */
    for(int i = 0; i < 4; i++)
    {
        if(decode_operand(x86_dctx, te, i) < 0)
        {
            return -1;
        }
    }

    /* apply some fixups if needed */
    decode_fix(x86_dctx);

    /* check for max instruction length */
    if(x86_dctx->pos > MAX_INST_LENGTH)
    {
        dbg_err("instruction's size exceeded the limit!");
        return -1;
    }

#if !defined(X86_DASM_NOFMT) || defined(X86_DASM_DEBUG)

    /* format the operands (currently max 4) */
    for(int i = 0; i < 4; i++)
    {
        format_operand(x86_dctx, i);
    }

    if(format_instruction(x86_dctx, te) < 0)
        return -1;

#endif
    
    return 0;
}
