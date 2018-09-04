#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
//下标是两位数！！！！！！！！！！！！！ 
using namespace std;
 
struct tree_node
{
    int value;
    tree_node* left;
    tree_node* right;
};
tree_node* tree[20];
int last_index;

int checkCBT(int root)
{
    queue<tree_node*>Q;
    Q.push(tree[root]);
    int stop = 0;
    
    while(Q.size()!=0)
    {
        tree_node* tmp = Q.front();
        Q.pop();
        last_index = tmp->value;
        if(stop == 1)
        {
            if(tmp->left != NULL || tmp->right !=NULL)
            {
                return 0;
            }
        }
        else
        {
            if(tmp->right != NULL && tmp->left == NULL)
            {
                return 0;
            }
            else if(tmp->right == NULL && tmp->left != NULL)
            {
                stop = 1;
                Q.push(tmp->left);
            }
            else if(tmp->right != NULL && tmp->left != NULL)
            {
                Q.push(tmp->left);
                Q.push(tmp->right);
            }
            else
            {
                stop = 1;
            }
        }
    }

    return 1;
}

int main()
{
    int N;
    char l[2], r[2];
    
    scanf("%d", &N);

    int ischild[20] = {0};
    int root;

    for(int i=0; i<N; i++)
    {
        tree[i] = new tree_node;
        tree[i]->value = i;
    }

    for(int i=0; i<N; i++)
    {
        scanf("%s%s", l, r);
        if(l[0]=='-')
        {
            tree[i]->left = NULL;
        }
        else
        {
        	int lindex;
			sscanf(l, "%d", &lindex);
            tree[i]->left = tree[lindex];
            ischild[lindex] = 1;
        }
        if(r[0]=='-')
        {
            tree[i]->right = NULL;
        }
        else
        {
        	int rindex;
			sscanf(r, "%d", &rindex);
            tree[i]->right = tree[rindex];
            ischild[rindex] = 1;
        }
    }

    for(int i=0; i<N; i++)
    {
        if(ischild[i] == 0)
        {
            root = i;
            break;
        }
    }
    int flag = checkCBT(root);

    if(flag)
    {
        printf("YES %d", last_index);
    }
    else
    {
        printf("NO %d", root);
    }
    printf("\n");
}
