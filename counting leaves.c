#include <stdlib.h>
#include <stdio.h>

int ifleaf(int parent, int N, int tree[100][100])
{
    int flag = 1;
    for (int i = 0; i < N; i++)
    {
        if (tree[parent][i] == 1)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

void bfs(int tree[100][100], int N)
{
    int queue[100];
    int front = 0;
    int rear = 0;
    int leafnum, childrennum;
    int isleaf;
    int flag;

    rear = 1;
    queue[0] = 1;

    while (front != rear)
    {
        leafnum = 0;
        childrennum = 0;
        for (int i = front; i < rear; i++)
        {
            isleaf = 1;
            for (int j = 1; j < 1+N; j++)
            {
                if (tree[queue[i]][j] == 1)
                {
                    isleaf = 0;
                    queue[rear+childrennum] = j;
                    childrennum++;
                }
            }
            if(isleaf == 1){
                leafnum++;
            }
        }
        front = rear;
        rear += childrennum;
        if(front == rear)
            printf("%d", leafnum);
        else
            printf("%d ", leafnum);
    }
}

int main()
{
    int N, M;
    int id;
    int child;
    int K;
    int tree[100][100];

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            tree[i][j] = 0;
        }
    }
    scanf("%d%d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &id, &K);
        for (int j = 0; j < K; j++)
        {
            scanf("%d", &child);
            tree[id][child] = 1;
        }
    }

    bfs(tree, N);

    system("pause");
}