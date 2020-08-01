FROM alpine:latest
MAINTAINER yohlee <yohlee@student.42seoul.kr>

RUN apk add grafana --repository=http://dl-3.alpinelinux.org/alpine/edge/testing/
# RUN mkdir -p /var/lib/grafana/dashboards

# COPY srcs/datasources.yaml /usr/share/grafana/conf/provisioning/datasources/
# COPY srcs/dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/
# COPY srcs/config.json /var/lib/grafana/dashboards/
COPY entrypoint.sh /tmp/

EXPOSE 3000

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]