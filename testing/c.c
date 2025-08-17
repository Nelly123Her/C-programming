/*Tabla del número deseado */
#include <stdio.h>

int main(){
    int i, re, multiplier;
     i =0;

     printf("Ingresa el número que deseas que sea la tabla de multiplicar: ");
     scanf("%d", &multiplier);

    while (i<=10)
    {
        re = multiplier * i;
        printf("%d X %d = %d\n", multiplier, i, re);
        i++;
    }
    return 0;
    

}