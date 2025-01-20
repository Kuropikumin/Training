FROM node

RUN apt update
RUN apt install -y apache2
COPY apache2.conf /etc/apache2
COPY 000-default.conf /etc/apache2/sites-available
COPY default-ssl.conf /etc/apache2/sites-available

EXPOSE 80
CMD ["/usr/sbin/apachectl", "-D", "FOREGROUND"]
