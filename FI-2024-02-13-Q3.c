//Si definisca una funzione ricorsiva int coppie(int n) che restituisce il numero di coppie di cifre
//uguali in posizioni adiacenti presenti nel numero n. Nel caso n sia negativo restituisce 0.
//Esempi: coppie(772211) restituisce 3, coppie(2344) restituisce 1, coppie(2) restituisce 0,
//coppie(888) restituisce 2.

#include <stdio.h>

int coppie(int);

int main() {
    int out;
    out = coppie(772211);
    printf("%d\n", out);
    return 0;
}

int coppie(int n) {
    if(n<0) return 0;
    int cur, prev;
    if (n < 10) return 0;

    cur = n % 10;
    prev = n % 100 / 10;
    
    if (cur == prev) {
        return 1 + coppie(n / 100); // se è una coppia toglie la coppia
    } else {
        return coppie(n / 10); // se non è una coppia toglie solo il corrente
    }
}