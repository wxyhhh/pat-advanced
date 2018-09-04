#include <stdlib.h>
#include <stdio.h>

int post[30];
int count = 0;
int N;
int inst_num = 0;

struct tree_node
{
    int value;
    struct tree_node* left;
    struct tree_node* right;
};

struct tree_node* buildtree()
{
    char inst[5];
    int value;
    struct tree_node* node;
    
    if(inst_num < N*2)
    {
        inst_num++;
        scanf("%s", inst);
        if(inst[1] == 'u')
        {
            scanf("%d", &value);
            node = (struct tree_node*)malloc(sizeof(struct tree_node));
            node->left = node->right = NULL;
            node->value = value;
            node->left = buildtree();
            node->right = buildtree();

            return node;
        }
        else{
            node = NULL;
            return node;
        }
    }

    else{
        return NULL;
    }
    
}

void post_order(struct tree_node* root)
{
    if(root == NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    post[count++] = root->value;

}

int main()
{
    struct tree_node* root = NULL;
    scanf("%d", &N);
    root = buildtree();

    post_order(root);

    for(int i=0; i<N; i++)
    {
        printf("%d", post[i]);
        if(i!=N-1)
        {
            printf(" ");
        }
    }

    system("pause");
}