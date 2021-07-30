# glibc - from "How Computers Really Work" book, by Matthew Justice

```bash
gcc -o random random.c
./random
```

libraries imported by this program
```bash
readelf -d random | grep NEEDED
```

```
 0x00000001 (NEEDED)                     Shared library: [libc.so.6]
```

`libc` is the standard library for C

functions being used and imported by the program
```bash
objdump -TC random
```

```
random:     file format elf32-littlearm

DYNAMIC SYMBOL TABLE:
00000000  w   D  *UND*	00000000              __gmon_start__
00000000      DF *UND*	00000000  GLIBC_2.4   srand
00000000      DF *UND*	00000000  GLIBC_2.4   rand
00000000      DF *UND*	00000000  GLIBC_2.4   printf
00000000      DF *UND*	00000000  GLIBC_2.4   time
00000000      DF *UND*	00000000  GLIBC_2.4   abort
00000000      DF *UND*	00000000  GLIBC_2.4   __libc_start_main
```

see all the available functions in `libc`

```bash
objdump -TC /lib/arm-linux-gnueabihf/libc.so.6
```

debugging `random`

```bash
gdb random
(gdb) start
(gdb) info sharedlibrary
```

```
From        To          Syms Read   Shared Object Library
0xb6fcea30  0xb6fea150  Yes         /lib/ld-linux-armhf.so.3
0xb6fb93ac  0xb6fbc300  Yes (*)     /usr/lib/arm-linux-gnueabihf/libarmmem-v7l.so
0xb6e6e050  0xb6f702b4  Yes         /lib/arm-linux-gnueabihf/libc.so.6
(*): Shared library is missing debugging information.
```

`ld-linux-armhf` is the Linux dynamic linker library, responsible for loading other libraries