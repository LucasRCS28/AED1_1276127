/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Rodrigues Camargo Soares
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1180
Data        : 21/08/2026
Objetivo    : Encontrar o menor valor e sua posição em um vetor
Dificuldade : fácil
Uso de IA   : nop
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>

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