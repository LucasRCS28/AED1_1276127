/*Lucas Rodrigues Camargo Soares - 1383 - Codigo que checa se um soduku é valido ou não. 
de boas esse codigo foi feito apos eu ja ter feito o 1383 do beecrowd então esse e uma Otimização 
*/
#include <stdio.h>
int Check(int Sodoku[9][9], int c, int d){
    int sc = c - (c % 3);
    int sd = d - (d % 3);
    for(int i = 0; i < 9; i++){
        if(Sodoku[c][i] == Sodoku[c][d] && i != d){
            return 0;
        }
        if(Sodoku[i][d] == Sodoku[c][d] && i != c){
            return 0;
        }
    }
    for(int i = sc; i < sc + 3; i++){
        for(int j = sd; j < sd + 3; j++){
            if(Sodoku[i][j] == Sodoku[c][d] && i != c && j != d){
                return 0;
            }
        }
    }
    if(Sodoku[c][d] < 1 || Sodoku[c][d] > 9){
        return 0;
    }
    if(c<8 || d<8){
        if(d<8){
            return Check(Sodoku, c, d+1);
        }
        else{
            return Check(Sodoku, c+1, 0);
        }
    }
    return 1;
}
int main() {
    int k;
    scanf("%d", &k);
    int M[k][9][9];
    for (int i = 0; i < k; i++){
       for(int j = 0; j < 9; j++){
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
    return 0;
}