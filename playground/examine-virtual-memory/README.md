# Examine virtual memory - from "How Computers Really Work" book, by Matthew Justice

```bash
dmesg | grep lowmem
```

2:2 split (32bit - 4GB of virtual address space - 2GB for use mode processes, 2GB for kernel mode processes)  
user mode processes can use addresses from 0x00000000 to 0x7fffffff  
kernel mode processes can use addresses from 0x80000000 to 0xffffffff
```
lowmem : 0x80000000 - 0xbb400000 (948 MB)
```

```bash
ps | grep bash
```

```
 1160 pts/0    00:00:00 bash
```

see virtual memory in use by the `bash` process
```bash
pmap 1160
```

```
1160:   -bash
00010000    884K r-x-- bash
000fc000      4K r---- bash
000fd000     20K rw--- bash
00102000     36K rw---   [ anon ]
0118a000    812K rw---   [ anon ]
b6939000     36K r-x-- libnss_files-2.28.so
b6942000     64K ----- libnss_files-2.28.so
b6952000      4K r---- libnss_files-2.28.so
b6953000      4K rw--- libnss_files-2.28.so
b6954000     24K rw---   [ anon ]
b695a000   2536K r---- locale-archive
b6bd4000   2048K r---- locale-archive
b6dd4000   1248K r-x-- libc-2.28.so
b6f0c000     64K ----- libc-2.28.so
b6f1c000      8K r---- libc-2.28.so
b6f1e000      4K rw--- libc-2.28.so
b6f1f000     12K rw---   [ anon ]
b6f22000      8K r-x-- libdl-2.28.so
b6f24000     60K ----- libdl-2.28.so
b6f33000      4K r---- libdl-2.28.so
b6f34000      4K rw--- libdl-2.28.so
b6f35000    120K r-x-- libtinfo.so.6.1
b6f53000     64K ----- libtinfo.so.6.1
b6f63000      8K r---- libtinfo.so.6.1
b6f65000      4K rw--- libtinfo.so.6.1
b6f7a000     16K r-x-- libarmmem-v7l.so
b6f7e000     60K ----- libarmmem-v7l.so
b6f8d000      4K r---- libarmmem-v7l.so
b6f8e000      4K rw--- libarmmem-v7l.so
b6f8f000    128K r-x-- ld-2.28.so
b6fb4000     28K r--s- gconv-modules.cache
b6fbb000     16K rw---   [ anon ]
b6fbf000      4K r---- ld-2.28.so
b6fc0000      4K rw--- ld-2.28.so
bea07000    132K rw---   [ stack ]
bef34000      4K r-x--   [ anon ]
bef35000      4K r----   [ anon ]
bef36000      4K r-x--   [ anon ]
ffff0000      4K r-x--   [ anon ]
 total     8492K
```

ffff0000 is in kernel's virtual memory address range because it correspond to the ARM CPU vector page