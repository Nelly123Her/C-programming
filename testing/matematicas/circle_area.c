#include <stdio.h>

int main(){

 float pi = 3.1416, area, radio;

    printf("Ingresa el valor de su radio : ");
    scanf("%f", &radio);
    area = pi * (radio* radio);
    printf("El área del círculo es: %.2f\n", area);
}