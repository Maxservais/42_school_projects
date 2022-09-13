#!/bin/sh

chown -R mysql:mysql /var/lib/mysql /var/run/mysqld

if [ ! -d /var/lib/mysql/$MYSQL_DATABASE ]; then
	service mysql start

	mysql -u root -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;"
	mysql -u root -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
	mysql -u root -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';"
	mysql -u root -e "FLUSH PRIVILEGES;"

	mysqladmin -u root password $MYSQL_ROOT_PASSWORD;

	service mysql stop
fi

exec "$@"
