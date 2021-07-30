# Examine storage devices and filesystems - from "How Computers Really Work" book, by Matthew Justice

block devices - linux storage devices
```bash
lsblk
```

sda (an SSD external disk)  
mmcblk0 (microSD card)  

mmcblk0 is divided into two partitions (mmcblk0p1 and mmcblk0p2). one is mapped to `/boot` and the other `/` (root)


```
NAME        MAJ:MIN RM   SIZE RO TYPE MOUNTPOINT
sda           8:0    0 223.6G  0 disk
└─sda1        8:1    0 223.6G  0 part
mmcblk0     179:0    0  59.7G  0 disk
├─mmcblk0p1 179:1    0   256M  0 part /boot
└─mmcblk0p2 179:2    0  59.4G  0 part /
```

get size, used and avaliable space for mapped directories
```bash
df -h -T
```

only `/` and `/boot` directories are mapped storage devices. the others are temporary filesystems that reside in memory
```
Filesystem     Type      Size  Used Avail Use% Mounted on
/dev/root      ext4       59G  7.5G   49G  14% /
devtmpfs       devtmpfs  805M     0  805M   0% /dev
tmpfs          tmpfs     934M  268K  934M   1% /dev/shm
tmpfs          tmpfs     934M  9.0M  925M   1% /run
tmpfs          tmpfs     5.0M  4.0K  5.0M   1% /run/lock
tmpfs          tmpfs     934M     0  934M   0% /sys/fs/cgroup
/dev/mmcblk0p1 vfat      253M   55M  198M  22% /boot
```

see directory structure 3 levels deep

```bash
tree -d -L 3
```

e.g this is the `~/source` directory in my raspberry
```
├── arm-assembly-exercises
├── examine-variables
├── glibc
├── os-api
├── srt-discord-bot
│   ├── src
│   │   └── SimpleRandomTeams
│   └── tests
│       └── SimpleRandomTeams.Tests
├── threader
└── tts-discord-bot
    └── src
```
