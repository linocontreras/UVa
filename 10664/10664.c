/**---------------------------------------------------------
 * 
 * Actividad de programación: Problema 10664 de UVA
 * Fecha: 26-Nov-2017
 * Autor: A01700457 - Lino Contreras
 * 
 * ---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int mochila(int, int*, int);
int max(int a, int b){ return a > b ? a : b;}

int main(int argc, char** argv){
    int luggage[20];
    int t, total, n, tmp, i, scan;
    char c;
    scanf("%d", &t);
    while(t--){
        i = n = total = 0;
        scanf("%d%c", &tmp, &c);
        while(c != '\n' && scan != EOF){
            luggage[i++] = tmp;
            total += tmp;
            n++;
            scan = scanf("%d%c", &tmp, &c);
        }
        luggage[i++] = tmp;
        total += tmp;
        n++;
        if(total % 2 != 0 || mochila(total/2, luggage, n) != total/2){
            printf("NO\n", total, mochila(total/2, luggage, n), total/2);
        }else{
            printf("YES\n");
        }
    }
    return 0;
}

int mochila(int peso, int *pesos, int n){
   int i, current;
   int **mat = malloc((n+1) * sizeof(int*));
   for(i = 0; i <= n; i++){
       mat[i] = malloc((peso + 1) * sizeof(int));
   }

   for (i = 0; i <= n; i++){
       for (current = 0; current <= peso; current++){
           if (i == 0 || current == 0)
               mat[i][current] = 0;
           else if (pesos[i-1] <= current)
                 mat[i][current] = max(pesos[i-1] + mat[i-1][current-pesos[i-1]],  mat[i-1][current]);
           else
                 mat[i][current] = mat[i-1][current];
       }
   }
   int res = mat[n][peso];
   for(i = 0; i <= n; i++){
       free(mat[i]);
   }
   free(mat);
   return res;
}