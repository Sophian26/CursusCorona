FROM debian:buster

RUN apt-get update -y
RUN apt-get install -y php nginx mariadb-server wget php-cli php-mysql php-curl php-gd php-intl php-fpm php-mbstring libnss3-tools
RUN apt-get clean -y

WORKDIR /ft_server
COPY srcs .
EXPOSE 80 443

ENTRYPOINT [ "bash", "entrypoint.sh" ]