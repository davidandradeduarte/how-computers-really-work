# Examine port usage - from "How Computers Really Work" book, by Matthew Justice

listening and established TCP sockets:

```bash
netstat -nat
```

ssh (22) is ESTABLISHED and LISTEN (listening for new ssh connections)  
the others are services i (or the operating system) have running  
the established ssh connection is from `192.168.3.14` (my laptop) and is waiting on a reply on a temporary (ephemeral) port (49681)

```
Active Internet connections (servers and established)
Proto Recv-Q Send-Q Local Address           Foreign Address         State
tcp        0      0 127.0.0.1:4711          0.0.0.0:*               LISTEN
tcp        0      0 0.0.0.0:80              0.0.0.0:*               LISTEN
tcp        0      0 0.0.0.0:53              0.0.0.0:*               LISTEN
tcp        0      0 0.0.0.0:22              0.0.0.0:*               LISTEN
tcp        0    172 192.168.3.17:22         192.168.3.14:49681      ESTABLISHED
tcp6       0      0 ::1:4711                :::*                    LISTEN
tcp6       0      0 :::80                   :::*                    LISTEN
tcp6       0      0 :::53                   :::*                    LISTEN
tcp6       0      0 ::1:3350                :::*                    LISTEN
tcp6       0      0 :::22                   :::*                    LISTEN
tcp6       0      0 :::3389                 :::*                    LISTEN
```

```bash
sudo netstat -natp
```

same list but with PID and program name of the running program to which the socket belongs

```
Active Internet connections (servers and established)
Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name
tcp        0      0 127.0.0.1:4711          0.0.0.0:*               LISTEN      819/pihole-FTL
tcp        0      0 0.0.0.0:80              0.0.0.0:*               LISTEN      747/lighttpd
tcp        0      0 0.0.0.0:53              0.0.0.0:*               LISTEN      819/pihole-FTL
tcp        0      0 0.0.0.0:22              0.0.0.0:*               LISTEN      537/sshd
tcp        0    196 192.168.3.17:22         192.168.3.14:49681      ESTABLISHED 9120/sshd: pi [priv
tcp6       0      0 ::1:4711                :::*                    LISTEN      819/pihole-FTL
tcp6       0      0 :::80                   :::*                    LISTEN      747/lighttpd
tcp6       0      0 :::53                   :::*                    LISTEN      819/pihole-FTL
tcp6       0      0 ::1:3350                :::*                    LISTEN      545/xrdp-sesman
tcp6       0      0 :::22                   :::*                    LISTEN      537/sshd
tcp6       0      0 :::3389                 :::*                    LISTEN      560/xrdp
```

scaning from my laptop a known (or unkown) ip address (either on local internet or on the internet)

e.g my default gateway (router)

```bash
namp -sT 192.168.3.1
```

listening on ports:

port 53 (DNS)  
port 80 (HTTP)  
port 443 (HTTPS)

```
Starting Nmap 7.91 ( https://nmap.org ) at 2021-07-30 17:51 WEST
Nmap scan report for 192.168.3.1
Host is up (0.013s latency).
Not shown: 997 filtered ports
PORT    STATE SERVICE
53/tcp  open  domain
80/tcp  open  http
443/tcp open  https
```

or we can use `rustscan` which is a faster port scanning tool written in rust

```bash
rustscan -a 192.168.3.1
```

```
Open 192.168.3.1:53
Open 192.168.3.1:80
Open 192.168.3.1:443
```
