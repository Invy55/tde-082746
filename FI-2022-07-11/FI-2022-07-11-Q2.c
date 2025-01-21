//Si scriva una funzione ricorsiva che, ricevuto come parametro un array di interi e ogni parametro
//ritenuto necessario, individui e restituisca al chiamante il valore massimo dell’array.

#include <stdio.h>
#include <stdlib.h>
#define N 6

int ricorsiva(int[], int);

int main(int argc, char ** argv) {
    int a[N] = {1,2,3,4,5,6};

    printf("%d", ricorsiva(a, N));
    return 0;
}

int ricorsiva(int a[], int n) {
    if(n>1) {
        if(*a>ricorsiva(a+1, n-1)) {
            return *a;
        } else {
            return ricorsiva(a+1, n-1);
        }
    } else {
        return *a;
    }
}