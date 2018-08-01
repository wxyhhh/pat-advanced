#include <stdlib.h>
#include <stdio.h>
int N, M, K;
int visited[1000];
int Map[1000][1000];

void dfs(int citynum){
    for(int i=1; i<=N; i++){
        if(visited[i]==0 && Map[citynum][i]==1){
            visited[i] = 1;
            dfs(i);
        }
    }
}


int main()
{
    int destroyed;

    scanf("%d%d%d", &N, &M, &K);
    for(int i=1; i<=N; i++){
        visited[i] = 0;
        for(int j=1; j<=N; j++){
            Map[i][j] = 0;
        }
    }
    
    for(int i=0; i<M; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        Map[u][v] = Map[v][u] = 1;
    }

    for(int i=0; i<K; i++){
        int count = 0;
        for(int j=1; j<=N; j++){
            visited[j] = 0;
        }
        scanf("%d", &destroyed);
        visited[destroyed] = 1;

        for(int j=1; j<=N; j++){
            if(visited[j] == 0){
                visited[j] = 1;
                dfs(j);
                count++;
            }
        }

        printf("%d", count-1);

        if(i!=K-1){
            printf("\n");
        }
    }

    system("pause");
}