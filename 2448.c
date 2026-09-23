//Lucas Rodrigues Camargo Soares - 2448 - Correio
#include <stdio.h>
#include <stdlib.h>
int BinarySort(int *array, int size, int value){
    int inicio = 0;
    int fim = size - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (array[meio] == value) {
            return meio;
        } else if (array[meio] < value) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}
int main() {
    int N, M, momento = 0;
    long long int andado = 0;
    scanf("%d %d", &N, &M);
    int casas[N], Order[M];
    for (int i = 0; i < N; i++) {
        scanf("%d", &casas[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &Order[i]);
    }
    for (int i = 0; i < M; i++) {
        int result = BinarySort(casas, N, Order[i]);
        if (momento > result){
            andado += (momento - result);
        } else {
            andado += (result - momento);
        }
        momento = result;
    }
    printf("%lld\n", andado);
    return 0;
}