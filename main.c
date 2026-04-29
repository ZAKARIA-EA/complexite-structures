int Min(ARB A)
{
    while(A->left)
        A = A->left;
    return A->val;
}
