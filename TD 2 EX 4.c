#include <stdio.h>

int rec1(int n) {
    if(n==0) return 1;
    return 2 * rec1(n-1);
}

int rec2(int n) {
    if(n==0) return 1;
    return rec2(n-1) + rec2(n-1);
}

int main() {
    printf("%d\n", rec1(5));
    printf("%d\n", rec2(5));
}
