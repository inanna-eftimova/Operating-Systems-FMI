#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s filename command [args...]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execlp("grep", "grep", "int", filename, NULL);
        perror("execlp grep");
        _exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);

        pid = fork();
        if (pid < 0) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            execvp(argv[2], &argv[2]);
            perror("execvp");
            _exit(1);
        } else {
            waitpid(pid, &status, 0);
            printf("Exit code of command '%s': %d\n", argv[2], WEXITSTATUS(status));
        }
    }

    return 0;
}
