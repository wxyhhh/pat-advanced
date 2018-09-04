#include <stdlib.h>
#include <stdio.h>

int coins[10000];
int coins_num;
int sequence[10000];
int N, M;

int comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int findcoins(int target, int start, int end)
{
    int result;
    for(int i=start; i<=end; i++){
        if(sequence[i] == target){
            coins[coins_num++] = sequence[i];
            return 1;
        }
        else if(sequence[i] > target){
            return 0;
        }
        else if(target - sequence[i] < sequence[i]){
            continue;
        }
        else{
            if(i==end){
                return 0;
            }
            else{
                coins[coins_num++] = sequence[i];
                result = findcoins(target-sequence[i], i+1, end);
                if(result == 1){
                    return 1;
                }
                //1 2 3 4 5 7 8 9
                else{
                    coins_num--;
                    continue;
                }
            }
        }
    }
}

int main()
{
    int result = 0;
    scanf("%d%d", &N, &M);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &sequence[i]);
    }

    qsort(sequence, N, sizeof(int), comp);

    result = findcoins(M, 0, N-1);

    if(result == 1){
        printf("%d", coins[0]);
        for(int i=1; i<coins_num; i++){
            printf(" %d", coins[i]);
        }
    }
    else{
        printf("No Solution");
    }

    system("pause");
}