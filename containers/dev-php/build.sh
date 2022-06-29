#!/bin/bash

docker stop dev-php
docker rm dev-php
docker create -t -v $(realpath ~)/Projects:/home/developer/Projects \
	-p 80:80 -p 8000:8000 \
	--name dev-php dev-php

