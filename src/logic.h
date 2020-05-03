/**
@file logic.h
Definição da parte lógica do jogo.
*/

#ifndef __LOGIC_H__
#define __LOGIC_H__

/**
\brief Faz movimento
Esta função realiza o movimento chamando todas as auxiliares.
@param e Apontador para o estado
@param c A coordenada
*/
void make_move(STATE *e, COORDINATE c);

/**
\brief Valida
Esta função faz a validação de uma jogada com uma certa coordenada.
@param e Apontador para o estado
@param c A coordenada
@return Verdadeiro ou Falso
*/
int validate_move(STATE *e, COORDINATE c);

/**
\brief Verifica vencedor
Esta função verifica se existem vencedores no momento da jogada.
@param e Apontador para o estado
@param c A coordenada
@return Verdadeiro ou Falso
*/
int check_winner(STATE *e, COORDINATE c);

/**
\brief Scanner
Esta função calcula todos os movimentos possíveis no tabuleiro.
@param e Apontador para o estado
@return Número de jogadas possíveis
*/
int valid_moves(STATE *e);

/**
\brief Movimento
Esta função faz a verificação de vencedores e caso não exista realiza o movimento.
@param e Apontador para o estado
@param c A coordenada
*/
void move(STATE *e, COORDINATE c);

/**
\brief Guarda coordenada
Esta função guarda uma coordenada no array de jogadas.
@param e Apontador para o estado
@param c A coordenada
*/
void store_coordinate(STATE *e, COORDINATE c);

#endif
