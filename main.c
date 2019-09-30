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
    int keypressed=0;
    

    posI= 0; //linha
    posJ= COLUMNS/2;

    //inicializando a matriz
    init (matrix); 

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system ("cls");

    //animação do jogo
    while ( keypressed != ESC) { //27 é o cod do esc- para sair do jogo
        gotoxy(0,0);
        
        matrix[posI][posJ]= '@';

        //mostra a matriz na tela
        printMatrix(matrix);

        matrix[posI][posJ]= ' ';
        if (posI<ROWS-1) posI++;



        //lendo teclas- kbhit -> da biblio conio.h
        keypressed=0; //para o bichinho não ficar indo para o lado infinitamente
        if(kbhit()){ //quando alguma tecla é apertada, o kbhit se torna verdadeiro 
            keypressed = getch(); //o keypressed vai receber qual tecla foi apertada
        }

        if (keypressed==ARROWS){ //224 é o codigo do teclado de setas e não alfabeto
            keypressed=getch();//vai ler qual seta foi acionado
        } 
        
        switch (keypressed){
            case TECLA_a: //outra forma de fazer (mas nao indicado)- (int)'a';
            case TECLA_A: //caso apertar o 'a' vai para esquerda tbm
            case LEFT://codigo da seta para esquerda 
                if( posJ>0) posJ--; 
                    break; 
            case TECLA_d:
            case TECLA_D: // caso apertar 'd' vai para direita
            case RIGHT: //codigo de seta para direita
                if (posJ< COLUMNS-1) posJ++;
                    break; 
        }

    } 

    system("pause");
    return 0;
}


