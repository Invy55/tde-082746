//Un file testuale contiene informazioni sulla provenienza dei partecipanti a un congresso
//scientifico: ogni riga, nel formato cognome nazione, riguarda un diverso partecipante. Dal
//file, esemplificato a lato, si vuole estrarre una struttura dati che a ciascuna nazione associ
//il numero di partecipanti da essa provenienti (nell’es.: Italia: 2, Chile: 1, USA: 3, UK:1).

//(a) Si codifichi in C una funzione … provenienze( FILE * fp, … ) che riceve un file (già aperto in
//modalità lettura) e rende disponibile all’ambiente chiamante una opportuna struttura dati
//(da definire) che contiene le coppie ⟨nazione, numero_partecipanti⟩. Si consideri, per
//semplicità, che il file sia sempre ben formato (ogni riga, cioè, ha sempre esattamente
//due stringhe, ciascuna di massimo 25 caratteri). [8 p.]

//(b) Si codifichi in C un programma (main) che, ricevuto da linea di comando il nome di un file come
//quello d’esempio, lo apre, invoca la funzione sopra definita, e stampa opportunamente su stdout le
//statistiche calcolate dall’invocazione. Si gestiscano gli eventuali errori nei parametri del main e
//nell’apertura del file. [4 p.]

//Esempio di possibile output del programma:
//Italia : 2
//Chile : 1
//USA : 3
//UK : 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 25
typedef struct nd {
    char nome[N+1];
    int partecipanti;
    struct nd *next;
} Nazione;

Nazione * provenienze(FILE*, Nazione*);

int main(int argc, char * argv[]) {
    if(argc < 2) {
        printf("Inserire il nome del file prima dell'esecuzione\n");
        return -1;
    }
    // potrei typedef Nazione* ptrNazione; e usare ptrNazione nazioni;
    Nazione *nazioni = NULL; // lista o array, non è specificato

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Impossibile aprire il file\n");
        return -1;
    }

    nazioni = provenienze(fp, nazioni);

    while (nazioni != NULL) {
        printf("%s: %d\n", nazioni->nome, nazioni->partecipanti);
        nazioni = nazioni->next;
    }

    fclose(fp);
    return 0;
}

Nazione * provenienze(FILE *fp, Nazione *nazioni) {
    Nazione *out, *cur, *prev=NULL;
    int c, trovato;
    char nome[N+1], nazione[N+1];
    out = nazioni;
    while(!feof(fp)) {
        fscanf(fp, "%s %s\n", nome, nazione);
        cur = out;
        trovato = 0;
        while(cur!=NULL && trovato==0) {
            if(strcmp(cur->nome, nazione)==0) {
                cur->partecipanti++;
                trovato = 1;
            }
            prev = cur;
            cur = cur->next;
        }
        if(!trovato) {
            cur = (Nazione*)malloc(sizeof(Nazione));
            strcpy(cur->nome, nazione);
            cur->partecipanti = 1;
            if (prev == NULL){
                out = cur;
            } else {
                prev->next = cur;
            }
        }
    }

    return out;
}
