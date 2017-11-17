/**---------------------------------------------------------
 * 
 * Actividad de programación: Problema 12210 de UVA
 * Fecha: 16-Nov-2017
 * Autor: A01700457 - Lino Contreras
 * 
 * ---------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1

int intCmp(const void *, const void *);
int min(int*, int);

int main(int argc, char** argv){
    int nBachelors, nSpinters;
    int *bachelors, *spinters;
    int nCase = 1, i;
    while(TRUE){
        scanf("%d %d", &nBachelors, &nSpinters);
        
        if(!nBachelors && !nSpinters)
            break;
        
        bachelors = malloc(nBachelors * sizeof *bachelors);
        spinters = malloc(nSpinters * sizeof *spinters);
        
        for(i = 0; i < nBachelors; i++)
            scanf("%d", (bachelors + i));
        
        for(i = 0; i < nSpinters; i++)
            scanf("%d", (spinters + i));
        
        if(nBachelors <= nSpinters){
            printf("Case %d: 0\n", nCase);
        }else{
            printf("Case %d: %d %d\n", nCase, nBachelors - nSpinters, min(bachelors, nBachelors));
        }
        
        free(bachelors);
        free(spinters);
        
        nCase++;
    }

    return 0;
}

int intCmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int min(int* arr, int size){
    int i, res = *arr;
    for(i = 0; i < size; i++){
        res = arr[i] < res ? arr[i] : res;
    }
    return res;
}
