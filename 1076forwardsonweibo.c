#include <stdlib.h>
#include <stdio.h>
int N, depth;
int M[1001];
int follower[1001][1000];
int known[1001];

int bfs(int user)
{
    int c_depth = 0;
    int count = 0;
    int queue[1001];
    int front = 0;
    int rear = 0;

    queue[0] = user;
    rear ++;
    while(front != rear)
    {
        int tmp = rear;

        for(int i=front; i<rear; i++)
        {
            int c_user = queue[i];
            for(int j = 0; j<M[c_user]; j++)
            {
                if(known[follower[c_user][j]] != 1){
                    queue[tmp++] = follower[c_user][j];
                    known[follower[c_user][j]] = 1;
                    count ++;
                }
            }
        }
        c_depth ++;
        front = rear;
        rear = tmp;
        if(c_depth == depth){
            break;
        }
    }

    return count;
}

int main()
{
    int follow_num;
    int tmp;
    int query_num;

    scanf("%d%d", &N, &depth);

    for(int i=1; i<=1000; i++)
    {
        M[i] = 0;
    }
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &follow_num);
        for(int j=0; j<follow_num; j++)
        {
            scanf("%d", &tmp);
            follower[tmp][M[tmp]++] = i;
        }
    }

    scanf("%d", &query_num);

    for(int i=0; i<query_num; i++)
    {
        int count = 0;
        scanf("%d", &tmp);
        for(int j=1; j<=N; j++)
        {
            known[j] = 0;
        }
        known[tmp] = 1;
        printf("%d\n", bfs(tmp));
    }

    system("pause");
}