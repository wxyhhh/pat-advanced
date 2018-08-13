#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info
{
    char id[14];
    int score;
    int final_rank;
    int local_rank;
    int location_number;
};
int comp(const void*a, const void* b)
{
    int scoreA;
    int scoreB;
    scoreA = (*(struct info*)a).score;
    scoreB = (*(struct info*)b).score;
    if(scoreA != scoreB)
        return scoreB-scoreA;
    else{
        return strcmp((*(struct info*)a).id, (*(struct info*)b).id);
    }
}
int main()
{
    struct info *total_list;
    int total_num = 0;
    int N, K;

    scanf("%d", &N);

    total_list = (struct info*)malloc(N*300*sizeof(struct info));

    for(int i=0; i<N; i++){
        scanf("%d", &K);
        for(int j=0; j<K; j++){
            scanf("%s%d", total_list[total_num].id, &total_list[total_num].score);
            total_list[total_num].location_number = i+1;
            total_num++;
        }
        qsort(total_list+total_num-K, K, sizeof(struct info), comp);
        int current_rank = 1;
        int current_score = total_list[total_num-K].score;
        for(int j=0; j<K; j++){
            if(total_list[total_num-K+j].score == current_score){
                total_list[total_num-K+j].local_rank = current_rank;
            }
            else{
                current_rank = j+1;
                total_list[total_num-K+j].local_rank = current_rank;
                current_score = total_list[total_num-K+j].score;
            }
        }
    }
    qsort(total_list, total_num, sizeof(struct info), comp);
    printf("%d\n", total_num);
    int current_rank = 1;
    int current_score = total_list[0].score;
    for(int i=0; i<total_num; i++){
        if(total_list[i].score == current_score){
                total_list[i].final_rank = current_rank;
        }
        else{
            current_rank = i+1;
            total_list[i].final_rank = current_rank;
            current_score = total_list[i].score;
        }

        printf("%s %d %d %d\n", total_list[i].id, total_list[i].final_rank, total_list[i].location_number, total_list[i].local_rank);
    }

    system("pause");
    
}