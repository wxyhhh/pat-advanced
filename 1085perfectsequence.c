#include <stdlib.h>
#include <stdio.h>

int comp(const void*a, const void*b)
{
    return *(int*)a - *(int*)b;   
}

int main()
{
    int N, p;
    int max_num = 0;
    int number[100000];
    int start;
    int tmp=0;
    scanf("%d%d", &N, &p);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &number[i]);
    }

    qsort(number, N, sizeof(int), comp);
    start = 0;
    for(int i=0; i<N; i++)
    {
        if(N-i < max_num)
        {
            break;
        }

        int j;
        for(j=start; j<N; j++)
        {
            if(number[j] <= p * number[i] || p*number[i] < 0)
            {
                tmp++;
            }
            else{
                break;
            }
        }
        if(tmp > max_num)
        {
            max_num = tmp;
        }
        //剪枝，如果i---j-1是一个序列，那么检查i+1时只需要用上一次的长度-1作为开始，再从j开始检查。
        //因为j-1以前的数已经必定小于等于p*m
        start = j;
        tmp -= 1;
    }

    printf("%d", max_num);

    system("pause");
}