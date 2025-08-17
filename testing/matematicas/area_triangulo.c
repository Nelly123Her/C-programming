#include <stdio.h>

int main(){
    float base, h, area;

    printf("Ingrese el valor de base : ");
    scanf("%f",&base);
    printf("Ingrese el valor de altura (h) : ");
    scanf("%f",&h);

    area = (base * h) / 2;
    printf("El area de su trangulo es: %.2f\n", area);
}