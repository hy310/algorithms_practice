#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int key;
    struct TreeNode* parent, * left, * right;
}TreeNode;

typedef struct
{
    TreeNode *root;
}TreeType;

void initTree(TreeType* T)
{
    T->root = (TreeNode*)malloc(sizeof(TreeNode));
    T->root->parent = T->root->left = T->root->right = NULL;
}

int isExternal(TreeNode* w)
{
    return (w->left == NULL & w->right == NULL);
}

TreeNode* treeSearch(TreeNode* v, int k)
{
    if (isExternal(v))
        return v;
    if (k == v->key)
        return v;
    else if(k < v->key)
        return treeSearch(v->left, k);
    else
        return treeSearch(v->right, k);
}

void expandExternal(TreeNode* w)
{
    TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
    l->left = NULL;
    l->right = NULL;
    l->parent = w;
    r->left = NULL;
    r->right = NULL;
    r->parent = w;
    w->left = l;
    w->right = r;
}

TreeNode* sibling(TreeNode* z)
{
    if (z->parent->left == z)
        return z->parent->right;
    else
        return z->parent->left;
}

TreeNode* reduceExternal(TreeType* T, TreeNode* z)
{
    TreeNode* w = z->parent;
    TreeNode* g = w->parent;
    TreeNode* zs = sibling(z);
    zs->parent = g;

    if (g == NULL)
    {
        T->root = zs;
    }
    else 
    {
        if (w == g->left)
            g->left = zs;
        else  // (if w == g->right)
            g->right = zs;
    }

    free(z);
    free(w);
    return zs;
}

int findElement(TreeType* T, int k)
{
    TreeNode* w = treeSearch(T->root, k);

    if (isExternal(w))
        return 0;
    else
        return w->key;
}

TreeNode* inOrderSucc(TreeNode* w)
{
    w = w->right;
    while(w->left != NULL)
        w = w->left;
    return w;
}

int removeElement(TreeType* T, int k)
{
    TreeNode* w = treeSearch(T->root, k);

    if (isExternal(w))
        return 0;
    
    TreeNode* z, * y;
    z = w->left;

    // case 1
    if(!isExternal(z))
        z = w->right;
    if(isExternal(z))
        reduceExternal(T, z);
    // case 2
    else
    {
        z = inOrderSucc(w);
        y = z->parent; 
        w->key = y->key;
        reduceExternal(T, z);
    }
    return k;
}

void insertItem(TreeType* T, int k)
{
    TreeNode* w = treeSearch(T->root, k);
    if (!isExternal(w))
        return;
    else
    {
        w->key = k;
        expandExternal(w);
    }
}

void preOrder(TreeNode* root)
{
    if (isExternal(root))
        return;
    printf("[%d] ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

void rightRotate(TreeType* T, TreeNode* x, TreeNode* y)
{
    TreeNode* T0, * T1, * T2, * p;
    p = y->parent;
    T0 = x->left;
    T1 = x->right;
    T2 = y->right;

    y->parent = x;
    x->parent = p;

    if (x->parent == NULL)
        T->root = x;
    
    x->left = T0;
    x->right = y;
    y->left = T1;
    y->right = T2;
}

void leftRotate(TreeType* T, TreeNode* x, TreeNode* y)
{
    TreeNode* T0, * T1, * T2, *p;
    p = y->parent;
    T0 = y->left;
    T1 = x->left;
    T2 = x->right;

    if (x->parent == NULL)
        T->root = x;
    
    x->left = y;
    x->right = T2;
    y->left = T0;
    y->right = T1;
}

// splay() ???? ????

int main()
{
    TreeType* T = (TreeType*)malloc(sizeof(TreeType));
    initTree(T);

    insertItem(T, 9);
    insertItem(T, 2);
    insertItem(T, 1);
    insertItem(T, 7);
    insertItem(T, 5);
    insertItem(T, 3);
    insertItem(T, 4);
    insertItem(T, 8);
    insertItem(T, 15);
    insertItem(T, 11);
    preOrder(T->root); printf("\n");

}