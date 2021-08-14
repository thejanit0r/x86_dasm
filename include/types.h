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
#ifndef _TYPES_H_
#define _TYPES_H_

#if defined(_MSC_VER)

    #include <windows.h>

    typedef LARGE_INTEGER           large_int_t;

    #if(_MSC_VER < 1300)

        typedef SIZE_T              size_t;
        typedef signed char         int8_t;
        typedef signed short        int16_t;
        typedef signed int          int32_t;
        typedef long long           int64_t

        typedef unsigned char       uint8_t;
        typedef unsigned short      uint16_t;
        typedef unsigned int        uint32_t;
        typedef unsigned long long  uint64_t;

    #else

        typedef signed __int8       int8_t;
        typedef signed __int16      int16_t;
        typedef signed __int32      int32_t;
        typedef signed __int64      int64_t;

        typedef unsigned __int8     uint8_t;
        typedef unsigned __int16    uint16_t;
        typedef unsigned __int32    uint32_t;
        typedef unsigned __int64    uint64_t;

        typedef signed long         long_t;
        typedef unsigned long       ulong_t;
        typedef unsigned char       uchar_t;
        typedef unsigned short      ushort_t;

    #endif

    #if defined(_WIN64)

        typedef signed __int64      intptr_t;
        typedef unsigned __int64    uintptr_t;
        typedef unsigned __int64    size_t;

    #else

        typedef signed int          intptr_t;
        typedef unsigned int        uintptr_t;

    #endif

#else

    #include <sys/types.h>
    #include <stdint.h>

    typedef signed long         long_t;
    typedef unsigned long       ulong_t;
    typedef unsigned char       uchar_t;
    typedef unsigned short      ushort_t;

#endif

typedef unsigned int bool_t;

#define true    1
#define false   0

#ifndef __cplusplus
    #define NULL    ((void *)0)
#endif

#if 0
#ifndef offsetof
#define offsetof(s,m) (size_t)&(((s *)0)->m)
#endif
#endif

#ifndef countof
#define countof(a) (sizeof(a) / sizeof(a[0]))
#endif

#define roundup(a, b) \
    (((ulong_t)(a) + (ulong_t)(b) - 1) & ~((ulong_t)(b) - 1))

/* token paste */
#define PASTE_INTERNAL(a, b) a##b 

/* level of indirection for recursive expansion */
#define PASTE_TOKEN(a, b) PASTE_INTERNAL(a, b) 

#endif //_TYPES_H_
