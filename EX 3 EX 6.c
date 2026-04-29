#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
} STACK;

void push(STACK **head, int value)
{
    STACK *n = malloc(sizeof(STACK));
    n->data = value;
    n->next = *head;
    *head = n;
}

int pop(STACK **head)
{
    STACK *tmp = *head;
    int v = tmp->data;
    *head = tmp->next;
    free(tmp);
    return v;
}

STACK* PairImpair(STACK *P1)
{
    STACK *P2=NULL,*P3=NULL;
    int val;

    while(P1)
    {
        val = pop(&P1);
        if(val%2==0) push(&P2,val);
        else push(&P3,val);
    }

    while(P3) push(&P2,pop(&P3));

    return P2;
}
