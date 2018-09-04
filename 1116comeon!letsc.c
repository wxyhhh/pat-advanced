#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int number[10000];
int checked[10000];

int isprime(int num)
{
    if(num == 1)
    {
        return 0;
    }
    if(num == 2)
    {
        return 1;
    }

    int end = (int)sqrt(num);

    for(int i=2; i<=end; i++)
    {
        if(num%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int N, K;

    scanf("%d", &N);
    for(int i=0; i<10000; i++)
    {
        number[i] = -1;
        checked[i] = 0;
    }
    int x;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &x);
        number[x] = i+1;
    }
    scanf("%d", &K);
    for(int i=0; i<K; i++)
    {
        scanf("%d", &x);
        if(number[x] == -1)
        {
            printf("%04d: Are you kidding?\n", x);
            continue;
        }
        if(checked[x] == 1)
        {
            printf("%04d: Checked\n", x);
            continue;
        }
        else
        {
            checked[x] = 1;
            if(number[x] == 1)
            {
                printf("%04d: Mystery Award\n", x);
            }
            else if(isprime(number[x]) == 1)
            {
                printf("%04d: Minion\n", x);
            }
            else
            {
                printf("%04d: Chocolate\n", x);
            }
        }
    }

    system("pause");
}