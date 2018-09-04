#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long int factors[1000];
int factor_num = 0;

int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
void findfactors(long int start, long int N)
{
    long int end = (long)sqrt(N);
    if(N == 2){
        factors[factor_num++] = 2;
        return;
    }
    for(long int i=start; i<=end; i++){
        if(N%i == 0){
            findfactors(i, N/i);
            findfactors(i, i);
            return;
        }
    }

    factors[factor_num++] = N;   
}

int main()
{
    long int N;

    scanf("%ld", &N);

    findfactors(2, N);

    qsort( factors, factor_num, sizeof(long int), comp);

    printf("%ld=", N);
    int current_count = 0;
    long int current_factor = factors[0];
    for(int i=0; i<factor_num; i++){
        if(factors[i] != current_factor){
            if(current_count != 1){
                printf("%ld^%d", current_factor, current_count);
            }
            else{
               printf("%ld", current_factor);
            }
            current_factor = factors[i];
            current_count = 1;
            printf("*");
        }
        else{
            current_count ++;
        }
    }
    if(current_count != 1){
        printf("%ld^%d", current_factor, current_count);
    }
    else{
        printf("%ld", current_factor);
    }

    system("pause");
}