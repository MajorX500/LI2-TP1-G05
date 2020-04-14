#ifndef __LISTS_H_
#define __LISTS_H_

typedef struct NODE { 
    // Any data type can be stored in this node 
    void  *data; 
  
    struct NODE *next; 
} *LIST; 

LIST initialize_list();

LIST insert_head(LIST, void *);

void *get_head(LIST);

LIST next(LIST);

LIST remove_head(LIST);

int is_list_empty(LIST);

#endif
