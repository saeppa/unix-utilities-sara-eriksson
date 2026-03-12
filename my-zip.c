#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static int zip_stream(FILE *fp) {
    int prev = EOF;
    int curr;
    int32_t count = 0;

    while ((curr = fgetc(fp)) != EOF) {
        if (prev == EOF) {
            prev = curr;
            count = 1;
            continue;
        }
        if (curr == prev) {
            if (count == INT32_MAX) {
                fwrite(&count, sizeof(int32_t), 1, stdout);
                fputc(prev, stdout);
                count = 0;
            }
            count++;
        } else {
            fwrite(&count, sizeof(int32_t), 1, stdout);
            fputc(prev, stdout);
            prev = curr;
            count = 1;
        }
    }

    if (prev != EOF) {
        fwrite(&count, sizeof(int32_t), 1, stdout);
        fputc(prev, stdout);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "rb");
        if (fp == NULL) {
            printf("my-zip: cannot open file\n");
            return 1;
        }
        zip_stream(fp);
        fclose(fp);
    }

    return 0;
}
