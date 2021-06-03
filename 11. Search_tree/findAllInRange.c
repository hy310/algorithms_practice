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

// z 의 왼, 오 자식노드 height 비교해서 불균형찾기
int heightUpdateAndBalanceCheck(TreeNode* w)
{
    TreeNode* l, * r;
    int b;      // balance

    // 끝까지 올라가봤는데 balance 가 안깨졌을 때
    if (w == NULL)
        return 1;    // 1 return 은 balance 깨지지 x 의미

    l = w->left;
    r = w->right;

    w->height = max(r->height, l->height) + 1;
    b = r->height - l->height;

    // b가 음수일 수 있으니 양수로 만들어주기 위해 곱함
    if ( b * b < 2)
        return 1;     // 차가 2보다 작으면 balance 깨지지 x
    else
        return 0;

}

TreeNode* restructure(TreeType* T, TreeNode* x)
{
    TreeNode* y, * z, * a, * b, * c, * T0, * T1, * T2, * T3;

    y = x->parent;
    z = y->parent;

    // 총 4가지의 회전 경우의 수
    // 1. RR ( z < y < x : 다 오른쪽으로 붙어있을 때 )
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

    // 2. LL ( x < y < z : 다 왼쪽으로 붙어있을 때 )
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

    // z를 루트로 하는 부트리를 b 루트로 하는 부트리로 대체
    // a-b-c 구도로 갈 수 있게 b 를 루트로 하는 과정
    if (z == T->root)
    {
        T->root = b;
        b->parent = NULL;
    }
    // 왼쪽에 z 가 있으니 a-b-c 구도 위해 b를 왼쪽으로
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

    // T0과 T1 을 각각 a 의 왼쪽 및 오른쪽 부트리로 만들기
    a->left = T0;
    T0->parent = a;
    a->right = T1;
    T1->parent = a;
    a->height = max(T0->height, T1->height) + 1; // 개조 일어났으니 주의!
    
    // T2와 T3 을 각각 c 의 왼쪽 및 오른쪽 부트리로 만들기
    c->left = T2;
    T2->parent = c;
    c->right = T3;
    T3->parent = c;
    c->height = max(T2->height, T3->height) + 1;

    // a와 c 를 각각 b의 왼쪽 및 오른쪽 자식으로 만들기 
    b->left = a;
    a->parent = b;
    b->right = c;
    c->parent = b;
    b->height = max(a->height, c->height) + 1;

    // root 역할이 b 이니 b return
    return b;

}

void searchAndFixAfterInsertion(TreeType* T, TreeNode* w)
{
    TreeNode* z = w;  // 처음엔 삽입한 노드로 시작해서 거슬러올라갈것
    TreeNode* y, * x;

    // 1. 처음 만나는 불균형 노드 z 찾기
    // 높이 차 balance 가 1이 날라오는동안 계속 parent 거슬러올라가기
    while(heightUpdateAndBalanceCheck(z))
    {
        // root 까지 올라갔으면 그냥 return
        if( z == NULL )
            return;
        z = z->parent;
    }
    // 빠져나왔다면 불균형 발생
    
    // 2. z의 높은 자식 y 라고 하기
    if (z->left->height > z->right->height)
        y = z->left;
    else
        y = z->right;
    
    // 3. y의 높은 자식 x 라고 하기
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
        searchAndFixAfterInsertion(T, w);    // AVL tree 니까 추가
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

    if (g == NULL)        // 노드의 부모가 NULL 이면 내가 루트
    {
        T->root = zs;
    }
    else    // w 와 z 가 삭제된 이후 zs 를 g 의 왼,오 중 어디에 붙일지 결정
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


TreeNode* inOrderSucc(TreeNode* w)   // 중위계승자 찾기
{
    w = w->right;   // 먼저 오른자식간이후
    while(w->left != NULL)    // 왼쪽자식맨끝 외부노드
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

    // 1. w 에서 루트로 올라가다가 처음 만나는 불균형 노드 z
    while (heightUpdateAndBalanceCheck(z))
    {
        if (z==NULL)
            return;
        z = z->parent;
    }

    // 2. z의 높은 자식 y
    if (z->left->height > z->right->height)
        y = z->left;
    else
        y = z->right;

    // 3. y의 자식 x(높은 자식, 같으면 같은쪽 자식)
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

    // 5. 균형 잃은 노드 찾아 수리 반복
    // 삭제 후 1회 수리로 복구되지 못할 수도 있으니 한번 더 호출
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


void preOrder(TreeNode* root)   // 전위순회
{
    if (isExternal(root))
        return;            // 이게 없으면 모조노드까지 쓰레기값 출력됨
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

