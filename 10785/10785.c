/**---------------------------------------------------------
 * 
 * Actividad de programación: Problema 10785 de UVA
 * Fecha: 09-Nov-2017
 * Autor: A01700457 - Lino Contreras
 * 
 * ---------------------------------------------------------*/

int charCmp(const void *, const void *);

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
    char v[] = "AUEOI";
    char c[] = "JSBKTCLDMVNWFXGPYHQZR";
    char *name, *nameV, *nameC;
    int t, nt, n, vC, cC, i;
    scanf("%d", &nt);
    for(t = 1; t <= nt; t++){
        scanf("%d", &n);

        cC = n/2;
        vC = n - cC;
        name = malloc((n + 1) * sizeof *name);
        name[n] = '\0';
        nameV = malloc(vC * sizeof *nameV);
        nameC = malloc(cC * sizeof *nameC);
        int letter = 0;
        int max = 5;
        for(i = 0; i < cC; i++){
            if(max--){
                nameC[i] = c[letter];
            }else{
                nameC[i] = c[++letter];
                max = 4;
            }
        }
        letter = 0;
        max = 21;
        for(i = 0; i < vC; i++){
            if(max--){
                nameV[i] = v[letter];
            }else{
                nameV[i] = v[++letter];
                max = 20;
            }
        }

        qsort(nameV, vC, sizeof *nameV, charCmp);
        qsort(nameC, cC, sizeof *nameC, charCmp);
        for(i = 0; i < n; i++){
            name[i] = i % 2 == 0 ? nameV[i/2] : nameC[i/2];
        }
        printf("Case %d: %s\n", t, name);
        free(name);
        free(nameV);
        free(nameC);
    }
    return 0;
}

int charCmp(const void *a, const void *b){
    return *(char*)a - *(char*)b;
}
