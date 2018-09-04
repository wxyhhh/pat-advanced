#include <stdlib.h>
#include <stdio.h>

struct tree_node
{
    int value;
    struct tree_node* left;
    struct tree_node* right;
};

typedef struct tree_node* tnode;

int height(tnode root){
    int a, b;
    if(root == NULL){
        return 0;
    }
    else{
        a = height(root->left);
        b = height(root->right);
        if(a>b){
            return a+1;
        }
        else{
            return b+1;
        }
    }
}

tnode LL(tnode root)
{
    tnode k;
    k = root->left;
    root->left = k->right;
    k->right = root;

    return k;
}

tnode RR(tnode root)
{
    tnode k;
    k = root->right;
    root->right = k->left;
    k->left = root;

    return k;
}

tnode LR(tnode root)
{
    root->left = RR(root->left);

    return LL(root);
}

tnode RL(tnode root)
{
    root->right = LL(root->right);

    return RR(root);
}

tnode insert(tnode root, int value){
    if(root == NULL){
        tnode newnode = (tnode)malloc(sizeof(struct tree_node));
        newnode->value = value;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    else if(value < root->value)
    {
        root->left = insert(root->left, value);
        if(height(root->left) - height(root->right) == 2){
            if(value > root->left->value){
                root = LR(root);
            }
            else{
                root = LL(root);
            }
        }
        return root;
    }

    else{
        root->right = insert(root->right, value);
        if(height(root->right) - height(root->left) == 2){
            if(value > root->right->value){
                root = RR(root);
            }
            else{
                root = RL(root);
            }
        }
        return root;
    }
}

int main()
{
    int N;
    int x;
    tnode root = NULL;

    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    if(N>0)
        printf("%d", root->value);
    
    system("pause");
}