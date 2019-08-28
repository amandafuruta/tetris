/*
    Jogo interativo Tetris implementado em linguagem C para uso no console
(terminal de comandos)

para executar:
    > start .\programa.exe

Autora: Amanda Furuta
Data 28/08/19
*/

#include "tetris.h"

 /*Parte principal do progrma, responsavel por iniciar e
 chamar as funções auxiliares*/

int main(){
    char matrix[ROWS][COLUMNS];
    int posI, posJ;
    
    posI= ROWS/2;
    posJ= COLUMNS/2;

    init (matrix);  
    while (1) {
        system ("cls");
        matrix[posI][posJ]= '@';
        printMatrix(matrix);
        matrix[posI][posJ]= ' ';
        if (posJ<COLUMNS) posJ++;
        

    } 

    system("pause");
    return 0;
}


