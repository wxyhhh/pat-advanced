#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct node
{
    int time_cost;
    int dist;
    int known;
    int path;
    int fast_path;
    int count;
    int fast_count;
    int num;
}cities[500];

struct street
{
    int length;
    int time_cost;
}graph[500][500];

int N, M;
int getMinVertex(int mode)
{
    int choice = -1;
    int minvalue = INT_MAX;
    if(mode == 0)
    {
        for(int i=0; i<N; i++)
        {
            if(cities[i].known == 1)
            {
                continue;
            }
            if(cities[i].dist < minvalue)
            {
                minvalue = cities[i].dist;
                choice = i;
            }
        }
    }
    else{
        for(int i=0; i<N; i++)
        {
            if(cities[i].known == 1)
            {
                continue;
            }
            if(cities[i].time_cost < minvalue)
            {
                minvalue = cities[i].time_cost;
                choice = i;
            }
        }
    }

    return choice;
}

int main()
{
    int v, w;
    int oneway;
    int tmp_dist, tmp_time_cost;
    int src, dest;
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
    {
        cities[i].dist = INT_MAX;
        cities[i].time_cost = INT_MAX;
        cities[i].known = 0;
        cities[i].num = 0;
        cities[i].count = 0;
        cities[i].fast_count = 0;
        cities[i].num = 0;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            graph[i][j].length = -1;
        }
    }
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &v, &w);
        scanf("%d%d%d", &oneway, &tmp_dist, &tmp_time_cost);
        if(oneway == 1)
        {
            graph[v][w].length = tmp_dist;
            graph[v][w].time_cost = tmp_time_cost;
        }
        else
        {
            graph[v][w].length = graph[w][v].length = tmp_dist;
            graph[v][w].time_cost = graph[w][v].time_cost = tmp_time_cost;
        }
    }
    scanf("%d%d", &src, &dest);
    cities[src].dist = 0;
    cities[src].path = -1;
    cities[src].fast_path = -1;
    cities[src].time_cost = 0;
    cities[src].count = 1;
    cities[src].fast_count = 1;
    for(v=src; v!=-1; v=getMinVertex(0))
    {
        cities[v].known = 1;
        if(v == dest)
        {
            break;
        }
        for(int w=0; w<N; w++)
        {
            if(graph[v][w].length == -1)
            {
                continue;
            }
            if(cities[v].dist + graph[v][w].length < cities[w].dist)
            {
                cities[w].count = cities[v].count;
                cities[w].dist = cities[v].dist + graph[v][w].length;
                cities[w].path = v;
                cities[w].time_cost = cities[v].time_cost + graph[v][w].time_cost;
            }
            else if(cities[v].dist + graph[v][w].length == cities[w].dist)
            {
                cities[w].count += cities[v].count;
                if(cities[v].time_cost + graph[v][w].time_cost < cities[w].time_cost)
                {
                    cities[w].dist = cities[v].dist + graph[v][w].length;
                    cities[w].path = v;
                    cities[w].time_cost = cities[v].time_cost + graph[v][w].time_cost;
                }
            }
        }
    }

    for(int i=0; i<N; i++)
    {
        cities[i].time_cost = INT_MAX;
        cities[i].known = 0;
        cities[i].num = 0;
        cities[i].count = 0;
        cities[i].fast_count = 0;
        cities[i].num = 0;
    }
    cities[src].path = -1;
    cities[src].fast_path = -1;
    cities[src].time_cost = 0;
    cities[src].count = 1;
    cities[src].fast_count = 1;

    for(v=src; v!=-1; v=getMinVertex(1))
    {
        cities[v].known = 1;
        if(v == dest)
        {
            break;
        }
        for(int w=0; w<N; w++)
        {
            if(graph[v][w].length == -1)
            {
                continue;
            }
            if(cities[v].time_cost + graph[v][w].time_cost < cities[w].time_cost)
            {
                cities[w].fast_count = cities[v].fast_count;
                cities[w].time_cost = cities[v].time_cost + graph[v][w].time_cost;
                cities[w].fast_path = v;
                cities[w].num = cities[v].num+1;
            }
            else if(cities[v].time_cost + graph[v][w].time_cost == cities[w].time_cost)
            {
                cities[w].fast_count += cities[v].fast_count;
                if(cities[v].num + 1 < cities[w].num)
                {
                    cities[w].time_cost = cities[v].time_cost + graph[v][w].time_cost;
                    cities[w].fast_path = v;
                    cities[w].num = cities[v].num + 1;
                }
            }
        }
    }


    int distancepath[500];
    int dist_num=0;
    int timepath[500];
    int time_num=0;
    int isequal = 1;
    for(int i=cities[dest].path, j = cities[dest].fast_path;i!=-1&&j!=-1 ;i= cities[i].path, j=cities[j].fast_path)
    {
        if(i!=j)
        {
            isequal = 0;
            break;
        }
    }
    for(int i=cities[dest].path; i != src; i=cities[i].path)
    {
        distancepath[dist_num++] = i;
    }
    for(int i=cities[dest].fast_path; i != src; i=cities[i].fast_path)
    {
        timepath[time_num++] = i;
    }

    if(isequal == 1)
    {
        printf("Distance = %d; Time = %d: %d -> ", cities[dest].dist, cities[dest].time_cost, src);
        for(int i=dist_num-1; i>= 0; i--)
        {
            printf("%d -> ", distancepath[i]);
        }
        printf("%d", dest);
    }
    else
    {
        printf("Distance = %d: %d -> ", cities[dest].dist, src);
        for(int i=dist_num-1; i>= 0; i--)
        {
            printf("%d -> ", distancepath[i]);
        }
        printf("%d\n", dest);
        printf("Time = %d: %d -> ", cities[dest].time_cost, src);
        for(int i=time_num-1; i>= 0; i--)
        {
            printf("%d -> ", timepath[i]);
        }
        printf("%d", dest);
    }
    system("pause");
}