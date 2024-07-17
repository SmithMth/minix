#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Proceso hijo
        int result = factorial(8);
        printf("Factorial de 8 es: %d\n", result);
    } else {
        // Proceso padre
        for (int i = 1; i <= 100; i++) {
            printf("%d\n", i);
        }
        wait(NULL); // Esperar a que el hijo termine
    }

    return 0;
}

