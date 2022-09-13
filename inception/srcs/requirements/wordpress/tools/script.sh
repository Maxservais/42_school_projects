#!/bin/sh

# Delete and generate new wp-config.php with proper settings (dbname, dbuser, etc.)
rm -rf /var/www/wordpress/wp-config.php
wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost="mariadb" --path="/var/www/wordpress/" --allow-root --skip-check

# Install wp if it isn't installed already
if ! wp core is-installed --allow-root; then
	wp core install --url="mservais.42.fr" --title="mservais website" --admin_user="$WP_ADMIN" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="mservais@student.s19.be" --path="/var/www/wordpress" --allow-root
fi

# Create new WP user
wp user create $WP_USER $WP_USER_EMAIL --role=editor --user_pass=$WP_USER_PWD --allow-root

# Execute FPM
exec php-fpm7.3 --nodaemonize
