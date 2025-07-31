#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s cmd1 [cmd2 ... cmdN]\n", argv[0]);
        return 1;
    }

    int success = 0, failure = 0;

    for (int i = 1; i < argc; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            execlp(argv[i], argv[i], NULL);
            perror("execlp");
            _exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
                success++;
            else
                failure++;
        }
    }

    printf("Success: %d, Failure: %d\n", success, failure);

    return 0;
}
