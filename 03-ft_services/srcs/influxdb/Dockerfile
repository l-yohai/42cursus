FROM alpine:latest
MAINTAINER yohlee <yohlee@student.42seoul.kr>

RUN apk add influxdb

COPY influxdb.conf /etc/
COPY entrypoint.sh /tmp/

VOLUME ["/var/lib/influxdb"]

EXPOSE 8086

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]