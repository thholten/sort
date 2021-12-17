#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sort.h"

void llinit(LINKEDLIST *ll)
{
    ll->head = NULL;
}

void nodeinit(NODE *node)
{
    node->body = NULL;
    node->next = NULL;
}

void llprint(LINKEDLIST *ll)
{
    for (NODE *n = ll->head; n != NULL; n = n->next)
    {
        fprintf(stderr, "%s\n", n->body);
    }
}

void lladd(LINKEDLIST *ll, NODE *new)
{
    if (ll->head == NULL)
    {
        ll->head = new;
    }
    else
    {
        for (NODE *n = ll->head; n != NULL; n = n->next)
        {
            if (n->next == NULL)
            {
                n->next = new;
                break;
            }
        }
    }
}
