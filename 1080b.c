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
#include <stdlib.h>

int main(){
    int *N, maior,p;
    N = (int*) malloc(100 * sizeof(int));
    for(int i = 0; i < 100; i++){
        scanf("%d", &N[i]);
        if(i == 0){
            maior = N[i];
            p = i;
        }
        else{
            if(N[i] > maior){
                maior = N[i];
                p = i;
            }
        }
    }
    printf("%d\n %d\n", maior, p+1);
    free(N);
    return 0;
}