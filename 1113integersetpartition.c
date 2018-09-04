#include <stdlib.h>
#include <stdio.h>

int comp(const void*a, const void*b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int N;
    int number[100000];

    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &number[i]);
    }
    qsort(number, N, sizeof(int), comp);
    int sum1=0, sum2=0;
    int count1;
    if(N%2==0)
    {
        count1 = N/2;
    }
    else
    {
        count1 = (N-1)/2;
    }
    for(int i=0; i<count1; i++)
    {
        sum1 += number[i];
    }
    for(int i=count1; i<N; i++)
    {
        sum2 += number[i];
    }

    printf("%d %d", N%2, sum2-sum1);

    system("pause");
}