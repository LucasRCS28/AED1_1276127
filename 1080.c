#include <stdio.h>
int main() {
    int N[100], maior, p;
    for (int i = 0; i < 100; i++) {
        scanf("%d", &N[i]);
    }
    maior = N[0];
    p = 0;
    for (int i = 1; i < 100; i++) {
        if (N[i] > maior) {
            maior = N[i];
            p = i;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", p+1);
    return 0;
}