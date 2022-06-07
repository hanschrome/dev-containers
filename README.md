# Develop containers

Docker containers with different stacks to developing purposes.

## Getting started

Containers are generated with specific names, so they can easily be connected to manage them easily.

To build all the images, just run `make build`. The containers are created stopped. You can manage them after building with docker as usual.

Check more make options just running `make`.

## Volumes

The default volume when the container is created is ~/Projects, which will be mounted on the docker container as /home/developer/Projects.

## List of containers

1. dev-angular: Debian with nodejs and Angular CLI globally installed.

