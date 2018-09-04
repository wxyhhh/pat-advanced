#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

struct tree_node
{
    int value;
    tree_node* left;
    tree_node* right;
};

int height(tree_node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int a = height(root->left);
    int b = height(root->right);

    if(a>b)
    {
        return a+1;
    }
    else
    {
        return b+1;
    }
}

tree_node* LL(tree_node* root)
{
    tree_node* tmp = root->left;
    root->left = root->left->right;
    tmp->right = root;

    return tmp;
}

tree_node* RR(tree_node* root)
{
    tree_node* tmp = root->right;
    root->right = root->right->left;
    tmp->left = root;

    return tmp;
}

tree_node* LR(tree_node* root)
{
    root->left = RR(root->left);

    return LL(root);
}

tree_node* RL(tree_node* root)
{
    root->right = LL(root->right);

    return RR(root);
}

tree_node* insert(int value, tree_node* root)
{
    if(root == NULL)
    {
        tree_node* tmp = new tree_node;
        tmp->value = value;
        tmp->left = tmp->right = NULL;
        return tmp;
    }
    else
    {
        if(value <= root->value)
        {
            root->left = insert(value, root->left);
            if(height(root->left) - height(root->right) > 1)
            {
                if(value <=root->left->value)
                {
                    root = LL(root);
                }
                else
                {
                    root = LR(root);
                }
            }
            return root;
        }
        else
        {
            root->right = insert(value, root->right);
            if(height(root->right) - height(root->left) > 1)
            {
                if(value <=root->right->value)
                {
                    root = RL(root);
                }
                else
                {
                    root = RR(root);
                }
            }
            return root;
        }
    }
}
bool isCBT = true;
vector<int>levels;
void level_print(tree_node* root)
{
    queue<tree_node*>Q;
    bool stop = false;
    if(root == NULL)
    {
        return;
    }

    Q.push(root);

    while(Q.size()!=0)
    {
        tree_node* tmp = Q.front();
        Q.pop();
        levels.push_back(tmp->value);
        if(tmp->left == NULL && tmp->right != NULL)
        {
            isCBT = false;
            stop = true;
            Q.push(tmp->right);
        }
        else if(tmp->left == NULL && tmp->right == NULL)
        {
            stop = true;
        }
        else if(tmp->left != NULL && tmp->right == NULL)
        {
            if(stop ==true)
            {
                isCBT = false;
            }
            else
            {
                stop = true;
            }
            Q.push(tmp->left);
        }
        else
        {
            if(stop == true)
            {
                isCBT = false;
            }
            Q.push(tmp->left);
            Q.push(tmp->right);
        }
    }
}

int main()
{
    int N, x;
    tree_node* root = NULL;
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &x);
        root = insert(x, root);
    }

    level_print(root);

    for(int i=0; i<levels.size(); i++)
    {
        printf("%d", levels[i]);
        if(i!=levels.size()-1)
        {
            printf(" ");
        }
    }
    printf("\n");
    if(isCBT)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
