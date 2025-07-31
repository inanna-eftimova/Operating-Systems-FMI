#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s output_file\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "w");
    if(!f) {
        perror("fopen");
        return 1;
    }

    int c;
    while((c = getchar()) != EOF) {
        if(c == '\t') {
            fputs(">>>", f);
            fprintf(stderr, ">>>");
        } else {
            fputc(c, f);
            fputc(c, stderr);
        }
    }

    fclose(f);
    return 0;
}
