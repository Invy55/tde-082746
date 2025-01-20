//Si vuole definire una funzione che verifichi la validità di una password. La
//funzione riceve in ingresso la stringa passwd, che rappresenta la password da verificare, un array di
//caratteri, speciali, che memorizza un insieme di caratteri speciali ammessi, e due interi, min e max. La
//funzione quindi verifica che la stringa:
//- sia lunga almeno min caratteri e non superi max caratteri,
//- contenga almeno uno tra i caratteri memorizzati nella stringa speciali.
//Nel caso in cui la password sia valida, la funzione restituisce 1, altrimenti restituisce:
//- -2 se la lunghezza è minore di min,
//- -1 se è maggiore di max,
//- 0 se non contiene caratteri speciali.

#include <stdio.h>
#define N 9

int valida(char[], char[], int, int);

int main() {
    char passwd[20] = "password123?";
    char speciali[N] = {'!', '@', '#', '$', '?', '-', '+', '*', '&'};
    int min = 8, max = 15;

    printf("%d", valida(passwd, speciali, min, max));

    return 0;
}

int valida(char passwd[], char speciali[], int min, int max) {
    int cont=0, spec=0;
    while(*passwd != '\0') {
        for(int i=0; i<N; i++) {
            if(*passwd == speciali[i]) spec++;
        }
        cont++;
        passwd++;
    }
    if(cont < min) return -2;
    if(cont > max) return -1;
    if(spec == 0) return 0;
    return 1;
}