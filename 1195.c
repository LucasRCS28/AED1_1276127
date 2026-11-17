/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Rodrigues Camargo Soares
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 30/10/2026
Objetivo    : Dar o valor do pre, in e post da tree montada
Dificuldade : Medio
Uso de IA   : Nem foi Necessario checagem de erros so rodou de boa msm
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Value;
    struct Node *D; // Direita
    struct Node *E; // Esquerda
    struct Node *P; // Pai
} Node;

Node* Insere(Node *Root, int val) {
    Node *Aux = (Node*) malloc(sizeof(Node));
    Aux->Value = val;
    Aux->E = NULL;
    Aux->D = NULL;
    Aux->P = NULL;
    if (Root == NULL) {
        return Aux;
    }
    Node *atual = Root;
    Node *pai = NULL;
    while (atual != NULL) {
        pai = atual;
        if (val < atual->Value) {
            atual = atual->E;
        } else {
            atual = atual->D;
        }
    }
    Aux->P = pai;
    if (val < pai->Value) {
        pai->E = Aux;
    } else {
        pai->D = Aux;
    }
    return Root;
}
void Pre(Node *Root) {
    if (Root != NULL) {
        printf(" %d", Root->Value);
        Pre(Root->E);
        Pre(Root->D);
    }
}
void In(Node *Root) {
    if (Root != NULL) {
        In(Root->E);
        printf(" %d", Root->Value);
        In(Root->D);
    }
}
void Post(Node *Root) {
    if (Root != NULL) {
        Post(Root->E);
        Post(Root->D);
        printf(" %d", Root->Value);
    }
}
void Empty(Node *Root) {
    if (Root != NULL) {
        Empty(Root->E);
        Empty(Root->D);
        free(Root);
    }
}
int main() {
    int Cases, N;
    if (scanf("%d", &Cases) != 1) return 0;
    for (int i = 0; i < Cases; i++) {
        scanf("%d", &N);
        Node *Root = NULL;
        for (int j = 0; j < N; j++) {
            int val;
            scanf("%d", &val);
            Root = Insere(Root, val);
        }
        printf("Case %d:\n", i + 1);
        printf("Pre.:");
        Pre(Root);
        printf("\n");
        printf("In..:");
        In(Root);
        printf("\n");
        printf("Post:");
        Post(Root);
        printf("\n\n");
        Empty(Root);
    }
    return 0;
}