//Si consideri una lista dinamica di interi, definita come segue:
typedef struct nd {
    int valore;
    struct nd *next;
} Nodo;
typedef Nodo *Lista;
//Si codifichi in C una funzione Lista filtra(Lista lis) che riceve una lista lis e la modifica in modo
//che, per ciascuna coppia formata da un nodo in posizione dispari e dal successivo nodo in posizione pari, la
//lista risultante contenga solo il nodo con il valore massimo della coppia. I nodi che non hanno valore massimo
//nella loro coppia devono essere rimossi dalla lista. Se la lista ha un numero dispari di elementi, l’ultimo
//elemento viene conservato nella lista modificata. Se una coppia ha i due elementi di ugual valore, entrambi
//vengono conservati nella lista modificata. L'invocazione di filtra() nel contesto di un programma
//chiamante può avvenire così:
//Lista lista = NULL; /* Inizializzazione della lista */
//…                   /* "Creazione" della lista lista, codice omesso */
//lista = filtra(lista); /* Invocazione. lista ora contiene solo i nodi massimi per
//                         ogni coppia */
//Esempio: Da lis ⟶ 1 ⟶ 2 ⟶ 5 ⟶ 3 ⟶ 7 ⟶ 7 ⟶ 4 ⬎ la funzione costruirà
//            lis ⟶ 2 ⟶ 5 ⟶ 7 ⟶ 7 ⟶ 4 ⬎.
//In questo esempio, i nodi con valori 1 e 3 sono rimossi poiché non sono i massimi nelle loro rispettive coppie.
//I due nodi di valore 7 sono conservati in quanto facenti parte di una coppia con valori uguali. Il nodo con
//valore 4 è conservato perché ultimo di una lista con un numero dispari di nodi.

#include <stdio.h>
#include <stdlib.h>

Lista filtra(Lista);

int main() {
    int numeri[] = {1,2,5,3,7,7,4};
    int n = 7;
    // creo e riempo la lista dai numeri
    Lista lis, curNodo;
    lis = (Lista)malloc(sizeof(Nodo));
    curNodo = lis;
    for(int i=0; i<n; i++) {
        curNodo->valore = numeri[i];
        if (i==(n-1)) curNodo->next = NULL; else {
            curNodo->next = (Lista)malloc(sizeof(Nodo));
            curNodo = curNodo->next;
        }
    }
    lis = filtra(lis);

    //stampo la lista
    curNodo = lis;
    while (curNodo != NULL) {
        if (curNodo == lis) {
            printf("%d", curNodo->valore);
        } else {
            printf(" -> %d", curNodo->valore);
        }
        curNodo = curNodo->next;
    }

    return 0;
}

Lista filtra(Lista lis) {
    Lista curNodo, nextNodo, prevNodo;
    curNodo = lis;
    nextNodo = curNodo->next;
    prevNodo = NULL;
    while(curNodo!=NULL && nextNodo!=NULL) {
        if (curNodo->valore > nextNodo->valore) {
            curNodo->next = nextNodo->next;
            free(nextNodo);
        } else if (curNodo->valore < nextNodo->valore) {
            if (prevNodo == NULL) {
                lis = nextNodo;
            } else {
                prevNodo->next = nextNodo;
            }
            free(curNodo);
        }
        prevNodo = nextNodo;
        curNodo = nextNodo->next;
        if (curNodo != NULL) {
            nextNodo = curNodo->next;
        }
    }
    return lis;
}