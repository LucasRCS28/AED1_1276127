/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Rodrigues Camargo Soares
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 30/09/2026
Objetivo    : expressão infixa para poxfixa
Dificuldade : achei que era pra resolver com pilha, mas depois que vi que me confundi e era pra resolver com lista fazendo o exercicio ficar bem mais facil.
Uso de IA   : nenhum depois da raiva que passei com o copilot.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    char valor;
    struct Lista *prox;
} Lista;

void push(Lista *cabeca, char valor) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = cabeca->prox;
    cabeca->prox = novo;
}

void pop(Lista *cabeca) {
    Lista *temp = cabeca;
    if (cabeca->prox == NULL) {
        return;
    }
    while (temp->prox != NULL && temp->prox->prox != NULL) {
        temp = temp->prox;
    }
    if (temp->prox != NULL) {
        Lista *freeD = temp->prox;
        temp->prox = temp->prox->prox;
        printf("%c", freeD->valor);
        free(freeD);
    }
}
int prioridade(char operador) {
    if (operador == '+' || operador == '-') {
        return 0;
    } else if (operador == '*' || operador == '/') {
        return 1;
    } else if (operador == '^') {
        return 2;
    } else {
        printf("Operador inválido: %c\n", operador);
        exit(1);
    }
}
void ResolvedorReverbo(Lista *cabeca, char expressao[]) {
    char caixa[3] = {'N','N','N'}; // Array para armazenar operadores temporariamente N significa que não tem operador dessa prioridade
    for (int i = 0; expressao[i] != '\0'; i++) {
        char atual = expressao[i];
        if (atual == '+' || atual == '-' || atual == '*' || atual == '/' || atual == '^') {
            int p = prioridade(atual);
            for (int j = 2; j > p; j--) {
                if (caixa[j] != 'N') {
                    push(cabeca, caixa[j]);
                    caixa[j] = 'N';
                }
            }
            if (caixa[p] != 'N') {
                push(cabeca, caixa[p]);
                caixa[p] = atual;
            }else {
                caixa[p] = atual;
            }
        } else if(atual == '(') {
            //parte recursiva
            int j = i + 1;
            int contador = 1;
            while (contador > 0) {
                if (expressao[j] == '(') {
                    contador++;
                } else if (expressao[j] == ')') {
                    contador--;
                }
                j++;
            }
            char subexpressao[100];
            int k = 0;
            for (int l = i + 1; l < j - 1; l++) {
                subexpressao[k++] = expressao[l];
            }
            subexpressao[k] = '\0';
            ResolvedorReverbo(cabeca, subexpressao);
            i = j - 1; // Atualiza o índice para pular a subexpressão
        } else {
            push(cabeca, atual);
        }
    }
    for (int j = 2; j >= 0; j--) {
        if (caixa[j] != 'N') {
            push(cabeca, caixa[j]);
        }
    }
}

int main() {
    Lista *cabeca = (Lista *)malloc(sizeof(Lista));
    cabeca->prox = NULL;
    int TestCases;
    if (scanf("%d", &TestCases) != 1) return 0;
    char expressao[TestCases][100];
    for (int i = 0; i < TestCases; i++) {
        scanf("%s", expressao[i]);
    }
    for (int i = 0; i < TestCases; i++) {
        ResolvedorReverbo(cabeca, expressao[i]);
        while (cabeca->prox != NULL) {
            pop(cabeca);
        }
        printf("\n");
    }
    free(cabeca);
    return 0;
}