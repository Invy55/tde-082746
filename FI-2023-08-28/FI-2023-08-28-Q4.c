//.1 Si definisca una funzione che, ricevuti come parametri di ingresso un array a di n numeri
//interi positivi, {x1, x2, ..., xn}, un intero y, (y>= xi, ∀ i = 1, ..., n), e qualsiasi altro parametro ritenuto necessario,
//individui le partizioni dell’array costituite da elementi adiacenti con somma minore o uguale a y.
//Per esempio, sia a = {2, 8, 0, 3, 9, 6, 1, 3} e sia y = 10. Allora:
//{2, 8, 0} {3} {9} {6, 1, 3} sono le possibili partizioni individuabili in base al criterio sopra definito.
//La funzione dovrà costruire e restituire al chiamante una lista dinamica i cui elementi memorizzano, per ogni
//partizione individuata, gli indici nell’array del primo e dell’ultimo elemento della partizione. Per esempio, per
//le partizioni individuate al punto precedente, la lista sarà così costituita:
// 0 2 -> 3 3 -> 4 4 -> 5 7 -> NULL
//Oltre a definire la funzione, si dichiarino opportunamente le strutture dati su cui la funzione opera, e cioè
//l’array, il nodo della lista e la lista stessa.
//.2 (3 punti). Si scriva un programma in C, completo delle sue parti dichiarative che, dopo aver letto i
//valori dell’array a da un file, e letto in input il valore di y, invochi in modo opportuno la funzione definita al
//punto precedente e utilizzi la lista restituita dalla funzione per stampare a video le partizioni.
//Per la lettura della matrice dal file, si consideri che:
//1. Il nome del file deve essere fornito in input da riga di comando (deve cioè essere gestito come
//parametro del main).
//2. Il file è organizzato in modo che i valori siano memorizzati in sequenza e siano separati da uno spazio.
//Per l’array nell’esempio precedente, il file è così organizzato:
//2 8 0 3 9 6 1 3
//Si può assumere che il numero dei valori memorizzati nel file sia minore o al più uguale alla dimensione
//massima dell’array, definita dalla costante predefinita N.

#include <stdio.h>
#include <stdlib.h>

#define N 15

typedef struct nd {
    int ini;
    int fin;
    struct nd * next;
} Nodo;

typedef Nodo* Lista;

Lista partiziona(int[], int, int);

int main(int argc, char **argv) {
    if (argc <2) return -1;
    FILE *fp = fopen(argv[1], "r");
    Lista lis, cur;
    int y, n=0, x[N];

    while(!feof(fp)) {
        fscanf(fp, "%d", &x[n]);
        n++;
    }

    printf("Inserire y: ");
    scanf("%d", &y);

    lis = partiziona(x, y, n);

    cur = lis;
    while(cur != NULL) {
        if (cur == lis) {
            printf("(%d %d)", cur->ini, cur->fin);
        } else {
            printf(" -> (%d %d)", cur->ini, cur->fin);
        }
        cur = cur->next;
    }

    return 0;
}

Lista partiziona(int x[], int y, int n) {
    Lista lis = NULL, cur, new;
    int somma = 0, ini=0;
    for(int i=0; i<n; i++) { // per ogni elemento x[i]
        if(somma+x[i] > y || i == n-1) {
            new = (Lista)malloc(sizeof(Nodo));
            new->ini = ini;
            if(i == n-1) {
                new->fin = i;
            } else {
                new->fin = i-1;
            }
            
            if (lis == NULL) {
                lis = new;
                cur = lis;
            } else {
                cur->next = new;
                cur = cur->next;
            }
            ini = i;
            somma = x[i];
        } else {
            somma += x[i];
        }
    }

    cur->next = NULL;
    return lis;
}