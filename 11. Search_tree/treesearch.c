#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int key;
    struct TreeNode* parent, * left, * right;
}TreeNode;
// ���⼭ root �����ص� ������ �׷� root ����ø���
// ��� root return ���־���ϱ� ������ ���� TreeType �����

typedef struct
{
    TreeNode *root;
}TreeType;

void initTree(TreeType* T)
{
    // root �� ���� memory �Ҵ�ޱ�
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
        return v;        // external �̸� �״�� ��ġ ����
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

    if (g == NULL)        // ����� �θ� NULL �̸� ���� ��Ʈ
    {
        T->root = zs;
    }
    else    // w �� z �� ������ ���� zs �� g �� ��,�� �� ��� ������ ����
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

TreeNode* inOrderSucc(TreeNode* w)   // ��������� ã��
{
    w = w->right;   // ���� �����ڽİ�����
    while(w->left != NULL)    // �����ڽĸǳ� �ܺγ��
        w = w->left;
    return w;
}

int removeElement(TreeType* T, int k)
{
    TreeNode* w = treeSearch(T->root, k);

    if (isExternal(w))
        return 0;
    
    // �����Ǵ�Ű�� ���� ��� w
    // w �� ������ȸ ����� y
    // y �� �ڽĳ�� z or w�� �ܺγ�� �ڽ� z
    TreeNode* z, * y;
    z = w->left;       // �ϴ� z �� ���� �ڽ�

    // case 1
    if(!isExternal(z))  // �����ڽ��� �ܺγ�尡�ƴϸ�
        z = w->right;   // �������ڽ��� �ܺγ��
    if(isExternal(z))
        reduceExternal(T, z);
    // case 2
    else                // ���� �������ڽ� ��� �ܺγ��
    {
        // ��������� z ã��
        z = inOrderSucc(w);
        y = z->parent; 
        w->key = y->key;
        reduceExternal(T, z);
    }
    return k;
}

void insertItem(TreeType* T, int k)
{
    // ���� ���� �ϴ� �ش� key �� �����ϴ��� Ž��(�ߺ�Ű���x)
    TreeNode* w = treeSearch(T->root, k);
    if (!isExternal(w))    // isInternal ��� ���
        return;
    else
    {
        w->key = k;
        expandExternal(w);   // w �� ���γ��� Ȯ��
    }
}

void preOrder(TreeNode* root)   // ������ȸ
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
    getchar();

    printf("������ Ű �Է� : ");
    int key;
    scanf("%d", &key);
    removeElement(T, key);
    preOrder(T->root); printf("\n");

    return 0;

}