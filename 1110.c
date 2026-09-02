/* Lucas Rodrigues Camargo Soares - 1110 - Jogando Cartas Fora */
#include <stdio.h>
#include <stdlib.h>

typedef struct Deck {
    int valor;
    struct Deck *prox;
} Deck;

typedef struct Fila {
    Deck *inicio;
    Deck *fim;
} Fila;

void Inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void Push(Fila *f, int valor) {
    Deck *novo = (Deck*) malloc(sizeof(Deck));
    if (novo == NULL) exit(1);
    
    novo->valor = valor;
    novo->prox = NULL;
    
    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int Pop(Fila *f) {
    if (f->inicio == NULL) return -1;
    
    Deck *aux = f->inicio;
    int valor = aux->valor;
    
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    free(aux);
    return valor;
}

void LimparFila(Fila *f) {
    while (f->inicio != NULL) {
        Pop(f);
    }
}

int Tamanho(Fila *f) {
    int count = 0;
    Deck *atual = f->inicio;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

int main() {
    int n;
    Fila f;
    
    while (scanf("%d", &n) == 1 && n != 0) {
        Inicializar(&f);
        
        for (int i = 1; i <= n; i++) {
            Push(&f, i);
        }
        
        printf("Discarded cards:");
        
        int primeiroDescarte = 1;
        while (Tamanho(&f) > 1) {
            int descartada = Pop(&f);
            if (primeiroDescarte) {
                printf(" %d", descartada);
                primeiroDescarte = 0;
            } else {
                printf(", %d", descartada);
            }
            
            int movida = Pop(&f);
            Push(&f, movida);
        }
        
        printf("\nRemaining card: %d\n", Pop(&f));
    }
    
    return 0;
}