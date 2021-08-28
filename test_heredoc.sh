#!/bin/bash --posix
make bonus > /dev/null && echo make: ok!
./t.heredoc_sample.sh | cat | wc >> out.0.txt
cat t.heredoc_sample.txt | ./pipex here_doc q cat wc out.txt
diff out.0.txt out.txt && echo "ok!"
