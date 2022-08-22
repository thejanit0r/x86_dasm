/*

    This file is part of x86_dasm.

    x86_dasm is a compact x86-64 disassembling library
    
    Copyright 2021 / the`janitor / < email: base64dec(dGhlLmphbml0b3JAcHJvdG9ubWFpbC5jb20=) >

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
#ifndef _DASM_MACROS_H_
#define _DASM_MACROS_H_

#include "x86_dasm.h"

/*
    This file provides some helper macros in an attempt to simplify conditional expressions.

    The core macros are part of the P99 macro suite for C99 by Jens Gustedt, with some slight modifications.
        - https://gitlab.inria.fr/gustedt/p99
    
*/

/***********************************************************************************************************************
    
    Core

***********************************************************************************************************************/

#define EXPAND(x) x

#define PP_CONCAT_(v1, v2) v1 ## v2
#define PP_CONCAT(v1, v2) PP_CONCAT_(v1, v2)

#define PP_CONCAT5_(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4

#define PP_IDENTITY_(x) x
#define PP_IDENTITY(x) PP_IDENTITY_(x)

#define PP_VA_ARGS_(...) __VA_ARGS__
#define PP_VA_ARGS(...) PP_VA_ARGS_(__VA_ARGS__)

#define PP_IDENTITY_VA_ARGS_(x, ...) x, __VA_ARGS__
#define PP_IDENTITY_VA_ARGS(x, ...) PP_IDENTITY_VA_ARGS_(x, __VA_ARGS__)

#define PP_IIF_0(x, ...) __VA_ARGS__
#define PP_IIF_1(x, ...) x
#define PP_IIF(c) PP_CONCAT_(PP_IIF_, c)

#define PP_HAS_COMMA(...) \
    PP_IDENTITY(PP_VA_ARGS_TAIL(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0))

#define PP_IS_EMPTY_TRIGGER_PARENTHESIS_(...) ,

#define PP_IS_EMPTY(...) PP_IS_EMPTY_( \
    /* test if there is just one argument, eventually an empty one */ \
    PP_HAS_COMMA(__VA_ARGS__),                                \
    /* test if _TRIGGER_PARENTHESIS_ together with the argument adds a comma */ \
    PP_HAS_COMMA(PP_IS_EMPTY_TRIGGER_PARENTHESIS_ __VA_ARGS__), \
    /* test if the argument together with a parenthesis adds a comma */ \
    PP_HAS_COMMA(__VA_ARGS__ ()),                             \
    /* test if placing it between _TRIGGER_PARENTHESIS_ and the parenthesis adds a comma */ \
    PP_HAS_COMMA(PP_IS_EMPTY_TRIGGER_PARENTHESIS_ __VA_ARGS__ ()))

#define PP_IS_EMPTY_(_0, _1, _2, _3) PP_HAS_COMMA(PP_CONCAT5_(PP_IS_EMPTY_IS_EMPTY_CASE_, _0, _1, _2, _3))
#define PP_IS_EMPTY_IS_EMPTY_CASE_0001 ,

#define PP_VA_ARGS_SIZE(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(0, PP_VA_ARGS_SIZE_(__VA_ARGS__, PP_VA_ARGS_SEQ64()))
#define PP_VA_ARGS_SIZE_(...) PP_IDENTITY(PP_VA_ARGS_TAIL(__VA_ARGS__))

#define PP_VA_ARGS_TAIL(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22, x, ...) x
#define PP_VA_ARGS_SEQ64() 23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

/***********************************************************************************************************************
    
    Register Operand

    Examples: REG(), REG32(), REG(RAX), REG(R8L)

***********************************************************************************************************************/

#define REG_CHECK_TYPE() type == X86_OPTYPE_REG
#define REG_CHECK_SIZE(_1) size == X86_OPSIZE_##_1
#define REG_0() REG_CHECK_TYPE(), REG_CHECK_TYPE(), REG_CHECK_TYPE()
#define REG_1(_1) reg == REG_##_1, REG_CHECK_TYPE(), REG_CHECK_TYPE()
#define REG_(N) REG_##N
#define REG_EVAL(N) REG_(N)
#define REG_INTERNAL(...) EXPAND(REG_EVAL(EXPAND(PP_VA_ARGS_SIZE(__VA_ARGS__)))(__VA_ARGS__))

