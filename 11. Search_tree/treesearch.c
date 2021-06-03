#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int key;
    struct TreeNode* parent, * left, * right;
}TreeNode;
// 여기서 root 선언해도 되지만 그럼 root 변경시마다
// 계속 root return 해주어야하기 때문에 따로 TreeType 만들기

typedef struct
{
    TreeNode *root;
}TreeType;

void initTree(TreeType* T)
{
    // root 를 위해 memory 할당받기
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
        return v;        // external 이면 그대로 위치 리턴
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

int findElement(TreeType* T, int k)
{
    TreeNode* w = treeSearch(T->root, k);

    if (isExternal(w))
        return 0;
    else
        return w->key;
}

TreeNode* inOrderSucc(TreeNode* w)   // 중위계승자 찾기
{
    w = w->right;   // 먼저 오른자식간이후
    while(w->left != NULL)    // 왼쪽자식맨끝 외부노드
        w = w->left;
    return w;
}

int removeElement(TreeType* T, int k)
{
    TreeNode* w = treeSearch(T->root, k);

    if (isExternal(w))
        return 0;
    
    // 삭제되는키를 가진 노드 w
    // w 의 중위순회 계승자 y
    // y 의 자식노드 z or w의 외부노드 자식 z
    TreeNode* z, * y;
    z = w->left;       // 일단 z 가 왼쪽 자식

    // case 1
    if(!isExternal(z))  // 왼쪽자식이 외부노드가아니면
        z = w->right;   // 오른쪽자식이 외부노드
    if(isExternal(z))
        reduceExternal(T, z);
    // case 2
    else                // 왼쪽 오른쪽자식 모두 외부노드
    {
        // 중위계승자 z 찾기
        z = inOrderSucc(w);
        y = z->parent; 
        w->key = y->key;
        reduceExternal(T, z);
    }
    return k;
}

void insertItem(TreeType* T, int k)
{
    // 삽입 전에 일단 해당 key 가 존재하는지 탐색(중복키허용x)
    TreeNode* w = treeSearch(T->root, k);
    if (!isExternal(w))    // isInternal 대신 사용
        return;
    else
    {
        w->key = k;
        expandExternal(w);   // w 를 내부노드로 확장
    }
}

void preOrder(TreeNode* root)   // 전위순회
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

    printf("삭제할 키 입력 : ");
    int key;
    scanf("%d", &key);
    removeElement(T, key);
    preOrder(T->root); printf("\n");

    return 0;

}