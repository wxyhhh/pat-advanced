#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX 100000

struct node
{
    long long amount;
    int count;
    int chain[MAX];
};

int N;
double p, r;
struct node nodes[MAX];

double total_price = 0;

void dfs(int index, int c_level)
{
    if(nodes[index].count == 0)
    {
        total_price += p*pow(r/100 + 1.0, c_level) * nodes[index].amount;
        return;
    }
    else{
        c_level ++;
        for(int i=0; i<nodes[index].count; i++)
        {
            dfs(nodes[index].chain[i], c_level);
        }
    }
}

int main()
{
    scanf("%d%lf%lf", &N, &p, &r);

    // for(int i=0; i<N; i++)
    // {
    //     for(int j=0; j<N; j++)
    //     {
    //         chain[i][j] = 0;
    //     }
    // }

    int w;
    int num;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &num);
        nodes[i].count = num;
        if(num != 0){
            for(int j=0; j<num; j++)
            {
                scanf("%d", &w);
                nodes[i].chain[j] = w;
            }
        }
        else{
            scanf("%lld", &(nodes[i].amount));
        }
    }
    


    dfs(0, 0);

    printf("%.1lf", total_price);

    system("pause");
}