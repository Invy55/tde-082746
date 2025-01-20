//Data una lista dinamica, una sua rotazione a destra fa in modo che l’ultimo valore a destra venga spostato in
//testa.
//Dopo aver definito un tipo di dato opportuno per rappresentare gli elementi di una lista di interi, si definisca una
//funzione che, ricevuta in ingresso una lista con nodi del tipo definito e un valore intero k >= 0, effettui k rotazioni
//a destra, per effetto delle quali gli ultimi k elementi della lista sono spostati in testa. Per esempio, data la lista
//6 → 8 → 3 → 1 → 10
//- Se k = 2 la funzione modificherà la lista spostando in testa gli ultimi due elementi: 1→ 10 → 6 → 8 → 3
//- Se k = 1, la funzione sposterà in testa solo l’ultimo elemento: 10 → 6 → 8 → 3 → 1
//Nel caso in cui la lista sia vuota o k sia maggiore o uguale al numero di nodi in essa contenuti, la funzione
//restituisce la lista ricevuta in ingresso senza apportare alcuna modifica.
//NOTA: verranno premiate soluzioni che prevedano una sola scansione della lista.

#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int value;
    struct nd *next;
} Nodo;
typedef Nodo * Lista;

Lista ruota(Lista, int);

int main() {
    int numeri[] = {6,8,3,1,10};
    int n = 5;
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

    lis = ruota(lis, 5);

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

Lista ruota(Lista lista, int k) {
    if(lista == NULL) return lista;
    Lista cur=lista, end=lista, before;

    //ES: 6 → 8 → 3 → 1 → 10  k = 3
    //cur = 6 => cont = 1  before = n/a  end = 6
    //cur = 8 => cont = 2  before = n/a  end = 6
    //cur = 3 => cont = 3  before = 6    end = 8
    //cur = 1 => cont = 4  before = 8    end = 3
    //cur = 10 => break

    //cur->next = lista;   => dopo l'ultimo nodo della lista iniziale c'è l'inizio della lista iniziale
    //lista = end;         => la nuova lista inizia dall'ultimo nodo individuato
    //before->next = NULL; => interrompo la lista tra l'ultimo nodo individuato e quello prima

    int cont=1;
    while(cur->next!=NULL) {
        if(cont >= k) {
            before = end;
            end = end->next;
        }
        cont++;
        cur = cur->next;
    }

    if (cont >= k) {
        return lista;
    }
    cur->next = lista;
    lista = end;
    before->next = NULL;
    return lista;
}
