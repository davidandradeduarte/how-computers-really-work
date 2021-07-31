# Find information in DNS - from "How Computers Really Work" book, by Matthew Justice

returning the IP address of www.google.com

```bash
host www.google.com
```

```
www.google.com has address 142.250.200.68
www.google.com has IPv6 address 2a00:1450:4003:807::2004
```

also supports reverse lookup (ip to hostname)

```bash
host 142.250.200.68
```

```
68.200.250.142.in-addr.arpa domain name pointer www.google.com.
```

using a different DNS server than the device is configured to use

```bash
host www.google.com 1.1.1.1 # (using cloudflare's DNS server)
```

```
Using domain server:
Name: 1.1.1.1
Address: 1.1.1.1#53
Aliases:

www.google.com has address 142.250.200.68
www.google.com has IPv6 address 2a00:1450:4003:80d::2004
```

verbose output with all DNS queries

```
Trying "www.google.com"
Using domain server:
Name: 1.1.1.1
Address: 1.1.1.1#53
Aliases:

;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 11363
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 0

;; QUESTION SECTION:
;www.google.com.			IN	A

;; ANSWER SECTION:
www.google.com.		284	IN	A	142.250.200.68

Received 48 bytes from 1.1.1.1#53 in 183 ms
Trying "www.google.com"
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 43643
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 0

;; QUESTION SECTION:
;www.google.com.			IN	AAAA

;; ANSWER SECTION:
www.google.com.		209	IN	AAAA	2a00:1450:4003:80d::2004

Received 60 bytes from 1.1.1.1#53 in 12 ms
Trying "www.google.com"
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 21104
;; flags: qr rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 1, ADDITIONAL: 0

;; QUESTION SECTION:
;www.google.com.			IN	MX

;; AUTHORITY SECTION:
google.com.		60	IN	SOA	ns1.google.com. dns-admin.google.com. 387768352 900 900 1800 60

Received 82 bytes from 1.1.1.1#53 in 41 ms
```
