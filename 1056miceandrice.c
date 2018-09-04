#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int mice[1000];
    int mouse_num;
    int group_size;
    int play_order[1000];
    int rank[1000];
    int candidate[1000];
    int candidate_num = 0;

    scanf("%d%d", &mouse_num, &group_size);

    for(int i=0; i<mouse_num; i++){
        scanf("%d", &mice[i]);
    }
    for(int i=0; i<mouse_num; i++){
        scanf("%d", &candidate[candidate_num++]);
    }

    while(candidate_num != 1){
        int group_num = (candidate_num + group_size-1) / group_size;
        int count = 0;
        for(int i=0; i < candidate_num;i += group_size){
            int end;
            int max_mouse;
            int max_weight = -1;
            if(i+group_size-1 >= candidate_num){
                end = candidate_num-1;
            }
            else{
                end = i+group_size-1;
            }
            for(int j=i; j <= end; j++){
                if(mice[candidate[j]] > max_weight){
                    max_weight = mice[candidate[j]];
                    max_mouse = candidate[j];
                }
            }
            for(int j=i; j <= end; j++){
                if(candidate[j] != max_mouse){
                    rank[candidate[j]] = group_num + 1;
                }
            }
            candidate[count++] = max_mouse;
        }

        candidate_num = group_num;
    }
    rank[candidate[0]] = 1;
    
    for(int i=0; i<mouse_num; i++){
        printf("%d", rank[i]);
        if(i!=mouse_num-1)
        {
            printf(" ");
        }
    }

    system("pause");

}