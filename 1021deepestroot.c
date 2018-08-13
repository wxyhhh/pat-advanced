#include <stdlib.h>
#include <stdio.h>

int max_length = 0;
int* deepest_root;
int* tmp;
int tmp_num = 0;
int deepest_num = 0;
struct tree_node* map;
int* known;

struct tree_node
{
    int* adjacent_list;
    int count;
};

int comp(const void*a, const void*b){
    return *(int*)a - *(int*)b;
}
void dfs(int node, int current_length){
    int flag = 1;
    known[node] = 1;
    for(int i=0; i<map[node].count; i++){
        if(known[map[node].adjacent_list[i]]==0){
            dfs(map[node].adjacent_list[i], current_length+1);
            flag = 0;
        }
    }
    if(flag == 0){
        return;
    }
    if(current_length +1 > max_length){
        deepest_num = 0;
        deepest_root[0] = node;
        deepest_num++;
        max_length = current_length+1;
    }
    else if(current_length +1 == max_length){
        deepest_root[deepest_num] = node;
        deepest_num++;
    }
}

int main()
{
    int N;
    int v, w;
    int components = 0;

    scanf("%d", &N);

    map = (struct tree_node*)malloc((N+1)*sizeof(*map));
    known = (int*)malloc((N+1)*sizeof(int));
    deepest_root = (int*)malloc((N+1)*sizeof(int));
    tmp = (int*)malloc((N+1)*sizeof(int));

    for(int i=1; i<=N; i++){
        map[i].adjacent_list = (int*)malloc(N*sizeof(int));
        map[i].count = 0;
        known[i] = 0;
    }
    for(int i=0; i<N-1; i++){
        scanf("%d%d", &v, &w);
        map[v].adjacent_list[map[v].count] = w;
        map[v].count++;
        map[w].adjacent_list[map[w].count] = v;
        map[w].count++;  
    }

    for(int i=1; i<=N; i++){
        if(known[i]==0){
            components++;
            dfs(i, 0);
        }
    }

    if(components>1){
                printf("Error: %d components", components);
                system("pause");
                return 0;
            }

    for(int i=1; i<=N; i++){
        known[i] = 0;
    }
    for(int i=0; i<deepest_num; i++){
        tmp[i] = deepest_root[i];
    }
    tmp_num = deepest_num;

    dfs(deepest_root[0], 0);

    for(int i= deepest_num; i<deepest_num+tmp_num; i++){
        deepest_root[i] = tmp[i-deepest_num];
    }
    deepest_num += tmp_num;
    qsort(deepest_root, deepest_num, sizeof(int), comp);

    for(int i=0; i<deepest_num; i++){
        if(i ==0 || deepest_root[i]!=deepest_root[i-1]){
            printf("%d", deepest_root[i]);
            if(i != deepest_num-1){
            printf("\n");
        }
        }
    }
    system("pause");
    return 0;

}