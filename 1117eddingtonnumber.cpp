#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std; 

bool comp(int a, int b)
{
    return b < a;
}


int main()
{
    int N;
    int dist[100000];

    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &dist[i]);
    }

    sort(dist, dist+N, comp);

    int e_number = dist[0] -1;
    int count = 0;

    for(int i=0; i<N; i++)
    {
        if(dist[i]>e_number)
        {
            count++;
        }
        else
        {
            if(count == e_number)
            {
                break;
            }
            else if(count > e_number)
            {
                break;
            }
            else
            {
                e_number = dist[i] - 1;
                count++;
            }
        }

        if(count > e_number)
        {
            break;
        }
    }


    printf("%d", e_number);
    
}
