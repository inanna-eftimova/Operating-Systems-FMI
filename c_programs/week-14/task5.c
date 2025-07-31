#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int run_command(char *cmd) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        execlp(cmd, cmd, NULL);
        perror("execlp");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return (WIFEXITED(status) && WEXITSTATUS(status) == 0);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s command1 command2\n", argv[0]);
        return 1;
    }

    if (run_command(argv[1])) {
        run_command(argv[2]);
    }

    return 0;
}
