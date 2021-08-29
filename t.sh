#!/bin/bash --posix
# sample usage: ./t.sh main.c cat "wc -l"

< $1 $2 | $3 > out.0.txt
echo 'Exit status =' $? >> out.0.txt

./pipex "$1" "$2" "$3" out.txt
echo 'Exit status =' $? >> out.txt

diff out.0.txt out.txt && echo "ok!"
