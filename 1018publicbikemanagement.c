#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int Vnum, Enum;
int Graph[501][501];
struct node* stations;
int max_capacity;

int best_path[501];
int best_send_bike = -1;
int best_fetch_bike = -1;
int best_station_num = 0;
int current_path[501];

struct node
{
    int known;
    int dist;
    int path[501];
    int bike_need;
    int bike_init;
    int count;
};

void dfs(int station, int current_station_num){
    if(station == 0){
        int carry_bikes = 0;
        int current_send = 0;
        for(int i=current_station_num-1; i>=0; i--){
            if (stations[current_path[i]].bike_init > max_capacity / 2)
            {
                carry_bikes += stations[current_path[i]].bike_init - max_capacity / 2;
            }
            else
            {
                if(carry_bikes >= max_capacity/2 - stations[current_path[i]].bike_init){
                    carry_bikes -= max_capacity/2 - stations[current_path[i]].bike_init;
                }
                else{
                    current_send += max_capacity/2 - stations[current_path[i]].bike_init - carry_bikes; 
                    carry_bikes = 0;
                }
            }
        }
        if(current_send < best_send_bike || best_send_bike == -1){
            best_send_bike = current_send;
            best_fetch_bike = carry_bikes;
            for(int i=0; i<current_station_num; i++){
                best_path[i] = current_path[i];
            }
            best_station_num = current_station_num;
        }
        else if(current_send == best_send_bike){
            if(carry_bikes < best_fetch_bike){
                best_send_bike = current_send;
                best_fetch_bike = carry_bikes;
                for(int i=0; i<current_station_num; i++){
                    best_path[i] = current_path[i];
                }
                best_station_num = current_station_num;
            }
        }
        return;
    }
    else{
        current_path[current_station_num] = station;

        for(int i=0; i < stations[station].count; i++){
            dfs(stations[station].path[i], current_station_num+1);
        }
        return;
    }
}

int getMinVertex(struct node *T){
	int min_dist = INT_MAX;
	int choice = -1;
	
	for(int i = 1; i <= Vnum; i++){
		if(T[i].known == 0){
			if(T[i].dist <= min_dist){
				choice = i;
				min_dist = T[i].dist;
			}
			else{
				continue;
			}
		}
		else{
			continue;
		}
	}
	
	return choice;
}

int main()
{
    int target_station;
    int v, w;
    int length;


    scanf("%d%d%d%d", &max_capacity, &Vnum, &target_station, &Enum);
    stations = (struct node*)malloc((Vnum+1) * sizeof(*stations));

    for(int i=1; i<=Vnum; i++){
        scanf("%d", &stations[i].bike_init);
        stations[i].known = 0;
        stations[i].dist = INT_MAX;
        stations[i].path[0] = -1;
        stations[i].count = 0;
        stations[i].bike_need = max_capacity/2 - stations[i].bike_init;
    }

    stations[0].bike_init = 0;
    stations[0].bike_need = 0;
    stations[0].path[0] = -1;
    stations[0].dist = 0;
    stations[0].count = 0;

    for(int i = 0; i <= Vnum; i++){
		for(int j = 0; j <= Vnum; j++){
			Graph[i][j] = -1;
		}
	}
    for(int i=0; i< Enum; i++){
        scanf("%d%d%d", &v, &w, &length);
        Graph[v][w] = Graph[w][v] = length;
    }


    for(v = 0; v!=-1; v = getMinVertex(stations)){
        stations[v].known = 1;
        if(v == target_station){
            break;
        }
        for(int w=1; w<=Vnum; w++){
            if(stations[w].known == 0){
                if(Graph[v][w] >= 0){
                if(Graph[v][w] + stations[v].dist < stations[w].dist){
                    stations[w].dist = Graph[v][w] + stations[v].dist;
                    stations[w].path[0] = v;
                    stations[w].count = 1;
                }
                else if(Graph[v][w] + stations[v].dist == stations[w].dist){
                    stations[w].path[stations[w].count] = v;
                    stations[w].count ++;
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

    dfs(target_station, 0);

    printf("%d 0", best_send_bike);
    for(int i=best_station_num-1; i>=0; i--)
    {
        printf("->%d", best_path[i]);
    }
    printf(" %d", best_fetch_bike);

    system("pause");
}