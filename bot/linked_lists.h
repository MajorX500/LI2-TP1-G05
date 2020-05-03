/**
@file linked_lists.h
Definição das listas ligadas
*/

#ifndef __LINKED_LISTS_H_
#define __LINKED_LISTS_H_

/** @struct NODE
 *  @brief Lista Ligada
 *  @var NODE::data
 *  Member 'data' Dados guardados na lista
 *  @var NODE::next
 *  Member 'next' Proximo elemento
*/
typedef struct NODE { 
    void  *data;
    struct NODE *next; 
} *LIST; /**< Apontador para a lista */

/**
\brief Inicializar lista
Esta função incicializa uma lista
@return O jogador atual
*/
LIST initialize_list();

/**
\brief Inserir na cabeça 
Esta função insere um elemento na cabeça da lista
@param l Lista ligada
@param e Apontador para o elemento a ser adicionado
@return nova lista
*/
LIST insert_head(LIST l, void *e);

/**
\brief Devolve cabeça
Esta função insere um elemento na cabeça da lista
@param l Lista ligada
@return Apontador para o primeiro elemento da lista
*/
void *get_head(LIST l);

/**
\brief Proximo elemento
Esta função percorre a lista
@param l Lista ligada
@return Apontador para a nova lista
*/
LIST next(LIST l);

/**
\brief Remove cabeça
Esta função remove o primeiro elemento da lista
@param l Lista ligada
@return Apontador para a nova lista
*/
LIST remove_head(LIST l);

/**
\brief Lista vazia
Esta função verifica se a lista esta vazia
@param l Lista ligada
@return algo diferente de 0 se a lista estiver vazia
*/
int is_list_empty(LIST l);

/**
\brief Tamanho da lista
Esta função devolve o tamanho da lista
@param l Lista ligada
@return Tamanho da lista
*/
int length(LIST l);

/**
\brief IsElem
Esta função se é elemento.
@param l Uma LISTA
@param e Apontador para o elemento a pesquisar
@return True/False
*/
int elem(LIST l, void *e);

#endif
