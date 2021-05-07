#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20

int main()
{
    int zero, um, m[TAM][TAM];

    scanf("%d%d", &zero, &um);

    if(zero+um > TAM*TAM) return 0;

    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            m[i][j] = 2;
        }
    }

    srand(time(NULL));

    // UM
    for(int i=um; i>0; ){
        int x = rand()%TAM;
        int y = rand()%TAM;
        if(m[x][y] == 2){
            m[x][y] = 1;
            i--;
        }
    }

    // ZERO
    for(int i=zero; i>0; ){
        int x = rand()%TAM;
        int y = rand()%TAM;
        if(m[x][y] == 2){
            m[x][y] = 0;
            i--;
        }
    }

    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            printf("%d", m[i][j]);
        }
        printf("\n");
    }

  return 0;
}
