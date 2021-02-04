FROM alpine:latest

COPY files /tmp/init/

RUN apk --no-cache add mysql mysql-client \
&& mv /tmp/init/run.sh / \
&& mysql_install_db --user=root --datadir=/var/lib/mysql \
&& mv /tmp/init/mariadb-server.cnf /etc/my.cnf.d/ \
&& cat /tmp/init/query.sql | mysqld --datadir=/var/lib/mysql --user=root --bootstrap --skip-grant-tables=0

EXPOSE 3306

CMD ["sh", "run.sh"]