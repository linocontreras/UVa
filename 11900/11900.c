/**---------------------------------------------------------
 * 
 * Actividad de programación: Problema 11900 de UVA
 * Fecha: 16-Nov-2017
 * Autor: A01700457 - Lino Contreras
 * 
 * ---------------------------------------------------------*/

#include<stdio.h>

int main(int argc, char** argv){
    int nT, t;
    scanf("%d", &nT);
    int n, p, q, tmp, currentP, currentQ, res;
    for(t = 1; t <= nT; t++){
        scanf("%d %d %d", &n, &p, &q);
        res = currentP = currentQ = 0;
        while(n--){
            scanf("%d", &tmp);
            if(++currentP <= p && (currentQ + tmp) <= q){
                res++;
                currentQ += tmp;
            }
        }
        printf("Case %d: %d\n", t, res);
    }
    return 0;
}
