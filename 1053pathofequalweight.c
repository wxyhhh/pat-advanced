#include <stdlib.h>
#include <stdio.h>

int weight[100];
int children[100][100];
int children_num[100];
int path[100];
int path_length = 0;
int node_num, non_leaf_num, given;

int comp(const void* a, const void *b)
{
    int weighta = weight[*(int*)a];
    int weightb = weight[*(int*)b];

    return weightb - weighta;
}

void dfs(int current_weight, int current_node)
{
    current_weight += weight[current_node];
    if(current_weight > given){
        return;
    }
    else if(current_weight == given && children_num[current_node] == 0){
        path[path_length++] = current_node;
        printf("%d", weight[path[0]]);
        for(int i=1; i<path_length; i++){
            printf(" %d", weight[path[i]]);
        }
        printf("\n");

        path_length--;
    }
    else{
        if(children_num[current_node] == 0){
            return;
        }
        path[path_length++] = current_node;
        for(int i=0; i<children_num[current_node]; i++){
            dfs(current_weight, children[current_node][i]);
        }
        path_length --;
    }
}

int main()
{


    scanf("%d%d%d", &node_num, &non_leaf_num, &given);

    for(int i=0; i<node_num; i++)
    {
        scanf("%d", &weight[i]);
        children_num[i] = 0;
    }

    for(int i=0; i<non_leaf_num; i++){
        int node;
        int num;
        scanf("%d%d", &node, &num);
        for(int j=0; j<num; j++)
        {
            scanf("%d", &children[node][j]);
        }
        children_num[node] = num;

        qsort(children[node], num, sizeof(int), comp);
    }

    dfs(0, 0);

    system("pause");
}