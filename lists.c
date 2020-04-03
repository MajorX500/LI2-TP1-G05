#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

LIST initialize_list() {
    LIST l = malloc(sizeof(NODE));
    l->data = NULL;
    l->next = NULL;
    return l;
}

LIST insert_head(LIST l, void *d) {
  if (!get_head(l)) {
    l->data = d;
    return l;
  }
  else {
    LIST nl = malloc(sizeof(NODE));
    nl->data = d;
    nl->next = l;
    return nl;
  }
}

void *get_head(LIST l) {
  return l->data;
}

LIST next(LIST l) {
  return l->next;
}

LIST remove_head(LIST l) {
  if (is_list_empty(l))
    return l;
  else if (l->next == NULL) {
    l->data = NULL;
    return l;
  }
  else {
    LIST nl = l->next;
    free(l);
    return nl;
  }
}

int is_list_empty(LIST l) {
  return !l;
}
