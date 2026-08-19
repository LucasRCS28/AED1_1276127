/*Lucas Rodrigues Camargo Soares - 1180 - pegar o menor valor e sua posição em um vetor de N elementos.
*/
#include <stdio.h>

int main() {
    int N, menor, posicaomenor;
    scanf("%d", &N);
    int X[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    for (int i = 0; i < N; i++)
    {
        if (i == 0) {
            menor = X[i];
            posicaomenor = i;
        } else if (X[i] < menor) {
            menor = X[i];
            posicaomenor = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicaomenor);
    return 0;
}