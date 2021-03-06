/**
@file interface.h
Definição da interface.
*/

#ifndef __INTERFACE_H__
#define __INTERFACE_H__

/*! \def BUF_SIZE
    \brief Tamanho do buf de memoria
*/
#define BUF_SIZE 1024

/**
\brief Interpretador de commandos
Esta função funciona como interpretador de comandos.
@param *e Apontador para o estado
@return Um inteiro diferente de 1 no caso de erro.
*/
int CMD(STATE *e);

/**
\brief Desenha
Esta função desenha o estado num ficheiro (stdout).
@param e Apontador para o estado
@param f Ficheiro
*/
void draw(STATE *e, FILE *f);

/**
\brief Desenha Movimentos
Esta função desenha o array de jogadas.
@param e Apontador para o estado
@param f Ficheiro
*/
void draw_moves(STATE *e, FILE *f);

/**
\brief Guarda
Esta função guarda o estado atual num ficheiro.
@param e Apontador para o estado
@param f Ficheiro
*/
void save(STATE *e, char *f);

/**
\brief Ler
Esta função lê o estado atual de um ficheiro.
@param e Apontador para o estado
@param f Ficheiro
*/
void read(STATE *e, char *f);

/**
\brief Prompt
Esta função faz print a informações úteis no ecran.
@param e Apontador para o estado
*/
void prompt(STATE *e);

/**
\brief Rollback
Esta função faz o rollback do estado e as jogadas até à jogada pretendida pelo jogador com o command `pos _`.
@param e Apontador para o estado
@param m Número da jogada
*/
void rollback(STATE *e,int m);

#endif
