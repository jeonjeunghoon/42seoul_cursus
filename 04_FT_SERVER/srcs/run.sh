# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 21:36:35 by jeunjeon          #+#    #+#              #
#    Updated: 2020/12/30 21:36:38 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

apt-get upgrade
# apt-get upgrade

service nginx start
# nginx 실행

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt
chmod 600 etc/ssl/private/localhost.dev.key
# 인증서 생성

cp ./tmp/default ./etc/nginx/sites-available/default
# srcs 파일 적용

service php7.3-fpm start
# php7.3-fpm 실행

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
rm latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
# wordpress 다운로드 및 설정

service mysql start
echo "CREATE DATABASE wordpress;" | mysql
echo "SHOW DATABASES;" | mysql
echo "CREATE USER 'jeunjeon'@'localhost' IDENTIFIED BY 'jeunjeon';" | mysql
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'jeunjeon'@'localhost' WITH GRANT OPTION;" | mysql
echo "USE wordpress;" | mysql
echo "SHOW TABLES;" | mysql
# wordpress 데이터베이스 생성

cp ./tmp/wp-config.php ./var/www/html/wordpress/wp-config.php
# srcs 파일 적용

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
rm phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
# phpMyAdmin 다운로드 및 설정

mysql < /var/www/html/phpmyadmin/sql/create_tables.sql
# phpMyAdmin 데이터베이스 생성

cp ./tmp/config.inc.php ./var/www/html/phpmyadmin/config.inc.php
# scrs 파일 적용

service nginx reload
service php7.3-fpm reload
# 설정 적용

bash
