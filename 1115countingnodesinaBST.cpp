#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>

using namespace std;

struct tree_node
{
    int value;
    tree_node* left;
    tree_node* right;
};

int N;
tree_node* root = NULL;
vector<int> levels;

void insert(int value, tree_node*&root)
{
    if(root == NULL)
    {
        root = new tree_node;
        root->value = value;
        root->left = root->right = NULL;
    }
    else
    {
        if(value <= root->value)
        {
            insert(value, root->left);
        }
        else
        {
            insert(value, root->right);
        }
    }
}

void calculate_level(tree_node* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<tree_node*>Q;
    Q.push(root);

    while(Q.size() != 0)
    {
        int count = Q.size();
        levels.push_back(count);

        for(int i=0; i<count; i++)
        {
            tree_node* tmp = Q.front();
            Q.pop();
            if(tmp->left != NULL)
            {
                Q.push(tmp->left);
            }
            if(tmp->right != NULL)
            {
                Q.push(tmp->right);
            }
        }
    }
}

int main()
{
    scanf("%d", &N);

    int x;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &x);
        insert(x, root);
    }
    
    calculate_level(root);

    if(levels.size() == 0)
    {
        printf("0 + 0 = 0");
    }
    else if(levels.size() == 1)
    {
        printf("1 + 0 = 1");
    }
    else
    {
        printf("%d + %d = %d", levels[levels.size()-1], levels[levels.size()-2], levels[levels.size()-1]+levels[levels.size()-2]);
    }
}
