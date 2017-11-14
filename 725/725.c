/**---------------------------------------------------------
 * 
 * Actividad de programación: Problema 725 de UVA
 * Fecha: 13-Nov-2017
 * Autor: A01700457 - Lino Contreras
 * 
 * ---------------------------------------------------------*/

#include<stdio.h>

#define TRUE 1
#define FALSE 0

int check(char *str){
    int i;
    char digits[10] = {0};
    for(i = 0; i < 10; i++){
        if(digits[str[i]-'0']++)
            return FALSE;
    }
    return TRUE;
}

int main(int argc, char** argv){
    int a, b, n, found;
    char digits[11], nl = 0;
    /* a = n * b */
    while(TRUE){
        scanf("%d", &n);
        if(n == 0) break;
        found = FALSE;
        if(nl)
            printf("\n");
        else
            nl = 1;
        for(b = 1; ; b++){
            a = n * b;
            if(a < 100000){
                sprintf(digits, "%05d%05d", a, b);
                if(check(digits)){
                    printf("%05d / %05d = %d\n", a, b, n);
                    found = TRUE;
                }                
            }else {
                if(!found)
                    printf("There are no solutions for %d.\n", n);
                break;
            }
        }
    }
    return 0;
}
