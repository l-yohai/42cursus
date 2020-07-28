echo "metalLB delete"
cd metallb
kubectl delete -f metallb.yaml
cd ..

echo "nginx delete"
cd nginx
kubectl delete -f nginx.yaml
cd ..

echo "ftps delete"
cd ftps
kubectl delete -f ftps.yaml
cd ..

echo "mysql delete"
cd mysql
kubectl delete -f mysql.yaml
cd ..

echo "phpmyadmin delete"
cd phpmyadmin
kubectl delete -f phpmyadmin.yaml
cd ..