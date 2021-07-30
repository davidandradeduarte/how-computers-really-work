# Examine Variables - from "How Computers Really Work" book, by Matthew Justice

Compile source code with GNU C Compiler (gcc)
```bash
gcc -o vars vars.c
```

Run the executable file
```bash
./vars
```

Examine the variables memory addresses and values stored in those addresses
```bash
gdb vars
```

```
GNU gdb (Raspbian 8.2.1-2) 8.2.1
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "arm-linux-gnueabihf".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from vars...(no debugging symbols found)...done.
(gdb) run
Starting program: /home/pi/source/examine-variables/vars
points is 27 and is stored at 0xbefff4fc
year is 2020 and is stored at 0xbefff4f8

Program received signal SIGINT, Interrupt.
__GI_raise (sig=2) at ../sysdeps/unix/sysv/linux/raise.c:50
50	../sysdeps/unix/sysv/linux/raise.c: No such file or directory.
(gdb) x/3xw 0xbefff4f8
0xbefff4f8:	0x000007e4	0x0000001b	0x00000000
```

`years` = 0x000007e4 = 2020 (in decimal)  
`points` = 0x0000001b = 27 (in decimal)

Same thing, this time printing the values in decimal format
```
(gdb) x/3dw 0xbefff4f8
0xbefff4f8:	2020	27	0
```

Same thing, this time in series of bytes (in little-endian data storage)
```
(gdb) x/12xb 0xbefff4f8
0xbefff4f8:	0xe4	0x07	0x00	0x00	0x1b	0x00	0x00	0x00
0xbefff500:	0x00	0x00	0x00	0x00
```

## stack vs heap memory allocation

```
gdb vars
GNU gdb (Raspbian 8.2.1-2) 8.2.1
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "arm-linux-gnueabihf".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from vars...(no debugging symbols found)...done.
(gdb) run
Starting program: /home/pi/source/examine-variables/vars
points is 27 and is stored at 0xbefff4fc
year is 2020 and is stored at 0xbefff4f8

Program received signal SIGINT, Interrupt.
__GI_raise (sig=2) at ../sysdeps/unix/sysv/linux/raise.c:50
50	../sysdeps/unix/sysv/linux/raise.c: No such file or directory.
(gdb) i proc mapping
process 4698
Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
	   0x10000    0x11000     0x1000        0x0 /home/pi/source/examine-variables/vars
	   0x20000    0x21000     0x1000        0x0 /home/pi/source/examine-variables/vars
	   0x21000    0x22000     0x1000     0x1000 /home/pi/source/examine-variables/vars
	   0x22000    0x43000    0x21000        0x0 [heap]
	0xb6e57000 0xb6f8f000   0x138000        0x0 /lib/arm-linux-gnueabihf/libc-2.28.so
	0xb6f8f000 0xb6f9f000    0x10000   0x138000 /lib/arm-linux-gnueabihf/libc-2.28.so
	0xb6f9f000 0xb6fa1000     0x2000   0x138000 /lib/arm-linux-gnueabihf/libc-2.28.so
	0xb6fa1000 0xb6fa2000     0x1000   0x13a000 /lib/arm-linux-gnueabihf/libc-2.28.so
	0xb6fa2000 0xb6fa5000     0x3000        0x0
	0xb6fb9000 0xb6fbd000     0x4000        0x0 /usr/lib/arm-linux-gnueabihf/libarmmem-v7l.so
	0xb6fbd000 0xb6fcc000     0xf000     0x4000 /usr/lib/arm-linux-gnueabihf/libarmmem-v7l.so
	0xb6fcc000 0xb6fcd000     0x1000     0x3000 /usr/lib/arm-linux-gnueabihf/libarmmem-v7l.so
	0xb6fcd000 0xb6fce000     0x1000     0x4000 /usr/lib/arm-linux-gnueabihf/libarmmem-v7l.so
	0xb6fce000 0xb6fee000    0x20000        0x0 /lib/arm-linux-gnueabihf/ld-2.28.so
	0xb6ff9000 0xb6ffb000     0x2000        0x0
	0xb6ffb000 0xb6ffc000     0x1000        0x0 [sigpage]
	0xb6ffc000 0xb6ffd000     0x1000        0x0 [vvar]
	0xb6ffd000 0xb6ffe000     0x1000        0x0 [vdso]
	0xb6ffe000 0xb6fff000     0x1000    0x20000 /lib/arm-linux-gnueabihf/ld-2.28.so
	0xb6fff000 0xb7000000     0x1000    0x21000 /lib/arm-linux-gnueabihf/ld-2.28.so
	0xbefdf000 0xbf000000    0x21000        0x0 [stack]
```

