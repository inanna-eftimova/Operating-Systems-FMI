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
        volatile unsigned long long i;
        for (i = 0; i < 10000000000ULL; i++) {
            // busy wait
        }
    } else {
        // Parent
        printf("Parent PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}
