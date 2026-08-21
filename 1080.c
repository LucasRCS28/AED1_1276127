/*Lucas Rodrigues Camargo Soares - 1080 - pegar o maior valor e sua posição em um vetor de 100 elementos.
errei uma vez pos dei a posição do indice da forma que o computador ve e nao que um humano ve*/
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