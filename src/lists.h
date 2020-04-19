/**
@file listas.h
Definição das listas ligadas
*/

#ifndef __LISTS_H_
#define __LISTS_H_

typedef struct NODE { 
    // Any data type can be stored in this node 
    void  *data; 
  
    struct NODE *next; 
} *LIST; 

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
LIST insert_head(LIST, void *);

/**
\brief Devolve cabeça
Esta função insere um elemento na cabeça da lista
@param l Lista ligada
@return Apontador para o primeiro elemento da lista
*/
void *get_head(LIST);

/**
\brief Proximo elemento
Esta função percorre a lista
@param l Lista ligada
@return Apontador para a nova lista
*/
LIST next(LIST);

/**
\brief Remove cabeça
Esta função remove o primeiro elemento da lista
@param l Lista ligada
@return Apontador para a nova lista
*/
LIST remove_head(LIST);

/**
\brief Lista vazia
Esta função verifica se a lista esta vazia
@param l Lista ligada
@return algo diferente de 0 se a lista estiver vazia
*/
int is_list_empty(LIST);

#endif
