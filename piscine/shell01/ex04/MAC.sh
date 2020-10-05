ifconfig -a | grep -oe "ether\s[^\s]*$" | cut -c 7- | tr -d ' '
