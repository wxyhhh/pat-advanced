#include <stdlib.h>
#include <stdio.h>


//贪心算法

struct station{
  double price;
  double position;  
};

int comp(const void*a, const void* b)
{
    return (*(struct station*)a).position - (*(struct station*)b).position;
}

int main()
{
    struct station stations[500];
    double tank_capacity;
    double total_distance;
    double distance_per_unit;
    int station_num;

    scanf("%lf%lf%lf%d", &tank_capacity, &total_distance, &distance_per_unit, &station_num);

    for(int i=0; i<station_num; i++){
        scanf("%lf%lf", &stations[i].price, &stations[i].position);
    }

    qsort(stations, station_num, sizeof(struct station), comp);
    
    if(stations[0].position != 0){
        if(total_distance == 0){
            printf("0.00");
        }
        else{
            printf("The maximum travel distance = 0.00");
        }

        system("pause");
        return 0;
    }

    double current_gas = 0;
    double current_distance = 0;
    int current_station = 0;
    double current_price = stations[current_station].price;
    double total_price = 0;
    while(current_distance < total_distance)
    {
        int next_station;
        double next_distance;
        int cheaper_flag = 0;
        int min_flag = 0;

        double tmp_min_price = -1;
        for(int i=current_station+1; i < station_num && stations[i].position <= current_distance + tank_capacity * distance_per_unit; i++){
            if(stations[i].price < current_price){
                next_station = i;
                next_distance = stations[i].position;
                cheaper_flag = 1;
                break;
            }
            else if(stations[i].price < tmp_min_price ||tmp_min_price < 0){
                next_station = i;
                next_distance = stations[i].position;
                min_flag = 1;
                tmp_min_price = stations[i].price;
            }
            else{
                continue;
            }
        }

        if(cheaper_flag){
            total_price += ((next_distance - current_distance) / distance_per_unit -current_gas) *current_price;
            current_gas = 0;
            current_price = stations[next_station].price;
            current_station = next_station;
            current_distance = next_distance;
        }
        else if(min_flag && current_distance + tank_capacity * distance_per_unit < total_distance){
            total_price += (tank_capacity - current_gas) * current_price;
            current_gas = tank_capacity - (next_distance - current_distance) / distance_per_unit;
            current_price = stations[next_station].price;
            current_station = next_station;
            current_distance = next_distance;
        }
        else if(min_flag && current_distance + tank_capacity * distance_per_unit >= total_distance){
            total_price += ((total_distance - current_distance)/distance_per_unit - current_gas) * current_price;
            printf("%.2lf", total_price);
            break;
        }
        else{
            if(current_distance + current_gas * distance_per_unit >= total_distance){
                printf("%.2lf", total_price);
                break;
            }
            else if(current_distance + tank_capacity * distance_per_unit >= total_distance){
                total_price += ((total_distance - current_distance)/distance_per_unit - current_gas) * current_price;
                printf("%.2lf", total_price);
                break;
            }
            else{
                printf("The maximum travel distance = %.2lf", current_distance + tank_capacity * distance_per_unit);
                break;
            }
        }
    }

    system("pause");
}