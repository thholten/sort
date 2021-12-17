#include "sort.h"

int sort()
{
    LINKEDLIST ll;
    llinit(&ll);
    NODE n1;
    nodeinit(&n1);
    n1.body = "aaa";
    NODE n2;
    nodeinit(&n2);
    n2.body = "bbb";
    NODE n3;
    nodeinit(&n3);
    n3.body = "ccc";
    NODE n4;
    nodeinit(&n4);
    n4.body = "ddd";

    lladd(&ll, &n3);
    lladd(&ll, &n1);
    lladd(&ll, &n4);
    lladd(&ll, &n2);

    llprint(&ll);

    return 0;
}