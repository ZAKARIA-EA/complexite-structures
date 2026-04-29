#include <stdio.h>

#define n 3
#define m 3

int MiniMax(int tab[n][m]) {
    int i,j,max,minimax;

    for(i=0;i<n;i++) {
        max = tab[i][0];
        for(j=1;j<m;j++) {
            if(tab[i][j] > max)
                max = tab[i][j];
        }

        if(i==0) minimax = max;
        else if(max < minimax)
            minimax = max;
    }

    return minimax;
}

int main() {
    int t[3][3] = {{2,3,4},{5,6,7},{8,9,10}};
    printf("MiniMax = %d\n", MiniMax(t));
}
