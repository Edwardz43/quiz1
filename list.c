#include "list.h"

node_t *list_make_node_t(node_t *list, int value)
{
    if (!list) {
        list = malloc(sizeof(node_t));
        list->value = value;
        return list;
    }
    node_t *head = list;

    while (list->next)
        list = list->next;

    list->next = malloc(sizeof(node_t));
    list->next->value = value;

    return head;
}

void list_free(node_t **list)
{
    while (*list) {
        node_t *tmp = *list;
        *list = (*list)->next;
        free(tmp);
    }
}

void inline list_add_node_t(node_t **list, node_t *node_t)
{
    node_t->next = *list;
    *list = node_t;
}

void inline list_concat(node_t **left, node_t *right)
{
    while (*left)
        left = &((*left)->next);
    *left = right;
}

void quicksort(node_t **list)
{
    if (!*list)
        return;

    node_t *pivot = *list;
    int value = pivot->value;
    node_t *p = pivot->next;
    pivot->next = NULL;

    node_t *left = NULL, *right = NULL;
    while (p) {
        node_t *n = p;
        p = p->next;
        list_add_node_t(n->value > value ? &right : &left, n);
    }

    quicksort(&left);
    quicksort(&right);

    node_t *result = NULL;
    list_concat(&result, left);
    list_concat(&result, pivot);
    list_concat(&result, right);
    *list = result;
}
