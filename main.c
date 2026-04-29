#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int val;
    struct Element *suivant;
} LISTE;

int RechercherValeur(LISTE *L, int valeur)
{
    while(L)
    {
        if(L->val == valeur) return 1;
        L = L->suivant;
    }
    return 0;
}

int main()
{
    LISTE a = {3,NULL};
    LISTE b = {5,&a};
    LISTE c = {7,&b};

    printf("%d\n", RechercherValeur(&c,5)); // 1
    printf("%d\n", RechercherValeur(&c,10)); // 0

    return 0;
}
