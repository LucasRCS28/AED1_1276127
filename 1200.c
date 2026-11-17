/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Rodrigues Camargo Soares
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 21/08/2026
Objetivo    : Ajudar a Marcela no Binary Search
Dificuldade :  Medio-Dificil
Uso de IA   : precisei pois não sabia como eu terminava o arquivo tive que perguntar pro gemini como fazia o programa terminar
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct We {
    char p;
    struct We *E;
    struct We *D;
} Node;
Node* Cria(char Value) {
    Node *help = (Node*) malloc(sizeof(Node));
    help->p = Value;
    help->E = NULL;
    help->D = NULL;
    return help;
}
Node* Insere(Node *Root, char Value) {
    if (Root == NULL) {
        return Cria(Value);
    }
    if (Value < Root->p) {
        Root->E = Insere(Root->E, Value);
    } else if (Value > Root->p) {
        Root->D = Insere(Root->D, Value);
    }
    return Root;
}
int Procura(Node *Root, char Value) {
    if (Root == NULL) return 0;
    if (Root->p == Value) return 1;
    
    if (Value < Root->p) {
        return Procura(Root->E, Value);
    } else {
        return Procura(Root->D, Value);
    }
}
void Pre(Node *Root, int *primeiro) {
    if (Root != NULL) {
        if (*primeiro) {
            printf("%c", Root->p);
            *primeiro = 0;
        } else {
            printf(" %c", Root->p);
        }
        Pre(Root->E, primeiro);
        Pre(Root->D, primeiro);
    }
}
void In(Node *Root, int *primeiro) {
    if (Root != NULL) {
        In(Root->E, primeiro);
        if (*primeiro) {
            printf("%c", Root->p);
            *primeiro = 0;
        } else {
            printf(" %c", Root->p);
        }
        In(Root->D, primeiro);
    }
}
void Post(Node *Root, int *primeiro) {
    if (Root != NULL) {
        Post(Root->E, primeiro);
        Post(Root->D, primeiro);
        if (*primeiro) {
            printf("%c", Root->p);
            *primeiro = 0;
        } else {
            printf(" %c", Root->p);
        }
    }
}
void liberarArvore(Node *Root) {
    if (Root != NULL) {
        liberarArvore(Root->E);
        liberarArvore(Root->D);
        free(Root);
    }
}
int main() {
    Node *Raizona = NULL;
    char text[10], c;
    int primeiro;
    while (scanf("%s", text) != EOF) {
        if (strcmp(text, "I") == 0) {
            scanf(" %c", &c);
            Raizona = Insere(Raizona, c);
        } 
        else if (strcmp(text, "P") == 0) {
            scanf(" %c", &c);
            if (Procura(Raizona, c) == 1) {
                printf("%c existe\n", c);
            } else {
                printf("%c nao existe\n", c);
            }
        } 
        else if (strcmp(text, "INFIXA") == 0) {
            primeiro = 1;
            In(Raizona, &primeiro);
            printf("\n");
        } 
        else if (strcmp(text, "PREFIXA") == 0) {
            primeiro = 1;
            Pre(Raizona, &primeiro);
            printf("\n");
        } 
        else if (strcmp(text, "POSFIXA") == 0) {
            primeiro = 1;
            Post(Raizona, &primeiro);
            printf("\n");
        }
    }
    liberarArvore(Raizona);
    return 0;
}