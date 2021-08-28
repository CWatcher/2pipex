#!/bin/bash --posix
./t.sh main_bonus.c cat "wc -l"
./tb.sh main_bonus.c cat "grep int" "wc -l"
