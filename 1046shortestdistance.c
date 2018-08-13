#include <stdlib.h>
#include <stdio.h>

int main()
{
    int exits_num;
    int query_num;
    int *distance;
    int *path;
    int total_length = 0;
    
    scanf("%d", &exits_num);

    distance = (int*)malloc((exits_num+1)*sizeof(int));
    path = (int*)malloc((exits_num+1)*sizeof(int));
    path[0] = 0;
    path[1] = 0;

    for(int i=1; i<= exits_num; i++){
        scanf("%d", &distance[i]);
        total_length += distance[i];
        if(i!= exits_num){
            path[i+1] = path[i] + distance[i];
        }
    }


    scanf("%d", &query_num);

    for(int i=0; i<query_num; i++){
        int start, end;
        scanf("%d%d", &start, &end);
        int length;
        if(start < end){
            length = path[end] - path[start];
        }
        else{
            length = path[start] - path[end];
        }
        
        if(total_length - length > length){
            printf("%d\n", length);
        }
        else{
            printf("%d\n", total_length -length);
        }
    }

    system("pause");

}