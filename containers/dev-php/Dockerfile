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

RUN apt install php8.1 -y

# RUN apt remove php-yac php-imagick php-apcu -y

RUN apt install -y php8.1-amqp       php8.1-common     php8.1-gd         php8.1-ldap       php8.1-odbc       php8.1-readline   php8.1-sqlite3    php8.1-xsl php8.1-curl       php8.1-gmp        php8.1-mailparse  php8.1-opcache    php8.1-redis      php8.1-sybase     php8.1-ast        php8.1-dba        php8.1-igbinary   php8.1-mbstring   php8.1-pgsql      php8.1-rrd        php8.1-tidy       php8.1-yaml php8.1-bcmath     php8.1-dev        php8.1-imagick    php8.1-memcached  php8.1-phpdbg     php8.1-smbclient  php8.1-uuid       php8.1-zip php8.1-bz2        php8.1-ds         php8.1-imap       php8.1-msgpack    php8.1-pspell     php8.1-snmp       php8.1-xdebug     php8.1-zmq php8.1-cgi        php8.1-enchant    php8.1-interbase  php8.1-mysql      php8.1-psr        php8.1-soap       php8.1-xhprof php8.1-cli        php8.1-fpm        php8.1-intl       php8.1-oauth      php8.1-raphf      php8.1-solr       php8.1-xml

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

