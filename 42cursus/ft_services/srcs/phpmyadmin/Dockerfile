FROM alpine:latest

COPY files /tmp/init

RUN apk --no-cache add nginx php7-mysqli php7-fpm php7-mbstring php7-json php7-session \
&& mkdir html \
&& wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz \
&& tar -zxvf phpMyAdmin-5.0.4-all-languages.tar.gz --strip-components=1 -C /html \
&& mv /tmp/init/config.inc.php /html \
&& mv /tmp/init/phpmyadmin.conf /etc/nginx/http.d \
&& mkdir /run/nginx

EXPOSE 5000

CMD php-fpm7 && nginx -g "daemon off;"