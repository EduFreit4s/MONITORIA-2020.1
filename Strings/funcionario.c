#include <stdio.h>
#include <stdlib.h>
#define TAM 10      // QUANTIDADE DE LEITURAS
#define FLOW 10     // TAMANHO DO STRING
#define GATILHO 18  // PLOTAR MATRICULAS COM IDADE SUPERIOR 

// COLEÇAO DE MATRICULAS
struct{
    char matricula[FLOW+1]; // TAMANHO DA STRING + 1 --> \0
}Funcionarios[TAM];

// RECORTA UM TRECHO DA STRING
// ARGUMENTOS: 
// ORIGEM DA STRING, DESTINO DA STRING
// LETRAS - QUANTIDADE DE LETRAS A SER RECORTADA
// INICIO - COMEÇAR RECORTAR A PARTIR DA POSIÇÃO
void charRecorte(char *origem, char *destrino, int letras, int inicio){
    for(int i=inicio; i<(letras+inicio); i++) 
        destrino[i-inicio] = origem[i];
}

// CONVERTE UMA STRING PARA INTEIRO
int char2int(char *idade){
    return atoi(idade); 
}

int main(void){

    struct Funcionarios;
    char idade[2];
    
    // LEITURA DOS DADOS
    for(int i=0; i<TAM;i++) 
        scanf("%s", Funcionarios[i].matricula);

    // APRESENTAÇÃO
    for(int i=0; i<TAM;i++){
        charRecorte(Funcionarios[i].matricula, idade, 2, 8);
        if(char2int(idade)>18) printf("Matricula: %s\n", Funcionarios[i].matricula);
    }

    return 0;
}
