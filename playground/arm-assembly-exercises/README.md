# ARM Assembly exercises from "How Computers Really Work" book, by Matthew Justice

### Assemble
```bash
as -o fac.o fac.s
```

### Link
```bash
ld -o fac fac.o
```

### Run executable
```bash
./fac
```

### Debug with GNU Debugger (gdb)

```
gdb fac
```

```
(gdb) info files
```

```
Entry point: 0x10074
```

Disassembly the entry point memory address:
```
(gdb) disas 0x10074
```

```
Dump of assembler code for function _start:
   0x00010074 <+0>:	ldr	r1, [pc, #40]	; 0x100a4 <end+20>
   0x00010078 <+4>:	ldr	r0, [r1]
   0x0001007c <+8>:	subs	r3, r0, #1
   0x00010080 <+12>:	ble	0x10090 <end>
End of assembler dump.
```

Print ending address  
(48 bytes is the total lenght of the program, since the program has 12 insructions
and each instruction is 4 bytes)
```
(gdb) print/x 0x00010074 + 48
```

```
$1 = 0x100a4
```

Disassemble the entire program
```
(gdb) disas 0x00010074, 0x100a4
```

```
Dump of assembler code from 0x10074 to 0x100a4:
   0x00010074 <_start+0>:	ldr	r1, [pc, #40]	; 0x100a4 <end+20>
   0x00010078 <_start+4>:	ldr	r0, [r1]
   0x0001007c <_start+8>:	subs	r3, r0, #1
   0x00010080 <_start+12>:	ble	0x10090 <end>
   0x00010084 <loop+0>:	mul	r0, r3, r0
   0x00010088 <loop+4>:	subs	r3, r3, #1
   0x0001008c <loop+8>:	bne	0x10084 <loop>
   0x00010090 <end+0>:	ldr	r1, [pc, #16]	; 0x100a8 <end+24>
   0x00010094 <end+4>:	str	r0, [r1]
   0x00010098 <end+8>:	mov	r0, #0
   0x0001009c <end+12>:	mov	r7, #1
   0x000100a0 <end+16>:	svc	0x00000000
End of assembler dump.
```

Set breakpoints
```
(gdb) break *0x10074
(gdb) break *0x1007c
(gdb) break *0x10090
(gdb) break *0x100a0
```

Run the program
```bash
(gdb) run
```

```bash
info register pc
```

