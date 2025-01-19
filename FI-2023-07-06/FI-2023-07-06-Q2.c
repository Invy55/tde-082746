//In una matrice di valori interi, si definisce dominante ogni elemento che è strettamente
//maggiore di tutti gli elementi della (sotto)matrice che si trova in basso a destra rispetto all’elemento stesso (si
//veda la figura). Dal calcolo devono essere esclusi gli elementi presenti nell’ultima colonna e nell’ultima riga.
//5 9 2 4 1 5 2 4
//3 5 6 2 5 6 1 2
//1 3 4 7 8 2 4 0
//1 3 5 6 7 8 2 1
//Schema per determinare se un elemento è dominante

//5 9 2 4 1 5 2 4
//3 5 6 2 5 6 1 2
//1 3 4 7 8 2 4 0
//1 3 5 6 7 8 2 1
//In evidenza: gli elementi dominanti

//Si realizzi una funzione, Dominante (...), che, ricevuti in ingresso una matrice m di dimensione N x M (N ed M
//costanti predefinite) e qualsiasi altro parametro ritenuto necessario, individui gli elementi dominanti della
//matrice e li memorizzi in una lista i cui nodi specificano i valori dominanti e la loro posizione nella matrice
//(indice di riga e indice di colonna).
//Per esempio, data la matrice riportata in alto e assumendo che l’aggiunta dei nodi nella lista avvenga con
//inserimenti in testa, la funzione creerà la seguente lista:
//N.B.: Per l’inserimento degli elementi trovati nella lista dinamica, si assuma sia disponibile la funzione
//InserisciInTesta(…), che riceve come parametri la testa della lista, il valore dell’elemento dominante, il suo indice
//di riga e quello di colonna e inserisce in testa alla lista un nuovo nodo che memorizza questi valori. La funzione
//non deve essere definita, mentre è necessario definire opportunamente il tipo del nodo e della lista.

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

Lista Dominante(int [][M]);
Lista InserisciInTesta(Lista, int, int, int);

int main() {
    Lista lis = NULL, cur;
    int mat[N][M] ={{5,9,2,4,1,5,2,4},
                    {3,5,6,2,5,6,1,2},
                    {1,3,4,7,8,2,4,0},
                    {1,3,5,6,7,8,2,1}};

    lis = Dominante(mat);
    
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

Lista InserisciInTesta(Lista lis, int value, int i, int j) {
    Lista new = (Lista)malloc(sizeof(Nodo));
    new->value = value;
    new->i = i;
    new->j = j;
    new->next = lis;
    return new;
}


Lista Dominante(int mat[][M]) {
    int i, j, i1, j1;
    int fine;
    Lista out = NULL;
    for(i=0; i<N-1; i++) {
        for(j=0; j<M-1; j++) {
            // per ogni elemento della matrice esclusa l'ultima riga e colonna
            fine = 0;
            for(i1=i+1; i1<N; i1++) {
                for(j1=j+1; j1<M; j1++) {
                    // per ogni elemento della sottomatrice
                    if(mat[i][j] <= mat[i1][j1]) {
                        fine = 1;
                    }
                    
                }
            }
            if (!fine) { // inserisci in testa
                out = InserisciInTesta(out, mat[i][j], i, j);
            }
        }
    }
    return out;
}