Q.2) Write a C program that redirects standard output to a file output.txt. (use of dup and open system call)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    printf("This output is redirected to the file output.txt\n");
    return 0;
}


Output (in the output.txt file):

This output is redirected to the file output.txt

