#include <stdlib.h>
#include <stdio.h>

int preorder[1000];
int N;
int mode = 0;
int traverse_count = 0;

struct tree_node{
    int value;
    struct tree_node* left;
    struct tree_node* right;
};

void post_traverse( struct tree_node* root){
    if(root == NULL){
        return;
    }
    post_traverse(root->left);
    post_traverse(root->right);
    printf("%d", root->value);
    if(traverse_count != N-1){
        printf(" ");
        traverse_count ++;
    }
}

void free_tree(struct tree_node* root){
    if(root != NULL){
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int check_BST(struct tree_node** node, int root, int judge, int start, int end){
    int flag = 1;
    struct tree_node* thisnode;
    if(start > end){
        *node = NULL;
        return 1;
    }
    for(int i=start; i<=end; i++){
        if(judge == 0){
            if(preorder[i] >= root){
                flag = 0;
                return flag;
            }
        }
        else{
            if(preorder[i] < root){
                flag = 0;
                return flag;
            }
        }
    }
    
    if(flag == 1){
        thisnode = (struct tree_node*)malloc(sizeof(struct tree_node));
        thisnode->value = preorder[start];
        thisnode->left = NULL;
        thisnode->right = NULL;
        *node = thisnode;

        int mark = end;

        for(int i=start+1; i<=end; i++){
            if(mode == 0){
                if(preorder[i] >= preorder[start]){
                    mark = i-1;
                    break;
                }
            }
            else{
                if(preorder[i] < preorder[start]){
                    mark = i-1;
                    break;
                }
            }
        }

        if(mode == 0){
            return check_BST(&(thisnode->left), thisnode->value, 0, start+1, mark) && check_BST(&(thisnode->right), thisnode->value, 1, mark+1, end);
        }
        else{
            return check_BST(&(thisnode->left), thisnode->value, 1, start+1, mark) && check_BST(&(thisnode->right), thisnode->value, 0, mark+1, end);
        }
    }

}

int main()
{
    struct tree_node* root;
    int mark;
    int istree;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &preorder[i]);
    }
    root = (struct tree_node*)malloc(sizeof(struct tree_node));
    root->value = preorder[0];

    mark = N-1;
    for(int i=1; i<N; i++){
        if(preorder[i] >= preorder[0]){
            mark = i-1;
            break;
        }
    }
    if(check_BST(&(root->left), root->value, 0, 1, mark) && check_BST(&(root->right), root->value, 1, mark+1, N-1)){
        istree = 1;
    }
    else{
        //free_tree(root);
        root = (struct tree_node*)malloc(sizeof(struct tree_node));
        root->value = preorder[0];
        mode = 1;
        mark = N-1;
        for(int i=1; i<N; i++){
            if(preorder[i] < preorder[0]){
                mark = i-1;
                break;
            }
        }
        if(check_BST(&(root->left), root->value, 1, 1, mark) && check_BST(&(root->right), root->value, 0, mark+1, N-1)){
            istree = 1;
        }
        else{
            istree = 0;
        }
    }

    if(istree == 1){
        printf("YES\n");
        post_traverse(root);
    }
    else{
        printf("NO\n");
    }
    system("pause");
}