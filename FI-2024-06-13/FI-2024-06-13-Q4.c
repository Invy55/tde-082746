typedef struct nd {
    int val;
    struct nd * next;
} Nodo;

typedef Nodo * List;
//Si consideri una lista dinamica di interi definita come sopra. Si codifichi in C una funzione
void somma_triplette(List);
//che riceve come parametro una lista e, a partire dall’inizio, la modifica nel seguente modo: per ciascuna tripletta
//(tre nodi consecutivi) modifica il valore del primo nodo, sostituendolo con la somma dei tre valori della tripletta, e
//rimuove i due nodi successivi.
//Esempi: 1 ⟶ 2 ⟶ 3 ⟶ 4 ⟶ 5 ⟶ 6 ⟶ 7 ⬎ diventa 6 ⟶ 15 ⟶ 7 ⬎         ⬎ rimane ⬎
//1 ⟶ 2 ⟶ 1 ⟶ 8 ⟶ 3 ⬎ diventa 4 ⟶ 8 ⟶ 3⬎                           1 ⬎ rimane 1 ⬎
//1 ⟶ 2 ⟶ 1 ⟶ 8 ⟶ 3 ⟶ 1 ⬎ diventa 4 ⟶ 12 ⬎                         1 ⟶ 2 ⬎ rimane 1 ⟶ 2 ⬎

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeri[] = {1,2,3,4,5,6,7};
    int n = 7;
    List lista = (List)malloc(sizeof(Nodo)), curNodo;
    curNodo = lista;
    for(int i=0; i<n; i++) {
        curNodo->val = numeri[i];
        if (i==(n-1)) curNodo->next = NULL; else {
            curNodo->next = (List)malloc(sizeof(Nodo));
            curNodo = curNodo->next;
        }
    }

    somma_triplette(lista);

    //stampo la lista
    curNodo = lista;
    while (curNodo != NULL) {
        if (curNodo == lista) {
            printf("%d", curNodo->val);
        } else {
            printf(" -> %d", curNodo->val);
        }
        curNodo = curNodo->next;
    }
    return 0;
}

void somma_triplette(List lista) {
    List cur, next, nexxt;
    cur = lista;

    while(cur != NULL && cur->next != NULL && cur->next->next != NULL) {
        next = cur->next;
        nexxt = next->next;
        cur->val = cur->val + next->val + nexxt->val;
        cur->next = nexxt->next;
        cur = cur->next;
        free(next);
        free(nexxt);
    }
}