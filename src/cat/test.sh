#!/bin/bash

rm -rf orig_cat.txt
rm -rf s21_cat.txt

cat -b ../files/cat/test_cat.txt >> orig_cat.txt
./s21_cat -b ../files/cat/test_cat.txt >> s21_cat.txt
diff orig_cat.txt s21_cat.txt

cat -b ../files/cat/cat.txt >> orig_cat.txt
./s21_cat -b ../files/cat/cat.txt >> s21_cat.txt
diff orig_cat.txt s21_cat.txt

cat -e ../files/cat/test_cat.txt >> orig_cat.txt
./s21_cat -e ../files/cat/test_cat.txt >> s21_cat.txt
diff orig_cat.txt s21_cat.txt

cat -n ../files/cat/test_cat.txt >> orig_cat.txt
./s21_cat -n ../files/cat/test_cat.txt >> s21_cat.txt
diff orig_cat.txt s21_cat.txt

cat -s ../files/cat/test_cat.txt >> orig_cat.txt
./s21_cat -s ../files/cat/test_cat.txt >> s21_cat.txt
diff orig_cat.txt s21_cat.txt

cat -t ../files/cat/test_cat.txt >> orig_cat.txt
./s21_cat -t ../files/cat/test_cat.txt >> s21_cat.txt
diff orig_cat.txt s21_cat.txt

cat ../files/cat/test_cat.txt >> orig_cat.txt
./s21_cat ../files/cat/test_cat.txt >> s21_cat.txt
diff orig_cat.txt s21_cat.txt

cat ../files/test3 >> orig_cat.txt
./s21_cat ../files/test3 >> s21_cat.txt
diff orig_cat.txt s21_cat.txt
