FROM alpine:latest

COPY files /tmp/init

RUN apk --no-cache add nginx php7-mysqli php7-fpm php7-mbstring php7-json php7-session telegraf \
&& mkdir html \
&& mkdir html/phpmyadmin \
&& wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz \
&& tar -zxvf phpMyAdmin-5.0.4-all-languages.tar.gz --strip-components=1 -C /html \
&& tar -zxvf phpMyAdmin-5.0.4-all-languages.tar.gz --strip-components=1 -C /html/phpmyadmin \
&& cp /tmp/init/config.inc.php /html \
&& cp /tmp/init/config.inc.php /html/phpmyadmin \
&& mv /tmp/init/phpmyadmin.conf /etc/nginx/http.d \
&& chown -R nobody /html/ \
&& mkdir /run/nginx \
&& mv /tmp/init/telegraf.conf / \
&& mv /tmp/init/run.sh /

EXPOSE 5000

CMD ["sh", "run.sh"]