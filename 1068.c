/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Rodrigues Camargo Soares
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 1/09/2026
Objetivo    : Verificar o balanço de parênteses em uma expressão
Dificuldade : fácil pois pilha e legal de mexer
Uso de IA   : se voce tiver vendo isso saiba que eu to adicionando esses comentarios em todos os codigos so agora por isso que algumas coisas estão faltando e por conhecidencia eu utilizei AI para fazer esses comentarios, 30/09/2026.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    struct Pilha *V;
    char ty;
} Pilha;

int Add(Pilha *p, char elem) {
    Pilha *Add = (Pilha*) malloc(sizeof(Pilha));
    if (Add == NULL) {
        return 0;
    }
    Add->V = p->V;
    p->V = Add;
    Add->ty = elem;
    return 1;
}

int Remove(Pilha *p) {
    if (p->V == NULL) {
        return 0;
    }
    Pilha *aux = p->V;
    p->V = aux->V;
    free(aux);
    return 1;
}

void LimparPilha(Pilha *p) {
    while (p->V != NULL) {
        Remove(p);
    }
}

int main() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->V = NULL;
    char c;
    int erro = 0;

    while (scanf("%c", &c) == 1) {
        if (erro) {
            if (c == '\n') {
                printf("incorrect\n");
                LimparPilha(p);
                erro = 0;
            }
            continue;
        }

        if (c == '(' || c == '[' || c == '{') {
            Add(p, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            Pilha *aux = p->V;

            if (p->V == NULL) {
                erro = 1;
            }
            else if (c == ')' && aux->ty == '(') {
                Remove(p);
            }
            else if (c == ']' && aux->ty == '[') {
                Remove(p);
            }
            else if (c == '}' && aux->ty == '{') {
                Remove(p);
            }
            else {
                erro = 1;
            }
        }
        else if (c == '\n') {
            if (p->V == NULL) {
                printf("correct\n");
            } else {
                printf("incorrect\n");
            }
            LimparPilha(p);
            erro = 0;
        }
    }

    if (erro || p->V != NULL) {
        printf("incorrect\n");
    }

    LimparPilha(p);
    free(p);
    return 0;
}