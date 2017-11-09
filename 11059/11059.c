/**---------------------------------------------------------
 * 
 * Actividad de programación: Problema 11059 de UVA
 * Fecha: 09-Nov-2017
 * Autor: A01700457 - Lino Contreras
 * 
 * ---------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(int argc, char** argv){
    int n, i, j, t=1;
    long long int *numbers, max, local;
    while(scanf("%d", &n) != EOF){
        numbers = (long long int*) malloc(n * sizeof(long long int));
        for(i = 0; i < n; i++){
            scanf("%jd", &numbers[i]);
        }
        max = 0;
        for(i = 0; i < n; i++){
            local = numbers[i];
            if(local > max)
                max = local;
            for(j = i+1; j < n; j++){
                local *= numbers[j];
                if(local > max)
                    max = local;
            }
        }
        printf("Case #%d: The maximum product is %jd.\n\n", t++, max > 0 ? max : 0);
    }
    return 0;
}
