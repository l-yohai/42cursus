# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohlee <yohlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 17:51:07 by yohlee            #+#    #+#              #
#    Updated: 2020/07/29 06:18:08 by yohlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
MAINTAINER yohlee <yohlee@student.42seoul.kr>

# install
RUN apt-get update
RUN apt-get install nginx -y
RUN apt-get install php-fpm -y
RUN apt-get install mariadb-server -y
RUN apt-get install php-mysql -y
RUN apt-get install php-cli -y
RUN apt-get install php-mbstring -y
RUN apt-get install openssl -y

# copy
COPY srcs/start.sh ./
COPY srcs/nginx.conf /etc/nginx/sites-available/localhost
COPY srcs/config.inc.php /var
COPY srcs/wp-config.php /var
COPY srcs/phpMyAdmin-4.9.0.1-all-languages.tar.gz ./
COPY srcs/wordpress-5.4.1.tar.gz ./

# start
CMD bash start.sh
#CMd sleep inf

EXPOSE 80 443
