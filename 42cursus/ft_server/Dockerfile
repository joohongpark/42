FROM debian:buster

COPY src/ /tmp/init/

RUN apt-get update -y \
&& apt-get install -y --no-install-recommends \
	nginx \
	php7.3-fpm \
	php7.3-mysql \
	php7.3-mbstring \
	mariadb-server \
	patch
RUN mkdir /var/www/html/phpmy \
&& mkdir /var/www/html/wordpress \
&& mkdir /etc/certs \
&& tar -zxvf /tmp/init/phpmy.tar.gz --strip-components=1 -C /var/www/html/phpmy \
&& tar -zxvf /tmp/init/wordpress.tar.gz --strip-components=1 -C /var/www/html/wordpress \
&& cp /var/www/html/phpmy/config.sample.inc.php /var/www/html/phpmy/config.inc.php \
&& cp /var/www/html/wordpress/wp-config-sample.php /var/www/html/wordpress/wp-config.php \
&& cp /tmp/init/gen.crt /etc/certs/ \
&& cp /tmp/init/priv.key /etc/certs/ \
&& patch -l /var/www/html/phpmy/config.inc.php /tmp/init/patch/config.inc.php.patch \
&& patch -l /var/www/html/wordpress/wp-config.php /tmp/init/patch/wp-config.php.patch \
&& patch -l /etc/nginx/sites-available/default /tmp/init/patch/default.patch \
&& chown -R www-data /var/www/html/
RUN service mysql start \
&& cat /tmp/init/set_sql.sql | mysql -u root \
&& rm -rf /tmp/init/
ENTRYPOINT service php7.3-fpm start && service nginx start && service mysql start && sleep inf