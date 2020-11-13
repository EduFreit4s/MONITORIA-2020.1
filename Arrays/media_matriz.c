/*
 * Eduardo Freitas
 * 13/11/2020
 * 
 * Matriz 10x10 preenchida com valores pseudo aleatórios no
 * intervalo [0+y, 5+y] tal que cada linha nova: y = y+1 
 * 
 * Adicionado média de cada linha e depois plotar na tela
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10 // Ordem da matriz quadrada

void mediaLinha(int med[TAM][TAM]){
    int soma;
    for(int i=0; i<TAM; i++){
        soma=0;
        for(int j=0; j<TAM; j++) soma += med[i][j];
        printf("Media da linha [%i]: %.2lf\n", i, (double)soma/TAM);
    }
}

int main(){

    int m[TAM][TAM] = {}, x, y;

    srand(time(NULL));

    // Preenche
    for(y=0; y<TAM; y++)
        for(x=0; x<TAM; x++)
            m[y][x] = rand()%6 + y;

    // Mostra
    y=0;
    do{ 
        x=0;
        do{
            printf("%i\t", m[y][x]);
        }while(++x<TAM);
    } while (++y<TAM && printf("\n"));

    printf("\n\n");

    // Mostra média
    mediaLinha(m);
    
    return 0;
}
