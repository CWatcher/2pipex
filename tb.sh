#!/bin/sh
< $1 $2 | $3 > tst/out.0.txt
pipex_bonus "$1" "$2" "$3" tst/out.txt
diff tst/out.0.txt tst/out.txt
