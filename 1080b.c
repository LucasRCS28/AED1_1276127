/* Lucas Rodrigues Camargo Soares - 1080b - mesma coisa do codigo 1080 porem utilizando alocação dinamica alem de algumas outras pequenas mudanças para otimizar o codigo e deixa-lo mais limpo.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *N, maior,p;
    N = (int*) malloc(100 * sizeof(int));
    for(int i = 0; i < 100; i++){
        scanf("%d", &N[i]);
        if(i == 0){
            maior = N[i];
            p = i;
        }
        else{
            if(N[i] > maior){
                maior = N[i];
                p = i;
            }
        }
    }
    printf("%d\n %d\n", maior, p+1);
    free(N);
    return 0;
}