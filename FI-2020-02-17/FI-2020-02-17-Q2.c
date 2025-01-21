//Scrivere una funzione ricorsiva che dati due interi, n1 ed n2, restituisca la somma di tutti gli
//interi compresi tra n1 ed n2.

#include <stdio.h>

int ricorsiva(int, int);

int main() {
    int n1, n2;
    n1 = 1;
    n2 = 4;

    printf("%d", ricorsiva(n1, n2));

    return 0;
}

int ricorsiva(int n1, int n2) {
    if(n1+1 == n2) {
        return 0;
    }
    return n1+1+ricorsiva(n1+1, n2);
}