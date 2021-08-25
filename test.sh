#!/bin/sh

[ ! -d bin1 ] && mkdir bin1
[ ! -d bin2 ] && mkdir bin2
ln -s /bin/ls bin2
PATH_SAVED=$PATH
PATH=bin1:bin2:$PATH

./t.sh main.c ls wc 2> out.error.txt

echo "bad_format" > bin1/ls
chmod +x bin1/ls
./t.sh main.c ls wc 2> out.error.txt
cat out.error.txt

cd bin1
ln -sf no_file ls
cd ..
./t.sh main.c ls wc 2> out.error.txt
cat out.error.txt

PATH=$PATH_SAVED
rm out.error.txt
rm -rf bin1 bin2

./t.sh main.c cat "wc -l"
