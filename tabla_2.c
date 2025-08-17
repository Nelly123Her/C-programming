#include <stdio.h>
 int main(){
    int i, num, re;
    num = 10;
    i = 0;  
    re = 0;

    while (i <= num)
    {   re = i * num;
        printf("%d\t%d\n", i, re);
        i++;

    }
    
}
