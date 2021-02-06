#!/bin/sh
telegraf --config telegraf.conf &
influxd run -config /etc/influxdb.conf