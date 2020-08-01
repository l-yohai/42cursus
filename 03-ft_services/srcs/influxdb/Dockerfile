FROM alpine:latest
MAINTAINER yohlee <yohlee@student.42seoul.kr>

RUN apk add influxdb --no-cache

# RUN mkdir -p /etc/influxdb
# RUN mkdir -p /var/lib/influxdb

EXPOSE 8086

ENTRYPOINT ["/usr/sbin/influxd"]