FROM alpine:latest

COPY query.sql /tmp/init/

RUN apk --no-cache add mysql \
&& mysql_install_db --user=root --datadir=/var/lib/mysql \
&& cat /tmp/init/query.sql | mysqld --datadir=/var/lib/mysql --user=root --bootstrap --skip-grant-tables=0

EXPOSE 3306

ENTRYPOINT ["mysqld_safe", "--user=root", "--datadir=/var/lib/mysql"]