#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    int m, n;
    printf("Enter m and n (positions): ");
    if (scanf("%d %d", &m, &n) != 2 || m <= 0 || n < m) {
        fprintf(stderr, "Invalid input for m and n\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("fopen");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, f) != -1) {
        int line_len = 0;
        
        while (line[line_len] != '\0' && line[line_len] != '\n') line_len++;

        int end_pos = (n > line_len) ? line_len : n;

        if (m <= end_pos) {
            for (int i = m - 1; i < end_pos; i++) {
                putchar(line[i]);
            }
        }
        putchar('\n');
    }

    free(line);
    fclose(f);
    return 0;
}
