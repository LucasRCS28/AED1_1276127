/* Lucas Rodrigues Camargo Soares - 1383b - mesma coisa do codigo 1383 porem utilizando alocação dinamica alem de algumas outras pequenas mudanças para otimizar o codigo e deixa-lo mais limpo.
*/
#include <stdio.h>
#include <stdlib.h>

int Check(int **Sodoku, int c, int d){
    int val = Sodoku[c][d];
    
    if(val < 1 || val > 9){
        return 0;
    }
    
    int sc = c - (c % 3);
    int sd = d - (d % 3);
    
    for(int i = 0; i < 9; i++){
        if(Sodoku[c][i] == val && i != d){
            return 0;
        }
        if(Sodoku[i][d] == val && i != c){
            return 0;
        }
    }
    
    for(int i = sc; i < sc + 3; i++){
        for(int j = sd; j < sd + 3; j++){
            if(Sodoku[i][j] == val && i != c && j != d){
                return 0;
            }
        }
    }
    
    if(c < 8 || d < 8){
        if(d < 8){
            return Check(Sodoku, c, d + 1);
        }
        else{
            return Check(Sodoku, c + 1, 0);
        }
    }
    
    return 1;
}

int main() {
    int k;
    if(scanf("%d", &k) != 1) return 1;
    
    int ***M = (int***) malloc(k * sizeof(int**));
    for (int i = 0; i < k; i++){
        M[i] = (int**) malloc(9 * sizeof(int*));
        for(int j = 0; j < 9; j++){
            M[i][j] = (int*) malloc(9 * sizeof(int));
            for(int l = 0; l < 9; l++){
                scanf("%d", &M[i][j][l]);
            }
        }
    }
    
    for(int i = 0; i < k; i++){
        if(Check(M[i], 0, 0)){
            printf("Instancia %d\nSIM\n\n", i+1);
        }
        else{
            printf("Instancia %d\nNAO\n\n", i+1);
        }
    }
    
    for (int i = 0; i < k; i++){
        for(int j = 0; j < 9; j++){
            free(M[i][j]);
        }
        free(M[i]);
    }
    free(M);
    
    return 0;
}