//Scrivere una funzione che riceve in ingresso una lista di interi e un valore intero dir. Se dir vale 0, il
//sottoprogramma effettua una rotazione a sinistra del contenuto della lista: il primo valore viene cioè spostato in
//fondo alla lista. Se dir vale 1 esegue una rotazione a destra: l’ultimo valore della lista viene cioè spostato in testa.
//La lista modificata viene quindi restituita al chiamante.
//Per esempio, se la lista iniziale è 6 → 8 → −3 → 1 → 10
//• la rotazione a sinistra produce la lista 8 → −3 → 1 → 10 → 6
//• la rotazione a destra produce la lista 10 → 6 → 8 → −3 → 1
//Nel caso in cui la lista sia vuota o contenga un solo elemento, il sottoprogramma restituisce la lista ricevuta in
//ingresso.
//Oltre a definire la funzione, si definisca un tipo di dato opportuno per rappresentare gli elementi della lista.

#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int value;
    struct nd * next;
} Nodo;
typedef Nodo * Lista;

void stampa(Lista);
Lista ruota(Lista, int);

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
    stampa(lis);
    lis = ruota(lis, 0);
    stampa(lis);
    return 0;
}

Lista ruota(Lista lis, int dir) {
    if (lis==NULL || lis->next == NULL) return lis;
    Lista cur, prev;
    if(!dir) { //dir = 0 primo in fondo alla lista
        cur = lis;
        while(cur->next!=NULL) {
            cur = cur->next;
        }
        cur->next = lis;
        prev = lis->next;
        lis->next = NULL;
        return prev;
    } else { // dir = 1
        cur = lis;
        prev = NULL;
        while(cur->next!=NULL) {
            prev = cur;
            cur = cur->next;
        }
        cur->next = lis;
        prev->next = NULL;
        return cur;
    }
}

void stampa(Lista lis) {
    Lista cur;
    int fine=0;
    cur = lis;
    while(!fine) {
        if (cur == NULL) {
            printf(" -> NULL\n");
            fine = 1;
        } else if (cur == lis) {
            printf("|%d|", cur->value);
        } else{
            printf(" -> |%d|", cur->value);
        }
        if(cur != NULL) {
            cur = cur->next;
        }
    }
}