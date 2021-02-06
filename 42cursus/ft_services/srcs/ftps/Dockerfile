FROM alpine:latest

COPY files /tmp/init

RUN apk --no-cache add vsftpd telegraf \
&& adduser --disabled-password joopark \
&& echo 'joopark:joopark' | chpasswd \
&& mv /tmp/init/certs /cert \
&& mv /tmp/init/telegraf.conf / \
&& mv /tmp/init/run.sh / \
&& mv /tmp/init/vsftpd.conf /

EXPOSE 21
EXPOSE 42420

CMD ["sh", "run.sh"]