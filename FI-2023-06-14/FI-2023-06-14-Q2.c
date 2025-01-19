//Una sequenza di caratteri è rappresentata da una lista dinamica. Scrivere una funzione che,
//ricevendo in ingresso una lista dinamica che rappresenta una sequenza di soli caratteri alfabetici, la comprime
//sostituendo ad ogni sottosequenza di almeno due caratteri alfabetici consecutivi uguali (ad esempio ..bbbb..),
//una coppia di caratteri (nell’esempio ..b4..) costituita dal carattere alfabetico che viene ripetuto e dalla cifra (un
//carattere compreso tra ‘2’ e ‘9’) che indica la lunghezza della sottosequenza.
//Per esempio, la sequenza sabbbassasemmmmpre diventa sab3as2asem4pre.
//NOTA: si suppone che nella lista in ingresso non vi siano mai più di 9 caratteri alfabetici uguali consecutivi.

#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    char c;
    struct nd * next;
} Lettera;
typedef Lettera * Stringa;

void comprimi(Stringa);
void stampa(Stringa);

int main() {
    char str[] = "sabbbassasemmmmpre";
    Stringa s = NULL, cur;
    cur = s;
    for(char *i=str; *i!='\0'; i++) {
        if(cur == NULL) {
            s = (Stringa)malloc(sizeof(Lettera));
            cur = s;
            cur->c = *i;
        } else {
            cur->next = (Stringa)malloc(sizeof(Lettera));
            cur = cur->next;
            cur->c = *i;
        }
    }
    cur->next = NULL; // aggiungi terminatore stringa
    comprimi(s);

    stampa(s);

    return 0;
}

void comprimi(Stringa s) {
    Stringa last = NULL, cur;
    int cont = 0;
    cur = s;
    while(cur!=NULL) {
        if (last == NULL) {
            last = cur;
            cont = 0;
        } else if (last->c == cur->c) {
            cont++;
        } else {
            if (cont > 0) {
                last->next = (Stringa)malloc(sizeof(Lettera));
                last->next->c = '1'+cont;
                last->next->next = cur;
            }
            cont = 0;
            last = cur;
        }
        cur = cur->next;
    }
    if (cont > 0) {
        last->next = (Stringa)malloc(sizeof(Lettera));
        last->next->c = '1'+cont;
        last->next->next = cur;
    }
}

void stampa(Stringa lis) {
    Stringa cur;
    int fine=0;
    cur = lis;
    while(cur!=NULL) {
        printf("%c", cur->c);
        cur = cur->next;
    }
}