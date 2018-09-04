//并查集 路径压缩
//题目印刷出错。。

#include <stdlib.h>
#include <stdio.h>

int disjoint[10001];
int birds[10001];

int find(int x)
{
    if(disjoint[x] < 0)
    {
        return x;
    }
    else
    {
        return disjoint[x] = find(disjoint[x]);
    }
}

void Union(int x, int y)
{
    int a = find(x);
    int b = find(y);

    if(disjoint[a] < disjoint[b])
    {
        disjoint[a] += disjoint[b];
        disjoint[b] = a;
    }
    else
    {
        disjoint[b] += disjoint[a];
        disjoint[a] = b;
    }
}

int main()
{
    for(int i=0; i<10001; i++)
    {
        disjoint[i] = -1;
        birds[i] = 0;
    }
    int N, K, count;
    int x, bird;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &count);
        if(count == 0)
        {
            continue;
        }
        scanf("%d", &x);
        if(birds[x]==0)
        {
            birds[x] = 1;
        }
        for(int j=1; j<count; j++)
        {
            scanf("%d", &bird);
            if(birds[bird]==0)
            {
                birds[bird] = 1;
            }
            Union(x, bird);
        }
    }

    int tree_num=0, bird_num=0;
    for(int i=1; i<=10000; i++)
    {

        if(disjoint[i] <= -1 && birds[i] == 1)
        {
            tree_num++;
        }
        if(birds[i] == 1)
        {
            bird_num++;
        }
    }

    printf("%d %d\n", tree_num, bird_num);

    scanf("%d", &K);
    for(int i=0; i<K; i++)
    {
        int first, second;
        scanf("%d%d", &first, &second);
        if(find(first) == find(second))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    system("pause");
}