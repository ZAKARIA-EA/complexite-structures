#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int val;
    struct tree *left,*right;
} *ARB;

ARB insert(int x, ARB A)
{
    if(!A)
    {
        A = malloc(sizeof(*A));
        A->val=x; A->left=A->right=NULL;
    }
    else if(x<=A->val)
        A->left=insert(x,A->left);
    else
        A->right=insert(x,A->right);
    return A;
}

void infixe(ARB A)
{
    if(A){
        infixe(A->left);
        printf("%d ",A->val);
        infixe(A->right);
    }
}

int main()
{
    ARB A=NULL;
    for(int i=0;i<10;i++)
        A=insert(rand()%10,A);

    infixe(A);
}
