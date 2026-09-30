/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Rodrigues Camargo Soares
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1180
Data        : 21/08/2026
Objetivo    : Encontrar o maior valor e sua posição em um vetor
Dificuldade : fácil
Uso de IA   : nop
-------------------------------------------------------------------------- */
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