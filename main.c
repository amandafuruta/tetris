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
#define DEBUG 1

 /*Parte principal do progrma, responsavel por iniciar e
 chamar as funções auxiliares*/

int main(){
    char matrix[ROWS][COLUMNS];
    Bloco tijolo;
    int keypressed=0;
    //int posI, posJ;- substituido pela struct
    tijolo.i =0;
    tijolo.j= COLUMNS/2;
    tijolo.orientacao = ORIENTACAO_LEFT;
    tijolo.width= 1;
    tijolo.height=8;
    

    //posI= 0; //linha
    //posJ= COLUMNS/2;

    //inicializando a matriz
    init (matrix); 

    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system ("cls");

    //animação do jogo
    while ( keypressed != ESC) { //27 é o cod do esc- para sair do jogo
        gotoxy(0,0);

        //se valor 1- mostra na tela. se valor 0, não mostra
        #if DEBUG == 1
            printf("@ = (%d, %d)\n", tijolo.i, tijolo.j);
        #endif


        
        /*switch (tijolo.orientacao){
            case ORIENTACAO_UP:
                if(tijolo.i-3>=0) matrix[tijolo.i-3][tijolo.j]= PIXEL;
                if(tijolo.i-2>=0) matrix[tijolo.i-2][tijolo.j]= PIXEL;
                if(tijolo.i-1>=0) matrix[tijolo.i-1][tijolo.j]= PIXEL;
                matrix[tijolo.i][tijolo.j]= PIXEL;
                break;
            case ORIENTACAO_LEFT:
                matrix[tijolo.i][tijolo.j+2]= PIXEL;
                matrix[tijolo.i][tijolo.j+1]= PIXEL;
                matrix[tijolo.i][tijolo.j]= PIXEL;
                matrix[tijolo.i][tijolo.j-1]= PIXEL;
                break;
        }*/
        

        //mostra a matriz na tela

        
        drawBar (matrix, tijolo, PIXEL);
                
        
        printMatrix(matrix);

       
        drawBar (matrix, tijolo, EMPTY);
               

        /*switch (tijolo.orientacao){
            case ORIENTACAO_UP:
                if(tijolo.i-3>=0) matrix[tijolo.i-3][tijolo.j]= EMPTY;
                if(tijolo.i-2>=0) matrix[tijolo.i-2][tijolo.j]= EMPTY;
                if(tijolo.i-1>=0) matrix[tijolo.i-1][tijolo.j]= EMPTY;
                matrix[tijolo.i][tijolo.j]= EMPTY;
                break;
            case ORIENTACAO_LEFT:
                matrix[tijolo.i][tijolo.j+2]= EMPTY;
                matrix[tijolo.i][tijolo.j+1]= EMPTY;
                matrix[tijolo.i][tijolo.j]= EMPTY;
                matrix[tijolo.i][tijolo.j-1]= EMPTY;
                break;
        }*/



        if (tijolo.i<ROWS-1)tijolo.i++;

        


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
                if( tijolo.j-2>0) tijolo.j--; 
                    break; 
            case TECLA_d:
            case TECLA_D: // caso apertar 'd' vai para direita
            case RIGHT: //codigo de seta para direita
                if (tijolo.j+2< COLUMNS-1) tijolo.j++;
                    break; 
            case TECLA_ESPACO:
                if(tijolo.orientacao==ORIENTACAO_LEFT)
                    tijolo.orientacao= ORIENTACAO_UP;
                else 
                    tijolo.orientacao++;
        }

    } 

    system("pause");
    return 0;
}


