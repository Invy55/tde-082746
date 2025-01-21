//Si definisca un sottoprogramma che data una stringa s e un carattere ch (e qualsiasi altro parametro
//ritenuto necessario), restituisca all’ambiente chiamante una lista i cui nodi memorizzano stringhe costituite dai
//caratteri che in s sono compresi tra due occorrenze di ch (queste occorrenze escluse). Tali stringhe, se esistono,
//hanno una dimensione massima N predefinita. Nel caso in cui s non contenga due occorrenze del carattere ch,
//il sottoprogramma restituisce una lista vuota.
//Si garantisce che, se ch è presente almeno due volte in s, il numero di caratteri compreso tra le due occorrenze
//non superi mai la lunghezza predefinita N.

//Per esempio:
//- se s = "almanacco" e ch ='a', il sottoprogramma restituisce la lista: “lm"--> “n”
//- se s = "uno-due-tre" e ch ='i' il sottoprogramma restituisce una lista vuota.
//Oltre a definire la funzione, si definisca opportunamente il tipo degli elementi della lista.

//Scrivere un programma che acquisisce da riga di comando una stringa e un carattere e richiama il
//sottoprogramma sviluppato al punto precedente. Quindi visualizza la lista costruita dal sottoprogramma (un
//elemento per riga) e termina. Nel caso di lista vuota, il sottoprogramma stampa il messaggio “Lista vuota”.
//Per esempio, se il nome del programma è “ritaglia”, si riportano sotto due esempi di esecuzione:
//./ritaglia almanacco a
//lm
//n
//./ritaglia uno-due-tre i
//Lista vuota

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

typedef struct nd {
    char value[N+1];
    struct nd * next;
} Nodo;
typedef Nodo * Lista;

void stampa(Lista);
Lista ritaglia(char[], char);

int main(int argc, char ** argv) {
    Lista lis;
    if(argc < 3) {
        return -1;
    }
    lis = ritaglia(argv[1], argv[2][0]);
    if(lis) {
        stampa(lis);
    }else {
        printf("Lista vuota\n");
    }

    return 0;
}

Lista ritaglia(char s[], char ch) {
    Lista lis = NULL, cur, new;
    char c;
    char str[N+1];
    int inside = -1;
    int first = 1;
    while((c=*s)!='\0') {
        //printf("%c %d\n", c, inside);
        if(c == ch) {
            str[inside] = '\0';
            inside = 0;
            if(!first) {
                new = (Lista)malloc(sizeof(Nodo));
                strcpy(new->value, str);
                new->next = NULL;
                if(lis == NULL) {
                    lis = new;
                    cur = lis;
                } else {
                    cur->next = new;
                    cur = cur->next;
                }
            } else {
                first = 0;
            }
        } else {
            str[inside++] = c;
        }
        s++;
    }
    return lis;
}

void stampa(Lista lis) {
    Lista cur;
    int fine=0;
    cur = lis;
    while(!fine) {
        if (cur == NULL) {
            //printf(" -> NULL\n");
            fine = 1;
        } else if (cur == lis) {
            printf("\"%s\"", cur->value);
        } else{
            printf(" -> \"%s\"", cur->value);
        }
        if(cur != NULL) {
            cur = cur->next;
        }
    }
}