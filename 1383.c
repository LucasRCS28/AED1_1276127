/*Lucas Rodrigues Camargo Soares - 1383 - Codigo que checa se um soduku é valido ou não. 
 */
#include <stdio.h>
int main() {
    int k,TF = 1,tt = 0;
    scanf("%d", &k);
    int M[k][9][9];
    for (int i = 0; i < k; i++){
       for(int j = 0; j < 9; j++){
           for(int l = 0; l < 9; l++){
               scanf("%d", &M[i][j][l]);
           }
       }
    }
    for (int i = 0; i < k; i++){
        TF = 1;
        for(int j = 0; j < 9; j++){
            for(int l = 0; l < 9; l++){
                for(int m = 0; m < 9; m++){
                    if(M[i][j][l] == M[i][j][m] && l != m){
                        TF = 0;
                    }
                    if(M[i][j][l] == M[i][m][l] && j != m){
                        TF = 0;
                    }
                    if(M[i][j][l] == M[i][(j/3)*3 + m/3][(l/3)*3 + m%3] && (j != (j/3)*3 + m/3 || l != (l/3)*3 + m%3)){
                        TF = 0;
                    }
                }
            }
        }
        printf("Instancia %d\n", i+1);
        if(TF == 1){
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    return 0;
}