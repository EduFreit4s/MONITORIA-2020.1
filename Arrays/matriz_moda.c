/*
 * Eduardo Freitas
 * 13/11/2020
 * 
 * Matriz 10x10 preenchida com valores pseudo aleatórios no
 * intervalo [0+y, 5+y] tal que cada linha nova: y = y+1 
 * 
 * Adicionado moda da matriz
 * 
 * CORREÇÃO /!\
 * 
 * Adicionado modas das linhas da matriz
 * Removido moda da matriz
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10 // Ordem da matriz quadrada

void modaLinha(int m[TAM][TAM]){
    
    int index=0, vezes=0, moda[TAM]={};
    
    for(int linha=0; linha<TAM; linha++){
        vezes=0;
        for(int i=0; i<TAM; i++){
            index=1;
            for(int j=i+1; j<TAM; j++) 
                if(m[linha][i]==m[linha][j]) index++;
            if(index>vezes)
                vezes=index, moda[linha]=m[linha][i];
        }
        printf("Moda[%i] eh: %i, apareceu vezes %i\n", linha, moda[linha], vezes);
    }

}

int main(){

    int m[TAM][TAM] = {}, x, y;

    srand(time(NULL));

    // Preenche
    for(y=0; y<TAM; y++)
        for(x=0; x<TAM; x++)
            m[y][x] = rand()%6 + y;

    // Mostra Matriz
    y=0;
    do{ 
        x=0;
        do{
            printf("%i\t", m[y][x]);
        }while(++x<TAM);
    } while (++y<TAM && printf("\n"));

    printf("\n\n");

    // Mostra moda de cada linha
    modaLinha(m);
    
    return 0;
}
