#!/bin/bash

rm -rf orig_grep.txt
rm -rf s21_grep.txt

./s21_grep -e qw ../files/*.txt >> s21_grep.txt
grep -e qw ../files/*.txt >> orig_grep.txt
diff orig_grep.txt s21_grep.txt

grep e ../files/*.txt >> orig_grep.txt
./s21_grep e ../files/*.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt

grep exam ../files/*.txt >> orig_grep.txt
./s21_grep exam ../files/*.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt

grep -v j ../files/*.txt >> orig_grep.txt
./s21_grep -v j ../files/*.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt

grep -c 12 ../files/*.txt >> orig_grep.txt
./s21_grep -c 12 ../files/*.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt

grep -c U+ ../files/*.txt >> orig_grep.txt
./s21_grep -c U+ ../files/*.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt

grep -i exam ../files/*.txt >> orig_grep.txt
./s21_grep -i exam ../files/*.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt

grep -l j ../files/*.txt >> orig_grep.txt
./s21_grep -l j ../files/*.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt

grep -n ere ../files/*.txt >> orig_grep.txt
./s21_grep -n ere ../files/*.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt

grep -h a ../files/*.txt >> orig_grep.txt
./s21_grep -h a ../files/*.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt

grep -f ../files/U.txt ../files/long_text.txt >> orig_grep.txt
./s21_grep -f ../files/U.txt ../files/long_text.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt

grep a -o ../files/text.txt >> orig_grep.txt
./s21_grep a -o ../files/text.txt >> s21_grep.txt
diff orig_grep.txt s21_grep.txt
