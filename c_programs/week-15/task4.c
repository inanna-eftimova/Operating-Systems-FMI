#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int run_command(const char *cmd) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        execlp(cmd, cmd, NULL);
        perror("execlp");
        _exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return (WIFEXITED(status) && WEXITSTATUS(status) == 0);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s cmd1 cmd2 filename\n", argv[0]);
        return 1;
    }

    char *cmd1 = argv[1];
    char *cmd2 = argv[2];
    char *filename = argv[3];

    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    close(fd);

    if (run_command(cmd1)) {
        fd = open(filename, O_WRONLY | O_APPEND);
        if (fd < 0) {
            perror("open for append");
            return 1;
        }
        write(fd, cmd1, strlen(cmd1));
        write(fd, "\n", 1);
        close(fd);
    } else {
        printf("Command %s failed.\n", cmd1);
    }

    run_command(cmd2);

    return 0;
}
