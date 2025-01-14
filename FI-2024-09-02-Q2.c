//Scrivere una funzione ricorsiva in C che, ricevuto come parametro un numero intero positivo n, costruisce e
//restituisce un nuovo numero ottenuto sostituendo a ciascuna cifra di n la sua successiva. N.B.: la cifra 9 viene
//sostituita con 0.
//Es: Se n = 34979, allora la funzione restituisce il valore 45080
//N.B.: Per il punteggio pieno è necessario che il risultato sia individuato ricorsivamente. Una soluzione
//sostanzialmente iterativa varrà al più 4 punti.

#include <stdio.h>

int nRicorsivo(int);

int main() {
    int n;
    printf("Inserire numero\n> ");
    scanf("%d", &n);

    printf("Risultato %d", nRicorsivo(n));

    return 0;
}

int nRicorsivo(int n) {
    int plus;
    plus = n % 10; // ultima cifra del numero
    plus++;
    if (plus > 9) plus = 0;
    if (n/10 == 0) return plus;
    return plus + 10 * nRicorsivo(n/10);
}