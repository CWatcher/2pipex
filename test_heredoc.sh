#!/bin/bash --posix

norminette | grep 'Error: '
make bonus > /dev/null && echo make: ok!

echo Old content > out.0.txt
./t.heredoc_sample.sh | cat | wc >> out.0.txt
echo 'Exit status =' $? >> out.0.txt

echo Old content > out.txt
cat t.heredoc_sample.txt | ./pipex here_doc q cat wc out.txt
echo 'Exit status =' $? >> out.txt

diff out.0.txt out.txt && echo "ok!"

#----------------------------------

echo Old content > out.0.txt
./t.heredoc_sample.sh | cat | ls >> out.0.txt
echo 'Exit status =' $? >> out.0.txt

echo Old content > out.txt
cat t.heredoc_sample.txt | ./pipex here_doc q cat ls out.txt
echo 'Exit status =' $? >> out.txt

diff out.0.txt out.txt && echo "ok!"
