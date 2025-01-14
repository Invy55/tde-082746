//Un’azienda ha dotato i propri dipendenti di un sensore che emette un codice numerico ogni volta che un
//dipendente attraversa la porta d’ingresso/uscita dell’azienda. L’azienda ha meno di 100 dipendenti. A ogni
//attraversamento, il sensore registra ora e minuti del passaggio, insieme al codice del dipendente (un
//codice alfanumerico di max 4 caratteri).
//Le registrazioni di una giornata sono memorizzate in un file composto da righe, ciascuna corrispondente
//a un passaggio e composta da tre campi: ora, minuti, codice_dipendente. Es.:
//8 30 a123
//8 31 z312
//12 00 z312
//12 10 a123
//Si può assumere che le registrazioni nel file siano ordinate temporalmente e che per ogni dipendente che
//risulti presente ci siano al massimo due registrazioni (una in entrata e una in uscita).

//Punto 1 (8 punti). Si codifichi una funzione in C che, ricevuti come parametri il puntatore al file e il codice
//di un dipendente, calcoli e restituisca al chiamante, per il dipendente specificato, il numero totale di minuti
//lavorati. Se il dipendente non risulta presente, la funzione restituisce 0.
//Es.: considerando il contenuto del file riportato sopra, per il codice a123 la funzione restituirà 220. Per il
//codice b222 restituirà 0.

//Punto 2 (4 punti). Si sviluppi un programma (main) che riceve sulla linea di comando un primo parametro,
//che rappresenta il nome del file contenente gli attraversamenti e, ***opzionalmente***, un secondo
//parametro che rappresenta il codice numerico di un dipendente:
//• Se il programma viene invocato con due parametri sulla linea di comando (è presente il codice del
//dipendente), allora invoca la funzione definita al punto 1 e stampa, per il dipendente specificato,
//il numero totale di minuti lavorati.
//• Se invece il programma viene invocato con un solo parametro sulla linea di comando (il codice del
//dipendente è assente), il programma stampa i dati dei passaggi registrati in quel giorno,
//cioè l’intero contenuto del file.

#include <stdio.h>
#include <string.h>

#define N 4

int tempo(FILE*, char[]);

int main(int argc, char ** argv) {
    if (argc < 2) {
        printf("Inserire il nome del file prima dell'esecuzione\n");
        return -1;
    }
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Impossibile aprire il file\n");
        return -1;
    }
    if (argc == 3) { // è stato inserito il codice dipendente da cercare
        int out;
        out = tempo(fp, argv[2]);
        printf("Minuti lavorativi per %s: %d\n", argv[2], out);
        return 0;
    }
    // caso generale
    int o, m;
    char dipendente[N+1];
    while(!feof(fp)) {
        fscanf(fp, "%d %d %s", &o, &m, dipendente);
        printf("%d:%02d - %s\n", o, m, dipendente);
    }
    return 0;
}

int tempo(FILE *fp, char user[]) {
    int o1=-1, m1, o2, m2, o, m;
    char dipendente[N+1];
    rewind(fp); // torna a inizio file
    while(!feof(fp)) {
        fscanf(fp, "%d %d %s", &o, &m, dipendente);
        if (strcmp(user, dipendente) == 0) { // dipendente corretto
            if(o1 <0) {
                o1 = o;
                m1 = m;
            } else {
                o2 = o;
                m2 = m;
            }
        }
    }
    if(o1 <0) {
        return 0; // dipendente non trovato -> 0 ore
    }

    return (o2 - o1)*60 + m2 - m1;
}