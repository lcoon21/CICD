#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Struct {
    int flag_b;
    int flag_e;
    int flag_n;
    int flag_s;
    int flag_t;
    int flag_v;
    int flag_E;
    int flag_T;
} _flags;

void open_file(char **argv, _flags *flags);
void show_error(char *argv);
void init_flags(_flags *flags);
void s21_cat(_flags *flags, FILE *fp);
int search_flag_in_str(char *argv, char c);

#endif  // SRC_CAT_S21_CAT_H_
