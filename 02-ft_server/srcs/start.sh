#!/bin/bash

service mysql start

chown -R www-data /var/www/*
chmod -R 755 /var/www/*

mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
			-out /etc/nginx/ssl/localhost.pem \
			-keyout /etc/nginx/ssl/localhost.key \
			-subj "/C=KR/ST=SEOUL/L=SEOUL/O=42 School/OU=yohlee/CN=localhost"

ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/
rm -rf /etc/nginx/sites-enabled/default

echo "CREATE DATABASE wordpress;" \
		| mysql -u root --skip-password
echo "UPDATE mysql.user SET plugin = 'mysql_native_password' WHERE user='root';" \
		| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* to 'root'@'localhost';" \
		| mysql -u root --skip-password
echo "FLUSH PRIVILEGES" \
		| mysql -u root --skip-password

mkdir -p /var/www/localhost/phpmyadmin
tar -xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz
mv phpMyAdmin-4.9.0.1-all-languages phpmyadmin
mv phpmyadmin /var/www/localhost/
mv /var/config.inc.php /var/www/localhost/phpmyadmin/
rm phpMyAdmin-4.9.0.1-all-languages.tar.gz

tar -xvf wordpress-5.4.1.tar.gz
mv wordpress/ /var/www/localhost
mv /var/wp-config.php /var/www/localhost/wordpress
rm wordpress-5.4.1.tar.gz

service php7.3-fpm start
service nginx start

bash
