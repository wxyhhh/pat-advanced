#include <stdlib.h>
#include <stdio.h>

int times[10001];

int comp(const void*a, const void*b){
    return times[*(int*)a] - times[*(int*)b];
}

int main()
{
    int N;
    int *nums;
    int number;
    int total = 0;

    scanf("%d", &N);
    nums = (int *)malloc(N * sizeof(int));
    for(int i=0; i<10001; i++){
        times[i] = 0;
    }
    for(int i=0; i<N; i++){
        scanf("%d", &number);
        if(times[number] == 0){
            nums[total++] = number;
            times[number] = 1;
        }
        else{
            times[number]++;
        }
    }

    qsort(nums, total, sizeof(int), comp);

    if(times[nums[0]] > 1){
        printf("None");
    }
    else{
        printf("%d", nums[0]);
    }

    system("pause");

    return 0;
}
