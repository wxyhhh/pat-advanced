#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    int M;
    char unlock_id[16];
    char lock_id[16];
    char id[16];
    char unlock_time[10] = "23:59:59";
    char lock_time[10] = "00:00:00";
    char leave_time[10];
    char arrive_time[10];
    scanf("%d", &M);

    for(int i=0; i < M; i++){
        scanf("%s%s%s", id, arrive_time, leave_time);
        if(strcmp(arrive_time, unlock_time) <= 0){
            strcpy(unlock_id, id);
            strcpy(unlock_time, arrive_time);
        }
        if(strcmp(leave_time, lock_time) >= 0){
            strcpy(lock_id, id);
            strcpy(lock_time, leave_time);
        }
    }

    printf("%s %s", unlock_id, lock_id);
    system("pause");
}