# OS API - from "How Computers Really Work" book, by Matthew Justice

```bash
gcc -o newfile newfile.c
./newfile
cat file1.txt
```

```
Hello, file!
```

```bash
python3 newfile.py
cat file2.txt
```

```
Hello from Python!
```

## Analysing system calls

```bash
strace ./newfile
```

C functions being used are wrappers to these system calls  
3 - number of the file descriptor  
13 - number of bytes written  
0 - success exit code  
```
openat(AT_FDCWD, "file1.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644) = 3
write(3, "Hello, file!\n", 13)          = 13
close(3)
```

now the python's program

```bash
strace python3 newfile.py
```

the same system calls are being made, with the addition of others, since when running with python we're using the python standard libraries (which may be doing other system calls for other reasons), in addition to the python interpreter also being traced by `strace`
```
openat(AT_FDCWD, "file2.txt", O_WRONLY|O_CREAT|O_TRUNC|O_LARGEFILE|O_CLOEXEC, 0666) = 3
fstat64(3, {st_mode=S_IFREG|0644, st_size=0, ...}) = 0
ioctl(3, TCGETS, 0xbedf5070)            = -1 ENOTTY (Inappropriate ioctl for device)
_llseek(3, 0, [0], SEEK_CUR)            = 0
ioctl(3, TCGETS, 0xbedf5040)            = -1 ENOTTY (Inappropriate ioctl for device)
_llseek(3, 0, [0], SEEK_CUR)            = 0
write(3, "Hello from Python!\n", 19)    = 19
close(3)
```