#define REG(...) REG_INTERNAL(__VA_ARGS__) , REG_CHECK_TYPE() , REG_CHECK_TYPE()
#define REG8(...) REG_INTERNAL(__VA_ARGS__) , REG_CHECK_SIZE(BYTE) , REG_CHECK_TYPE()
#define REG16(...) REG_INTERNAL(__VA_ARGS__) , REG_CHECK_SIZE(WORD) , REG_CHECK_TYPE()
#define REG32(...) REG_INTERNAL(__VA_ARGS__) , REG_CHECK_SIZE(DWORD) , REG_CHECK_TYPE()
#define REG64(...) REG_INTERNAL(__VA_ARGS__) , REG_CHECK_SIZE(QWORD) , REG_CHECK_TYPE()

/***********************************************************************************************************************
    
    Immediate Operand

    Examples: IMM(), IMM8(), IMMS16(-2), IMM32(0xFFFFFFF8)

***********************************************************************************************************************/

#define IMM_CHECK_TYPE() type == X86_OPTYPE_IMM
#define IMM_CHECK_SIZE(_1) size == X86_OPSIZE_##_1
#define IMM_0() IMM_CHECK_TYPE()
#define IMM_1(_1) data.u64 == (uint64_t)_1
#define IMM_2(_1, _2) data.##_1 == _2
#define IMM_(N) IMM_##N
#define IMM_EVAL(N) IMM_(N)
#define IMM_INTERNAL(...) EXPAND(IMM_EVAL(EXPAND(PP_VA_ARGS_SIZE(__VA_ARGS__)))(__VA_ARGS__)) , \
    IMM_CHECK_TYPE() , IMM_CHECK_TYPE() , IMM_CHECK_TYPE()

#define IMM(...) IMM_INTERNAL(__VA_ARGS__) , IMM_CHECK_TYPE()
    
#define IMMU8(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(IMM_INTERNAL(__VA_ARGS__), IMM_INTERNAL(u8, __VA_ARGS__)) , \
    IMM_CHECK_SIZE(BYTE)

#define IMMU16(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(IMM_INTERNAL(__VA_ARGS__), IMM_INTERNAL(u16, __VA_ARGS__)) , \
    IMM_CHECK_SIZE(WORD)

#define IMMU32(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(IMM_INTERNAL(__VA_ARGS__), IMM_INTERNAL(u32, __VA_ARGS__)) , \
    IMM_CHECK_SIZE(DWORD)

#define IMMU64(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(IMM_INTERNAL(__VA_ARGS__), IMM_INTERNAL(u64, __VA_ARGS__)) , \
    IMM_CHECK_SIZE(QWORD)

#define IMMS8(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(IMM_INTERNAL(__VA_ARGS__), IMM_INTERNAL(s8, __VA_ARGS__)) , \
    IMM_CHECK_SIZE(BYTE)

#define IMMS16(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(IMM_INTERNAL(__VA_ARGS__), IMM_INTERNAL(s16, __VA_ARGS__)) , \
    IMM_CHECK_SIZE(WORD)

#define IMMS32(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(IMM_INTERNAL(__VA_ARGS__), IMM_INTERNAL(s32, __VA_ARGS__)) , \
    IMM_CHECK_SIZE(DWORD)

#define IMMS64(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(IMM_INTERNAL(__VA_ARGS__), IMM_INTERNAL(s64, __VA_ARGS__)) , \
    IMM_CHECK_SIZE(QWORD)

#define IMM8(...) IMMU8(__VA_ARGS__)
#define IMM16(...) IMMU16(__VA_ARGS__)
#define IMM32(...) IMMU32(__VA_ARGS__)
#define IMM64(...) IMMU64(__VA_ARGS__)

/***********************************************************************************************************************
    
    Memory Offset Operand

    Examples: MOFFS32(), MOFFS(0xFF800000)

***********************************************************************************************************************/

#define MOFFS_CHECK_TYPE() type == X86_OPTYPE_MOFFS
#define MOFFS_CHECK_SIZE(_1) size == X86_OPSIZE_##_1
#define MOFFS_0() MOFFS_CHECK_TYPE()
#define MOFFS_1(_1) data.u64 == (uint64_t)_1
#define MOFFS_2(_1, _2) data.##_1 == _2
#define MOFFS_(N) MOFFS_##N
#define MOFFS_EVAL(N) MOFFS_(N)
#define MOFFS_INTERNAL(...) EXPAND(MOFFS_EVAL(EXPAND(PP_VA_ARGS_SIZE(__VA_ARGS__)))(__VA_ARGS__)) , \
    MOFFS_CHECK_TYPE() , MOFFS_CHECK_TYPE() , MOFFS_CHECK_TYPE()

