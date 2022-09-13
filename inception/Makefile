all: build
	sudo mkdir -p /home/mservais/data 
	sudo mkdir -p /home/mservais/data/database
	sudo mkdir -p /home/mservais/data/website
	sudo chmod 777 /etc/hosts
	sudo echo "127.0.0.1 mservais.42.fr" >> /etc/hosts
	sudo echo "127.0.0.1 www.mservais.42.fr" >> /etc/hosts
	cd srcs && sudo docker compose up -d

build:
	cd srcs && sudo docker compose build

up:
	cd srcs && sudo docker compose up -d

down:
	cd srcs && sudo docker compose down

clean:
	cd srcs && sudo docker compose down -v --rmi all --remove-orphans

fclean: clean
	sudo docker system prune --volumes -af
	sudo docker network prune -f
	sudo docker image prune -f
	sudo rm -rf /home/mservais/data

re: fclean all

.PHONY: all clean fclean re
