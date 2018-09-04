#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct tree_node
{
    int value;
    tree_node* left;
    tree_node* right;
};

void level_print(tree_node* root)
{
    vector<int>result;
    queue<tree_node*>Q;
    Q.push(root);

    while(Q.size()!=0)
    {
        tree_node* tmp = Q.front();
        Q.pop();
        if(tmp!=NULL)
        {
            result.push_back(tmp->value); 
            Q.push(tmp->left);
            Q.push(tmp->right);
        }
    }

    for(int i=0; i<result.size(); i++)
    {
        printf("%d", result[i]);
        if(i!=result.size()-1)
        {
            printf(" ");
        }
    }
}
vector<int>result;
void inorder_print(tree_node* root)
{
    if(root!=NULL)
    {
        inorder_print(root->left);
        result.push_back(root->value);
        inorder_print(root->right);
    }
}

int main()
{
    tree_node* root;
    tree_node* tree[10];
    int N;
    int ischild[10] = {0};
    char child1[2], child2[2];

    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        tree[i] = new tree_node;
        tree[i]->value = i;
    }
    for(int i=0; i<N; i++)
    {
        scanf("%s%s", child1, child2);
        if(child1[0] == '-')
        {
            tree[i]->right = NULL;
        }
        else
        {
            tree[i]->right = tree[child1[0]-'0'];
            ischild[child1[0]-'0'] = 1;
        }
        if(child2[0] == '-')
        {
            tree[i]->left = NULL;
        }
        else
        {
            tree[i]->left = tree[child2[0]-'0'];
            ischild[child2[0]-'0'] = 1;
        }
    }

    for(int i=0; i<N; i++)
    {
        if(ischild[i] == 0)
        {
            root = tree[i];
            break;
        }
    }


    level_print(root);
    printf("\n");
    inorder_print(root);
    for(int i=0; i<result.size(); i++)
    {
        printf("%d", result[i]);
        if(i!=result.size()-1)
        {
            printf(" ");
        }
    }
}
