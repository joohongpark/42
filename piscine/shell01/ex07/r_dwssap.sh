#!/bin/sh
cat /etc/passwd | grep -e "^[^#]" | awk "NR % 2 == 0" | awk -F ':' '{ print $1 }' | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | tr '\r\n' ',' | sed 's/,/, /g' | rev | cut -c 3- | rev | tr '\n' '.'
