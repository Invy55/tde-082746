//Scrivere un sottoprogramma che, ricevuta in ingresso una matrice
//quadrata di interi (e qualsiasi altro parametro ritenuto strettamente necessario), verifichi se esistono
//almeno una riga e una colonna identiche, cioè contenenti gli stessi valori e nello stesso ordine. In caso
//positivo il sottoprogramma restituisce 1 altrimenti 0.

#include <stdio.h>
#define N 5

int rigcol(int[][N]);

int main() {
    int mat[N][N] = {{1,2,3,4,5},
                     {2,3,4,5,6},
                     {3,4,5,6,7},
                     {4,5,6,7,8},
                     {5,6,7,8,9}};

    printf("%d", rigcol(mat));
    return 0;
}

int rigcol(int mat[][N]) {
    int i, j, k, trovato;
    for(i=0; i<N; i++) { //per ogni riga1
        
        for(j=0; j<N; j++) { // per ogni colonna
            trovato = 1;
            for(k=0; k<N; k++) { //per ogni riga della colonna
                //printf("%d (%d, %d) ?= %d (%d, %d)\n", mat[i][k], i, k, mat[k][j], k, j);
                if(mat[i][k] != mat[k][j]) { // se una colonna della riga1 è diversa dalla corrispondente riga della colonna corrente
                    trovato = 0;
                }
            }
            if(trovato){
                return 1;
            }
        }
        
    }
    return 0;
}
