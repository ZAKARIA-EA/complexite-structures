#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int val;
    struct Element *suivant;
} LISTE;

int InsererElementEnTete(LISTE **L, int valeur)
{
    LISTE *element = (LISTE*) malloc(sizeof(LISTE));
    if (!element) return 0;

    element->val = valeur;
    element->suivant = *L;
    *L = element;
    return 1;
}

void AfficheListe(LISTE *L)
{
    while(L)
    {
        printf("%d -> ", L->val);
        L = L->suivant;
    }
    printf("NULL\n");
}

int main()
{
    LISTE *L = NULL;
    int i;

    for(i=0;i<5;i++)
        InsererElementEnTete(&L, rand()%100);

    AfficheListe(L);
    return 0;
}
