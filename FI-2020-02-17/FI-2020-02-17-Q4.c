//Data una matrice di interi mat, di dimensione NxM (N e M costanti), si scriva una funzione per individuare se mat
//contiene una sottomatrice, submat, di dimensioni r e c (r < N, c <M). La funzione riceve come parametri le due
//matrici, le loro dimensioni e ogni altro parametro ritenuto necessario. Quindi, restituisce all’ambiente chiamante
//la posizione di submat all’interno di mat (vedi esempio). Se mat non contiene submat, la funzione restituisce
//indici di valore -1, -1.
//Per esempio, se la matrice mat e submat hanno i seguenti valori:
//mat = -7 7 - 4 -34
//-3 9 - 2 18
//-15 -5 3 29
//submat = 9 -2
//-5 3
//la funzione dovrà individuerà submat all’interno di mat (vedi elementi evidenziati in mat) e restituirà la coppia
//di indici 1, 1.

#include <stdio.h>
#define N 3
#define M 4

void contiene(int[][M], int[][M], int, int, int, int, int[2]);

int main(int argc, char ** argv) {
    int mat[N][M] = {{1,2,3,4},
                     {2,3,4,5},
                     {3,4,5,6}};
    int r=2, c=2, submat[N][M] = {{3,4},
                                  {4,5}};
    
    int out[2];
    
    contiene(mat, submat, N, M, r, c, out);

    printf("(%d, %d)\n", out[0], out[1]);

    return 0;
}

void contiene(int mat[][M], int submat[][M], int n, int m, int r, int c, int out[2]){
    int primo = submat[0][0], uguali;
    for(int i=0; i<=n-r; i++) {
        for(int j=0; j<=m-c; j++) {
            if(mat[i][j] == primo) { //gli angoli della matrice corrispondono
                uguali = 1;
                for(int k=0; k<r; k++) {
                    for(int l=0; l<c; l++) {
                        if(mat[i+k][j+l] != submat[k][l]) {
                            uguali = 0;
                        }
                    }
                }
                if(uguali) {
                    out[0] = i;
                    out[1] = j;
                    return;
                }
            }
        }
    }
    out[0] = -1;
    out[1] = -1;
}