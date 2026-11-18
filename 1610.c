/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Lucas Rodrigues Camargo Soares
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 17/11/2026
Objetivo    : ajudar ao dudu a finalizar o trabalho checando se ele é possivel
Dificuldade :  Dificil
Uso de IA   : essa eu precisei me enbabanei todo tive que faltar as aulas por atestado e não sabia muito bem como mecher com grafos eu utilizei para entender a teoria
-------------------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>
typedef struct base {
    int n;
    int dp;
    struct expansion *req;
} Doc;
typedef struct expansion {
    struct expansion *next;
    Doc *Pendencias;
} requisitos;
requisitos *CriarCadeia(requisitos *list, Doc *Base) {
    requisitos *helper = (requisitos*) malloc(sizeof(requisitos));
    helper->next = list;
    helper->Pendencias = Base;
    return helper;
}
int main() {
    int T, N, M, A, B;
    scanf(" %d", &T);
    for (int i = 1; i <= T; i++) {
        scanf(" %d %d", &N, &M);
        int Fila[N + 1], inicio = 0, fim = 0, con = 0;
        Doc DT[N];
        for (int j = 0; j < N; j++) {
            DT[j].n = j + 1;
            DT[j].req = NULL;
            DT[j].dp = 0;
        }
        for (int j = 0; j < M; j++) {
            scanf(" %d %d", &A, &B);
            DT[B - 1].req = CriarCadeia(DT[B - 1].req, &DT[A - 1]);
            DT[A - 1].dp++;
        }
        for (int j = 0; j < N; j++) {
            if (DT[j].dp == 0) {
                Fila[fim++] = j;
            }
        }
        while (inicio < fim) {
            int atual = Fila[inicio++];
            con++;
            requisitos *aux = DT[atual].req;
            while (aux != NULL) {
                aux->Pendencias->dp--;
                if (aux->Pendencias->dp == 0) {
                    Fila[fim++] = aux->Pendencias->n - 1;
                }
                aux = aux->next;
            }
        }
        if (con < N) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        for (int j = 0; j < N; j++) {
            requisitos *aux = DT[j].req;
            while (aux != NULL) {
                requisitos *temp = aux->next;
                free(aux);
                aux = temp;
            }
        }
    }
    return 0;
}