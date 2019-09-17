/*
    Jogo interativo Tetris implementado em linguagem C para uso no console
(terminal de comandos)

para executar:
    > start .\programa.exe

Autora: Amanda Furuta
Data 28/08/19
*/

#include "tetris.h"


/*Inicializa a matriz principal com espaços vazios*/
void init (char matrix[ROWS][COLUMNS]){
    int i, j;
        for (i=0; i<ROWS; i++){
            for (j=0; j<COLUMNS; j++){
                matrix[i][j]= ' ';
            }
        }
        
}


/* Mostra o conteúdo da matriz principal na tela do pc*/
void printMatrix (char matrix[ROWS][COLUMNS]){
    int i , j;
    printf("\t\t\t");
    //Linha de cima
    for(j=0; j<COLUMNS+2; j++){
        printf("*");
    }
    printf("\n");

    //Matriz do jogo
    for(i=0; i<ROWS; i++){        
        printf("\t\t\t*");
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }
        printf("*\n");
    }

    printf("\t\t\t");
    //Linha de baixo
    for(j=0; j<COLUMNS+2; j++){
        printf("*");
    }
    printf("\n");

}