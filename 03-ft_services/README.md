# ft_services
---
### settings
```shell
# init docker
./42toolbox/init_docker.sh

# start minikube
mv .minikube goinfre/minikube
ln -s goinfre/minikube .minikube
minikube delete
minikube start --driver=virtualbox
eval $(minikube -p minikube docker-env)

# start ft_services
./srcs/setup.sh
```
---
### nginx with docker
```shell
# build nginx image
docker run -it -p 80:80 -p 443:443 alpine
# update and import modules
/ \# apk update && apk add nginx openssh openssl
# create certification and key
/ \# mkdir -p /etc/nginx/ssl
/ \# openssl req -newkey rsa:4096 -x509 -days 365 -nodes \
			-out /etc/nginx/ssl/nginx.crt \
			-keyout /etc/nginx/ssl/nginx.key \
			-subj "/C=KR/ST=SEOUL/L=SEOUL/O=42SEOUL/OU=yohlee/CN=NGINX"
# generate ssh key and run
/ \# ssh-keygen -A
/ \# adduser --disabled-password admin
/ \# echo "admin:admin" | chpasswd
/ \# /usr/sbin/sshd
# make directory for running nginx and run server
/ \# mkdir -p /var/run/nginx
/ \# nginx -g "daemon off;"
```
---
### nginx
```Shell
# build ftps image and run
cd /srcs/nginx
docker build -t nginx-image .
kubectl apply -f nginx.yaml
```
---
### ftps

##### reference
https://github.com/lhauspie/docker-vsftpd-alpine

```Shell
# build ftps image and run
cd /srcs/ftps
docker build -t ftps-image .
kubectl apply -f vsftpd.yaml
# file upload
curl ftp://EXTERNAL-IP:21 --ssl -k -u admin:admin -T filename
# file download
curl ftp://EXTERNAL-IP:21/filename --ssl -k -u admin:admin -o ./filename
# check
kubectl get pods
kubectl exec -it ftps-pods-name -- sh 
/ \# cd home/vsftpd/user/
```
---
### mysql
```Shell
# build mysql image and run
cd /srcs/mysql
docker build -t mysql-image .
kubectl apply -f mysql.yaml
# check generated wordpress table
kubectl exec -it mysql-pods-name -- sh 
/ \# cd var/lib/mysql/wordpress
```
---
### phpmyadmin
```Shell
# build phpmyadmin image and run
cd /srcs/phpmyadmin
docker build -t phpmyadmin-image .
kubectl apply -f phpmyadmin.yaml
# check login success
minikube dashboard

move `EXTERNALIP:phpmyadmin-PORT/`
and check `wordpress table`
```
---
### wordpress
```Shell
# build wordpress image and run
cd /srcs/wordpress
```

At first, build dockerfile without `wordpress.sql` file.

** Dockerfile
```Shell
FROM alpine:latest
MAINTAINER yohlee <yohlee@student.42seoul.kr>

RUN apk update
RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib\
			php7-curl php7-mbstring php7-json php7-session mysql-client

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN rm -f latest.tar.gz
RUN mv wordpress /etc/

COPY wp-config.php /etc/wordpress/
COPY entrypoint.sh /tmp/

EXPOSE 5050
ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]
```

** wp-config.php
```php
...
...

define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'USER' );

/** MySQL database password */
define( 'DB_PASSWORD', 'PASSWORD' );

/** MySQL hostname */
define( 'DB_HOST', 'YOUR_MYSQL_SERVICE_NAME' );
define( 'WP_HOME', 'http://YOUR_EXTERNAL_IP:5050/' );
define( 'WP_SITEURL', 'http://YOUR_EXTERNAL_IP:5050/' );

...
...
```

** entrypoint.sh
```Shell
#!/bin/sh

sleep 5
# sh /tmp/init-wordpress.sh # here
php -S 0.0.0.0:5050 -t /etc/wordpress/
until [ $? != 1 ]
do
	php -S 0.0.0.0:5050 -t /etc/wordpress/
done
```

```Shell
docker build -t wordpress-image .
kubectl apply -f wordpress.yaml
```

And then 
1. connect wordpress in your web.
2. install wordpress.
3. create users and post.
4. move phpmyadmin and check your database
5. export your `wordpress.sql`
6. execute the rest files.

My Root User
* user: admin
* pass: lLp)3y6mXqwaZA(s3N
---
### influxdb

* preparation
```Shell
docker run -it alpine
/ \# apk add influxdb
/ \# vi /etc/influxdb.conf
copy and paste
```

```Shell
# build influxdb image and run
cd /srcs/influxdb
docker build -t influxdb-image .
kubectl apply -f influxdb.yaml
```
---
### telegraf

* preparation
```Shell
docker run -it alpine
/ \# apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/testing/
/ \# vi /etc/telegraf.conf
copy and paste
```

```Shell
# build telegraf image and run
cd /srcs/telegraf
docker build -t telegraf-image .
kubectl apply -f telegraf.yaml
```
---
### grafana
* preparation
```Shell
docker run -it -p 30000:3000 alpine /bin/sh
/ \# apk add grafana --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --no-cache
/ \# /usr/sbin/grafana-server --homepath=/usr/share/grafana

if you\'re using kubernetes, check `minikube docker-env` command and move CONTAINER_IP:30000

* id: admin
* pwd: admin

docker cp CONTAINER_ID:/usr/share/grafana/conf .
```

