/**
@file bot.h
Definição do bot e das funçoes utilizadas pelo mesmo
*/


#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__


/**
\brief Max
Esta função calcula o maior de dois números
@param x Numero 1
@param y Numero 2
@return O maior numero
*/
int max(int, int);



/**
\brief Min
Esta função calcula o menor de dois números
@param x Numero 1
@param y Numero 2
@return O menor numero
*/
int min(int, int);


/**
\brief Jogadas possiveis
Esta função verifica as jogadas/casa que são possiveis efectuar
a partir de uma certa coordenada.
@param e Apontador para o estado
@param c Coordenada
@return Uma Lista Ligada de coordenadas
*/
LIST possible_coordinates(STATE *, COORDINATE);


/**
\brief Valor da Casa
Esta função devolve o valor de uma casa.
@param c Uma Coordenada
@return O valor da casa
*/
int value_of(COORDINATE);


/**
\brief MinMax
Esta função é o brain do bot.
@param e Apontador para o estado
@param c Coordenada
@param depth Numero de Pecas a Procurar
@param alpha Pontuação minima do jogador maximizante
@param beta Pontuação maxima do jogador minimizante
@param j Identificação do jogador
@return O valor da melhor coordenada
*/
int minmax(STATE *, COORDINATE, int, int, int, int);


/**
\brief Melhor coordenada
Esta função calcula qual a melhor coordenada para
aumentar a probabilidade de ganhar.
@param e Apontador para o estado
@return A melhor coordenada
*/
COORDINATE find_best_coordinate(STATE *);

/**
\brief Paridade
Esta função é o algoritmo da Paridade.
@param e Apontador para o estado
@return A melhor coordenada
*/
COORDINATE pairity(STATE *);

/**
\brief ContaVazio
Esta função conta o numero de 
casa vazias no tabuleiro.
@param e Apontador para o estado
@param c Coordenada Atual
@return Numero de Vazios
*/
int numbEmpty(STATE *, COORDINATE);

#endif
