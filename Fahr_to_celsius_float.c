#include <stdio.h>  // Biblioteca estándar para entrada y salida

int main() {
    float fahr, celsius;         // Variables para Fahrenheit y Celsius
    int lower, upper, step;    // Límites y paso para la tabla

    lower = 0;     // Límite inferior de la tabla (0 °F)
    upper = 300;   // Límite superior de la tabla (300 °F)
    step = 20;     // Incremento entre cada fila de la tabla

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 /9.0 ) * (fahr -32.0);                  // Conversión de Fahrenheit a Celsius
        printf("%1.0f %5.2f\n ", fahr, celsius);              // Imprimir los valores con tabulación
        fahr += step;                             // Avanzar al siguiente valor
    }

    return 0;  // Indica que el programa terminó correctamente
}
//Página 9 como referencia del libre C programming language