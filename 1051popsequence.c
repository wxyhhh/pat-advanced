#include <stdlib.h>
#include <stdio.h>

int stack[1000];
int stack_pointer = 0;

int main()
{
    int M, N, K;
    int sequence[1000];
    int element;
    int current_seq;
    int current_capacity;

    scanf("%d%d%d", &M, &N, &K);

    for(int i=0; i<K; i++){
        stack_pointer = 0;
        current_seq = 1;
        current_capacity = 0;
        int j;
        for(j=0; j<N; j++){
            scanf("%d", &sequence[j]);
        }
        for(j=0; j<N; j++){
            element = sequence[j];
            if(stack_pointer == 0 || element >= current_seq){
                for(int k= current_seq; k<= element; k++){
                    stack[stack_pointer++] = k;
                    current_capacity++;
                }

                if(current_capacity > M){
                        break;
                }
                stack_pointer--;
                current_capacity--;
                current_seq = element + 1;
            }
            else if(element == stack[stack_pointer-1]){
                stack_pointer--;
                current_capacity--;
            }
            else{
                break;
            }
        }
        if(j == N){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    system("pause");

}