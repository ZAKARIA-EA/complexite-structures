#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int val;
    struct Element *suivant;
} LISTE;

int SuppressionValeurMin(LISTE **L)
{
    LISTE *ptr = *L, *pMin = NULL;
    int min;

    if (!ptr) return 0;

    if (!ptr->suivant)
    {
        free(ptr);
        *L = NULL;
        return 1;
    }

    min = ptr->val;

    while (ptr->suivant)
    {
        if (ptr->suivant->val < min)
        {
            min = ptr->suivant->val;
            pMin = ptr;
        }
        ptr = ptr->suivant;
    }

    if (!pMin)
    {
        ptr = *L;
        *L = (*L)->suivant;
        free(ptr);
    }
    else
    {
        ptr = pMin->suivant;
        pMin->suivant = ptr->suivant;
        free(ptr);
    }

    return 1;
}

