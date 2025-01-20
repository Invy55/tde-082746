//Ti è mai capitato di re-inserire qualche prodotto già presente nella tua “lista della spesa”, magari digitale, solo
//perché usavi un editor che non rileva le ripetizioni? Con Spesa Facile sarà solo un brutto ricordo! Per esempio:
//        mele 2
//        pere 2
//        pane 1
//        mele 1
//        pesto 2
//        mele 4
//        olio 1
//        pere 1
//nell’elenco soprastante, dove i prodotti sono rappresentati da un nome (stringa di max 20 caratteri) e una
//quantità da acquistare (numero intero), figurano in totale 7 mele e 3 pere, ma compaiono in linee duplicate,
//forse aggiunte distrattamente, in tempi diversi.
//Punto 1 (9 punti). Si codifichi in C una funzione void ripulisci(FILE * fin, FILE * fout) che riceve
//dal chiamante due file testuali (già aperti) (fin in modalità lettura e contenente l’elenco dei prodotti
//potenzialmente duplicati, fout in modalità scrittura e inizialmente vuoto), individua e unifica i prodotti
//duplicati, e salva in fout l'elenco compattato.
//Attenzione:
//- Nel leggere il file in input la funzione si troverà verosimilmente a riversare i dati in una qualche struttura
//dati; si badi a progettarla in modo conveniente e a definirla in modo chiaro e comprensibile.
//- Si può considerare definito un limite al numero di diversi prodotti inseribili(#define MAX_PROD 100) .
//- Si ipotizzi che le linee del file di input siano sempre ben formate (con una stringa e un intero).
//- Il file di output conterrà un nuovo elenco, senza linee duplicate, sostituite da un’unica linea con quantità
//uguale alla somma delle quantità di tutti i duplicati eliminati. Dall’esempio riportato sopra si otterrà:
//        mele 7
//        pere 3
//        pane 1
//        pesto 2
//        olio 1
//Punto 2 (3 punti). Si codifichi un programma C (main) che riceve da linea di comando i nomi dei due file, invoca
//la funzione definita al punto precedente e stampa un messaggio per comunicare l’esito dell’operazione.
//Si chiede di gestire esplicitamente gli eventuali errori nei parametri del main e nell’apertura del file.

#include <stdio.h>
#include <string.h>
#define MAX_PROD 100

typedef struct elemento {
    char nome[21];
    int numero;
} elemento;

void ripulisci(FILE *, FILE *);

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Passare i nomi dei file\n");
        return -1;
    }
    FILE *fin, *fout;
    fin = fopen(argv[1], "r"); // FI-2024-01-20-Q2-IN.txt
    fout =  fopen(argv[2], "w"); // FI-2024-01-20-Q2-OUT.txt

    if(fin == NULL) {
        printf("Errore durante l'apertura del file di input\n");
        return -1;
    }

    if(fout == NULL) {
        printf("Errore durante l'apertura del file di output\n");
        return -1;
    }

    ripulisci(fin, fout);

    printf("Fatto\n");
    fclose(fin);
    fclose(fout);
    return 0;
}

void ripulisci(FILE * fin, FILE * fout) {
    elemento lista[MAX_PROD], cur;
    int i, count=0, trovato;
    while(!feof(fin)) {
        fscanf(fin, "%s %d\n", cur.nome, &cur.numero);
        trovato = 0;
        i = 0;
        for(i=0; i<count; i++) {
            if(strcmp(cur.nome, lista[i].nome) == 0) {
                lista[i].numero += cur.numero;
                trovato = 1;
            }   
        }
        if(!trovato) {
            strcpy(lista[count].nome, cur.nome);
            lista[count].numero = cur.numero;
            count++;
        }
    }
    for(i=0; i<count; i++) {
        if (i==0) {
            fprintf(fout, "%s %d", lista[i].nome, lista[i].numero);
        } else {
            fprintf(fout, "\n%s %d", lista[i].nome, lista[i].numero);
        }
    }
}