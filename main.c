#include <stdio.h>

int puissance(int a,int i)
{
    if(i==0)
        return 1;
    else
        return (a*puissance(a,i-1));
}

int expRapide(int a, int i)
{
    if (i==0)
        return 1;
    else if (i%2 == 0)
        return expRapide(expRapide(a,i/2),2);
    else
        return a*expRapide(expRapide(a,i/2),2);
}

int somme(int a, int n)
{
    if(n==0)
        return 1;
    else
        return (puissance(a,n)+somme(a,n-1));
}

int main()
{
    int a = 2, n = 5;

    printf("puissance = %d\n", puissance(a,n));
    printf("expRapide = %d\n", expRapide(a,n));
    printf("somme = %d\n", somme(a,n));

    return 0;
}
