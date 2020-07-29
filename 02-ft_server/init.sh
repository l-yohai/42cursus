docker build -t tmp .
docker run --name ft_server -it --rm -p 80:80 -p 443:443 tmp
