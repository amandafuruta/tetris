/*
    Jogo interativo Tetris implementado em linguagem C para uso no console
(terminal de comandos)

Autora: Amanda Furuta
Data 28/08/19
*/

#include <stdio.h>
#include <stdlib.h>

//Config das dimensões da matriz principal do jogo
#define COLUMNS 60
#define ROWS 20

//assinaturas
void init (char matrix[ROWS][COLUMNS]);
/*Inicializa a matriz principal com espaços vazios*/

void printMatrix (char matrix[ROWS][COLUMNS]);
/* Mostra o conteúdo da matriz principal na tela do pc*/