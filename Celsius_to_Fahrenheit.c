#include <stdio.h>  // Biblioteca estándar para entrada y salida

int main(){

    int  celsius, fahr;         // Variables para Celsius y Fahrenheit
    int lower, upper, step;     // Límites y paso

    step = 20;      // Valor del incremento
    upper = 300;    // Límite superior (Celsius máximo)
    lower = 0;      // Límite inferior (Celsius mínimo)

    celsius = lower;
    while (celsius <= upper)
    {
        // Fórmula para convertir de Celsius a Fahrenheit (pero usa división entera)
        // Mejora posible: usar 9.0 / 5.0 y convertir variables a float para mayor precisión
        fahr = 9 * (celsius / 5) + 32;

        // Imprime los valores actuales de celsius y fahr con tabulación
        printf("%d\t%d\n", celsius, fahr);   

        // Incrementa el valor de celsius en el paso definido
        celsius = celsius + step;        //también se puede declarar como celsiues=+step
    }

    // Buenas prácticas: retornar 0 al finalizar main
    return 0;
}