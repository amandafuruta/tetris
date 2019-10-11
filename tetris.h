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
#define ROWS 25

//configuração das teclas
#define ESC 27
#define ARROWS 224 //teclado de setas
#define LEFT 75
#define RIGHT 77
#define TECLA_a 97
#define TECLA_d 100
#define TECLA_A 65
#define TECLA_D 68
#define TECLA_ESPACO 32
//ORIENTAÇÃO DAS PEÇAS
#define ORIENTACAO_UP 1
#define ORIENTACAO_RIGHT 2
#define ORIENTACAO_DOWN 3
#define ORIENTACAO_LEFT 4
//TIPOS DE PEÇAS
#define TIPO_L 1
#define TIPO_L_R 2 //L REVERSO
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5
#define TIPO_O 6
#define TIPO_I 7

//config de layout
#define PIXEL 219
#define EMPTY 32

//Estrutura padrão de componentes
typedef struct{
    int i, j;
    int orientacao;
    int tipo;
    int width;
    int height;
}Bloco;

//assinaturas
void init (char matrix[ROWS][COLUMNS]);
/*Inicializa a matriz principal com espaços vazios*/

void printMatrix (char matrix[ROWS][COLUMNS]);
/* Mostra o conteúdo da matriz principal na tela do pc*/

//desenha bara usando simbolo ASCII passado por parametro
void drawBar (char matrix[ROWS][COLUMNS],Bloco barra, int simbolo);