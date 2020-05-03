#include <stddef.h>
#include <stdlib.h>
#include "linked_lists.h"

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

int length(LIST l) {
	int length = 0;
	for (; !is_list_empty(l); length++, l = next(l));
	return length;
}

int elem(LIST l, void *data) {
	for(; l != NULL && get_head(l) != data; l = next(l));
	return !!l;
}