points ... is stored at 0xbefff4fc  
year ... is stored at 0xbefff4f8

the memory range 0xbefdf000 0xbf000000 (where our variables are stored) is allocated for the **stack**

```bash
gcc -o vars-heap vars-heap.c
```

```
gdb vars-heap
GNU gdb (Raspbian 8.2.1-2) 8.2.1
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "arm-linux-gnueabihf".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from vars-heap...(no debugging symbols found)...done.
(gdb) run
Starting program: /home/pi/source/examine-variables/vars-heap
points is 27 and is stored at 0xbefff4ec
year is 2020 and is stored at 0xbefff4e8
data is 0x00022558 and is stored at 0xbefff4e4

Program received signal SIGINT, Interrupt.
__GI_raise (sig=2) at ../sysdeps/unix/sysv/linux/raise.c:50
50	../sysdeps/unix/sysv/linux/raise.c: No such file or directory.
(gdb) i p mapp
Ambiguous info command "p mapp": pretty-printer, probes, proc, program.
(gdb) i pro mapp
Ambiguous info command "pro mapp": probes, proc, program.
(gdb) i proc mapp
process 4811
Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
	   0x10000    0x11000     0x1000        0x0 /home/pi/source/examine-variables/vars-heap
	   0x20000    0x21000     0x1000        0x0 /home/pi/source/examine-variables/vars-heap
	   0x21000    0x22000     0x1000     0x1000 /home/pi/source/examine-variables/vars-heap
	   0x22000    0x43000    0x21000        0x0 [heap]
	0xb6e57000 0xb6f8f000   0x138000        0x0 /lib/arm-linux-gnueabihf/libc-2.28.so
	0xb6f8f000 0xb6f9f000    0x10000   0x138000 /lib/arm-linux-gnueabihf/libc-2.28.so
	0xb6f9f000 0xb6fa1000     0x2000   0x138000 /lib/arm-linux-gnueabihf/libc-2.28.so
	0xb6fa1000 0xb6fa2000     0x1000   0x13a000 /lib/arm-linux-gnueabihf/libc-2.28.so
	0xb6fa2000 0xb6fa5000     0x3000        0x0
	0xb6fb9000 0xb6fbd000     0x4000        0x0 /usr/lib/arm-linux-gnueabihf/libarmmem-v7l.so
	0xb6fbd000 0xb6fcc000     0xf000     0x4000 /usr/lib/arm-linux-gnueabihf/libarmmem-v7l.so
	0xb6fcc000 0xb6fcd000     0x1000     0x3000 /usr/lib/arm-linux-gnueabihf/libarmmem-v7l.so
	0xb6fcd000 0xb6fce000     0x1000     0x4000 /usr/lib/arm-linux-gnueabihf/libarmmem-v7l.so
	0xb6fce000 0xb6fee000    0x20000        0x0 /lib/arm-linux-gnueabihf/ld-2.28.so
	0xb6ff9000 0xb6ffb000     0x2000        0x0
	0xb6ffb000 0xb6ffc000     0x1000        0x0 [sigpage]
	0xb6ffc000 0xb6ffd000     0x1000        0x0 [vvar]
	0xb6ffd000 0xb6ffe000     0x1000        0x0 [vdso]
	0xb6ffe000 0xb6fff000     0x1000    0x20000 /lib/arm-linux-gnueabihf/ld-2.28.so
	0xb6fff000 0xb7000000     0x1000    0x21000 /lib/arm-linux-gnueabihf/ld-2.28.so
	0xbefdf000 0xbf000000    0x21000        0x0 [stack]
```

data is 0x00022558 (HEAP) and is stored at 0xbefff4e4 (STACK)  

the memory range 0x22000 0x43000 (where our pointer variable is stored) is allocated for the **heap**

0xbefff4e4 is stack address  
0x00022558 is the value stored in this stack address that points to another address in the heap

