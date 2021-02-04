#!/bin/sh
mysqld_safe --user=root --datadir=/var/lib/mysql &
sleep 5
mysql -u root < /tmp/init/wp_db.sql
sleep inf