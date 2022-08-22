# x86_dasm

This lightweight library aims at providing x86-64 disassembling features while being compact and simple to understand and fix. There are no dependencies other than the C standard library, which can also be avoided with slight modifications, depending on the compilation options. It does not use any dynamic memory allocation.

It is programmed entirely in C99 and supports all `x86` and `x86-64`/`AMD64` instructions and most ISA extensions (e.g. `AVX512` is currently not supported).

# Build

Compilation switches that can optionally be defined:

- `X86_DASM_DEBUG` to enable verbose debug output
- `X86_DASM_NOFMT` to disable all the instruction formatting (no strings)

```
make all
```

# Usage example

```c
x86_dasm_context_t x86_dctx = {0};

uint8_t code[] = {
    0xeb, 0xfe
};

x86_set_buffer(&x86_dctx, code);
x86_set_dmode(&x86_dctx, X86_DMODE_64BIT);
x86_set_ip(&x86_dctx, 0x7ffe0000);

if(x86_dasm(&x86_dctx) == 0)
    printf("%s", x86_dctx.inst_str);
```

# Output example

```
0000 |                 6A 60  | push 60
0002 |                    5A  | pop rdx
0003 |        68 63 61 6C 63  | push 636C6163
0008 |                    54  | push rsp
0009 |                    59  | pop rcx
000A |              48 29 D4  | sub rsp, rdx
000D |           65 48 8B 32  | mov rsi, qword ptr gs:[rdx]
0011 |           48 8B 76 18  | mov rsi, qword ptr ds:[rsi+18]
0015 |           48 8B 76 10  | mov rsi, qword ptr ds:[rsi+10]
0019 |                 48 AD  | lodsq rax, qword ptr ds:[rsi]
001B |              48 8B 30  | mov rsi, qword ptr ds:[rax]
001E |           48 8B 7E 30  | mov rdi, qword ptr ds:[rsi+30]
0022 |              03 57 3C  | add edx, dword ptr ds:[rdi+3C]
0025 |           8B 5C 17 28  | mov ebx, dword ptr ds:[rdi+rdx+28]
0029 |           8B 74 1F 20  | mov esi, dword ptr ds:[rdi+rbx+20]
002D |              48 01 FE  | add rsi, rdi
0030 |           8B 54 1F 24  | mov edx, dword ptr ds:[rdi+rbx+24]
0034 |           0F B7 2C 17  | movzx ebp, word ptr ds:[rdi+rdx]
0038 |              8D 52 02  | lea edx, ds:[rdx+2]
003B |                    AD  | lodsd eax, dword ptr ds:[rsi]
003C |  81 3C 07 57 69 6E 45  | cmp dword ptr ds:[rdi+rax], 456E6957
0043 |                 75 EF  | jnz short 34
0045 |           8B 74 1F 1C  | mov esi, dword ptr ds:[rdi+rbx+1C]
0049 |              48 01 FE  | add rsi, rdi
004C |              8B 34 AE  | mov esi, dword ptr ds:[rsi+rbp*4]
004F |              48 01 F7  | add rdi, rsi
0052 |                    99  | cdq
0053 |                 FF D7  | call rdi
```

# Helper macros for conditional expressions

```c
#include "x86_dasm_macros.h"

// ...

if(x86_dasm(&x86_dctx) == 0)
{
    if(X86M(&x86_dctx, ANY, REG(), REG())) 
        printf("Matched an instruction with two register operands");
    
    if(X86M(&x86_dctx, MOV, REG(), MEXPR()))
        printf("Matched: mov reg, mem");
    
    if(X86M(&x86_dctx, CALL, REG(EDI)))
        printf("Matched: call edi");
}
```

# License

`x86_dasm` is licensed under the Apache License, Version 2.0




