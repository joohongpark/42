FROM alpine:latest

COPY files /tmp/init

RUN apk --no-cache add nginx openssh \
&& ssh-keygen -t rsa -f /etc/ssh/ssh_host_rsa_key -N '' \
&& echo 'root:joopark' | chpasswd \
&& mv /tmp/init/sshd_config /etc/ssh/sshd_config \
&& mv /tmp/init/certs /cert \
&& mv /tmp/init/html /html \
&& rm /etc/nginx/http.d/default.conf \
&& mv /tmp/init/http.conf /tmp/init/https.conf /etc/nginx/http.d \
&& mkdir /run/nginx

EXPOSE 22
EXPOSE 80
EXPOSE 443

CMD /usr/sbin/sshd && nginx -g "daemon off;"