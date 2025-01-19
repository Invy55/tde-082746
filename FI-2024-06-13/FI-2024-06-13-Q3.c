//Si codifichi ricorsivamente in C una funzione int distingui(char s[], char up[], char low[])
//che riceve una stringa s (da analizzare) e due stringhe inizialmente vuote, ma già allocate e
//di dimensione pari a quella di s. La funzione dovrà
//(i) copiare nelle stringhe up e low i caratteri alfabetici rispettivamente maiuscoli e minuscoli
//di s, nello stesso ordine in cui compaiono in s, e
//(ii) restituire al chiamante il numero di caratteri non alfabetici di s (non copiati).
//Esempio: con s[] = "2Ew?jm7y9TR£" avremmo up[] = "ETR", low[] = "wjmy", valore restituito:
//5 (caratteri 2 ? 7 9 e £ ). Per il punteggio pieno è necessario che il risultato sia individuato
//ricorsivamente. Una soluzione sostanzialmente iterativa varrà al più 4 punti.

#include <stdio.h>
#define LEN 25

int distingui(char[], char[], char[]);

int main(int argc, char **argv) {
    char s[LEN]="stRINGa-di.PROva", up[LEN], low[LEN];
    int out;
    out = distingui(s, up, low);
    printf("%s, %s, %d", up, low, out);
    return 0;
}

int distingui(char s[], char up[], char low[]) {
    char cur = *s;
    if (cur == '\0') { // terminatore di stringa
        *up = '\0';
        *low = '\0';
        return 0;
    } else if (cur>='a' && cur<='z') { // carattere minuscolo
        *low = cur;
        *(++low) = '\0';
        return distingui(++s, up, low);
    } else if (cur>='A' && cur<='Z') { // carattere maiuscolo
        *up = cur;
        *(++up) = '\0';
        return distingui(++s, up, low);
    } else { // non lettera
        return 1 + distingui(++s, up, low);
    }
}