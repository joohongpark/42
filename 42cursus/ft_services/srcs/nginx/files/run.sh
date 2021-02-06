#!/bin/sh
telegraf --config telegraf.conf &
/usr/sbin/sshd && nginx -g "daemon off;"