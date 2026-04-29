#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TMAX 20

typedef struct {
    int abs;
    int ord;
} Point;

/* Saisir un point */
Point SaisirPoint() {
    Point p;
    printf("Donner les coordonnees du point : ");
    scanf("%d %d", &p.abs, &p.ord);
    return p;
}

/* Afficher un point */
void AfficherPoint(Point p) {
    printf("(%d,%d)\n", p.abs, p.ord);
}

/* Distance */
float DistTransVal(Point p) {
    return sqrt(p.abs * p.abs + p.ord * p.ord);
}

/* Tri */
void tritab(Point t[], int taille) {
    int i, j;
    Point aux;

    for(i=0; i<taille-1; i++) {
        for(j=i+1; j<taille; j++) {
            if (DistTransVal(t[i]) > DistTransVal(t[j])) {
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
}

int main() {
    Point a;
    int i, taille;

    a = SaisirPoint();
    AfficherPoint(a);

    Point TStat[TMAX], *TDyn = NULL;

    printf("Donner la taille (<%d) du tableau: ", TMAX);
    scanf("%d", &taille);

    TDyn = (Point*) malloc(taille * sizeof(Point));

    srand(time(NULL));

    /* Remplissage */
    for(i=0; i<taille; i++) {
        TStat[i].abs = rand() % 100;
        TStat[i].ord = rand() % 100;

        TDyn[i].abs = rand() % 100;
        TDyn[i].ord = rand() % 100;
    }

    printf("\nTableau Statique:\n");
    for(i=0; i<taille; i++)
        AfficherPoint(TStat[i]);

    printf("\nTableau Dynamique:\n");
    for(i=0; i<taille; i++)
        AfficherPoint(TDyn[i]);

    /* Tri */
    tritab(TDyn, taille);

    printf("\nApres tri:\n");
    for(i=0; i<taille; i++)
        AfficherPoint(TDyn[i]);

    free(TDyn);
    return 0;
}
