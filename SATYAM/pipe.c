#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    pid_t pid;
    char arr[100], str[100];
    int fd[2], nbr, nbw;
    pipe(fd);      // Creating a pipe
    pid = fork();  // Calling fork to create a child process
    if (pid == 0) {
        printf("\nEnter a string: ");
        gets(str);
        nbw = write(fd[1], str, strlen(str));
        printf("Child wrote %d bytes\n", nbw);
        exit(0);
    } else {
        nbr = read(fd[0], arr, sizeof(arr));
        arr[nbr] = '\0';
        printf("Parent read %d bytes: %s\n", nbr, arr);
    }
    return 0;
}