#!/bin/bash --posix

norminette | grep 'Error: '
make pipex > /dev/null && echo make ok!

./t.sh Makefile cat "wc -l"
./t.sh Makefile yes ls
./t.sh Makefile "t.exit.sh 0" "t.exit.sh -1"
./t.sh Makefile "t.exit.sh 0" "t.exit.sh 256"
./t.sh Makefile "t.exit.sh 256" "t.exit.sh 0"

#$PATH

[ ! -d bin ] && mkdir bin
PATH=bin:$PATH
[ -f out.error.txt ] && rm out.error.txt

ln -sf no_file bin/ls
echo test1 error output: > out.error.txt

./t.sh main.c ls wc 2>> out.error.txt

echo -e "----------------------------------\n" >> out.error.txt
# If the execl() function fails due to an error equivalent to the [ENOEXEC] error <…>
#  the shell <…> shall write an error message, and shall return an exit status of 126.
#https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_01_01A
head -c 20 /bin/ls > bin/ls
tail -c +19 /bin/ls > bin/ls
chmod +x bin/ls

echo test2 error output: >> out.error.txt

./t.sh main.c ls wc 2>> out.error.txt

echo -e "----------------------------------\n" >> out.error.txt
cat out.error.txt

rm -rf bin
