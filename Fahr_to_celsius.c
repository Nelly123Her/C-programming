#include <stdio.h>  // Biblioteca estándar para entrada y salida

int main() {
    int fahr, celsius;         // Variables para Fahrenheit y Celsius
    int lower, upper, step;    // Límites y paso para la tabla

    lower = 0;     // Límite inferior de la tabla (0 °F)
    upper = 300;   // Límite superior de la tabla (300 °F)
    step = 20;     // Incremento entre cada fila de la tabla

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;                  // Conversión de Fahrenheit a Celsius
        printf("%d\t%d\n", fahr, celsius);              // Imprimir los valores con tabulación
        fahr = fahr + step;                             // Avanzar al siguiente valor
    }

    return 0;  // Indica que el programa terminó correctamente
}
//Página 9 como referencia del libre C programming language