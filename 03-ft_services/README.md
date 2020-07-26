# ft_services

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

### nginx
```Shell
# build ftps image and run
cd /srcs/nginx
docker build -t nginx-image .
kubectl apply -f nginx.yaml
```

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

