#!/bin/bash
FICHERO=test_check.txt

./checker "8 "9 1" 12" 2> test_check.txt
if [ -s "$FICHERO" ];then
while IFS= read -r line
do
  if [[ $line == "Error" ]]; then
  	printf "13.[OKKKK]\n";
  else
  	printf "13.[KO000]\n";
  	break
  fi
done < test_check.txt
else
	printf "[KO]\n";
fi

ruby -e "puts (00..99).to_a.shuffle.join(' ')"