#define MOFFS(...) MOFFS_INTERNAL(__VA_ARGS__) , MOFFS_CHECK_TYPE()
    
#define MOFFS16(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(MOFFS_INTERNAL(__VA_ARGS__), MOFFS_INTERNAL(u16, __VA_ARGS__)) , \
    MOFFS_CHECK_SIZE(WORD)
    
#define MOFFS32(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(MOFFS_INTERNAL(__VA_ARGS__), MOFFS_INTERNAL(u32, __VA_ARGS__)) , \
    MOFFS_CHECK_SIZE(DWORD)
    
#define MOFFS64(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(MOFFS_INTERNAL(__VA_ARGS__), MOFFS_INTERNAL(u64, __VA_ARGS__)) , \
    MOFFS_CHECK_SIZE(QWORD)

/***********************************************************************************************************************
 
    Absolute Address Operand

    Examples: ABS32(0x33, 0x77546009), ABS64()

***********************************************************************************************************************/

#define ABS_CHECK_TYPE() type == X86_OPTYPE_ABS
#define ABS_CHECK_SIZE(_1) size == X86_OPSIZE_##_1
#define ABS_0() ABS_CHECK_TYPE(), ABS_CHECK_TYPE()
#define ABS_1(_1) abs.seg == _1, ABS_CHECK_TYPE()
#define ABS_3(_1, _2, _3) abs.seg == _2, abs.offs.##_1 == _3
#define ABS_(N) ABS_##N
#define ABS_EVAL(N) ABS_(N)
#define ABS_INTERNAL(...) EXPAND(ABS_EVAL(EXPAND(PP_VA_ARGS_SIZE(__VA_ARGS__)))(__VA_ARGS__)) , \
    ABS_CHECK_TYPE() , ABS_CHECK_TYPE()

#define ABS(...) ABS_INTERNAL(__VA_ARGS__) , ABS_CHECK_TYPE()
    
#define ABS16(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(ABS_INTERNAL(__VA_ARGS__), ABS_INTERNAL(u16, __VA_ARGS__)) , \
    ABS_CHECK_SIZE(DWORD)
    
#define ABS32(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(ABS_INTERNAL(__VA_ARGS__), ABS_INTERNAL(u32, __VA_ARGS__)) , \
    ABS_CHECK_SIZE(FWORD)
    
#define ABS64(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(ABS_INTERNAL(__VA_ARGS__), ABS_INTERNAL(u64, __VA_ARGS__)) , \
    ABS_CHECK_SIZE(TWORD)

/***********************************************************************************************************************
    
    Relative Operand

    Examples: REL8(), REL(-2), RELDST(0xBADF00D)

***********************************************************************************************************************/

#define REL_CHECK_TYPE() type == X86_OPTYPE_REL
#define REL_CHECK_SIZE(_1) size == X86_OPSIZE_##_1
#define REL_0() REL_CHECK_TYPE()
#define REL_1(_1) data.u64 == (uint64_t)_1
#define REL_2(_1, _2) data.##_1 == _2
#define REL_(N) REL_##N
#define REL_EVAL(N) REL_(N)
#define REL_INTERNAL(...) EXPAND(REL_EVAL(EXPAND(PP_VA_ARGS_SIZE(__VA_ARGS__)))(__VA_ARGS__)) , \
    REL_CHECK_TYPE() , REL_CHECK_TYPE() , REL_CHECK_TYPE()

#define REL(...) REL_INTERNAL(__VA_ARGS__) , REL_CHECK_TYPE()
    
#define REL8(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(REL_INTERNAL(__VA_ARGS__), REL_INTERNAL(s8, __VA_ARGS__)) , \
    REL_CHECK_SIZE(BYTE)
    
#define REL16(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(REL_INTERNAL(__VA_ARGS__), REL_INTERNAL(s16, __VA_ARGS__)) , \
    REL_CHECK_SIZE(WORD)
    
#define REL32(...) PP_IIF(PP_IS_EMPTY(__VA_ARGS__))(REL_INTERNAL(__VA_ARGS__), REL_INTERNAL(s32, __VA_ARGS__)) , \
    REL_CHECK_SIZE(DWORD)

