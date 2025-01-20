//Si scriva una funzione ricorsiva che, ricevuto come parametro
//un array di interi (e ogni altro parametro ritenuto necessario), individui e restituisca al chiamante il
//numero di valori pari contenuti dell’array.

#include <stdio.h>

int ricorsiva(int[], int);

int main() {
    int a[5] = {1,2,3,4,5};

    printf("Numero di pari: %d", ricorsiva(a, 5));

    return 0;
}

int ricorsiva(int a[], int n) {
    if(n==0) return 0;
    if(*a % 2 == 0) {
        return 1 + ricorsiva(a+1, n-1);
    } else {
        return ricorsiva(a+1, n-1);
    }
}