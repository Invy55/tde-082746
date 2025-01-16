//Dopo aver opportunamente definito i tipi di dati atti a rappresentare una lista dinamica di valori interi, si
//scriva una funzione Lista MaggioriDiTuttiISuccessori(Lista pL) che, ricevendo la testa
//di una lista dinamica di interi, la modifica eliminando da essa ciascun elemento E che sia minore di almeno
//uno degli elementi successivi a E.
//Per esempio, se lista passata al sottoprogramma è
//L->3->32->4->6->3->20->17->2->17->9->7->1⬎ , la lista modificata è L->32->20->17->17->9->7->1⬎
//La funzione restituisce al chiamante la testa della lista modificata.

typedef struct n {
    int value;
    struct n *next;
} Nodo;

typedef Nodo * Lista;

#include <stdio.h>
#include <stdlib.h>

Lista MaggioriDiTuttiISuccessori(Lista);

int main() {
    int numeri[] = {3,32,4,6,3,20,17,2,17,9,7,1};
    int n = 12;
    // creo e riempo la lista dai numeri
    Lista lis, curNodo;
    lis = (Lista)malloc(sizeof(Nodo));
    curNodo = lis;
    for(int i=0; i<n; i++) {
        curNodo->value = numeri[i];
        if (i==(n-1)) curNodo->next = NULL; else {
            curNodo->next = (Lista)malloc(sizeof(Nodo));
            curNodo = curNodo->next;
        }
    }
    lis = MaggioriDiTuttiISuccessori(lis);

    //stampo la lista
    curNodo = lis;
    while (curNodo != NULL) {
        if (curNodo == lis) {
            printf("%d", curNodo->value);
        } else {
            printf(" -> %d", curNodo->value);
        }
        curNodo = curNodo->next;
    }

    return 0;
}

Lista MaggioriDiTuttiISuccessori(Lista pL) {
    Lista cur, iter, prev;
    int rimuovere;
    cur = pL;
    while(cur!=NULL) {
        rimuovere = 0;
        iter = cur->next;
        while(iter!=NULL && !rimuovere) {
            if(iter->value > cur->value) {
                rimuovere = 1;
            }
            iter = iter->next;
        }
        if (rimuovere) {
            if (prev == NULL) {
                pL = cur->next;
                free(cur);
                cur = pL;
            } else {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return pL;
}