FROM alpine:latest

COPY files /tmp/init

RUN apk --no-cache add influxdb telegraf \
&& mv /tmp/init/telegraf.conf / \
&& mv /tmp/init/run.sh /

EXPOSE 8086

CMD ["sh", "run.sh"]