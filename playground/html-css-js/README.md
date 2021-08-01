# HTML, CSS and JavaScript - from "How Computers Really Work" book, by Matthew Justice

running the webserver
```bash
python3 -m http.server 8888
```

using curl to perform an http get and receive a response
```bash
curl -i localhost:8888
```

```
HTTP/1.0 200 OK
Server: SimpleHTTP/0.6 Python/3.9.6
Date: Sun, 01 Aug 2021 12:10:38 GMT
Content-type: text/html
Content-Length: 255
Last-Modified: Sun, 01 Aug 2021 12:07:29 GMT

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <title>A Cat</title>
    </head>
    <body>
        <h1>Thoughts on a Cat</h1>
        <p>This is a cat.</p>
        <img src="cat.jpg" alt="cat photo">
    </body>
</html>
```

when the client is a browser, an additional http request is going to be made to get the image
```
::1 - - [01/Aug/2021 13:12:30] "GET / HTTP/1.1" 200 -
::1 - - [01/Aug/2021 13:12:31] "GET /cat.jpg HTTP/1.1" 200 -
``` 