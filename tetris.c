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
        
        for (j=0; j<COLUMNS; j++){
            matrix[0][j]= '*';
            matrix[19][j]='*';
        } 
        for (i=0; i<ROWS; i++){
            matrix[i][0]= '*';
            matrix[i][59]='*';
        }
        for (i=1; i<ROWS-1; i++){
            for(j=1; j<COLUMNS-1; j++){
                matrix[i][j]= ' ';
            }
        }
}


/* Mostra o conteúdo da matriz principal na tela do pc*/
void printMatrix (char matrix[ROWS][COLUMNS]){
    int i , j;
    for (i=0; i<ROWS; i++){
        for (j=0; j<COLUMNS; j++){
            printf ("%c", matrix[i][j]);
        }
       printf ("\n"); //quebra linha
    }

}