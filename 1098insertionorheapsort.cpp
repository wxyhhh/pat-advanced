#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int N;
    int flag = 0;
    int number[100];
    int sorted[100];

    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &number[i]);
    }
    for(int i=0; i<N; i++)
    {
        scanf("%d", &sorted[i]);
    }

    int i=1;
    int start;
    for(; i<N; i++)
    {
        if(sorted[i] < sorted[i-1])
        {
            start = i;
            break;
        }
    }

    for(; i<N; i++)
    {
        if(sorted[i] != number[i])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Insertion Sort\n");
        int tmp = sorted[start];
        int target = 0;
        for(int i=start-1; i>=0; i--)
        {
            if(sorted[i]<=tmp)
            {
                target = i+1;
                break;
            }
        }

        for(int i=start; i>target; i--)
        {
            sorted[i] = sorted[i-1];
        }

        sorted[target] = tmp;

        for(int i=0; i<N; i++)
        {
            printf("%d", sorted[i]);
            if(i!=N-1)
            {
                printf(" ");
            }
        }
    }
    else
    {
        printf("Heap Sort\n");
        int tmp = sorted[0];
        int end = N;
        for(int i=N-1; i>0; i--)
        {
            if(sorted[i] < tmp)
            {
                sorted[0] = sorted[i];
                sorted[i] = tmp;
                end = i;
                break;
            }
        }

        for(int i=0;i<end;)
        {
            if(i*2+1 >= end)
            {
                break;
            }
            else if(i*2+2 >=end)
            {
                if(sorted[i] < sorted[i*2+1])
                {
                    swap(sorted[i], sorted[i*2+1]);
                    i = i*2+1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                int x;
                if(sorted[i*2+1] > sorted[i*2+2])
                {
                    x = i*2+1;                
                }
                else
                {
                    x = i*2+2;
                }
                if(sorted[i] < sorted[x])
                {
                    swap(sorted[i], sorted[x]);
                    i = x;
                }
                else
                {
                    break;
                }
        	}	
        }
        for(int i=0; i<N; i++)
        {
            printf("%d", sorted[i]);
            if(i!=N-1)
            {
                printf(" ");
            }
        }

    }


}
