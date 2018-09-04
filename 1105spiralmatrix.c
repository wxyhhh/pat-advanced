#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int comp(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

int main()
{
    int N;
    int number[10000];
    int**matrix;
    scanf("%d", &N);

    int n=(int)sqrt(N);
    int m;
    for(int i=n; i>=1; i--)
    {
        if(N%i == 0)
        {
            n = i;
            break;
        }
    }
    m = N/n;

    matrix = (int**)malloc(m*sizeof(int*));

    for(int i=0; i<m; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * n);
    }
    for(int i=0; i<N; i++)
    {
        scanf("%d", &number[i]);
    }

    qsort(number, N, sizeof(int), comp);    
    int x=0, y=0;
    int l=0, r=n-1, u=0, d=m-1;
    int index=0;
    while(index<N)
    {
        u += 1;
        for(y=l;y<=r; y++)
        {
            matrix[x][y] = number[index++];
        }
        y--;

        r--;
        for(x=u; x<=d; x++)
        {
            matrix[x][y] = number[index++];
        }
        x--;
        if(index >= N)
        {
            break;
        }
        d--;
        for(y=r; y>=l; y--)
        {
            matrix[x][y] = number[index++];
        }
        y++;
        l++;

        for(x=d; x>=u; x--)
        {
            matrix[x][y] = number[index++];
        }
        x++;

    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d", matrix[i][j]);
            if(j!=n-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }


    system("pause");
}