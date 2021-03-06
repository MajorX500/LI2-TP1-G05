/**
@file data.h
Definição do estado e das funções que o manipulam
*/

#ifndef __DATA_H__
#define __DATA_H__

/** @brief Tipo de dados para a casa
*/
typedef enum {
    EMPTY = '.', /**< Vazia HOUSE#EMPTY*/
    WHITE = '@', /**< Branca HOUSE#WHITE*/
    BLACK = '#', /**< Preta HOUSE#BLACK*/
    H1 = '1', /**< Casa 1 HOUSE#H1*/
    H2 = '2' /**< Casa 2 HOUSE#H2*/
    } HOUSE; /**< Casa */

/** @struct COORDINATE
 *  @brief Define as Cooredenadas
 *  @var COORDINATE::x 
 *  Member 'x' Colunas
 *  @var COORDINATE::y
 *  Member 'y' Linhas
 */
typedef struct {
    int x; 
    int y; 
} COORDINATE;

/** @struct MOVE
 *  @brief Uma Jogada completa
 *  @var MOVE::player1 
 *  Member 'player1' jogador 1
 *  @var MOVE::player2
 *  Member 'player2' jogador 2
 */
typedef struct {
    COORDINATE player1;
    COORDINATE player2;
} MOVE;

/**
\brief Tipo de dados para as jogadas
*/
typedef MOVE MOVES[32];


/** @struct STATE
 *  @brief Estado do jogo
 *  @var STATE::board 
 *  Member 'board' Tabuleiro de Jogo
 *  @var STATE::previous_move 
 *  Member 'previous_move' Jogada anterior
 *  @var STATE::moves
 *  Member 'moves' Lista de Jogadas anteriores
 *  @var STATE::num_moves
 *  Member 'num_moves' Numero de jogadas
 *  @var STATE::current_player
 *  Member 'current_player' jogador atual
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
void empty_board(HOUSE t[8][8]);

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
int get_current_player(STATE *e);

/**
\brief Devolve o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@return O valor da casa
*/
HOUSE get_house(STATE *e, COORDINATE c);

/**
\brief Número de jogadas
Esta função calcula qual o número total das jogadas.
@param e Apontador para o estado
@return Número total de jogadas
*/
int get_num_moves(STATE *e);

/**
\brief Jogada anterior
Esta função diz qual foi a coordenada da jogada anterior.
@param e Apontador para o estado
@return A coordenada da jogada anterior
*/
COORDINATE get_previous_move(STATE *e);

/**
\brief Jogada no array de jogadas
Esta função devolve a jogada de um certo indice do array.
@param e Apontador para o estado
@param i Indice da jogada
*/
MOVE get_move(STATE *e, int i);

/**
\brief Querido Mudei a Casa
Esta função altera o valor da casa de uma certa coordenada.
@param e Apontador para o estado
@param c A coordenada
@param h O valor da casa
*/
void change_house(STATE *e, COORDINATE c, HOUSE h);

/**
\brief Atualiza jogada anterior
Esta função altera a coordenada da jogada anterior no estado para a coordenada nova.
@param e Apontador para o estado
@param c A coordenada
*/
void update_previous_move(STATE *e, COORDINATE c);

/**
\brief Próximo jogador
Esta função altera o jogador atual.
@param e Apontador para o estado
*/
void next_player(STATE *e);

/**
\brief Jogador 1 atual
Esta função altera o jogador atual para o jogador 1.
@param e Apontador para o estado
*/
void set_player1(STATE *e);

/**
\brief Jogador 2 atual
Esta função altera o jogador atual para o jogador 2.
@param e Apontador para o estado
*/
void set_player2(STATE *e);

/**
\brief Póxima jogada
Esta função altera o o número de jogadas efetuadas.
@param e Apontador para o estado
*/
void next_move(STATE *e);

/**
\brief Guarda coordenada do jogador 1
Esta função guarda uma coordenada do jogador 1 no array de jogadas.
@param e Apontador para o estado
@param c Coordenada a ser guardada
*/
void store_p1_coordinate(STATE *e, COORDINATE c);

/**
\brief Guarda coordenada do jogador 2
Esta função guarda uma coordenada do jogador 2 no array de jogadas.
@param e Apontador para o estado
@param c Coordenada a ser guardada
*/
void store_p2_coordinate(STATE *e, COORDINATE c);

/**
\brief Faz o rollback do estado
Esta função limpa o estado do jogo, deixando apenas qual a lista de jogadas e o nº das mesmas.
@param e Apontador para o estado
*/
void clear_state(STATE *e);

/**
\brief Coordenada do jogador
Esta função retorna uma coordenada de um dos jogadores.
@param j Jogada
@param p Jogador
@return a coordenada
*/
COORDINATE get_player_coordinate(MOVE j, int p);

/**
\brief Eixo do jogador
Esta função retorna um eixo de um dos jogadores.
@param c Coordenada
@param a eixo
@return n valor do eixo
*/
int get_player_point(COORDINATE c, char a);

#endif


