# Run your own webserver - from "How Computers Really Work" book, by Matthew Justice

inside pi: create html file, serve it in a http server listening on port 8888
```bash
echo "Hello, web!" > index.html
python3 -m http.server 8888
```

from my laptop
```bash
curl -i 192.168.3.17:8888
```

```
HTTP/1.0 200 OK
Server: SimpleHTTP/0.6 Python/3.7.3
Date: Sun, 01 Aug 2021 11:59:31 GMT
Content-type: text/html
Content-Length: 12
Last-Modified: Sun, 01 Aug 2021 11:53:21 GMT

Hello, Web!
```
