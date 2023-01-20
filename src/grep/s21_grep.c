#include "s21_grep.h"

int main(int argc, char* argv[]) {
    t_flags_grep flags;
    s21_init(&flags);
    int file_numbers = 0, find = 0, i = 1;
    char* find_str = calloc(1000, sizeof(char));
    s21_strcat(find_str, convert_for_char('('));
    while (i < argc) {
        if (argv[i][0] == '-') {
            if (flag_to_int(argv[i], 'e')) {
                s21_strcpy(find_str, convert_for_char('('));
                s21_strcat(find_str, argv[i + 1]);
                flags.e = 1;
                if (flags.f == 0) {
                    s21_strcpy(find_str, convert_for_char('('));
                    s21_strcat(find_str, argv[i + 1]);
                }
                i++;
            }
            flags.i = flags.i == 1 ? 1 : flag_to_int(argv[i], 'i');
            flags.v = flags.v == 1 ? 1 : flag_to_int(argv[i], 'v');
            flags.c = flags.c == 1 ? 1 : flag_to_int(argv[i], 'c');
            flags.l = flags.l == 1 ? 1 : flag_to_int(argv[i], 'l');
            flags.n = flags.n == 1 ? 1 : flag_to_int(argv[i], 'n');
            flags.h = flags.h == 1 ? 1 : flag_to_int(argv[i], 'h');
            flags.s = flags.s == 1 ? 1 : flag_to_int(argv[i], 's');
            flags.o = flags.o == 1 ? 1 : flag_to_int(argv[i], 'o');
            if (flag_to_int(argv[i], 'f')) {
                flags.f = 1;
                filename_flagf(find_str, &flags, argv, i);
                i++;
            }
        } else {
            if (flags.e == 0 && flags.f == 0 && find == 0) {
                find++;
                s21_strcat(find_str, argv[i]);
            } else {
                file_numbers++;
            }
        }
        i++;
    }
    if (find_str) s21_strcat(find_str, convert_for_char(')'));
    open_file(&flags, argv, file_numbers, find_str);
    free(find_str);
}

void s21_init(t_flags_grep *flags) {
    flags->i = 0;
    flags->e = 0;
    flags->c = 0;
    flags->n = 0;
    flags->v = 0;
    flags->h = 0;
    flags->l = 0;
    flags->s = 0;
    flags->f = 0;
    flags->o = 0;
}

int flag_to_int(char* flags, char flag) {
    int tmp = 0;
    for (int i = 0; i < (int)strlen(flags); i++) {
        if (flags[i] == flag) {
            tmp = 1;
            break;
        }
    }
    return tmp;
}

char* convert_for_char(unsigned int num) {
    static char buffer[2];
    char* ptr;
    ptr = &buffer[1];
    *ptr = '\0';
    *--ptr = (char)num;
    return (ptr);
}

