#include <stdlib.h>
#include <stdio.h>

struct r
{
    long long int n;
    long long int d;
};

long long int gct(long long int a, long long int b)
{
    if(b==0)
    {
        return 1;
    }
    long long int c = a%b;

    if(c == 0)
    {
        return b;
    }

    while(c!=0)
    {
        c = a % b;

        a = b;
        b = c;
    }

    return a;
}

long long int lcm(long long int a, long long int b)
{
    long long int factor = gct(a, b);

    return a/factor * (b/factor) * factor;
}



int main()
{
    int N;

    struct r rational[100];
    struct r sum;

    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%lld/%lld", &rational[i].n, &rational[i].d);
    }

    // if(N == 1)
    // {
    //     long long int tmp = rational[0].n / rational[0].d;
    //     if(tmp != 0){
    //         printf("%lld ", tmp);
    //     }
    //     rational[0].n -= rational[0].d * tmp;
    //     long long int tmp2 = gct(rational[0].n, rational[0].d);
    //     printf("%lld/%lld", rational[0].n / tmp2, rational[0].d/tmp2);
    // }
    // else{
        sum.n = rational[0].n;
        sum.d = rational[0].d;
        for(int i=1; i<N; i++)
        {
            long long int tmp = lcm(sum.d, rational[i].d);
            sum.n *= tmp / sum.d;
            rational[i].n *= tmp / rational[i].d;
            sum.n += rational[i].n;
            sum.d = tmp;
            tmp = gct(sum.n, sum.d);
            sum.n /= tmp;
            sum.d /= tmp;
        }

        long long int integer = sum.n / sum.d;
        if(sum.n /sum.d && sum.n%sum.d)
        {
            printf("%lld %lld/%lld", sum.n/sum.d, sum.n%sum.d, sum.d);
        }
        else if(sum.n / sum.d)
        {
            printf("%lld", sum.n/sum.d);
        }
        else if(sum.n %sum.d){
            printf("%lld/%lld", sum.n, sum.d);
        }
        else{
            printf("0");
        }
    //}

    system("pause");
}