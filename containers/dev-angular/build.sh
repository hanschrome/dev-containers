#!/bin/bash

docker stop dev-angular
docker rm dev-angular
docker create -t -v $(realpath ~)/Projects:/home/developer/Projects \
	-p 4200:4200 -p 3000:3000 \
	--name dev-angular dev-angular

