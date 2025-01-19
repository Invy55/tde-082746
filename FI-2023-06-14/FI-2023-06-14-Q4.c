//Scrivere una funzione che, ricevendo in ingresso una matrice di N x M interi (con M > N) e i
//soli parametri dimensionali necessari, verifichi la seguente condizione: per ogni k tra 1 e N-1, l’elemento di valore
//massimo della riga di indice k della matrice si trovi in posizione più avanzata rispetto all’elemento di valore
//massimo della riga precedente (di indice k-1). Si suppone che ciascuna riga della matrice contenga tutti valori
//distinti. La funzione dovrà restituire 1 se la condizione è verificata, 0 altrimenti. Per esempio: la matrice
//        1 3 8 2
//        10 5 12 3
//        3 2 12 16
//non soddisfa la condizione, in quanto il massimo (12) della riga di indice k = 1 (la seconda) si trova in terza
//posizione, che NON è più avanzata rispetto alla posizione del massimo (8) della riga precedente. La condizione è
//invece soddisfatta dalla matrice
//        11 3 8 2
//        12 15 22 3
//        3 2 12 16
//dove il massimo (22) della riga di indice k=1 si trova in terza posizione, più avanzata rispetto alla posizione del
//massimo (11) della riga precedente, e il massimo (16) della terza riga (indice k = 2) si trova in quarta posizione,
//che è più avanzata rispetto alla terza posizione dove si trova il massimo (22) della riga precedente.

#include <stdio.h>

#define N 3
#define M 4

int funzione(int[][M], int, int);

int main() {
    int mat[N][M] = {{ 1,3, 8,2 },
                     {10,5,12,3 },
                     {3, 2,12,16}};

    printf("%d", funzione(mat, N, M));
    return 0;
}


int funzione(int mat[][M], int n, int m) {
    int max, maxj, prevj=-1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(j==0 || mat[i][j] > max) {
                max = mat[i][j];
                maxj = j;
            }
        }
        if(prevj>=0 && prevj>=maxj) {
            return 0;
        }
        prevj = maxj;
    }
    return 1;
}

