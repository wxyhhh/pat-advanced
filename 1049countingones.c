#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
// 1 10+10*1 100 + 9*(10+(9*1)); 1000 + 9 *(100+9*19)
int main()
{
    int ones_num[11];
    int N;
    int digits_num;
    int ones = 0;

    scanf("%d", &N);

    int factor = 1;

    while(N / factor != 0){
        int higher  = N / factor /10;
        int current = N / factor % 10;
        int lower = N - N/factor * factor;

        if(current == 0){
            ones += higher * factor;
        }
        else if(current == 1){
            ones += higher * factor + 1 * lower + 1;
        }
        else{
            ones += higher * factor + factor;
        }

        factor *= 10;
    }

    printf("%d", ones);

    system("pause");

}