#include <stdio.h>

int minIndex(int tab[], int n) {
    int i, index = 0;
    for(i=1;i<n;i++) {
        if(tab[i] < tab[index])
            index = i;
    }
    return index;
}

int main() {
    int t[] = {5,2,4,2,1,7,9,4,1,1};
    int n = 10;

    printf("Index min = %d\n", minIndex(t,n));
    return 0;
}
