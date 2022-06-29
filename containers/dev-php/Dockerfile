FROM debian:buster-slim

EXPOSE 3000 4200

ENV TZ=Europe/Madrid
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt update -y && apt upgrade -y

RUN apt install sudo curl wget git -y

RUN apt install -y lsb-release ca-certificates apt-transport-https software-properties-common gnupg2

RUN echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" | tee /etc/apt/sources.list.d/sury-php.list

RUN wget -qO - https://packages.sury.org/php/apt.gpg | sudo apt-key add -

RUN apt update -y

RUN apt install php8.0 -y

# RUN apt remove php-yac php-imagick php-apcu -y

RUN apt install -y php8.0-amqp       php8.0-common     php8.0-gd         php8.0-ldap       php8.0-odbc       php8.0-readline   php8.0-sqlite3    php8.0-xsl php8.0-curl       php8.0-gmp        php8.0-mailparse  php8.0-opcache    php8.0-redis      php8.0-sybase     php8.0-ast        php8.0-dba        php8.0-igbinary   php8.0-mbstring   php8.0-pgsql      php8.0-rrd        php8.0-tidy       php8.0-yaml php8.0-bcmath     php8.0-dev        php8.0-imagick    php8.0-memcached  php8.0-phpdbg     php8.0-smbclient  php8.0-uuid       php8.0-zip php8.0-bz2        php8.0-ds         php8.0-imap       php8.0-msgpack    php8.0-pspell     php8.0-snmp       php8.0-xdebug     php8.0-zmq php8.0-cgi        php8.0-enchant    php8.0-interbase  php8.0-mysql      php8.0-psr        php8.0-soap       php8.0-xhprof php8.0-cli        php8.0-fpm        php8.0-intl       php8.0-oauth      php8.0-raphf      php8.0-solr       php8.0-xml

RUN export uid=1000 gid=1000 && \
    mkdir -p /home/developer && \
    echo "developer:x:${uid}:${gid}:Developer,,,:/home/developer:/bin/bash" >> /etc/passwd && \
    echo "developer:x:${uid}:" >> /etc/group && \
    echo "developer ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/developer && \
    chmod 0440 /etc/sudoers.d/developer && \
    chown ${uid}:${gid} -R /home/developer

USER developer
ENV HOME /home/developer

RUN mkdir /home/developer/Projects
WORKDIR /home/developer/Projects

# Change it after building the container if you want to manage git inside the container
RUN git config --global user.email "you@example.com"
RUN git config --global user.name "developer"

