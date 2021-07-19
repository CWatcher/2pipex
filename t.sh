< $1 $2 | $3 > tst/out.0.txt
pipex "$1" "$2" "$3" tst/out.txt
diff tst/out.0.txt tst/out.txt
