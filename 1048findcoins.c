#include <stdlib.h>
#include <stdio.h>

int comp(const void*a, const void*b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int N, M;

    int coins[100000];

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%d", &coins[i]);
    }

    qsort(coins, N, sizeof(int), comp);
    int i, j;
    for(i = 0, j=N-1; i < j; ){
        int sum = coins[i] + coins[j];
        if(sum == M){
            printf("%d %d", coins[i], coins[j]);
            break;
        }
        else if(sum > M){
            j--;
        }
        else{
            i++;
        }
    }

    if(i >= j){
        printf("No Solution");
    }

    system("pause");
}