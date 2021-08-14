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
#include "x86_dasm.h"
#include "x86_dasm_tables.h"

/****************************************************************************

    One-byte tables

****************************************************************************/

TABLE_BEGIN(1B)

    /* 00h */
    TABLE_ENTRY("add",  X86_MN_ADD,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("add",  X86_MN_ADD,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("add",  X86_MN_ADD,     PF_NONE,    X86_ISET_GP,    OP(Gb, Eb)),
    TABLE_ENTRY("add",  X86_MN_ADD,     PF_NONE,    X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("add",  X86_MN_ADD,     PF_NONE,    X86_ISET_GP,    OP(AL, Ib)),
    TABLE_ENTRY("add",  X86_MN_ADD,     PF_NONE,    X86_ISET_GP,    OP(rAX, Iz)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_I64,     X86_ISET_GP,    OP(ES)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_I64,     X86_ISET_GP,    OP(ES)),
    
    TABLE_ENTRY("or",   X86_MN_OR,      PF_LOCK,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("or",   X86_MN_OR,      PF_LOCK,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("or",   X86_MN_OR,      PF_NONE,    X86_ISET_GP,    OP(Gb, Eb)),
    TABLE_ENTRY("or",   X86_MN_OR,      PF_NONE,    X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("or",   X86_MN_OR,      PF_NONE,    X86_ISET_GP,    OP(AL, Ib)),
    TABLE_ENTRY("or",   X86_MN_OR,      PF_NONE,    X86_ISET_GP,    OP(rAX, Iz)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_I64,     X86_ISET_GP,    OP(CS)),

    /* 0Fh: two-byte table escape */
    TABLE_ENTRY_INVALID(),

    /* 10h */
    TABLE_ENTRY("adc",  X86_MN_ADC,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("adc",  X86_MN_ADC,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("adc",  X86_MN_ADC,     PF_NONE,    X86_ISET_GP,    OP(Gb, Eb)),
    TABLE_ENTRY("adc",  X86_MN_ADC,     PF_NONE,    X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("adc",  X86_MN_ADC,     PF_NONE,    X86_ISET_GP,    OP(AL, Ib)),
    TABLE_ENTRY("adc",  X86_MN_ADC,     PF_NONE,    X86_ISET_GP,    OP(rAX, Iz)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_I64,     X86_ISET_GP,    OP(SS)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_I64,     X86_ISET_GP,    OP(SS)),
    
    TABLE_ENTRY("sbb",  X86_MN_SBB,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("sbb",  X86_MN_SBB,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("sbb",  X86_MN_SBB,     PF_NONE,    X86_ISET_GP,    OP(Gb, Eb)),
    TABLE_ENTRY("sbb",  X86_MN_SBB,     PF_NONE,    X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("sbb",  X86_MN_SBB,     PF_NONE,    X86_ISET_GP,    OP(AL, Ib)),
    TABLE_ENTRY("sbb",  X86_MN_SBB,     PF_NONE,    X86_ISET_GP,    OP(rAX, Iz)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_I64,     X86_ISET_GP,    OP(DS)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_I64,     X86_ISET_GP,    OP(DS)),

    /* 20h */
    TABLE_ENTRY("and",  X86_MN_AND,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("and",  X86_MN_AND,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("and",  X86_MN_AND,     PF_NONE,    X86_ISET_GP,    OP(Gb, Eb)),
    TABLE_ENTRY("and",  X86_MN_AND,     PF_NONE,    X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("and",  X86_MN_AND,     PF_NONE,    X86_ISET_GP,    OP(AL, Ib)),
    TABLE_ENTRY("and",  X86_MN_AND,     PF_NONE,    X86_ISET_GP,    OP(rAX, Iz)),
    
    /* 26h: prefix (prefixes should have already been parsed) */
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY("daa",  X86_MN_DAA,     PF_I64,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sub",  X86_MN_SUB,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("sub",  X86_MN_SUB,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("sub",  X86_MN_SUB,     PF_NONE,    X86_ISET_GP,    OP(Gb, Eb)),
    TABLE_ENTRY("sub",  X86_MN_SUB,     PF_NONE,    X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("sub",  X86_MN_SUB,     PF_NONE,    X86_ISET_GP,    OP(AL, Ib)),
    TABLE_ENTRY("sub",  X86_MN_SUB,     PF_NONE,    X86_ISET_GP,    OP(rAX, Iz)),

    /* 2Eh: prefix (prefixes should have already been parsed) */
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY("das",  X86_MN_DAS,     PF_I64,     X86_ISET_GP,    OP(NONE)),

    /* 30h */
    TABLE_ENTRY("xor",  X86_MN_XOR,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("xor",  X86_MN_XOR,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("xor",  X86_MN_XOR,     PF_NONE,    X86_ISET_GP,    OP(Gb, Eb)),
    TABLE_ENTRY("xor",  X86_MN_XOR,     PF_NONE,    X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("xor",  X86_MN_XOR,     PF_NONE,    X86_ISET_GP,    OP(AL, Ib)),
    TABLE_ENTRY("xor",  X86_MN_XOR,     PF_NONE,    X86_ISET_GP,    OP(rAX, Iz)),

    /* 36h: prefix (prefixes should have already been parsed) */
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY("aaa",  X86_MN_AAA,     PF_I64,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("cmp",  X86_MN_CMP,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("cmp",  X86_MN_CMP,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("cmp",  X86_MN_CMP,     PF_NONE,    X86_ISET_GP,    OP(Gb, Eb)),
    TABLE_ENTRY("cmp",  X86_MN_CMP,     PF_NONE,    X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("cmp",  X86_MN_CMP,     PF_NONE,    X86_ISET_GP,    OP(AL, Ib)),
    TABLE_ENTRY("cmp",  X86_MN_CMP,     PF_NONE,    X86_ISET_GP,    OP(rAX, Iz)),

    /* 3Eh: prefix (prefixes should have already been parsed) */
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY("aas",  X86_MN_AAS,     PF_I64,     X86_ISET_GP,    OP(NONE)),

    /* 40h: rex in 64-bit mode should have already been taken care of */
    TABLE_ENTRY("inc",  X86_MN_INC,     PF_I64,     X86_ISET_GP,    OP(eAX)),
    TABLE_ENTRY("inc",  X86_MN_INC,     PF_I64,     X86_ISET_GP,    OP(eCX)),
    TABLE_ENTRY("inc",  X86_MN_INC,     PF_I64,     X86_ISET_GP,    OP(eDX)),
    TABLE_ENTRY("inc",  X86_MN_INC,     PF_I64,     X86_ISET_GP,    OP(eBX)),
    TABLE_ENTRY("inc",  X86_MN_INC,     PF_I64,     X86_ISET_GP,    OP(eSP)),
    TABLE_ENTRY("inc",  X86_MN_INC,     PF_I64,     X86_ISET_GP,    OP(eBP)),
    TABLE_ENTRY("inc",  X86_MN_INC,     PF_I64,     X86_ISET_GP,    OP(eSI)),
    TABLE_ENTRY("inc",  X86_MN_INC,     PF_I64,     X86_ISET_GP,    OP(eDI)),
    TABLE_ENTRY("dec",  X86_MN_DEC,     PF_I64,     X86_ISET_GP,    OP(eAX)),
    TABLE_ENTRY("dec",  X86_MN_DEC,     PF_I64,     X86_ISET_GP,    OP(eCX)),
    TABLE_ENTRY("dec",  X86_MN_DEC,     PF_I64,     X86_ISET_GP,    OP(eDX)),
    TABLE_ENTRY("dec",  X86_MN_DEC,     PF_I64,     X86_ISET_GP,    OP(eBX)),
    TABLE_ENTRY("dec",  X86_MN_DEC,     PF_I64,     X86_ISET_GP,    OP(eSP)),
    TABLE_ENTRY("dec",  X86_MN_DEC,     PF_I64,     X86_ISET_GP,    OP(eBP)),
    TABLE_ENTRY("dec",  X86_MN_DEC,     PF_I64,     X86_ISET_GP,    OP(eSI)),
    TABLE_ENTRY("dec",  X86_MN_DEC,     PF_I64,     X86_ISET_GP,    OP(eDI)),

    /* 50h */
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(rAX_r8)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(rCX_r9)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(rDX_r10)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(rBX_r11)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(rSP_r12)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(rBP_r13)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(rSI_r14)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(rDI_r15)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_D64,     X86_ISET_GP,    OP(rAX_r8)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_D64,     X86_ISET_GP,    OP(rCX_r9)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_D64,     X86_ISET_GP,    OP(rDX_r10)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_D64,     X86_ISET_GP,    OP(rBX_r11)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_D64,     X86_ISET_GP,    OP(rSP_r12)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_D64,     X86_ISET_GP,    OP(rBP_r13)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_D64,     X86_ISET_GP,    OP(rSI_r14)),
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_D64,     X86_ISET_GP,    OP(rDI_r15)),

    /* 60h - 61h: pusha/pushad and popa/popad depending on operand size */
    TABLE_ENTRY_ESCAPE(60),
    TABLE_ENTRY_ESCAPE(61),

    TABLE_ENTRY("bound", X86_MN_BOUND,  PF_I64,     X86_ISET_GP,    OP(Gv, Ma)),

    /* 63h: ARPL I64 and MOVSXD O64 */
    TABLE_ENTRY_ESCAPE(63),

    /* 64h - 67h: prefix (prefixes should have already been parsed) */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 68h */
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(Iz)),
    TABLE_ENTRY("imul", X86_MN_IMUL,    PF_NONE,    X86_ISET_GP,    OP(Gv, Ev, Iz)),
    TABLE_ENTRY("push", X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(Ib)),
    TABLE_ENTRY("imul", X86_MN_IMUL,    PF_NONE,    X86_ISET_GP,    OP(Gv, Ev, Ib)),
    TABLE_ENTRY("insb", X86_MN_INSB,    PF_REP,     X86_ISET_GP,    OP(Yb, DX)),

    /* 6Dh: insw/insd depending on operand size */
    TABLE_ENTRY_ESCAPE(6D),

    /* 6Eh */
    TABLE_ENTRY("outsb",    X86_MN_OUTSB,   PF_REP, X86_ISET_GP,    OP(DX, Xb)),

    /* 6Fh: outsw/outsd depending on operand size */
    TABLE_ENTRY_ESCAPE(6F),

    /* 70h */
    TABLE_ENTRY("jo",   X86_MN_JO,      PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jno",  X86_MN_JNO,     PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jc",   X86_MN_JC,      PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jnc",  X86_MN_JNC,     PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jz",   X86_MN_JZ,      PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jnz",  X86_MN_JNZ,     PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jna",  X86_MN_JNA,     PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("ja",   X86_MN_JA,      PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("js",   X86_MN_JS,      PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jns",  X86_MN_JNS,     PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jp",   X86_MN_JP,      PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jnp",  X86_MN_JNP,     PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jl",   X86_MN_JL,      PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jnl",  X86_MN_JNL,     PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jng",  X86_MN_JNG,     PF_NONE,    X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jg",   X86_MN_JG,      PF_NONE,    X86_ISET_GP,    OP(Jb)),

    /* 80h: immediate group 1 */
    TABLE_ENTRY_ESCAPE(80),
    TABLE_ENTRY_ESCAPE(81),
    TABLE_ENTRY_ESCAPE(82),
    TABLE_ENTRY_ESCAPE(83),

    /* 84h */
    TABLE_ENTRY("test", X86_MN_TEST,    PF_NONE,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("test", X86_MN_TEST,    PF_NONE,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("xchg", X86_MN_XCHG,    PF_LOCK,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("xchg", X86_MN_XCHG,    PF_LOCK,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("mov",  X86_MN_MOV,     PF_NONE,    X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("mov",  X86_MN_MOV,     PF_NONE,    X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("mov",  X86_MN_MOV,     PF_NONE,    X86_ISET_GP,    OP(Gb, Eb)),
    TABLE_ENTRY("mov",  X86_MN_MOV,     PF_NONE,    X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("mov",  X86_MN_MOV,     PF_NONE,    X86_ISET_GP,    OP(Ev, Sw)),
    TABLE_ENTRY("lea",  X86_MN_LEA,     PF_NONE,    X86_ISET_GP,    OP(Gv, M)),
    TABLE_ENTRY("mov",  X86_MN_MOV,     PF_NONE,    X86_ISET_GP,    OP(Sw, Ew)),

    /* 8Fh: group 1A */
    TABLE_ENTRY_ESCAPE(8F),

    /* 90h */
    TABLE_ENTRY("xchg", X86_MN_XCHG,    PF_NONE,    X86_ISET_GP,    OP(rAX, rAX_r8)), /* alias nop, +f3 prefix=pause */
    TABLE_ENTRY("xchg", X86_MN_XCHG,    PF_NONE,    X86_ISET_GP,    OP(rAX, rCX_r9)),
    TABLE_ENTRY("xchg", X86_MN_XCHG,    PF_NONE,    X86_ISET_GP,    OP(rAX, rDX_r10)),
    TABLE_ENTRY("xchg", X86_MN_XCHG,    PF_NONE,    X86_ISET_GP,    OP(rAX, rBX_r11)),
    TABLE_ENTRY("xchg", X86_MN_XCHG,    PF_NONE,    X86_ISET_GP,    OP(rAX, rSP_r12)),
    TABLE_ENTRY("xchg", X86_MN_XCHG,    PF_NONE,    X86_ISET_GP,    OP(rAX, rBP_r13)),
    TABLE_ENTRY("xchg", X86_MN_XCHG,    PF_NONE,    X86_ISET_GP,    OP(rAX, rSI_r14)),
    TABLE_ENTRY("xchg", X86_MN_XCHG,    PF_NONE,    X86_ISET_GP,    OP(rAX, rDI_r15)),

    /* 98h - 99h: cbw/cwde/cdqe and cwd/cdq/cqo depending on operand size */
    TABLE_ENTRY_ESCAPE(98),
    TABLE_ENTRY_ESCAPE(99),

    /* 9Ah */
    TABLE_ENTRY("call",     X86_MN_CALLF,   PF_I64,     X86_ISET_GP,    OP(Ap)),
    TABLE_ENTRY("wait",     X86_MN_WAIT,    PF_NONE,    X86_ISET_FPU,   OP(NONE)), /* alias fwait */

    /* 9Ch - 9Dh: pushf/pushfd/pushfq and popf/popfd/popfq depending on operand size */
    TABLE_ENTRY_ESCAPE(9C),
    TABLE_ENTRY_ESCAPE(9D),

    /* 9Eh */
    TABLE_ENTRY("sahf",     X86_MN_SAHF,    PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("lahf",     X86_MN_LAHF,    PF_NONE,    X86_ISET_GP,    OP(NONE)),
    
    /* A0h */
    TABLE_ENTRY("mov",      X86_MN_MOV,     PF_NONE,    X86_ISET_GP,    OP(AL, Ob)),
    TABLE_ENTRY("mov",      X86_MN_MOV,     PF_NONE,    X86_ISET_GP,    OP(rAX, Ov)),
    TABLE_ENTRY("mov",      X86_MN_MOV,     PF_NONE,    X86_ISET_GP,    OP(Ob, AL)),
    TABLE_ENTRY("mov",      X86_MN_MOV,     PF_NONE,    X86_ISET_GP,    OP(Ov, rAX)),
    TABLE_ENTRY("movsb",    X86_MN_MOVSB,   PF_REP,     X86_ISET_GP,    OP(Yb, Xb)),

    /* A5h: movsw/movsd/movsq depending on operand size */
    TABLE_ENTRY_ESCAPE(A5),

    /* A6h */
    TABLE_ENTRY("cmpsb",    X86_MN_CMPSB,   PF_REPE_REPNE,  X86_ISET_GP,    OP(Xb, Yb)),

    /* A7h: cmpsw/cmpsd depending on operand size */
    TABLE_ENTRY_ESCAPE(A7),

    /* A8h */
    TABLE_ENTRY("test",     X86_MN_TEST,    PF_NONE,    X86_ISET_GP,    OP(AL, Ib)),
    TABLE_ENTRY("test",     X86_MN_TEST,    PF_NONE,    X86_ISET_GP,    OP(rAX, Iz)),
    TABLE_ENTRY("stosb",    X86_MN_STOSB,   PF_REP,     X86_ISET_GP,    OP(Yb, AL)),

    /* ABh: stosw/stosd/stosq depending on operand size */
    TABLE_ENTRY_ESCAPE(AB),

    /* ACh */
    TABLE_ENTRY("lodsb",    X86_MN_LODSB,   PF_REP,     X86_ISET_GP,    OP(AL, Xb)),

    /* ADh: lodsw/lodsd/lodsq depending on operand size */
    TABLE_ENTRY_ESCAPE(AD),

    /* AEh */
    TABLE_ENTRY("scasb",    X86_MN_SCASB,   PF_REPE_REPNE,  X86_ISET_GP,    OP(AL, Yb)),

    /* AFh: scasw/scasd/scasq depending on operand size */
    TABLE_ENTRY_ESCAPE(AF),

    /* B0h */
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(AL_r8L, Ib)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(CL_r9L, Ib)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(DL_r10L, Ib)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(BL_r11L, Ib)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(AH_r12L, Ib)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(CH_r13L, Ib)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(DH_r14L, Ib)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(BH_r15L, Ib)),
    
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(rAX_r8, Iv)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(rCX_r9, Iv)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(rDX_r10, Iv)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(rBX_r11, Iv)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(rSP_r12, Iv)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(rBP_r13, Iv)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(rSI_r14, Iv)),
    TABLE_ENTRY("mov",  X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(rDI_r15, Iv)),

    /* C0h - C1h: shift group 2 */
    TABLE_ENTRY_ESCAPE(C0),
    TABLE_ENTRY_ESCAPE(C1),

    /* C2h */
    TABLE_ENTRY("retn", X86_MN_RETN,    PF_NONE,    X86_ISET_GP,    OP(Iw)),
    TABLE_ENTRY("retn", X86_MN_RETN,    PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("les",  X86_MN_LES,     PF_I64,     X86_ISET_GP,    OP(Gz, Mp)), /* vex +2byte */
    TABLE_ENTRY("lds",  X86_MN_LDS,     PF_I64,     X86_ISET_GP,    OP(Gz, Mp)), /* vex +1byte */

    /* C6h - C7h: group 11 */
    TABLE_ENTRY_ESCAPE(C6),
    TABLE_ENTRY_ESCAPE(C7),

    /* C8h */
    TABLE_ENTRY("enter",    X86_MN_ENTER,   PF_NONE,    X86_ISET_GP,    OP(Iw, Ib)),
    TABLE_ENTRY("leave",    X86_MN_LEAVE,   PF_D64,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("retf",     X86_MN_RETF,    PF_NONE,    X86_ISET_GP,    OP(Iw)),
    TABLE_ENTRY("retf",     X86_MN_RETF,    PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("int",      X86_MN_INT3,    PF_NONE,    X86_ISET_GP,    OP(I3)),
    TABLE_ENTRY("int",      X86_MN_INT,     PF_NONE,    X86_ISET_GP,    OP(Ib)),
    TABLE_ENTRY("into",     X86_MN_INTO,    PF_I64,     X86_ISET_GP,    OP(NONE)),

    /* CFh: iretw/iretd/iretq depending on operand size */
    TABLE_ENTRY_ESCAPE(CF),

    /* D0h: shift group 2 */
    TABLE_ENTRY_ESCAPE(D0),
    TABLE_ENTRY_ESCAPE(D1),
    TABLE_ENTRY_ESCAPE(D2),
    TABLE_ENTRY_ESCAPE(D3),

    /* D4h */
    TABLE_ENTRY("aam",      X86_MN_AAM,     PF_I64,     X86_ISET_GP,    OP(Ib)),
    TABLE_ENTRY("aad",      X86_MN_AAD,     PF_I64,     X86_ISET_GP,    OP(Ib)),
    TABLE_ENTRY("salc",     X86_MN_SALC,    PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("xlatb",    X86_MN_XLAT,    PF_NONE,    X86_ISET_GP,    OP(NONE)),

    /* D8h: x87 FPU co-processor escape */
    TABLE_ENTRY_ESCAPE(D8),
    TABLE_ENTRY_ESCAPE(D9),
    TABLE_ENTRY_ESCAPE(DA),
    TABLE_ENTRY_ESCAPE(DB),
    TABLE_ENTRY_ESCAPE(DC),
    TABLE_ENTRY_ESCAPE(DD),
    TABLE_ENTRY_ESCAPE(DE),
    TABLE_ENTRY_ESCAPE(DF),

    /* E0h */
    TABLE_ENTRY("loopnz",   X86_MN_LOOPNZ,  PF_F64,     X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("loopz",    X86_MN_LOOPZ,   PF_F64,     X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("loop",     X86_MN_LOOP,    PF_F64,     X86_ISET_GP,    OP(Jb)),

    /* E3h: jcxz/jecxz/jrcxz depending on addressing size */
    TABLE_ENTRY_ESCAPE(E3),

    /* E4h */
    TABLE_ENTRY("in",       X86_MN_IN,      PF_NONE,    X86_ISET_GP,    OP(AL, Ib)),
    TABLE_ENTRY("in",       X86_MN_IN,      PF_NONE,    X86_ISET_GP,    OP(eAX, Ib)),
    TABLE_ENTRY("out",      X86_MN_OUT,     PF_NONE,    X86_ISET_GP,    OP(Ib, AL)),
    TABLE_ENTRY("out",      X86_MN_OUT,     PF_NONE,    X86_ISET_GP,    OP(Ib, eAX)),
    
    TABLE_ENTRY("call",     X86_MN_CALL,    PF_F64,     X86_ISET_GP,    OP(Jz)),
    TABLE_ENTRY("jmp",      X86_MN_JMP,     PF_F64,     X86_ISET_GP,    OP(Jz)),
    TABLE_ENTRY("jmp",      X86_MN_JMPF,    PF_I64,     X86_ISET_GP,    OP(Ap)),
    TABLE_ENTRY("jmp",      X86_MN_JMP,     PF_F64,     X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("in",       X86_MN_IN,      PF_NONE,    X86_ISET_GP,    OP(AL, DX)),
    TABLE_ENTRY("in",       X86_MN_IN,      PF_NONE,    X86_ISET_GP,    OP(eAX, DX)),
    TABLE_ENTRY("out",      X86_MN_OUT,     PF_NONE,    X86_ISET_GP,    OP(DX, AL)),
    TABLE_ENTRY("out",      X86_MN_OUT,     PF_NONE,    X86_ISET_GP,    OP(DX, eAX)),

    /* F0h: prefix (prefixes should have already been parsed) */
    TABLE_ENTRY_INVALID(), /* lock */
    TABLE_ENTRY("icebp",    X86_MN_ICEBP,   PF_NONE,    X86_ISET_GP,    OP(NONE)), /* single-step exception (int 01) */
    TABLE_ENTRY_INVALID(), /* repne/xacquire */
    TABLE_ENTRY_INVALID(), /* rep/xrelease */

    /* F4h */
    TABLE_ENTRY("hlt",  X86_MN_HLT,     PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("cmc",  X86_MN_CMC,     PF_NONE,    X86_ISET_GP,    OP(NONE)),

    /* F6h - F7h: unary group 3 */
    TABLE_ENTRY_ESCAPE(F6),
    TABLE_ENTRY_ESCAPE(F7),

    /* F8h */
    TABLE_ENTRY("clc",  X86_MN_CLC,     PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("stc",  X86_MN_STC,     PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("cli",  X86_MN_CLI,     PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sti",  X86_MN_STI,     PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("cld",  X86_MN_CLD,     PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("std",  X86_MN_STD,     PF_NONE,    X86_ISET_GP,    OP(NONE)),

    /* FEh - FFh: inc/dec group 4,5 */
    TABLE_ENTRY_ESCAPE(FE),
    TABLE_ENTRY_ESCAPE(FF)

TABLE_END(1B)

TABLE_BEGIN(60)

    /* operand size:  0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("pusha",    X86_MN_PUSHA,   PF_I64, X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("pushad",   X86_MN_PUSHAD,  PF_I64, X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY_INVALID()

TABLE_END(60)

TABLE_BEGIN(61)

    /* operand size:  0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("popa",     X86_MN_POPA,    PF_I64, X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("popad",    X86_MN_POPAD,   PF_I64, X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY_INVALID()

TABLE_END(61)

TABLE_BEGIN(63)

    /* dasm mode:  0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("arpl",     X86_MN_ARPL,        PF_I64,     X86_ISET_GP,    OP(Ew, Gw)),
    TABLE_ENTRY("arpl",     X86_MN_ARPL,        PF_I64,     X86_ISET_GP,    OP(Ew, Gw)),
    TABLE_ENTRY("movsxd",   X86_MN_MOVSXD,      PF_NONE,    X86_ISET_GP,    OP(Gv, Ev))

TABLE_END(63)

TABLE_BEGIN(6D)

    /* operand size:  0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("insw",     X86_MN_INSW,    PF_REP, X86_ISET_GP,    OP(Yz, DX)),
    TABLE_ENTRY("insd",     X86_MN_INSD,    PF_REP, X86_ISET_GP,    OP(Yz, DX)),
    TABLE_ENTRY("insd",     X86_MN_INSD,    PF_REP, X86_ISET_GP,    OP(Yz, DX))

TABLE_END(6D)

TABLE_BEGIN(6F)

    /* operand size:  0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("outsw",    X86_MN_OUTSW,   PF_REP, X86_ISET_GP,    OP(DX, Xz)),
    TABLE_ENTRY("outsd",    X86_MN_OUTSD,   PF_REP, X86_ISET_GP,    OP(DX, Xz)),
    TABLE_ENTRY("outsd",    X86_MN_OUTSD,   PF_REP, X86_ISET_GP,    OP(DX, Xz))

TABLE_END(6F)

TABLE_BEGIN(80)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("add",  X86_MN_ADD,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("or",   X86_MN_OR,      PF_LOCK,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("adc",  X86_MN_ADC,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("sbb",  X86_MN_SBB,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("and",  X86_MN_AND,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("sub",  X86_MN_SUB,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("xor",  X86_MN_XOR,     PF_LOCK,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("cmp",  X86_MN_CMP,     PF_NONE,    X86_ISET_GP,    OP(Eb, Ib))

TABLE_END(80)

TABLE_BEGIN(81)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("add",  X86_MN_ADD,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Iz)),
    TABLE_ENTRY("or",   X86_MN_OR,      PF_LOCK,    X86_ISET_GP,    OP(Ev, Iz)),
    TABLE_ENTRY("adc",  X86_MN_ADC,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Iz)),
    TABLE_ENTRY("sbb",  X86_MN_SBB,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Iz)),
    TABLE_ENTRY("and",  X86_MN_AND,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Iz)),
    TABLE_ENTRY("sub",  X86_MN_SUB,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Iz)),
    TABLE_ENTRY("xor",  X86_MN_XOR,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Iz)),
    TABLE_ENTRY("cmp",  X86_MN_CMP,     PF_NONE,    X86_ISET_GP,    OP(Ev, Iz))

TABLE_END(81)

TABLE_BEGIN(82)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("add",  X86_MN_ADD,     PF_I64 | PF_LOCK,       X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("or",   X86_MN_OR,      PF_I64 | PF_LOCK,       X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("adc",  X86_MN_ADC,     PF_I64 | PF_LOCK,       X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("sbb",  X86_MN_SBB,     PF_I64 | PF_LOCK,       X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("and",  X86_MN_AND,     PF_I64 | PF_LOCK,       X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("sub",  X86_MN_SUB,     PF_I64 | PF_LOCK,       X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("xor",  X86_MN_XOR,     PF_I64 | PF_LOCK,       X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("cmp",  X86_MN_CMP,     PF_I64,                 X86_ISET_GP,    OP(Eb, Ib))

TABLE_END(82)

TABLE_BEGIN(83)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("add",  X86_MN_ADD,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("or",   X86_MN_OR,      PF_LOCK,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("adc",  X86_MN_ADC,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("sbb",  X86_MN_SBB,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("and",  X86_MN_AND,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("sub",  X86_MN_SUB,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("xor",  X86_MN_XOR,     PF_LOCK,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("cmp",  X86_MN_CMP,     PF_NONE,    X86_ISET_GP,    OP(Ev, Ib))

TABLE_END(83)

TABLE_BEGIN(8F)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("pop",  X86_MN_POP,     PF_D64,     X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(8F)

TABLE_BEGIN(98)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("cbw",  X86_MN_CBW,     PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("cwde", X86_MN_CWDE,    PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("cdqe", X86_MN_CDQE,    PF_NONE,    X86_ISET_GP,    OP(NONE))

TABLE_END(98)

TABLE_BEGIN(99)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("cwd",  X86_MN_CWD, PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("cdq",  X86_MN_CDQ, PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("cqo",  X86_MN_CQO, PF_NONE,    X86_ISET_GP,    OP(NONE))

TABLE_END(99)

TABLE_BEGIN(9C)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("pushf",    X86_MN_PUSHF,   PF_D64, X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("pushfd",   X86_MN_PUSHFD,  PF_D64, X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("pushfq",   X86_MN_PUSHFQ,  PF_D64, X86_ISET_GP,    OP(NONE))

TABLE_END(9C)

TABLE_BEGIN(9D)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("popf",     X86_MN_POPF,    PF_D64, X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("popfd",    X86_MN_POPFD,   PF_D64, X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("popfq",    X86_MN_POPFQ,   PF_D64, X86_ISET_GP,    OP(NONE))

TABLE_END(9D)

TABLE_BEGIN(A5)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("movsw",    X86_MN_MOVSW,   PF_REP, X86_ISET_GP,    OP(Yv, Xv)),
    TABLE_ENTRY("movsd",    X86_MN_MOVSD,   PF_REP, X86_ISET_GP,    OP(Yv, Xv)),
    TABLE_ENTRY("movsq",    X86_MN_MOVSQ,   PF_REP, X86_ISET_GP,    OP(Yv, Xv))

TABLE_END(A5)

TABLE_BEGIN(A7)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("cmpsw",    X86_MN_CMPSW,   PF_REPE_REPNE,  X86_ISET_GP,    OP(Xv, Yv)),
    TABLE_ENTRY("cmpsd",    X86_MN_CMPSD,   PF_REPE_REPNE,  X86_ISET_GP,    OP(Xv, Yv)),
    TABLE_ENTRY("cmpsq",    X86_MN_CMPSQ,   PF_REPE_REPNE,  X86_ISET_GP,    OP(Xv, Yv)),

TABLE_END(A7)

TABLE_BEGIN(AB)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("stosw",    X86_MN_STOSW,   PF_REP, X86_ISET_GP,    OP(Yv, rAX)),
    TABLE_ENTRY("stosd",    X86_MN_STOSD,   PF_REP, X86_ISET_GP,    OP(Yv, rAX)),
    TABLE_ENTRY("stosq",    X86_MN_STOSQ,   PF_REP, X86_ISET_GP,    OP(Yv, rAX))

TABLE_END(AB)

TABLE_BEGIN(AD)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("lodsw",    X86_MN_LODSW,   PF_REP, X86_ISET_GP,    OP(rAX, Xv)),
    TABLE_ENTRY("lodsd",    X86_MN_LODSD,   PF_REP, X86_ISET_GP,    OP(rAX, Xv)),
    TABLE_ENTRY("lodsq",    X86_MN_LODSQ,   PF_REP, X86_ISET_GP,    OP(rAX, Xv))

TABLE_END(AD)

TABLE_BEGIN(AF)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("scasw",    X86_MN_SCASW,   PF_REPE_REPNE,  X86_ISET_GP,    OP(rAX, Xv)),
    TABLE_ENTRY("scasd",    X86_MN_SCASD,   PF_REPE_REPNE,  X86_ISET_GP,    OP(rAX, Xv)),
    TABLE_ENTRY("scasq",    X86_MN_SCASQ,   PF_REPE_REPNE,  X86_ISET_GP,    OP(rAX, Xv))

TABLE_END(AF)

TABLE_BEGIN(C0)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("rol",      X86_MN_ROL, PF_NONE,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("ror",      X86_MN_ROR, PF_NONE,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("rcl",      X86_MN_RCL, PF_NONE,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("rcr",      X86_MN_RCR, PF_NONE,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("shr",      X86_MN_SHR, PF_NONE,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("sar",      X86_MN_SAR, PF_NONE,    X86_ISET_GP,    OP(Eb, Ib))

TABLE_END(C0)

TABLE_BEGIN(C1)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("rol",      X86_MN_ROL, PF_NONE,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("ror",      X86_MN_ROR, PF_NONE,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("rcl",      X86_MN_RCL, PF_NONE,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("rcr",      X86_MN_RCR, PF_NONE,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("shr",      X86_MN_SHR, PF_NONE,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("sar",      X86_MN_SAR, PF_NONE,    X86_ISET_GP,    OP(Ev, Ib))

TABLE_END(C1)

TABLE_BEGIN(C6)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("mov",      X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("xabort",   X86_MN_XABORT,  PF_NONE,    X86_ISET_TSX,   OP(Ib))

TABLE_END(C6)

TABLE_BEGIN(C7)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("mov",      X86_MN_MOV, PF_NONE,    X86_ISET_GP,    OP(Ev, Iz)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("xbegin",   X86_MN_XBEGIN,  PF_NONE,    X86_ISET_TSX,   OP(Jz))

TABLE_END(C7)

TABLE_BEGIN(CF)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("iretw",    X86_MN_IRETW,   PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("iretd",    X86_MN_IRETD,   PF_NONE,    X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("iretq",    X86_MN_IRETQ,   PF_NONE,    X86_ISET_GP,    OP(NONE))

TABLE_END(CF)

TABLE_BEGIN(D0)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("rol",      X86_MN_ROL, PF_NONE,    X86_ISET_GP,    OP(Eb, I1)),
    TABLE_ENTRY("ror",      X86_MN_ROR, PF_NONE,    X86_ISET_GP,    OP(Eb, I1)),
    TABLE_ENTRY("rcl",      X86_MN_RCL, PF_NONE,    X86_ISET_GP,    OP(Eb, I1)),
    TABLE_ENTRY("rcr",      X86_MN_RCR, PF_NONE,    X86_ISET_GP,    OP(Eb, I1)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Eb, I1)),
    TABLE_ENTRY("shr",      X86_MN_SHR, PF_NONE,    X86_ISET_GP,    OP(Eb, I1)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Eb, I1)),
    TABLE_ENTRY("sar",      X86_MN_SAR, PF_NONE,    X86_ISET_GP,    OP(Eb, I1))

TABLE_END(D0)

TABLE_BEGIN(D1)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("rol",      X86_MN_ROL, PF_NONE,    X86_ISET_GP,    OP(Ev, I1)),
    TABLE_ENTRY("ror",      X86_MN_ROR, PF_NONE,    X86_ISET_GP,    OP(Ev, I1)),
    TABLE_ENTRY("rcl",      X86_MN_RCL, PF_NONE,    X86_ISET_GP,    OP(Ev, I1)),
    TABLE_ENTRY("rcr",      X86_MN_RCR, PF_NONE,    X86_ISET_GP,    OP(Ev, I1)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Ev, I1)),
    TABLE_ENTRY("shr",      X86_MN_SHR, PF_NONE,    X86_ISET_GP,    OP(Ev, I1)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Ev, I1)),
    TABLE_ENTRY("sar",      X86_MN_SAR, PF_NONE,    X86_ISET_GP,    OP(Ev, I1))

TABLE_END(D1)

TABLE_BEGIN(D2)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("rol",      X86_MN_ROL, PF_NONE,    X86_ISET_GP,    OP(Eb, CL)),
    TABLE_ENTRY("ror",      X86_MN_ROR, PF_NONE,    X86_ISET_GP,    OP(Eb, CL)),
    TABLE_ENTRY("rcl",      X86_MN_RCL, PF_NONE,    X86_ISET_GP,    OP(Eb, CL)),
    TABLE_ENTRY("rcr",      X86_MN_RCR, PF_NONE,    X86_ISET_GP,    OP(Eb, CL)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Eb, CL)),
    TABLE_ENTRY("shr",      X86_MN_SHR, PF_NONE,    X86_ISET_GP,    OP(Eb, CL)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Eb, CL)),
    TABLE_ENTRY("sar",      X86_MN_SAR, PF_NONE,    X86_ISET_GP,    OP(Eb, CL))

TABLE_END(D2)

TABLE_BEGIN(D3)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("rol",      X86_MN_ROL, PF_NONE,    X86_ISET_GP,    OP(Ev, CL)),
    TABLE_ENTRY("ror",      X86_MN_ROR, PF_NONE,    X86_ISET_GP,    OP(Ev, CL)),
    TABLE_ENTRY("rcl",      X86_MN_RCL, PF_NONE,    X86_ISET_GP,    OP(Ev, CL)),
    TABLE_ENTRY("rcr",      X86_MN_RCR, PF_NONE,    X86_ISET_GP,    OP(Ev, CL)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Ev, CL)),
    TABLE_ENTRY("shr",      X86_MN_SHR, PF_NONE,    X86_ISET_GP,    OP(Ev, CL)),
    TABLE_ENTRY("shl",      X86_MN_SHL, PF_NONE,    X86_ISET_GP,    OP(Ev, CL)),
    TABLE_ENTRY("sar",      X86_MN_SAR, PF_NONE,    X86_ISET_GP,    OP(Ev, CL))

TABLE_END(D3)

TABLE_BEGIN(E3)

    /* addressing size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("jcxz",     X86_MN_JCXZ,    PF_F64,     X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jecxz",    X86_MN_JECXZ,   PF_F64,     X86_ISET_GP,    OP(Jb)),
    TABLE_ENTRY("jrcxz",    X86_MN_JRCXZ,   PF_F64,     X86_ISET_GP,    OP(Jb))

TABLE_END(E3)

TABLE_BEGIN(F6)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("test",     X86_MN_TEST,    PF_NONE,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("test",     X86_MN_TEST,    PF_NONE,    X86_ISET_GP,    OP(Eb, Ib)),
    TABLE_ENTRY("not",      X86_MN_NOT,     PF_LOCK,    X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("neg",      X86_MN_NEG,     PF_LOCK,    X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("mul",      X86_MN_MUL,     PF_NONE,    X86_ISET_GP,    OP(Eb)), // OP(AL, Eb)
    TABLE_ENTRY("imul",     X86_MN_IMUL,    PF_NONE,    X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("div",      X86_MN_DIV,     PF_NONE,    X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("idiv",     X86_MN_IDIV,    PF_NONE,    X86_ISET_GP,    OP(Eb))

TABLE_END(F6)

TABLE_BEGIN(F7)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("test",     X86_MN_TEST,    PF_NONE,    X86_ISET_GP,    OP(Ev, Iz)),
    TABLE_ENTRY("test",     X86_MN_TEST,    PF_NONE,    X86_ISET_GP,    OP(Ev, Iz)),
    TABLE_ENTRY("not",      X86_MN_NOT,     PF_LOCK,    X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("neg",      X86_MN_NEG,     PF_LOCK,    X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("mul",      X86_MN_MUL,     PF_NONE,    X86_ISET_GP,    OP(Ev)), // OP(rAX, Ev)
    TABLE_ENTRY("imul",     X86_MN_IMUL,    PF_NONE,    X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("div",      X86_MN_DIV,     PF_NONE,    X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("idiv",     X86_MN_IDIV,    PF_NONE,    X86_ISET_GP,    OP(Ev))

TABLE_END(F7)

TABLE_BEGIN(FE)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("inc",      X86_MN_INC, PF_LOCK,    X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("dec",      X86_MN_DEC, PF_LOCK,    X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(FE)

TABLE_BEGIN(FF)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("inc",      X86_MN_INC,     PF_LOCK,    X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("dec",      X86_MN_DEC,     PF_LOCK,    X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("call",     X86_MN_CALL,    PF_F64,     X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("call",     X86_MN_CALLF,   PF_NONE,    X86_ISET_GP,    OP(Ep)),
    TABLE_ENTRY("jmp",      X86_MN_JMP,     PF_F64,     X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("jmp",      X86_MN_JMPF,    PF_NONE,    X86_ISET_GP,    OP(Mp)),
    TABLE_ENTRY("push",     X86_MN_PUSH,    PF_D64,     X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY_INVALID()

TABLE_END(FF)

/****************************************************************************

    x87 FPU co-processor tables

****************************************************************************/

TABLE_BEGIN(D8)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_ESCAPE(D8_MOD_N11),
    TABLE_ENTRY_ESCAPE(D8_MOD_11)

TABLE_END(D8)

TABLE_BEGIN(D9)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_ESCAPE(D9_MOD_N11),
    TABLE_ENTRY_ESCAPE(D9_MOD_11)

TABLE_END(D9)

TABLE_BEGIN(DA)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_ESCAPE(DA_MOD_N11),
    TABLE_ENTRY_ESCAPE(DA_MOD_11)

TABLE_END(DA)

TABLE_BEGIN(DB)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_ESCAPE(DB_MOD_N11),
    TABLE_ENTRY_ESCAPE(DB_MOD_11)

TABLE_END(DB)

TABLE_BEGIN(DC)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_ESCAPE(DC_MOD_N11),
    TABLE_ENTRY_ESCAPE(DC_MOD_11)

TABLE_END(DC)

TABLE_BEGIN(DD)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_ESCAPE(DD_MOD_N11),
    TABLE_ENTRY_ESCAPE(DD_MOD_11)

TABLE_END(DD)

TABLE_BEGIN(DE)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_ESCAPE(DE_MOD_N11),
    TABLE_ENTRY_ESCAPE(DE_MOD_11)

TABLE_END(DE)

TABLE_BEGIN(DF)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_ESCAPE(DF_MOD_N11),
    TABLE_ENTRY_ESCAPE(DF_MOD_11)

TABLE_END(DF)

TABLE_BEGIN(D8_MOD_N11)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(Md)), /* 32-bit real (single-real) */
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(Md)), /* 32-bit real (single-real) */
    TABLE_ENTRY("fcom",     X86_MN_FCOM,        PF_NONE,    X86_ISET_FPU,   OP(Md)), /* 32-bit real (single-real) */
    TABLE_ENTRY("fcomp",    X86_MN_FCOMP,       PF_NONE,    X86_ISET_FPU,   OP(Md)), /* 32-bit real (single-real) */
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(Md)), /* 32-bit real (single-real) */
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(Md)), /* 32-bit real (single-real) */
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(Md)), /* 32-bit real (single-real) */
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(Md))  /* 32-bit real (single-real) */

TABLE_END(D8_MOD_N11)

TABLE_BEGIN(D8_MOD_11)

    /* modr/m byte:  index = modr/m byte - C0h */
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 08h */
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 10h */
    TABLE_ENTRY("fcom",     X86_MN_FCOM,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcom",     X86_MN_FCOM,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcom",     X86_MN_FCOM,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcom",     X86_MN_FCOM,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcom",     X86_MN_FCOM,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcom",     X86_MN_FCOM,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcom",     X86_MN_FCOM,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcom",     X86_MN_FCOM,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 18h */
    TABLE_ENTRY("fcomp",    X86_MN_FCOMP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcomp",    X86_MN_FCOMP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcomp",    X86_MN_FCOMP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcomp",    X86_MN_FCOMP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcomp",    X86_MN_FCOMP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcomp",    X86_MN_FCOMP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcomp",    X86_MN_FCOMP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcomp",    X86_MN_FCOMP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 20h */
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 28h */
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 30h */
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 38h */
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7))

TABLE_END(D8_MOD_11)

TABLE_BEGIN(D9_MOD_N11)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("fld",      X86_MN_FLD,         PF_NONE,    X86_ISET_FPU,   OP(Md)), /* 32-bit real (single-real) */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("fst",      X86_MN_FST,         PF_NONE,    X86_ISET_FPU,   OP(Md)), /* 32-bit real (single-real) */
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(Md)), /* 32-bit real (single-real) */
    TABLE_ENTRY("fldenv",   X86_MN_FLDENV,      PF_NONE,    X86_ISET_FPU,   OP(M)),  /* 14/28 bytes */
    TABLE_ENTRY("fldcw",    X86_MN_FLDCW,       PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* 2 bytes -> word */
    TABLE_ENTRY("fnstenv",  X86_MN_FNSTENV,     PF_NONE,    X86_ISET_FPU,   OP(M)),  /* 14/28 bytes */
    TABLE_ENTRY("fnstcw",   X86_MN_FNSTCW,      PF_NONE,    X86_ISET_FPU,   OP(Mw))  /* 2 bytes -> word */

    /*
        The FSTENV instruction checks for and handles any pending unmasked 
        floating-point exceptions before storing the FPU environment; 
        the FNSTENV instruction does not.

        The assembler issues two instructions for the FSTENV instruction (an 
        FWAIT instruction followed by an FNSTENV instruction), and the 
        processor executes each of these instructions separately. If an 
        exception is generated for either of these instructions, the save EIP 
        points to the instruction that caused the exception.
    */

TABLE_END(D9_MOD_N11)

TABLE_BEGIN(D9_MOD_11)

    /* modr/m byte:  index = modr/m byte - C0h */
    TABLE_ENTRY("fld",      X86_MN_FLD,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fld",      X86_MN_FLD,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fld",      X86_MN_FLD,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fld",      X86_MN_FLD,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fld",      X86_MN_FLD,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fld",      X86_MN_FLD,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fld",      X86_MN_FLD,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fld",      X86_MN_FLD,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 08h */
    TABLE_ENTRY("fxch",     X86_MN_FXCH,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fxch",     X86_MN_FXCH,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fxch",     X86_MN_FXCH,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fxch",     X86_MN_FXCH,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fxch",     X86_MN_FXCH,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fxch",     X86_MN_FXCH,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fxch",     X86_MN_FXCH,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fxch",     X86_MN_FXCH,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 10h */
    TABLE_ENTRY("fnop",     X86_MN_FNOP,        PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 18h */
    TABLE_ENTRY("fstp1",    X86_MN_FSTP1,       PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("fstp1",    X86_MN_FSTP1,       PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("fstp1",    X86_MN_FSTP1,       PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("fstp1",    X86_MN_FSTP1,       PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("fstp1",    X86_MN_FSTP1,       PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("fstp1",    X86_MN_FSTP1,       PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("fstp1",    X86_MN_FSTP1,       PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("fstp1",    X86_MN_FSTP1,       PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 20h */
    TABLE_ENTRY("fchs",     X86_MN_FCHS,        PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fabs",     X86_MN_FABS,        PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("ftst",     X86_MN_FTST,        PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fxam",     X86_MN_FXAM,        PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 28h */
    TABLE_ENTRY("fld1",     X86_MN_FLD1,        PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fldl2t",   X86_MN_FLDL2T,      PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fldl2e",   X86_MN_FLDL2E,      PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fldpi",    X86_MN_FLDPI,       PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fldlg2",   X86_MN_FLDLG2,      PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fldln2",   X86_MN_FLDLN2,      PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fldz",     X86_MN_FLDZ,        PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY("f2xm1",    X86_MN_F2XM1,       PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fyl2x",    X86_MN_FYL2X,       PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fptan",    X86_MN_FPTAN,       PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fpatan",   X86_MN_FPATAN,      PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fxtract",  X86_MN_FXTRACT,     PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fprem1",   X86_MN_FPREM1,      PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fdecstp",  X86_MN_FDECSTP,     PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fincstp",  X86_MN_FINCSTP,     PF_NONE,    X86_ISET_FPU,   OP(NONE)),

    /* 38h */
    TABLE_ENTRY("fprem",    X86_MN_FPREM,       PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fyl2xp1",  X86_MN_FYL2XP1,     PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fsqrt",    X86_MN_FSQRT,       PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fsincos",  X86_MN_FSINCOS,     PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("frndint",  X86_MN_FRNDINT,     PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fscale",   X86_MN_FSCALE,      PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fsin",     X86_MN_FSIN,        PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fcos",     X86_MN_FCOS,        PF_NONE,    X86_ISET_FPU,   OP(NONE))

TABLE_END(D9_MOD_11)

TABLE_BEGIN(DA_MOD_N11)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("fiadd",    X86_MN_FIADD,       PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY("fimul",    X86_MN_FIMUL,       PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY("ficom",    X86_MN_FICOM,       PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY("ficomp",   X86_MN_FICOMP,      PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY("fisub",    X86_MN_FISUB,       PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY("fisubr",   X86_MN_FISUBR,      PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY("fidiv",    X86_MN_FIDIV,       PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY("fidivr",   X86_MN_FIDIVR,      PF_NONE,    X86_ISET_FPU,   OP(Md))  /* dword-integer */

TABLE_END(DA_MOD_N11)

TABLE_BEGIN(DA_MOD_11)

    /* modr/m byte:  index = modr/m byte - C0h */
    TABLE_ENTRY("fcmovb",   X86_MN_FCMOVB,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcmovb",   X86_MN_FCMOVB,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcmovb",   X86_MN_FCMOVB,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcmovb",   X86_MN_FCMOVB,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcmovb",   X86_MN_FCMOVB,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcmovb",   X86_MN_FCMOVB,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcmovb",   X86_MN_FCMOVB,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcmovb",   X86_MN_FCMOVB,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 08h */
    TABLE_ENTRY("fcmove",   X86_MN_FCMOVE,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcmove",   X86_MN_FCMOVE,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcmove",   X86_MN_FCMOVE,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcmove",   X86_MN_FCMOVE,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcmove",   X86_MN_FCMOVE,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcmove",   X86_MN_FCMOVE,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcmove",   X86_MN_FCMOVE,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcmove",   X86_MN_FCMOVE,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 10h */
    TABLE_ENTRY("fcmovbe",  X86_MN_FCMOVBE,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcmovbe",  X86_MN_FCMOVBE,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcmovbe",  X86_MN_FCMOVBE,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcmovbe",  X86_MN_FCMOVBE,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcmovbe",  X86_MN_FCMOVBE,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcmovbe",  X86_MN_FCMOVBE,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcmovbe",  X86_MN_FCMOVBE,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcmovbe",  X86_MN_FCMOVBE,     PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 18h */
    TABLE_ENTRY("fcmovu",   X86_MN_FCMOVU,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcmovu",   X86_MN_FCMOVU,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcmovu",   X86_MN_FCMOVU,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcmovu",   X86_MN_FCMOVU,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcmovu",   X86_MN_FCMOVU,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcmovu",   X86_MN_FCMOVU,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcmovu",   X86_MN_FCMOVU,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcmovu",   X86_MN_FCMOVU,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 28h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("fucompp",  X86_MN_FUCOMPP, PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 38h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(DA_MOD_11)

TABLE_BEGIN(DB_MOD_N11)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("fild",     X86_MN_FILD,        PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY("fisttp",   X86_MN_FISTTP,      PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY("fist",     X86_MN_FIST,        PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY("fistp",    X86_MN_FISTP,       PF_NONE,    X86_ISET_FPU,   OP(Md)), /* dword-integer */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("fld",      X86_MN_FLD,         PF_NONE,    X86_ISET_FPU,   OP(Mt)), /* 80-bit real (extended-real) */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(Mt))  /* 80-bit real (extended-real) */

TABLE_END(DB_MOD_N11)

TABLE_BEGIN(DB_MOD_11)

    /* modr/m byte:  index = modr/m byte - C0h */
    TABLE_ENTRY("fcmovnb",  X86_MN_FCMOVNB, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcmovnb",  X86_MN_FCMOVNB, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcmovnb",  X86_MN_FCMOVNB, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcmovnb",  X86_MN_FCMOVNB, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcmovnb",  X86_MN_FCMOVNB, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcmovnb",  X86_MN_FCMOVNB, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcmovnb",  X86_MN_FCMOVNB, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcmovnb",  X86_MN_FCMOVNB, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 08h */
    TABLE_ENTRY("fcmovne",  X86_MN_FCMOVNE, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcmovne",  X86_MN_FCMOVNE, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcmovne",  X86_MN_FCMOVNE, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcmovne",  X86_MN_FCMOVNE, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcmovne",  X86_MN_FCMOVNE, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcmovne",  X86_MN_FCMOVNE, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcmovne",  X86_MN_FCMOVNE, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcmovne",  X86_MN_FCMOVNE, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 10h */
    TABLE_ENTRY("fcmovnbe", X86_MN_FCMOVNBE,    PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcmovnbe", X86_MN_FCMOVNBE,    PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcmovnbe", X86_MN_FCMOVNBE,    PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcmovnbe", X86_MN_FCMOVNBE,    PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcmovnbe", X86_MN_FCMOVNBE,    PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcmovnbe", X86_MN_FCMOVNBE,    PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcmovnbe", X86_MN_FCMOVNBE,    PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcmovnbe", X86_MN_FCMOVNBE,    PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 18h */
    TABLE_ENTRY("fcmovnu",  X86_MN_FCMOVNU, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcmovnu",  X86_MN_FCMOVNU, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcmovnu",  X86_MN_FCMOVNU, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcmovnu",  X86_MN_FCMOVNU, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcmovnu",  X86_MN_FCMOVNU, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcmovnu",  X86_MN_FCMOVNU, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcmovnu",  X86_MN_FCMOVNU, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcmovnu",  X86_MN_FCMOVNU, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("fnclex",   X86_MN_FNCLEX,      PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY("fninit",   X86_MN_FNINIT,      PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /*
        The assembler issues two instructions for the FCLEX instruction (an 
        FWAIT instruction followed by an FNCLEX instruction), and the 
        processor executes each of these instructions separately. If an 
        exception is generated for either of these instructions, the save EIP 
        points to the instruction that caused the exception.

        same shit for FINIT/FNINIT
    */

    /* 28h */
    TABLE_ENTRY("fucomi",   X86_MN_FUCOMI,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fucomi",   X86_MN_FUCOMI,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fucomi",   X86_MN_FUCOMI,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fucomi",   X86_MN_FUCOMI,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fucomi",   X86_MN_FUCOMI,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fucomi",   X86_MN_FUCOMI,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fucomi",   X86_MN_FUCOMI,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fucomi",   X86_MN_FUCOMI,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 30h */
    TABLE_ENTRY("fcomi",    X86_MN_FCOMI,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcomi",    X86_MN_FCOMI,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcomi",    X86_MN_FCOMI,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcomi",    X86_MN_FCOMI,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcomi",    X86_MN_FCOMI,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcomi",    X86_MN_FCOMI,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcomi",    X86_MN_FCOMI,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcomi",    X86_MN_FCOMI,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 38h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(DB_MOD_11)

TABLE_BEGIN(DC_MOD_N11)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* 64-bit real (double-real) */
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* 64-bit real (double-real) */
    TABLE_ENTRY("fcom",     X86_MN_FCOM,        PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* 64-bit real (double-real) */
    TABLE_ENTRY("fcomp",    X86_MN_FCOMP,       PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* 64-bit real (double-real) */
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* 64-bit real (double-real) */
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* 64-bit real (double-real) */
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* 64-bit real (double-real) */
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(Mq))  /* 64-bit real (double-real) */

TABLE_END(DC_MOD_N11)

TABLE_BEGIN(DC_MOD_11)

    /* modr/m byte:  index = modr/m byte - C0h */
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fadd",     X86_MN_FADD,        PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 08h */
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fmul",     X86_MN_FMUL,        PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 10h */
    TABLE_ENTRY("fcom2",    X86_MN_FCOM2,       PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("fcom2",    X86_MN_FCOM2,       PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("fcom2",    X86_MN_FCOM2,       PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("fcom2",    X86_MN_FCOM2,       PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("fcom2",    X86_MN_FCOM2,       PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("fcom2",    X86_MN_FCOM2,       PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("fcom2",    X86_MN_FCOM2,       PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("fcom2",    X86_MN_FCOM2,       PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 18h */
    TABLE_ENTRY("fcomp3",   X86_MN_FCOMP3,      PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("fcomp3",   X86_MN_FCOMP3,      PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("fcomp3",   X86_MN_FCOMP3,      PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("fcomp3",   X86_MN_FCOMP3,      PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("fcomp3",   X86_MN_FCOMP3,      PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("fcomp3",   X86_MN_FCOMP3,      PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("fcomp3",   X86_MN_FCOMP3,      PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("fcomp3",   X86_MN_FCOMP3,      PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 20h */
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fsubr",    X86_MN_FSUBR,       PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 28h */
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fsub",     X86_MN_FSUB,        PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 30h */
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fdivr",    X86_MN_FDIVR,       PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 38h */
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fdiv",     X86_MN_FDIV,        PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0))

TABLE_END(DC_MOD_11)

TABLE_BEGIN(DD_MOD_N11)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("fld",      X86_MN_FLD,         PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* 64-bit real (double-real) */ 
    TABLE_ENTRY("fisttp",   X86_MN_FISTTP,      PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* integer64 */
    TABLE_ENTRY("fst",      X86_MN_FST,         PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* 64-bit real (double-real) */
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* 64-bit real (double-real) */
    TABLE_ENTRY("frstor",   X86_MN_FRSTOR,      PF_NONE,    X86_ISET_FPU,   OP(M)),  /* 98/108 bytes */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("fnsave",   X86_MN_FNSAVE,      PF_NONE,    X86_ISET_FPU,   OP(M)),  /* 98/108 bytes */
    TABLE_ENTRY("fnstsw",   X86_MN_FNSTSW,      PF_NONE,    X86_ISET_FPU,   OP(Mw))  /* 2 bytes -> word */

    /* 
        FNSAVE/FSAVE and FNSTSW/FSTSW with WAIT/FWAIT prefix same shit like 
        before. 
    */

TABLE_END(DD_MOD_N11)

TABLE_BEGIN(DD_MOD_11)

    /* modr/m byte:  index = modr/m byte - C0h */
    TABLE_ENTRY("ffree",    X86_MN_FFREE,       PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("ffree",    X86_MN_FFREE,       PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("ffree",    X86_MN_FFREE,       PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("ffree",    X86_MN_FFREE,       PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("ffree",    X86_MN_FFREE,       PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("ffree",    X86_MN_FFREE,       PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("ffree",    X86_MN_FFREE,       PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("ffree",    X86_MN_FFREE,       PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 08h */
    TABLE_ENTRY("fxch4",    X86_MN_FXCH4,       PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("fxch4",    X86_MN_FXCH4,       PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("fxch4",    X86_MN_FXCH4,       PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("fxch4",    X86_MN_FXCH4,       PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("fxch4",    X86_MN_FXCH4,       PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("fxch4",    X86_MN_FXCH4,       PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("fxch4",    X86_MN_FXCH4,       PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("fxch4",    X86_MN_FXCH4,       PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 10h */
    TABLE_ENTRY("fst",      X86_MN_FST,     PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("fst",      X86_MN_FST,     PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("fst",      X86_MN_FST,     PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("fst",      X86_MN_FST,     PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("fst",      X86_MN_FST,     PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("fst",      X86_MN_FST,     PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("fst",      X86_MN_FST,     PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("fst",      X86_MN_FST,     PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 18h */
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("fstp",     X86_MN_FSTP,        PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 20h */
    TABLE_ENTRY("fucom",    X86_MN_FUCOM,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fucom",    X86_MN_FUCOM,       PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fucom",    X86_MN_FUCOM,       PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fucom",    X86_MN_FUCOM,       PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fucom",    X86_MN_FUCOM,       PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fucom",    X86_MN_FUCOM,       PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fucom",    X86_MN_FUCOM,       PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fucom",    X86_MN_FUCOM,       PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 28h */
    TABLE_ENTRY("fucomp",   X86_MN_FUCOMP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fucomp",   X86_MN_FUCOMP,      PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fucomp",   X86_MN_FUCOMP,      PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fucomp",   X86_MN_FUCOMP,      PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fucomp",   X86_MN_FUCOMP,      PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fucomp",   X86_MN_FUCOMP,      PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fucomp",   X86_MN_FUCOMP,      PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fucomp",   X86_MN_FUCOMP,      PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 38h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(DD_MOD_11)

TABLE_BEGIN(DE_MOD_N11)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("fiadd",    X86_MN_FIADD,       PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("fimul",    X86_MN_FIMUL,       PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("ficom",    X86_MN_FICOM,       PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("ficomp",   X86_MN_FICOMP,      PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("fisub",    X86_MN_FISUB,       PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("fisubr",   X86_MN_FISUBR,      PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("fidiv",    X86_MN_FIDIV,       PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("fidivr",   X86_MN_FIDIVR,      PF_NONE,    X86_ISET_FPU,   OP(Mw))  /* word integer */

TABLE_END(DE_MOD_N11)

TABLE_BEGIN(DE_MOD_11)

    /* modr/m byte:  index = modr/m byte - C0h */
    TABLE_ENTRY("faddp",    X86_MN_FADDP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("faddp",    X86_MN_FADDP,       PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("faddp",    X86_MN_FADDP,       PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("faddp",    X86_MN_FADDP,       PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("faddp",    X86_MN_FADDP,       PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("faddp",    X86_MN_FADDP,       PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("faddp",    X86_MN_FADDP,       PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("faddp",    X86_MN_FADDP,       PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 08h */
    TABLE_ENTRY("fmulp",    X86_MN_FMULP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fmulp",    X86_MN_FMULP,       PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fmulp",    X86_MN_FMULP,       PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fmulp",    X86_MN_FMULP,       PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fmulp",    X86_MN_FMULP,       PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fmulp",    X86_MN_FMULP,       PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fmulp",    X86_MN_FMULP,       PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fmulp",    X86_MN_FMULP,       PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 10h */
    TABLE_ENTRY("fcomp5",   X86_MN_FCOMP5,      PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("fcomp5",   X86_MN_FCOMP5,      PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("fcomp5",   X86_MN_FCOMP5,      PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("fcomp5",   X86_MN_FCOMP5,      PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("fcomp5",   X86_MN_FCOMP5,      PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("fcomp5",   X86_MN_FCOMP5,      PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("fcomp5",   X86_MN_FCOMP5,      PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("fcomp5",   X86_MN_FCOMP5,      PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 18h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("fcompp",   X86_MN_FCOMPP,      PF_NONE,    X86_ISET_FPU,   OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY("fsubrp",   X86_MN_FSUBRP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fsubrp",   X86_MN_FSUBRP,      PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fsubrp",   X86_MN_FSUBRP,      PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fsubrp",   X86_MN_FSUBRP,      PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fsubrp",   X86_MN_FSUBRP,      PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fsubrp",   X86_MN_FSUBRP,      PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fsubrp",   X86_MN_FSUBRP,      PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fsubrp",   X86_MN_FSUBRP,      PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 28h */
    TABLE_ENTRY("fsubp",    X86_MN_FSUBP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fsubp",    X86_MN_FSUBP,       PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fsubp",    X86_MN_FSUBP,       PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fsubp",    X86_MN_FSUBP,       PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fsubp",    X86_MN_FSUBP,       PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fsubp",    X86_MN_FSUBP,       PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fsubp",    X86_MN_FSUBP,       PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fsubp",    X86_MN_FSUBP,       PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 30h */
    TABLE_ENTRY("fdivrp",   X86_MN_FDIVRP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fdivrp",   X86_MN_FDIVRP,      PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fdivrp",   X86_MN_FDIVRP,      PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fdivrp",   X86_MN_FDIVRP,      PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fdivrp",   X86_MN_FDIVRP,      PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fdivrp",   X86_MN_FDIVRP,      PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fdivrp",   X86_MN_FDIVRP,      PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fdivrp",   X86_MN_FDIVRP,      PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0)),

    /* 38h */
    TABLE_ENTRY("fdivp",    X86_MN_FDIVP,       PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fdivp",    X86_MN_FDIVP,       PF_NONE,    X86_ISET_FPU,   OP(ST1, ST0)),
    TABLE_ENTRY("fdivp",    X86_MN_FDIVP,       PF_NONE,    X86_ISET_FPU,   OP(ST2, ST0)),
    TABLE_ENTRY("fdivp",    X86_MN_FDIVP,       PF_NONE,    X86_ISET_FPU,   OP(ST3, ST0)),
    TABLE_ENTRY("fdivp",    X86_MN_FDIVP,       PF_NONE,    X86_ISET_FPU,   OP(ST4, ST0)),
    TABLE_ENTRY("fdivp",    X86_MN_FDIVP,       PF_NONE,    X86_ISET_FPU,   OP(ST5, ST0)),
    TABLE_ENTRY("fdivp",    X86_MN_FDIVP,       PF_NONE,    X86_ISET_FPU,   OP(ST6, ST0)),
    TABLE_ENTRY("fdivp",    X86_MN_FDIVP,       PF_NONE,    X86_ISET_FPU,   OP(ST7, ST0))

TABLE_END(DE_MOD_11)

TABLE_BEGIN(DF_MOD_N11)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("fild",     X86_MN_FILD,        PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("fisttp",   X86_MN_FISTTP,      PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("fist",     X86_MN_FIST,        PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("fistp",    X86_MN_FISTP,       PF_NONE,    X86_ISET_FPU,   OP(Mw)), /* word integer */
    TABLE_ENTRY("fbld",     X86_MN_FBLD,        PF_NONE,    X86_ISET_FPU,   OP(Mt)), /* 80-bit (packed-BCD) */
    TABLE_ENTRY("fild",     X86_MN_FILD,        PF_NONE,    X86_ISET_FPU,   OP(Mq)), /* qword integer */
    TABLE_ENTRY("fbstp",    X86_MN_FBSTP,       PF_NONE,    X86_ISET_FPU,   OP(Mt)), /* 80-bit (packed-BCD) */
    TABLE_ENTRY("fistp",    X86_MN_FISTP,       PF_NONE,    X86_ISET_FPU,   OP(Mq))  /* qword integer */

TABLE_END(DF_MOD_N11)

TABLE_BEGIN(DF_MOD_11)

    /* modr/m byte:  index = modr/m byte - C0h */
    TABLE_ENTRY("ffreep",   X86_MN_FFREEP,      PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("ffreep",   X86_MN_FFREEP,      PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("ffreep",   X86_MN_FFREEP,      PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("ffreep",   X86_MN_FFREEP,      PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("ffreep",   X86_MN_FFREEP,      PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("ffreep",   X86_MN_FFREEP,      PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("ffreep",   X86_MN_FFREEP,      PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("ffreep",   X86_MN_FFREEP,      PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 08h */
    TABLE_ENTRY("fxch7",    X86_MN_FXCH7,       PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("fxch7",    X86_MN_FXCH7,       PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("fxch7",    X86_MN_FXCH7,       PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("fxch7",    X86_MN_FXCH7,       PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("fxch7",    X86_MN_FXCH7,       PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("fxch7",    X86_MN_FXCH7,       PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("fxch7",    X86_MN_FXCH7,       PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("fxch7",    X86_MN_FXCH7,       PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 10h */
    TABLE_ENTRY("fstp8",    X86_MN_FSTP8,       PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("fstp8",    X86_MN_FSTP8,       PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("fstp8",    X86_MN_FSTP8,       PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("fstp8",    X86_MN_FSTP8,       PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("fstp8",    X86_MN_FSTP8,       PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("fstp8",    X86_MN_FSTP8,       PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("fstp8",    X86_MN_FSTP8,       PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("fstp8",    X86_MN_FSTP8,       PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 18h */
    TABLE_ENTRY("fstp9",    X86_MN_FSTP9,       PF_NONE,    X86_ISET_FPU,   OP(ST0)),
    TABLE_ENTRY("fstp9",    X86_MN_FSTP9,       PF_NONE,    X86_ISET_FPU,   OP(ST1)),
    TABLE_ENTRY("fstp9",    X86_MN_FSTP9,       PF_NONE,    X86_ISET_FPU,   OP(ST2)),
    TABLE_ENTRY("fstp9",    X86_MN_FSTP9,       PF_NONE,    X86_ISET_FPU,   OP(ST3)),
    TABLE_ENTRY("fstp9",    X86_MN_FSTP9,       PF_NONE,    X86_ISET_FPU,   OP(ST4)),
    TABLE_ENTRY("fstp9",    X86_MN_FSTP9,       PF_NONE,    X86_ISET_FPU,   OP(ST5)),
    TABLE_ENTRY("fstp9",    X86_MN_FSTP9,       PF_NONE,    X86_ISET_FPU,   OP(ST6)),
    TABLE_ENTRY("fstp9",    X86_MN_FSTP9,       PF_NONE,    X86_ISET_FPU,   OP(ST7)),

    /* 20h */
    TABLE_ENTRY("fnstsw",   X86_MN_FNSTSW,      PF_NONE,    X86_ISET_FPU,   OP(AX)),
    TABLE_ENTRY("fstdw",    X86_MN_FSTDW,       PF_NONE,    X86_ISET_FPU,   OP(AX)),
    TABLE_ENTRY("fstsg",    X86_MN_FSTSG,       PF_NONE,    X86_ISET_FPU,   OP(AX)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 28h */
    TABLE_ENTRY("fucomip",  X86_MN_FUCOMIP, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fucomip",  X86_MN_FUCOMIP, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fucomip",  X86_MN_FUCOMIP, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fucomip",  X86_MN_FUCOMIP, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fucomip",  X86_MN_FUCOMIP, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fucomip",  X86_MN_FUCOMIP, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fucomip",  X86_MN_FUCOMIP, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fucomip",  X86_MN_FUCOMIP, PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 30h */
    TABLE_ENTRY("fcomip",   X86_MN_FCOMIP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST0)),
    TABLE_ENTRY("fcomip",   X86_MN_FCOMIP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST1)),
    TABLE_ENTRY("fcomip",   X86_MN_FCOMIP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST2)),
    TABLE_ENTRY("fcomip",   X86_MN_FCOMIP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST3)),
    TABLE_ENTRY("fcomip",   X86_MN_FCOMIP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST4)),
    TABLE_ENTRY("fcomip",   X86_MN_FCOMIP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST5)),
    TABLE_ENTRY("fcomip",   X86_MN_FCOMIP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST6)),
    TABLE_ENTRY("fcomip",   X86_MN_FCOMIP,      PF_NONE,    X86_ISET_FPU,   OP(ST0, ST7)),

    /* 38h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(DF_MOD_11)

/****************************************************************************

    Two-byte tables - no mandatory prefix

****************************************************************************/

TABLE_BEGIN(0F)

    /* 00h: group 6, 7 */
    TABLE_ENTRY_ESCAPE(0F_00),
    TABLE_ENTRY_ESCAPE(0F_01),

    /* 02h */
    TABLE_ENTRY("lar",          X86_MN_LAR,     PF_PFXNA,   X86_ISET_GP,        OP(Gv, Ew)),
    TABLE_ENTRY("lsl",          X86_MN_LSL,     PF_PFXNA,   X86_ISET_GP,        OP(Gv, Ew)),

    /* 04h */
    TABLE_ENTRY_INVALID(),

    /* 05h */
    TABLE_ENTRY("syscall",      X86_MN_SYSCALL,     PF_O64 | PF_PFXNA,      X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("clts",         X86_MN_CLTS,        PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("sysret",       X86_MN_SYSRET,      PF_O64 | PF_PFXNA,      X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("invd",         X86_MN_INVD,        PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("wbinvd",       X86_MN_WBINVD,      PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),

    /* 0Ah */
    TABLE_ENTRY_INVALID(),

    /* 0Bh */
    TABLE_ENTRY("ud2",          X86_MN_UD2,     PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),

    /* 0Ch */
    TABLE_ENTRY_INVALID(),

    /* 0Dh: group p */
    TABLE_ENTRY_ESCAPE(0F_0D),

    /* 0Eh: AMD only */
    TABLE_ENTRY("femms",        X86_MN_FEMMS,   PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),

    /* 0Fh: AMD only, 3DNow! escape */
    TABLE_ENTRY_ESCAPE(0F_0F),
    
    /* 10h */
    TABLE_ENTRY("movups",       X86_MN_MOVUPS,      PF_VEX,     X86_ISET_SSE,       OP(Vps, Wps)),
    TABLE_ENTRY("movups",       X86_MN_MOVUPS,      PF_VEX,     X86_ISET_SSE,       OP(Wps, Vps)),

    /* 12h: movlps or movhlps */
    TABLE_ENTRY_ESCAPE(0F_12),

    /* 13h */
    TABLE_ENTRY("movlps",       X86_MN_MOVLPS,      PF_VEX128,  X86_ISET_SSE,       OP(Mq, Vq)),
    TABLE_ENTRY("unpcklps",     X86_MN_UNPCKLPS,    PF_VEX,     X86_ISET_SSE,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("unpckhps",     X86_MN_UNPCKHPS,    PF_VEX,     X86_ISET_SSE,       OP(Vx, Hx, Wx)),

    /* 16h: movhps or movlhps */
    TABLE_ENTRY_ESCAPE(0F_16),

    /* 17h */
    TABLE_ENTRY("movhps",       X86_MN_MOVHPS,      PF_VEX128,  X86_ISET_SSE,       OP(Mq, Vq)),

    /* 18h: group 16 */
    TABLE_ENTRY_ESCAPE(0F_18),

    /* 19h */
    TABLE_ENTRY_ESCAPE(F2_0F_19),

    TABLE_ENTRY("nop",          X86_MN_NOP,     PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ev)),
    TABLE_ENTRY("nop",          X86_MN_NOP,     PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ev)),
    
    TABLE_ENTRY_ESCAPE(0F_1C),
    TABLE_ENTRY_ESCAPE(0F_1D),
    TABLE_ENTRY_ESCAPE(0F_1E),
    TABLE_ENTRY_ESCAPE(0F_1F),

    /* 20h */
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Ry, Cy)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Ry, Dy)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Cy, Ry)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Dy, Ry)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("movaps",       X86_MN_MOVAPS,      PF_VEX,     X86_ISET_SSE,       OP(Vps, Wps)),
    TABLE_ENTRY("movaps",       X86_MN_MOVAPS,      PF_VEX,     X86_ISET_SSE,       OP(Wps, Vps)),
    TABLE_ENTRY("cvtpi2ps",     X86_MN_CVTPI2PS,    PF_NONE,    X86_ISET_SSE,       OP(Vps, Qpi)),
    TABLE_ENTRY("movntps",      X86_MN_MOVNTPS,     PF_VEX,     X86_ISET_SSE,       OP(Mps, Vps)),
    TABLE_ENTRY("cvttps2pi",    X86_MN_CVTTPS2PI,   PF_NONE,    X86_ISET_SSE,       OP(Ppi, Wps)),
    TABLE_ENTRY("cvtps2pi",     X86_MN_CVTPS2PI,    PF_NONE,    X86_ISET_SSE,       OP(Ppi, Wps)),
    TABLE_ENTRY("ucomiss",      X86_MN_UCOMISS,     PF_VEX128,  X86_ISET_SSE,       OP(Vss, Wss)),
    TABLE_ENTRY("comiss",       X86_MN_COMISS,      PF_VEX128,  X86_ISET_SSE,       OP(Vss, Wss)),

    /* 30h */
    TABLE_ENTRY("wrmsr",        X86_MN_WRMSR,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("rdtsc",        X86_MN_RDTSC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("rdmsr",        X86_MN_RDMSR,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("rdpmc",        X86_MN_RDPMC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("sysenter",     X86_MN_SYSENTER,    PF_I64 | PF_PFXNA,      X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("sysexit",      X86_MN_SYSEXIT,     PF_I64 | PF_PFXNA,      X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("getsec",       X86_MN_GETSEC,      PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),

    /* 38h: three-byte table escape */
    TABLE_ENTRY_ESCAPE(0F_38),
    TABLE_ENTRY_INVALID(),

    /* 3Ah: three-byte table escape */
    TABLE_ENTRY_ESCAPE(0F_3A),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY("cmovo",        X86_MN_CMOVO,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovno",       X86_MN_CMOVNO,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovc",        X86_MN_CMOVC,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnc",       X86_MN_CMOVNC,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovz",        X86_MN_CMOVZ,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnz",       X86_MN_CMOVNZ,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovna",       X86_MN_CMOVNA,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmova",        X86_MN_CMOVA,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovs",        X86_MN_CMOVS,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovns",       X86_MN_CMOVNS,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovp",        X86_MN_CMOVP,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnp",       X86_MN_CMOVNP,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovl",        X86_MN_CMOVL,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnl",       X86_MN_CMOVNL,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovng",       X86_MN_CMOVNG,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovg",        X86_MN_CMOVG,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),

    /* 50h */
    TABLE_ENTRY("movmskps",     X86_MN_MOVMSKPS,    PF_VEX,     X86_ISET_SSE,       OP(Gy, Ups)),
    TABLE_ENTRY("sqrtps",       X86_MN_SQRTPS,      PF_VEX,     X86_ISET_SSE,       OP(Vps, Wps)),
    TABLE_ENTRY("rsqrtps",      X86_MN_RSQRTPS,     PF_VEX,     X86_ISET_SSE,       OP(Vps, Wps)),
    TABLE_ENTRY("rcpps",        X86_MN_RCPPS,       PF_VEX,     X86_ISET_SSE,       OP(Vps, Wps)),
    TABLE_ENTRY("andps",        X86_MN_ANDPS,       PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps)),
    TABLE_ENTRY("andnps",       X86_MN_ANDNPS,      PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps)),
    TABLE_ENTRY("orps",         X86_MN_ORPS,        PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps)),
    TABLE_ENTRY("xorps",        X86_MN_XORPS,       PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps)),
    TABLE_ENTRY("addps",        X86_MN_ADDPS,       PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps)),
    TABLE_ENTRY("mulps",        X86_MN_MULPS,       PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps)),
    TABLE_ENTRY("cvtps2pd",     X86_MN_CVTPS2PD,    PF_VEX,     X86_ISET_SSE2,      OP(Vpd, Wps)),
    TABLE_ENTRY("cvtdq2ps",     X86_MN_CVTDQ2PS,    PF_VEX,     X86_ISET_SSE2,      OP(Vps, Wdq)),
    TABLE_ENTRY("subps",        X86_MN_SUBPS,       PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps)),
    TABLE_ENTRY("minps",        X86_MN_MINPS,       PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps)),
    TABLE_ENTRY("divps",        X86_MN_DIVPS,       PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps)),
    TABLE_ENTRY("maxps",        X86_MN_MAXPS,       PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps)),

    /* 60h */
    TABLE_ENTRY("punpcklbw",    X86_MN_PUNPCKLBW,   PF_NONE,    X86_ISET_MMX,       OP(Pq, Qd)),
    TABLE_ENTRY("punpcklwd",    X86_MN_PUNPCKLWD,   PF_NONE,    X86_ISET_MMX,       OP(Pq, Qd)),
    TABLE_ENTRY("punpckldq",    X86_MN_PUNPCKLDQ,   PF_NONE,    X86_ISET_MMX,       OP(Pq, Qd)),
    TABLE_ENTRY("packsswb",     X86_MN_PACKSSWB,    PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pcmpgtb",      X86_MN_PCMPGTB,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pcmpgtw",      X86_MN_PCMPGTW,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pcmpgtd",      X86_MN_PCMPGTD,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("packuswb",     X86_MN_PACKUSWB,    PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("punpckhbw",    X86_MN_PUNPCKHBW,   PF_NONE,    X86_ISET_MMX,       OP(Pq, Qd)),
    TABLE_ENTRY("punpckhwd",    X86_MN_PUNPCKHWD,   PF_NONE,    X86_ISET_MMX,       OP(Pq, Qd)),
    TABLE_ENTRY("punpckhdq",    X86_MN_PUNPCKHDQ,   PF_NONE,    X86_ISET_MMX,       OP(Pq, Qd)),
    TABLE_ENTRY("packssdw",     X86_MN_PACKSSDW,    PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),

    /* 6Ch */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 6Eh */
    TABLE_ENTRY_ESCAPE(0F_6E),
    TABLE_ENTRY("movq",         X86_MN_MOVQ,        PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),

    /* 70h */
    TABLE_ENTRY("pshufw",       X86_MN_PSHUFW,      PF_NONE,    X86_ISET_SSE,       OP(Pq, Qq, Ib)),

    /* 71h: group 12, 13, 14 */
    TABLE_ENTRY_ESCAPE(0F_71),
    TABLE_ENTRY_ESCAPE(0F_72),
    TABLE_ENTRY_ESCAPE(0F_73),

    /* 74h */
    TABLE_ENTRY("pcmpeqb",      X86_MN_PCMPEQB,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pcmpeqw",      X86_MN_PCMPEQW,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pcmpeqd",      X86_MN_PCMPEQD,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("emms",         X86_MN_EMMS,        PF_NONE,    X86_ISET_MMX,       OP(NONE)),
    TABLE_ENTRY("vmread",       X86_MN_VMREAD,      PF_NONE,    X86_ISET_VMX,       OP(Ey, Gy)),
    TABLE_ENTRY("vmwrite",      X86_MN_VMWRITE,     PF_NONE,    X86_ISET_VMX,       OP(Gy, Ey)),

    /* 7Ah */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 7Eh */
    TABLE_ENTRY_ESCAPE(0F_7E),
    TABLE_ENTRY("movq",         X86_MN_MOVQ,        PF_NONE,    X86_ISET_MMX,       OP(Qq, Pq)),

    /* 80h */
    TABLE_ENTRY("jo",           X86_MN_JO,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jno",          X86_MN_JNO,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jc",           X86_MN_JC,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnc",          X86_MN_JNC,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jz",           X86_MN_JZ,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnz",          X86_MN_JNZ,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jna",          X86_MN_JNA,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("ja",           X86_MN_JA,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("js",           X86_MN_JS,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jns",          X86_MN_JNS,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jp",           X86_MN_JP,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnp",          X86_MN_JNP,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jl",           X86_MN_JL,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnl",          X86_MN_JNL,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jng",          X86_MN_JNG,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jg",           X86_MN_JG,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),

    /* 90h */
    TABLE_ENTRY("seto",         X86_MN_SETO,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setno",        X86_MN_SETNO,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setc",         X86_MN_SETC,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnc",        X86_MN_SETNC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setz",         X86_MN_SETZ,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnz",        X86_MN_SETNZ,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setna",        X86_MN_SETNA,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("seta",         X86_MN_SETA,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("sets",         X86_MN_SETS,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setns",        X86_MN_SETNS,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setp",         X86_MN_SETP,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnp",        X86_MN_SETNP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setl",         X86_MN_SETL,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnl",        X86_MN_SETNL,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setng",        X86_MN_SETNG,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setg",         X86_MN_SETG,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),

    /* A0h */
    TABLE_ENTRY("push",         X86_MN_PUSH,        PF_D64 | PF_PFXNA,      X86_ISET_GP,        OP(FS)),
    TABLE_ENTRY("pop",          X86_MN_POP,         PF_D64 | PF_PFXNA,      X86_ISET_GP,        OP(FS)),
    TABLE_ENTRY("cpuid",        X86_MN_CPUID,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("bt",           X86_MN_BT,          PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv)),
    TABLE_ENTRY("shld",         X86_MN_SHLD,        PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv, Ib)),
    TABLE_ENTRY("shld",         X86_MN_SHLD,        PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv, CL)), 

    /* A6h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A8h */
    TABLE_ENTRY("push",         X86_MN_PUSH,        PF_D64 | PF_PFXNA,      X86_ISET_GP,        OP(GS)),
    TABLE_ENTRY("pop",          X86_MN_POP,         PF_D64 | PF_PFXNA,      X86_ISET_GP,        OP(GS)),
    TABLE_ENTRY("rsm",          X86_MN_RSM,         PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("bts",          X86_MN_BTS,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv)),
    TABLE_ENTRY("shrd",         X86_MN_SHRD,        PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv, Ib)),
    TABLE_ENTRY("shrd",         X86_MN_SHRD,        PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv, CL)),

    /* AEh: group 15 */
    TABLE_ENTRY_ESCAPE(0F_AE),

    /* AFh */
    TABLE_ENTRY("imul",         X86_MN_IMUL,        PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Gv, Ev)),

    /* B0h */
    TABLE_ENTRY("cmpxchg",      X86_MN_CMPXCHG,     PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Eb, Gb)),
    TABLE_ENTRY("cmpxchg",      X86_MN_CMPXCHG,     PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv)),
    TABLE_ENTRY("lss",          X86_MN_LSS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Gv, Mp)),
    TABLE_ENTRY("btr",          X86_MN_BTR,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv)),
    TABLE_ENTRY("lfs",          X86_MN_LFS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Gv, Mp)),
    TABLE_ENTRY("lgs",          X86_MN_LGS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Gv, Mp)),
    TABLE_ENTRY("movzx",        X86_MN_MOVZX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Gv, Eb)),
    TABLE_ENTRY("movzx",        X86_MN_MOVZX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Gv, Ew)),

    /* B8h */
    TABLE_ENTRY_INVALID(),

    /* B9h: group 10, 8 */
    TABLE_ENTRY_ESCAPE(0F_B9),
    TABLE_ENTRY_ESCAPE(0F_BA),

    /* BBh */
    TABLE_ENTRY("btc",          X86_MN_BTC,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv)),
    TABLE_ENTRY("bsf",          X86_MN_BSF,         PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("bsr",          X86_MN_BSR,         PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("movsx",        X86_MN_MOVSX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Gv, Eb)),
    TABLE_ENTRY("movsx",        X86_MN_MOVSX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(Gv, Ew)),

    /* C0h */
    TABLE_ENTRY("xadd",         X86_MN_XADD,        PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Eb, Gb)),
    TABLE_ENTRY("xadd",         X86_MN_XADD,        PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv)),
    TABLE_ENTRY("cmp*ps",       X86_MN_CMPPS,       PF_VEX | PF_CC,         X86_ISET_SSE,       OP(Vps, Hps, Wps, Ib)),
    TABLE_ENTRY("movnti",       X86_MN_MOVNTI,      PF_NONE,                X86_ISET_SSE2,      OP(My, Gy)),
    
    /* C4h */
    TABLE_ENTRY_ESCAPE(0F_C4),

    TABLE_ENTRY("pextrw",       X86_MN_PEXTRW,      PF_NONE,    X86_ISET_SSE,       OP(Gw, Nq, Ib)),
    TABLE_ENTRY("shufps",       X86_MN_SHUFPS,      PF_VEX,     X86_ISET_SSE,       OP(Vps, Hps, Wps, Ib)),

    /* C7h: group 9 */
    TABLE_ENTRY_ESCAPE(0F_C7),

    /* C8h */
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(rAX_r8)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(rCX_r9)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(rDX_r10)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(rBX_r11)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(rSP_r12)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(rBP_r13)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(rSI_r14)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(rDI_r15)),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psrlw",        X86_MN_PSRLW,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psrld",        X86_MN_PSRLD,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psrlq",        X86_MN_PSRLQ,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("paddq",        X86_MN_PADDQ,       PF_NONE,    X86_ISET_SSE2,      OP(Pq, Qq)),
    TABLE_ENTRY("pmullw",       X86_MN_PMULLW,      PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pmovmskb",     X86_MN_PMOVMSKB,    PF_NONE,    X86_ISET_SSE,       OP(Gd, Nq)),
    TABLE_ENTRY("psubusb",      X86_MN_PSUBUSB,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psubusw",      X86_MN_PSUBUSW,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pminub",       X86_MN_PMINUB,      PF_NONE,    X86_ISET_SSE,       OP(Pq, Qq)),
    TABLE_ENTRY("pand",         X86_MN_PAND,        PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("paddusb",      X86_MN_PADDUSB,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("paddusw",      X86_MN_PADDUSW,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pmaxub",       X86_MN_PMAXUB,      PF_NONE,    X86_ISET_SSE,       OP(Pq, Qq)),
    TABLE_ENTRY("pandn",        X86_MN_PANDN,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),

    /* E0h */
    TABLE_ENTRY("pavgb",        X86_MN_PAVGB,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psraw",        X86_MN_PSRAW,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psrad",        X86_MN_PSRAD,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pavgw",        X86_MN_PAVGW,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pmulhuw",      X86_MN_PMULHUW,     PF_NONE,    X86_ISET_SSE,       OP(Pq, Qq)),
    TABLE_ENTRY("pmulhw",       X86_MN_PMULHW,      PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("movntq",       X86_MN_MOVNTQ,      PF_NONE,    X86_ISET_SSE,       OP(Mq, Pq)),
    TABLE_ENTRY("psubsb",       X86_MN_PSUBSB,      PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psubsw",       X86_MN_PSUBSW,      PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pminsw",       X86_MN_PMINSW,      PF_NONE,    X86_ISET_SSE,       OP(Pq, Qq)),
    TABLE_ENTRY("por",          X86_MN_POR,         PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("paddsb",       X86_MN_PADDSB,      PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("paddsw",       X86_MN_PADDSW,      PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pmaxsw",       X86_MN_PMAXSW,      PF_NONE,    X86_ISET_SSE,       OP(Pq, Qq)),
    TABLE_ENTRY("pxor",         X86_MN_PXOR,        PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),

    /* F0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psllw",        X86_MN_PSLLW,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pslld",        X86_MN_PSLLD,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psllq",        X86_MN_PSLLQ,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("pmuludq",      X86_MN_PMULUDQ,     PF_NONE,    X86_ISET_SSE2,      OP(Pq, Qq)),
    TABLE_ENTRY("pmaddwd",      X86_MN_PMADDWD,     PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psadbw",       X86_MN_PSADBW,      PF_NONE,    X86_ISET_SSE,       OP(Pq, Qq)),
    TABLE_ENTRY("maskmovq",     X86_MN_MASKMOVQ,    PF_NONE,    X86_ISET_SSE,       OP(Pq, Qq)),
    TABLE_ENTRY("psubb",        X86_MN_PSUBB,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psubw",        X86_MN_PSUBW,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psubd",        X86_MN_PSUBD,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("psubq",        X86_MN_PSUBQ,       PF_NONE,    X86_ISET_SSE2,      OP(Pq, Qq)),
    TABLE_ENTRY("paddb",        X86_MN_PADDB,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("paddw",        X86_MN_PADDW,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("paddd",        X86_MN_PADDD,       PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq)),
    TABLE_ENTRY("ud0",          X86_MN_UD,          PF_NONE,    X86_ISET_MMX,       OP(Pq, Qq))

TABLE_END(0F)

TABLE_BEGIN(0F_00)

    /* modr/m byte reg/nnn field */

    /* 00h: sldt Mw/Rv */
    TABLE_ENTRY_ESCAPE(0F_00_REG0),

    /* 01h: str Mw/Rv */
    TABLE_ENTRY_ESCAPE(0F_00_REG1),

    /* 02h */
    TABLE_ENTRY("lldt",         X86_MN_LLDT,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ew)),
    TABLE_ENTRY("ltr",          X86_MN_LTR,         PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ew)),
    TABLE_ENTRY("verr",         X86_MN_VERR,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ew)),
    TABLE_ENTRY("verw",         X86_MN_VERW,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ew)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_00)

TABLE_BEGIN(0F_00_REG0)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("sldt",         X86_MN_SLDT,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Mw)),
    TABLE_ENTRY("sldt",         X86_MN_SLDT,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Rv))

TABLE_END(0F_00_REG0)

TABLE_BEGIN(0F_00_REG1)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("str",          X86_MN_STR,     PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Mw)),
    TABLE_ENTRY("str",          X86_MN_STR,     PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Rv))

TABLE_END(0F_00_REG1)

TABLE_BEGIN(0F_01)

    /* modr/m byte reg/nnn field */

    /* 00h: sgdt or r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG0),

    /* 01h: sidt or r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG1),

    /* 02h: lgdt or r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG2),

    /* 03h: lidt or r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG3),

    /* 04h: smsw Mw/Rv */
    TABLE_ENTRY_ESCAPE(0F_01_REG4),

    /* 05h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("lmsw",         X86_MN_LMSW,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ew)),

    /* 07h: invlpg or r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG7)

TABLE_END(0F_01)

TABLE_BEGIN(0F_01_REG0)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("sgdt",         X86_MN_SGDT,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ms)),

    /* 01h: r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG0_RM)

TABLE_END(0F_01_REG0)

TABLE_BEGIN(0F_01_REG1)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("sidt",         X86_MN_SIDT,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ms)),

    /* 01h: r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG1_RM)

TABLE_END(0F_01_REG1)

TABLE_BEGIN(0F_01_REG2)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("lgdt",         X86_MN_LGDT,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ms)),

    /* 01h: r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG2_RM)

TABLE_END(0F_01_REG2)

TABLE_BEGIN(0F_01_REG3)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("lidt",         X86_MN_LIDT,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ms)),

    /* 01h: r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG3_RM)

TABLE_END(0F_01_REG3)

TABLE_BEGIN(0F_01_REG4)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("smsw",         X86_MN_SMSW,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Mw)),
    TABLE_ENTRY("smsw",         X86_MN_SMSW,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Rv))

TABLE_END(0F_01_REG4)

TABLE_BEGIN(0F_01_REG7)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("invlpg",       X86_MN_INVLPG,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Mb)),
    
    /* 01h: r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG7_RM)

TABLE_END(0F_01_REG7)

TABLE_BEGIN(0F_01_REG0_RM)

    /* modr/m byte r/m field */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vmcall",       X86_MN_VMCALL,      PF_NONE | PF_PFXNA, X86_ISET_VMX,       OP(NONE)),
    TABLE_ENTRY("vmlaunch",     X86_MN_VMLAUNCH,    PF_NONE | PF_PFXNA, X86_ISET_VMX,       OP(NONE)),
    TABLE_ENTRY("vmresume",     X86_MN_VMRESUME,    PF_NONE | PF_PFXNA, X86_ISET_VMX,       OP(NONE)),
    TABLE_ENTRY("vmxoff",       X86_MN_VMXOFF,      PF_NONE | PF_PFXNA, X86_ISET_VMX,       OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_01_REG0_RM)

TABLE_BEGIN(0F_01_REG1_RM)

    /* modr/m byte r/m field */
    TABLE_ENTRY("monitor",      X86_MN_MONITOR,     PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("mwait",        X86_MN_MWAIT,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("clac",         X86_MN_CLAC,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("stac",         X86_MN_STAC,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_01_REG1_RM)

TABLE_BEGIN(0F_01_REG2_RM)

    /* modr/m byte r/m field */
    TABLE_ENTRY("xgetbv",       X86_MN_XGETBV,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("xsetbv",       X86_MN_XSETBV,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vmfunc",       X86_MN_VMFUNC,      PF_NONE | PF_PFXNA, X86_ISET_VMX,       OP(NONE)),
    TABLE_ENTRY("xend",         X86_MN_XEND,        PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("xtest",        X86_MN_XTEST,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_01_REG2_RM)

TABLE_BEGIN(0F_01_REG3_RM)

    /* modr/m byte r/m field */
    TABLE_ENTRY("vmrun",        X86_MN_VMRUN,       PF_NONE | PF_PFXNA, X86_ISET_SVM,       OP(NONE)),
    TABLE_ENTRY("vmcall",       X86_MN_VMCALL,      PF_NONE | PF_PFXNA, X86_ISET_SVM,       OP(NONE)),
    TABLE_ENTRY("vmload",       X86_MN_VMLOAD,      PF_NONE | PF_PFXNA, X86_ISET_SVM,       OP(NONE)),
    TABLE_ENTRY("vmsave",       X86_MN_VMSAVE,      PF_NONE | PF_PFXNA, X86_ISET_SVM,       OP(NONE)),
    TABLE_ENTRY("stgi",         X86_MN_STGI,        PF_NONE | PF_PFXNA, X86_ISET_SVM,       OP(NONE)),
    TABLE_ENTRY("clgi",         X86_MN_CLGI,        PF_NONE | PF_PFXNA, X86_ISET_SVM,       OP(NONE)),
    TABLE_ENTRY("skinit",       X86_MN_SKINIT,      PF_NONE | PF_PFXNA, X86_ISET_SVM,       OP(NONE)),
    TABLE_ENTRY("invlpga",      X86_MN_INVLPGA,     PF_NONE | PF_PFXNA, X86_ISET_SVM,       OP(NONE))

TABLE_END(0F_01_REG3_RM)

TABLE_BEGIN(0F_01_REG7_RM)

    /* modr/m byte r/m field */
    TABLE_ENTRY("swapgs",       X86_MN_SWAPGS,      PF_O64 | PF_PFXNA,      X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY("rdtscp",       X86_MN_RDTSCP,      PF_NONE | PF_PFXNA,     X86_ISET_GP,        OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_01_REG7_RM)

TABLE_BEGIN(0F_0D)
    
    /* modr/m byte reg/nnn field */

    /* p group on amd docs, prefetchw Ev on intel docs; should check better */
    TABLE_ENTRY("prefetch",     X86_MN_PREFETCH,    PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(M)),
    TABLE_ENTRY("prefetchw",    X86_MN_PREFETCHW,   PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ev)),
    TABLE_ENTRY("prefetchwt1",  X86_MN_PREFETCHWT1, PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(M)),
    TABLE_ENTRY("prefetch",     X86_MN_PREFETCH,    PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(M)),
    TABLE_ENTRY("prefetch",     X86_MN_PREFETCH,    PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(M)),
    TABLE_ENTRY("prefetch",     X86_MN_PREFETCH,    PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(M)),
    TABLE_ENTRY("prefetch",     X86_MN_PREFETCH,    PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(M)),
    TABLE_ENTRY("prefetch",     X86_MN_PREFETCH,    PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(M))

TABLE_END(0F_0D)

TABLE_BEGIN(0F_12)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("movlps",       X86_MN_MOVLPS,      PF_VEX128,  X86_ISET_SSE,       OP(Vq, Hq, Mq)),
    TABLE_ENTRY("movhlps",      X86_MN_MOVHLPS,     PF_VEX128,  X86_ISET_SSE,       OP(Vq, Hq, Uq))

TABLE_END(0F_12)

TABLE_BEGIN(0F_16)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("movhps",       X86_MN_MOVHPS,      PF_VEX128,  X86_ISET_SSE,       OP(Vdq, Hq, Mq)),
    TABLE_ENTRY("movlhps",      X86_MN_MOVLHPS,     PF_VEX128,  X86_ISET_SSE,       OP(Vdq, Hq, Uq))

TABLE_END(0F_16)

TABLE_BEGIN(0F_18)

    /* modr/m byte reg/nnn field */

    /* 00h: prefetch NTA or invalid*/
    TABLE_ENTRY_ESCAPE(0F_18_REG0),

    /* 01h: prefetch T0 or invalid*/
    TABLE_ENTRY_ESCAPE(0F_18_REG1),

    /* 02h: prefetch T1 or invalid*/
    TABLE_ENTRY_ESCAPE(0F_18_REG2),

    /* 03h: prefetch T2 or invalid*/
    TABLE_ENTRY_ESCAPE(0F_18_REG3),

    TABLE_ENTRY("nop",      X86_MN_NOP,     PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Eb)),
    TABLE_ENTRY("nop",      X86_MN_NOP,     PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Eb)),
    TABLE_ENTRY("nop",      X86_MN_NOP,     PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Eb)),
    TABLE_ENTRY("nop",      X86_MN_NOP,     PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Eb))

TABLE_END(0F_18)

TABLE_BEGIN(0F_18_REG0)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("prefetchnta",  X86_MN_PREFETCHNTA,     PF_NONE | PF_PFXNA, X86_ISET_SSE,   OP(Mb)),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_18_REG0)

TABLE_BEGIN(0F_18_REG1)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("prefetcht0",   X86_MN_PREFETCHT0,      PF_NONE | PF_PFXNA, X86_ISET_SSE,   OP(Mb)),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_18_REG1)

TABLE_BEGIN(0F_18_REG2)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("prefetcht1",   X86_MN_PREFETCHT1,      PF_NONE | PF_PFXNA, X86_ISET_SSE,   OP(Mb)),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_18_REG2)

TABLE_BEGIN(0F_18_REG3)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("prefetcht2",   X86_MN_PREFETCHT2,      PF_NONE | PF_PFXNA, X86_ISET_SSE,   OP(Mb)),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_18_REG3)

TABLE_BEGIN(0F_19)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(0F_19)

TABLE_BEGIN(0F_1C)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(0F_1C)

TABLE_BEGIN(0F_1D)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(0F_1D)

TABLE_BEGIN(0F_1E)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(0F_1E)

TABLE_BEGIN(0F_1F)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(0F_1F)

TABLE_BEGIN(0F_6E)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("movd",         X86_MN_MOVD,            PF_NONE,    X86_ISET_MMX,   OP(Py, Ey)),
    TABLE_ENTRY("movd",         X86_MN_MOVD,            PF_NONE,    X86_ISET_MMX,   OP(Py, Ey)),
    TABLE_ENTRY("movq",         X86_MN_MOVQ,            PF_NONE,    X86_ISET_MMX,   OP(Py, Ey))

TABLE_END(0F_6E)

TABLE_BEGIN(0F_71)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 02h: psrlw or invalid*/
    TABLE_ENTRY_ESCAPE(0F_71_REG2),
    
    TABLE_ENTRY_INVALID(),
    
    /* 04h: psraw or invalid*/
    TABLE_ENTRY_ESCAPE(0F_71_REG4),

    TABLE_ENTRY_INVALID(),
    
    /* 06h: psllw or invalid*/
    TABLE_ENTRY_ESCAPE(0F_71_REG6),

    TABLE_ENTRY_INVALID()

TABLE_END(0F_71)

TABLE_BEGIN(0F_71_REG2)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psrlw",        X86_MN_PSRLW,       PF_NONE,        X86_ISET_MMX,   OP(Nq, Ib))

TABLE_END(0F_71_REG2)

TABLE_BEGIN(0F_71_REG4)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psraw",        X86_MN_PSRAW,       PF_NONE,        X86_ISET_MMX,   OP(Nq, Ib))

TABLE_END(0F_71_REG4)

TABLE_BEGIN(0F_71_REG6)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psllw",        X86_MN_PSLLW,       PF_NONE,        X86_ISET_MMX,   OP(Nq, Ib))

TABLE_END(0F_71_REG6)

TABLE_BEGIN(0F_72)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 02h: psrld or invalid*/
    TABLE_ENTRY_ESCAPE(0F_72_REG2),

    TABLE_ENTRY_INVALID(),

    /* 04h: psrad or invalid*/
    TABLE_ENTRY_ESCAPE(0F_72_REG4),
    
    TABLE_ENTRY_INVALID(),

    /* 06h: pslld or invalid*/
    TABLE_ENTRY_ESCAPE(0F_72_REG6),
    
    TABLE_ENTRY_INVALID()

TABLE_END(0F_72)

TABLE_BEGIN(0F_72_REG2)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psrld",        X86_MN_PSRLD,       PF_NONE,        X86_ISET_MMX,   OP(Nq, Ib))

TABLE_END(0F_72_REG2)

TABLE_BEGIN(0F_72_REG4)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psrad",        X86_MN_PSRAD,       PF_NONE,        X86_ISET_MMX,   OP(Nq, Ib))

TABLE_END(0F_72_REG4)

TABLE_BEGIN(0F_72_REG6)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pslld",        X86_MN_PSLLD,       PF_NONE,        X86_ISET_MMX,   OP(Nq, Ib))

TABLE_END(0F_72_REG6)

TABLE_BEGIN(0F_73)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 02h: psrlq or invalid*/
    TABLE_ENTRY_ESCAPE(0F_73_REG2),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 06h: psllq or invalid*/
    TABLE_ENTRY_ESCAPE(0F_73_REG6),
    
    TABLE_ENTRY_INVALID()

TABLE_END(0F_73)

TABLE_BEGIN(0F_73_REG2)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psrlq",        X86_MN_PSRLQ,       PF_NONE,        X86_ISET_MMX,   OP(Nq, Ib))

TABLE_END(0F_73_REG2)

TABLE_BEGIN(0F_73_REG6)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psllq",        X86_MN_PSLLQ,       PF_NONE,        X86_ISET_MMX,   OP(Nq, Ib))

TABLE_END(0F_73_REG6)

TABLE_BEGIN(0F_7E)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("movd",         X86_MN_MOVD,        PF_NONE,        X86_ISET_MMX,   OP(Ey, Py)),
    TABLE_ENTRY("movd",         X86_MN_MOVD,        PF_NONE,        X86_ISET_MMX,   OP(Ey, Py)),
    TABLE_ENTRY("movq",         X86_MN_MOVQ,        PF_NONE,        X86_ISET_MMX,   OP(Ey, Py))

TABLE_END(0F_7E)

TABLE_BEGIN(0F_AE)

    /* modr/m byte reg/nnn field */

    /* 00h: fxsave or invalid*/
    TABLE_ENTRY_ESCAPE(0F_AE_REG0),

    /* 01h: fxrstor or invalid*/
    TABLE_ENTRY_ESCAPE(0F_AE_REG1),

    /* 02h: ldmxcsr or invalid*/
    TABLE_ENTRY_ESCAPE(0F_AE_REG2),

    /* 03h: stmxcsr or invalid*/
    TABLE_ENTRY_ESCAPE(0F_AE_REG3),

    /* 04h: xsave or invalid*/
    TABLE_ENTRY_ESCAPE(0F_AE_REG4),

    /* 05h: xrstor or lfence*/
    TABLE_ENTRY_ESCAPE(0F_AE_REG5),

    /* 06h: xsaveopt or mfence*/
    TABLE_ENTRY_ESCAPE(0F_AE_REG6),

    /* 07h: clflush or sfence*/
    TABLE_ENTRY_ESCAPE(0F_AE_REG7)

TABLE_END(0F_AE)

TABLE_BEGIN(0F_AE_REG0)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("fxsave",       X86_MN_FXSAVE,      PF_NONE,        X86_ISET_FPU,   OP(M)), /* 512-byte (+fxsave64 with rex.w) */
    TABLE_ENTRY_INVALID()

TABLE_END(0F_AE_REG0)

TABLE_BEGIN(0F_AE_REG1)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("fxrstor",      X86_MN_FXRSTOR,     PF_NONE,        X86_ISET_FPU,   OP(M)), /* 512-byte (+fxrstor64 with rex.w) */
    TABLE_ENTRY_INVALID()

TABLE_END(0F_AE_REG1)

TABLE_BEGIN(0F_AE_REG2)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("ldmxcsr",      X86_MN_LDMXCSR,     PF_VEX,         X86_ISET_SSE,   OP(Md)),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_AE_REG2)

TABLE_BEGIN(0F_AE_REG3)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("stmxcsr",      X86_MN_STMXCSR,     PF_VEX,         X86_ISET_SSE,   OP(Md)),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_AE_REG3)

TABLE_BEGIN(0F_AE_REG4)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("xsave",        X86_MN_XSAVE,       PF_NONE,        X86_ISET_SSE,   OP(M)), /* mem (+xsave64 with rex.w) */
    TABLE_ENTRY_INVALID()

TABLE_END(0F_AE_REG4)

TABLE_BEGIN(0F_AE_REG5)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("xrstor",       X86_MN_XRSTOR,      PF_NONE,        X86_ISET_SSE,   OP(M)), /* mem (+xrstor64 with rex.w) */
    TABLE_ENTRY("lfence",       X86_MN_LFENCE,      PF_NONE,        X86_ISET_GP,    OP(NONE))

TABLE_END(0F_AE_REG5)

TABLE_BEGIN(0F_AE_REG6)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("xsaveopt",     X86_MN_XSAVEOPT,    PF_NONE,        X86_ISET_SSE,   OP(M)), /* mem (+xsaveopt64 with rex.w) */
    TABLE_ENTRY("mfence",       X86_MN_MFENCE,      PF_NONE,        X86_ISET_GP,    OP(NONE))

TABLE_END(0F_AE_REG6)

TABLE_BEGIN(0F_AE_REG7)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("clflush",      X86_MN_CLFLUSH,     PF_NONE,        X86_ISET_SSE2,  OP(Mb)), /* 8-bit */
    TABLE_ENTRY("sfence",       X86_MN_SFENCE,      PF_NONE,        X86_ISET_SSE,   OP(NONE))

TABLE_END(0F_AE_REG7)

TABLE_BEGIN(0F_B9)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY("ud1",          X86_MN_UD1,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("ud1",          X86_MN_UD1,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("ud1",          X86_MN_UD1,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("ud1",          X86_MN_UD1,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("ud1",          X86_MN_UD1,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("ud1",          X86_MN_UD1,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("ud1",          X86_MN_UD1,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("ud1",          X86_MN_UD1,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE))

TABLE_END(0F_B9)

TABLE_BEGIN(0F_BA)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("bt",           X86_MN_BT,          PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("bts",          X86_MN_BTS,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("btr",          X86_MN_BTR,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Ib)),
    TABLE_ENTRY("btc",          X86_MN_BTC,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Ib))

TABLE_END(0F_BA)

TABLE_BEGIN(0F_C4)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pinsrw",       X86_MN_PINSRW,      PF_NONE,        X86_ISET_SSE,   OP(Pq, Mw, Ib)),
    TABLE_ENTRY("pinsrw",       X86_MN_PINSRW,      PF_NONE,        X86_ISET_SSE,   OP(Pq, Ry, Ib))

TABLE_END(0F_C4)

TABLE_BEGIN(0F_C7)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),

    /* cmpxchg8b or 16b depending on operand size */
    TABLE_ENTRY_ESCAPE(0F_C7_REG1),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(0F_C7_REG3),
    TABLE_ENTRY_ESCAPE(0F_C7_REG4),
    TABLE_ENTRY_ESCAPE(0F_C7_REG5),
    
    /* vmptrld or rdrand */
    TABLE_ENTRY_ESCAPE(0F_C7_REG6),

    /* vmptrst or rdseed */
    TABLE_ENTRY_ESCAPE(0F_C7_REG7)

TABLE_END(0F_C7)

TABLE_BEGIN(0F_C7_REG1)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("cmpxchg8b",    X86_MN_CMPXCHG8B,       PF_LOCK,    X86_ISET_GP,    OP(Mq)),
    TABLE_ENTRY("cmpxchg8b",    X86_MN_CMPXCHG8B,       PF_LOCK,    X86_ISET_GP,    OP(Mq)),
    TABLE_ENTRY("cmpxchg16b",   X86_MN_CMPXCHG16B,      PF_LOCK,    X86_ISET_GP,    OP(Mdq))

TABLE_END(0F_C7_REG1)

TABLE_BEGIN(0F_C7_REG3)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("xrstors",      X86_MN_XRSTORS,     PF_NONE,    X86_ISET_UNKNOWN,   OP(M)), 
    TABLE_ENTRY("xrstors",      X86_MN_XRSTORS,     PF_NONE,    X86_ISET_UNKNOWN,   OP(M)), 
    TABLE_ENTRY("xrstors64",    X86_MN_XRSTORS64,   PF_NONE,    X86_ISET_UNKNOWN,   OP(M))

TABLE_END(0F_C7_REG3)

TABLE_BEGIN(0F_C7_REG4)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("xsavec",       X86_MN_XSAVEC,      PF_NONE,    X86_ISET_UNKNOWN,   OP(M)), 
    TABLE_ENTRY("xsavec",       X86_MN_XSAVEC,      PF_NONE,    X86_ISET_UNKNOWN,   OP(M)), 
    TABLE_ENTRY("xsavec64",     X86_MN_XSAVEC64,    PF_NONE,    X86_ISET_UNKNOWN,   OP(M))

TABLE_END(0F_C7_REG4)

TABLE_BEGIN(0F_C7_REG5)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("xsaves",       X86_MN_XSAVES,      PF_NONE,    X86_ISET_UNKNOWN,   OP(M)), 
    TABLE_ENTRY("xsaves",       X86_MN_XSAVES,      PF_NONE,    X86_ISET_UNKNOWN,   OP(M)), 
    TABLE_ENTRY("xsaves64",     X86_MN_XSAVES64,    PF_NONE,    X86_ISET_UNKNOWN,   OP(M))

TABLE_END(0F_C7_REG5)

TABLE_BEGIN(0F_C7_REG6)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("vmptrld",      X86_MN_VMPTRLD,         PF_NONE | PF_PFXNA, X86_ISET_VMX,   OP(Mq)),
    TABLE_ENTRY("rdrand",       X86_MN_RDRAND,          PF_NONE | PF_PFXNA, X86_ISET_GP,    OP(Rv))

TABLE_END(0F_C7_REG6)

TABLE_BEGIN(0F_C7_REG7)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("vmptrst",      X86_MN_VMPTRST,         PF_NONE | PF_PFXNA, X86_ISET_VMX,   OP(Mq)),
    TABLE_ENTRY("rdseed",       X86_MN_RDSEED,          PF_NONE | PF_PFXNA, X86_ISET_GP,    OP(Rv))

TABLE_END(0F_C7_REG7)

/****************************************************************************

    Two-byte tables - 66h mandatory prefix

****************************************************************************/

TABLE_BEGIN(66_0F)

    /* 00h: group 6, 7; both groups have prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_00),
    TABLE_ENTRY_ESCAPE(0F_01),

    /* 02h */
    TABLE_ENTRY("lar",          X86_MN_LAR,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),
    TABLE_ENTRY("lsl",          X86_MN_LSL,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),

    /* 04h */
    TABLE_ENTRY_INVALID(),

    /* 05h */
    TABLE_ENTRY("syscall",      X86_MN_SYSCALL,     PF_O64 | PF_PFXNA,      X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("clts",         X86_MN_CLTS,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sysret",       X86_MN_SYSRET,      PF_O64 | PF_PFXNA,      X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("invd",         X86_MN_INVD,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("wbinvd",       X86_MN_WBINVD,      PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),

    /* 0Ah */
    TABLE_ENTRY_INVALID(),

    /* 0Bh */
    TABLE_ENTRY("ud2",          X86_MN_UD2,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),

    /* 0Ch */
    TABLE_ENTRY_INVALID(),

    /* 0Dh: group p; group has prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_0D),

    /* 0Eh */
    TABLE_ENTRY("femms",        X86_MN_FEMMS,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),

    /* 0Fh: AMD only, 3DNow! escape */
    TABLE_ENTRY_INVALID(),
    
    /* 10h */
    TABLE_ENTRY("movupd",       X86_MN_MOVUPD,      PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Wpd)),
    TABLE_ENTRY("movupd",       X86_MN_MOVUPD,      PF_VEX,         X86_ISET_SSE2,  OP(Wpd, Vpd)),

    /* 12h */
    TABLE_ENTRY("movlpd",       X86_MN_MOVLPD,      PF_VEX128,      X86_ISET_SSE2,  OP(Vq, Hq, Mq)),
    TABLE_ENTRY("movlpd",       X86_MN_MOVLPD,      PF_VEX128,      X86_ISET_SSE2,  OP(Mq, Vq)),
    TABLE_ENTRY("unpcklpd",     X86_MN_UNPCKLPD,    PF_VEX,         X86_ISET_SSE2,  OP(Vx, Hx, Wx)),
    TABLE_ENTRY("unpckhpd",     X86_MN_UNPCKHPD,    PF_VEX,         X86_ISET_SSE2,  OP(Vx, Hx, Wx)),
    TABLE_ENTRY("movhpd",       X86_MN_MOVHPD,      PF_VEX128,      X86_ISET_SSE2,  OP(Vdq, Hq, Mq)),
    TABLE_ENTRY("movhpd",       X86_MN_MOVHPD,      PF_VEX128,      X86_ISET_SSE2,  OP(Mq, Vq)),

    /* 18h: group 16; group has prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_18),

    /* 19h */
    TABLE_ENTRY_ESCAPE(66_0F_19),

    TABLE_ENTRY("nop",          X86_MN_NOP,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("nop",          X86_MN_NOP,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Ev)),

    TABLE_ENTRY_ESCAPE(66_0F_1C),
    TABLE_ENTRY_ESCAPE(66_0F_1D),
    TABLE_ENTRY_ESCAPE(66_0F_1E),
    TABLE_ENTRY_ESCAPE(66_0F_1F),

    /* 20h */
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,          X86_ISET_GP,    OP(Ry, Cy)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,          X86_ISET_GP,    OP(Ry, Dy)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,          X86_ISET_GP,    OP(Cy, Ry)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,          X86_ISET_GP,    OP(Dy, Ry)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    
    /* 28h */
    TABLE_ENTRY("movapd",       X86_MN_MOVAPD,      PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Wpd)),
    TABLE_ENTRY("movapd",       X86_MN_MOVAPD,      PF_VEX,         X86_ISET_SSE2,  OP(Wpd, Vpd)),
    TABLE_ENTRY("cvtpi2pd",     X86_MN_CVTPI2PD,    PF_NONE,        X86_ISET_SSE2,  OP(Vpd, Qpi)),
    TABLE_ENTRY("movntpd",      X86_MN_MOVNTPD,     PF_VEX,         X86_ISET_SSE,   OP(Mpd, Vpd)),
    TABLE_ENTRY("cvttpd2pi",    X86_MN_CVTTPD2PI,   PF_NONE,        X86_ISET_SSE2,  OP(Ppi, Wpd)),
    TABLE_ENTRY("cvtpd2pi",     X86_MN_CVTPD2PI,    PF_NONE,        X86_ISET_SSE2,  OP(Ppi, Wpd)),
    TABLE_ENTRY("ucomisd",      X86_MN_UCOMISD,     PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Wsd)),
    TABLE_ENTRY("comisd",       X86_MN_COMISD,      PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Wsd)),

    /* 30h */
    TABLE_ENTRY("wrmsr",        X86_MN_WRMSR,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("rdtsc",        X86_MN_RDTSC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("rdmsr",        X86_MN_RDMSR,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("rdpmc",        X86_MN_RDPMC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sysenter",     X86_MN_SYSENTER,    PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sysexit",      X86_MN_SYSEXIT,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 38h: three-byte table escape */
    TABLE_ENTRY_ESCAPE(66_0F_38),
    TABLE_ENTRY_INVALID(),

    /* 3Ah: three-byte table escape */
    TABLE_ENTRY_ESCAPE(66_0F_3A),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY("cmovo",        X86_MN_CMOVO,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovno",       X86_MN_CMOVNO,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovc",        X86_MN_CMOVC,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnc",       X86_MN_CMOVNC,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovz",        X86_MN_CMOVZ,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnz",       X86_MN_CMOVNZ,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovna",       X86_MN_CMOVNA,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmova",        X86_MN_CMOVA,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovs",        X86_MN_CMOVS,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovns",       X86_MN_CMOVNS,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovp",        X86_MN_CMOVP,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnp",       X86_MN_CMOVPO,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovl",        X86_MN_CMOVL,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnl",       X86_MN_CMOVNL,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovng",       X86_MN_CMOVNG,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovg",        X86_MN_CMOVG,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),

    /* 50h */
    TABLE_ENTRY("movmskpd",     X86_MN_MOVMSKPD,    PF_VEX,         X86_ISET_SSE2,  OP(Gd, Upd)),
    TABLE_ENTRY("sqrtpd",       X86_MN_SQRTPD,      PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Wpd)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("andpd",        X86_MN_ANDPD,       PF_VEX,         X86_ISET_SSE,   OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("andnpd",       X86_MN_ANDNPD,      PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("orpd",         X86_MN_ORPD,        PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("xorpd",        X86_MN_XORPD,       PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("addpd",        X86_MN_ADDPD,       PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("mulpd",        X86_MN_MULPD,       PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("cvtpd2ps",     X86_MN_CVTPD2PS,    PF_VEX,         X86_ISET_SSE2,  OP(Vps, Wpd)),
    TABLE_ENTRY("cvtps2dq",     X86_MN_CVTPS2DQ,    PF_VEX,         X86_ISET_SSE2,  OP(Vdq, Wps)),
    TABLE_ENTRY("subpd",        X86_MN_SUBPD,       PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("minpd",        X86_MN_MINPD,       PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("divpd",        X86_MN_DIVPD,       PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("maxpd",        X86_MN_MAXPD,       PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Hpd, Wpd)),

    /* 60h */
    TABLE_ENTRY("punpcklbw",    X86_MN_PUNPCKLBW,   PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("punpcklwd",    X86_MN_PUNPCKLWD,   PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("punpckldq",    X86_MN_PUNPCKLDQ,   PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("packsswb",     X86_MN_PACKSSWB,    PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pcmpgtb",      X86_MN_PCMPGTB,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pcmpgtw",      X86_MN_PCMPGTW,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pcmpgtd",      X86_MN_PCMPGTD,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("packuswb",     X86_MN_PACKUSWB,    PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("punpckhbw",    X86_MN_PUNPCKHBW,   PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("punpckhwd",    X86_MN_PUNPCKHWD,   PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("punpckhdq",    X86_MN_PUNPCKHDQ,   PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("packssdw",     X86_MN_PACKSSDW,    PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("punpcklqdq",   X86_MN_PUNPCKLQDQ,  PF_VEX,         X86_ISET_SSE2,  OP(Vx, Hx, Wx)),
    TABLE_ENTRY("punpckhqdq",   X86_MN_PUNPCKHQDQ,  PF_VEX,         X86_ISET_SSE2,  OP(Vx, Hx, Wx)),
    
    TABLE_ENTRY_ESCAPE(66_0F_6E),
    
    TABLE_ENTRY("movdqa",       X86_MN_MOVDQA,      PF_VEX,         X86_ISET_SSE2,  OP(Vx, Wx)),

    /* 70h */
    TABLE_ENTRY("pshufd",       X86_MN_PSHUFD,      PF_VEX,         X86_ISET_SSE2,  OP(Vx, Wx, Ib)),

    /* 71h: group 12, 13, 14 */
    TABLE_ENTRY_ESCAPE(66_0F_71),
    TABLE_ENTRY_ESCAPE(66_0F_72),
    TABLE_ENTRY_ESCAPE(66_0F_73),

    /* 74h */
    TABLE_ENTRY("pcmpeqb",      X86_MN_PCMPEQB,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pcmpeqw",      X86_MN_PCMPEQW,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pcmpeqd",      X86_MN_PCMPEQD,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY_INVALID(),

    /* 78h: group 17 */
    TABLE_ENTRY_ESCAPE(66_0F_78),

    /* 79h */
    TABLE_ENTRY("extrq",        X86_MN_EXTRQ,       PF_NONE,        X86_ISET_SSE4A, OP(Vss, Uss)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("haddpd",       X86_MN_HADDPD,      PF_VEX,         X86_ISET_SSE3,  OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("hsubpd",       X86_MN_HSUBPD,      PF_VEX,         X86_ISET_SSE3,  OP(Vpd, Hpd, Wpd)),
    
    TABLE_ENTRY_ESCAPE(66_0F_7E),

    TABLE_ENTRY("movdqa",       X86_MN_MOVDQA,      PF_VEX,         X86_ISET_MMX,   OP(Wx, Vx)),

    /* 80h */
    TABLE_ENTRY("jo",           X86_MN_JO,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jno",          X86_MN_JNO,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jc",           X86_MN_JC,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnc",          X86_MN_JNC,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jz",           X86_MN_JZ,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnz",          X86_MN_JNZ,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jna",          X86_MN_JNA,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("ja",           X86_MN_JA,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("js",           X86_MN_JS,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jns",          X86_MN_JNS,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jp",           X86_MN_JP,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnp",          X86_MN_JNP,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jl",           X86_MN_JL,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnl",          X86_MN_JNL,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jng",          X86_MN_JNG,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jg",           X86_MN_JG,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),

    /* 90h */
    TABLE_ENTRY("seto",         X86_MN_SETO,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setno",        X86_MN_SETNO,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setc",         X86_MN_SETC,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnc",        X86_MN_SETNC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setz",         X86_MN_SETZ,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnz",        X86_MN_SETNZ,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setna",        X86_MN_SETNA,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("seta",         X86_MN_SETA,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("sets",         X86_MN_SETS,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setns",        X86_MN_SETNS,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setp",         X86_MN_SETP,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnp",        X86_MN_SETNP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setl",         X86_MN_SETL,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnl",        X86_MN_SETNL,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setng",        X86_MN_SETNG,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setg",         X86_MN_SETG,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),

    /* A0h */
    TABLE_ENTRY("push",         X86_MN_PUSH,        PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(FS)),
    TABLE_ENTRY("pop",          X86_MN_POP,         PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(FS)),
    TABLE_ENTRY("cpuid",        X86_MN_CPUID,       PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("bt",           X86_MN_BT,          PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("shld",         X86_MN_SHLD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, Ib)),
    TABLE_ENTRY("shld",         X86_MN_SHLD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, CL)),

    /* A6h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A8h */
    TABLE_ENTRY("push",         X86_MN_PUSH,        PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(GS)),
    TABLE_ENTRY("pop",          X86_MN_POP,         PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(GS)),
    TABLE_ENTRY("rsm",          X86_MN_RSM,         PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("bts",          X86_MN_BTS,         PF_LOCK | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("shrd",         X86_MN_SHRD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, Ib)),
    TABLE_ENTRY("shrd",         X86_MN_SHRD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, CL)),

    /* AEh: group 15 */
    TABLE_ENTRY_ESCAPE(66_0F_AE),

    /* AFh */
    TABLE_ENTRY("imul",         X86_MN_IMUL,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Gv, Ev)),

    /* B0h */
    TABLE_ENTRY("cmpxchg",      X86_MN_CMPXCHG,     PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("cmpxchg",      X86_MN_CMPXCHG,     PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("lss",          X86_MN_LSS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Mp)),
    TABLE_ENTRY("btr",          X86_MN_BTR,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("lfs",          X86_MN_LFS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Mp)),
    TABLE_ENTRY("lgs",          X86_MN_LGS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Mp)),
    TABLE_ENTRY("movzx",        X86_MN_MOVZX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Eb)),
    TABLE_ENTRY("movzx",        X86_MN_MOVZX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),

    /* B8h */
    TABLE_ENTRY_INVALID(),

    /* B9h: group 10, 8; both groups have prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_B9),
    TABLE_ENTRY_ESCAPE(0F_BA),

    /* BBh */
    TABLE_ENTRY("btc",          X86_MN_BTC,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("bsf",          X86_MN_BSF,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("bsr",          X86_MN_BSR,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("movsx",        X86_MN_MOVSX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Eb)),
    TABLE_ENTRY("movsx",        X86_MN_MOVSX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),

    /* C0h */
    TABLE_ENTRY("xadd",         X86_MN_XADD,        PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Eb, Gb)),
    TABLE_ENTRY("xadd",         X86_MN_XADD,        PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv)),
    TABLE_ENTRY("cmp*pd",       X86_MN_CMPPD,       PF_VEX | PF_CC,         X86_ISET_SSE2,      OP(Vpd, Hpd, Wpd, Ib)),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_ESCAPE(66_0F_C4),

    TABLE_ENTRY("pextrw",       X86_MN_PEXTRW,      PF_VEX128,      X86_ISET_SSE,   OP(Gw, Udq, Ib)),
    TABLE_ENTRY("shufpd",       X86_MN_SHUFPD,      PF_VEX,         X86_ISET_SSE2,  OP(Vpd, Hpd, Wpd, Ib)),

    /* C7h: group 9; group has prefix n/a -> not for intel */
    TABLE_ENTRY_ESCAPE(66_0F_C7),

    /* C8h */
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rAX_r8)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rCX_r9)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rDX_r10)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rBX_r11)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rSP_r12)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rBP_r13)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rSI_r14)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rDI_r15)),

    /* D0h */
    TABLE_ENTRY("addsubpd",     X86_MN_ADDSUBPD,    PF_VEX,         X86_ISET_SSE3,  OP(Vpd, Hpd, Wpd)),
    TABLE_ENTRY("psrlw",        X86_MN_PSRLW,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wss)),
    TABLE_ENTRY("psrld",        X86_MN_PSRLD,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wss)),
    TABLE_ENTRY("psrlq",        X86_MN_PSRLQ,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wss)),
    TABLE_ENTRY("paddq",        X86_MN_PADDQ,       PF_VEX,         X86_ISET_SSE,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmullw",       X86_MN_PMULLW,      PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("movq",         X86_MN_MOVQ,        PF_VEX,         X86_ISET_MMX,   OP(Wq, Vq)),
    TABLE_ENTRY("pmovmskb",     X86_MN_PMOVMSKB,    PF_VEX,         X86_ISET_SSE,   OP(Gd, Ux)),

    TABLE_ENTRY("psubusb",      X86_MN_PSUBUSB,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psubusw",      X86_MN_PSUBUSW,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pminub",       X86_MN_PMINUB,      PF_VEX,         X86_ISET_SSE,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pand",         X86_MN_PAND,        PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("paddusb",      X86_MN_PADDUSB,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("paddusw",      X86_MN_PADDUSW,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmaxub",       X86_MN_PMAXUB,      PF_VEX,         X86_ISET_SSE,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pandn",        X86_MN_PANDN,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),

    /* E0h */
    TABLE_ENTRY("pavgb",        X86_MN_PAVGB,       PF_VEX,         X86_ISET_SSE,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psraw",        X86_MN_PSRAW,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wss)),
    TABLE_ENTRY("psrad",        X86_MN_PSRAD,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wss)),
    TABLE_ENTRY("pavgw",        X86_MN_PAVGW,       PF_VEX,         X86_ISET_SSE,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmulhuw",      X86_MN_PMULHUW,     PF_VEX,         X86_ISET_SSE,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmulhw",       X86_MN_PMULHW,      PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("cvttpd2dq",    X86_MN_CVTTPD2DQ,   PF_VEX,         X86_ISET_SSE2,  OP(Vx, Wpd)),
    TABLE_ENTRY("movntdq",      X86_MN_MOVNTDQ,     PF_VEX,         X86_ISET_MMX,   OP(Mx, Vx)),

    TABLE_ENTRY("psubsb",       X86_MN_PSUBSB,      PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psubsw",       X86_MN_PSUBSW,      PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pminsw",       X86_MN_PMINSW,      PF_VEX,         X86_ISET_SSE,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("por",          X86_MN_POR,         PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("paddsb",       X86_MN_PADDSB,      PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("paddsw",       X86_MN_PADDSW,      PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmaxsw",       X86_MN_PMAXSW,      PF_VEX,         X86_ISET_SSE,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pxor",         X86_MN_PXOR,        PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),

    /* F0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psllw",        X86_MN_PSLLW,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wss)),
    TABLE_ENTRY("pslld",        X86_MN_PSLLD,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wss)),
    TABLE_ENTRY("psllq",        X86_MN_PSLLQ,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wss)),
    TABLE_ENTRY("pmuludq",      X86_MN_PMULUDQ,     PF_VEX,         X86_ISET_SSE2,  OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmaddwd",      X86_MN_PMADDWD,     PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psadbw",       X86_MN_PSADBW,      PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("maskmovdqu",   X86_MN_MASKMOVDQU,  PF_VEX,         X86_ISET_SSE,   OP(Vdq, Udq)),
    
    TABLE_ENTRY("psubb",        X86_MN_PSUBB,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psubw",        X86_MN_PSUBW,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psubd",        X86_MN_PSUBD,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psubq",        X86_MN_PSUBQ,       PF_VEX,         X86_ISET_SSE2,  OP(Vx, Hx, Wx)),
    TABLE_ENTRY("paddb",        X86_MN_PADDB,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("paddw",        X86_MN_PADDW,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("paddd",        X86_MN_PADDD,       PF_VEX,         X86_ISET_MMX,   OP(Vx, Hx, Wx)),
    TABLE_ENTRY("ud0",          X86_MN_UD,          PF_VEX,         X86_ISET_MMX,   OP(Pq, Qq))

TABLE_END(66_0F)

TABLE_BEGIN(66_0F_19)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(66_0F_19)

TABLE_BEGIN(66_0F_1C)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(66_0F_1C)

TABLE_BEGIN(66_0F_1D)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(66_0F_1D)

TABLE_BEGIN(66_0F_1E)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(66_0F_1E)

TABLE_BEGIN(66_0F_1F)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(66_0F_1F)

TABLE_BEGIN(66_0F_6E)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("movd",         X86_MN_MOVD,        PF_VEX128,      X86_ISET_MMX,   OP(Vy, Ey)),
    TABLE_ENTRY("movd",         X86_MN_MOVD,        PF_VEX128,      X86_ISET_MMX,   OP(Vy, Ey)),
    TABLE_ENTRY("movq",         X86_MN_MOVQ,        PF_VEX128,      X86_ISET_MMX,   OP(Vy, Ey))

TABLE_END(66_0F_6E)

TABLE_BEGIN(66_0F_71)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 02h: psrlw or invalid*/
    TABLE_ENTRY_ESCAPE(66_0F_71_REG2),

    TABLE_ENTRY_INVALID(),

    /* 04h: psraw or invalid*/
    TABLE_ENTRY_ESCAPE(66_0F_71_REG4),
    
    TABLE_ENTRY_INVALID(),

    /* 06h: psllw or invalid*/
    TABLE_ENTRY_ESCAPE(66_0F_71_REG6),
    
    TABLE_ENTRY_INVALID()

TABLE_END(66_0F_71)

TABLE_BEGIN(66_0F_71_REG2)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psrlw",        X86_MN_PSRLW,       PF_VEX,         X86_ISET_MMX,   OP(Hx, Ux, Ib))

TABLE_END(66_0F_71_REG2)

TABLE_BEGIN(66_0F_71_REG4)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psraw",        X86_MN_PSRAW,       PF_VEX,         X86_ISET_MMX,   OP(Hx, Ux, Ib))

TABLE_END(66_0F_71_REG4)

TABLE_BEGIN(66_0F_71_REG6)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psllw",        X86_MN_PSLLW,       PF_VEX,         X86_ISET_MMX,   OP(Hx, Ux, Ib))

TABLE_END(66_0F_71_REG6)

TABLE_BEGIN(66_0F_72)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 02h: psrld or invalid*/
    TABLE_ENTRY_ESCAPE(66_0F_72_REG2),

    TABLE_ENTRY_INVALID(),

    /* 04h: psrad or invalid*/
    TABLE_ENTRY_ESCAPE(66_0F_72_REG4),
    
    TABLE_ENTRY_INVALID(),

    /* 06h: pslld or invalid*/
    TABLE_ENTRY_ESCAPE(66_0F_72_REG6),
    
    TABLE_ENTRY_INVALID()

TABLE_END(66_0F_72)

TABLE_BEGIN(66_0F_72_REG2)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psrld",        X86_MN_PSRLD,       PF_VEX,         X86_ISET_MMX,   OP(Hx, Ux, Ib))

TABLE_END(66_0F_72_REG2)

TABLE_BEGIN(66_0F_72_REG4)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psrad",        X86_MN_PSRAD,       PF_VEX,         X86_ISET_MMX,   OP(Hx, Ux, Ib))

TABLE_END(66_0F_72_REG4)

TABLE_BEGIN(66_0F_72_REG6)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pslld",        X86_MN_PSLLD,       PF_VEX,         X86_ISET_MMX,   OP(Hx, Ux, Ib))

TABLE_END(66_0F_72_REG6)

TABLE_BEGIN(66_0F_73)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 02h: psrlq or invalid*/
    TABLE_ENTRY_ESCAPE(66_0F_73_REG2),

    /* 03h: psrldq or invalid*/
    TABLE_ENTRY_ESCAPE(66_0F_73_REG3),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 06h: psllq or invalid*/
    TABLE_ENTRY_ESCAPE(66_0F_73_REG6),
    
    /* 07h: pslldq or invalid*/
    TABLE_ENTRY_ESCAPE(66_0F_73_REG7)

TABLE_END(66_0F_73)

TABLE_BEGIN(66_0F_73_REG2)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psrlq",        X86_MN_PSRLQ,       PF_VEX,         X86_ISET_MMX,   OP(Hx, Ux, Ib))

TABLE_END(66_0F_73_REG2)

TABLE_BEGIN(66_0F_73_REG3)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psrldq",       X86_MN_PSRLDQ,      PF_VEX,         X86_ISET_SSE2,  OP(Hx, Ux, Ib))

TABLE_END(66_0F_73_REG3)

TABLE_BEGIN(66_0F_73_REG6)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("psllq",        X86_MN_PSLLQ,       PF_VEX,         X86_ISET_MMX,   OP(Hx, Ux, Ib))

TABLE_END(66_0F_73_REG6)

TABLE_BEGIN(66_0F_73_REG7)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pslldq",       X86_MN_PSLLDQ,      PF_VEX,         X86_ISET_SSE2,  OP(Hx, Ux, Ib))

TABLE_END(66_0F_73_REG7)

TABLE_BEGIN(66_0F_7E)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("movd",         X86_MN_MOVD,        PF_VEX128,      X86_ISET_MMX,   OP(Ey, Vy)),
    TABLE_ENTRY("movd",         X86_MN_MOVD,        PF_VEX128,      X86_ISET_MMX,   OP(Ey, Vy)),
    TABLE_ENTRY("movq",         X86_MN_MOVQ,        PF_VEX128,      X86_ISET_MMX,   OP(Ey, Vy))

TABLE_END(66_0F_7E)

TABLE_BEGIN(66_0F_AE)

    /* modr/m byte reg/nnn field */

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(66_0F_AE)

TABLE_BEGIN(66_0F_78)

    /* modr/m byte reg/nnn field */

    TABLE_ENTRY("extrq",        X86_MN_EXTRQ,       PF_NONE,        X86_ISET_SSE4A, OP(Vss, Ib, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(66_0F_78)

TABLE_BEGIN(66_0F_C4)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pinsrw",       X86_MN_PINSRW,      PF_VEX128,      X86_ISET_SSE,   OP(Vdq, Hdq, Mw, Ib)),
    TABLE_ENTRY("pinsrw",       X86_MN_PINSRW,      PF_VEX128,      X86_ISET_SSE,   OP(Vdq, Hdq, Ry, Ib))

TABLE_END(66_0F_C4)

TABLE_BEGIN(66_0F_C7)

    /* modr/m byte reg/nnn field */

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    
    /* vmclear */
    TABLE_ENTRY_ESCAPE(66_0F_C7_REG6),
    TABLE_ENTRY_INVALID()

TABLE_END(66_0F_C7)

TABLE_BEGIN(66_0F_C7_REG6)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("vmclear",      X86_MN_VMCLEAR,     PF_NONE | PF_PFXNA,     X86_ISET_VMX,   OP(Mq)),
    TABLE_ENTRY("rdrand",       X86_MN_RDRAND,      PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Rv))

TABLE_END(66_0F_C7_REG6)

/****************************************************************************

    Two-byte tables - F3h mandatory prefix

****************************************************************************/

TABLE_BEGIN(F3_0F)

    /* 00h: group 6, 7; both groups have prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_00),
    TABLE_ENTRY_ESCAPE(F3_0F_01),

    /* 02h */
    TABLE_ENTRY("lar",          X86_MN_LAR,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),
    TABLE_ENTRY("lsl",          X86_MN_LSL,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),

    /* 04h */
    TABLE_ENTRY_INVALID(),

    /* 05h */
    TABLE_ENTRY("syscall",      X86_MN_SYSCALL,     PF_O64 | PF_PFXNA,          X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("clts",         X86_MN_CLTS,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sysret",       X86_MN_SYSRET,      PF_O64 | PF_PFXNA,          X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("invd",         X86_MN_INVD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("wbinvd",       X86_MN_WBINVD,      PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),

    /* 0Ah */
    TABLE_ENTRY_INVALID(),

    /* 0Bh */
    TABLE_ENTRY("ud2",          X86_MN_UD2,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),

    /* 0Ch */
    TABLE_ENTRY_INVALID(),

    /* 0Dh: group p; group has prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_0D),

    /* 0Eh */
    TABLE_ENTRY("femms",        X86_MN_FEMMS,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),

    /* 0Fh: AMD only, 3DNow! escape */
    TABLE_ENTRY_INVALID(),
    
    /* 10h */
    TABLE_ENTRY("movss",        X86_MN_MOVSS,       PF_VEX128,      X86_ISET_SSE,   OP(Vx, Hx, Wss)),
    TABLE_ENTRY("movss",        X86_MN_MOVSS,       PF_VEX128,      X86_ISET_SSE,   OP(Wss, Hx, Vss)),

    /* 12h */
    TABLE_ENTRY("movsldup",     X86_MN_MOVSLDUP,    PF_VEX,         X86_ISET_SSE3,  OP(Vx, Wx)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("movshdup",     X86_MN_MOVSHDUP,    PF_VEX,         X86_ISET_SSE3,  OP(Vx, Wx)),
    TABLE_ENTRY_INVALID(),

    /* 18h: group 16; group has prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_18),

    /* 19h */
    TABLE_ENTRY_ESCAPE(F3_0F_19),

    TABLE_ENTRY("nop",          X86_MN_NOP,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("nop",          X86_MN_NOP,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Ev)),

    TABLE_ENTRY_ESCAPE(F3_0F_1C),
    TABLE_ENTRY_ESCAPE(F3_0F_1D),
    TABLE_ENTRY_ESCAPE(F3_0F_1E),
    TABLE_ENTRY_ESCAPE(F3_0F_1F),

    /* 20h */
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,      X86_ISET_GP,    OP(Ry, Cy)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,      X86_ISET_GP,    OP(Ry, Dy)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,      X86_ISET_GP,    OP(Cy, Ry)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,      X86_ISET_GP,    OP(Dy, Ry)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    
    /* 28h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("cvtsi2ss",     X86_MN_CVTSI2SS,    PF_VEX128,      X86_ISET_SSE,   OP(Vss, Hss, Ey)),
    TABLE_ENTRY("movntss",      X86_MN_MOVNTSS,     PF_NONE,        X86_ISET_SSE4A, OP(Md, Vss)),
    TABLE_ENTRY("cvttss2si",    X86_MN_CVTTSS2SI,   PF_VEX128,      X86_ISET_SSE,   OP(Gy, Wss)),
    TABLE_ENTRY("cvtss2si",     X86_MN_CVTSS2SI,    PF_VEX128,      X86_ISET_SSE,   OP(Gy, Wss)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY("wrmsr",        X86_MN_WRMSR,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("rdtsc",        X86_MN_RDTSC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("rdmsr",        X86_MN_RDMSR,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("rdpmc",        X86_MN_RDPMC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sysenter",     X86_MN_SYSENTER,    PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sysexit",      X86_MN_SYSEXIT,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 38h: three-byte table escape */
    TABLE_ENTRY_ESCAPE(F3_0F_38),
    TABLE_ENTRY_INVALID(),

    /* 3Ah: three-byte table escape */
    TABLE_ENTRY_ESCAPE(F3_0F_3A),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY("cmovo",        X86_MN_CMOVO,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovno",       X86_MN_CMOVNO,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovc",        X86_MN_CMOVC,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnc",       X86_MN_CMOVNC,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovz",        X86_MN_CMOVZ,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnz",       X86_MN_CMOVNZ,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovna",       X86_MN_CMOVNA,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmova",        X86_MN_CMOVA,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovs",        X86_MN_CMOVS,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovns",       X86_MN_CMOVNS,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovp",        X86_MN_CMOVP,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnp",       X86_MN_CMOVPO,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovl",        X86_MN_CMOVL,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnl",       X86_MN_CMOVNL,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovng",       X86_MN_CMOVNG,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovg",        X86_MN_CMOVG,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("sqrtss",       X86_MN_SQRTSS,      PF_VEX128,      X86_ISET_SSE,   OP(Vss, Hss, Wss)),
    TABLE_ENTRY("rsqrtss",      X86_MN_RSQRTSS,     PF_VEX128,      X86_ISET_SSE,   OP(Vss, Hss, Wss)),
    TABLE_ENTRY("rcpss",        X86_MN_RCPSS,       PF_VEX128,      X86_ISET_SSE,   OP(Vss, Hss, Wss)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("addss",        X86_MN_ADDSS,       PF_VEX128,      X86_ISET_SSE,   OP(Vss, Hss, Wss)),
    TABLE_ENTRY("mulss",        X86_MN_MULSS,       PF_VEX128,      X86_ISET_SSE,   OP(Vss, Hss, Wss)),
    TABLE_ENTRY("cvtss2sd",     X86_MN_CVTSS2SD,    PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Hx, Wss)),
    TABLE_ENTRY("cvttps2dq",    X86_MN_CVTTPS2DQ,   PF_VEX,         X86_ISET_SSE2,  OP(Vdq, Wps)),
    TABLE_ENTRY("subss",        X86_MN_SUBSS,       PF_VEX128,      X86_ISET_SSE,   OP(Vss, Hss, Wss)),
    TABLE_ENTRY("minss",        X86_MN_MINSS,       PF_VEX128,      X86_ISET_SSE,   OP(Vss, Hss, Wss)),
    TABLE_ENTRY("divss",        X86_MN_DIVSS,       PF_VEX128,      X86_ISET_SSE,   OP(Vss, Hss, Wss)),
    TABLE_ENTRY("maxss",        X86_MN_MAXSS,       PF_VEX128,      X86_ISET_SSE,   OP(Vss, Hss, Wss)),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("movdqu",       X86_MN_MOVDQU,      PF_VEX,         X86_ISET_SSE2,  OP(Vx, Wx)),

    /* 70h */
    TABLE_ENTRY("pshufhw",      X86_MN_PSHUFHW,     PF_VEX,         X86_ISET_SSE2,  OP(Vx, Wx, Ib)),

    /* 71h: group 12, 13, 14 */
    TABLE_ENTRY_ESCAPE(F3_0F_71),
    TABLE_ENTRY_ESCAPE(F3_0F_72),
    TABLE_ENTRY_ESCAPE(F3_0F_73),

    /* 74h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 78h */
    TABLE_ENTRY_INVALID(),

    /* 79h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("movq",         X86_MN_MOVQ,        PF_VEX128,      X86_ISET_MMX,   OP(Vq, Wq)),
    TABLE_ENTRY("movdqu",       X86_MN_MOVDQU,      PF_VEX,         X86_ISET_MMX,   OP(Wx, Vx)),

    /* 80h */
    TABLE_ENTRY("jo",           X86_MN_JO,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jno",          X86_MN_JNO,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jc",           X86_MN_JC,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnc",          X86_MN_JNC,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jz",           X86_MN_JZ,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnz",          X86_MN_JNZ,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jna",          X86_MN_JNA,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("ja",           X86_MN_JA,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("js",           X86_MN_JS,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jns",          X86_MN_JNS,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jp",           X86_MN_JP,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnp",          X86_MN_JNP,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jl",           X86_MN_JL,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnl",          X86_MN_JNL,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jng",          X86_MN_JNG,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jg",           X86_MN_JG,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),

    /* 90h */
    TABLE_ENTRY("seto",         X86_MN_SETO,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setno",        X86_MN_SETNO,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setc",         X86_MN_SETC,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnc",        X86_MN_SETNC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setz",         X86_MN_SETZ,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnz",        X86_MN_SETNZ,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setna",        X86_MN_SETNA,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("seta",         X86_MN_SETA,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("sets",         X86_MN_SETS,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setns",        X86_MN_SETNS,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setp",         X86_MN_SETP,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnp",        X86_MN_SETNP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setl",         X86_MN_SETL,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnl",        X86_MN_SETNL,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setng",        X86_MN_SETNG,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setg",         X86_MN_SETG,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),

    /* A0h */
    TABLE_ENTRY("push",         X86_MN_PUSH,        PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(FS)),
    TABLE_ENTRY("pop",          X86_MN_POP,         PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(FS)),
    TABLE_ENTRY("cpuid",        X86_MN_CPUID,       PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("bt",           X86_MN_BT,          PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("shld",         X86_MN_SHLD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, Ib)),
    TABLE_ENTRY("shld",         X86_MN_SHLD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, CL)),

    /* A6h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A8h */
    TABLE_ENTRY("push",         X86_MN_PUSH,        PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(GS)),
    TABLE_ENTRY("pop",          X86_MN_POP,         PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(GS)),
    TABLE_ENTRY("rsm",          X86_MN_RSM,         PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("bts",          X86_MN_BTS,         PF_LOCK | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("shrd",         X86_MN_SHRD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, Ib)),
    TABLE_ENTRY("shrd",         X86_MN_SHRD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, CL)),

    /* AEh: group 15 */
    TABLE_ENTRY_ESCAPE(F3_0F_AE),

    /* AFh */
    TABLE_ENTRY("imul",         X86_MN_IMUL,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Gv, Ev)),

    /* B0h */
    TABLE_ENTRY("cmpxchg",      X86_MN_CMPXCHG,     PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("cmpxchg",      X86_MN_CMPXCHG,     PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("lss",          X86_MN_LSS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Mp)),
    TABLE_ENTRY("btr",          X86_MN_BTR,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("lfs",          X86_MN_LFS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Mp)),
    TABLE_ENTRY("lgs",          X86_MN_LGS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Mp)),
    TABLE_ENTRY("movzx",        X86_MN_MOVZX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Eb)),
    TABLE_ENTRY("movzx",        X86_MN_MOVZX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),

    /* B8h */
    TABLE_ENTRY("popcnt",       X86_MN_POPCNT,      PF_NONE | PF_PFXNA,     X86_ISET_SSE42, OP(Gv, Ev)),

    /* B9h: group 10, 8; both groups have prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_B9),
    TABLE_ENTRY_ESCAPE(0F_BA),

    /* BBh */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("tzcnt",        X86_MN_TZCNT,       PF_NONE | PF_PFXNA,     X86_ISET_BMI1,  OP(Gv, Ev)),
    TABLE_ENTRY("lzcnt",        X86_MN_LZCNT,       PF_NONE | PF_PFXNA,     X86_ISET_BMI1,  OP(Gv, Ev)),
    TABLE_ENTRY("movsx",        X86_MN_MOVSX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Eb)),
    TABLE_ENTRY("movsx",        X86_MN_MOVSX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),

    /* C0h */
    TABLE_ENTRY("xadd",         X86_MN_XADD,        PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Eb, Gb)),
    TABLE_ENTRY("xadd",         X86_MN_XADD,        PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv)),
    TABLE_ENTRY("cmp*ss",       X86_MN_CMPSS,       PF_VEX | PF_CC,         X86_ISET_SSE,       OP(Vss, Hss, Wss, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C7h: group 9; group has prefix n/a */
    TABLE_ENTRY_ESCAPE(F3_0F_C7),

    /* C8h */
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rAX_r8)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rCX_r9)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rDX_r10)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rBX_r11)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rSP_r12)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rBP_r13)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rSI_r14)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rDI_r15)),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("movq2dq",      X86_MN_MOVQ2DQ,     PF_NONE,        X86_ISET_SSE2,  OP(Vdq, Nq)),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("cvtdq2pd",     X86_MN_CVTDQ2PD,    PF_VEX,         X86_ISET_SSE2,  OP(Vx, Wpd)),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("ud0",          X86_MN_UD,          PF_VEX128,      X86_ISET_MMX,   OP(Pq, Qq))

TABLE_END(F3_0F)

TABLE_BEGIN(F3_0F_01)

    /* modr/m byte reg/nnn field */

    /* 00h: sgdt or r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG0),

    /* 01h: sidt or r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG1),

    /* 02h: lgdt or r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG2),

    /* 03h: lidt or r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG3),

    /* 04h: smsw Mw/Rv */
    TABLE_ENTRY_ESCAPE(0F_01_REG4),

    /* 05h */
    TABLE_ENTRY_ESCAPE(F3_0F_01_REG5),

    /* 06h */
    TABLE_ENTRY("lmsw", X86_MN_LMSW,    PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Ew)),

    /* 07h: invlpg or r/m extension */
    TABLE_ENTRY_ESCAPE(0F_01_REG7)

TABLE_END(F3_0F_01)

TABLE_BEGIN(F3_0F_01_REG5)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("rstorssp",         X86_MN_RSTORSSP,        PF_NONE,            X86_ISET_CET,       OP(Mq)),

    /* r/m extension */
    TABLE_ENTRY_ESCAPE(F3_0F_01_REG5_RM)

TABLE_END(F3_0F_01_REG5)

TABLE_BEGIN(F3_0F_01_REG5_RM)

    /* modr/m byte r/m field */
    TABLE_ENTRY("setssbsy",         X86_MN_SETSSBSY,        PF_NONE,            X86_ISET_CET,       OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("saveprevssp",      X86_MN_SAVEPREVSSP,     PF_NONE,            X86_ISET_CET,       OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F3_0F_01_REG5_RM)

TABLE_BEGIN(F3_0F_19)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(F3_0F_19)

TABLE_BEGIN(F3_0F_1C)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(F3_0F_1C)

TABLE_BEGIN(F3_0F_1D)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(F3_0F_1D)

TABLE_BEGIN(F3_0F_1E)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),

    TABLE_ENTRY_ESCAPE(F3_0F_1E_REG1),

    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    
    TABLE_ENTRY_ESCAPE(F3_0F_1E_REG7_RM)

TABLE_END(F3_0F_1E)

TABLE_BEGIN(F3_0F_1E_REG1)

    TABLE_ENTRY("rdsspd",       X86_MN_RDSSPD,      PF_NONE,    X86_ISET_CET,       OP(Rd)),
    TABLE_ENTRY("rdsspd",       X86_MN_RDSSPD,      PF_NONE,    X86_ISET_CET,       OP(Rd)),
    TABLE_ENTRY("rdsspq",       X86_MN_RDSSPQ,      PF_NONE,    X86_ISET_CET,       OP(Rq))

TABLE_END(F3_0F_1E_REG1)

TABLE_BEGIN(F3_0F_1E_REG7_RM)

    /* modr/m byte r/m field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("endbr64",      X86_MN_ENDBR64,     PF_NONE,        X86_ISET_GP, OP(NONE)),
    TABLE_ENTRY("endbr32",      X86_MN_ENDBR32,     PF_NONE,        X86_ISET_GP, OP(NONE)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(F3_0F_1E_REG7_RM)

TABLE_BEGIN(F3_0F_1F)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(F3_0F_1F)

TABLE_BEGIN(F3_0F_71)

    /* modr/m byte reg/nnn field */

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F3_0F_71)

TABLE_BEGIN(F3_0F_72)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F3_0F_72)

TABLE_BEGIN(F3_0F_73)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F3_0F_73)

TABLE_BEGIN(F3_0F_AE)

    /* modr/m byte reg/nnn field */

    TABLE_ENTRY("rdfsbase",     X86_MN_RDFSBASE,    PF_NONE,        X86_ISET_GP,    OP(Ry)),
    TABLE_ENTRY("wrfsbase",     X86_MN_WRFSBASE,    PF_NONE,        X86_ISET_GP,    OP(Ry)),
    TABLE_ENTRY("rdgsbase",     X86_MN_RDGSBASE,    PF_NONE,        X86_ISET_GP,    OP(Ry)),
    TABLE_ENTRY("wrgsbase",     X86_MN_WRGSBASE,    PF_NONE,        X86_ISET_GP,    OP(Ry)),
    TABLE_ENTRY("ptwrite",      X86_MN_PTWRITE,     PF_NONE,        X86_ISET_GP,    OP(Ry)),
    TABLE_ENTRY_ESCAPE(F3_0F_AE_REG5),
    TABLE_ENTRY("clrssbsy",     X86_MN_CLRSSBSY,    PF_NONE,        X86_ISET_CET,   OP(Mq)),
    TABLE_ENTRY_INVALID()

TABLE_END(F3_0F_AE)

TABLE_BEGIN(F3_0F_AE_REG5)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("incsspd",          X86_MN_INCSSPD,         PF_NONE,        X86_ISET_CET,       OP(Rd)),
    TABLE_ENTRY("incsspd",          X86_MN_INCSSPD,         PF_NONE,        X86_ISET_CET,       OP(Rd)),
    TABLE_ENTRY("incsspq",          X86_MN_INCSSPQ,         PF_NONE,        X86_ISET_CET,       OP(Rq))

TABLE_END(F3_0F_AE_REG5)

TABLE_BEGIN(F3_0F_C7)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    
    /* vmxon or rdrand */
    TABLE_ENTRY_ESCAPE(F3_0F_C7_REG6),

    /* vmptrst or rdseed */
    TABLE_ENTRY_ESCAPE(F3_0F_C7_REG7)

TABLE_END(F3_0F_C7)

TABLE_BEGIN(F3_0F_C7_REG6)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("vmxon",        X86_MN_VMXON,       PF_NONE | PF_PFXNA,     X86_ISET_VMX,   OP(Mq)),
    TABLE_ENTRY("rdrand",       X86_MN_RDRAND,      PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Rv))

TABLE_END(F3_0F_C7_REG6)

TABLE_BEGIN(F3_0F_C7_REG7)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("vmptrst",      X86_MN_VMPTRST,     PF_NONE | PF_PFXNA,     X86_ISET_VMX,   OP(Mq)),
    TABLE_ENTRY("rdseed",       X86_MN_RDSEED,      PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Rv))

TABLE_END(F3_0F_C7_REG7)

/****************************************************************************

    Two-byte tables - F2h mandatory prefix

****************************************************************************/

TABLE_BEGIN(F2_0F)

    /* 00h: group 6, 7; both groups have prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_00),
    TABLE_ENTRY_ESCAPE(0F_01),

    /* 02h */
    TABLE_ENTRY("lar",          X86_MN_LAR,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),
    TABLE_ENTRY("lsl",          X86_MN_LSL,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),

    /* 04h */
    TABLE_ENTRY_INVALID(),

    /* 05h */
    TABLE_ENTRY("syscall",      X86_MN_SYSCALL,     PF_O64 | PF_PFXNA,          X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("clts",         X86_MN_CLTS,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sysret",       X86_MN_SYSRET,      PF_O64 | PF_PFXNA,          X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("invd",         X86_MN_INVD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("wbinvd",       X86_MN_WBINVD,      PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),

    /* 0Ah */
    TABLE_ENTRY_INVALID(),

    /* 0Bh */
    TABLE_ENTRY("ud2",          X86_MN_UD2,         PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),

    /* 0Ch */
    TABLE_ENTRY_INVALID(),

    /* 0Dh: group p; group has prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_0D),

    /* 0Eh */
    TABLE_ENTRY("femms",        X86_MN_FEMMS,       PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),

    /* 0Fh: AMD only, 3DNow! escape */
    TABLE_ENTRY_INVALID(),
    
    /* 10h */
    TABLE_ENTRY("movsd",        X86_MN_MOVSD,       PF_VEX128,      X86_ISET_SSE2,  OP(Vx, Hx, Wsd)),
    TABLE_ENTRY("movsd",        X86_MN_MOVSD,       PF_VEX128,      X86_ISET_SSE2,  OP(Wq, Hx, Vsd)),

    /* 12h */
    TABLE_ENTRY("movddup",      X86_MN_MOVDDUP,     PF_VEX,         X86_ISET_SSE3,  OP(Vx, Wx)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 18h: group 16; group has prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_18),

    /* 19h */
    TABLE_ENTRY_ESCAPE(F2_0F_19),

    TABLE_ENTRY("nop",          X86_MN_NOP,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Ev)),
    TABLE_ENTRY("nop",          X86_MN_NOP,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Ev)),

    TABLE_ENTRY_ESCAPE(F2_0F_1C),
    TABLE_ENTRY_ESCAPE(F2_0F_1D),
    TABLE_ENTRY_ESCAPE(F2_0F_1E),
    TABLE_ENTRY_ESCAPE(F2_0F_1F),

    /* 20h */
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,          X86_ISET_GP,    OP(Ry, Cy)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,          X86_ISET_GP,    OP(Ry, Dy)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,          X86_ISET_GP,    OP(Cy, Ry)),
    TABLE_ENTRY("mov",          X86_MN_MOV,     PF_F64 | PF_PFXNA,          X86_ISET_GP,    OP(Dy, Ry)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    
    /* 28h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("cvtsi2sd",     X86_MN_CVTSI2SD,    PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Hsd, Ey)),
    TABLE_ENTRY("movntsd",      X86_MN_MOVNTSD,     PF_NONE,        X86_ISET_SSE4A, OP(Mq, Vsd)),
    TABLE_ENTRY("cvttsd2si",    X86_MN_CVTTSD2SI,   PF_VEX128,      X86_ISET_SSE2,  OP(Gy, Wsd)),
    TABLE_ENTRY("cvtsd2si",     X86_MN_CVTSD2SI,    PF_VEX128,      X86_ISET_SSE2,  OP(Gy, Wsd)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY("wrmsr",        X86_MN_WRMSR,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("rdtsc",        X86_MN_RDTSC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("rdmsr",        X86_MN_RDMSR,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("rdpmc",        X86_MN_RDPMC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sysenter",     X86_MN_SYSENTER,    PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("sysexit",      X86_MN_SYSEXIT,     PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 38h: three-byte table escape */
    TABLE_ENTRY_ESCAPE(F2_0F_38),
    TABLE_ENTRY_INVALID(),

    /* 3Ah: three-byte table escape */
    TABLE_ENTRY_ESCAPE(F2_0F_3A),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY("cmovo",        X86_MN_CMOVO,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovno",       X86_MN_CMOVNO,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovc",        X86_MN_CMOVC,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnc",       X86_MN_CMOVNC,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovz",        X86_MN_CMOVZ,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnz",       X86_MN_CMOVNZ,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovna",       X86_MN_CMOVNA,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmova",        X86_MN_CMOVA,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovs",        X86_MN_CMOVS,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovns",       X86_MN_CMOVNS,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovp",        X86_MN_CMOVP,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnp",       X86_MN_CMOVPO,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovl",        X86_MN_CMOVL,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovnl",       X86_MN_CMOVNL,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovng",       X86_MN_CMOVNG,      PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),
    TABLE_ENTRY("cmovg",        X86_MN_CMOVG,       PF_NONE | PF_PFXNA, X86_ISET_GP,        OP(Gv, Ev)),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("sqrtsd",       X86_MN_SQRTSD,      PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Hsd, Wsd)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("addsd",        X86_MN_ADDSD,       PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Hsd, Wsd)),
    TABLE_ENTRY("mulsd",        X86_MN_MULSD,       PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Hsd, Wsd)),
    TABLE_ENTRY("cvtsd2ss",     X86_MN_CVTSD2SS,    PF_VEX128,      X86_ISET_SSE2,  OP(Vss, Hx, Wsd)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("subsd",        X86_MN_SUBSD,       PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Hsd, Wsd)),
    TABLE_ENTRY("minsd",        X86_MN_MINSD,       PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Hsd, Wsd)),
    TABLE_ENTRY("divsd",        X86_MN_DIVSD,       PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Hsd, Wsd)),
    TABLE_ENTRY("maxsd",        X86_MN_MAXSD,       PF_VEX128,      X86_ISET_SSE2,  OP(Vsd, Hsd, Wsd)),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY("pshuflw",      X86_MN_PSHUFLW, PF_VEX,         X86_ISET_SSE2,  OP(Vx, Wx, Ib)),

    /* 71h: group 12, 13, 14 */
    TABLE_ENTRY_ESCAPE(F2_0F_71),
    TABLE_ENTRY_ESCAPE(F2_0F_72),
    TABLE_ENTRY_ESCAPE(F2_0F_73),

    /* 74h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 78h */
    TABLE_ENTRY("insertq",      X86_MN_INSERTQ,     PF_NONE,        X86_ISET_SSE4A, OP(Vss, Uss, Ib, Ib)),
    TABLE_ENTRY("insertq",      X86_MN_INSERTQ,     PF_NONE,        X86_ISET_SSE4A, OP(Vss, Uss)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("haddps",       X86_MN_HADDPS,      PF_VEX,         X86_ISET_SSE3,  OP(Vps, Hps, Wps)),
    TABLE_ENTRY("hsubps",       X86_MN_HSUBPS,      PF_VEX,         X86_ISET_SSE3,  OP(Vps, Hps, Wps)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY("jo",           X86_MN_JO,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jno",          X86_MN_JNO,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jc",           X86_MN_JC,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnc",          X86_MN_JNC,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jz",           X86_MN_JZ,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnz",          X86_MN_JNZ,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jna",          X86_MN_JNA,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("ja",           X86_MN_JA,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("js",           X86_MN_JS,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jns",          X86_MN_JNS,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jp",           X86_MN_JP,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnp",          X86_MN_JNP,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jl",           X86_MN_JL,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jnl",          X86_MN_JNL,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jng",          X86_MN_JNG,         PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),
    TABLE_ENTRY("jg",           X86_MN_JG,          PF_F64 | PF_PFXNA,      X86_ISET_GP,        OP(Jz)),

    /* 90h */
    TABLE_ENTRY("seto",         X86_MN_SETO,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setno",        X86_MN_SETNO,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setc",         X86_MN_SETC,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnc",        X86_MN_SETNC,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setz",         X86_MN_SETZ,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnz",        X86_MN_SETNZ,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setna",        X86_MN_SETNA,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("seta",         X86_MN_SETA,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("sets",         X86_MN_SETS,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setns",        X86_MN_SETNS,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setp",         X86_MN_SETP,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnp",        X86_MN_SETNP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setl",         X86_MN_SETL,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setnl",        X86_MN_SETNL,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setng",        X86_MN_SETNG,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),
    TABLE_ENTRY("setg",         X86_MN_SETG,        PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Eb)),

    /* A0h */
    TABLE_ENTRY("push",         X86_MN_PUSH,        PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(FS)),
    TABLE_ENTRY("pop",          X86_MN_POP,         PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(FS)),
    TABLE_ENTRY("cpuid",        X86_MN_CPUID,       PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("bt",           X86_MN_BT,          PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("shld",         X86_MN_SHLD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, Ib)),
    TABLE_ENTRY("shld",         X86_MN_SHLD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, CL)),

    /* A6h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A8h */
    TABLE_ENTRY("push",         X86_MN_PUSH,        PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(GS)),
    TABLE_ENTRY("pop",          X86_MN_POP,         PF_D64 | PF_PFXNA,          X86_ISET_GP,    OP(GS)),
    TABLE_ENTRY("rsm",          X86_MN_RSM,         PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(NONE)),
    TABLE_ENTRY("bts",          X86_MN_BTS,         PF_LOCK | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("shrd",         X86_MN_SHRD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, Ib)),
    TABLE_ENTRY("shrd",         X86_MN_SHRD,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Ev, Gv, CL)),

    /* AEh: group 15 */
    TABLE_ENTRY_ESCAPE(F2_0F_AE),

    /* AFh */
    TABLE_ENTRY("imul",         X86_MN_IMUL,        PF_NONE | PF_PFXNA,         X86_ISET_GP,    OP(Gv, Ev)),

    /* B0h */
    TABLE_ENTRY("cmpxchg",      X86_MN_CMPXCHG,     PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Eb, Gb)),
    TABLE_ENTRY("cmpxchg",      X86_MN_CMPXCHG,     PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("lss",          X86_MN_LSS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gz, Mp)),
    TABLE_ENTRY("btr",          X86_MN_BTR,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("lfs",          X86_MN_LFS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gz, Mp)),
    TABLE_ENTRY("lgs",          X86_MN_LGS,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gz, Mp)),
    TABLE_ENTRY("movzx",        X86_MN_MOVZX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Eb)),
    TABLE_ENTRY("movzx",        X86_MN_MOVZX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),

    /* B8h */
    TABLE_ENTRY_INVALID(),

    /* B9h: group 10, 8; both groups have prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_B9),
    TABLE_ENTRY_ESCAPE(0F_BA),

    /* BBh */
    TABLE_ENTRY("btc",          X86_MN_BTC,         PF_LOCK | PF_PFXNA,     X86_ISET_GP,    OP(Ev, Gv)),
    TABLE_ENTRY("bsf",          X86_MN_BSF,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("bsr",          X86_MN_BSR,         PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ev)),
    TABLE_ENTRY("movsx",        X86_MN_MOVSX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Eb)),
    TABLE_ENTRY("movsx",        X86_MN_MOVSX,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(Gv, Ew)),
        
    /* C0h */
    TABLE_ENTRY("xadd",         X86_MN_XADD,        PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Eb, Gb)),
    TABLE_ENTRY("xadd",         X86_MN_XADD,        PF_LOCK | PF_PFXNA,     X86_ISET_GP,        OP(Ev, Gv)),
    TABLE_ENTRY("cmp*sd",       X86_MN_CMPSD,       PF_VEX | PF_CC,         X86_ISET_SSE2,      OP(Vsd, Hsd, Wq, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C7h: group 9; group has prefix n/a */
    TABLE_ENTRY_ESCAPE(0F_C7),

    /* C8h */
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rAX_r8)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rCX_r9)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rDX_r10)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rBX_r11)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rSP_r12)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rBP_r13)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rSI_r14)),
    TABLE_ENTRY("bswap",        X86_MN_BSWAP,       PF_NONE | PF_PFXNA,     X86_ISET_GP,    OP(rDI_r15)),

    /* D0h */
    TABLE_ENTRY("addsubps",     X86_MN_ADDSUBPS,    PF_VEX,         X86_ISET_SSE3,  OP(Vps, Hps, Wps)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("movdq2q",      X86_MN_MOVDQ2Q,     PF_NONE,        X86_ISET_SSE2,  OP(Pq, Uq)),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("cvtpd2dq",     X86_MN_CVTPD2DQ,    PF_VEX,         X86_ISET_SSE2,  OP(Vx, Wpd)),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY("lddqu",        X86_MN_LDDQU,       PF_VEX,         X86_ISET_SSE3,  OP(Vx, Wx)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("ud0",          X86_MN_UD,          PF_VEX128,      X86_ISET_MMX,   OP(Pq, Qq))

TABLE_END(F2_0F)

TABLE_BEGIN(F2_0F_19)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(F2_0F_19)

TABLE_BEGIN(F2_0F_1C)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(F2_0F_1C)

TABLE_BEGIN(F2_0F_1D)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(F2_0F_1D)

TABLE_BEGIN(F2_0F_1E)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(F2_0F_1E)

TABLE_BEGIN(F2_0F_1F)

    /* modr/m byte reg/nnn field */
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev)),
    TABLE_ENTRY("nop",  X86_MN_NOP,     PF_NONE | PF_PFXNA,         X86_ISET_GP, OP(Ev))

TABLE_END(F2_0F_1F)

TABLE_BEGIN(F2_0F_71)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F2_0F_71)

TABLE_BEGIN(F2_0F_72)

    //* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F2_0F_72)

TABLE_BEGIN(F2_0F_73)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F2_0F_73)

TABLE_BEGIN(F2_0F_AE)

    /* modr/m byte reg/nnn field */

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F2_0F_AE)

/****************************************************************************

    Three-byte tables - no mandatory prefix

****************************************************************************/

TABLE_BEGIN(0F_38)

    /* 00h */
    TABLE_ENTRY("pshufb",       X86_MN_PSHUFB,      PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("phaddw",       X86_MN_PHADDW,      PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("phaddd",       X86_MN_PHADDD,      PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("phaddsw",      X86_MN_PHADDSW,     PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("pmaddubsw",    X86_MN_PMADDUBSW,   PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("phsubw",       X86_MN_PHSUBW,      PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("phsubd",       X86_MN_PHSUBD,      PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("phsubsw",      X86_MN_PHSUBSW,     PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("psignb",       X86_MN_PSIGNB,      PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("psignw",       X86_MN_PSIGNW,      PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("psignd",       X86_MN_PSIGND,      PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("pmulhrsw",     X86_MN_PMULHRSW,    PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 10h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pabsb",        X86_MN_PABSB,       PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("pabsw",        X86_MN_PABSW,       PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY("pabsd",        X86_MN_PABSD,       PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY("movbe",        X86_MN_MOVBE,       PF_NONE,        X86_ISET_GP,    OP(Gy, My)),
    TABLE_ENTRY("movbe",        X86_MN_MOVBE,       PF_NONE,        X86_ISET_GP,    OP(My, Gy)),
    TABLE_ENTRY("andn",         X86_MN_ANDN,        PF_VEX,         X86_ISET_BMI1,  OP(Gy, By, Ey)),

    /* F3h: group 17; vex prefix is required */
    TABLE_ENTRY_ESCAPE(0F_38_F3),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("bzhi",         X86_MN_BZHI,        PF_VEX,         X86_ISET_BMI2,  OP(Gy, Ey, By)),
    TABLE_ENTRY_ESCAPE(0F_38_F6),
    TABLE_ENTRY("bextr",        X86_MN_BEXTR,       PF_VEX,         X86_ISET_BMI1,  OP(Gy, Ey, By)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_38)

TABLE_BEGIN(0F_38_F3)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("blsr",         X86_MN_BLSR,        PF_OVEX,        X86_ISET_BMI1,  OP(By, Ey)),
    TABLE_ENTRY("blsmsk",       X86_MN_BLSMSK,      PF_OVEX,        X86_ISET_BMI1,  OP(By, Ey)),
    TABLE_ENTRY("blsi",         X86_MN_BLSI,        PF_OVEX,        X86_ISET_BMI1,  OP(By, Ey)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_38_F3)

TABLE_BEGIN(0F_38_F6)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("wrssd",            X86_MN_WRSSD,           PF_NONE,        X86_ISET_CET,       OP(Md, Gd)),
    TABLE_ENTRY("wrssd",            X86_MN_WRSSD,           PF_NONE,        X86_ISET_CET,       OP(Md, Gd)),
    TABLE_ENTRY("wrssq",            X86_MN_WRSSQ,           PF_NONE,        X86_ISET_CET,       OP(Mq, Gq))

TABLE_END(0F_38_F6)

TABLE_BEGIN(0F_3A)

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("palignr",      X86_MN_PALIGNR,     PF_NONE,        X86_ISET_SSSE3, OP(Pq, Qq, Ib)),

    /* 10h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_3A)

/****************************************************************************

    Three-byte tables - 66h mandatory prefix

****************************************************************************/

TABLE_BEGIN(66_0F_38)

    /* 00h */
    TABLE_ENTRY("pshufb",           X86_MN_PSHUFB,          PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("phaddw",           X86_MN_PHADDW,          PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("phaddd",           X86_MN_PHADDD,          PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("phaddsw",          X86_MN_PHADDSW,         PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmaddubsw",        X86_MN_PMADDUBSW,       PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("phsubw",           X86_MN_PHSUBW,          PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("phsubd",           X86_MN_PHSUBD,          PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("phsubsw",          X86_MN_PHSUBSW,         PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psignb",           X86_MN_PSIGNB,          PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psignw",           X86_MN_PSIGNW,          PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psignd",           X86_MN_PSIGND,          PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmulhrsw",         X86_MN_PMULHRSW,        PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("permilps",         X86_MN_PERMILPS,        PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("permilpd",         X86_MN_PERMILPD,        PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("testps",           X86_MN_TESTPS,          PF_OVEX,        X86_ISET_AVX,       OP(Vx, Wx)),
    TABLE_ENTRY("testpd",           X86_MN_TESTPD,          PF_OVEX,        X86_ISET_AVX,       OP(Vx, Wx)),

    /* 10h */
    TABLE_ENTRY("pblendvb",         X86_MN_PBLENDVB,        PF_NONE,        X86_ISET_SSE41,     OP(Vdq, Wdq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("cvtph2ps",         X86_MN_CVTPH2PS,        PF_VEX,         X86_ISET_F16C,      OP(Vx, Wx, Ib)),
    TABLE_ENTRY("blendvps",         X86_MN_BLENDVPS,        PF_NONE,        X86_ISET_SSE41,     OP(Vdq, Wdq)),
    TABLE_ENTRY("blendvpd",         X86_MN_BLENDVPD,        PF_NONE,        X86_ISET_SSE41,     OP(Vdq, Wdq)),
    TABLE_ENTRY("permps",           X86_MN_PERMPS,          PF_VEX,         X86_ISET_AVX,       OP(Vqq, Hqq, Wqq)),
    TABLE_ENTRY("ptest",            X86_MN_PTEST,           PF_VEX,         X86_ISET_SSE41,     OP(Vx, Wx)),

    TABLE_ENTRY("broadcastss",      X86_MN_BROADCASTSS,     PF_OVEX,        X86_ISET_AVX,       OP(Vx, Wd)),
    TABLE_ENTRY("broadcastsd",      X86_MN_BROADCASTSD,     PF_OVEX,        X86_ISET_AVX,       OP(Vqq, Wq)),
    TABLE_ENTRY("broadcastf128",    X86_MN_BROADCASTF128,   PF_OVEX,        X86_ISET_AVX,       OP(Vqq, Mdq)),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY("pabsb",            X86_MN_PABSB,           PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Wx)),
    TABLE_ENTRY("pabsw",            X86_MN_PABSW,           PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Wx)),
    TABLE_ENTRY("pabsd",            X86_MN_PABSD,           PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Wx)),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_ESCAPE(66_0F_38_20),
    TABLE_ENTRY_ESCAPE(66_0F_38_21),
    TABLE_ENTRY_ESCAPE(66_0F_38_22),
    TABLE_ENTRY_ESCAPE(66_0F_38_23),
    TABLE_ENTRY_ESCAPE(66_0F_38_24),
    TABLE_ENTRY_ESCAPE(66_0F_38_25),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY("pmuldq",           X86_MN_PMULDQ,          PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pcmpeqq",          X86_MN_PCMPEQQ,         PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("movntdqa",         X86_MN_MOVNTDQA,        PF_VEX,         X86_ISET_SSE41,     OP(Vx, Mx)),
    TABLE_ENTRY("packusdw",         X86_MN_PACKUSDW,        PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("maskmovps",        X86_MN_MASKMOVPS,       PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Mx)),
    TABLE_ENTRY("maskmovpd",        X86_MN_MASKMOVPD,       PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Mx)),
    TABLE_ENTRY("maskmovps",        X86_MN_MASKMOVPS,       PF_OVEX,        X86_ISET_AVX,       OP(Mx, Hx, Vx)),
    TABLE_ENTRY("maskmovpd",        X86_MN_MASKMOVPD,       PF_OVEX,        X86_ISET_AVX,       OP(Mx, Hx, Vx)),

    /* 30h */
    TABLE_ENTRY_ESCAPE(66_0F_38_30),
    TABLE_ENTRY_ESCAPE(66_0F_38_31),
    TABLE_ENTRY_ESCAPE(66_0F_38_32),
    TABLE_ENTRY_ESCAPE(66_0F_38_33),
    TABLE_ENTRY_ESCAPE(66_0F_38_34),
    TABLE_ENTRY_ESCAPE(66_0F_38_35),

    /* 36h */
    TABLE_ENTRY("permd",            X86_MN_PERMD,           PF_OVEX,        X86_ISET_AVX,       OP(Vqq, Hqq, Wqq)),
    TABLE_ENTRY("pcmpgtq",          X86_MN_PCMPGTQ,         PF_VEX,         X86_ISET_SSE42,     OP(Vx, Hx, Wx)),

    TABLE_ENTRY("pminsb",           X86_MN_PMINSB,          PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pminsd",           X86_MN_PMINSD,          PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pminuw",           X86_MN_PMINUW,          PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pminud",           X86_MN_PMINUD,          PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmaxsb",           X86_MN_PMAXSB,          PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmaxsd",           X86_MN_PMAXSD,          PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmaxuw",           X86_MN_PMAXUW,          PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("pmaxud",           X86_MN_PMAXUD,          PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),

    /* 40h */
    TABLE_ENTRY("pmulld",           X86_MN_PMULLD,          PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx)),
    TABLE_ENTRY("phminposuw",       X86_MN_PHMINPOSUW,      PF_VEX,         X86_ISET_SSE41,     OP(Vdq, Wdq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 45h: operand size */
    TABLE_ENTRY_ESCAPE(66_0F_38_45),
    
    TABLE_ENTRY("psravd",           X86_MN_PSRAVD,          PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Wx)),
    
    /* 47h: operand size */
    TABLE_ENTRY_ESCAPE(66_0F_38_47),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY("pbroadcastd",      X86_MN_PBROADCASTD,     PF_OVEX,        X86_ISET_AVX,       OP(Vx, Wx)),
    TABLE_ENTRY("pbroadcastq",      X86_MN_PBROADCASTQ,     PF_OVEX,        X86_ISET_AVX,       OP(Vx, Wx)),
    TABLE_ENTRY("broadcasti128",    X86_MN_BROADCASTI128,   PF_OVEX,        X86_ISET_AVX,       OP(Vqq, Mdq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY("pbroadcastb",      X86_MN_PBROADCASTB,     PF_OVEX,        X86_ISET_AVX,       OP(Vx, Wx)),
    TABLE_ENTRY("pbroadcastw",      X86_MN_PBROADCASTW,     PF_OVEX,        X86_ISET_AVX,       OP(Vx, Wx)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY("invept",           X86_MN_INVEPT,          PF_NONE,        X86_ISET_VMX,       OP(Gy, Mdq)),
    TABLE_ENTRY("invvpid",          X86_MN_INVVPID,         PF_NONE,        X86_ISET_VMX,       OP(Gy, Mdq)),
    TABLE_ENTRY("invpcid",          X86_MN_INVPCID,         PF_NONE,        X86_ISET_VMX,       OP(Gy, Mdq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(66_0F_38_8C),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(66_0F_38_8E),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY_ESCAPE(66_0F_38_90),
    TABLE_ENTRY_ESCAPE(66_0F_38_91),
    TABLE_ENTRY_ESCAPE(66_0F_38_92),
    TABLE_ENTRY_ESCAPE(66_0F_38_93),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(66_0F_38_96),
    TABLE_ENTRY_ESCAPE(66_0F_38_97),

    TABLE_ENTRY_ESCAPE(66_0F_38_98),
    TABLE_ENTRY_ESCAPE(66_0F_38_99),
    TABLE_ENTRY_ESCAPE(66_0F_38_9A),
    TABLE_ENTRY_ESCAPE(66_0F_38_9B),
    TABLE_ENTRY_ESCAPE(66_0F_38_9C),
    TABLE_ENTRY_ESCAPE(66_0F_38_9D),
    TABLE_ENTRY_ESCAPE(66_0F_38_9E),
    TABLE_ENTRY_ESCAPE(66_0F_38_9F),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(66_0F_38_A6),
    TABLE_ENTRY_ESCAPE(66_0F_38_A7),

    TABLE_ENTRY_ESCAPE(66_0F_38_A8),
    TABLE_ENTRY_ESCAPE(66_0F_38_A9),
    TABLE_ENTRY_ESCAPE(66_0F_38_AA),
    TABLE_ENTRY_ESCAPE(66_0F_38_AB),
    TABLE_ENTRY_ESCAPE(66_0F_38_AC),
    TABLE_ENTRY_ESCAPE(66_0F_38_AD),
    TABLE_ENTRY_ESCAPE(66_0F_38_AE),
    TABLE_ENTRY_ESCAPE(66_0F_38_AF),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(66_0F_38_B6),
    TABLE_ENTRY_ESCAPE(66_0F_38_B7),

    TABLE_ENTRY_ESCAPE(66_0F_38_B8),
    TABLE_ENTRY_ESCAPE(66_0F_38_B9),
    TABLE_ENTRY_ESCAPE(66_0F_38_BA),
    TABLE_ENTRY_ESCAPE(66_0F_38_BB),
    TABLE_ENTRY_ESCAPE(66_0F_38_BC),
    TABLE_ENTRY_ESCAPE(66_0F_38_BD),
    TABLE_ENTRY_ESCAPE(66_0F_38_BE),
    TABLE_ENTRY_ESCAPE(66_0F_38_BF),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("aesimc",           X86_MN_AESIMC,          PF_VEX128,      X86_ISET_AESNI,     OP(Vdq, Wdq)),
    TABLE_ENTRY("aesenc",           X86_MN_AESENC,          PF_VEX128,      X86_ISET_AESNI,     OP(Vdq, Hdq, Wdq)),
    TABLE_ENTRY("aesenclast",       X86_MN_AESENCLAST,      PF_VEX128,      X86_ISET_AESNI,     OP(Vdq, Hdq, Wdq)),
    TABLE_ENTRY("aesdec",           X86_MN_AESDEC,          PF_VEX128,      X86_ISET_AESNI,     OP(Vdq, Hdq, Wdq)),
    TABLE_ENTRY("aesdeclast",       X86_MN_AESDECLAST,      PF_VEX128,      X86_ISET_AESNI,     OP(Vdq, Hdq, Wdq)),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY("movbe",            X86_MN_MOVBE,           PF_NONE,        X86_ISET_GP,        OP(Gw, Mw)),
    TABLE_ENTRY("movbe",            X86_MN_MOVBE,           PF_NONE,        X86_ISET_GP,        OP(Mw, Gw)),
    TABLE_ENTRY_INVALID(),

    /* F3h: group 17; vex prefix is required */
    TABLE_ENTRY_ESCAPE(0F_38_F3),
    TABLE_ENTRY_INVALID(),
    
    /* F5h: operand size */
    TABLE_ENTRY_ESCAPE(66_0F_38_F5),

    TABLE_ENTRY("adcx",             X86_MN_ADCX,            PF_NONE,        X86_ISET_ADX,       OP(Gy, Ey)),
    TABLE_ENTRY("shlx",             X86_MN_SHLX,            PF_OVEX,        X86_ISET_BMI2,      OP(Gy, Ey, By)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(66_0F_38)

TABLE_BEGIN(66_0F_38_20)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovsxbw",         X86_MN_PMOVSXBW,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovsxbw",         X86_MN_PMOVSXBW,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss))

TABLE_END(66_0F_38_20)

TABLE_BEGIN(66_0F_38_21)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovsxbd",         X86_MN_PMOVSXBD,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovsxbd",         X86_MN_PMOVSXBD,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss))

TABLE_END(66_0F_38_21)

TABLE_BEGIN(66_0F_38_22)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovsxbq",         X86_MN_PMOVSXBQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovsxbq",         X86_MN_PMOVSXBQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss))

TABLE_END(66_0F_38_22)

TABLE_BEGIN(66_0F_38_23)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovsxwd",         X86_MN_PMOVSXWD,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovsxwd",         X86_MN_PMOVSXWD,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss)),

TABLE_END(66_0F_38_23)

TABLE_BEGIN(66_0F_38_24)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovsxwq",         X86_MN_PMOVSXWQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovsxwq",         X86_MN_PMOVSXWQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss))

TABLE_END(66_0F_38_24)

TABLE_BEGIN(66_0F_38_25)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovsxdq",         X86_MN_PMOVSXDQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovsxdq",         X86_MN_PMOVSXDQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss))

TABLE_END(66_0F_38_25)

TABLE_BEGIN(66_0F_38_30)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovzxbw",         X86_MN_PMOVZXBW,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovzxbw",         X86_MN_PMOVZXBW,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss))

TABLE_END(66_0F_38_30)

TABLE_BEGIN(66_0F_38_31)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovzxbd",         X86_MN_PMOVZXBD,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovzxbd",         X86_MN_PMOVZXBD,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss))

TABLE_END(66_0F_38_31)

TABLE_BEGIN(66_0F_38_32)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovzxbq",         X86_MN_PMOVZXBQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovzxbq",         X86_MN_PMOVZXBQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss))

TABLE_END(66_0F_38_32)

TABLE_BEGIN(66_0F_38_33)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovzxwd",         X86_MN_PMOVZXWD,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovzxwd",         X86_MN_PMOVZXWD,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss)),

TABLE_END(66_0F_38_33)

TABLE_BEGIN(66_0F_38_34)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovzxwq",         X86_MN_PMOVZXWQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovzxwq",         X86_MN_PMOVZXWQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss))

TABLE_END(66_0F_38_34)

TABLE_BEGIN(66_0F_38_35)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pmovzxdq",         X86_MN_PMOVZXDQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Moq)),
    TABLE_ENTRY("pmovzxdq",         X86_MN_PMOVZXDQ,        PF_VEX,     X86_ISET_SSE41,     OP(Vx, Uss))

TABLE_END(66_0F_38_35)

TABLE_BEGIN(66_0F_38_45)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("psrlvd",           X86_MN_PSRLVD,          PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psrlvq",           X86_MN_PSRLVQ,          PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_45)

TABLE_BEGIN(66_0F_38_47)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("psllvd",           X86_MN_PSLLVD,          PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("psllvq",           X86_MN_PSLLVQ,          PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_47)

TABLE_BEGIN(66_0F_38_8C)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("pmaskmovd",        X86_MN_PMASKMOVD,       PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Mx)),
    TABLE_ENTRY("pmaskmovq",        X86_MN_PMASKMOVQ,       PF_OVEX,        X86_ISET_AVX,       OP(Vx, Hx, Mx))

TABLE_END(66_0F_38_8C)

TABLE_BEGIN(66_0F_38_8E)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("pmaskmovd",        X86_MN_PMASKMOVD,       PF_OVEX,        X86_ISET_AVX,       OP(Mx, Hx, Vx)),
    TABLE_ENTRY("pmaskmovq",        X86_MN_PMASKMOVQ,       PF_OVEX,        X86_ISET_AVX,       OP(Mx, Hx, Vx))

TABLE_END(66_0F_38_8E)

TABLE_BEGIN(66_0F_38_90)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("gatherdd",         X86_MN_GATHERDD,        PF_OVEX | PF_VSIB_L,        X86_ISET_AVX,       OP(Vx, Wd, Hx)),
    TABLE_ENTRY("gatherdq",         X86_MN_GATHERDQ,        PF_OVEX | PF_VSIB_X,        X86_ISET_AVX,       OP(Vx, Wd, Hx))

TABLE_END(66_0F_38_90)

TABLE_BEGIN(66_0F_38_91)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("gatherqd",         X86_MN_GATHERQD,        PF_OVEX | PF_VSIB_L,        X86_ISET_AVX,       OP(Vx, Wq, Hx)),
    TABLE_ENTRY("gatherqq",         X86_MN_GATHERQQ,        PF_OVEX | PF_VSIB_L,        X86_ISET_AVX,       OP(Vx, Wq, Hx))

TABLE_END(66_0F_38_91)

TABLE_BEGIN(66_0F_38_92)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("gatherdps",        X86_MN_GATHERDPS,       PF_OVEX | PF_VSIB_L,        X86_ISET_AVX,       OP(Vx, Wd, Hx)),
    TABLE_ENTRY("gatherdpd",        X86_MN_GATHERDPD,       PF_OVEX | PF_VSIB_X,        X86_ISET_AVX,       OP(Vx, Wd, Hx))

TABLE_END(66_0F_38_92)

TABLE_BEGIN(66_0F_38_93)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("gatherqps",        X86_MN_GATHERQPS,       PF_OVEX | PF_VSIB_L,        X86_ISET_AVX,       OP(Vx, Wq, Hx)),
    TABLE_ENTRY("gatherqpd",        X86_MN_GATHERQPD,       PF_OVEX | PF_VSIB_L,        X86_ISET_AVX,       OP(Vx, Wq, Hx))

TABLE_END(66_0F_38_93)

TABLE_BEGIN(66_0F_38_96)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmaddsub132ps",    X86_MN_FMADDSUB132PS,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmaddsub132pd",    X86_MN_FMADDSUB132PD,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_96)

TABLE_BEGIN(66_0F_38_97)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsubadd132ps",    X86_MN_FMSUBADD132PS,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmsubadd132pd",    X86_MN_FMSUBADD132PD,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_97)

TABLE_BEGIN(66_0F_38_98)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmadd132ps",       X86_MN_FMADD132PS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmadd132pd",       X86_MN_FMADD132PD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_98)

TABLE_BEGIN(66_0F_38_99)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmadd132ss",       X86_MN_FMADD132SS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmadd132sd",       X86_MN_FMADD132SD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_99)

TABLE_BEGIN(66_0F_38_9A)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsub132ps",       X86_MN_FMSUB132PS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmsub132pd",       X86_MN_FMSUB132PD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_9A)

TABLE_BEGIN(66_0F_38_9B)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsub132ss",       X86_MN_FMSUB132SS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmsub132sd",       X86_MN_FMSUB132SD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_9B)

TABLE_BEGIN(66_0F_38_9C)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmadd132ps",      X86_MN_FNMADD132PS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmadd132pd",      X86_MN_FNMADD132PD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_9C)

TABLE_BEGIN(66_0F_38_9D)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmadd132ss",      X86_MN_FNMADD132SS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmadd132sd",      X86_MN_FNMADD132SD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_9D)

TABLE_BEGIN(66_0F_38_9E)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmsub132ps",      X86_MN_FNMSUB132PS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmsub132pd",      X86_MN_FNMSUB132PD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_9E)

TABLE_BEGIN(66_0F_38_9F)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmsub132ss",      X86_MN_FNMSUB132SS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmsub132sd",      X86_MN_FNMSUB132SD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_9F)

TABLE_BEGIN(66_0F_38_A6)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmaddsub213ps",    X86_MN_FMADDSUB213PS,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmaddsub213pd",    X86_MN_FMADDSUB213PD,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_A6)

TABLE_BEGIN(66_0F_38_A7)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsubadd213ps",    X86_MN_FMSUBADD213PS,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmsubadd213pd",    X86_MN_FMSUBADD213PD,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_A7)

TABLE_BEGIN(66_0F_38_A8)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmadd213ps",       X86_MN_FMADD213PS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmadd213pd",       X86_MN_FMADD213PD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_A8)

TABLE_BEGIN(66_0F_38_A9)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmadd213ss",       X86_MN_FMADD213SS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmadd213sd",       X86_MN_FMADD213SD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_A9)

TABLE_BEGIN(66_0F_38_AA)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsub213ps",       X86_MN_FMSUB213PS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmsub213pd",       X86_MN_FMSUB213PD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_AA)

TABLE_BEGIN(66_0F_38_AB)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsub213ss",       X86_MN_FMSUB213SS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmsub213sd",       X86_MN_FMSUB213SD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_AB)

TABLE_BEGIN(66_0F_38_AC)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmadd213ps",      X86_MN_FNMADD213PS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmadd213pd",      X86_MN_FNMADD213PD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_AC)

TABLE_BEGIN(66_0F_38_AD)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmadd213ss",      X86_MN_FNMADD213SS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmadd213sd",      X86_MN_FNMADD213SD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_AD)

TABLE_BEGIN(66_0F_38_AE)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmsub213ps",      X86_MN_FNMSUB213PS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmsub213pd",      X86_MN_FNMSUB213PD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_AE)

TABLE_BEGIN(66_0F_38_AF)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmsub213ss",      X86_MN_FNMSUB213SS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmsub213sd",      X86_MN_FNMSUB213SD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_AF)

TABLE_BEGIN(66_0F_38_B6)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmaddsub231ps",    X86_MN_FMADDSUB231PS,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmaddsub231pd",    X86_MN_FMADDSUB231PD,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_B6)

TABLE_BEGIN(66_0F_38_B7)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsubadd231ps",    X86_MN_FMSUBADD231PS,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmsubadd231pd",    X86_MN_FMSUBADD231PD,   PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_B7)

TABLE_BEGIN(66_0F_38_B8)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmadd231ps",       X86_MN_FMADD231PS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmadd231pd",       X86_MN_FMADD231PD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_B8)

TABLE_BEGIN(66_0F_38_B9)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmadd231ss",       X86_MN_FMADD231SS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmadd231sd",       X86_MN_FMADD231SD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_B9)

TABLE_BEGIN(66_0F_38_BA)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsub231ps",       X86_MN_FMSUB231PS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmsub231pd",       X86_MN_FMSUB231PD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_BA)

TABLE_BEGIN(66_0F_38_BB)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsub231ss",       X86_MN_FMSUB231SS,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fmsub231sd",       X86_MN_FMSUB231SD,      PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_BB)

TABLE_BEGIN(66_0F_38_BC)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmadd231ps",      X86_MN_FNMADD231PS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmadd231pd",      X86_MN_FNMADD231PD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_BC)

TABLE_BEGIN(66_0F_38_BD)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmadd231ss",      X86_MN_FNMADD231SS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmadd231sd",      X86_MN_FNMADD231SD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_BD)

TABLE_BEGIN(66_0F_38_BE)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmsub231ps",      X86_MN_FNMSUB231PS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmsub231pd",      X86_MN_FNMSUB231PD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_BE)

TABLE_BEGIN(66_0F_38_BF)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmsub231ss",      X86_MN_FNMSUB231SS,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx)),
    TABLE_ENTRY("fnmsub231sd",      X86_MN_FNMSUB231SD,     PF_OVEX,        X86_ISET_FMA,       OP(Vx, Hx, Wx))

TABLE_END(66_0F_38_BF)

TABLE_BEGIN(66_0F_38_F5)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("wrussd",           X86_MN_WRUSSD,          PF_NONE,        X86_ISET_CET,       OP(Md, Gd)),
    TABLE_ENTRY("wrussd",           X86_MN_WRUSSD,          PF_NONE,        X86_ISET_CET,       OP(Md, Gd)),
    TABLE_ENTRY("wrussq",           X86_MN_WRUSSQ,          PF_NONE,        X86_ISET_CET,       OP(Mq, Gq))

TABLE_END(66_0F_38_F5)

TABLE_BEGIN(66_0F_3A)

    /* 00h */
    TABLE_ENTRY("permq",            X86_MN_PERMQ,           PF_OVEX,        X86_ISET_AVX2,      OP(Vqq, Wqq, Ib)),
    TABLE_ENTRY("permpd",           X86_MN_PERMPD,          PF_OVEX,        X86_ISET_AVX2,      OP(Vqq, Wqq, Ib)),
    TABLE_ENTRY("pblendd",          X86_MN_PBLENDD,         PF_OVEX,        X86_ISET_AVX2,      OP(Vx, Hx, Wx, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("permilps",         X86_MN_PERMILPS,        PF_OVEX,        X86_ISET_AVX2,      OP(Vx, Wx, Ib)),
    TABLE_ENTRY("permilpd",         X86_MN_PERMILPD,        PF_OVEX,        X86_ISET_AVX2,      OP(Vx, Wx, Ib)),
    TABLE_ENTRY("perm2f128",        X86_MN_PERM2F128,       PF_OVEX,        X86_ISET_AVX2,      OP(Vqq, Hqq, Wqq, Ib)),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY("roundps",          X86_MN_ROUNDPS,         PF_VEX,         X86_ISET_SSE41,     OP(Vx, Wx, Ib)),
    TABLE_ENTRY("roundpd",          X86_MN_ROUNDPD,         PF_VEX,         X86_ISET_SSE41,     OP(Vx, Wx, Ib)),
    TABLE_ENTRY("roundss",          X86_MN_ROUNDSS,         PF_VEX128,      X86_ISET_SSE41,     OP(Vss, Wss, Ib)),
    TABLE_ENTRY("roundsd",          X86_MN_ROUNDSD,         PF_VEX128,      X86_ISET_SSE41,     OP(Vsd, Wq, Ib)),
    TABLE_ENTRY("blendps",          X86_MN_BLENDPS,         PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx, Ib)),
    TABLE_ENTRY("blendpd",          X86_MN_BLENDPD,         PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx, Ib)),
    TABLE_ENTRY("pblendw",          X86_MN_PBLENDW,         PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx, Ib)),
    TABLE_ENTRY("palignr",          X86_MN_PALIGNR,         PF_VEX,         X86_ISET_SSSE3,     OP(Vx, Hx, Wx, Ib)),

    /* 10h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(66_0F_3A_14),
    TABLE_ENTRY_ESCAPE(66_0F_3A_15),
    TABLE_ENTRY_ESCAPE(66_0F_3A_16),
    TABLE_ENTRY("extractps",        X86_MN_EXTRACTPS,       PF_VEX,         X86_ISET_SSE41,     OP(Ed, Vdq, Ib)),

    TABLE_ENTRY("insertf128",       X86_MN_INSERTF128,      PF_VEX256,      X86_ISET_AVX,       OP(Vqq, Hqq, Wqq, Ib)),
    TABLE_ENTRY("extractf128",      X86_MN_EXTRACTF128,     PF_VEX256,      X86_ISET_AVX,       OP(Wdq, Vqq, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("cvtps2ph",         X86_MN_CVTPS2PH,        PF_OVEX,        X86_ISET_F16C,      OP(Woq, Vx, Ib)), // Woq
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_ESCAPE(66_0F_3A_20),
    TABLE_ENTRY_ESCAPE(66_0F_3A_21),
    TABLE_ENTRY_ESCAPE(66_0F_3A_22),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY("inserti128",       X86_MN_INSERTI128,      PF_VEX256,      X86_ISET_AVX2,      OP(Vqq, Hqq, Wqq, Ib)),
    TABLE_ENTRY("extracti128",      X86_MN_EXTRACTI128,     PF_VEX256,      X86_ISET_AVX2,      OP(Wdq, Vqq, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY("dpps",             X86_MN_DPPS,            PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx, Ib)), 
    TABLE_ENTRY("dppd",             X86_MN_DPPD,            PF_VEX,         X86_ISET_SSE41,     OP(Vdq, Hdq, Wdq, Ib)),
    TABLE_ENTRY("mpsadbw",          X86_MN_MPSADBW,         PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pclmulqdq",        X86_MN_PCLMULQDQ,       PF_VEX,         X86_ISET_PCLMULQDQ, OP(Vdq, Hdq, Wdq, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("perm2i128",        X86_MN_PERM2I128,       PF_VEX256,      X86_ISET_AVX2,      OP(Vqq, Hqq, Wqq, Ib)),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("blendvps",         X86_MN_BLENDVPS,        PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx, Lx)), 
    TABLE_ENTRY("blendvpd",         X86_MN_BLENDVPD,        PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx, Lx)), 
    TABLE_ENTRY("pblendvb",         X86_MN_PBLENDVB,        PF_VEX,         X86_ISET_SSE41,     OP(Vx, Hx, Wx, Lx)), 
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(66_0F_3A_5C),
    TABLE_ENTRY_ESCAPE(66_0F_3A_5D),
    TABLE_ENTRY_ESCAPE(66_0F_3A_5E),
    TABLE_ENTRY_ESCAPE(66_0F_3A_5F),

    /* 60h */
    TABLE_ENTRY("pcmpestrm",        X86_MN_PCMPESTRM,       PF_VEX,         X86_ISET_SSE42,     OP(Vdq, Wdq, Ib)),
    TABLE_ENTRY("pcmpestri",        X86_MN_PCMPESTRI,       PF_VEX,         X86_ISET_SSE42,     OP(Vdq, Wdq, Ib)),
    TABLE_ENTRY("pcmpistrm",        X86_MN_PCMPISTRM,       PF_VEX,         X86_ISET_SSE42,     OP(Vdq, Wdq, Ib)),
    TABLE_ENTRY("pcmpistri",        X86_MN_PCMPISTRI,       PF_VEX,         X86_ISET_SSE42,     OP(Vdq, Wdq, Ib)),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_ESCAPE(66_0F_3A_68),
    TABLE_ENTRY_ESCAPE(66_0F_3A_69),
    TABLE_ENTRY_ESCAPE(66_0F_3A_6A),
    TABLE_ENTRY_ESCAPE(66_0F_3A_6B),
    TABLE_ENTRY_ESCAPE(66_0F_3A_6C),
    TABLE_ENTRY_ESCAPE(66_0F_3A_6D),
    TABLE_ENTRY_ESCAPE(66_0F_3A_6E),
    TABLE_ENTRY_ESCAPE(66_0F_3A_6F),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_ESCAPE(66_0F_3A_78),
    TABLE_ENTRY_ESCAPE(66_0F_3A_79),
    TABLE_ENTRY_ESCAPE(66_0F_3A_7A),
    TABLE_ENTRY_ESCAPE(66_0F_3A_7B),
    TABLE_ENTRY_ESCAPE(66_0F_3A_7C),
    TABLE_ENTRY_ESCAPE(66_0F_3A_7D),
    TABLE_ENTRY_ESCAPE(66_0F_3A_7E),
    TABLE_ENTRY_ESCAPE(66_0F_3A_7F),

    /* 80h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("aeskeygenassist",      X86_MN_AESKEYGENASSIST,     PF_VEX,         X86_ISET_AESNI,     OP(Vdq, Wdq, Ib)),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(66_0F_3A)

TABLE_BEGIN(66_0F_3A_14)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pextrb",       X86_MN_PEXTRB,          PF_VEX128,          X86_ISET_SSE41,     OP(Mb, Vdq, Ib)),
    TABLE_ENTRY("pextrb",       X86_MN_PEXTRB,          PF_VEX128,          X86_ISET_SSE41,     OP(Rb, Vdq, Ib))

TABLE_END(66_0F_3A_14)

TABLE_BEGIN(66_0F_3A_15)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pextrw",       X86_MN_PEXTRW,          PF_VEX128,          X86_ISET_SSE41,     OP(Mw, Vdq, Ib)),
    TABLE_ENTRY("pextrw",       X86_MN_PEXTRW,          PF_VEX128,          X86_ISET_SSE41,     OP(Rw, Vdq, Ib))

TABLE_END(66_0F_3A_15)

TABLE_BEGIN(66_0F_3A_16)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("pextrd",       X86_MN_PEXTRD,          PF_VEX128,          X86_ISET_SSE41,     OP(Ey, Vdq, Ib)),
    TABLE_ENTRY("pextrd",       X86_MN_PEXTRD,          PF_VEX128,          X86_ISET_SSE41,     OP(Ey, Vdq, Ib)),
    TABLE_ENTRY("pextrq",       X86_MN_PEXTRQ,          PF_VEX128,          X86_ISET_SSE41,     OP(Ey, Vdq, Ib))

TABLE_END(66_0F_3A_16)

TABLE_BEGIN(66_0F_3A_20)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("pinsrb",       X86_MN_PINSRB,          PF_VEX128,          X86_ISET_SSE41,     OP(Vdq, Hdq, Mb, Ib)),
    TABLE_ENTRY("pinsrb",       X86_MN_PINSRB,          PF_VEX128,          X86_ISET_SSE41,     OP(Vdq, Hdq, Ry, Ib))

TABLE_END(66_0F_3A_20)

TABLE_BEGIN(66_0F_3A_21)

    /* modr/m byte mod field:  0 = !11b, 1 = 11b */
    TABLE_ENTRY("insertps",     X86_MN_INSERTPS,        PF_VEX128,          X86_ISET_SSE41,     OP(Vdq, Hdq, Md, Ib)),
    TABLE_ENTRY("insertps",     X86_MN_INSERTPS,        PF_VEX128,          X86_ISET_SSE41,     OP(Vdq, Hdq, Udq, Ib))

TABLE_END(66_0F_3A_21)

TABLE_BEGIN(66_0F_3A_22)

    /* operand size: 0 = 16-bits, 1 = 32-bits, 2 = 64-bits */
    TABLE_ENTRY("pinsrd",       X86_MN_PINSRD,          PF_VEX128,          X86_ISET_SSE41,     OP(Vdq, Hdq, Ey, Ib)),
    TABLE_ENTRY("pinsrd",       X86_MN_PINSRD,          PF_VEX128,          X86_ISET_SSE41,     OP(Vdq, Hdq, Ey, Ib)),
    TABLE_ENTRY("pinsrq",       X86_MN_PINSRQ,          PF_VEX128,          X86_ISET_SSE41,     OP(Vdq, Hdq, Ey, Ib))

TABLE_END(66_0F_3A_22)

#if 1

// FMA4!

TABLE_BEGIN(66_0F_3A_5C)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmaddsubps",   X86_MN_FMADDSUBPS,      PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fmaddsubps",   X86_MN_FMADDSUBPS,      PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_5C)

TABLE_BEGIN(66_0F_3A_5D)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmaddsubpd",   X86_MN_FMADDSUBPD,      PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fmaddsubpd",   X86_MN_FMADDSUBPD,      PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_5D)

TABLE_BEGIN(66_0F_3A_5E)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsubaddps",   X86_MN_FMSUBADDPS,      PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fmsubaddps",   X86_MN_FMSUBADDPS,      PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_5E)

TABLE_BEGIN(66_0F_3A_5F)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsubaddpd",   X86_MN_FMSUBADDPD,      PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fmsubaddpd",   X86_MN_FMSUBADDPD,      PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_5F)

TABLE_BEGIN(66_0F_3A_68)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmaddps",      X86_MN_FMADDPS,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fmaddps",      X86_MN_FMADDPS,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_68)

TABLE_BEGIN(66_0F_3A_69)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmaddpd",      X86_MN_FMADDPD,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fmaddpd",      X86_MN_FMADDPD,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_69)

TABLE_BEGIN(66_0F_3A_6A)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmaddss",      X86_MN_FMADDSS,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wd, Lx)),
    TABLE_ENTRY("fmaddss",      X86_MN_FMADDSS,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wd))

TABLE_END(66_0F_3A_6A)

TABLE_BEGIN(66_0F_3A_6B)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmaddsd",      X86_MN_FMADDSD,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wq, Lx)),
    TABLE_ENTRY("fmaddsd",      X86_MN_FMADDSD,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wq))

TABLE_END(66_0F_3A_6B)

TABLE_BEGIN(66_0F_3A_6C)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsubps",      X86_MN_FMSUBPS,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fmsubps",      X86_MN_FMSUBPS,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_6C)

TABLE_BEGIN(66_0F_3A_6D)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsubpd",      X86_MN_FMSUBPD,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fmsubpd",      X86_MN_FMSUBPD,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_6D)

TABLE_BEGIN(66_0F_3A_6E)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsubss",      X86_MN_FMSUBSS,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wd, Lx)),
    TABLE_ENTRY("fmsubss",      X86_MN_FMSUBSS,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wd))

TABLE_END(66_0F_3A_6E)

TABLE_BEGIN(66_0F_3A_6F)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fmsubsd",      X86_MN_FMSUBSD,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wq, Lx)),
    TABLE_ENTRY("fmsubsd",      X86_MN_FMSUBSD,         PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wq))

TABLE_END(66_0F_3A_6F)

TABLE_BEGIN(66_0F_3A_78)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmaddps",     X86_MN_FNMADDPS,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fnmaddps",     X86_MN_FNMADDPS,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_78)

TABLE_BEGIN(66_0F_3A_79)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmaddpd",     X86_MN_FNMADDPD,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fnmaddpd",     X86_MN_FNMADDPD,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_79)

TABLE_BEGIN(66_0F_3A_7A)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmaddss",     X86_MN_FNMADDSS,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wd, Lx)),
    TABLE_ENTRY("fnmaddss",     X86_MN_FNMADDSS,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wd))

TABLE_END(66_0F_3A_7A)

TABLE_BEGIN(66_0F_3A_7B)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmaddsd",     X86_MN_FNMADDSD,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wq, Lx)),
    TABLE_ENTRY("fnmaddsd",     X86_MN_FNMADDSD,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wq))

TABLE_END(66_0F_3A_7B)

TABLE_BEGIN(66_0F_3A_7C)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmsubps",     X86_MN_FNMSUBPS,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fnmsubps",     X86_MN_FNMSUBPS,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_7C)

TABLE_BEGIN(66_0F_3A_7D)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmsubpd",     X86_MN_FNMSUBPD,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("fnmsubpd",     X86_MN_FNMSUBPD,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wx))

TABLE_END(66_0F_3A_7D)

TABLE_BEGIN(66_0F_3A_7E)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmsubss",     X86_MN_FNMSUBSS,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wd, Lx)),
    TABLE_ENTRY("fnmsubss",     X86_MN_FNMSUBSS,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wd))

TABLE_END(66_0F_3A_7E)

TABLE_BEGIN(66_0F_3A_7F)

    /* operand size: 0 = vex.w0, 1 = vex.w1 */
    TABLE_ENTRY("fnmsubsd",     X86_MN_FNMSUBSD,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Wq, Lx)),
    TABLE_ENTRY("fnmsubsd",     X86_MN_FNMSUBSD,        PF_OVEX,            X86_ISET_FMA4,      OP(Vx, Hx, Lx, Wq))

TABLE_END(66_0F_3A_7F)

#endif

/****************************************************************************

    Three-byte tables - F2h mandatory prefix

****************************************************************************/

TABLE_BEGIN(F2_0F_38)

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 10h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY("crc32",        X86_MN_CRC32,       PF_NONE,    X86_ISET_SSE42,     OP(Gy, Eb)),
    TABLE_ENTRY("crc32",        X86_MN_CRC32,       PF_NONE,    X86_ISET_SSE42,     OP(Gy, Ev)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pdep",         X86_MN_PDEP,        PF_OVEX,    X86_ISET_BMI2,      OP(Gy, By, Ey)),
    TABLE_ENTRY("mulx",         X86_MN_MULX,        PF_OVEX,    X86_ISET_BMI2,      OP(By, Gy, rDX, Ey)),
    TABLE_ENTRY("shrx",         X86_MN_SHRX,        PF_OVEX,    X86_ISET_BMI2,      OP(Gy, Ey, By)),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F2_0F_38)

TABLE_BEGIN(F2_0F_3A)

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 10h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY("rorx",     X86_MN_RORX,    PF_OVEX,    X86_ISET_BMI2,  OP(Gy, Ey, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F2_0F_3A)

/****************************************************************************

    Three-byte tables - F3h mandatory prefix

****************************************************************************/

TABLE_BEGIN(F3_0F_38)

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 10h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pext",     X86_MN_PEXT,    PF_OVEX,    X86_ISET_BMI2,      OP(Gy, By, Ey)),
    TABLE_ENTRY("adox",     X86_MN_ADOX,    PF_NONE,    X86_ISET_ADX,       OP(Gy, Ey)),
    TABLE_ENTRY("sarx",     X86_MN_SARX,    PF_OVEX,    X86_ISET_BMI2,      OP(Gy, Ey, By)),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F3_0F_38)

TABLE_BEGIN(F3_0F_3A)

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 10h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY("rorx",     X86_MN_RORX,    PF_OVEX,    X86_ISET_BMI2,  OP(Gy, Ey, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(F3_0F_3A)

/****************************************************************************

    XOP tables

****************************************************************************/

TABLE_BEGIN(XOP_8)

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 10h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vpmacssww",    X86_MN_VPMACSSWW,   PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),
    TABLE_ENTRY("vpmacsswd",    X86_MN_VPMACSSWD,   PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),
    TABLE_ENTRY("vpmacssdql",   X86_MN_VPMACSSDQL,  PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vpmacssdd",    X86_MN_VPMACSSDD,   PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),
    TABLE_ENTRY("vpmacssdqh",   X86_MN_VPMACSSDQH,  PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),

    /* 90h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vpmacsww",     X86_MN_VPMACSWW,    PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),
    TABLE_ENTRY("vpmacswd",     X86_MN_VPMACSWD,    PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),
    TABLE_ENTRY("vpmacsdql",    X86_MN_VPMACSDQL,   PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vpmacsdd",     X86_MN_VPMACSDD,    PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),
    TABLE_ENTRY("vpmacsdqh",    X86_MN_VPMACSDQH,   PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(XOP_8_A2),
    TABLE_ENTRY_ESCAPE(XOP_8_A3),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vpmadcsswd",   X86_MN_VPMADCSSWD,  PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vpmadcswd",    X86_MN_VPMADCSWD,   PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C0h */
    TABLE_ENTRY("vprotb",       X86_MN_VPROTB,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Ib)),
    TABLE_ENTRY("vprotw",       X86_MN_VPROTW,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Ib)),
    TABLE_ENTRY("vprotd",       X86_MN_VPROTD,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Ib)),
    TABLE_ENTRY("vprotq",       X86_MN_VPROTQ,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Ib)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vpcom*b",      X86_MN_VPCOMB,      PF_XOPCC,   X86_ISET_XOP,   OP(Vss, Hss, Wss, Ib)),
    TABLE_ENTRY("vpcom*w",      X86_MN_VPCOMW,      PF_XOPCC,   X86_ISET_XOP,   OP(Vss, Hss, Wss, Ib)),
    TABLE_ENTRY("vpcom*d",      X86_MN_VPCOMD,      PF_XOPCC,   X86_ISET_XOP,   OP(Vss, Hss, Wss, Ib)),
    TABLE_ENTRY("vpcom*q",      X86_MN_VPCOMQ,      PF_XOPCC,   X86_ISET_XOP,   OP(Vss, Hss, Wss, Ib)),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vpcom*ub",     X86_MN_VPCOMUB,     PF_XOPCC,   X86_ISET_XOP,   OP(Vss, Hss, Wss, Ib)),
    TABLE_ENTRY("vpcom*uw",     X86_MN_VPCOMUW,     PF_XOPCC,   X86_ISET_XOP,   OP(Vss, Hss, Wss, Ib)),
    TABLE_ENTRY("vpcom*ud",     X86_MN_VPCOMUD,     PF_XOPCC,   X86_ISET_XOP,   OP(Vss, Hss, Wss, Ib)),
    TABLE_ENTRY("vpcom*uq",     X86_MN_VPCOMUQ,     PF_XOPCC,   X86_ISET_XOP,   OP(Vss, Hss, Wss, Ib)),

    /* F0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(XOP_8)

TABLE_BEGIN(XOP_8_A2)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vpcmov",           X86_MN_VPCMOV,          PF_NONE,    X86_ISET_XOP,   OP(Vx, Hx, Wx, Lx)),
    TABLE_ENTRY("vpcmov",           X86_MN_VPCMOV,          PF_NONE,    X86_ISET_XOP,   OP(Vx, Hx, Lx, Wx))

TABLE_END(XOP_8_A2)

TABLE_BEGIN(XOP_8_A3)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vpperm",           X86_MN_VPPERM,          PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss, Lss)),
    TABLE_ENTRY("vpperm",           X86_MN_VPPERM,          PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Lss, Wss))

TABLE_END(XOP_8_A3)

TABLE_BEGIN(XOP_9)

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(XOP_9_1),
    TABLE_ENTRY_ESCAPE(XOP_9_2),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 10h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(XOP_9_12),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY("vfrczps",          X86_MN_VFRCZPS,         PF_NONE,    X86_ISET_XOP,   OP(Vx, Wx)),
    TABLE_ENTRY("vfrczpd",          X86_MN_VFRCZPD,         PF_NONE,    X86_ISET_XOP,   OP(Vx, Wx)),
    TABLE_ENTRY("vfrczss",          X86_MN_VFRCZSS,         PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY("vfrczsd",          X86_MN_VFRCZSD,         PF_NONE,    X86_ISET_XOP,   OP(Vss, Wsd)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY_ESCAPE(XOP_9_90),
    TABLE_ENTRY_ESCAPE(XOP_9_91),
    TABLE_ENTRY_ESCAPE(XOP_9_92),
    TABLE_ENTRY_ESCAPE(XOP_9_93),
    TABLE_ENTRY_ESCAPE(XOP_9_94),
    TABLE_ENTRY_ESCAPE(XOP_9_95),
    TABLE_ENTRY_ESCAPE(XOP_9_96),
    TABLE_ENTRY_ESCAPE(XOP_9_97),

    TABLE_ENTRY_ESCAPE(XOP_9_98),
    TABLE_ENTRY_ESCAPE(XOP_9_99),
    TABLE_ENTRY_ESCAPE(XOP_9_9A),
    TABLE_ENTRY_ESCAPE(XOP_9_9B),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vphaddbw",         X86_MN_VPHADDBW,        PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY("vphaddbd",         X86_MN_VPHADDBD,        PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY("vphaddbq",         X86_MN_VPHADDBQ,        PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vphaddwd",         X86_MN_VPHADDWD,        PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY("vphaddwq",         X86_MN_VPHADDWQ,        PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vphadddq",         X86_MN_VPHADDDQ,        PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vphaddubwd",       X86_MN_VPHADDUBWD,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY("vphaddubd",        X86_MN_VPHADDUBD,       PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY("vphaddubq",        X86_MN_VPHADDUBQ,       PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vphadduwd",        X86_MN_VPHADDUWD,       PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY("vphadduwq",        X86_MN_VPHADDUWQ,       PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vphaddudq",        X86_MN_VPHADDUDQ,       PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("vphsubbw",         X86_MN_VPHSUBBW,        PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY("vphsubwd",         X86_MN_VPHSUBWD,        PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY("vphsubdq",         X86_MN_VPHSUBDQ,        PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(XOP_9)

TABLE_BEGIN(XOP_9_1)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("blcfill",          X86_MN_BLCFILL,     PF_NONE,    X86_ISET_XOP,   OP(By, Ey)),
    TABLE_ENTRY("blsfill",          X86_MN_BLSFILL,     PF_NONE,    X86_ISET_XOP,   OP(By, Ey)),
    TABLE_ENTRY("blcs",             X86_MN_BLCS,        PF_NONE,    X86_ISET_XOP,   OP(By, Ey)),
    TABLE_ENTRY("tzmsk",            X86_MN_TZMSK,       PF_NONE,    X86_ISET_XOP,   OP(By, Ey)),
    TABLE_ENTRY("blcic",            X86_MN_BLCIC,       PF_NONE,    X86_ISET_XOP,   OP(By, Ey)),
    TABLE_ENTRY("blcsic",           X86_MN_BLCSIC,      PF_NONE,    X86_ISET_XOP,   OP(By, Ey)),
    TABLE_ENTRY("t1mskc",           X86_MN_T1MSKC,      PF_NONE,    X86_ISET_XOP,   OP(By, Ey))

TABLE_END(XOP_9_1)

TABLE_BEGIN(XOP_9_2)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("blcmsk",           X86_MN_BLCMSK,      PF_NONE,    X86_ISET_XOP,   OP(By, Ey)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(XOP_9_2)

TABLE_BEGIN(XOP_9_12)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY("llwpcb",           X86_MN_LLWPCB,      PF_NONE,    X86_ISET_XOP,   OP(Ry)),
    TABLE_ENTRY("slwpcb",           X86_MN_SLWPCB,      PF_NONE,    X86_ISET_XOP,   OP(Ry)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(XOP_9_12)

TABLE_BEGIN(XOP_9_90)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vprotb",       X86_MN_VPROTB,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vprotb",       X86_MN_VPROTB,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_90)

TABLE_BEGIN(XOP_9_91)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vprotw",       X86_MN_VPROTW,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vprotw",       X86_MN_VPROTW,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_91)

TABLE_BEGIN(XOP_9_92)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vprotd",       X86_MN_VPROTD,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vprotd",       X86_MN_VPROTD,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_92)

TABLE_BEGIN(XOP_9_93)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vprotq",       X86_MN_VPROTQ,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vprotq",       X86_MN_VPROTQ,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_93)

TABLE_BEGIN(XOP_9_94)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vpshlb",       X86_MN_VPSHLB,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vpshlb",       X86_MN_VPSHLB,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_94)

TABLE_BEGIN(XOP_9_95)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vpshlw",       X86_MN_VPSHLW,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vpshlw",       X86_MN_VPSHLW,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_95)

TABLE_BEGIN(XOP_9_96)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vpshld",       X86_MN_VPSHLD,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vpshld",       X86_MN_VPSHLD,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_96)

TABLE_BEGIN(XOP_9_97)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vpshlq",       X86_MN_VPSHLQ,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vpshlq",       X86_MN_VPSHLQ,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_97)

TABLE_BEGIN(XOP_9_98)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vpshab",       X86_MN_VPSHAB,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vpshab",       X86_MN_VPSHAB,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_98)

TABLE_BEGIN(XOP_9_99)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vpshaw",       X86_MN_VPSHAW,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vpshaw",       X86_MN_VPSHAW,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_99)

TABLE_BEGIN(XOP_9_9A)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vpshad",       X86_MN_VPSHAD,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vpshad",       X86_MN_VPSHAD,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_9A)

TABLE_BEGIN(XOP_9_9B)

    /* operand size: 0 = xop.w0, 1 = xop.w1 */
    TABLE_ENTRY("vpshaq",       X86_MN_VPSHAQ,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Wss, Hss)),
    TABLE_ENTRY("vpshaq",       X86_MN_VPSHAQ,      PF_NONE,    X86_ISET_XOP,   OP(Vss, Hss, Wss))

TABLE_END(XOP_9_9B)

TABLE_BEGIN(XOP_A)

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 10h */
    TABLE_ENTRY("bextr",        X86_MN_BEXTR,       PF_NONE,    X86_ISET_XOP,   OP(Gy, Ey, Id)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_ESCAPE(XOP_A_12),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* A0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(XOP_A)

TABLE_BEGIN(XOP_A_12)

    /* modr/m byte reg/nnn field */

    /* 00h */
    TABLE_ENTRY("lwpins",           X86_MN_LWPINS,      PF_NONE,    X86_ISET_XOP,   OP(By, Ed, Id)),
    TABLE_ENTRY("lwpval",           X86_MN_LWPVAL,      PF_NONE,    X86_ISET_XOP,   OP(By, Ed, Id)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(XOP_A_12)

/****************************************************************************

    3DNow! table

****************************************************************************/

TABLE_BEGIN(0F_0F)

    /* 00h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pi2fw",        X86_MN_PI2FW,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY("pi2fd",        X86_MN_PI2FD,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 10h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pf2iw",        X86_MN_PF2IW,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY("pf2id",        X86_MN_PF2ID,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 20h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 30h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 40h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 50h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 60h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 70h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* 80h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfnacc",       X86_MN_PFNACC,      PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfpnacc",      X86_MN_PFPNACC,     PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),

    /* 90h */
    TABLE_ENTRY("pfcmpge",      X86_MN_PFCMPGE,     PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfmin",        X86_MN_PFMIN,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfrcp",        X86_MN_PFRCP,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY("pfrsqrt",      X86_MN_PFRSQRT,     PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfsub",        X86_MN_PFSUB,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfadd",        X86_MN_PFADD,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),

    /* A0h */
    TABLE_ENTRY("pfcmpgt",      X86_MN_PFCMPGT,     PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfmax",        X86_MN_PFMAX,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfrcpit1",     X86_MN_PFRCPIT1,    PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY("pfrsqit1",     X86_MN_PFRSQIT1,    PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfsubr",       X86_MN_PFSUBR,      PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfacc",        X86_MN_PFACC,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),

    /* B0h */
    TABLE_ENTRY("pfcmpeq",      X86_MN_PFCMPEQ,     PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfmul",        X86_MN_PFMUL,       PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pfrcpit2",     X86_MN_PFRCPIT2,    PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY("pmulhrw",      X86_MN_PMULHRW,     PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pswapd",       X86_MN_PSWAPD,      PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY("pavgusb",      X86_MN_PAVGUSB,     PF_NONE,    X86_ISET_3DNOW, OP(Pq, Qq)),

    /* C0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* D0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* E0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    /* F0h */
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),

    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID(),
    TABLE_ENTRY_INVALID()

TABLE_END(0F_0F)

/****************************************************************************

    Master table

****************************************************************************/

const x86_table_link_t x86_table_links[] =
{
    TABLE_LINK(1B, BYTE),
    TABLE_LINK(60, OSIZE),
    TABLE_LINK(61, OSIZE),
    TABLE_LINK(63, DMODE),
    TABLE_LINK(6D, OSIZE),
    TABLE_LINK(6F, OSIZE),
    TABLE_LINK(80, MODRM_REG),
    TABLE_LINK(81, MODRM_REG),
    TABLE_LINK(82, MODRM_REG),
    TABLE_LINK(83, MODRM_REG),
    TABLE_LINK(8F, MODRM_REG),
    TABLE_LINK(98, OSIZE),
    TABLE_LINK(99, OSIZE),
    TABLE_LINK(9C, OSIZE),
    TABLE_LINK(9D, OSIZE),
    TABLE_LINK(A5, OSIZE),
    TABLE_LINK(A7, OSIZE),
    TABLE_LINK(AB, OSIZE),
    TABLE_LINK(AD, OSIZE),
    TABLE_LINK(AF, OSIZE),
    TABLE_LINK(C0, MODRM_REG),
    TABLE_LINK(C1, MODRM_REG),
    TABLE_LINK(C6, MODRM_REG),
    TABLE_LINK(C7, MODRM_REG),
    TABLE_LINK(CF, OSIZE),
    TABLE_LINK(D0, MODRM_REG),
    TABLE_LINK(D1, MODRM_REG),
    TABLE_LINK(D2, MODRM_REG),
    TABLE_LINK(D3, MODRM_REG),
    TABLE_LINK(D8, MODRM_MOD),
    TABLE_LINK(D9, MODRM_MOD),
    TABLE_LINK(DA, MODRM_MOD),
    TABLE_LINK(DB, MODRM_MOD),
    TABLE_LINK(DC, MODRM_MOD),
    TABLE_LINK(DD, MODRM_MOD),
    TABLE_LINK(DE, MODRM_MOD),
    TABLE_LINK(DF, MODRM_MOD),
    TABLE_LINK(E3, ASIZE), 
    TABLE_LINK(F6, MODRM_REG),
    TABLE_LINK(F7, MODRM_REG),
    TABLE_LINK(FE, MODRM_REG),
    TABLE_LINK(FF, MODRM_REG),
    TABLE_LINK(D8_MOD_N11, MODRM_REG),
    TABLE_LINK(D8_MOD_11, FPU),
    TABLE_LINK(D9_MOD_N11, MODRM_REG),
    TABLE_LINK(D9_MOD_11, FPU),
    TABLE_LINK(DA_MOD_N11, MODRM_REG),
    TABLE_LINK(DA_MOD_11, FPU),
    TABLE_LINK(DB_MOD_N11, MODRM_REG),
    TABLE_LINK(DB_MOD_11, FPU),
    TABLE_LINK(DC_MOD_N11, MODRM_REG),
    TABLE_LINK(DC_MOD_11, FPU),
    TABLE_LINK(DD_MOD_N11, MODRM_REG),
    TABLE_LINK(DD_MOD_11, FPU),
    TABLE_LINK(DE_MOD_N11, MODRM_REG),
    TABLE_LINK(DE_MOD_11, FPU),
    TABLE_LINK(DF_MOD_N11, MODRM_REG), 
    TABLE_LINK(DF_MOD_11, FPU),

    TABLE_LINK(0F, BYTE),
    TABLE_LINK(0F_00, MODRM_REG),
    TABLE_LINK(0F_01, MODRM_REG),
    TABLE_LINK(0F_0D, MODRM_REG),
    TABLE_LINK(0F_0F, 3DNOW),
    TABLE_LINK(0F_12, MODRM_MOD),
    TABLE_LINK(0F_16, MODRM_MOD),
    TABLE_LINK(0F_18, MODRM_REG),
    TABLE_LINK(0F_19, MODRM_REG),
    TABLE_LINK(0F_1C, MODRM_REG),
    TABLE_LINK(0F_1D, MODRM_REG),
    TABLE_LINK(0F_1E, MODRM_REG),
    TABLE_LINK(0F_1F, MODRM_REG),
    TABLE_LINK(0F_6E, OSIZE),
    TABLE_LINK(0F_71, MODRM_REG),
    TABLE_LINK(0F_71_REG2, MODRM_MOD),
    TABLE_LINK(0F_71_REG4, MODRM_MOD),
    TABLE_LINK(0F_71_REG6, MODRM_MOD),
    TABLE_LINK(0F_72, MODRM_REG),
    TABLE_LINK(0F_72_REG2, MODRM_MOD),
    TABLE_LINK(0F_72_REG4, MODRM_MOD),
    TABLE_LINK(0F_72_REG6, MODRM_MOD), 
    TABLE_LINK(0F_73, MODRM_REG),
    TABLE_LINK(0F_73_REG2, MODRM_MOD),
    TABLE_LINK(0F_73_REG6, MODRM_MOD), 
    TABLE_LINK(0F_7E, OSIZE), 
    TABLE_LINK(0F_AE, MODRM_REG),
    TABLE_LINK(0F_B9, MODRM_REG),
    TABLE_LINK(0F_BA, MODRM_REG),
    TABLE_LINK(0F_C4, MODRM_MOD),
    TABLE_LINK(0F_C7, MODRM_REG),
    TABLE_LINK(0F_00_REG0, MODRM_MOD),
    TABLE_LINK(0F_00_REG1, MODRM_MOD),
    TABLE_LINK(0F_01_REG0, MODRM_MOD),
    TABLE_LINK(0F_01_REG1, MODRM_MOD),
    TABLE_LINK(0F_01_REG2, MODRM_MOD),
    TABLE_LINK(0F_01_REG3, MODRM_MOD),
    TABLE_LINK(0F_01_REG4, MODRM_MOD),
    TABLE_LINK(0F_01_REG7, MODRM_MOD),
    TABLE_LINK(0F_01_REG0_RM, MODRM_RM),
    TABLE_LINK(0F_01_REG1_RM, MODRM_RM),
    TABLE_LINK(0F_01_REG2_RM, MODRM_RM),
    TABLE_LINK(0F_01_REG3_RM, MODRM_RM),
    TABLE_LINK(0F_01_REG7_RM, MODRM_RM),
    TABLE_LINK(0F_18_REG0, MODRM_MOD),
    TABLE_LINK(0F_18_REG1, MODRM_MOD),
    TABLE_LINK(0F_18_REG2, MODRM_MOD),
    TABLE_LINK(0F_18_REG3, MODRM_MOD),
    TABLE_LINK(0F_AE_REG0, MODRM_MOD),
    TABLE_LINK(0F_AE_REG1, MODRM_MOD),
    TABLE_LINK(0F_AE_REG2, MODRM_MOD),
    TABLE_LINK(0F_AE_REG3, MODRM_MOD),
    TABLE_LINK(0F_AE_REG4, MODRM_MOD),
    TABLE_LINK(0F_AE_REG5, MODRM_MOD),
    TABLE_LINK(0F_AE_REG6, MODRM_MOD),
    TABLE_LINK(0F_AE_REG7, MODRM_MOD),
    TABLE_LINK(0F_C7_REG1, OSIZE),
    TABLE_LINK(0F_C7_REG3, OSIZE),
    TABLE_LINK(0F_C7_REG4, OSIZE),
    TABLE_LINK(0F_C7_REG5, OSIZE),
    TABLE_LINK(0F_C7_REG6, MODRM_MOD),
    TABLE_LINK(0F_C7_REG7, MODRM_MOD),
    TABLE_LINK(66_0F, BYTE),
    TABLE_LINK(66_0F_19, MODRM_REG),
    TABLE_LINK(66_0F_1C, MODRM_REG),
    TABLE_LINK(66_0F_1D, MODRM_REG),
    TABLE_LINK(66_0F_1E, MODRM_REG),
    TABLE_LINK(66_0F_1F, MODRM_REG),
    TABLE_LINK(66_0F_6E, OSIZE),
    TABLE_LINK(66_0F_71, MODRM_REG),
    TABLE_LINK(66_0F_71_REG2, MODRM_MOD),
    TABLE_LINK(66_0F_71_REG4, MODRM_MOD),
    TABLE_LINK(66_0F_71_REG6, MODRM_MOD),
    TABLE_LINK(66_0F_72, MODRM_REG),
    TABLE_LINK(66_0F_72_REG2, MODRM_MOD),
    TABLE_LINK(66_0F_72_REG4, MODRM_MOD),
    TABLE_LINK(66_0F_72_REG6, MODRM_MOD),
    TABLE_LINK(66_0F_73, MODRM_REG), 
    TABLE_LINK(66_0F_73_REG2, MODRM_MOD), 
    TABLE_LINK(66_0F_73_REG3, MODRM_MOD),
    TABLE_LINK(66_0F_73_REG6, MODRM_MOD),
    TABLE_LINK(66_0F_73_REG7, MODRM_MOD),
    TABLE_LINK(66_0F_78, MODRM_REG),
    TABLE_LINK(66_0F_7E, OSIZE),
    TABLE_LINK(66_0F_AE, MODRM_REG), 
    TABLE_LINK(66_0F_C4, MODRM_MOD),
    TABLE_LINK(66_0F_C7, MODRM_REG),
    TABLE_LINK(66_0F_C7_REG6, MODRM_MOD),
    TABLE_LINK(F3_0F, BYTE),
    TABLE_LINK(F3_0F_01, MODRM_REG),
    TABLE_LINK(F3_0F_01_REG5, MODRM_MOD),
    TABLE_LINK(F3_0F_01_REG5_RM, MODRM_RM),
    TABLE_LINK(F3_0F_19, MODRM_REG),
    TABLE_LINK(F3_0F_1C, MODRM_REG),
    TABLE_LINK(F3_0F_1D, MODRM_REG),
    TABLE_LINK(F3_0F_1E, MODRM_REG),
    TABLE_LINK(F3_0F_1E_REG1, OSIZE),
    TABLE_LINK(F3_0F_1E_REG7_RM, MODRM_RM),
    TABLE_LINK(F3_0F_1F, MODRM_REG),
    TABLE_LINK(F3_0F_71, MODRM_REG),
    TABLE_LINK(F3_0F_72, MODRM_REG),
    TABLE_LINK(F3_0F_73, MODRM_REG),
    TABLE_LINK(F3_0F_AE, MODRM_REG),
    TABLE_LINK(F3_0F_AE_REG5, OSIZE),
    TABLE_LINK(F3_0F_C7, MODRM_REG),
    TABLE_LINK(F3_0F_C7_REG6, MODRM_MOD),
    TABLE_LINK(F3_0F_C7_REG7, MODRM_MOD),
    TABLE_LINK(F2_0F, BYTE),
    TABLE_LINK(F2_0F_19, MODRM_REG),
    TABLE_LINK(F2_0F_1C, MODRM_REG),
    TABLE_LINK(F2_0F_1D, MODRM_REG),
    TABLE_LINK(F2_0F_1E, MODRM_REG),
    TABLE_LINK(F2_0F_1F, MODRM_REG),
    TABLE_LINK(F2_0F_71, MODRM_REG),
    TABLE_LINK(F2_0F_72, MODRM_REG),
    TABLE_LINK(F2_0F_73, MODRM_REG),
    TABLE_LINK(F2_0F_AE, MODRM_REG),

    TABLE_LINK(0F_38, BYTE),
    TABLE_LINK(0F_38_F3, MODRM_REG),
    TABLE_LINK(0F_38_F6, OSIZE),
    TABLE_LINK(0F_3A, BYTE),
    TABLE_LINK(66_0F_38, BYTE),
    TABLE_LINK(66_0F_38_20, MODRM_MOD),
    TABLE_LINK(66_0F_38_21, MODRM_MOD),
    TABLE_LINK(66_0F_38_22, MODRM_MOD),
    TABLE_LINK(66_0F_38_23, MODRM_MOD),
    TABLE_LINK(66_0F_38_24, MODRM_MOD),
    TABLE_LINK(66_0F_38_25, MODRM_MOD),
    TABLE_LINK(66_0F_38_30, MODRM_MOD),
    TABLE_LINK(66_0F_38_31, MODRM_MOD),
    TABLE_LINK(66_0F_38_32, MODRM_MOD),
    TABLE_LINK(66_0F_38_33, MODRM_MOD),
    TABLE_LINK(66_0F_38_34, MODRM_MOD),
    TABLE_LINK(66_0F_38_35, MODRM_MOD),
    TABLE_LINK(66_0F_38_45, OSIZE_VEX),
    TABLE_LINK(66_0F_38_47, OSIZE_VEX),
    TABLE_LINK(66_0F_38_8C, OSIZE_VEX),
    TABLE_LINK(66_0F_38_8E, OSIZE_VEX),
    TABLE_LINK(66_0F_38_90, OSIZE_VEX),
    TABLE_LINK(66_0F_38_91, OSIZE_VEX),
    TABLE_LINK(66_0F_38_92, OSIZE_VEX),
    TABLE_LINK(66_0F_38_93, OSIZE_VEX),
    TABLE_LINK(66_0F_38_96, OSIZE_VEX),
    TABLE_LINK(66_0F_38_97, OSIZE_VEX),
    TABLE_LINK(66_0F_38_98, OSIZE_VEX), 
    TABLE_LINK(66_0F_38_99, OSIZE_VEX),
    TABLE_LINK(66_0F_38_9A, OSIZE_VEX),
    TABLE_LINK(66_0F_38_9B, OSIZE_VEX), 
    TABLE_LINK(66_0F_38_9C, OSIZE_VEX),
    TABLE_LINK(66_0F_38_9D, OSIZE_VEX),
    TABLE_LINK(66_0F_38_9E, OSIZE_VEX),
    TABLE_LINK(66_0F_38_9F, OSIZE_VEX),
    TABLE_LINK(66_0F_38_A6, OSIZE_VEX),
    TABLE_LINK(66_0F_38_A7, OSIZE_VEX),
    TABLE_LINK(66_0F_38_A8, OSIZE_VEX),
    TABLE_LINK(66_0F_38_A9, OSIZE_VEX),
    TABLE_LINK(66_0F_38_AA, OSIZE_VEX),
    TABLE_LINK(66_0F_38_AB, OSIZE_VEX),
    TABLE_LINK(66_0F_38_AC, OSIZE_VEX),
    TABLE_LINK(66_0F_38_AD, OSIZE_VEX),
    TABLE_LINK(66_0F_38_AE, OSIZE_VEX),
    TABLE_LINK(66_0F_38_AF, OSIZE_VEX),
    TABLE_LINK(66_0F_38_B6, OSIZE_VEX),
    TABLE_LINK(66_0F_38_B7, OSIZE_VEX),
    TABLE_LINK(66_0F_38_B8, OSIZE_VEX),
    TABLE_LINK(66_0F_38_B9, OSIZE_VEX),
    TABLE_LINK(66_0F_38_BA, OSIZE_VEX), 
    TABLE_LINK(66_0F_38_BB, OSIZE_VEX),
    TABLE_LINK(66_0F_38_BC, OSIZE_VEX),
    TABLE_LINK(66_0F_38_BD, OSIZE_VEX),
    TABLE_LINK(66_0F_38_BE, OSIZE_VEX),
    TABLE_LINK(66_0F_38_BF, OSIZE_VEX),
    TABLE_LINK(66_0F_38_F5, OSIZE),
    TABLE_LINK(66_0F_3A, BYTE),
    TABLE_LINK(66_0F_3A_14, MODRM_MOD),
    TABLE_LINK(66_0F_3A_15, MODRM_MOD),
    TABLE_LINK(66_0F_3A_16, OSIZE),
    TABLE_LINK(66_0F_3A_20, MODRM_MOD),
    TABLE_LINK(66_0F_3A_21, MODRM_MOD),
    TABLE_LINK(66_0F_3A_22, OSIZE),
    TABLE_LINK(F3_0F_38, BYTE),
    TABLE_LINK(F3_0F_3A, BYTE),
    TABLE_LINK(F2_0F_38, BYTE),
    TABLE_LINK(F2_0F_3A, BYTE),
    TABLE_LINK(XOP_8, BYTE),
    TABLE_LINK(XOP_8_A2, OSIZE_XOP),
    TABLE_LINK(XOP_8_A3, OSIZE_XOP),
    TABLE_LINK(XOP_9, BYTE), 
    TABLE_LINK(XOP_9_1, MODRM_REG),
    TABLE_LINK(XOP_9_2, MODRM_REG),
    TABLE_LINK(XOP_9_12, MODRM_REG),
    TABLE_LINK(XOP_9_90, OSIZE_XOP),
    TABLE_LINK(XOP_9_91, OSIZE_XOP),
    TABLE_LINK(XOP_9_92, OSIZE_XOP), 
    TABLE_LINK(XOP_9_93, OSIZE_XOP), 
    TABLE_LINK(XOP_9_94, OSIZE_XOP),
    TABLE_LINK(XOP_9_95, OSIZE_XOP),
    TABLE_LINK(XOP_9_96, OSIZE_XOP),
    TABLE_LINK(XOP_9_97, OSIZE_XOP),
    TABLE_LINK(XOP_9_98, OSIZE_XOP),
    TABLE_LINK(XOP_9_99, OSIZE_XOP),
    TABLE_LINK(XOP_9_9A, OSIZE_XOP),
    TABLE_LINK(XOP_9_9B, OSIZE_XOP),
    TABLE_LINK(XOP_A, BYTE),
    TABLE_LINK(XOP_A_12, MODRM_REG),

    TABLE_LINK(66_0F_3A_69, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_5C, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_5D, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_5E, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_5F, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_68, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_6A, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_6B, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_6C, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_6D, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_6E, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_6F, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_78, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_79, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_7A, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_7B, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_7C, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_7D, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_7E, OSIZE_VEX),
    TABLE_LINK(66_0F_3A_7F, OSIZE_VEX)
};

/****************************************************************************

    EFLAGS table

****************************************************************************/

const x86_eflags_t x86_eflags_table[] =
{
/*         X86_MN_ADD */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*          X86_MN_OR */ EFLAGS_ENTRY(CLR,  NA,  NA,   M,   M,   M,   M, CLR),
/*         X86_MN_ADC */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,  TM),
/*         X86_MN_SBB */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,  TM),
/*         X86_MN_AND */ EFLAGS_ENTRY(CLR,  NA,  NA,   M,   M,   M,   M, CLR),
/*         X86_MN_DAA */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,  TM,   M,  TM),
/*         X86_MN_SUB */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_DAS */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,  TM,   M,  TM),
/*         X86_MN_XOR */ EFLAGS_ENTRY(CLR,  NA,  NA,   M,   M,   M,   M, CLR),
/*         X86_MN_AAA */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,  TM,   M,   M),
/*         X86_MN_CMP */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_AAS */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,  TM,   M,   M),
/*         X86_MN_INC */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,  NA),
/*         X86_MN_DEC */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,  NA),
/*       X86_MN_BOUND */ EFLAGS_ENTRY( NA,  NA, CLR,  NA,  NA,  NA,  NA,  NA),
/*        X86_MN_ARPL */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   M,  NA,  NA,  NA),
/*        X86_MN_IMUL */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*        X86_MN_INSB */ EFLAGS_ENTRY(  M,   T,  NA,   M,   M,   M,   M,   M),
/*        X86_MN_INSW */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*        X86_MN_INSD */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_OUTSB */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_OUTSW */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_OUTSD */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*          X86_MN_JO */ EFLAGS_ENTRY(  T,  NA,  NA,  NA,  NA,  NA,  NA,  NA),
/*         X86_MN_JNO */ EFLAGS_ENTRY(  T,  NA,  NA,  NA,  NA,  NA,  NA,  NA),
/*          X86_MN_JC */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA,   T),
/*         X86_MN_JNC */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA,   T),
/*          X86_MN_JE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*         X86_MN_JNE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*         X86_MN_JNA */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,   T),
/*          X86_MN_JA */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,   T),
/*          X86_MN_JS */ EFLAGS_ENTRY( NA,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*         X86_MN_JNS */ EFLAGS_ENTRY( NA,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*         X86_MN_JPE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,   T,  NA),
/*         X86_MN_JPO */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,   T,  NA),
/*        X86_MN_JNGE */ EFLAGS_ENTRY(  T,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*         X86_MN_JGE */ EFLAGS_ENTRY(  T,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*         X86_MN_JNG */ EFLAGS_ENTRY(  T,  NA,  NA,   T,   T,  NA,  NA,  NA),
/*          X86_MN_JG */ EFLAGS_ENTRY(  T,  NA,  NA,   T,   T,  NA,  NA,  NA),
/*        X86_MN_TEST */ EFLAGS_ENTRY(CLR,  NA,  NA,   M,   M,   M,   M, CLR),
/*        X86_MN_SAHF */ EFLAGS_ENTRY(CLR,  NA,  NA,   M,   M,   M,   M,   M),
/*        X86_MN_LAHF */ EFLAGS_ENTRY( NA,  NA,  NA,   T,   T,   T,   T,   T),
/*       X86_MN_MOVSB */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_MOVSW */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_MOVSD */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_MOVSQ */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_CMPSB */ EFLAGS_ENTRY(  M,   T,  NA,   M,   M,   M,   M,   M),
/*       X86_MN_CMPSW */ EFLAGS_ENTRY(  M,   T,  NA,   M,   M,   M,   M,   M),
/*       X86_MN_CMPSD */ EFLAGS_ENTRY(  M,   T,  NA,   M,   M,   M,   M,   M),
/*       X86_MN_CMPSQ */ EFLAGS_ENTRY(  M,   T,  NA,   M,   M,   M,   M,   M),
/*       X86_MN_STOSB */ EFLAGS_ENTRY(CLR,   T,  NA,   M,   M,   M,   M, CLR),
/*       X86_MN_STOSW */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_STOSD */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_STOSQ */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_LODSB */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_LODSW */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_LODSD */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_LODSQ */ EFLAGS_ENTRY( NA,   T,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_SCASB */ EFLAGS_ENTRY(  M,   T,  NA,   M,   M,   M,   M,   M),
/*       X86_MN_SCASW */ EFLAGS_ENTRY(  M,   T,  NA,   M,   M,   M,   M,   M),
/*       X86_MN_SCASD */ EFLAGS_ENTRY(  M,   T,  NA,   M,   M,   M,   M,   M),
/*       X86_MN_SCASQ */ EFLAGS_ENTRY(  M,   T,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_ROL */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_ROR */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_RCL */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,  TM),
/*         X86_MN_RCR */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,  TM),
/*         X86_MN_SAL */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_SHR */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_SHL */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_SAR */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_INT */ EFLAGS_ENTRY( NA,  NA, CLR,  NA,  NA,  NA,  NA,  NA),
/*        X86_MN_INTO */ EFLAGS_ENTRY(  T,  NA, CLR,  NA,  NA,  NA,  NA,  NA),
/*         X86_MN_AAM */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_AMX */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_AAD */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_ADX */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*      X86_MN_SETALC */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA,   T),
/*      X86_MN_FCMOVB */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA,   T),
/*      X86_MN_FCMOVE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*     X86_MN_FCMOVBE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*      X86_MN_FCMOVU */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,   T,  NA),
/*     X86_MN_FCMOVNB */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA,   T),
/*     X86_MN_FCMOVNE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*    X86_MN_FCMOVNBE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*     X86_MN_FCMOVNU */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,   T,  NA),
/*      X86_MN_FUCOMI */ EFLAGS_ENTRY(CLR,  NA,  NA,  NA,   M,  NA,   M,   M),
/*       X86_MN_FCOMI */ EFLAGS_ENTRY(CLR,  NA,  NA,  NA,   M,  NA,   M,   M),
/*     X86_MN_FUCOMIP */ EFLAGS_ENTRY(CLR,  NA,  NA,  NA,   M,  NA,   M,   M),
/*      X86_MN_FCOMIP */ EFLAGS_ENTRY(CLR,  NA,  NA,  NA,   M,  NA,   M,   M),
/*      X86_MN_LOOPNE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*       X86_MN_LOOPE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*       X86_MN_ICEBP */ EFLAGS_ENTRY( NA,  NA, CLR,  NA,   T,  NA,  NA,  NA),
/*         X86_MN_CMC */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  TM),
/*         X86_MN_NEG */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_MUL */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_DIV */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*        X86_MN_IDIV */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_CLC */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA, CLR),
/*         X86_MN_STC */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA, SET),
/*         X86_MN_CLI */ EFLAGS_ENTRY( NA,  NA, CLR,  NA,  NA,  NA,  NA,  NA),
/*         X86_MN_STI */ EFLAGS_ENTRY( NA,  NA, SET,  NA,  NA,  NA,  NA,  NA),
/*         X86_MN_CLD */ EFLAGS_ENTRY( NA, CLR,  NA,  NA,  NA,  NA,  NA,  NA),
/*         X86_MN_STD */ EFLAGS_ENTRY( NA, SET,  NA,  NA,  NA,  NA,  NA,  NA),
/*        X86_MN_VERR */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   M,  NA,  NA,  NA),
/*        X86_MN_VERW */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   M,  NA,  NA,  NA),
/*      X86_MN_VMCALL */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*    X86_MN_VMLAUNCH */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*    X86_MN_VMRESUME */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*      X86_MN_VMXOFF */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_LAR */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   M,  NA,  NA,  NA),
/*         X86_MN_LSL */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   M,  NA,  NA,  NA),
/*         X86_MN_MOV */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*     X86_MN_UCOMISS */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*     X86_MN_UCOMISD */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   M,  NA,   M,   M),
/*      X86_MN_COMISS */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   M,  NA,   M,   M),
/*      X86_MN_COMISD */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   M,  NA,   M,   M),
/*    X86_MN_SYSENTER */ EFLAGS_ENTRY( NA,  NA, CLR,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_PTEST */ EFLAGS_ENTRY(CLR,  NA, CLR, CLR,   M, CLR, CLR,   M),
/*      X86_MN_INVEPT */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*     X86_MN_INVVPID */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*   X86_MN_PCMPESTRM */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M, CLR, CLR,   M),
/*   X86_MN_PCMPESTRI */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M, CLR, CLR,   M),
/*   X86_MN_PCMPISTRM */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M, CLR, CLR,   M),
/*   X86_MN_PCMPISTRI */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M, CLR, CLR,   M),
/*       X86_MN_CMOVO */ EFLAGS_ENTRY(  T,  NA,  NA,  NA,  NA,  NA,  NA,  NA),
/*      X86_MN_CMOVNO */ EFLAGS_ENTRY(  T,  NA,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_CMOVC */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA,   T),
/*      X86_MN_CMOVNC */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA,   T),
/*       X86_MN_CMOVE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*      X86_MN_CMOVNE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*      X86_MN_CMOVNA */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,   T),
/*       X86_MN_CMOVA */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,   T),
/*       X86_MN_CMOVS */ EFLAGS_ENTRY( NA,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*      X86_MN_CMOVNS */ EFLAGS_ENTRY( NA,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*      X86_MN_CMOVPE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,   T,  NA),
/*      X86_MN_CMOVPO */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,   T,  NA),
/*     X86_MN_CMOVNGE */ EFLAGS_ENTRY(  T,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*      X86_MN_CMOVGE */ EFLAGS_ENTRY(  T,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*      X86_MN_CMOVNG */ EFLAGS_ENTRY(  T,  NA,  NA,   T,   T,  NA,  NA,  NA),
/*       X86_MN_CMOVG */ EFLAGS_ENTRY(  T,  NA,  NA,   T,   T,  NA,  NA,  NA),
/*      X86_MN_VMREAD */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*     X86_MN_VMWRITE */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*        X86_MN_SETO */ EFLAGS_ENTRY(  T,  NA,  NA,  NA,  NA,  NA,  NA,  NA),
/*       X86_MN_SETNO */ EFLAGS_ENTRY(  T,  NA,  NA,  NA,  NA,  NA,  NA,  NA),
/*        X86_MN_SETC */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA,   T),
/*       X86_MN_SETNC */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,  NA,   T),
/*        X86_MN_SETE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*       X86_MN_SETNE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,  NA),
/*       X86_MN_SETNA */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,   T),
/*        X86_MN_SETA */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   T,  NA,  NA,   T),
/*        X86_MN_SETS */ EFLAGS_ENTRY( NA,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*       X86_MN_SETNS */ EFLAGS_ENTRY( NA,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*       X86_MN_SETPE */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,   T,  NA),
/*       X86_MN_SETPO */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,  NA,  NA,   T,  NA),
/*      X86_MN_SETNGE */ EFLAGS_ENTRY(  T,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*       X86_MN_SETGE */ EFLAGS_ENTRY(  T,  NA,  NA,   T,  NA,  NA,  NA,  NA),
/*       X86_MN_SETNG */ EFLAGS_ENTRY(  T,  NA,  NA,   T,   T,  NA,  NA,  NA),
/*        X86_MN_SETG */ EFLAGS_ENTRY(  T,  NA,  NA,   T,   T,  NA,  NA,  NA),
/*          X86_MN_BT */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*        X86_MN_SHLD */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_BTS */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*        X86_MN_SHRD */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*     X86_MN_CMPXCHG */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_BTR */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*      X86_MN_POPCNT */ EFLAGS_ENTRY(CLR,  NA,  NA, CLR,   M, CLR, CLR, CLR),
/*         X86_MN_BTC */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_BSF */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*         X86_MN_BSR */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*        X86_MN_XADD */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*   X86_MN_CMPXCHG8B */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*  X86_MN_CMPXCHG16B */ EFLAGS_ENTRY( NA,  NA,  NA,  NA,   M,  NA,  NA,  NA),
/*     X86_MN_VMPTRLD */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*     X86_MN_VMCLEAR */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*       X86_MN_VMXON */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*     X86_MN_VMPTRST */ EFLAGS_ENTRY(  M,  NA,  NA,   M,   M,   M,   M,   M),
/*        X86_MN_POPF */ EFLAGS_ENTRY(  M,   M,   M,   M,   M,   M,   M,   M)
};

x86_eflags_t
x86_eflags_get(uint16_t mnem)
{
    int i;

    /* default return */
    x86_eflags_t default_result = 
    {
        X86_FLAG_NA, X86_FLAG_NA, X86_FLAG_NA, X86_FLAG_NA, 
        X86_FLAG_NA, X86_FLAG_NA, X86_FLAG_NA, X86_FLAG_NA
    };

    switch(mnem)
    {
        case         X86_MN_ADD: i = 0; break; 
        case          X86_MN_OR: i = 1; break; 
        case         X86_MN_ADC: i = 2; break; 
        case         X86_MN_SBB: i = 3; break; 
        case         X86_MN_AND: i = 4; break; 
        case         X86_MN_DAA: i = 5; break; 
        case         X86_MN_SUB: i = 6; break; 
        case         X86_MN_DAS: i = 7; break; 
        case         X86_MN_XOR: i = 8; break; 
        case         X86_MN_AAA: i = 9; break; 
        case         X86_MN_CMP: i = 10; break; 
        case         X86_MN_AAS: i = 11; break; 
        case         X86_MN_INC: i = 12; break; 
        case         X86_MN_DEC: i = 13; break; 
        case       X86_MN_BOUND: i = 14; break; 
        case        X86_MN_ARPL: i = 15; break; 
        case        X86_MN_IMUL: i = 16; break; 
        case        X86_MN_INSB: i = 17; break; 
        case        X86_MN_INSW: i = 18; break; 
        case        X86_MN_INSD: i = 19; break; 
        case       X86_MN_OUTSB: i = 20; break; 
        case       X86_MN_OUTSW: i = 21; break; 
        case       X86_MN_OUTSD: i = 22; break; 
        case          X86_MN_JO: i = 23; break; 
        case         X86_MN_JNO: i = 24; break; 
        case          X86_MN_JC: i = 25; break; 
        case         X86_MN_JNC: i = 26; break; 
        case          X86_MN_JZ: i = 27; break; 
        case         X86_MN_JNZ: i = 28; break; 
        case         X86_MN_JNA: i = 29; break; 
        case          X86_MN_JA: i = 30; break; 
        case          X86_MN_JS: i = 31; break; 
        case         X86_MN_JNS: i = 32; break; 
        case          X86_MN_JP: i = 33; break; 
        case         X86_MN_JNP: i = 34; break; 
        case          X86_MN_JL: i = 35; break; 
        case         X86_MN_JNL: i = 36; break; 
        case         X86_MN_JNG: i = 37; break; 
        case          X86_MN_JG: i = 38; break; 
        case        X86_MN_TEST: i = 39; break; 
        case        X86_MN_SAHF: i = 40; break; 
        case        X86_MN_LAHF: i = 41; break; 
        case       X86_MN_MOVSB: i = 42; break; 
        case       X86_MN_MOVSW: i = 43; break; 
        case       X86_MN_MOVSD: i = 44; break; 
        case       X86_MN_MOVSQ: i = 45; break; 
        case       X86_MN_CMPSB: i = 46; break; 
        case       X86_MN_CMPSW: i = 47; break; 
        case       X86_MN_CMPSD: i = 48; break; 
        case       X86_MN_CMPSQ: i = 49; break; 
        case       X86_MN_STOSB: i = 50; break; 
        case       X86_MN_STOSW: i = 51; break; 
        case       X86_MN_STOSD: i = 52; break; 
        case       X86_MN_STOSQ: i = 53; break; 
        case       X86_MN_LODSB: i = 54; break; 
        case       X86_MN_LODSW: i = 55; break; 
        case       X86_MN_LODSD: i = 56; break; 
        case       X86_MN_LODSQ: i = 57; break; 
        case       X86_MN_SCASB: i = 58; break; 
        case       X86_MN_SCASW: i = 59; break; 
        case       X86_MN_SCASD: i = 60; break; 
        case       X86_MN_SCASQ: i = 61; break; 
        case         X86_MN_ROL: i = 62; break; 
        case         X86_MN_ROR: i = 63; break; 
        case         X86_MN_RCL: i = 64; break; 
        case         X86_MN_RCR: i = 65; break; 
        case         X86_MN_SAL: i = 66; break; 
        case         X86_MN_SHR: i = 67; break; 
        case         X86_MN_SHL: i = 68; break; 
        case         X86_MN_SAR: i = 69; break; 
        case         X86_MN_INT: i = 70; break; 
        case        X86_MN_INTO: i = 71; break; 
        case         X86_MN_AAM: i = 72; break; 
        case         X86_MN_AMX: i = 73; break; 
        case         X86_MN_AAD: i = 74; break; 
        case         X86_MN_ADX: i = 75; break; 
        case        X86_MN_SALC: i = 76; break; 
        case      X86_MN_FCMOVB: i = 77; break; 
        case      X86_MN_FCMOVE: i = 78; break; 
        case     X86_MN_FCMOVBE: i = 79; break; 
        case      X86_MN_FCMOVU: i = 80; break; 
        case     X86_MN_FCMOVNB: i = 81; break; 
        case     X86_MN_FCMOVNE: i = 82; break; 
        case    X86_MN_FCMOVNBE: i = 83; break; 
        case     X86_MN_FCMOVNU: i = 84; break; 
        case      X86_MN_FUCOMI: i = 85; break; 
        case       X86_MN_FCOMI: i = 86; break; 
        case     X86_MN_FUCOMIP: i = 87; break; 
        case      X86_MN_FCOMIP: i = 88; break; 
        case      X86_MN_LOOPNZ: i = 89; break; 
        case        X86_MN_LOOP: i = 90; break; 
        case       X86_MN_ICEBP: i = 91; break; 
        case         X86_MN_CMC: i = 92; break; 
        case         X86_MN_NEG: i = 93; break; 
        case         X86_MN_MUL: i = 94; break; 
        case         X86_MN_DIV: i = 95; break; 
        case        X86_MN_IDIV: i = 96; break; 
        case         X86_MN_CLC: i = 97; break; 
        case         X86_MN_STC: i = 98; break; 
        case         X86_MN_CLI: i = 99; break; 
        case         X86_MN_STI: i = 100; break; 
        case         X86_MN_CLD: i = 101; break; 
        case         X86_MN_STD: i = 102; break; 
        case        X86_MN_VERR: i = 103; break; 
        case        X86_MN_VERW: i = 104; break; 
        case      X86_MN_VMCALL: i = 105; break; 
        case    X86_MN_VMLAUNCH: i = 106; break; 
        case    X86_MN_VMRESUME: i = 107; break; 
        case      X86_MN_VMXOFF: i = 108; break; 
        case         X86_MN_LAR: i = 109; break; 
        case         X86_MN_LSL: i = 110; break; 
        case     X86_MN_UCOMISS: i = 112; break; 
        case     X86_MN_UCOMISD: i = 113; break; 
        case      X86_MN_COMISS: i = 114; break; 
        case      X86_MN_COMISD: i = 115; break; 
        case    X86_MN_SYSENTER: i = 116; break; 
        case       X86_MN_PTEST: i = 117; break; 
        case      X86_MN_INVEPT: i = 118; break; 
        case     X86_MN_INVVPID: i = 119; break; 
        case   X86_MN_PCMPESTRM: i = 120; break; 
        case   X86_MN_PCMPESTRI: i = 121; break; 
        case   X86_MN_PCMPISTRM: i = 122; break; 
        case   X86_MN_PCMPISTRI: i = 123; break; 
        case       X86_MN_CMOVO: i = 124; break; 
        case      X86_MN_CMOVNO: i = 125; break; 
        case       X86_MN_CMOVC: i = 126; break; 
        case      X86_MN_CMOVNC: i = 127; break; 
        case       X86_MN_CMOVZ: i = 128; break; 
        case      X86_MN_CMOVNZ: i = 129; break; 
        case      X86_MN_CMOVNA: i = 130; break; 
        case       X86_MN_CMOVA: i = 131; break; 
        case       X86_MN_CMOVS: i = 132; break; 
        case      X86_MN_CMOVNS: i = 133; break; 
        case       X86_MN_CMOVP: i = 134; break; 
        case      X86_MN_CMOVPO: i = 135; break; 
        case       X86_MN_CMOVL: i = 136; break; 
        case      X86_MN_CMOVNL: i = 137; break; 
        case      X86_MN_CMOVNG: i = 138; break; 
        case       X86_MN_CMOVG: i = 139; break; 
        case      X86_MN_VMREAD: i = 140; break; 
        case     X86_MN_VMWRITE: i = 141; break; 
        case        X86_MN_SETO: i = 142; break; 
        case       X86_MN_SETNO: i = 143; break; 
        case        X86_MN_SETC: i = 144; break; 
        case       X86_MN_SETNC: i = 145; break; 
        case        X86_MN_SETZ: i = 146; break; 
        case       X86_MN_SETNZ: i = 147; break; 
        case       X86_MN_SETNA: i = 148; break; 
        case        X86_MN_SETA: i = 149; break; 
        case        X86_MN_SETS: i = 150; break; 
        case       X86_MN_SETNS: i = 151; break; 
        case        X86_MN_SETP: i = 152; break; 
        case       X86_MN_SETPO: i = 153; break; 
        case        X86_MN_SETL: i = 154; break; 
        case       X86_MN_SETNL: i = 155; break; 
        case       X86_MN_SETNG: i = 156; break; 
        case        X86_MN_SETG: i = 157; break; 
        case          X86_MN_BT: i = 158; break; 
        case        X86_MN_SHLD: i = 159; break; 
        case         X86_MN_BTS: i = 160; break; 
        case        X86_MN_SHRD: i = 161; break; 
        case     X86_MN_CMPXCHG: i = 162; break; 
        case         X86_MN_BTR: i = 163; break; 
        case      X86_MN_POPCNT: i = 164; break; 
        case         X86_MN_BTC: i = 165; break; 
        case         X86_MN_BSF: i = 166; break; 
        case         X86_MN_BSR: i = 167; break; 
        case        X86_MN_XADD: i = 168; break; 
        case   X86_MN_CMPXCHG8B: i = 169; break; 
        case  X86_MN_CMPXCHG16B: i = 170; break; 
        case     X86_MN_VMPTRLD: i = 171; break; 
        case     X86_MN_VMCLEAR: i = 172; break; 
        case       X86_MN_VMXON: i = 173; break; 
        case     X86_MN_VMPTRST: i = 174; break;

        case        X86_MN_POPF: 
        case       X86_MN_POPFD:
        case       X86_MN_POPFQ: i = 175; break;

        default: 
            i = -1;
            break;
    }

    /* check if the instruction has an eflags entry */
    if(i < 0)
    {
        return default_result;
    }
    else
    {
        return x86_eflags_table[i];
    }
}
















