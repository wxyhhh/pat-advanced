#include <stdlib.h>
#include <stdio.h>

int main()
{
    char result[3] = "WTL";
    double odds[3];
    double profit = 1;

    for(int i=0; i<3;i++){
        scanf("%lf%lf%lf", &odds[0], &odds[1], &odds[2]);
        double max_odd = odds[0];
        int choice = 0;
        if(odds[1] > max_odd){
            max_odd = odds[1];
            choice = 1;
        }
        if(odds[2] > max_odd){
            max_odd = odds[2];
            choice = 2;
        }

        profit *= max_odd;
        printf("%c ", result[choice]);
    }

    profit = (profit * 0.65 - 1) * 2;
    printf("%.2lf", profit);
}