#define RELDST(_1) dest_rip.u64 == (uint64_t)_1

/***********************************************************************************************************************
    
    Memory Expression Operand

    Examples: MEXPR(EAX), MEXPR(RAX, RCX, 2, 0x1BADB002)

***********************************************************************************************************************/

#define MEXPR_CHECK_TYPE() type == X86_OPTYPE_MEXPR

#define MEXPR_0() \
    MEXPR_CHECK_TYPE(), \
    MEXPR_CHECK_TYPE(), \
    MEXPR_CHECK_TYPE(), \
    MEXPR_CHECK_TYPE(), \
    MEXPR_CHECK_TYPE()

#define MEXPR_1(_1) \
    mexpr.base == X86_REG_##_1, \
    MEXPR_CHECK_TYPE(), \
    MEXPR_CHECK_TYPE(), \
    MEXPR_CHECK_TYPE(), \
    MEXPR_CHECK_TYPE()

#define MEXPR_2(_1, _2) \
    mexpr.base == X86_REG_##_1, \
    mexpr.index == X86_REG_##_2, \
    MEXPR_CHECK_TYPE(), \
    MEXPR_CHECK_TYPE(), \
    MEXPR_CHECK_TYPE()

#define MEXPR_3(_1, _2, _3) \
    mexpr.base == X86_REG_##_1, \
    mexpr.index == X86_REG_##_2, \
    mexpr.scale == _3, \
    MEXPR_CHECK_TYPE(), \
    MEXPR_CHECK_TYPE()

#define MEXPR_4(_1, _2, _3, _4) \
    mexpr.base == X86_REG_##_1, \
    mexpr.index == X86_REG_##_2, \
    mexpr.scale == _3, \
    mexpr.disp.u64 == (uint64_t)_4, \
    MEXPR_CHECK_TYPE()

#define MEXPR_(N) MEXPR_##N
#define MEXPR_EVAL(N) MEXPR_(N)
#define MEXPR(...) EXPAND(MEXPR_EVAL(EXPAND(PP_VA_ARGS_SIZE(__VA_ARGS__)))(__VA_ARGS__))

/***********************************************************************************************************************
    
    Matching Functions

    Examples: 
        
        X86M(&ctx, ANY, REG(), REG())
        X86M(&ctx, MOV, REG8(), IMM8())
        X86M(&ctx, CALL, RELDST(0xD00D2BAD))
        X86M(&ctx, JMP, REL(-2))

***********************************************************************************************************************/

#define OP_MATCH(_1, _2, _3, _4, _5, _6, _7) \
    ((_1)->operands[_2]._3 && (_1)->operands[_2]._4 && \
    (_1)->operands[_2]._5 && (_1)->operands[_2]._6 && \
    (_1)->operands[_2]._7)

#define INST_MATCH_0() ,
#define INST_MATCH_1(_1) ,
#define INST_MATCH_2(_1, _2) ((_1)->mnem == X86_MN_##_2 || X86_MN_##_2 == X86_MN_ANY)
#define INST_MATCH_3(_1, _2, _3) (IMATCH_2(_1, _2) && ((_1)->_3))
    
#define INST_MATCH_7(_1, _2, _3, _4, _5, _6, _7) \
    (INST_MATCH_2(_1, _2) && \
    OP_MATCH(_1, 0, _3, _4, _5, _6, _7))
    
#define INST_MATCH_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) \
    (INST_MATCH_7(_1, _2, _3, _4, _5, _6, _7) && \
    OP_MATCH(_1, 1, _8, _9, _10, _11, _12))
    
#define INST_MATCH_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) \
    (INST_MATCH_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) && \
    OP_MATCH(_1, 2, _13, _14, _15, _16, _17))
    
#define INST_MATCH_22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22) \
    (INST_MATCH_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) && \
    OP_MATCH(_1, 3, _18, _19, _20, _21, _22))
    
#define INST_MATCH_(N) INST_MATCH_##N
#define INST_MATCH_EVAL(N) INST_MATCH_(N)

#define X86M(...) EXPAND(INST_MATCH_EVAL(EXPAND(PP_VA_ARGS_SIZE(__VA_ARGS__)))(__VA_ARGS__))

#endif //_DASM_MACROS_H_