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

void findAllElements(TreeType* T, int k)
{
    int count = 0;
    TreeNode* w = treeSearch(T->root, k);

    while(!isExternal(w))
    {
        count++;
        w = treeSearch(w->right, k);
    }
    printf("%d개의 %d 값이 존재합니다.\n", count, k);
}

void removeAllElements(TreeType* T, int k)
{
    TreeNode* w, * z, * y;
    w = treeSearch(T->root, k);

    while(!isExternal(w))  // key 값 갖는 노드가 내부노드일동안 계속 반복
    {
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
        // 반복
        w = treeSearch(T->root, k);
    }
}

void insertItem(TreeType* T, int k)
{
    TreeNode* w = treeSearch(T->root, k);
    while (!isExternal(w))    // isInternal 대신해서 사용
        // 같은 값이 있다면 오른쪽 subtree 로 찾아나서기
        w = treeSearch(w->right, k);
    // 외부노드까지 도달했다면 삽입
    w->key = k;
    expandExternal(w);
}

void preOrder(TreeNode* root)
{
    if (isExternal(root))
        return;
    printf("[%d] ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    TreeType* T = (TreeType*)malloc(sizeof(TreeType));
    initTree(T);

    insertItem(T, 39);
    insertItem(T, 24);
    insertItem(T, 55);
    insertItem(T, 41);
    insertItem(T, 8);
    insertItem(T, 33);
    insertItem(T, 30);
    insertItem(T, 24);
    insertItem(T, 27);
    insertItem(T, 33);
    insertItem(T, 24);
    insertItem(T, 24);

    preOrder(T->root); printf("\n");
    getchar();

    findAllElements(T, 24);

    removeAllElements(T, 24);
    preOrder(T->root); printf("\n");
    getchar();

}