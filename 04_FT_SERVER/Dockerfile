# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeunjeon <jeunjeon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 21:36:04 by jeunjeon          #+#    #+#              #
#    Updated: 2020/12/30 21:36:40 by jeunjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:buster
# FROM은 어떤 이미지를 기반으로 이미지를 생성할 것인지 정의한다.
# FROM <image>:<tag> 형식
# image는 생략할 수 없지만 tag는 생략가능함. tag 생략시 latest 버전이 디폴드값임
# image를 생성할 때 데이터가 로컬에 있다면 로컬에서 가져온다. 반면에 로컬에 없다면 도커허브에서 가져온다.

LABEL	maintainer="jeunjeon@student.42seoul.kr"

RUN		apt-get update && apt-get install -y \
		wget \
		nginx \
		openssl \
		php7.3-fpm \
		mariadb-server \
		php-mysql \
		php-mbstring
# 이미지에서 명령을 실행한다.

ADD		./srcs/run.sh ./
ADD		./srcs/default ./tmp
ADD		./srcs/wp-config.php ./tmp
ADD		./srcs/config.inc.php ./tmp
# 미리 수정해둔 파일을 컨테이너 안에 넣는다.

EXPOSE	80 443
# 호스트와 연결할 포트번호를 설정한다.

CMD		bash run.sh
# 컨테이너가 시작되었을 때, 스크립트 혹은 명령을 실행한다.
# CMD는 Dockerfile에서 한 번만 사용 가능하다.