minikube start --driver=virtualbox
#./42toolbox/init_docker
eval $(minikube -p minikube docker-env)

echo "metalLB manifest"
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

cd srcs/metallb
kubectl apply -f metallb.yaml
cd ../..

cd srcs/nginx/
docker build -t nginx-image .
kubectl apply -f nginx.yaml
cd ../..

cd srcs/ftps/
docker build -t ftps-image .
kubectl apply -f ftps.yaml
cd ../..

cd srcs/mysql
docker build -t mysql-image .
kubectl apply -f mysql.yaml
cd ../..

cd srcs/phpmyadmin
docker build -t phpmyadmin-image .
kubectl apply -f phpmyadmin.yaml
cd ../..
