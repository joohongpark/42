#!/bin/sh
telegraf --config telegraf.conf &
grafana-server -homepath /usr/share/grafana