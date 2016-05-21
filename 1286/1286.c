//Adaptação do problema da mochila

#include <stdio.h>

int F[21][31], qtdPizzas[31], tempoPizzas[21];

int MAX(int a, int b) {
    return (a > b) ? a : b;
}

int tempoPedidos(int i, int j){
    int retorno;
    
    if(F[i][j] < 0){
        if(j < qtdPizzas[i])
            retorno = tempoPedidos(i-1, j);
        else
            retorno = MAX(tempoPedidos(i-1, j), tempoPizzas[i] + tempoPedidos(i-1, j - qtdPizzas[i]));
        
        F[i][j] = retorno;
    }
    
    return F[i][j];
}

int main(){
    int n, p, i, j;
    
    while(1){
        scanf("%d", &n);
        
        if(n == 0)
            return 0;
            
        scanf("%d", &p);
        
        for(i = 1; i <= n; i++){
            scanf("%d %d", &tempoPizzas[i], &qtdPizzas[i]);
        }
        
        qtdPizzas[0] = 0;
        tempoPizzas[0] = 0;
        
        for(i = 0; i < 21; i++){
            for(j = 0; j < 31; j++){
                if(i == 0 || j == 0)
                    F[i][j] = 0;
                else
                    F[i][j] = -1;
            }
        }
        
        
        printf("%d min.\n", tempoPedidos(n, p));
    }
    
    return 0;
}