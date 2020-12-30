FROM	debian:buster

LABEL	maintainer="jeunjeon@student.42seoul.kr"

RUN		apt-get update && apt-get install -y \
		wget \
		nginx \
		openssl \
		php7.3-fpm \
		mariadb-server \
		php-mysql \
		php-mbstring

ADD		./srcs/run.sh ./
ADD		./srcs/default ./tmp
ADD		./srcs/wp-config.php ./tmp
ADD		./srcs/config.inc.php ./tmp

EXPOSE	80 443

CMD		bash run.sh
