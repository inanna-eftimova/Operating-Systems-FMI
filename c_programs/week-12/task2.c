#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "file.bin";
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if(fd < 0) {
        perror("open");
        return 1;
    }

    const char *data = "1234567890123456789012345"; // 25 bytes
    if (write(fd, data, 25) != 25) {
        perror("write");
        close(fd);
        return 1;
    }

    lseek(fd, 0, SEEK_SET);

    char buf[11];
    ssize_t n;

    while ((n = read(fd, buf, 10)) > 0) {
        buf[n] = '\0';
        printf("Read %zd bytes: %s\n", n, buf);
    }

    if(n < 0) perror("read");

    close(fd);
    return 0;
}
