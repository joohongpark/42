#!/bin/sh
telegraf --config telegraf.conf &
php-fpm7
nginx -g "daemon off;"