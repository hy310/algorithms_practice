#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ( ( (a) > (b) ) ? (a) : (b) )

typedef struct TreeNode
{
    int key, height;
    struct TreeNode* parent, * left, * right;
}TreeNode;

typedef struct
{
    TreeNode * root;
}TreeType;

void initTree(TreeType* T)
{
    T->root = (TreeNode*)malloc(sizeof(TreeNode));
    T->root->parent = T->root->left = T->root->right = NULL;
    T->root->height = 0;
}

int isExternal(TreeNode* w)
{
    return (w->left == NULL && w->right == NULL);
}

TreeNode* treeSearch(TreeNode* v, int k)
{
    if (isExternal(v))
        return v;
    if (k == v->key)
        return v;
    else if (k < v->key)
        return treeSearch(v->left, k);
    else
        return treeSearch(v->right, k);
}

int findElement(TreeType* T, int k)
{
    TreeNode* w = treeSearch(T->root, k);

    if (isExternal(w))
        return 0;
    else
        return w->key;
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

// z �� ��, �� �ڽĳ�� height ���ؼ� �ұ���ã��
int heightUpdateAndBalanceCheck(TreeNode* w)
{
    TreeNode* l, * r;
    int b;      // balance

    // ������ �ö󰡺ôµ� balance �� �ȱ����� ��
    if (w == NULL)
        return 1;    // 1 return �� balance ������ x �ǹ�

    l = w->left;
    r = w->right;

    w->height = max(r->height, l->height) + 1;
    b = r->height - l->height;

    // b�� ������ �� ������ ����� ������ֱ� ���� ����
    if ( b * b < 2)
        return 1;     // ���� 2���� ������ balance ������ x
    else
        return 0;

}

TreeNode* restructure(TreeType* T, TreeNode* x)
{
    TreeNode* y, * z, * a, * b, * c, * T0, * T1, * T2, * T3;

    y = x->parent;
    z = y->parent;

    // �� 4������ ȸ�� ����� ��
    // 1. RR ( z < y < x : �� ���������� �پ����� �� )
    if (z->key < y->key && y->key < x->key)
    {
        a = z;
        b = y;
        c = x;
        T0 = a->left;
        T1 = b->left;
        T2 = c->left;
        T3 = c->right;
    }

    // 2. LL ( x < y < z : �� �������� �پ����� �� )
    else if (x->key < y->key && y->key < z->key)
    {
        a = x;
        b = y;
        c = z;
        T0 = a->left;
        T1 = a->right;
        T2 = b->right;
        T3 = c->right;
    }

    // 3. RL ( z < x < y )
    else if ( z->key < x->key && x->key < y->key)
    {
        a = z;
        b = x;
        c = y;
        T0 = a->left;
        T1 = b->left;
        T2 = b->right;
        T3 = c->right;
    }

    // 4. LR ( y < x < z )
    else
    {
        a = y;
        b = x;
        c = z;
        T0 = a->left;
        T1 = b->left;
        T2 = b->right;
        T3 = c->right;
    }

    // z�� ��Ʈ�� �ϴ� ��Ʈ���� b ��Ʈ�� �ϴ� ��Ʈ���� ��ü
    // a-b-c ������ �� �� �ְ� b �� ��Ʈ�� �ϴ� ����
    if (z == T->root)
    {
        T->root = b;
        b->parent = NULL;
    }
    // ���ʿ� z �� ������ a-b-c ���� ���� b�� ��������
    else if (z->parent->left == z)
    {
        z->parent->left = b;
        b->parent = z->parent;
    }
    else // if (z->parent->right == z)
    {
        z->parent->right = b;
        b->parent = z->parent;
    }

    // T0�� T1 �� ���� a �� ���� �� ������ ��Ʈ���� �����
    a->left = T0;
    T0->parent = a;
    a->right = T1;
    T1->parent = a;
    a->height = max(T0->height, T1->height) + 1; // ���� �Ͼ���� ����!
    
    // T2�� T3 �� ���� c �� ���� �� ������ ��Ʈ���� �����
    c->left = T2;
    T2->parent = c;
    c->right = T3;
    T3->parent = c;
    c->height = max(T2->height, T3->height) + 1;

    // a�� c �� ���� b�� ���� �� ������ �ڽ����� ����� 
    b->left = a;
    a->parent = b;
    b->right = c;
    c->parent = b;
    b->height = max(a->height, c->height) + 1;

    // root ������ b �̴� b return
    return b;

}

void searchAndFixAfterInsertion(TreeType* T, TreeNode* w)
{
    TreeNode* z = w;  // ó���� ������ ���� �����ؼ� �Ž����ö󰥰�
    TreeNode* y, * x;

    // 1. ó�� ������ �ұ��� ��� z ã��
    // ���� �� balance �� 1�� ������µ��� ��� parent �Ž����ö󰡱�
    while(heightUpdateAndBalanceCheck(z))
    {
        // root ���� �ö����� �׳� return
        if( z == NULL )
            return;
        z = z->parent;
    }
    // �������Դٸ� �ұ��� �߻�
    
    // 2. z�� ���� �ڽ� y ��� �ϱ�
    if (z->left->height > z->right->height)
        y = z->left;
    else
        y = z->right;
    
    // 3. y�� ���� �ڽ� x ��� �ϱ�
    if (y->left->height > y->right->height)
        x = y->left;
    else
        x = y->right;

    // 4. restructure(x,y,z)
    restructure(T, x);

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
        searchAndFixAfterInsertion(T, w);    // AVL tree �ϱ� �߰�
    }
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


TreeNode* inOrderSucc(TreeNode* w)   // ��������� ã��
{
    w = w->right;   // ���� �����ڽİ�����
    while(w->left != NULL)    // �����ڽĸǳ� �ܺγ��
        w = w->left;
    return w;
}

void searchAndFixAfterRemoval(TreeType* T, TreeNode* w)
{
    TreeNode* z = w;
    TreeNode* y;
    TreeNode* x;
    TreeNode* b;
    x = NULL;

    // 1. w ���� ��Ʈ�� �ö󰡴ٰ� ó�� ������ �ұ��� ��� z
    while (heightUpdateAndBalanceCheck(z))
    {
        if (z==NULL)
            return;
        z = z->parent;
    }

    // 2. z�� ���� �ڽ� y
    if (z->left->height > z->right->height)
        y = z->left;
    else
        y = z->right;

    // 3. y�� �ڽ� x(���� �ڽ�, ������ ������ �ڽ�)
    if (y->left->height > y->right->height)
        x = y->left;
    else if (y->left->height < y->right->height)
        x = y->right;
    else if (z->left == y)
        x = y->left;
    else if (z->right == y)
        x = y->right;

    // 4. restructure
    b= restructure(T, x);

    // 5. ���� ���� ��� ã�� ���� �ݺ�
    // ���� �� 1ȸ ������ �������� ���� ���� ������ �ѹ� �� ȣ��
    searchAndFixAfterRemoval(T, b);

}

int removeElement(TreeType* T, int k)
{
    TreeNode* w = treeSearch(T->root, k);

    if (isExternal(w))
        return 0;
    
    TreeNode* z, * y, * zs;
    z = w->left;

    // case 1
    if(!isExternal(z))  
        z = w->right;
    if(isExternal(z))
        zs = reduceExternal(T, z);
    // case 2
    else                
    {
        z = inOrderSucc(w);
        y = z->parent; 
        w->key = y->key;
        zs = reduceExternal(T, z);
    }
    searchAndFixAfterRemoval(T, zs->parent);
    return k;
}


void preOrder(TreeNode* root)   // ������ȸ
{
    if (isExternal(root))
        return;            // �̰� ������ ���������� �����Ⱚ ��µ�
    printf("[%d] ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

void rFindAllInRange(TreeNode* v, int k1, int k2)
{
    if (isExternal(v))
        return;
    if (k1 <= v->key && v->key <= k2)
        printf("[%d] ", v->key);
    if (v->key <= k1)
        rFindAllInRange(v->right, k1, k2);
    else if (k2 <= v->key)
        rFindAllInRange(v->left, k1, k2);
    else // (k1 < v->key < k2)
    {
        rFindAllInRange(v->left, k1, k2);
        rFindAllInRange(v->right, k1, k2);
    }

}

int main()
{
    TreeType* T = (TreeType*)malloc(sizeof(TreeType));
    initTree(T);

    insertItem(T, 44);
    insertItem(T, 17);
    insertItem(T, 32);
    insertItem(T, 78);
    insertItem(T, 50);
    insertItem(T, 88);
    insertItem(T, 48);
    insertItem(T, 62);
    insertItem(T, 54);
    preOrder(T->root); printf("\n");

    rFindAllInRange(T->root, 50, 80);


}

