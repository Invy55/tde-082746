//Si supponga di avere, già presente in memoria, una matrice quadrata di interi di dimensione
//NxN, N costante predefinita. Si scriva una funzione ricorsiva che riceve come parametro la matrice (più altri
//parametri che si ritenga siano necessari) e verifica se la matrice è simmetrica, cioè se tutti gli elementi in
//posizioni simmetriche rispetto alla diagonale principale hanno stesso valore.

#include <stdio.h>
#define N 3

int ricorsiva(int[][N], int, int);

int main(int argc, char ** argv) {
    int mat[N][N] = {{1,2,3},
                     {2,3,4},
                     {3,4,5}};
    printf("%d", ricorsiva(mat, N, 0));
    return 0;
}

int ricorsiva(int mat[][N], int n, int i) {
    // N = 3
    // 1  2  3
    // 3  4  5
    // 5  7  9
    if(i<N) {
        if(n == 0) {
            return ricorsiva(mat, N, i+1);
        } else if(mat[i][N-n] != mat[N-n][i]) {
            return 0;
        } else {
            return ricorsiva(mat, n-1, i);
        }
    } else {
        return 1;
    }
    
}