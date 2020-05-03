/**
@file algorithms.h
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
int max(int x, int y);



/**
\brief Min
Esta função calcula o menor de dois números
@param x Numero 1
@param y Numero 2
@return O menor numero
*/
int min(int x, int y);


/**
\brief Jogadas possiveis
Esta função verifica as jogadas/casa que são possiveis efectuar
a partir de uma certa coordenada.
@param e Apontador para o estado
@return Uma Lista Ligada de coordenadas
*/
LIST possible_coordinates(STATE *e);


/**
\brief Valor da Casa
Esta função devolve o valor de uma casa.
@param c Uma Coordenada
@return O valor da casa
*/
int value_of(COORDINATE c);


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
int minmax(STATE *e, COORDINATE c, int depth, int alpha, int beta, int j);

/**
\brief Decide Iguais
Esta função escolhe a melhor casa.
@param e Apontador para p estado
@param c1 uma coordenada
@param c2 outra coordenada
@return A melhor coordenada
*/
COORDINATE decide_between_equals(STATE *e, COORDINATE c1, COORDINATE c2);

/**
\brief FreeCoord
Esta função monta uma lista de coordenadas vazias.
@param e apontador para o estado
@param l Lista de coordenadas
@return Uma Lista de coordenadas
*/
LIST free_coordinates(STATE *e, LIST l);

/**
\brief Número de vazias
Esta função devolve o numero de casa vazias adjacentes ao jogador.
@param e apontador paar um estado
@return Número de casas
*/
int num_free_coordinates(STATE *e);


/**
\brief Melhor coordenada
Esta função calcula qual a melhor coordenada para
aumentar a probabilidade de ganhar.
@param e Apontador para o estado
@return A melhor coordenada
*/
COORDINATE find_best_coordinate(STATE *e);

/**
\brief Paridade
Esta função é o algoritmo da Paridade.
@param e Apontador para o estado
@return A melhor coordenada
*/
COORDINATE pairity(STATE *e);

/**
\brief ContaVazio
Esta função conta o numero de 
casa vazias no tabuleiro.
@param e Apontador para o estado
@param c Coordenada Atual
@return Numero de Vazios
*/
int numbEmpty(STATE *e, COORDINATE c);

#endif