char* s21_strcat(char* dest, const char* src) {
    size_t i, j;
    for (i = 0; dest[i] != '\0'; i++) {
    }
    for (j = 0; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}

char* s21_strcpy(char* dest, const char* src) {
    char* tmp = dest;
    for (; *src; src++, dest++)
        *dest = *src;
    *dest = 0;
    return tmp;
}

void* s21_to_lower(const char* str) {
    short isError = 1;
    char* temp_str = calloc((strlen(str) + 1), sizeof(char));
    if (temp_str) {
        s21_strcpy(temp_str, str);
        for (char* p = (char*)temp_str; *p != '\0'; p++) {
            if (*p >= 'A' && *p <= 'Z') {
                *p += 32;
            }
        }
        isError = 0;
    }
    return (isError) ? NULL : (void*)temp_str;
}

void open_file(t_flags_grep *flags, char** argv, int file_numbers, char* find_str) {
    FILE* fp;
    char* filename;
    int find = 0;
    argv++;
    while (*argv) {
        if (flag_to_int(*argv, '-')) {
            if (flag_to_int(*argv, 'e') || flag_to_int(*argv, 'f'))
                argv++;
            argv++;
        } else {
            if (find == 0 && flags->e == 0 && flags->f == 0) {
                find++;
                argv++;
            } else if ((fp = fopen(*argv, "r")) == NULL) {
                argv++;
            } else {
                filename = *argv++;
                s21_grep(flags, file_numbers, find_str, fp, filename);
                fclose(fp);
            }
        }
    }
}

void filename_flagf(char* find_str, t_flags_grep *flags, char* argv[], int i) {
    FILE* fp;
    fp = fopen(argv[i + 1], "r");
    if (fp == NULL) exit(EXIT_FAILURE);
    char current, prev = 'z';
    if (flags->e > 0 && flags->f > 0) {
        s21_strcat(find_str, convert_for_char('|'));
    }
    while ((current = getc(fp)) != EOF) {
        if (prev == '\n' && current != '\n') {
            s21_strcat(find_str, convert_for_char('|'));
        }
        if (current != '\n') {
            s21_strcat(find_str, convert_for_char(current));
        }
        if (prev == '\n' && current == '\n') {
            s21_strcat(find_str, convert_for_char('|'));
            s21_strcat(find_str, "\n");
        }
        prev = current;
    }
    fclose(fp);
}

void s21_grep_flag_n(t_flags_grep *flags, int count, char* line) {
    if (flags->n && !flags->c && !flags->l) {
        printf("%d:", count);
        printf("%s", line);
    } else if (!flags->c && !flags->l) {
        printf("%s", line);
    }
}

void flags_vcl(t_flags_grep *flags, int count_c, int count_vc, char* filename) {
    if (flags->l && !flags->v) {
        if (count_c != 0) {
            printf("%s\n", filename);
        }
    } else if (flags->l && flags->v) {
        if (count_vc != 0)
            printf("%s\n", filename);
    }
    if (flags->c && !flags->v && !flags->l) {
        printf("%s:", filename);
        printf("%d\n", count_c);
    } else if (flags->c && flags->v && !flags->l) {
        printf("%d", count_vc);
    }
}

void s21_grep(t_flags_grep *flags, int file_numbers, char* find_str, FILE* fp, char* filename) {
    regex_t regex;
    char* line = NULL;
    size_t len = 0, nmatch = 2;
    int count = 1, count_c = 0, count_vc = 0, reti, read;
    if (flags->i) {
        char* tmp_find_str = s21_to_lower(find_str);
        regcomp(&regex, tmp_find_str, REG_EXTENDED);
        free(tmp_find_str);
    } else {
        regcomp(&regex, find_str, REG_EXTENDED);
    }
    regmatch_t pmatch[2];
    while ((read = getline(&line, &len, fp)) != EOF) {
        char* line_tmp = calloc(strlen(line), sizeof(char));
        if (line[strlen(line)] == '\n' && strlen(line) == 1)
            s21_strcat(line, "\n");
        if (line[strlen(line) - 1] != '\n')
            s21_strcat(line, "\n");
        if (flags->i) {
            s21_strcpy(line_tmp, line);
            char* line_tmp2 = s21_to_lower(line_tmp);
            reti = regexec(&regex, line_tmp2, nmatch, pmatch, 0);
            free(line_tmp2);
        } else {
            reti = regexec(&regex, line, nmatch, pmatch, 0);
        }
        if (flags->o && !flags->v && !reti) {
            if (strlen(line) != 1) {
                char* str_tmp = calloc(strlen(line) + 1, sizeof(char));
                snprintf(str_tmp, strlen(line) + 1, "%c%s", '\t', line);
                snprintf(line, strlen(line), "%.*s", (int)(pmatch[1].rm_eo - pmatch[1].rm_so),
                &str_tmp[pmatch[1].rm_so + 1]);
                s21_strcat(line, "\n");
                free(str_tmp);
            }
        }
        if (file_numbers > 1 && !flags->h && !reti && !flags->v && !flags->c && !flags->l) {
            printf("%s:", filename);
        }
        if (file_numbers > 1 && !flags->h && reti && flags->v && !flags->c && !flags->l) {
            printf("%s:", filename);
        }
        if (!reti && !flags->v) {
            s21_grep_flag_n(flags, count, line);
            count_c++;
        } else if (flags->v && reti) {
            s21_grep_flag_n(flags, count, line);
            count_vc++;
        }
        count++;
        if (line_tmp) {
            free(line_tmp);
        }
    }
    flags_vcl(flags, count_c, count_vc, filename);
    if (line) free(line);
    regfree(&regex);
}
