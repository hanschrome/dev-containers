FROM debian:buster-slim

EXPOSE 3000 4200

ENV TZ=Europe/Madrid
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt update -y && apt upgrade -y

RUN apt install sudo curl wget git -y

RUN curl -fsSL https://deb.nodesource.com/setup_18.x | bash -
RUN apt-get install -y nodejs

RUN npm install -g @angular/cli

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

RUN echo 'echo ------------- ALIASES -----------------' >> /home/developer/.bashrc
RUN echo 'echo ng-serve - Runs ng serve --host 0.0.0.0 --disable-host-check' >> /home/developer/.bashrc
RUN echo 'echo ---------------------------------------' >> /home/developer/.bashrc
RUN echo 'alias ng-serve="ng serve --host 0.0.0.0 --disable-host-check"' >> /home/developer/.bashrc

