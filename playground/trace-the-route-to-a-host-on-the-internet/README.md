# Trace the route to a host on the internet - from "How Computers Really Work" book, by Matthew Justice

tracing the route a packet travels from current host to an host on the internet

```bash
traceroute www.google.com
```

from my "internal" router 192.168.3.1 to ISP's router 192.168.1.254, than to the DNS servers until it gets the IP address of www.google.com

```
traceroute to www.google.com (142.250.178.164), 64 hops max, 52 byte packets
 1  192.168.3.1 (192.168.3.1)  3.963 ms  2.118 ms  3.409 ms
 2  meo.home (192.168.1.254)  96.397 ms  2.802 ms  3.573 ms
 3  * 10.250.192.1 (10.250.192.1)  9.393 ms  5.211 ms
 4  telepac15-hsi.cprm.net (195.8.30.246)  7.048 ms
    telepac16-hsi.cprm.net (195.8.30.250)  7.514 ms  6.576 ms
 5  ga-cr1-bu10-200.cprm.net (195.8.30.245)  7.686 ms
    tva-cr1-bu10-200.cprm.net (195.8.30.249)  7.074 ms
    ga-cr1-bu10-200.cprm.net (195.8.30.245)  7.339 ms
 6  lis2-cr1-be4.cprm.net (195.8.1.57)  10.909 ms
    lis1-cr1-be4.cprm.net (195.8.0.165)  17.383 ms  12.925 ms
 7  72.14.211.90 (72.14.211.90)  11.250 ms  11.767 ms
    74.125.51.20 (74.125.51.20)  11.903 ms
 8  * 74.125.245.100 (74.125.245.100)  37.048 ms
    74.125.245.68 (74.125.245.68)  14.364 ms
 9  142.251.51.142 (142.251.51.142)  20.984 ms  22.609 ms
    142.251.55.149 (142.251.55.149)  23.139 ms
10  108.170.253.225 (108.170.253.225)  23.231 ms
    74.125.242.163 (74.125.242.163)  22.711 ms
    108.170.253.241 (108.170.253.241)  23.093 ms
11  www.google.com (142.250.178.164)  43.344 ms  20.800 ms
    142.251.54.155 (142.251.54.155)  25.028 ms
```
