#include <stdlib.h>
#include <stdio.h>

int main()
{
    int times;
    int permutation[55];
    int cards[55];
    int tmp[55];

    for(int i=1; i<=54; i++)
    {
        cards[i] = i;
    }

    scanf("%d", &times);
    for(int i=1; i<=54; i++){
        scanf("%d", &permutation[i]);
    }

    for(int i=0; i<times; i++){
        for(int j=1; j<=54; j++){
            tmp[permutation[j]] = cards[j];
        }
        for(int j=1; j<=54; j++){
            cards[j] = tmp[j];
        }
    }

    for(int i=1; i<=54; i++){
        if(cards[i] >=1 && cards[i] <= 13){
            printf("S%d", (cards[i]-1) % 13+1);
        }
        else if(cards[i] >=14 && cards[i] <= 26){
            printf("H%d", (cards[i]-1) % 13+1);
        }
        else if(cards[i] >=27 && cards[i] <= 39){
            printf("C%d", (cards[i]-1) % 13+1);
        }
        else if(cards[i] >=40 && cards[i] <= 52){
            printf("D%d", (cards[i]-1) % 13+1);
        }
        else if(cards[i] == 53){
            printf("J1");
        }
        else{
            printf("J2");
        }

        if(i!=54){
            printf(" ");
        }
    }

    system("pause");
    return 0;

}