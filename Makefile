help:
	@echo ""
	@echo "Welcome to dev-containers. A list of containers for developing purposes is here"
	@echo "Run 'make build' before to run any container."
	@echo "To start a container, just check 'make ls' and start the one which you want to with 'docker start <selected-container>'."
	@echo "To connect a container with a network run 'docker network connect <network> <selected-container>"
	@echo "To check the container's ip, just run 'docker inspect <selected-container>"
	@echo ""
	@echo "	build	- Build the containers"
	@echo "	ls	- List containers"
	@echo ""

build:
	@g++ src/build.cpp -o bin/build
	@./bin/build
ls:
	@ls containers
