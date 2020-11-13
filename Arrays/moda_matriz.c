/*
 * Eduardo Freitas
 * 13/11/2020
 * 
 * Matriz 10x10 preenchida com valores pseudo aleatórios no
 * intervalo [0+y, 5+y] tal que cada linha nova: y = y+1 
 * 
 * Adicionado moda da matriz
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10 // Ordem da matriz quadrada

void modaMatriz(int m[TAM][TAM]){
    
    int n[TAM*TAM] = {}, index=0, moda=0, vezes=0;

    for(int i=0;i<TAM;i++)
        for(int j=0;j<TAM;j++) 
            n[index++] = m[i][j];
    
    for(int i=0; i<(TAM*TAM); i++){
        index=1;
        for(int j=i+1; j<(TAM*TAM); j++) 
            if(n[i]==n[j]) index++;
        if(index>vezes)
            vezes=index, moda=n[i];
    }

    printf("Moda eh: %i, Apareceu %i vezes\n", moda, vezes);
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

    // Mostra Moda
    modaMatriz(m);
    
    return 0;
}
