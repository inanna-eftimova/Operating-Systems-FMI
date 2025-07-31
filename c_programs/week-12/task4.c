#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s input_file append_file\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if(!fin) {
        perror("fopen input");
        return 1;
    }

    FILE *fappend = fopen(argv[2], "a");
    if(!fappend) {
        perror("fopen append");
        fclose(fin);
        return 1;
    }

    char line[1024];
    while(fgets(line, sizeof(line), fin)) {
        fputs(line, stdout);

        // Extract first 3 chars of line (if available)
        char first3[4] = {0};
        strncpy(first3, line, 3);

        // Write them to append file
        fputs(first3, fappend);
    }

    fclose(fin);
    fclose(fappend);
    return 0;
}
