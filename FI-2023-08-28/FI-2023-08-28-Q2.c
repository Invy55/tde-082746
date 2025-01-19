//Si formuli la funzione strcmpRicorsiva(char s1[], char s2[]), come versione ricorsiva della ben nota
//funzione strcmp(char s1[], char s2[]), definita in string.h, che confronta due stringhe in base
//all’ordinamento alfabetico e restituisce:
//● 0 se le stringhe sono uguali,
//● un valore < 0 se s1 precede alfabeticamente s2
//● un valore > 0 se s1 segue alfabeticamente s2

#include <stdio.h>

int strcmpRicorsiva(char[], char[]);

int main() {
    char s1[] = "";
    char s2[] = "adsfasdf";
    int out;

    out = strcmpRicorsiva(s1, s2);
    if (out == 0) {
        printf("Le stringhe sono uguali\n");
    } else if (out < 0) {
        printf("S1 precede alfabeticamente s2\n");
    } else {
        printf("S1 segue alfabeticamente s2\n");
    }
    return 0;
}

int strcmpRicorsiva(char s1[], char s2[]) {
    if (*s1 == '\0' && *s2 == '\0') { // se a fine stringa di entrambe => uguali
        return 0;
    } else if (*s1 == *s2) { // check next
        return strcmpRicorsiva(s1+1, s2+1);
    } else if (*s1 < * s2) { // se s1 < s2
        return -1;
    } else { // rimane se s1 > s2
        return 1;
    }
}