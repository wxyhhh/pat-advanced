#include <stdlib.h>
#include <stdio.h>

int N;

int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}


int judge_merge(int *n, int len)
{
    for(int i=0; i<N; i+=len)
    {
        for(int j=i+1; j<i+len&&j<N; j++)
        {
            if(n[j] < n[j-1])
            {
                return 0;
            }
        }
    }

    return 1;
}

void do_merge(int* n, int len)
{
    for(int i=0; i<N; i+=len)
    {
        if(i+len>=N)
        {
            qsort(n+i,N-i, sizeof(int), comp);
        }
        else{
            qsort(n+i, len, sizeof(int),comp);
        }
    }
}



int main()
{
    int n[100];
    int after[100];
    int flag;// 0 insert 1 merge;
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &n[i]);
    }

    for(int i=0; i<N; i++)
    {
        scanf("%d", &after[i]);
    }
    int start;
    for(int i=0; i<N-1; i++)
    {
        if(after[i+1] < after[i])
        {
            start = i+1; 
            break;
        }  

    }
    int j=0;
    for(j=start;j<N; j++)
    {
        if(after[j] != n[j])
        {
            flag = 1;
            break;
        }
    }
    if(j==N)
    {
        flag = 0;
    }

    if(flag == 0)
    {
        printf("Insertion Sort\n");
        int tmp = after[start];
        int i=0;
        for(; i<start; i++)
        {
            if(tmp < after[i])
            {
                break;
            }
        }
        for(int j=start; j>=i+1; j--)
        {
            after[j] = after[j-1];
        }

        after[i] = tmp;
        for(i=0; i<N; i++)
        {
            printf("%d", after[i]);
            if(i!=N-1)
            {
                printf(" ");
            }
        }
    }
    else{
        printf("Merge Sort\n");
        int len =1;
        while(len*2<=N)
        {
            len *= 2;
        }

        for(int i=len; i>=1; i/=2)
        {
            if(judge_merge(after, i))
            {
                do_merge(n, i*2);
                for(int i=0; i<N; i++)
                {
                    printf("%d", n[i]);
                    if(i!=N-1)
                    {
                        printf(" ");
                    }
                }
                break;
            }
        }
    }

    system("pause");
}