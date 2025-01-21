//Scrivere un sottoprogramma che riceve in ingresso il puntatore a un file che memorizza una
//sequenza di numeri interi positivi, uno per ogni riga. Per ogni valore letto dal file, il sottoprogramma calcola la
//cifra che compare più di frequente, quindi stampa a video il numero letto dal file e la cifra con maggiori
//occorrenze. Nel caso ci siano più cifre con lo stesso numero di occorrenze, restituisce la cifra con valore più alto.
//Per esempio, se il file memorizza i seguenti valori:
//    144360
//    14433660
//    2005
//allora il sottoprogramma stampa:
//Numero letto: 144360 - Cifra più frequente: 4
//Numero letto: 14433660 - Cifra più frequente: 6
//Numero letto: 20005 - Cifra più frequente: 0

#include <stdio.h>
#include <stdlib.h>

void funzione(FILE*);

int main() {
    FILE *fp = fopen("FI-2019-07-15-Q5.txt", "r");
    funzione(fp);
    fclose(fp);
    return 0;
}

void funzione(FILE *fp) {
    int n, bckn;
    int a[10] = {0};
    int max, maxn;
    while(!feof(fp)) {
        fscanf(fp, "%d\n", &bckn);
        n = bckn;
        while(n>0) {
            a[n%10]++;
            n = n/10;
        }
        for(int i=0; i<10; i++) {
            if(i == 0 || a[i]>=max) {
                max = a[i];
                maxn = i;
            }
            a[i] = 0;
        }
        printf("Numero letto: %d - Cifra più frequente: %d\n", bckn, maxn);
    }
}