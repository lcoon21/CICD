#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <string.h>

typedef struct flags {
    int e;
    int i;
    int v;
    int c;
    int l;
    int n;
    int h;
    int s;
    int f;
    int o;
} t_flags_grep;

void s21_init(t_flags_grep *flags);
void filename_flagf(char* find_str, t_flags_grep *flags, char* argv[], int i);
void s21_grep(t_flags_grep *flags, int file_numbers, char* find_str, FILE* fp, char* filename);
void open_file(t_flags_grep *flags, char** argv, int file_numbers, char* find_str);
void s21_grep_flag_n(t_flags_grep *flags, int count, char* line);
void flags_vcl(t_flags_grep *flags, int count_c, int count_vc, char* filename);

void* s21_to_lower(const char* str);
char* s21_strcat(char* dest, const char* src);
char* s21_strcpy(char* dest, const char* src);
int flag_to_int(char* flags, char flag);
char* convert_for_char(unsigned int num);

#endif  //  SRC_GREP_S21_GREP_H_
