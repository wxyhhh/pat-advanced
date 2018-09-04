#include <stdlib.h>
#include <stdio.h>

int N;
int sequence[2000];

struct tree_node
{
    struct tree_node* left;
    struct tree_node* right;
    int value;
};

int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

struct tree_node* buildtree(int start, int end)
{
    if(start > end){
        return NULL;
    }
    struct tree_node* thisnode;
    thisnode = (struct tree_node*)malloc(sizeof(struct tree_node));
    int num = end-start+1;
    int left_num, right_num;
    int difference = 1;

    if(num == 1){
        thisnode->value = sequence[start];
        thisnode->left = thisnode->right = NULL;
        return thisnode;
    }
    int capacity = 2;
    while(capacity <= num){
        capacity *=2;
    }
    int last_level = capacity/2/2;
    capacity -= 1;

    for(int i=last_level*2+1; i<=num; i++){
        if(i-last_level*2<last_level){
            difference++;
        }
        else{
            difference--;
        }
    }
    left_num = (num-1+difference)/2;
    right_num = (num-1-difference)/2;

    thisnode->value = sequence[start+left_num];
    thisnode->left = buildtree(start, start+left_num-1);
    thisnode->right = buildtree(end-right_num+1,end);

    return thisnode;
}

void level_print(struct tree_node* root)
{
    struct tree_node* queue[2000];
    int front = 0;
    int rear = 0;

    queue[0] = root;
    rear++;

    while(front!=rear){
        int tmp = rear;
        for(int i=front; i<rear;i++){
            if(queue[i]!=NULL){
                if(i==0){
                    printf("%d", queue[i]->value);
                }
                else{
                    printf(" %d", queue[i]->value);
                }
                if(queue[i]->left != NULL){
                    queue[tmp++] = queue[i]->left;
                }
                if(queue[i]->right != NULL){
                    queue[tmp++] = queue[i]->right;
                }
            }
        }

        front = rear;
        rear = tmp;
    }
}


int main()
{
    struct tree_node* root;

    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &sequence[i]);
    }

    qsort(sequence, N, sizeof(int), comp);

    root = buildtree(0, N-1);

    level_print(root);

}