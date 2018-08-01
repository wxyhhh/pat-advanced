#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isPrime(int number){
    int flag = 1;
    if(number < 2){
        return 0;
    }
    for(int i=2; i <= (int)sqrt(number); i++){
        if(number % i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int N, D;
    int tmp;
    int rN;

    while(1){
        scanf("%d", &N);
        if(N < 0){
            break;
        }
        scanf("%d", &D);
        tmp = N;
        rN = 0;
        while(tmp != 0){
            rN = rN*D + tmp%D;
            tmp = tmp/D;
        }
        if(isPrime(N) == 1 && isPrime(rN) == 1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}