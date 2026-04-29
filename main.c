int EstABR(ARB A)
{
    if(!A) return 1;

    if(A->left && A->left->val > A->val)
        return 0;
    if(A->right && A->right->val < A->val)
        return 0;

    return EstABR(A->left) && EstABR(A->right);
}
