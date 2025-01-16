//Si codifichi ricorsivamente in C una funzione char min_ch( char s[] ) che restituisce il minimo carattere di
//s (nel consueto ordine alfabetico). E’ necessario, per il punteggio pieno, che il risultato sia individuato con il
//metodo ricorsivo. Esempi: “MELO” → ‘E’ “BURRO” → ‘B’ “ZANGOLA” → ‘A’ “F” → ‘F’ “” → ‘\0’

#include <stdio.h>

char min_ch(char[]);

int main() {
    char out;
    out = min_ch("");
    printf("%c [%d]\n", out, (int)out);
    return 0;
}

char min_ch(char s[]) {
    if (*s == '\0') return '\0';
    char next;
    next = min_ch(s+1);
    if(*s<next || next == '\0') {
        return *s;
    } else {
        return next;
    }
}