FROM alpine:latest

COPY files /tmp/init

RUN apk --no-cache add grafana telegraf \
&& mv /tmp/init/telegraf.conf / \
&& mv /tmp/init/run.sh /

EXPOSE 3000

CMD ["sh", "run.sh"]