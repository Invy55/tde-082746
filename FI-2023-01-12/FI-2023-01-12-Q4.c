//Scrivere una funzione che, ricevendo in ingresso una lista dinamica e un intero k > 0, individui il nodo che si trova
//k posizioni dopo il nodo centrale e ne restituisca il puntatore al chiamante. Se tale nodo non esiste, ad esempio
//a causa di un insufficiente numero di nodi nella lista, la funzione deve restituire il valore NULL.
//NOTA: per ottenere punteggio pieno è necessario presentare una soluzione che preveda una sola scansione
//della lista (una scansione intera più una scansione anche solo parziale è considerata equivalente a due
//scansioni). Altre soluzioni saranno comunque valutate.

#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int value;
    struct nd * next;
} Nodo;
typedef Nodo * Lista;

Lista funzione(Lista, int);

int main() {
    int numeri[] = {6,8,3,1,10,11,5,6};
    int n = 8;
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

    lis = funzione(lis, 2);

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

Lista funzione(Lista lis, int k) {
    if(lis == NULL) return NULL;
    Lista lento=lis, veloce=lis;
    int cont = 0;
    while(lento->next!=NULL && cont < k) {
        if(veloce!=NULL && veloce->next!=NULL) {
            veloce = veloce->next->next;
        } else {
            cont++;
        }
        lento = lento->next;
    }
    if (cont == k){
        return lento;
    } else {
        return NULL;
    }
}