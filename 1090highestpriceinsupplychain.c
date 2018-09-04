#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//这个版本最后一个点超时，原因是出现了重复的遍历，遍历过程中不能保存level
int main()
{
    int N;
    double p, r;
    int supplier[100000];
    int known[100000] = {0};

    scanf("%d%lf%lf", &N, &p, &r);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &supplier[i]);
        if(supplier[i]!= -1)
            known[supplier[i]] = 1;
    }
    int max_level = 0;
    int count = 1;

    for(int i=0; i<N; i++)
    {
        if(known[i])
        {
            continue;
        }
        int j=i;
        int c_level = 0;
        while(supplier[j]!=-1)
        {
            j = supplier[j];
            c_level++;
        }
        if(c_level == max_level)
        {
            if(c_level != 0)
                count++;
        }
        else if(c_level > max_level)
        {
            max_level = c_level;
            count = 1;   
        }
    }

    double max_price = p*pow(1+r/100, max_level);

    printf("%.2lf %d", max_price, count);

    system("pause");
}