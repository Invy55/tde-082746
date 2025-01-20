//Si definisca una funzione ricorsiva che, ricevuti come parametri un array di interi, a, due valori interi, x e y, e
//qualsiasi altro parametro ritenuto necessario, restituisca:
//- il numero di volte in cui x è seguito da y, oppure
//- il valore -1 nel caso in cui l’array non contenga alcuna occorrenza di x.
//Per esempio, dato l’larray a[8]= {5,3,2,5,3,5,3,3},
//- se x = 5 e y = 3 la funzione restituirà 3
//- se x = 5 e y = 4 la funzione restituirà 0
//- se x = 4, e quindi x non è presente nell’array, la funzione restituirà il valore -1

#include <stdio.h>

int ricorsiva(int[], int, int, int);

int main() {
    int a[8] = {5,3,2,5,3,5,3,3}, x = 5, y = 3;

    printf("%d", ricorsiva(a, x, y, 8));

    return 0;
}

int ricorsiva(int a[], int x, int y, int n) {
    if(n > 1) {
        int next;
        if(*a == x && *(a+1) == y) {
            next = ricorsiva(a+2, x, y, n-2);
            if (next > 0) {
                return next + 1;
            } else {
                return 1;
            }
        } else {
            next = ricorsiva(a+1, x, y, n-1);
            if (next < 0 && *a == x) {
                return 0;
            } else {
                return next;
            }        
        }
    } else {
        if (n > 0 && *a != x) {
            return -1;
        } else {
            return 0;
        }
    }
}