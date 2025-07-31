#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if(!f) {
        perror("fopen");
        return 1;
    }

    int lines = 0, words = 0, bytes = 0;
    int c, in_word = 0;

    while((c = fgetc(f)) != EOF) {
        bytes++;

        if(c == '\n')
            lines++;

        if(isspace(c))
            in_word = 0;
        else if(!in_word) {
            in_word = 1;
            words++;
        }
    }

    fclose(f);

    printf("Lines: %d Words: %d Bytes: %d\n", lines, words, bytes);

    return 0;
}
