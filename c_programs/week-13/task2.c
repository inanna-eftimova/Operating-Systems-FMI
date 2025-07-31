#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "w");
    if (!f) {
        perror("fopen");
        return 1;
    }

    int c;
    while ((c = getchar()) != EOF) {
        fputc(c, f);
        putchar(c);
    }

    fclose(f);
    return 0;
}
