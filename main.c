
#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int val;
    struct Element *suivant;
} LISTE;

void InsererFin(LISTE **L, int val)
{
    LISTE *n = malloc(sizeof(LISTE));
    n->val = val;
    n->suivant = NULL;

    if(!*L) { *L = n; return; }

    LISTE *tmp = *L;
    while(tmp->suivant) tmp = tmp->suivant;
    tmp->suivant = n;
}

LISTE* Fusion(LISTE *L1, LISTE *L2)
{
    LISTE *res = NULL;

    while(L1 && L2)
    {
        InsererFin(&res, L1->val);
        InsererFin(&res, L2->val);
        L1 = L1->suivant;
        L2 = L2->suivant;
    }

    while(L1){ InsererFin(&res,L1->val); L1=L1->suivant; }
    while(L2){ InsererFin(&res,L2->val); L2=L2->suivant; }

    return res;
}
