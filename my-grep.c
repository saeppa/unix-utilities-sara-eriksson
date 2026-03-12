#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static int grep_stream(FILE *fp, const char *needle) {
    char *line = NULL;
    size_t cap = 0;
    ssize_t n;
    while ((n = getline(&line, &cap, fp)) != -1) {
        if (strstr(line, needle) != NULL) {
            printf("%s", line);
        }
    }
    free(line);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-grep: searchterm [file ...]\n");
        return 1;
    }

    const char *needle = argv[1];

    if (argc == 2) {
        grep_stream(stdin, needle);
        return 0;
    }

    for (int i = 2; i < argc; i++) {
        const char *path = argv[i];
        FILE *fp = fopen(path, "r");
        if (fp == NULL) {
            printf("my-grep: cannot open file\n");
            return 1;
        }
        grep_stream(fp, needle);
        fclose(fp);
    }

    return 0;
}
