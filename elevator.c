#include <stdio.h>

int main()
{
    int current = 0;
    int request;
    int N;
    int total_time = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &request);
        if(request > current){
            total_time += (request-current) * 6;
        }
        else{
            total_time += (current-request) * 4;
        }
        total_time += 5;
        current = request;
    }

    printf("%d", total_time);

    system("pause");
}