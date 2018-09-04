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
    int sorted[100000];
    int candidate[100000];
    int count = 0;

    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &number[i]);
        sorted[i] = number[i];
    }

    qsort(sorted, N, sizeof(int), comp);

    int max = 0;

    for(int i=0; i<N; i++)
    {
        if(number[i] > max)
        {
            max = number[i];
        }
        if(number[i] == sorted[i] && number[i] == max)
        {
            candidate[count++] = number[i];
        }
    }
    printf("%d\n", count);
    for(int i=0; i<count; i++)
    {
        printf("%d", candidate[i]);
        if(i!=count-1)
        {
            printf(" ");
        }
    }

    printf("\n");
    system("pause");
}