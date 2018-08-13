#include <stdlib.h>
#include <stdio.h>

int post[30];
int in[30];

struct tree_node{
    int value;
    struct tree_node* left;
    struct tree_node* right;
};

typedef struct tree_node* Tnode;

Tnode buildtree(int post_start, int post_end, int in_start, int in_end){
    Tnode result;
    int root_index;
    if(post_start > post_end || in_start>in_end){
        return NULL;
    }

    result = (Tnode)malloc(sizeof(*result));

    result->value = post[post_end];
    if(post_start == post_end){
        result->left = NULL;
        result->right = NULL;
        return result;
    }
    for(int i=in_start; i<=in_end; i++){
        if(in[i] == post[post_end]){
            root_index = i;
            break;
        }
    }
    result->left = buildtree(post_start, post_start+(root_index-in_start)-1, in_start, root_index-1);
    result->right = buildtree(post_start+(root_index-in_start), post_end-1, root_index+1, in_end);
    return result;
}

void print_level(Tnode root){
    Tnode queue[30];

    int front = 0;
    int rear = 0;

    queue[0] = root;
    rear++;
    if(root == NULL){
        return;
    }
    else{
        printf("%d", root->value);
    }
    while(front != rear){
        int tmp_rear = rear;
        for(int i=front; i < rear; i++){
            if(queue[i]!= NULL){
                if(i!=0)
                    printf(" %d", queue[i]->value);
                if(queue[i]->left!= NULL)
                    queue[tmp_rear++] = queue[i]->left;
                if(queue[i]->right!= NULL)
                    queue[tmp_rear++] = queue[i]->right;
            }
        }

        front = rear;
        rear = tmp_rear;
    }
}

int main()
{
    int N;
    Tnode root;

    scanf("%d", &N);

    for(int i=0; i< N; i++){
        scanf("%d", &post[i]);
    }
    for(int i=0; i< N; i++){
        scanf("%d", &in[i]);
    }

    root = buildtree(0, N-1, 0, N-1);

    print_level(root);

    system("pause");
}

