#!/bin/sh
# sample usage: ./tb.sh main.c cat "grep int" "wc -l"
mkdir tst
< $1 $2 | $3 | $4 > tst/out.0.txt
pipex "$1" "$2" "$3" "$4" tst/out.txt
diff tst/out.0.txt tst/out.txt
