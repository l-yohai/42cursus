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

- influxdb는 시계열데이터를 저장하는 데이터베이스로, 데이터를 수집하는 telegraf, 대시보드화 시키는 grafana와 주로 함께 사용된다.
- 효율성이 좋기 때문에 influxdb는 60%가 넘는 점유율을 차지하고 있으며, 점점 사용량이 많아지는 추세임. 기본적으로 8086 포트와 연결된다.
- 쿠버네티스를 이용하여 influxdb를 구축하기 위해서는, 알파인 리눅스 환경에서 influxdb를 실행 후 conf파일을 준비해놓을 필요가 있다. `/etc/infuxdb.conf/`
- mysql과 동일하게 persistent volume claim을 이용하여 telegraf와 grafana등 다른 컨테이너에서 접속할 수 있게끔 설정을 해주어야 한다. 미리 준비해놓은 conf파일을 컨피그맵으로 설정하고, yaml파일에서 환경변수들을 이용하여 서버를 초기화한다.

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

- telegraf는 데이터 수집을 위한 컨테이너이다. 위의 과정까지 진행했으면, influxdb에 telegraf라는 '빈' 데이터베이스가 만들어져있는데, 이 telegraf 컨테이너를 통해 수집한 데이터를 influxdb에 저장시켜줄 것이다.
- alpine linux환경에서 telegraf를 install한 뒤 conf파일을 이용하여 수집하려는 데이터의 input과 수집한 데이터를 저장할 output을 지정해야 한다.

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
- grafana의 dashboard에서는 수집하고 저장한 시계열 데이터를 시각화하여 볼 수 있다.
- 쿠버네티스로 grafana를 이용하기 위해서는 아래와 같이 /usr/share/grafana/conf 폴더를 미리 준비한 이후 yaml파일을 통해 config 파일들을 수정해야 한다.
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
- 도커 컨테이너에서 grafana의 conf폴더를 가져온 이후에, provisioning의 datasource와 dashboards 폴더의 yaml파일을 이용한다.
