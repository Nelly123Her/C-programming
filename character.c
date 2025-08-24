#include <stdio.h>

int main() {
    int c;

    printf("Escribe algo (Ctrl+D en Linux/macOS o Ctrl+Z en Windows para terminar):\n");

    while ((c = getchar()) != EOF) {
        printf("Resultado de (getchar() != EOF): %d\n", (c != EOF));
    }

    // Cuando lleguemos a EOF, también lo imprime
    printf("Al llegar a EOF, la expresión es: %d\n", (c != EOF));

    return 0;
}