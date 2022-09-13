FROM	debian:buster

RUN	apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y nginx openssl && \
	whereis nginx

COPY	/tools/mysite.conf /etc/nginx/sites-enabled/

RUN	openssl req -x509 -nodes -sha256 -days 365 \
	-subj "/C=BE/ST=BXL/0=19/CN=localhost" \
	-newkey rsa:2048 \
	-keyout /etc/ssl/nginx.key \
	-out /etc/ssl/nginx.crt

CMD	["nginx", "-g", "daemon off;"]
