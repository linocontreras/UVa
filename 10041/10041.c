/**---------------------------------------------------------
 * 
 * Actividad de programación: Problema 10041 de UVA
 * Fecha: 09-Nov-2017
 * Autor: A01700457 - Lino Contreras
 * 
 * ---------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

int intcmp(const void *, const void *);

int main(int argc, char** argv){
    int t, r, i, res, location;
    int *rel;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &r);
        rel = (int*) malloc(r * sizeof(int));
        res = 0;
        for(i = 0; i < r; i++){
            scanf("%d", rel+i);
        }
        qsort(rel, r, sizeof(int), intcmp);
        location = rel[r/2];
        for(i = 0; i < r; i++){
            res += abs(location - rel[i]);
        }
        printf("%d\n", res);
        free(rel);
    }
    return 0;
}

int intcmp(const void *a, const void *b){
    return *((int*)a) - *((int*)b);
}
