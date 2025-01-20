//Scrivere una funzione che, ricevuta in ingresso una lista dinamica L
//che memorizza interi, modifichi la lista cancellando eventuali ripetizioni. Per esempio, data la lista:
//4-> 3 -> 1 -> 3 -> 7-> 6-> 7-|
//la lista sarà modificata nel seguente modo:
//4 -> 3-> 1 -> 7 -> 6--|

#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int value;
    struct nd * next;
} Nodo;

typedef Nodo * Lista;

void rimDup(Lista);

int main() {
    int numeri[] = {1,2,3,1,2,3,3};
    int n = 7;
    // creo e riempo la lista dai numeri
    Lista lis=NULL, curNodo;
    lis = (Lista)malloc(sizeof(Nodo));
    curNodo = lis;
    for(int i=0; i<n; i++) {
        curNodo->value = numeri[i];
        if (i==(n-1)) curNodo->next = NULL; else {
            curNodo->next = (Lista)malloc(sizeof(Nodo));
            curNodo = curNodo->next;
        }
    }

    rimDup(lis);

    curNodo = lis;
    while(curNodo!=NULL) {
        if(curNodo==lis) {
            printf("%d", curNodo->value);
        } else {
            printf(" -> %d", curNodo->value);
        }
        curNodo = curNodo->next;
    }
    return 0;
}

void rimDup(Lista L) {
    if(L == NULL) return;
    Lista cur, iter, prev;
    cur = L;
    while(cur!=NULL&&cur->next!=NULL) { // cur != NULL perchè se rimuovo l'ultimo elemento cur->next non si può fare
        prev = cur;
        iter = cur->next;
        while(iter!=NULL) {
            if(iter->value == cur->value) {
                prev->next = iter->next;
                free(iter);
                iter = prev->next;
            } else {
                prev = iter;
                iter = iter->next;
            }
        }
        cur = cur->next;
    }
}