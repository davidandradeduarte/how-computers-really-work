# Examine the internet layer - from "How Computers Really Work" book, by Matthew Justice

list all network interfaces and their associated IP addresses

```bash
ifconfig
```

typical interfaces: `lo`, `eth0` and `wlan0`

`lo` - loopback interface, used to communicate between processes running in the same machine. the ip address is 127.0.0.1

```
lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
```

`eth0` - wired via Ethernet interface (ip assigned by DHCP)

```
eth0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.3.17  netmask 255.255.255.0  broadcast 192.168.3.255
        inet6 fe80::8a34:a65d:29b1:12be  prefixlen 64  scopeid 0x20<link>
```

`wlan0` - wireless WIFI interface (ip assigned by DHCP)  
(mine isn't connected to any network, thus why there's no ip being assigned)

```
wlan0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        ...
```

interpret `ip route`

```bash
ip route
```

```
default via 192.168.3.1 dev eth0 proto dhcp metric 100
default via 192.168.3.1 dev eth0 src 192.168.3.17 metric 202
169.254.0.0/16 dev vethb16a838 scope link src 169.254.54.126 metric 206
169.254.0.0/16 dev veth29b2a38 scope link src 169.254.240.146 metric 208
172.17.0.0/16 dev docker0 proto kernel scope link src 172.17.0.1
192.168.3.0/24 dev eth0 proto kernel scope link src 192.168.3.17 metric 100
192.168.3.0/24 dev eth0 proto dhcp scope link src 192.168.3.17 metric 202
```

**192.168.3.1** - default route. where packets should be sent when there isn't a specific route that applies, meaning the router (also known as the default gateway)  
_(ignore the others, they are network interfaces created by apps - e.g docker)_  ∑‘∑‘
**192.168.3.0/24** any packet sent to an IP address in the range of 192.168.3.0/24 should be sent through interface `eth0`, without the need to go through a router
