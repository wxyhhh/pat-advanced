#include <stdlib.h>
#include <stdio.h>

int main()
{
    int N;
    int x;
    int fn[37];
    int count = 0;

    for(int i=0; i<37; i++)
    {
        fn[i] = 0;
    }
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &x);
        if(x==0)
        {
            if(fn[0] == 0)
            {
                fn[0] = 1;
                count++;
            }
        }
        else
        {
            int sum=0;
            while(x!=0)
            {
                sum+=x%10;
                x /= 10;
            }
            if(fn[sum] == 0)
            {
                fn[sum] = 1;
                count ++;
            }
        }
        
    }

    printf("%d\n", count);
    int index = 37;
    for(int i=0; i<37; i++)
    {
        if(fn[i] != 0)
        {
            printf("%d", i);
            index = i;
            break;
        }
    }
    for(int i=index+1; i<37; i++)
    {
        if(fn[i] != 0)
        {
            printf(" %d", i);
        }
    }
    printf("\n");
    system("pause");
}