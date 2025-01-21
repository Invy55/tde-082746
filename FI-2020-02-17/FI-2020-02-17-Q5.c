//Dato un file di testo e una sequenza di caratteri alfabetici minuscoli tutti diversi tra loro, si vuole determinare il
//numero di volte in cui i caratteri della sequenza compaiono nel file. La sequenza può avere lunghezza variabile e
//comunque non superiore a 26 caratteri.
//Per esempio, se il file contiene il testo: Il mio cucciolo vuole sempre giocare
//e i caratteri da cercare nel file sono quelli nella sequenza: mar
//l’output sarà:
//m: 2
//a: 1
//r: 2
//(6 punti) Si definisca una funzione che, ricevuti come parametri il puntatore al file di testo, la sequenza di caratteri
//e qualsiasi altro parametro ritenuto necessario, determini la frequenza nel file di ogni carattere della sequenza
//e stampi a video i risultati nel formato sopra riportato.
//(2 punti) Si scriva un programma che:
//1. Acquisisce da riga di comando il nome del file;
//2. Chiede all’utente di immettere la sequenza di caratteri; si può assumere che l’utente immetta in input
//una stringa di caratteri minuscoli e tutti distinti (quindi di lunghezza minore o uguale a 26);
//3. Dopo aver aperto il file, richiama la funzione definita al punto precedente.
//(1 punto) Si spieghi brevemente come cambierebbero la funzione e il main se, invece di stampare i risultati, la
//funzione dovesse restituire al main, come valori di ritorno, i caratteri e le rispettive frequenze.

#include <stdio.h>

void frequenza(FILE*, char[]);

int main(int argc, char ** argv) {
    if(argc<2) {
        printf("Specifica nome file\n");
        return -1;
    }
    FILE *fp = fopen(argv[1], "r");
    if(fp==NULL) {
        printf("Impossibile aprire il file\n");
        return -1;
    }
    char sequenza[27];
    printf("Inserire stringa da cercare: ");
    scanf("%s", sequenza);

    frequenza(fp, sequenza);

    fclose(fp);
    return 0;
}

void frequenza(FILE *fp, char str[]) {
    int cont[26]={0};
    char c;
    while(!feof(fp)) {
        c = fgetc(fp);
        if(c>='a'&&c<='z') {
            cont[c-'a']++;
        }
    }

    while((c=*str) != '\0') {
        printf("%c: %d\n", c, cont[c-'a']);
        str++;
    }
}