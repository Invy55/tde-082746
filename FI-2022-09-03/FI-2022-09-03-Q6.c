//Siano dati due file che memorizzano ognuno una sequenza
//ordinata di interi positivi con possibili ripetizioni, s1 e s2. Il numero di valori nelle due sequenze non è
//noto a priori. A partire da s1 ed s2, si vuole creare una nuova sequenza che fonda i valori di s1 e s2 in
//modo ordinato e senza ripetizioni.
//Per esempio, se s1= {0 1 3 4 5 5 6 7 7 7 7 8 8} ed s2 = {3 3 3 3 3 3 3 4 5 9},
//allora la nuova sequenza sarà
//s3 = {0 1 3 4 5 6 7 8 9}.
//La nuova sequenza s3 deve essere memorizzata su un nuovo file.

//1. Si scriva una funzione che riceve come parametri i puntatori a tre file distinti: i primi
//due memorizzano le due sequenze s1 e s2, sul terzo dovrà essere slavata la nuova funzione.
//La funzione dovrà calcolare e scrivere nel terzo file la nuova sequenza s3.
//Restituirà all’ambiente chiamante: 1 se il salvataggio della nuova sequenza va a buon fine, 0 altrimenti.

//2. Si definisca il main di un programma (completo di opportune dichiarazioni a livello
//globale e locale), che:
//- riceva da riga di comando (parametro del main) il nome dei tre file
//- invochi la funzione definita al punto precedente
//- stampi un messaggio che indichi se il salvataggio della nuova sequenza è andato a buon fine

#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int value;
    struct nd * next;
} Nodo;
typedef Nodo * Lista;

int funzione(FILE*, FILE*, FILE*);
void stampa(Lista);

int main(int argc, char ** argv) {
    if(argc <4) {
        printf("program 1.txt 2.txt out.txt");
        return -1;
    }
    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");
    FILE *fout = fopen(argv[3], "w");
    if(f1==NULL||f2==NULL||fout==NULL) {
        printf("Errore durante l'apertura di un file\n");
        return -1;
    }

    if(funzione(f1, f2, fout)) {
        printf("Salvataggio andato a buon fine!");
    } else {
        printf("Salvataggio fallito!");
    }

    fclose(f1);
    fclose(f2);
    fclose(fout);
    return 0;
}

int funzione(FILE *f1, FILE *f2, FILE *fout) {
    Lista s1=NULL, s2=NULL, sout=NULL, cur;
    int valore;
    // riempo le liste
    cur = s1;
    while(!feof(f1)) {
        fscanf(f1, "%d", &valore);
        if(cur==NULL) {
            s1 = (Lista)malloc(sizeof(Nodo));
            cur = s1;
        } else {
            cur->next = (Lista)malloc(sizeof(Nodo));
            cur = cur->next;
        }
        cur->value = valore;
        cur->next = NULL;
    }
    cur = s2;
    while(!feof(f2)) {
        fscanf(f2, "%d", &valore);
        if(cur==NULL) {
            s2 = (Lista)malloc(sizeof(Nodo));
            cur = s2;
        } else {
            cur->next = (Lista)malloc(sizeof(Nodo));
            cur = cur->next;
        }
        cur->value = valore;
        cur->next = NULL;
    }

    if(s1==NULL && s2==NULL) return 0;

    // scorro le liste
    while(s1!=NULL||s2!=NULL) {
        if(sout == NULL) { // non ho già aggiunto nessun elemento a fout
            sout = (Lista)malloc(sizeof(Nodo));
            sout->next = NULL;
            if(s1->value < s2->value){
                sout->value = s1->value;
                s1 = s1->next;
            } else {
                sout->value = s2->value;
                s2 = s2->next;
            }
            cur = sout;
        } else {
            //printf("%d %d %d\n", s1->value, s2->value, cur->value);
            if(s1!=NULL&&s1->value < s2->value || s2 == NULL && s1 != NULL) {
                if(s1->value != cur->value) {
                    cur->next = (Lista)malloc(sizeof(Nodo));
                    cur = cur->next;
                    cur->value = s1->value;
                    cur->next = NULL;
                }
                s1 = s1->next;
            } else {
                if(s2->value != cur->value) {
                    cur->next = (Lista)malloc(sizeof(Nodo));
                    cur = cur->next;
                    cur->value = s2->value;
                    cur->next = NULL;
                }
                s2 = s2->next;
            }
        }
    }

    // stampo nel file
    while(sout!=NULL) {
        fprintf(fout, "%d ", sout->value);
        sout = sout->next;
    }

    return 1;
}