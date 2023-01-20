CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE

all: s21_cat test

s21_cat:
	$(CC) $(CFLAGS) s21_cat.c -o s21_cat

test: s21_cat
	chmod 777 test.sh
	./test.sh

style:
	python3 ../../materials/linters/cpplint.py --extensions=c,h --recursive ./
	cppcheck --enable=all --suppress=missingIncludeSystem ./

clean:
	rm -f ./s21_cat
	rm -rf s21_cat.txt orig_cat.txt

rebuild: clean all
