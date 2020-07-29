FROM alpine:latest
MAINTAINER yohlee <yohlee@student.42seoul.kr>

RUN apk update
RUN apk add grafana --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --no-cache

RUN mkdir -p /etc/grafana

COPY conf/provisioning/dashboards /usr/share/grafana/public/dashboards
COPY conf/provisioning/datasources/influxdb.yaml /usr/share/grafana/conf/provisioning/datasources/influxdb.yaml
COPY conf/provisioning/dashboards/dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/dashboards.yaml

EXPOSE 3000

ENTRYPOINT ["/usr/sbin/grafana-server","--config=/usr/share/grafana/conf/custom.ini","--homepath=/usr/share/grafana"]