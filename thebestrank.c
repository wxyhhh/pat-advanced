#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct student{
    char id[10];
    int grade[4];
    int best_subject;
    int best_rank;
};

struct sortNode{
    int value;
    int stu_seq;
};

int compare(const void* a, const void* b){
    return (*(struct sortNode*)b).value - (*(struct sortNode*)a).value;
}

int main()
{
    struct student stu[2000];
    int N, M;
    struct sortNode sort[2000];
    char subjects[4] = "ACME";
    char queryID[10];

    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%s%d%d%d", stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/3;
        stu[i].best_rank = N;
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<N; j++){
            sort[j].value = stu[j].grade[i];
            sort[j].stu_seq = j;
        }

        qsort(sort, N, sizeof(struct sortNode), compare);

        int tmpGrade = -1;
        int tmpRank = -1;
        for(int j=0; j<N; j++){
            if(sort[j].value != tmpGrade){
                tmpRank = j+1;
                tmpGrade = sort[j].value;
            }

            if(tmpRank < stu[sort[j].stu_seq].best_rank){
                stu[sort[j].stu_seq].best_rank = tmpRank;
                stu[sort[j].stu_seq].best_subject = i;
            }
        }
    }

    for(int i=0; i<M; i++){
        scanf("%s", queryID);
        int j;
        for(j=0; j<N; j++){
            if(strcmp(queryID, stu[j].id) == 0){
                printf("%d %c", stu[j].best_rank, subjects[stu[j].best_subject]);
                break;
            }
        }

        if(j == N){
            printf("N/A");
        }

        if(i != M-1){
            printf("\n");
        }
    }
    
}