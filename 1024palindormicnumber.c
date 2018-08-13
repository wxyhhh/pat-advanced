#include <stdlib.h>
#include <stdio.h>


long long int getreversed(long long int origin)
{
    long long int result = 0;
    int tmp;
    if (origin == 0){
        return 0;
    }
    while(origin != 0){
        tmp = origin %10;
        result = result * 10 + tmp;
        origin /= 10;
    }

    return result;
}

int main()
{
    long long int N;
    int K;
    long long int reversed;
    int i;

    scanf("%lld%d", &N, &K);

    for(i=0; i<=K; i++){
        reversed = getreversed(N);
        if(reversed == N){
            printf("%lld\n%d", reversed, i);
            break;
        }
        else{
            N += reversed;
        }
    }
    if(i == K+1){
        printf("%lld\n%d", N-reversed, K);
    }


    system("pause");

}