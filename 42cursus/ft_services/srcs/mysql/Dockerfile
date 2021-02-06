FROM alpine:latest

COPY files /tmp/init/

RUN apk --no-cache add mysql mysql-client \
&& mv /tmp/init/run.sh / \
&& mv /tmp/init/mariadb-server.cnf /etc/my.cnf.d/

EXPOSE 3306

CMD ["sh", "run.sh"]