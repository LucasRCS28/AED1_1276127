/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Rodrigues Camargo Soares
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 23/09/2026
Objetivo    : fazer o carteiro entregar as cartas na ordem correta, calculando a distância percorrida
Dificuldade : organizar as Variaveis
Uso de IA   : apenas para fazer o ultimo laço for porque tava com preguiça de fazer(utilizei o copilot), mas o resto foi feito por mim
-------------------------------------------------------------------------- */
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