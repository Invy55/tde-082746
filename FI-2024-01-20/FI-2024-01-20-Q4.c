//Si consideri una lista dinamica di interi, definita come segue.
typedef struct nd {
    int valore;
    struct nd * next;
} Nodo;
typedef Nodo * Lista;
//Si codifichi in C una funzione void sdoppia( Lista lis, Lista * pPos, Lista * pNeg) che riceve
//una lista lis e, modificando solo i collegamenti tra i nodi (senza allocare né deallocare memoria), costruisce e
//rende disponibili al chiamante due liste così definite: una (puntata da pPos) che contiene tutti gli elementi con
//valore positivo e una (puntata da pNeg) che contiene tutti gli elementi con valore negativo, preservandone
//l’ordine originale. L’invocazione di sdoppia() nel contesto di un programma chiamante può avvenire così:
//Lista lis=NULL, pos=NULL, neg=NULL; /* Inizializzazioni: tre liste vuote */
//… /* “creazione” della lista lis, codice omesso */
//sdoppia( lis, &pos, &neg ); /* Invocazione. pos e neg devono essere ancora vuote */
//lis = NULL; /* Per evitare effetti collaterali - lis ora è “svuotata” */
//Esempio: da lis ⟶ 1 ⟶ -2 ⟶ -3 ⟶ 4 ⟶ 5 ⟶ -6 ⬎ costruisce pos ⟶ 1 ⟶ 4 ⟶ 5 ⬎ e neg ⟶ -2 ⟶ -3 ⟶ -6 ⬎

#include <stdio.h>
#include <stdlib.h>
void sdoppia(Lista, Lista *, Lista *);

int main() {
    int numeri[] = {1,-2,-3,4,5,-6};
    int n = 6;
    // creo e riempo la lista dai numeri
    Lista lis=NULL, pos=NULL, neg=NULL, curNodo;
    lis = (Lista)malloc(sizeof(Nodo));
    curNodo = lis;
    for(int i=0; i<n; i++) {
        curNodo->valore = numeri[i];
        if (i==(n-1)) curNodo->next = NULL; else {
            curNodo->next = (Lista)malloc(sizeof(Nodo));
            curNodo = curNodo->next;
        }
    }

    sdoppia(lis, &pos, &neg);

    //stampo la lista
    curNodo = pos;
    while (curNodo != NULL) {
        if (curNodo == pos) {
            printf("%d", curNodo->valore);
        } else {
            printf(" -> %d", curNodo->valore);
        }
        curNodo = curNodo->next;
    }
    printf("\n");
    curNodo = neg;
    while (curNodo != NULL) {
        if (curNodo == neg) {
            printf("%d", curNodo->valore);
        } else {
            printf(" -> %d", curNodo->valore);
        }
        curNodo = curNodo->next;
    }

    return 0;
}

void sdoppia(Lista lis, Lista * pPos, Lista * pNeg) {
    Lista cur, curPos, curNeg;
    cur = lis;
    curPos = NULL;
    curNeg = NULL;
    while(cur != NULL) {
        if(cur->valore == 0) {
            // non si sa che farci con lo zero
        } else if (cur->valore>0) {
            // lista positivi
            if(curPos == NULL) {
                curPos = cur;
                *pPos = cur;
            } else {
                curPos->next = cur;
                curPos = curPos->next;
            }
        } else {
            // lista negativi
            if(curNeg == NULL) {
                curNeg = cur;
                *pNeg = curNeg;
            } else {
                curNeg->next = cur;
                curNeg = curNeg->next;
            }
        }
        cur = cur->next;
    }
    curPos->next = NULL;
    curNeg->next = NULL;

}