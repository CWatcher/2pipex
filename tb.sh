#!/bin/bash --posix
# sample usage: ./tb.sh main.c cat "grep int" "wc -l"

< $1 $2 | $3 | $4 > out.0.txt
echo 'Exit status =' $? >> out.0.txt

./pipex "$1" "$2" "$3" "$4" out.txt
echo 'Exit status =' $? >> out.txt

diff out.0.txt out.txt && echo "ok!"
