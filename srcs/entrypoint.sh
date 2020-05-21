# Extract Wordpress and PMA
tar -xf web.tar.gz

# Droits
chown -R www-data:www-data wordpress/*
chmod -R 777 wordpress/
chmod +x apply_autoindexing.sh

# Database
service mysql start
echo "CREATE DATABASE wordpress;" | mysql -u root 
echo "CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'password';" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

# SSL
chmod +x mkcert
./mkcert -install
./mkcert localhost

# Delete default config of nginx and replace by mine
rm -rf /etc/nginx/sites-enabled/default
cp nginx/nginx.conf /etc/nginx/sites-enabled/

# Start FPM & Nginx
service php7.3-fpm start
service nginx start

# Boucle infinie et lecture des logs de nginx
tail -f /var/log/nginx/access.log /var/log/nginx/error.log