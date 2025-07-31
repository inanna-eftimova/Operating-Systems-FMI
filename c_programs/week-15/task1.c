#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd = open("abc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    for (int i = 0; i < 2; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            // child writes "hello"
            const char *msg = "hello\n";
            write(fd, msg, 6);
            _exit(0);
        }
    }

    // parent waits for children
    for (int i = 0; i < 2; i++) {
        wait(NULL);
    }

    close(fd);
    return 0;
}
