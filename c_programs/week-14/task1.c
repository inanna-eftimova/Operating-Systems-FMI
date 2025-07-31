#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
        sleep(10); // sleep long enough for parent to finish
    } else {
        // Parent
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}
