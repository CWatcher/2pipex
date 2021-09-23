#!/bin/bash --posix
# sample usage: ./t.sh main.c cat "wc -l"


< $1 $2 | $3 > out.txt
ls -l $1 out.txt > out.0.txt
cat out.txt >> out.0.txt
echo 'Exit status =' $? >> out.0.txt

rm -f out.txt
./pipex "$1" "$2" "$3" out.txt
ls -l $1 out.txt > out.1.txt
cat out.txt >> out.1.txt
echo 'Exit status =' $? >> out.1.txt

diff out.0.txt out.1.txt && echo "ok!"
