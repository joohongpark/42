FROM alpine:latest

COPY files /tmp/init

RUN apk --no-cache add grafana telegraf \
&& mv /tmp/init/telegraf.conf / \
&& mkdir -p /usr/share/grafana/data \
&& mv /tmp/init/grafana.db /usr/share/grafana/data/grafana.db \
&& mv /tmp/init/run.sh /

EXPOSE 3000

CMD ["sh", "run.sh"]