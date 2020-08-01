FROM alpine:latest
MAINTAINER yohlee <yohlee@student.42seoul.kr>

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.14.0-static_linux_amd64.tar.gz
RUN tar -xzf telegraf-1.14.0-static_linux_amd64.tar.gz
RUN mv /telegraf /etc/
RUN rm -rf telegraf-1.14.0-static_linux_amd64.tar.gz

COPY telegraf.conf /etc/telegraf/
COPY entrypoint.sh /tmp/

ENTRYPOINT ["sh", "/tmp/entrypoint.sh"]