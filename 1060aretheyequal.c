#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    float f[2];

    scanf("%d%f%f", &N, &f[0], &f[1]);

    float factor = 1;
    int digits[2] = {0};
    for (int i = 0; i < 2; i++)
    {
        factor = 1;
        if (f[i] == 1)
        {
            f[i] = 0.1;
            digits[i] = 1;
        }
        if (f[i] == 0){
            f[i] = 0;
            digits[i] = -1;
        }
        else
        {
            if (f[i] > 1)
            {
                while (factor <= f[i])
                {
                    factor *= 10;
                    digits[i]++;
                }
                f[i] = f[i] / factor;
            }
            else
            {
                while (factor > f[i])
                {
                    factor /= 10;
                    digits[i]--;
                }
                factor *= 10;
                f[i] = f[i] / factor;
            }
        }
    }

    float result_a, result_b;
    result_a = (int)(f[0] * (int)pow(10, N))/pow(10, N);
    result_b = (int)(f[1] * (int)pow(10, N))/pow(10, N);

    if(result_a == result_b && digits[0] == digits[1]){
        printf("YES");
        if(digits[0] > 0){
            printf(" %.*f*10^%d", N, result_a, digits[0]);
        }
        else {
            printf(" %.*f*10^%d", N, result_a, digits[0]+1);
        }
    }
    else{
        printf("NO");
        if(digits[0] > 0){
            printf(" %.*f*10^%d", N, result_a, digits[0]);
        }
        else{
            printf(" %.*f*10^%d", N, result_a, digits[0]+1);
        }
        if(digits[1] > 0){
            printf(" %.*f*10^%d", N, result_b, digits[1]);
        }
        else{
            printf(" %.*f*10^%d", N, result_b, digits[1]+1);
        }
    }

    system("pause");
}