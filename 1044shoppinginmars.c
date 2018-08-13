#include <stdlib.h>
#include <stdio.h>

struct chain
{
    int sum;
    int start;
    int end;
};

int comp(const void* a, const void* b){
    if((*(struct chain*)a).sum - (*(struct chain*)b).sum != 0)
        return (*(struct chain*)a).sum - (*(struct chain*)b).sum;
    else{
        return (*(struct chain*)a).start - (*(struct chain*)b).start;
    }
}

int main()
{
    int total_num;
    int target_sum;
    int diamonds[100000];
    struct chain over_chains[100000];
    int chains_num = 0;
    int flag = 0;

    scanf("%d%d", &total_num, &target_sum);

    for(int i=0; i<total_num; i++)
    {
        scanf("%d", &diamonds[i]);
    }

    for(int i=0; i<total_num; i++){
        int tmp_sum = 0;
        for(int j=i; j<total_num; j++){
            tmp_sum += diamonds[j];
            if(tmp_sum < target_sum){
                continue;
            }
            else if(tmp_sum == target_sum){
                flag = 1;
                printf("%d-%d\n", i+1, j+1);
            }
            else{
                over_chains[chains_num].sum = tmp_sum;
                over_chains[chains_num].start = i;
                over_chains[chains_num].end = j;
                chains_num ++;
            }
            break;
        }
        if(tmp_sum < target_sum){
            break;
        }
    }

    if(flag == 0){
        qsort(over_chains, chains_num, sizeof(struct chain), comp);
        int min_sum = over_chains[0].sum;
        for(int i=0; i<chains_num; i++){
            if(over_chains[i].sum == min_sum){
                printf("%d-%d\n", over_chains[i].start+1, over_chains[i].end+1);
            }
        }
    }

    system("pause");

    return 0;
}   