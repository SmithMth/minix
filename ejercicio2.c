#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_processes>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            return 1;
        } else if (pid == 0) {
            printf("Process ID: %d\n", getpid());
            exit(0); // Terminar el proceso hijo
        }
    }

    // Esperar a que todos los hijos terminen
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    return 0;
}

