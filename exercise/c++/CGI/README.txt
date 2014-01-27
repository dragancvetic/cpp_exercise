1. 
Run in browser:
http://127.0.0.1/cgi-bin/cgi_001.cgi
Result:
Hello World! This is my first CGI program

2. 
Run in browser
http://127.0.0.1/cgi-bin/cgi_002.cgi
Result:
COMSPEC	Environment variable does not exist.
DOCUMENT_ROOT	/var/www
GATEWAY_INTERFACE	CGI/1.1
HTTP_ACCEPT	text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
HTTP_ACCEPT_ENCODING	gzip, deflate
HTTP_ACCEPT_LANGUAGE	en-US,en;q=0.5
HTTP_CONNECTION	keep-alive
HTTP_HOST	127.0.0.1
HTTP_USER_AGENT	Mozilla/5.0 (X11; Ubuntu; Linux i686; rv:26.0) Gecko/20100101 Firefox/26.0
PATH	/usr/local/bin:/usr/bin:/bin
QUERY_STRING	
REMOTE_ADDR	127.0.0.1
REMOTE_PORT	52405
REQUEST_METHOD	GET
REQUEST_URI	/cgi-bin/cgi_002.cgi
SCRIPT_FILENAME	/usr/lib/cgi-bin/cgi_002.cgi
SCRIPT_NAME	/cgi-bin/cgi_002.cgi
SERVER_ADDR	127.0.0.1
SERVER_ADMIN	webmaster@localhost
SERVER_NAME	127.0.0.1
SERVER_PORT	80
SERVER_PROTOCOL	HTTP/1.1
SERVER_SIGNATURE	
Apache/2.2.22 (Ubuntu) Server at 127.0.0.1 Port 80
SERVER_SOFTWARE	Apache/2.2.22 (Ubuntu)
< 

3.
Create a html page /var/www/cgi_003.html which queries data.
Run in browser:
http://127.0.0.1/cgi_003.html
Result:
First Name:
Last Name: 

Submit names, eg ZARA and ALI and will get:
First name: ZARA
Last name: ALI 

4. 

