# Examine the link layer - from "How Computers Really Work" book, by Matthew Justice

get MAC address of ethernet adapter

```bash
ifconfig eht0 | grep ether
```

hex representation of a 48 bit number (each hex is 4 bits, 12 x 4 = 48)

```
ether dc:a6:32:23:1d:d7  txqueuelen 1000  (Ethernet)
```

the first 24 bits represent the vendor/manufactor, known as organizationally unique identifier (OUI), in this case `DCA632`

getting the MAC addres of the WIFI adapter

```bash
ifconfig wlan0 | grep ether
```

```
ether da:51:72:45:44:85  txqueuelen 1000  (Ethernet)
```

scan all MAC addresses in the network with `arp-scan`

```bash
apr-scan -l
```

```
Interface: en0, type: EN10MB, MAC: c4:b3:01:d5:e5:73, IPv4: 192.168.3.14
Starting arp-scan 1.9.7 with 256 hosts (https://github.com/royhills/arp-scan)
192.168.3.1	f0:e4:a2:23:26:b9	HUAWEI TECHNOLOGIES CO.,LTD
192.168.3.3	f0:e4:a2:23:90:b5	HUAWEI TECHNOLOGIES CO.,LTD
192.168.3.4	f0:e4:a2:23:90:60	HUAWEI TECHNOLOGIES CO.,LTD
192.168.3.7	04:8c:9a:b6:4a:d8	Huawei Device Co., Ltd.
192.168.3.17	dc:a6:32:23:1d:d7	Raspberry Pi Trading Ltd
192.168.3.30	7c:2e:bd:30:c1:c4	Google, Inc.
192.168.3.28	80:91:33:77:b9:4e	AzureWave Technology Inc.
192.168.3.60	d4:5e:ec:51:f7:d9	(Unknown)
192.168.3.59	b8:27:eb:4e:01:9f	Raspberry Pi Foundation
192.168.3.31	b0:0c:d1:ac:85:83	Hewlett Packard
192.168.3.35	a4:83:e7:8a:04:9f	Apple, Inc.
192.168.3.38	ca:24:5b:9e:6f:00	(Unknown: locally administered)
192.168.3.58	4e:12:c3:d2:c9:ed	(Unknown: locally administered)
```
