#!/bin/bash

mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -days 365 -nodes \
			-out /etc/nginx/ssl/nginx.crt \
			-keyout /etc/nginx/ssl/nginx.key \
			-subj "/C=KR/ST=SEOUL/L=SEOUL/O=42 School/OU=yohlee/CN=localhost"

mkdir -p /var/run/nginx

ssh-keygen -A
adduser --disabled-password admin
echo "admin:admin" | chpasswd

/usr/sbin/sshd

nginx -g "daemon off;"
