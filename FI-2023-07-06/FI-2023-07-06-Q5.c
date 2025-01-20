//Si scriva un programma in C, completo di parti dichiarative che, dopo aver letto i valori della
//matrice da un file, invochi in modo opportuno le funzioni definite ai punti precedenti per costruire la lista
//ordinata degli elementi dominanti della matrice. Il programma stampa quindi la lista.
//Per la lettura della matrice dal file, si consideri che:
//1. Il nome del file da cui leggere la matrice deve essere letto da riga di comando (deve cioè essere gestito
//come parametro del main).
//2. Il file è organizzato in modo che la prima riga memorizzi le dimensioni effettive della matrice, n e m. Si
//può assumere che questi valori siano minori o uguali alle costanti predefinite N e M, che invece
//rappresentano le dimensioni massime costanti della matrice.
//3. Ogni riga successiva del file memorizza i valori delle righe della matrice separati da uno spazio. Per
//esempio, il file che memorizza la matrice riportata come esempio nel quesito 2 sarà organizzato nel
//seguente modo:
//        8 4
//        5 9 2 4 1 5 2 4
//        3 5 6 2 5 6 1 2
//        1 3 4 7 8 2 4 0
//        1 3 5 6 7 8 2 1

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

void stampa(Lista);
Lista Ordina(Lista);
Lista MinimoInTesta(Lista);
Lista Dominante(int [][M]);
Lista InserisciInTesta(Lista, int, int, int);

int main(int argc, char ** argv) {
    int i,j;
    /*if(argc <2) {
        printf("Specificare il nome del file\n");
        return -1;
    }*/
    FILE *fp = fopen("FI-2023-07-06-Q5.txt", "r");
    if (fp == NULL) {
        printf("Errore durante l'apertura del file\n");
        return -1;
    }
    fscanf(fp, "%d %d\n", &j, &i);
    if(i > N || j > M) {
        printf("Out of boundaries\n");
        return -1;
    }
    int mat[N][M] = {0};
    for(int k=0; k<i; k++) {
        for(int l=0; l<j; l++) {
            fscanf(fp, "%d", &mat[k][l]);
        }
    }
    Lista lis;
    lis = Dominante(mat);

    lis = Ordina(lis);
    stampa(lis);
    fclose(fp);
    return 0;
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
            printf("|%d (%d, %d)|", cur->value, cur->i, cur->j);
        } else{
            printf(" -> |%d (%d, %d)|", cur->value, cur->i, cur->j);
        }
        if(cur != NULL) {
            cur = cur->next;
        }
    }
}

Lista Ordina(Lista lis) {
    if(lis==NULL) return NULL;

    lis = MinimoInTesta(lis);
    lis->next = Ordina(lis->next);

    return lis;
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