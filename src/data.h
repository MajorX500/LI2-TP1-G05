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
typedef struct {
    int x; //columns
    int y; //lines
} COORDINATE;


/**
\brief Tipo de dados para a jogada
*/
typedef struct {
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
typedef struct {
    /** O tabuleiro */
    HOUSE board[8][8];
    /** A coordenada da última jogada */
    COORDINATE previous_move;
    /** As jogadas */
    MOVES moves;
    /** O número das jogadas */
    int num_moves;
    /** O jogador atual */
    int current_player;
} STATE;


/**
\brief Tabuleiro vazio
Esta função inicializa o array do tabuleiro.
@param t Array do tabuleiro
*/
void empty_board(HOUSE [8][8]);

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@return O novo estado
*/
STATE *starting_state();


/**
\brief Jogador Atual
Esta função diz qual é o jogador a efectuar a jogada.
@param e Apontador para o estado
@return O jogador atual
*/
int get_current_player(STATE *);

/**
\brief Devolve o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@return O valor da casa
*/
HOUSE get_house(STATE *, COORDINATE);

/**
\brief Número de jogadas
Esta função calcula qual o número total das jogadas.
@param e Apontador para o estado
@return Número total de jogadas
*/
int get_num_moves(STATE *);

/**
\brief Jogada anterior
Esta função diz qual foi a coordenada da jogada anterior.
@param e Apontador para o estado
@return A coordenada da jogada anterior
*/
COORDINATE get_previous_move(STATE *);

/**
\brief Jogada no array de jogadas
Esta função devolve a jogada de um certo indice do array.
@param e Apontador para o estado
@param i Indice da jogada
*/
MOVE get_move(STATE *, int);

/**
\brief Querido Mudei a Casa
Esta função altera o valor da casa de uma certa coordenada.
@param e Apontador para o estado
@param c A coordenada
@param h O valor da casa
*/
void change_house(STATE *, COORDINATE , HOUSE);

/**
\brief Atualiza jogada anterior
Esta função altera a coordenada da jogada anterior no estado para a coordenada nova.
@param e Apontador para o estado
@param c A coordenada
*/
void update_previous_move(STATE *, COORDINATE );

/**
\brief Próximo jogador
Esta função altera o jogador atual.
@param e Apontador para o estado
*/
void next_player(STATE *s);

/**
\brief Jogador 1 atual
Esta função altera o jogador atual para o jogador 1.
@param e Apontador para o estado
*/
void set_player1(STATE *s);

/**
\brief Jogador 2 atual
Esta função altera o jogador atual para o jogador 2.
@param e Apontador para o estado
*/
void set_player2(STATE *s);

/**
\brief Póxima jogada
Esta função altera o o número de jogadas efetuadas.
@param e Apontador para o estado
*/
void next_move(STATE *s);

/**
\brief Guarda coordenada do jogador 1
Esta função guarda uma coordenada do jogador 1 no array de jogadas.
@param e Apontadoe para o estado
@param c Coordenada a ser guardada
*/
void store_p1_coordinate(STATE *, COORDINATE);

/**
\brief Guarda coordenada do jogador 2
Esta função guarda uma coordenada do jogador 2 no array de jogadas.
@param e Apontadoe para o estado
@param c Coordenada a ser guardada
*/
void store_p2_coordinate(STATE *, COORDINATE);

/**
\brief Faz o rollback do estado
Esta função limpa o estado do jogo, deixando apenas qual a lista de jogadas e o nº das mesmas.
@param e Apontadoe para o estado
*/
void clear_state(STATE *);
#endif
