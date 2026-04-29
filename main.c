#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int val;
    struct Element *suivant;
} LISTE;

void DestructionListe(LISTE **L)
{
    LISTE *tmp;
    while(*L)
    {
        tmp = *L;
        *L = (*L)->suivant;
        free(tmp);
    }
}
