#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static int unzip_stream(FILE *fp) {
    int32_t count;
    unsigned char ch;

    while (1) {
        size_t rn = fread(&count, sizeof(int32_t), 1, fp);
        if (rn != 1) {
            break;
        }
        int c2 = fgetc(fp);
        if (c2 == EOF) {
            break;
        }
        ch = (unsigned char)c2;

        for (int32_t i = 0; i < count; i++) {
            fputc(ch, stdout);
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("my-unzip: file1 [file2 ...]\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "rb");
        if (fp == NULL) {
            printf("my-unzip: cannot open file\n");
            return 1;
        }
        unzip_stream(fp);
        fclose(fp);
    }

    return 0;
}
