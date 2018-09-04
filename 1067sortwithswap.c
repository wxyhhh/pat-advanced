#include<stdlib.h>
#include<stdio.h>


int main()
{
    int N;
    int number;
    int position[100000];
    int count = 0;

    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &number);
        position[number] = i;
        if(number != i && number!=0){
            count++;
        }
    }


    int swap_count = 0;
    int index = 0;
    while(count != 0){
        if(position[0] == 0){
            for(int i=index; i<N; i++){
                if(position[i] != i){
                    position[0] = position[i];
                    position[i] = 0;
                    swap_count ++;
                    break;
                }
                index++;
            }
        }
        while(position[0]!=0){
            int tmp = position[0];
            position[0] = position[tmp];
            position[tmp] = tmp;
            swap_count++;
            count--;
            
        }
    }

    printf("%d", swap_count);

    system("pause");
}