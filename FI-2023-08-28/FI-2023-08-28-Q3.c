//Si consideri una matrice di dimensioni MxN che contiene valori binari 0 e 1. La matrice rappresenta una griglia
//di possibili percorsi, in cui 0 indica un varco attraversabile e 1 rappresenta un muro invalicabile. I movimenti
//all'interno di questa griglia avvengono in orizzontale e verticale, e possono essere rappresentati da coppie di
//valori (±i, 0), per gli spostamenti verticali (verso l'alto o il basso), e (0, ±j) per gli spostamenti orizzontali (a destra
//o a sinistra). i e j rappresentano cioè scostamenti di riga e di colonna, rispettivamente.
//Dopo aver opportunamente dichiarato le strutture dati necessarie, e cioè la matrice e l’array delle mosse, si
//definisca una funzione che, ricevuti come parametri la matrice dei percorsi, l’array di mosse, e qualsiasi altro
//parametro ritenuto necessario, verifichi che partendo dalla cella iniziale della matrice di coordinate (0, 0)
//l'applicazione sequenziale dei movimenti sulla matrice porti a un percorso valido, ovvero un percorso che non
//incontri muri.
//La funzione stampa quindi un messaggio opportuno che indichi se il percorso è stato completamente applicato
//oppure se è stato applicato parzialmente, e riporti le coordinate dell’elemento della matrice su cui il cammino
//è terminato.
//Per esempio, si consideri la seguente matrice:
//      0 1 0 1 1
//      0 0 1 1 0
//      1 0 0 0 0
//      1 1 0 1 0
//      1 1 1 1 0
//● La sequenza di mosse (1, 0), (0, 1), (1, 0), (0, 3), (-1, 0) è interamente realizzabile e porta nell’elemento di
//indici [1, 4]. La funzione stampa un messaggio indicante il successo e la coppia di indici di arrivo, [1, 4].
//● La sequenza (1, 0), (0, 2), (2, 0), invece, si ferma alla seconda mossa, poiché la cella di indici [1, 2] memorizza
//un muro. La funzione, quindi, stampa un messaggio di insuccesso e gli indici dell’ultima cella attraversata,
//[1,0].
//● La sequenza (1, 0), (0, 2), (5, 0) porta oltre i limiti della matrice a causa della terza mossa. In tal caso, la funzione
//stampa un messaggio di insuccesso e gli indici dell’ultima cella valida, [1,2]. (??)
//N.B.: Per l’array contenente le mosse si può ipotizzare una dimensione massima predefinita e costante, K

#include <stdio.h>
#define M 5 // righe
#define N 5 // colonne
#define K 5 // n mosse

void testMosse1(int[][N], int[][2]);
void testMosse2(int[][N], int[][2]);

int main() {
    int mat[M][N] = {{0,1,0,1,1},
                     {0,0,1,1,0},
                     {1,0,0,0,0},
                     {1,1,0,1,0},
                     {1,1,1,1,0}};
    int mosse[K][2] = {{1,0},{0,1},{1,0},{0,3},{-1,0}};
    
    testMosse1(mat, mosse);
    testMosse2(mat, mosse);

    return 0;
}

void testMosse2(int mat[][N], int mosse[][2]) {
    int fine=0, k, i, j, c=0, max, cord, magg;
    int pos[2] = {0,0};
    while(c<K && !fine) { // per ogni mossa c da 0 a K
        i = 0;
        j = 0;
        if(mosse[c][0] > 0) { //mosse in giù
            max = mosse[c][0];
            i=1;
            cord = 0;
            magg = M;
        } else if(mosse[c][0] < 0) { //mosse in su
            max = -1*mosse[c][0];
            i=-1;
            cord = 0;
            magg = M;
        } else if(mosse[c][1] > 0) { //mosse a dx
            max = mosse[c][1];
            j=1;
            cord = 1;
            magg = N;
        } else if(mosse[c][1] < 0) { //mosse a sx
            max = -1*mosse[c][1];
            j=-1;
            cord = 1;
            magg = N;
        }

        //printf("[%d, %d] (%d, %d) max %d i %d j %d cord %d\n", pos[0], pos[1], mosse[c][0], mosse[c][1], max, i, j, cord);

        for(k=1; k<=max; k++) {
            if(pos[cord]+k*(i+j) > magg || pos[cord]+k*(i+j) < 0 // out of boundaries
            || mat[pos[0]+(k*i)][pos[1]+(k*j)] == 1) { //muro
                // errore
                fine = -1;
            }
        }
        if (!fine) {
            pos[cord] += max * (i+j);
        }

        c++;
    }
    if(fine<0) {
        printf("Fallito! Ultima posizione: %d, %d\n", pos[0], pos[1]);
    } else {
        printf("Successo! Nuova posizione: %d, %d\n", pos[0], pos[1]);
    }
    
}

void testMosse1(int mat[][N], int mosse[][2]) {
    int fine=0, i, j, c=0;
    int pos[2] = {0,0};
    while(c<K && !fine) { // per ogni mossa c da 0 a K
        if(mosse[c][0] > 0) { //mosse in giù
            for(i=1; i<=mosse[c][0]; i++) {
                if(pos[0]+i > M || mat[pos[0]+i][pos[1]] == 1) {
                    // errore
                    fine = -1;
                }
            }
            if (!fine) {
                pos[0] += mosse[c][0];
            }
        } else if(mosse[c][0] < 0) { //mosse in su
            for(i=1; i<=mosse[c][0]*-1; i++) {
                if(pos[0]-i < 0 || mat[pos[0]-i][pos[1]] == 1) {
                    // errore
                    fine = -1;
                }
            }
            if (!fine) {
                pos[0] += mosse[c][0];
            }
        }

        if(mosse[c][1] > 0) { //mosse a dx
            for(i=1; i<=mosse[c][1]; i++) {
                if(pos[1]+i > N || mat[pos[0]][pos[1]+i] == 1) {
                    // errore
                    fine = -1;
                }
            }
            if (!fine) {
                pos[1] += mosse[c][1];
            }
        } else if(mosse[c][1] < 0) { //mosse a sx
            for(i=1; i<=mosse[c][1]*-1; i++) {
                if(pos[1]-i < 0 || mat[pos[0]][pos[1]-i] == 1) {
                    // errore
                    fine = -1;
                }
            }
            if (!fine) {
                pos[1] += mosse[c][1];
            }
        }
        c++;
    }
    if(fine<0) {
        printf("Fallito! Ultima posizione: %d, %d\n", pos[0], pos[1]);
    } else {
        printf("Successo! Nuova posizione: %d, %d\n", pos[0], pos[1]);
    }
    
}