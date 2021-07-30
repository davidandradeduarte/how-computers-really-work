# Create a thread and observe it - from "How Computers Really Work" book, by Matthew Justice

```bash
gcc -pthread -o threader threader.c 
./threader
```

`mythread`'s PID is still the process id, while TID is the new id for mythread  
the main thread's TID is the same as the process id
```
main PID: 6822
main TID: 6822
mythread PID: 6822
mythread TID: 6823
```

```bash
pstree | grep thread
```

process tree for the threader process (curly braces means it's a thread or group of threads - in the last case would be `n*[{name}]`, n being the number of threads)
```
|-sshd-+-sshd---sshd---bash---threader---{threader}
```

`ps` output (with threads) showing PID and TID
```bash
ps -e -T | grep threader
```

```
 6822  6822 pts/0    00:00:00 threader
 6822  6823 pts/0    00:00:00 threader
```

killing the entire process
```bash
kill 6822
```

