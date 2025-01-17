//Scrivere un sottoprogramma MinimoInTesta(..) che, ricevendo in ingresso la lista dinamica
//costruita al punto precedente, la modifica spostando in prima posizione il nodo che contiene il valore dominante
//minimo e rende la lista modificata disponibile al chiamante. Per esempio, se la lista in ingresso è quella riportata
//nel Quesito 2, la lista modificata sarà:
//N.B.: La procedura deve operare modificando esclusivamente il campo puntatore dei nodi coinvolti, senza
//modificarne i campi di tipo int, né creare o cancellare nodi.

#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 8

typedef struct nd {
    int value;
    int i;
    int j;
    struct nd * next;
} Nodo;
typedef Nodo * Lista;

Lista MinimoInTesta(Lista);

Lista Dominante(int [][M]);
Lista InserisciInTesta(Lista, int, int, int);

int main() {
    Lista lis = NULL, cur;
    // matrice modificata sennò la lista usciva già ordinata
    int mat[N][M] ={{5,9,2,4,1,5,2,4},
                    {3,5,6,2,5,6,1,2},
                    {1,3,4,7,8,2,5,0},
                    {1,3,5,6,7,7,2,5}}; 

    lis = Dominante(mat);

    lis = MinimoInTesta(lis);
    
    cur = lis;
    while(cur != NULL) {
        if (cur == lis) {
            printf("|%d (%d, %d)|", cur->value, cur->i, cur->j);
        } else {
            printf(" -> |%d (%d, %d)|", cur->value, cur->i, cur->j);
        }
        cur = cur->next;
    }

    return 0;
}

Lista MinimoInTesta(Lista lis) {
    Lista cur, min = NULL, prev = NULL, prevMin;
    cur = lis;
    while(cur!=NULL) {
        if(min == NULL || cur->value < min->value) {
            prevMin = prev;
            min = cur;
        }
        prev = cur;
        cur = cur->next;
    }
    if(prevMin == NULL) {
        return lis;
    } else {
        prevMin->next = min->next;
        min->next = lis;

        return min;
    }
}

// vedi FI-2023-07-06-Q2.c
Lista InserisciInTesta(Lista lis, int value, int i, int j) { Lista new = (Lista)malloc(sizeof(Nodo)); new->value = value; new->i = i; new->j = j; new->next = lis; return new; }
Lista Dominante(int mat[][M]) { int i, j, i1, j1; int fine; Lista out = NULL; for(i=0; i<N-1; i++) { for(j=0; j<M-1; j++) { fine = 0; for(i1=i+1; i1<N; i1++) { for(j1=j+1; j1<M; j1++) { if(mat[i][j] <= mat[i1][j1]) { fine = 1; }  } } if (!fine) { out = InserisciInTesta(out, mat[i][j], i, j); } } } return out; }