FROM alpine:latest

COPY files /tmp/init

RUN apk --no-cache add nginx php7-mysqli php7-fpm php7-common php7-curl php7-json php7-mbstring php7-xml php7-zip php7-gd php7-soap php7-ssh2 php7-tokenizer telegraf \
&& wget https://ko.wordpress.org/latest-ko_KR.tar.gz \
&& mkdir html \
&& mkdir /run/nginx \
&& tar -zxvf latest-ko_KR.tar.gz --strip-components=1 -C /html \
&& mv /tmp/init/wordpress.conf /etc/nginx/http.d \
&& mv /tmp/init/wp-config.php /html \
&& dos2unix /html/wp-config.php \
&& mv /tmp/init/telegraf.conf / \
&& mv /tmp/init/run.sh /

EXPOSE 5050
EXPOSE 3306

CMD ["sh", "run.sh"]