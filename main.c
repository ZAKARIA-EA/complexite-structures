#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    char data;
    struct stack *next;
} STACK;

typedef struct node {
    char data;
    struct node *next;
} NODE;

typedef struct {
    NODE *first;
    NODE *last;
} QUEUE;

void push(STACK **p,char c){
    STACK *n=malloc(sizeof(STACK));
    n->data=c; n->next=*p; *p=n;
}

char pop(STACK **p){
    STACK *t=*p; char c=t->data;
    *p=t->next; free(t); return c;
}

void enqueue(QUEUE *q,char c){
    NODE *n=malloc(sizeof(NODE));
    n->data=c; n->next=NULL;
    if(!q->first) q->first=q->last=n;
    else{ q->last->next=n; q->last=n; }
}

char dequeue(QUEUE *q){
    NODE *t=q->first; char c=t->data;
    q->first=t->next; free(t); return c;
}

int EstPalindrome(char s[]){
    int i,len=strlen(s);
    STACK *p=NULL;
    QUEUE q={NULL,NULL};

    for(i=0;i<len;i++) enqueue(&q,s[i]);
    for(i=0;i<len/2;i++) push(&p,dequeue(&q));

    if(len%2) dequeue(&q);

    for(i=0;i<len/2;i++)
        if(pop(&p)!=dequeue(&q)) return 0;

    return 1;
}
