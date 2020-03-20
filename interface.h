/**
@file interface.h
Definição da interface.
*/

#ifndef __INTERFACE_H__
#define __INTERFACE_H__

/**
\brief Desenha
@param e Apontador para o estado
@param F Ficheiro
Esta função desenha o estado num ficheiro (stdout).
*/
void draw(STATE *, FILE *);

/**
\brief Guarda
@param e Apontador para o estado
@param F Ficheiro
Esta função guarda o estado atual num ficheiro.
*/
void save(STATE *, FILE *);

/**
\brief Movimento
@param e Apontador para o estado
@param c A coordenada
Esta função faz a verificação de vencedores e caso não exista realiza o movimento.
*/
void move(STATE *, COORDINATE);

/**
\brief Interpretador de commandos
@param e Apontador para o estado
Esta função funciona como interpretador de comandos.
*/
int CMD(STATE *);

/**
\brief Prompt
@param e Apontador para o estado
Esta função faz print a informações úteis no ecran.
*/
void prompt(STATE *s);

#endif