program counter register points to the start address for the first program instruction:
```
pc             0x10074             0x10074 <_start>
````

Another way is to disassemble the current code:  
(the => sign tells where the program is halted)
```
(gdb) disas
Dump of assembler code for function _start:
=> 0x00010074 <+0>:	ldr	r1, [pc, #40]	; 0x100a4 <end+20>
   0x00010078 <+4>:	ldr	r0, [r1]
   0x0001007c <+8>:	subs	r3, r0, #1
   0x00010080 <+12>:	ble	0x10090 <end>
End of assembler dump.
(gdb) print (int)n
$2 = 5
(gdb) p (int)result
$3 = 0
```

Printing memory address of symbolic labels:
```
(gdb) p &n
$4 = (<data variable, no debug info> *) 0x200ac
(gdb) p &result
$5 = (<data variable, no debug info> *) 0x200b0
```

Print the hex value of consecutive memory addresses:
```
(gdb) x/2xw 0x200ac
0x200ac:	0x00000005	0x00000000
```

Continue execution
```
(gdb) continue
Continuing.

Breakpoint 2, 0x0001007c in _start ()
(gdb) disas
Dump of assembler code for function _start:
   0x00010074 <+0>:	ldr	r1, [pc, #40]	; 0x100a4 <end+20>
   0x00010078 <+4>:	ldr	r0, [r1]
=> 0x0001007c <+8>:	subs	r3, r0, #1
   0x00010080 <+12>:	ble	0x10090 <end>
End of assembler dump.
(gdb) info registers r0
r0             0x5                 5
```

r0 = 5

```
(gdb) continue
Continuing.

Breakpoint 3, 0x00010090 in end ()
(gdb) disas
Dump of assembler code for function end:
=> 0x00010090 <+0>:	ldr	r1, [pc, #16]	; 0x100a8 <end+24>
   0x00010094 <+4>:	str	r0, [r1]
   0x00010098 <+8>:	mov	r0, #0
   0x0001009c <+12>:	mov	r7, #1
   0x000100a0 <+16>:	svc	0x00000000
   0x000100a4 <+20>:	andeq	r0, r2, r12, lsr #1
   0x000100a8 <+24>:	strheq	r0, [r2], -r0	; <UNPREDICTABLE>
End of assembler dump.
(gdb) i r r0
r0             0x78                120
(gdb) p (int)result
$6 = 0
```

r0 = 120  
result = 0

```
(gdb) c
Continuing.

Breakpoint 4, 0x000100a0 in end ()
(gdb) disas
Dump of assembler code for function end:
   0x00010090 <+0>:	ldr	r1, [pc, #16]	; 0x100a8 <end+24>
   0x00010094 <+4>:	str	r0, [r1]
   0x00010098 <+8>:	mov	r0, #0
   0x0001009c <+12>:	mov	r7, #1
=> 0x000100a0 <+16>:	svc	0x00000000
   0x000100a4 <+20>:	andeq	r0, r2, r12, lsr #1
   0x000100a8 <+24>:	strheq	r0, [r2], -r0	; <UNPREDICTABLE>
End of assembler dump.
(gdb) p (int)result
$7 = 120
(gdb) i r r0
r0             0x0                 0
```

result = 120  
r0 = 0

**Hack the running program and change the value of `n` at runtime**
```
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/pi/source/arm-assembly-exercises/fac

Breakpoint 1, 0x00010074 in _start ()
(gdb) p &n
$8 = (<data variable, no debug info> *) 0x200ac
(gdb) set {int}0x200ac = 7
(gdb) p (int)n
$9 = 7
(gdb) disable 2
(gdb) disable 3
(gdb) c
Continuing.

Breakpoint 4, 0x000100a0 in end ()
(gdb) p (int)result
$10 = 5040
```

### Dump object file
```bash
objdump -d fac.o
```

```
fac.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <_start>:
   0:	e59f1028 	ldr	r1, [pc, #40]	; 30 <end+0x14>
   4:	e5910000 	ldr	r0, [r1]
   8:	e2503001 	subs	r3, r0, #1
   c:	da000002 	ble	1c <end>

00000010 <loop>:
  10:	e0000093 	mul	r0, r3, r0
  14:	e2533001 	subs	r3, r3, #1
  18:	1afffffc 	bne	10 <loop>

0000001c <end>:
  1c:	e59f1010 	ldr	r1, [pc, #16]	; 34 <end+0x18>
  20:	e5810000 	str	r0, [r1]
  24:	e3a00000 	mov	r0, #0
  28:	e3a07001 	mov	r7, #1
  2c:	ef000000 	svc	0x00000000
  30:	00000000 	.word	0x00000000
  34:	00000004 	.word	0x00000004
```

### Hex dump executable file
```bash
hexdump fac
```

```
0000000 457f 464c 0101 0001 0000 0000 0000 0000
0000010 0002 0028 0001 0000 0074 0001 0034 0000
0000020 0294 0000 0200 0500 0034 0020 0002 0028
0000030 0007 0006 0001 0000 0000 0000 0000 0001
0000040 0000 0001 00ac 0000 00ac 0000 0005 0000
0000050 0000 0001 0001 0000 00ac 0000 00ac 0002
0000060 00ac 0002 0008 0000 0008 0000 0006 0000
0000070 0000 0001 1028 e59f 0000 e591 3001 e250
0000080 0002 da00 0093 e000 3001 e253 fffc 1aff
0000090 1010 e59f 0000 e581 0000 e3a0 7001 e3a0
00000a0 0000 ef00 00ac 0002 00b0 0002 0005 0000
00000b0 0000 0000 1141 0000 6100 6165 6962 0100
00000c0 0007 0000 0108 0000 0000 0000 0000 0000
00000d0 0000 0000 0000 0000 0000 0000 0074 0001
00000e0 0000 0000 0003 0001 0000 0000 00ac 0002
00000f0 0000 0000 0003 0002 0000 0000 0000 0000
0000100 0000 0000 0003 0003 0001 0000 0000 0000
0000110 0000 0000 0004 fff1 0007 0000 00ac 0002
0000120 0000 0000 0000 0002 0009 0000 0074 0001
0000130 0000 0000 0000 0001 0051 0000 0090 0001
0000140 0000 0000 0000 0001 000c 0000 0084 0001
0000150 0000 0000 0000 0001 0011 0000 00b0 0002
0000160 0000 0000 0000 0002 0018 0000 00a4 0001
0000170 0000 0000 0000 0001 0018 0000 00ac 0002
0000180 0000 0000 0000 0002 002a 0000 00b4 0002
0000190 0000 0000 0010 0002 001b 0000 00b4 0002
00001a0 0000 0000 0010 0002 0029 0000 00b4 0002
00001b0 0000 0000 0010 0002 003a 0000 0074 0001
00001c0 0000 0000 0010 0001 0035 0000 00b4 0002
00001d0 0000 0000 0010 0002 0041 0000 00b4 0002
00001e0 0000 0000 0010 0002 0049 0000 00b4 0002
00001f0 0000 0000 0010 0002 0050 0000 00b4 0002
0000200 0000 0000 0010 0002 6600 6361 6f2e 6e00
0000210 2400 0061 6f6c 706f 7200 7365 6c75 0074
0000220 6424 5f00 625f 7373 735f 6174 7472 5f5f
0000230 5f00 625f 7373 655f 646e 5f5f 5f00 625f
0000240 7373 735f 6174 7472 5f00 655f 646e 5f5f
0000250 5f00 6465 7461 0061 655f 646e 0000 732e
0000260 6d79 6174 0062 732e 7274 6174 0062 732e
0000270 7368 7274 6174 0062 742e 7865 0074 642e
0000280 7461 0061 412e 4d52 612e 7474 6972 7562
0000290 6574 0073 0000 0000 0000 0000 0000 0000
00002a0 0000 0000 0000 0000 0000 0000 0000 0000
00002b0 0000 0000 0000 0000 0000 0000 001b 0000
00002c0 0001 0000 0006 0000 0074 0001 0074 0000
00002d0 0038 0000 0000 0000 0000 0000 0004 0000
00002e0 0000 0000 0021 0000 0001 0000 0003 0000
00002f0 00ac 0002 00ac 0000 0008 0000 0000 0000
0000300 0000 0000 0001 0000 0000 0000 0027 0000
0000310 0003 7000 0000 0000 0000 0000 00b4 0000
0000320 0012 0000 0000 0000 0000 0000 0001 0000
0000330 0000 0000 0001 0000 0002 0000 0000 0000
0000340 0000 0000 00c8 0000 0140 0000 0005 0000
0000350 000c 0000 0004 0000 0010 0000 0009 0000
0000360 0003 0000 0000 0000 0000 0000 0208 0000
0000370 0055 0000 0000 0000 0000 0000 0001 0000
0000380 0000 0000 0011 0000 0003 0000 0000 0000
0000390 0000 0000 025d 0000 0037 0000 0000 0000
00003a0 0000 0000 0001 0000 0000 0000
00003ac
```

### Read the headers in the file
```bash
readelf -e fac
```

```
ELF Header:
  Magic:   7f 45 4c 46 01 01 01 00 00 00 00 00 00 00 00 00
  Class:                             ELF32
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           ARM
  Version:                           0x1
  Entry point address:               0x10074
  Start of program headers:          52 (bytes into file)
  Start of section headers:          660 (bytes into file)
  Flags:                             0x5000200, Version5 EABI, soft-float ABI
  Size of this header:               52 (bytes)
  Size of program headers:           32 (bytes)
  Number of program headers:         2
  Size of section headers:           40 (bytes)
  Number of section headers:         7
  Section header string table index: 6

Section Headers:
  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            00000000 000000 000000 00      0   0  0
  [ 1] .text             PROGBITS        00010074 000074 000038 00  AX  0   0  4
  [ 2] .data             PROGBITS        000200ac 0000ac 000008 00  WA  0   0  1
  [ 3] .ARM.attributes   ARM_ATTRIBUTES  00000000 0000b4 000012 00      0   0  1
  [ 4] .symtab           SYMTAB          00000000 0000c8 000140 10      5  12  4
  [ 5] .strtab           STRTAB          00000000 000208 000055 00      0   0  1
  [ 6] .shstrtab         STRTAB          00000000 00025d 000037 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  y (purecode), p (processor specific)

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  LOAD           0x000000 0x00010000 0x00010000 0x000ac 0x000ac R E 0x10000
  LOAD           0x0000ac 0x000200ac 0x000200ac 0x00008 0x00008 RW  0x10000

 Section to Segment mapping:
  Segment Sections...
   00     .text
   01     .data
```

### Example with `ls` bin

We can do this with any standard [ELF](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format) file on UNIX systems.

```bash
whereis ls
objdump -d /bin/ls
```

## Notes

.word -> 4 bytes (32 bits)

gdb supports shortened versions of commands (e.g print -> p)