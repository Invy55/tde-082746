//Si vuole definire una funzione che, ricevuto come parametro (almeno) un array di 100 valori interi, restituisce
//all’ambiente chiamante il minimo, il massimo e il valore medio dei valori nell’array.
//Si definisca la funzione evidenziando almeno due diverse modalità in cui la funzione può comunicare con
//l’ambiente chiamante per restituire i valori calcolati.

#include <stdio.h>
#define N 100

float mmm(int[], int*, int*);

int main(int argc, char ** argv) {
    int min, max;
    float media;
    int a[N];
    for(int i=0; i<N; i++) {
        a[i] = i+1;
    }
    media = mmm(a, &min, &max);

    printf("min: %d max: %d media: %.2f\n", min, max, media);
    return 0;
}

float mmm(int a[], int *mi, int *ma) {
    int min, max, somma;
    for(int i=0; i<N; i++) {
        if(i==0) {
            min = a[i];
            max = a[i];
        } else {
            if(a[i]<min) min = a[i];
            if(a[i]>max) max = a[i];
        }
        somma += a[i];
    }
    *mi = min;
    *ma = max;

    return (float)somma/N;
}