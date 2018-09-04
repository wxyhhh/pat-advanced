#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct person
{
    char name[10];
    int height;
}p[10000];

int comp(const void* a, const void* b)
{
    struct person* pa = (struct person*)a;
    struct person* pb = (struct person*)b;

    if(pa->height != pb->height)
    {
        return pb->height - pa->height;
    }
    return strcmp(pa->name, pb->name);
}

int main()
{
    int N;
    int K;
    int* matrix[10];

    scanf("%d%d", &N, &K);

    for(int i=0; i<N; i++)
    {
        scanf("%s%d", p[i].name, &p[i].height);
    }

    qsort(p, N, sizeof(struct person), comp);

    int length = N/K;
    int extra = N%K;
    int start = N-1;
    int end;
    for(int i=0; i<K; i++)
    {
        matrix[i] = (int*)malloc((length*2+1)*sizeof(int));
        int real_length = length;
        end = start-length+1;
        if(i==K-1)
        {
            end = 0;
            real_length += extra;
        }
        matrix[i][real_length/2+1] = end;
        int flag = 0;
        int left = real_length/2;
        int right = real_length/2+2;
        for(int j= end+1; j<=start; j++)
        {
            if(flag == 0)
            {
                matrix[i][left--] = j;
                flag = 1;
            }
            else{
                matrix[i][right++] = j;
                flag = 0;
            }
        }
        start = end-1;
    }

    for(int i=K-1; i>=0; i--)
    {
        int count;
        if(i==K-1)
        {
            count = length+extra;
        }
        else
        {
            count = length;
        }

        for(int j=1; j<=count; j++)
        {
            printf("%s", p[matrix[i][j]].name);
            if(j!=count)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    system("pause");
}