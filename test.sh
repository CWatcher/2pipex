#!/bin/sh

make pipex

./t.sh main.c cat "wc -l"

#$PATH

[ ! -d bin1 ] && mkdir bin1
[ ! -d bin2 ] && mkdir bin2
PATH_SAVED=$PATH
PATH=bin1:bin2:$PATH

# cd bin1
# ln -sf no_file ls
ln -sf no_file bin1/ls
# cd ..
ln -sf /bin/ls bin2
echo test1 error output: > out.error.txt

./t.sh main.c ls wc 2>> out.error.txt

echo ---------------------------------- >> out.error.txt
head -c 20 /bin/ls > bin1/ls
tail -c +19 /bin/ls > bin1/ls
chmod +x bin1/ls

echo test2 error output: >> out.error.txt

./t.sh main.c ls wc 2>> out.error.txt

echo ---------------------------------- >> out.error.txt

echo "\n"
cat out.error.txt

PATH=$PATH_SAVED
rm -rf bin1 bin2
