#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

int map[1100][1100];

struct house
{
    int dist;
    int known;
};

struct station
{
    int index;
    double avg_dist;
    double min_dist;
};

struct house houses[1100];
struct station stations[15];
int station_num = 0;
int N, M;

int comp(const void*a, const void*b)
{
    struct station stationa = *(struct station*)a;
    struct station stationb = *(struct station*)b;

    if(stationa.min_dist != stationb.min_dist)
    {
        return stationb.min_dist - stationa.min_dist;
    }
    else if(stationa.avg_dist != stationb.avg_dist)
    {
        if(stationa.avg_dist > stationb.avg_dist){
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        return stationa.index - stationb.index;
    }
}

int getMinVertex()
{
    int choice = -1;
    int min_dist = INT_MAX;
    for(int i=1; i<=N; i++)
    {
        if(houses[i].known == 0){
            if(houses[i].dist < min_dist){
                choice = i;
                min_dist = houses[i].dist;
            }
        }
    }

    for(int i=1001; i<=1000+M; i++)
    {
        if(houses[i].known == 0){
            if(houses[i].dist < min_dist){
                choice = i;
                min_dist = houses[i].dist;
            }
        }
    }

    return choice;
}

int main()
{
    int length;
    char v_str[5];
    char w_str[5];
    int v, w;
    int range;
    int edge_num;

    scanf("%d%d%d%d", &N, &M, &edge_num, &range);

    for(int i=1; i<=1000+M; i++)
    {
        for(int j=1; j<=1000+M; j++)
        {
            map[i][j] = -1;
        }
    }


    for(int i=0; i<edge_num; i++)
    {
        scanf("%s%s%d", v_str, w_str, &length);
        int l=strlen(v_str);
        int sum=0;
        if(v_str[0] == 'G')
        {
            for(int j=1; j<l; j++){
                sum = sum*10+(v_str[j]-'0');
            }
            v = 1000+sum;
        }
        else{
            for(int j=0; j<l; j++){
                sum = sum*10+(v_str[j]-'0');
            }
            v = sum;
        }
        l = strlen(w_str);
        sum = 0;
        if(w_str[0] == 'G')
        {
            for(int j=1; j<l; j++){
                sum = sum*10+(w_str[j]-'0');
            }
            w = 1000+sum;
        }
        else{
            for(int j=0; j<l; j++){
                sum = sum*10+(w_str[j]-'0');
            }
            w = sum;
        }
        map[v][w] = map[w][v] = length;
    }

    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=1000+M; j++)
        {
            houses[j].dist = INT_MAX;
            houses[j].known = 0;
        }

        houses[1000+i].known = 1;
        for(int j=1; j<=N; j++){
            if(map[1000+i][j]>=0){
                houses[j].dist = map[1000+i][j];
            }
        }
        for(int j=1001; j<=1000+M; j++){
            if(map[1000+i][j]>=0){
                houses[j].dist = map[1000+i][j];
            }
        }
        int dist_sum = 0;
        int min_dist = INT_MAX;
        int flag = 1;
        for(v=getMinVertex(); v!=-1; v=getMinVertex())
        {
            houses[v].known = 1;
            // if(houses[v].dist > range && v<=N)
            // {
            //     flag = 0;
            //     break;
            // }
            // else{
            //     if(v<=N){
            //         dist_sum += houses[v].dist;
            //         if(houses[v].dist < min_dist){
            //         min_dist = houses[v].dist;
            //     }
            //     }
            // }
            for(int w=1; w<=N; w++)
            {
                if(map[v][w] >= 0)
                {
                    if(houses[v].dist + map[v][w] < houses[w].dist){
                        houses[w].dist = houses[v].dist + map[v][w];
                    }
                }
            }
            for(int w=1001; w<=1000+M; w++){
                if(map[v][w] >= 0)
                {
                    if(houses[v].dist + map[v][w] < houses[w].dist){
                        houses[w].dist = houses[v].dist + map[v][w];
                    }
                }
            }
        }
        for(int j=1; j<=N; j++){
            if(houses[j].dist > range){
                flag = 0;
                break;
            }
            dist_sum += houses[j].dist;
            if(houses[j].dist < min_dist){
                min_dist = houses[j].dist;
            }
        }
        if(flag == 1){
            stations[station_num].index = i;
            stations[station_num].avg_dist = (double)dist_sum / N;
            stations[station_num++].min_dist = min_dist;
        }
    }

    qsort(stations, station_num, sizeof(struct station), comp);
    if(station_num == 0)
    {
        printf("No Solution");
    }
    else{
        printf("G%d\n%.1lf %.1lf", stations[0].index, stations[0].min_dist, stations[0].avg_dist);
    }
    system("pause");
}