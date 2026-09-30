/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Rodrigues Camargo Soares
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 30/09/2026
Objetivo    : Organizar os trilhos utilizando pilha
Dificuldade : Enteder a pergunta, tive que fazer 11 tentativas ate eu entender oque ele queria
Uso de IA   : usei para definir a strutura e as funções de pilha pois são triviais que por sinal o Copilot não soube fazer e eu tive que fazer tudo pq o copilot e ruim
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

typedef struct {
    Node *topo;
} Pilha;

void push(Pilha *p, int elem) {
    Node *novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) exit(1);
    novo->valor = elem;
    novo->prox = p->topo;
    p->topo = novo;
}

void pop(Pilha *p) {
    if (p->topo == NULL) return;
    Node *temp = p->topo;
    p->topo = temp->prox;
    free(temp);
}

void clear(Pilha *p) {
    while (p->topo != NULL) {
        pop(p);
    }
}

void organizarTrilhos(int *saida_desejada, int n) {
    Pilha p;
    p.topo = NULL;
    
    int vagao_atual = 1;
    int idx_saida = 0;

    while (vagao_atual <= n) {
        push(&p, vagao_atual);
        vagao_atual++;

        while (p.topo != NULL && p.topo->valor == saida_desejada[idx_saida]) {
            pop(&p);
            idx_saida++;
        }
    }

    if (p.topo == NULL) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    clear(&p);
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int *v = (int*) malloc(n * sizeof(int));
        while (1) {
            scanf("%d", &v[0]);
            if (v[0] == 0) {
                printf("\n");
                break;
            }
            for (int i = 1; i < n; i++) {
                scanf("%d", &v[i]);
            }
            organizarTrilhos(v, n);
        }
        free(v);
    }
    return 0;
}