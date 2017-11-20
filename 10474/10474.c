/**---------------------------------------------------------
 * 
 * Actividad de programación: Problema 10474 de UVA
 * Fecha: 19-Nov-2017
 * Autor: A01700457 - Lino Contreras
 * 
 * Where is the Marble?
 * ---------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1

int binaryFistOcurrence(int*, int, int);
int intcmp(const void *, const void *);

int main(int argc, char **argv){
    int n, nq, q, i, pos, ncase = 1;
    int *marbles;
    while(TRUE){
        scanf("%d %d", &n, &nq);
        if(!n && !nq) break;
        printf("CASE# %d:\n", ncase++);
        marbles = malloc(n * sizeof *marbles);
        for(i = 0; i < n; i++)
            scanf("%d", marbles + i);
        qsort(marbles, n, sizeof *marbles, intcmp);
        while(nq--){
            scanf("%d", &q);
            pos = binaryFistOcurrence(marbles, n, q);
            if(pos != -1)
                printf("%d found at %d\n", q, pos + 1);
            else
                printf("%d not found\n", q);
        }
        free(marbles);
    }
    return 0;
}

int binaryFistOcurrence(int *arr, int size, int val){
    int low, mid, high;
    low = 0;
    high = size - 1;    
    while(low <= high){
        mid = (high + low) / 2;
        if(arr[mid] > val || (mid > 0 && arr[mid - 1] == val)){
            high = mid - 1;
        }else if(arr[mid] < val){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

int intcmp(const void *a, const void *b){
    return *((int*)a) - *((int*)b);
}
