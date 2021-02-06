#!/bin/sh
telegraf --config telegraf.conf &
if [ -d "/var/lib/mysql/mysql" ]; then
    mysqld_safe --user=root --datadir=/var/lib/mysql
else
    mysql_install_db --user=root --datadir=/var/lib/mysql
    mysqld_safe --user=root --datadir=/var/lib/mysql &
    sleep 5
    mysql -u root < /tmp/init/query.sql
    mysql -u root < /tmp/init/wp_db.sql
    sleep inf
fi