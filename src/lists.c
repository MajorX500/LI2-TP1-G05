#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

LIST initialize_list() {
    return NULL;
}

LIST insert_head(LIST l, void *d) {
    LIST nl = malloc(sizeof(struct NODE));
    nl->data = d;
    nl->next = l;
    return nl;
}

void *get_head(LIST l) {
    return l->data;
}

LIST next(LIST l) {
    return l->next;
}

LIST remove_head(LIST l) {
    LIST nl = l->next;
    free(l);
    return nl;
}

int is_list_empty(LIST l) {
    return !l;
}