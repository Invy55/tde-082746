//Si scriva un sottoprogramma ricorsivo void(...) che riceve due array ordinati e le loro dimensioni, e copia i loro
//elementi in un terzo array, che dovrà risultare anch'esso ordinato. Anche il terzo array dovrà esser passato come
//parametro al sottoprogramma. Ad esempio, dati i due array a : [1, 4, 6, 10] e b : [2, 3, 6, 9], il sottoprogramma
//costruisce l’array c : [1, 2, 3, 4, 6, 6, 9, 10].
//NOTA: si suppone che il terzo array sia stato dichiarato (nel programma chiamante) con dimensione sufficiente
//per poter sempre ospitare gli elementi dei primi due array.

#include <stdio.h>

#define N 4

void ricorsiva(int[], int[], int, int, int[]);

int main() {
    int a[N]={1, 4, 6, 9}, b[N+1]={2, 3, 6, 8, 9}, c[N*2+1];

    ricorsiva(a, b, N, N+1, c);
    for(int i=0; i<N*2+1; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
    return 0;
}

// a  6 7 8
// b  4 5 6

void ricorsiva(int a[], int b[], int na, int nb, int c[]) {
    if(na == 0) {
        if(nb > 0) {
            *c = *b;
            ricorsiva(a, b+1, na, nb-1, c+1);
        }
    }else if(nb == 0) {
        if(na > 0) {
            *c = *a;
            ricorsiva(a+1, b, na-1, nb, c+1);
        }
    } else {
        if(na==0 && nb==0) {
            return;
        } else if(*a < *b) {
            *c = *a;
            ricorsiva(a+1, b, na-1, nb, c+1);
        } else {
            *c = *b;
            ricorsiva(a, b+1, na, nb-1, c+1);
        }
    }
}