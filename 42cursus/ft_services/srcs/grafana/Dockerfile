FROM alpine:latest

RUN apk --no-cache add grafana

EXPOSE 3000

CMD ["grafana-server", "-homepath", "/usr/share/grafana"]