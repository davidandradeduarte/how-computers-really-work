#include <fcntl.h>
#include <unistd.h>

#define msg "Hello, file!\n"

int main(){
    int fd;
    fd = open("file1.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    write(fd, msg, sizeof(msg) -1);
    close(fd);
    return 0;
}