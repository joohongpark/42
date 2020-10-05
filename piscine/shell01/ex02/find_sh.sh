find . -name "*.sh" | grep -oe "[^/]*\.sh$" | rev | cut -c 4- | rev
