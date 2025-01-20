//Si vuole definire un programma in C che, data una matrice di interi di dimensione massima NxM (N ed M costanti
//predefinite), individui quanti e quali elementi, di seguito detti minimoRC, sono il minimo sia della colonna sia
//della riga in cui sono posizionati.

//1. Si definisca una funzione che, ricevuta come parametro la matrice e ogni altro parametro ritenuto strettamente
//necessario, analizzi la matrice e restituisca:
//- il numero di elementi che sono minimoRC
//- le coordinate (<riga, colonna>) di tutti elementi che sono minimoRC.
//Per esempio, data la seguente matrice di dimensione 3x4:
//        1  3 8  2
//        10 5 0  2
//        3  2 12 6       1  0  2
//gli elementi evidenziati in grassetto sono minimoRC. Quindi, la funzione restituirà il valore 3, come numero di
//elementi minimoRC trovati, e le coordinate (0,0) (1,2) (2,1).
//N.B.: La funzione può far uso di altre funzioni e di strutture dati aggiuntive.

//2. Si scriva il main di un programma, completo di ogni dichiarazione, che riceve come parametro sulla linea di
//comando il nome di un file che memorizza gli elementi di una matrice di elementi interi. Quindi:
//1. Legge il file e costruisce la matrice in esso memorizzata. Si assuma che il file abbia il seguente formato:
//- la prima riga memorizza il numero effettivo di righe e colonne della matrice memorizzata nel file;
//- le successive righe memorizzano le righe della matrice;
//- in ogni riga gli elementi sono separati da spazi;
//Per esempio, per la matrice nell’esempio precedente, il file sarà organizzato nel seguente modo:
//        3 4
//        1  3 8  2
//        10 5 2  0
//        3  2 12 6
//2. Invoca la funzione definita al punto precedente per l’analisi della matrice;
//3. Stampa il numero di elementi di tipo minimoRC trovati nella matrice e le loro coordinate.

#include <stdio.h>

#define N 3
#define M 4
#if M<N
    #define K M
#else
    #define K N
#endif


int minRC(int[][M], int, int, int[][2]);

int main(int argc, char **argv) {
    int i, j;
    if(argc < 2) {
        printf("Passare nome file");
        return -1;
    }
    FILE *fp = fopen(argv[1], "r");
    fscanf(fp, "%d %d\n", &i, &j);
    if(i>N||j>M) {
        printf("Matrice out of boundaries");
        return -1;
    }

    int mat[N][M] = {0};
    int minimiRC[K][2];
    int minimoRC;

    for(int p=0; p<i; p++) {
        for(int l=0; l<j; l++) {
            fscanf(fp, "%d", &mat[p][l]);
        }
    }

    minimoRC = minRC(mat, i, j, minimiRC);
    printf("Trovati %d minimiRC:\n", minimoRC);
    for(int p=0; p<minimoRC; p++) {
        printf("(%d, %d) ", minimiRC[p][0], minimiRC[p][1]);
    }
    printf("\n");
    
    fclose(fp);
    return 0;
}

int minRC(int mat[][M], int i, int j, int minimiRC[][2]) {
    int min, minj, isMin, cont=0;
    for(int p=0; p<i; p++) { // per ogni riga
        for(int l=0; l<j; l++) {
            if(l==0||mat[p][l]<min) {
                min = mat[p][l];
                minj = l;
            }
        }
        isMin = 1;
        for(int l=0; l<i; l++) {
            if(mat[l][minj]<min) {
                isMin = 0;
            }
        }

        if(isMin) {
            minimiRC[cont][0] = p;
            minimiRC[cont][1] = minj;
            cont++;
        }
    }
}