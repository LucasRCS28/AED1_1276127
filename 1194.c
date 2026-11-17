/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Rodrigues Camargo Soares
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 22/10/2026
Objetivo    : Dar o Valor do do Post de acordo com o valor do pre-order e in-order
Dificuldade : Dificil
Uso de IA   : apenas para achar os erros criticos quando eu tinha terminado o codigo e não sabia porque não tava rodando
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char valor;
    struct Node* esq;
    struct Node* dir;
} Node;

Node *CriaNode(char valor){
    Node *Helper = (Node*)malloc(sizeof(Node));
    Helper->valor = valor;
    Helper->dir = NULL;
    Helper->esq = NULL;
    return Helper;
}

int Buscador(char *in, int c, int f, char valor){
    for (int i = c; i <= f; i++) {
        if (in[i] == valor) return i;
    }
    return -1;
}

Node *ReConstr(char *in, char *pre, int in_c, int in_f, int *pre_index){
    if (in_c > in_f) return NULL;

    char val = pre[*pre_index];
    (*pre_index)++;

    Node *Raiz = CriaNode(val);

    if (in_c == in_f) return Raiz;

    int in_index = Buscador(in, in_c, in_f, val);

    Raiz->esq = ReConstr(in, pre, in_c, in_index - 1, pre_index);
    Raiz->dir = ReConstr(in, pre, in_index + 1, in_f, pre_index);

    return Raiz;
}

void PrintPost(Node *Raiz){
    if (Raiz == NULL) return; 
    PrintPost(Raiz->esq);
    PrintPost(Raiz->dir);
    printf("%c", Raiz->valor);
    free(Raiz);
}

int main(){
    int N, n;
    
    if (scanf("%d", &N) != 1) return 1;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        char *pre = (char*)malloc((n + 1) * sizeof(char));
        char *in = (char*)malloc((n + 1) * sizeof(char));
        
        scanf("%s", pre);
        scanf("%s", in);
        
        int index = 0; 
        PrintPost(ReConstr(in, pre, 0, n - 1, &index));
        printf("\n");
        
        free(in);
        free(pre);
    }
    
    return 0;
}