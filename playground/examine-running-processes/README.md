# Examine running processes - from "How Computers Really Work" book, by Matthew Justice

see running processes
```bash
ps -eH
```

`ps` running as a child process of `bash`, which is a child process of `sshd` (because we're executing this command within an ssh connection), which is also a child process of `systemd` (the first process that runs - init process)
```
 1    ?        00:00:04 systemd
 525  ?        00:00:00   sshd
 1507 ?        00:00:00     sshd
 1518 ?        00:00:00       sshd
 1521 pts/0    00:00:00         bash
 1562 pts/0    00:00:00           ps
```

to know which program initiated the `systemd` process (PID=1) 
```bash
ps 1
```

```
  PID TTY      STAT   TIME COMMAND
    1 ?        Ss     0:04 /sbin/init splash
```

```bash
stat /sbin/init
```

`/sbin/init` is a symbolic link to `/lib/systemd/systemd`
```
  File: /sbin/init -> /lib/systemd/systemd
  Size: 20        	Blocks: 0          IO Block: 4096   symbolic link
Device: b302h/45826d	Inode: 8211        Links: 1
Access: (0777/lrwxrwxrwx)  Uid: (    0/    root)   Gid: (    0/    root)
Access: 2020-08-20 11:53:33.484115936 +0100
Modify: 2020-05-11 08:06:25.000000000 +0100
Change: 2020-08-20 11:53:33.484115936 +0100
 Birth: -
````

nice tree format output for running processes
```bash
pstree
```

```
systemd─┬─ModemManager───2*[{ModemManager}]
        ├─NetworkManager─┬─dhclient
        │                └─2*[{NetworkManager}]
        ├─alsactl
        ├─avahi-daemon───avahi-daemon
        ├─bluealsa───2*[{bluealsa}]
        ├─bluetoothd
        ├─containerd───13*[{containerd}]
        ├─cron
        ├─dbus-daemon
        ├─dhcpcd
        ├─dockerd───11*[{dockerd}]
        ├─hciattach
        ├─lighttpd───php-cgi───4*[php-cgi]
        ├─login───bash
        ├─pihole-FTL───5*[{pihole-FTL}]
        ├─polkitd───2*[{polkitd}]
        ├─rngd───3*[{rngd}]
        ├─rsyslogd───3*[{rsyslogd}]
        ├─sshd───sshd───sshd───bash───pstree
        ├─2*[systemd───(sd-pam)]
        ├─systemd-journal
        ├─systemd-logind
        ├─systemd-timesyn───{systemd-timesyn}
        ├─systemd-udevd
        ├─thd
        ├─udisksd───4*[{udisksd}]
        ├─unattended-upgr───{unattended-upgr}
        ├─2*[wpa_supplicant]
        ├─xrdp
        └─xrdp-sesman
```