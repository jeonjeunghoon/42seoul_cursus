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

service nginx start

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt
chmod 600 etc/ssl/private/localhost.dev.key

cp ./tmp/default ./etc/nginx/sites-available/default

service php7.3-fpm start

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
rm latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress

service mysql start
echo "CREATE DATABASE wordpress;" | mysql
echo "SHOW DATABASES;" | mysql
echo "CREATE USER 'jeunjeon'@'localhost' IDENTIFIED BY 'jeunjeon';" | mysql
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'jeunjeon'@'localhost' WITH GRANT OPTION;" | mysql
echo "USE wordpress;" | mysql
echo "SHOW TABLES;" | mysql

cp ./tmp/wp-config.php ./var/www/html/wordpress/wp-config.php

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
rm phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/

mysql < /var/www/html/phpmyadmin/sql/create_tables.sql

cp ./tmp/config.inc.php ./var/www/html/phpmyadmin/config.inc.php

service nginx reload
service php7.3-fpm reload

bash
