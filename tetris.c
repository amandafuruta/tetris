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
    printf("\t\t\t\t\t");
    //Linha de cima
    for(j=0; j<COLUMNS+2; j++){
        printf("*");
    }
    printf("\n");

    //Matriz do jogo
    for(i=0; i<ROWS; i++){        
        printf("\t\t\t\t\t*");
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }
        printf("*\n");
    }

    printf("\t\t\t\t\t");
    //Linha de baixo
    for(j=0; j<COLUMNS+2; j++){
        printf("*");
    }
    printf("\n");

} 

void drawBar (char matrix[ROWS][COLUMNS], Bloco barra, int simbolo){ //o simbolo pode ser o PIXEL ou EMPTY tbm
    switch (barra.orientacao){
            case ORIENTACAO_DOWN:
            case ORIENTACAO_UP:
                if(barra.i-3>=0) matrix[barra.i-4][barra.j]= simbolo;
                if(barra.i-3>=0) matrix[barra.i-3][barra.j]= simbolo;
                if(barra.i-2>=0) matrix[barra.i-2][barra.j]= simbolo;
                if(barra.i-1>=0) matrix[barra.i-1][barra.j]= simbolo;
                matrix[barra.i][barra.j]= simbolo;
                break;
            case ORIENTACAO_RIGHT:
            case ORIENTACAO_LEFT:
                matrix[barra.i][barra.j+2]= simbolo;
                matrix[barra.i][barra.j+1]= simbolo;
                matrix[barra.i][barra.j]= simbolo;
                matrix[barra.i][barra.j-1]= simbolo;
                matrix[barra.i][barra.j-2]= simbolo;
                break;
        }   
}

void initBar(Bloco *barra){
    barra->i =0;
    barra->j= COLUMNS/2;
    barra->orientacao = ORIENTACAO_LEFT;
    barra->width= 5;
    barra->height=1;

    #if DEBUG ==1
        printf("PosI:%d  PosJ: %d", barra->i, barra->j);
        system("pause");
        
    #endif
}

void rotate (Bloco *bloco){
     if(bloco->orientacao==ORIENTACAO_LEFT)
                    bloco->orientacao= ORIENTACAO_UP;
     else 
        bloco->orientacao++;
        //inversão da dimensao do tijolo
        int aux= bloco->width;
        bloco->width= bloco->height;
        bloco->height= aux;
        //resolvendo bug dos cantos
        if (bloco->j < (bloco->width/2))
            bloco->j= bloco->width/2;
        else if (bloco->j > COLUMNS - (bloco->width/2))
            bloco->j= COLUMNS - (bloco->width/2)-1;
}

int collisionBar(char matrix[ROWS][COLUMNS],Bloco barra, int collideSide, int side){
    int retorno=0;
     
     //colisão com base
        if((barra.i +1) >=ROWS)
        retorno=1;

    //colisao da base da barra com outras peças 
        if(matrix [barra.i+1 ][barra.j] != EMPTY)
        retorno = 1;
     
     //colisão com base horizontal
        int t2= barra.width/2;
        if(matrix[barra.i+1][barra.j+t2] != EMPTY)
        retorno =1;
        if(matrix[barra.i+1][barra.j- t2] != EMPTY)
        retorno=1;

    //colisão lateral horizontal
    if(collideSide==CHECK_SIDE && (barra.orientacao==ORIENTACAO_LEFT || barra.orientacao==ORIENTACAO_RIGHT) ){
        if(side==RIGHT && matrix[barra.i][barra.j+ t2+1] != EMPTY)
            retorno= 1;
        if(side==RIGHT && barra.j+ t2+1 >= COLUMNS)
            retorno =1;
        if(side==LEFT && matrix[barra.i][barra.j- t2-1] != EMPTY)
            retorno= 1;
        if(side==LEFT && barra.j- t2-1 <0)
            retorno =1;
    }

    //colisão lateral vertical
    if(collideSide ==CHECK_SIDE && (barra.orientacao==ORIENTACAO_UP || barra.orientacao==ORIENTACAO_DOWN)){
        int i;
        for(i=0; i<barra.height; i++){
            //verificando colisão lateral com restos de outras peças
            if(side==RIGHT && matrix[barra.i-i][barra.j+1] != EMPTY)
            retorno=1;
            if(side==LEFT && matrix[barra.i-i][barra.j-1]!= EMPTY)
            retorno=1;
        }
    }
    return retorno;
}