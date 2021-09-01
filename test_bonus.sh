#!/bin/bash --posix

norminette | grep 'Error: '
make bonus > /dev/null && echo make: ok!

./t.sh main_bonus.c cat "wc -l"
./tb.sh main_bonus.c cat "grep int" "wc -l"
./t.sh main.c "t.exit.sh 0" "t.exit.sh -1"
./tb.sh main.c "t.exit.sh 0" "t.exit.sh -1" "t.exit.sh 0"
./tb.sh main.c "t.exit.sh 0" "t.exit.sh -1" "t.exit.sh 256"
./tb.sh main.c "t.exit.sh 1" "t.exit.sh -1" "t.exit.sh 0"
