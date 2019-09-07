/*
    Jogo interativo Tetris implementado em linguagem C para uso no console
(terminal de comandos)

para executar:
    > start .\programa.exe

Autora: Amanda Furuta
Data 28/08/19
*/

#include "tetris.h"
#include "display.h"

 /*Parte principal do progrma, responsavel por iniciar e
 chamar as funções auxiliares*/

int main(){
    char matrix[ROWS][COLUMNS];
    int posI, posJ;
    

    posI= 1; //linha
    posJ= COLUMNS/2;

    //inicializando a atriz
    init (matrix); 

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system ("cls");


    while (1) {
        gotoxy(0,0);
        
        matrix[posI][posJ]= '@';
        printMatrix(matrix);
        matrix[posI][posJ]= ' ';
        if (posI<ROWS-2) posI++;
        

    } 

    system("pause");
    return 0;
}


