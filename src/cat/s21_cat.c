#include "s21_cat.h"

int main(int argc, char **argv) {
    _flags flags;
    init_flags(&flags);
    int i = 0;
    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1] != '-') {
            flags.flag_b = search_flag_in_str(argv[i], 'b');
            flags.flag_E = search_flag_in_str(argv[i], 'E');
            flags.flag_e = search_flag_in_str(argv[i], 'e');
            flags.flag_n = search_flag_in_str(argv[i], 'n');
            flags.flag_s = search_flag_in_str(argv[i], 's');
            flags.flag_T = search_flag_in_str(argv[i], 'T');
            flags.flag_t = search_flag_in_str(argv[i], 't');
            if (flags.flag_t == 1) flags.flag_v = 1;
            if (flags.flag_e == 1) flags.flag_v = 1;
        }
        if (argv[i][0] == '-' && argv[i][1] == '-') {
            if (strcmp(argv[i], "--number") == 0) flags.flag_n = 1;
            if (strcmp(argv[i], "--number-nonblank") == 0) flags.flag_b = 1;
            if (strcmp(argv[i], "--squeeze-blank") == 0) flags.flag_s = 1;
        }
        i++;
    }
    open_file(argv, &flags);
}

int search_flag_in_str(char *argv, char flag) {
    int temp = 0;
    for (int i = 0; i < (int)strlen(argv); i++) {
        if (argv[i] == flag) {
            temp = 1;
            break;
        }
    }
    return temp;
}

void open_file(char **argv, _flags *flags) {
    FILE *fp;
    argv++;
    while (*argv) {
        if (*argv[0] == '-') {
            argv++;
        } else {
            if ((fp = fopen(*argv, "r")) == NULL) {
                show_error(*argv);
                argv++;
            } else {
                s21_cat(flags, fp);
                argv++;
            }
        }
    }
}

void s21_cat(_flags *flags, FILE *fp) {
    int cnt = 1;
    char sym = ' ', pred_sym = ' ';
    while (1) {
        char pred_pred_sym = pred_sym;
        pred_sym = sym;
        if ((sym = getc(fp)) == EOF) {
            break;
        }
        if (flags->flag_s != 1 || pred_sym != '\n' || sym != '\n' ||
            pred_pred_sym != '\n') {
            if ((pred_sym == '\n') ||
                (cnt == 1 && (flags->flag_n == 1 || flags->flag_b == 1))) {
                if ((flags->flag_n == 1 && flags->flag_b == 0) ||
                    (flags->flag_b == 1 && sym != '\n')) {
                    printf("%6d\t", cnt);
                    cnt++;
                }
            }
            if (sym == '\n') {
                if (flags->flag_e == 1) {
                    printf("$");
                }
            }
            if (sym == '\t' && flags->flag_t == 1) {
                printf("^I");
            } else if (sym < 32 && flags->flag_v == 1 && sym != 9 &&
                       sym != 10) {
                printf("^%c", sym + 64);
            } else {
                printf("%c", sym);
            }
        }
    }
    fclose(fp);
}

void show_error(char *argv) {
    printf("\ncat: %s: No such file of directory", argv);
}

void init_flags(_flags *flags) {
    flags->flag_b = 0;
    flags->flag_e = 0;
    flags->flag_n = 0;
    flags->flag_s = 0;
    flags->flag_t = 0;
    flags->flag_v = 0;
}
