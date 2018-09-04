#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int N, M , K;
    int v, w;
    int graph[201][201];
    scanf("%d%d", &N, &M);

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            graph[i][j] = 0;
        }
    }

    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &v, &w);
        graph[v][w] = graph[w][v] = 1;
    }

    int known[201];
    scanf("%d", &K);
    for(int i=0; i<K; i++)
    {
        int count;
        int iscorrect = 1;
        int cover_count = 0;
        int start_point;
        scanf("%d", &count);
        if(count == 0 || count == 1)
        {
            printf("NO\n");
            continue;
        }
        for(int j=1; j<=N; j++)
        {
            known[j] = 0;
        }
        scanf("%d", &v);
        start_point = v;
        known[v] = 1;
        cover_count++;
        for(int j=1; j<count; j++)
        {
            scanf("%d", &w);
            if(graph[v][w] == 0)
            {
                iscorrect = 0;
            }
            if(known[w] == 1 && j!=count-1)
            {
                iscorrect = 0;
            }
            if(known[w]!=1)
            {
            	known[w] = 1;
            	cover_count ++;	
			}
            v = w;
        }
        if(v!=start_point || cover_count != N)
        {
            iscorrect = 0;
        }
        if(iscorrect == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}
