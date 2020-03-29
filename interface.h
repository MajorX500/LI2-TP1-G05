/**
@file interface.h
Definição da interface.
*/

#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#define BUF_SIZE 1024

/**
\brief Interpretador de commandos
@param e Apontador para o estado
Esta função funciona como interpretador de comandos.
@return Um inteiro diferente de 1 no caso de erro.
*/
int CMD(STATE *);

/**
\brief Desenha
@param e Apontador para o estado
@param F Ficheiro
Esta função desenha o estado num ficheiro (stdout).
*/
void draw(STATE *, FILE *);

void draw_moves(STATE *, FILE *);

/**
\brief Guarda
@param e Apontador para o estado
@param F Ficheiro
Esta função guarda o estado atual num ficheiro.
*/
void save(STATE *, FILE *);

void read(STATE *, FILE *);

/**
\brief Prompt
@param e Apontador para o estado
Esta função faz print a informações úteis no ecran.
*/
void prompt(STATE *s);

#endif
