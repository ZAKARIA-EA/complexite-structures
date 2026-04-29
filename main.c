#include <stdio.h>

typedef struct {
    int hh;
    int mm;
    int ss;
} Heure;

/* Heure → secondes */
int HeureEnSecondes(Heure h) {
    return h.hh*3600 + h.mm*60 + h.ss;
}

/* secondes → Heure */
Heure SecondesEnHeure(int sec) {
    Heure h;
    h.hh = sec/3600;
    sec %= 3600;
    h.mm = sec/60;
    h.ss = sec%60;
    return h;
}

/* Addition */
Heure AddHeures(Heure h1, Heure h2) {
    return SecondesEnHeure(
        HeureEnSecondes(h1) + HeureEnSecondes(h2)
    );
}

int main() {
    Heure h1 = {1, 20, 30};
    Heure h2 = {2, 10, 40};

    Heure res = AddHeures(h1, h2);

    printf("Resultat: %dh %dm %ds\n", res.hh, res.mm, res.ss);

    return 0;
}
