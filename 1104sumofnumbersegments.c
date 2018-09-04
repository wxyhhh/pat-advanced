#include<stdlib.h>
#include<stdio.h>

//0.1 0.2 0.3 0.4 0.5
//0.1 0.2 0.3
//0.1 0.1 0.2 0.1 0.2 0.3 0.2 0.2 0.3 0.3
//测试用例十分迷幻，必须得正着加，不然就会出错。。

int main()
{
    int N;
    double a[100000];
    double sum = 0.0;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%lf", &a[i]);
    }

    int end = N/2;
    //double segment = a[0] + a[N-1];
    for(int i=0; i<end; i++)
    {
        sum += a[i] * (i+1)*(N-i);
    }
    if(N%2==1)
    {
        sum += a[end]*(end+1)*(N-end);
    }
    // for(int i=0; i<=end-1; i++)
    // {
    //     sum += a[N-1-i] * (i+1)*(N-i);
    //     // n-1 1 n
    //     // n-end end n-end+1
    // }
    for(int i=N-end; i<= N-1; i++)
    {
        sum += a[i] * (i+1)*(N-i);
    }
    // for(int i=N-1; i>=N-end; i--)
    // {
    //     sum += a[i] * (i+1)*(N-i);
    // }
    
    printf("%.2lf\n", sum);
    system("pause");
}