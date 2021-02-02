FROM alpine:latest

COPY files /tmp/init

RUN apk --no-cache add vsftpd \
&& adduser --disabled-password joopark \
&& echo 'joopark:joopark' | chpasswd \
&& mv /tmp/init/certs /cert \
&& mv /tmp/init/vsftpd.conf /

EXPOSE 21
EXPOSE 42420

CMD vsftpd vsftpd.conf