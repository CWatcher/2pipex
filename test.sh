#!/bin/sh

make pipex > /dev/null && echo make ok!

./t.sh main.c cat "wc -l"

#$PATH

[ ! -d bin ] && mkdir bin
PATH=bin:$PATH
rm out.error.txt

ln -sf no_file bin/ls
echo test1 error output: > out.error.txt

./t.sh main.c ls wc 2>> out.error.txt

echo -e "----------------------------------\n" >> out.error.txt
head -c 20 /bin/ls > bin/ls
tail -c +19 /bin/ls > bin/ls
chmod +x bin/ls

echo test2 error output: >> out.error.txt

./t.sh main.c ls wc 2>> out.error.txt

echo -e "----------------------------------\n" >> out.error.txt
cat out.error.txt

rm -rf bin
