/**
@file data.h
Definição do estado e das funções que o manipulam
*/

#ifndef __DATA_H__
#define __DATA_H__

/**
\brief Tipo de dados para a casa
*/
typedef enum {
    EMPTY = '.',
    WHITE = '@',
    BLACK = '#',
    H1 = '1',
    H2 = '2'
    } HOUSE;

/**
\brief Tipo de dados para as coordenadas
*/
typedef struct
{
    int x; //columns
    int y; //lines
} COORDINATE;


/**
\brief Tipo de dados para a jogada
*/
typedef struct
{
    COORDINATE player1;
    COORDINATE player2;
} MOVE;

/**
\brief Tipo de dados para as jogadas
*/
typedef MOVE MOVES[32];


/**
\brief Tipo de dados para o estado
*/
typedef struct
{
    /** O tabuleiro */
    HOUSE board[8][8];
    /** A coordenada da última jogada */
    COORDINATE previous_move;
    /** As jogadas */
    MOVES moves;
    /** O número das jogadas, usado no prompt */
    int num_moves;
    /** O jogador atual */
    int current_player;
} STATE;


/**
\brief Tabuleiro vazio
@param t Array do tabuleiro
Esta função inicializa o array do tabuleiro.
*/
void empty_board(HOUSE [8][8]);

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
STATE *starting_state();


/**
\brief Jogador Atual
@param e Apontador para o estado
Esta função diz qual é o jogador a efectuar a jogada.
@returns O jogador atual
*/
int get_current_player(STATE *);

/**
\brief Devolve o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@returns O valor da casa
*/
HOUSE get_house(STATE *, COORDINATE);

/**
\brief Número de jogadas
@param e Apontador para o estado
Esta função calcula qual o número total das jogadas.
@returns Número total de jogadas
*/
int get_num_moves(STATE *);

/**
\brief Jogada anterior
@param e Apontador para o estado
Esta função diz qual foi a coordenada da jogada anterior.
@return A coordenada da jogada anterior
*/
COORDINATE get_previous_move (STATE *);

/**
\brief Jogada no array de jogadas
@param e Apontador para o estado
@param i Indice da jogada
Esta função devolve a jogada de um certo indice do array.
*/
MOVE get_move(STATE *, int);

/**
\brief Querido Mudei a Casa
@param e Apontador para o estado
@param c A coordenada
@param h O valor da casa
Esta função altera o valor da casa de uma certa coordenada.
*/
void change_house(STATE *, COORDINATE , HOUSE);

/**
\brief Atualiza jogada anterior
@param e Apontador para o estado
@param c A coordenada
Esta função altera a coordenada da jogada anterior no estado para a coordenada nova.
*/
void update_previous_move(STATE *, COORDINATE );

/**
\brief Atualiza o numero de jogadas
@param e Apontador para o estado
@param i O novo numero de jogadas
Esta função altera a co numero de jogadas efetuadas
*/
void update_num_moves(STATE *, int);

/**
\brief Próximo jogador
@param e Apontador para o estado
Esta função altera o jogador atual.
*/
void next_player(STATE *s);

/**
\brief Jogador 1 atual
@param e Apontador para o estado
Esta função altera o jogador atual para o jogador 1.
*/
void set_player1(STATE *s);

/**
\brief Jogador 2 atual
@param e Apontador para o estado
Esta função altera o jogador atual para o jogador 2.
*/
void set_player2(STATE *s);

/**
\brief Póxima jogada
@param e Apontador para o estado
Esta função altera o o número de jogadas efetuadas.
*/
void next_move(STATE *s);

/**
\brief Guarda coordenada do jogador 1
@param e Apontadoe para o estado
@param c Coordenada a ser guardada
Esta função guarda uma coordenada do jogador 1 no array de jogadas.
*/
void store_p1_coordinate(STATE *, COORDINATE);

/**
\brief Guarda coordenada do jogador 2
@param e Apontadoe para o estado
@param c Coordenada a ser guardada
Esta função guarda uma coordenada do jogador 2 no array de jogadas.
*/
void store_p2_coordinate(STATE *, COORDINATE);

#endif
