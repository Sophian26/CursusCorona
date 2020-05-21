rm -rf /etc/nginx/sites-enabled/nginx.conf
cp nginx/nginx_indexing.conf /etc/nginx/sites-enabled
service nginx restart