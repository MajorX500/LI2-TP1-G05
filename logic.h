/**
@file logic.h
Definição da parte lógica do jogo.
*/

#ifndef __LOGIC_H__
#define __LOGIC_H__

/**
\brief Faz movimento
@param e Apontador para o estado
@param c A coordenada
Esta função realiza o movimento chamando todas as auxiliares.
*/
void make_move(STATE *, COORDINATE);

/**
\brief Valida
@param e Apontador para o estado
@param c A coordenada
Esta função faz a validação de uma jogada com uma certa coordenada.
@return Verdadeiro ou Falso
*/
int validate_move(STATE *, COORDINATE);

/**
\brief Verifica vencedor
@param e Apontador para o estado
@param c A coordenada
Esta função verifica se existem vencedores no momento da jogada.
@return Verdadeiro ou Falso
*/
int check_winner(STATE *, COORDINATE);

/**
\brief Scanner
@param e Apontador para o estado
Esta função calcula todos os movimentos possíveis no tabuleiro.
@return Número de jogadas possíveis
*/
int valid_moves(STATE *);

/**
\brief Movimento
@param e Apontador para o estado
@param c A coordenada
Esta função faz a verificação de vencedores e caso não exista realiza o movimento.
*/
void move(STATE *, COORDINATE);

/**
\brief Guarda coordenada
@param e Apontadoe para o estado
Esta função guarda uma coordenada no array de jogadas.
*/
void store_coordinate(STATE *, COORDINATE);

#endif
