//Si vuole definire un programma in C che aiuti la mamma a capire se una ricetta può essere preparata con gli
//ingredienti disponibili in cucina. Il programma fa uso di due file:
//● Un primo file di testo contiene la lista e la quantità degli alimenti disponibili in cucina. Ogni riga riporta
//il nome di un alimento (una stringa di max 20 caratteri) e la quantità disponibile in cucina (un numero
//intero). Si può assumere che il file memorizzi al massimo N alimenti (N costante).
//● Un secondo file di testo contiene gli ingredienti necessari per la ricetta. Ogni riga riporta il nome di un
//ingrediente (una stringa di max 20 caratteri) e la quantità necessaria (un numero intero).
//Il programma deve confrontare le quantità richieste dalla ricetta con quelle disponibili; quindi, per ogni
//ingrediente della ricetta indica se esso sia disponibile o meno. Infine, il programma produce un messaggio che
//dice se la ricetta scelta può essere preparata o no. Per esempio, dati i file:
//    DISPENSA.TXT        TIRAMISU.TXT
//    Caffe 100           Uova 2
//    Uova 4              Mascarpone 300
//    Zucchero 150        Savoiardi 300
//    Savoiardi 200       Caffe 100
//                        Zucchero 100
//il programma deve produrre il seguente output:
//    Uova: OK
//    Mascarpone: manca 300
//    Savoiardi: manca 100
//    Caffe: OK
//    Zucchero: OK
//    La ricetta non può essere preparata
//Punto 3.1 (8 punti). Si scriva una funzione che, ricevuti come parametri i puntatori ai due file (si assume quindi
//che i file siano aperti nell’ambiente chiamante), esegua il confronto tra gli ingredienti contenuti nei due file e
//stampi l’output descritto sopra. La funzione, poi, restituisce 1 se la ricetta può essere preparata, 0 altrimenti.
//Punto 3.2 (4 punti). Si scriva il main del programma, completo di ogni dichiarazione, in modo che, ricevuti come
//parametri sulla linea di comando i nomi dei due file, invochi la funzione definita al punto precedente e infine
//stampi il messaggio “La ricetta può essere preparata!” se la funzione restituisce 1, oppure “La ricetta non può
//essere preparata” se la funzione restituisce 0.

#include <stdio.h>
#include <string.h>

#define N 5 // N alimenti

int ingredienti(FILE*, FILE*);

int main(int argc, char ** argv) {
    if (argc < 3) {
        printf("programma DISPENSA.TXT RICETTA.TXT\n");
        return -1;
    }

    FILE *disp = fopen(argv[1], "r");
    FILE *ingr = fopen(argv[2], "r");
    if(disp==NULL||ingr==NULL) {
        printf("Errore durante l'apertura dei file\n");
        return -1;
    }
    int out;
    out = ingredienti(disp, ingr);
    if (out) {
        printf("La ricetta può essere preparata!\n");
    } else {
        printf("La ricetta non può essere preparata\n");
    }
    return 0;
}

int ingredienti(FILE *disp, FILE *ingr) {
    char nome[20+1], nome1[20+1];
    int quant, quant1, trovato, ok=1;
    while(!feof(ingr)) { // scorro gli ingredienti
        fscanf(ingr, "%s %d\n", nome, &quant);
        rewind(disp); // riporto la dispensa all'inizio
        trovato = 0;
        while(!feof(disp)&&!trovato) {
            fscanf(disp, "%s %d\n", nome1, &quant1);
            if(strcmp(nome, nome1) == 0) {
                trovato = 1;
            }
        }
        if(trovato) {
            if (quant <= quant1) {
                printf("%s: OK\n", nome);
            } else {
                printf("%s: manca %d\n", nome, quant - quant1);
            }
        } else {
            ok = 0;
            printf("%s: manca %d\n", nome, quant);
        }
    }
    return ok;
}