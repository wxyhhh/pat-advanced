#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct tree_node
{
    int value;
    tree_node* left;
    tree_node* right;
};

int N;
int number[100];
int index = 0;

void inorder(tree_node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    root->value = number[index++];
    inorder(root->right);
}

void levelorder(tree_node* root)
{
    vector <int> level_number;
    queue<tree_node*> Q;
    Q.push(root);

    while(Q.size()!=0)
    {
        tree_node* tmp = Q.front();
        Q.pop();
        if(tmp == NULL)
        {
            continue;
        }
        else
        {
            level_number.push_back(tmp->value);
            Q.push(tmp->left);
            Q.push(tmp->right);
        }
    }

    for(int i=0; i<level_number.size(); i++)
    {
        printf("%d", level_number[i]);
        if(i!=level_number.size()-1)
        {
            printf(" ");
        }
    }
}

int main()
{
    scanf("%d", &N);

    int child1, child2;
    tree_node* tree[100];
    
    for(int i=0; i<N; i++)
	{
		tree[i] = new tree_node;
	}
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &child1, &child2);
        if(child1 != -1)
        {
            tree[i]->left = tree[child1];
        }
        else
        {
            tree[i]->left = NULL;
        }
        if(child2 != -1)
        {
            tree[i]->right = tree[child2];
        }
        else
        {
            tree[i]->right = NULL;
        }
        
    }
    
    for(int i=0; i<N; i++)
    {
        scanf("%d", &number[i]);
    }

    sort(number, number+N);

    inorder(tree[0]);

    levelorder(tree[0]);
}
