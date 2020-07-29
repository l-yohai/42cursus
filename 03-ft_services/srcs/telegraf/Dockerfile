FROM alpine:latest
MAINTAINER yohlee <yohlee@student.42seoul.kr>

RUN	wget https://dl.influxdata.com/telegraf/releases/telegraf-1.14.0-static_linux_amd64.tar.gz \
	&& tar -C . -xzf telegraf-1.14.0-static_linux_amd64.tar.gz \
	&& chmod +x telegraf/telegraf \
	&& cp telegraf/telegraf /usr/bin/ \
	&& rm -rf telegraf-1.14.0-static_linux_amd64.tar.gz telegraf/

ENTRYPOINT ["/usr/bin/telegraf"]