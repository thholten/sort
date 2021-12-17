#ifndef SORT_H
#define SORT_H

typedef struct node
{
    char *body;
    struct node *next;
} NODE;

typedef struct linkedlist
{
    NODE *head;
} LINKEDLIST;

void llinit(LINKEDLIST *ll);
void nodeinit(NODE *n);
void llprint(LINKEDLIST *ll);
void lladd(LINKEDLIST *ll, NODE *new);

int sort();
#endif