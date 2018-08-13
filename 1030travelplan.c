#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct city{
    int dist;
    int cost;
    int known;
    int path;
};
int N, M;

int getMinVertex(struct city* cities)
{
    int choice = -1;
    int current_dist = INT_MAX;
    for(int i=0; i<N; i++){
        if(cities[i].known != 1){
            if(cities[i].dist < current_dist){
                choice = i;
                current_dist = cities[i].dist;
            }
        }
    }

    return choice;
}

int main()
{
    int src, dst;
    struct city* cities;
    int dist[500][500];
    int cost[500][500];
    int *rout;
    int rout_length = 0;

    scanf("%d%d%d%d", &N, &M, &src, &dst);

    cities = (struct city*)malloc(N*sizeof(struct city));
    rout = (int*)malloc(N*sizeof(int));
    for(int i=0; i<N; i++)
    {
        cities[i].dist = INT_MAX;
        cities[i].cost = INT_MAX;
        cities[i].known = 0;
        cities[i].path = -1;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dist[i][j] = -1;
            cost[i][j] = -1;
        }
    }

    int tmp_cost, tmp_dist;
    int v, w;
    
    for(int i=0; i<M; i++){
        scanf("%d%d%d%d", &v, &w, &tmp_dist, &tmp_cost);
        dist[v][w] = dist[w][v] = tmp_dist;
        cost[v][w] = cost[w][v] = tmp_cost;
    }

    cities[src].dist = 0;
    cities[src].cost = 0;
    cities[src].known = 1;

    for(v = src; v != -1; v=getMinVertex(cities))
    {
        cities[v].known = 1;
        if(v == dst){
            break;
        }
        for(w = 0; w<N; w++){
            if(dist[v][w]>=0){
                if(cities[w].dist > cities[v].dist + dist[v][w]){
                    cities[w].dist = cities[v].dist + dist[v][w];
                    cities[w].cost = cities[v].cost + cost[v][w];
                    cities[w].path = v;
                }
                else if(cities[w].dist == cities[v].dist + dist[v][w]){
                    if(cities[w].cost > cities[v].cost + cost[v][w]){
                        cities[w].dist = cities[v].dist + dist[v][w];
                        cities[w].cost = cities[v].cost + cost[v][w];
                        cities[w].path = v;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    continue;
                }
            }
        }
    }

    int last = dst;
    while(last != -1){
        rout[rout_length++] = last;
        last = cities[last].path;
    }
    for(int i=rout_length-1; i>=0; i--){
        printf("%d ", rout[i]);
    }
    printf("%d %d", cities[dst].dist, cities[dst].cost);

    system("pause");

    return 0;

}