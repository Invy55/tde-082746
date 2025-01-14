//Si definisca una funzione che calcoli il numero di giorni che intercorrono tra due date
//dell'anno 2024. Si supponga che nell’ambiente globale del programma sia presente la dichiarazione
const int Anno[12]= {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//i cui elementi coincidono con il numero dei giorni dei 12 mesi dell’anno 2024.
//Per calcolare la differenza in giorni tra due date, si definisca un nuovo tipo Data che comprende due campi
//interi: il primo, con valori variabili tra 1 e 31, rappresenta il giorno del mese mentre il secondo, variabile tra
//1 e 12, rappresenta il mese.
//La funzione:
//(i) riceve due parametri di tipo Data che rappresentano due date
//(ii) verifica che entrambe siano date valide per l’anno 2024 e che la prima data sia anteriore alla seconda
//(iii) se entrambe le date sono valide, e la prima data è anteriore alla seconda, restituisce il numero di giorni
//che intercorrono tra la prima e la seconda data, altrimenti restituisce un intero negativo.
//Per esempio, se la funzione riceve le date 25/12 e 26/12, essa restituisce il valore 1; se riceve 7/2 e 28/4 essa
//restituisce il valore 81 (pari a 29-7=22 giorni in febbraio + 31 in marzo + 28 in aprile). Se invece la funzione
//riceve le date 30/2 e 12/11 restituisce un valore negativo poiché la prima data (30 febbraio) non è valida;
//anche se riceve 27/9 e 28/4 la funzione restituisce un valore negativo, poiché la prima data non è anteriore
//alla seconda.

//Si codifichi il main di un programma che, utilizzando la funzione definita al punto
//precedente, aiuti un albergatore a calcolare delle statistiche sulla durata dei soggiorni dei clienti presso la
//sua struttura.
//Un file di testo memorizza, per ogni soggiorno presso l’hotel, la data di arrivo e la data di partenza. Ogni riga
//del file riporta, per un singolo soggiorno, le due date nel formato <gg mm gg mm>. Ogni riga memorizzerà
//quindi 4 interi, separati da spazi: il primo e il secondo rappresentano giorno e mese di arrivo; il terzo e il
//quarto il giorno e il mese di partenza.
//Esempio di contenuto del file:
//Si può supporre che ogni riga del file contenga due date. Tuttavia, la loro
//validità deve essere controllata secondo quanto spiegato al punto precedente.
//Il main riceve il nome del file come parametro sulla linea di comando. Quindi, leggendo i dati dal file e
//utilizzando la funzione definita al punto precedente, il programma calcola e stampa la durata media dei
//soggiorni.

#include <stdio.h>

typedef struct d {
    int giorno;
    int mese;
} Data;

int diffDate(Data, Data);

// main usato per testare la parte 1
/*int main() {
    Data data1, data2;
    int out;
    // data 1
    data1.giorno = 7;
    data1.mese = 2;
    // data 2
    data2.giorno = 28;
    data2.mese = 4;
    // output
    out = diffDate(data1, data2);
    if (out >= 0)
    printf("Diff: %d", out);
    else
    printf("invalid");
    return 0;
}*/

// main parte 2
int main(int argc, char* argv[]) {
    int somma, c=0, diff, err=0;
    Data data1, data2;
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp == NULL) {
            printf("Errore durante l'apertura del file.\n");
            return -1;
        }
        while(!feof(fp)) {
            fscanf(fp, "%d %d %d %d\n", &data1.giorno, &data1.mese, &data2.giorno, &data2.mese);
            diff = diffDate(data1, data2);
            if (diff >= 0) {
                c++;
                somma += diff;
            } else {
                err++;
            }
        }
        printf("La media è di %d giorno/i (arrotondati per difetto)\n", somma/c);
        if (err > 0) {
            printf("Si è verificato un errore con %d data/e", err);
        }
        
        fclose(fp);
    }
    return 0;
}

int diffDate(Data data1, Data data2) {
    //(ii)
    if(!(data1.mese>0 && data1.mese<=12 && data1.giorno>0 && data1.giorno<=Anno[data1.mese-1])) return -1; // giorno 1 non valido
    if(!(data2.mese>0 && data2.mese<=12 && data2.giorno>0 && data2.giorno<=Anno[data2.mese-1])) return -2; // giorno 2 non valido
    if(!(data1.mese<data2.mese || (data1.mese==data2.mese && data1.giorno<data2.giorno))) return -3;       // date non in ordine data1 < data2
    //(iii)
    int giorni=0;
    for(int i=data1.mese; i<=data2.mese; i++) {
        giorni += Anno[i-1];        
    }
    giorni -= data1.giorno + (Anno[data2.mese-1] - data2.giorno);
    return giorni;
}