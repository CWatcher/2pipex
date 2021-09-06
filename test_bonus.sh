#!/bin/bash --posix

norminette | grep 'Error: '
make bonus > /dev/null && echo make: ok!

./t.sh Makefile cat "wc -l"
./tb.sh Makefile cat "grep int" "wc -l"
./tb.sh Makefile yes ls wc
./t.sh main.c "t.exit.sh 0" "t.exit.sh -1"
./tb.sh main.c "t.exit.sh 0" "t.exit.sh -1" "t.exit.sh 0"
./tb.sh main.c "t.exit.sh 0" "t.exit.sh -1" "t.exit.sh 256"
./tb.sh main.c "t.exit.sh 1" "t.exit.sh -1" "t.exit.sh 0"
