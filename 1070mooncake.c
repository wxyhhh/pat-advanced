#include <stdlib.h>
#include <stdio.h>

struct inventory
{
    double amount;
    double price;
    double real_price;
};

int comp(const void* a, const void* b)
{
    double first = (*(struct inventory*)a).real_price;
    double second = (*(struct inventory*)b).real_price;

    return (int)(second*100+0.5) - (int)(first*100+0.5);
}

int main()
{
    struct inventory c[1000];
    int total_amount;
    double profit = 0;
    int N;

    scanf("%d%d", &N, &total_amount);
    for(int i=0;i<N; i++)
    {
        scanf("%lf", &c[i].amount);
    }

    for(int i=0;i<N; i++)
    {
        scanf("%lf", &c[i].price);
        c[i].real_price = c[i].price / c[i].amount;
    }

    qsort(c, N, sizeof(struct inventory), comp);

    for(int i=0; i<N; i++)
    {
        if(c[i].amount > total_amount)
        {
            profit += c[i].price * total_amount / c[i].amount;
            total_amount = 0;
        }
        else{
            profit += c[i].price;
            total_amount -= c[i].amount;
        }

        if(total_amount == 0){
            break;
        }
    }

    printf("%.2lf", profit);

    system("pause");
}