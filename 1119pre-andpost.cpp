#include <iostream>
#include <vector>
using namespace std;
int pre[30];
int post[30];
int N;
int flag = 0;

struct tree_node
{
    int value;
    tree_node* left;
    tree_node* right;
};

tree_node* buildtree(int pre_start, int pre_end, int post_start, int post_end)
{
    if(pre_start > pre_end)
    {
        return NULL;
    }
    tree_node* root = new tree_node;
    root->value = pre[pre_start];
    root->left = root->right = NULL;
    if(pre_start == pre_end)
    {
        return root;
    }
    int i = pre_start+1;
    if(pre[pre_start+1] == post[post_end-1])
    {
        flag = 1;
        root->left = buildtree(pre_start+1, pre_end, post_start, post_end-1);
        root->right = NULL;
        return root;
    }
    else
    {
        for(;i<=pre_end; i++)
        {
            if(pre[i] == post[post_end-1])
            {
                break;
            }
        }
        int left_count = i-(pre_start+1);
        int right_count = pre_end-i+1;
        root->left = buildtree(pre_start+1, i-1, post_start, post_start+left_count-1);
        root->right = buildtree(i, pre_end, post_end-right_count, post_end-1);

        return root;
    }
}
vector<int>inorder;
void inorder_traversal(tree_node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    inorder.push_back(root->value);
    inorder_traversal(root->right);
}

int main()
{
    tree_node* root;  
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &pre[i]);
    }

    for(int i=0; i<N; i++)
    {
        scanf("%d", &post[i]);
    }

    root = buildtree(0, N-1, 0, N-1);

    inorder_traversal(root);

    if(flag)
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }
    printf("\n");
    for(int i=0; i<inorder.size(); i++)
    {
        printf("%d", inorder[i]);
        if(i!=inorder.size()-1)
        {
            printf(" ");
        }
    }

    printf("\n");
}
