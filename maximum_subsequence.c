#include <stdlib.h>
#include <stdio.h>

int main()
{
    int K;
    int a[10000];
    int iszero = 1;
    int local_sum = 0;
    int max_sum = 0;
    int start = 0;
    int temp_start = 0;
    int last = 0;
    scanf("%d", &K);

    for( int i=0; i < K; i++){
        scanf("%d", &a[i]);
        if(a[i] >= 0){
            iszero = 0;
        }
    }
    if(iszero == 1){
        printf("0 %d %d", a[0], a[K-1]);
        return 0;
    }
    
    for(int i=0; i < K; i++){
        local_sum += a[i];
        if(local_sum > max_sum || (local_sum==max_sum && max_sum==0)){
            max_sum = local_sum;
            start = temp_start;
            last = i;
        }
        else if(local_sum < 0){
            local_sum = 0;
            temp_start = i+1;
        }
    }

    printf("%d %d %d", max_sum, start, last);

    system("pause");

}