CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE

all: s21_grep test

s21_grep:
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep

test: s21_grep
	chmod 777 test.sh
	./test.sh

style:
	python3 ../../materials/linters/cpplint.py --extensions=c,h --recursive ./
	cppcheck --enable=all --suppress=missingIncludeSystem ./

clean:
	rm -rf ./s21_grep
	rm -rf s21_grep.txt orig_grep.txt

rebuild: clean all
