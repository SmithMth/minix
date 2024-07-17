#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void create_process_tree(int depth) {
    if (depth == 0) return;

    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return;
    } else if (pid == 0) {
        printf("Process ID: %d, Parent ID: %d, Depth: %d\n", getpid(), 
getppid(), depth);
        create_process_tree(depth - 1);
        exit(0);
    } else {
        wait(NULL); // Esperar a que el hijo termine
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <depth>\n", argv[0]);
        return 1;
    }

    int depth = atoi(argv[1]);
    create_process_tree(depth);

    return 0;
}

