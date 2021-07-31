# See your leased ip address - from "How Computers Really Work" book, by Matthew Justice

```bash
cat /var/log/syslog | grep leased
```

192.168.3.59 was leased by DHCP server (192.168.3.1 in this case) to this host, for use in eth0 (ethernet interface)

```
Jul 31 11:21:09 oldpi dhcpcd[380]: eth0: leased 192.168.3.59 for 86400 seconds
```

releasing current ip and requesting a new one

```bash
sudo dhclient -r # release your current ip
sudo dhclient # ask for a new ip
cat /var/log/syslog | grep leased
```

in my case it gave me the same ip

```
Jul 31 11:26:59 oldpi dhcpcd[380]: eth0: leased 192.168.3.59 for 86400 seconds
```
