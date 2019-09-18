/*
    Jogo interativo Tetris implementado em linguagem C para uso no console
(terminal de comandos)

Autora: Amanda Furuta
Data 28/08/19
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Config das dimensões da matriz principal do jogo
#define COLUMNS 60
#define ROWS 20

//configuração das teclas
#define ESC 27
#define ARROWS 224 //teclado de setas
#define LEFT 75
#define RIGHT 77
#define TECLA_A 97
#define TECLA_D 100

//assinaturas
void init (char matrix[ROWS][COLUMNS]);
/*Inicializa a matriz principal com espaços vazios*/

void printMatrix (char matrix[ROWS][COLUMNS]);
/* Mostra o conteúdo da matriz principal na tela do pc*/