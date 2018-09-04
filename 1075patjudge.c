#include <stdlib.h>
#include <stdio.h>

struct user
{
    int score[6];
    int submit[6];
    int count;
    int id;
    int total;
};

int comp(const void* a, const void* b)
{
    struct user ua = *(struct user*)a;
    struct user ub = *(struct user*)b;

    if(ua.total != ub.total)
    {
        return ub.total - ua.total;
    }

    if(ua.count != ub.count)
    {
        return ub.count - ua.count;
    }
    
    return ua.id - ub.id;
}

int main()
{
    struct user users[10001];

    int N, K, M;
    int uid, pid, score;
    int full[6];

    scanf("%d%d%d", &N, &K, &M);
    for(int i=1; i<=K; i++){
        scanf("%d", &full[i]);
    }
    for(int i=1; i<=N; i++){
        users[i].id = i;
        users[i].count = 0;
        for(int j=1; j<=K; j++){
            users[i].score[j] = -1;
            users[i].submit[j] = 0;
        }
        users[i].total = -1;
    }

    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d", &uid, &pid, &score);
        users[uid].submit[pid] = 1;
        if(users[uid].score[pid] < score)
        {
            if(users[uid].total == -1){
                users[uid].total = score;
            }
            else{
                if(users[uid].score[pid] != -1)
                    users[uid].total += score - users[uid].score[pid];
                else{
                    users[uid].total += score;
                }
            }
            users[uid].score[pid] = score;
            if(score == full[pid]){
                users[uid].count++;
            }
        }
    }
    qsort(users+1, N, sizeof(struct user), comp);

    int current_score = users[1].total;
    int current_rank = 1;
    for(int i=1; i<=N; i++)
    {
        if(users[i].total != -1)
        {
            if(users[i].total == current_score)
            {
                printf("%d", current_rank);
            }
            else{
                current_rank = i;
                current_score = users[i].total;
                printf("%d", i);
            }

            printf(" %05d %d", users[i].id, users[i].total);
            for(int j=1; j<=K; j++)
            {
                if(users[i].submit[j] == 1){
                    if(users[i].score[j] == -1)
                        printf(" 0");
                    else
                        printf(" %d", users[i].score[j]);
                }
                else{
                    printf(" -");
                }
            }

            printf("\n");
        }
    }
    system("pause");
}