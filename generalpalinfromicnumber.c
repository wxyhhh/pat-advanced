#include <stdlib.h>
#include <stdio.h>

int main()
{
    long long int N;
    long long int b;
    long long int digits[30];
    int digits_num = 0;

    scanf("%lld%lld", &N, &b);

    if(N == 0){
        printf("Yes\n0");
        return 0;
    }

    while(N!=0){
        digits[digits_num] = N%b;
        N = N/b;
        digits_num++;
    }

    if(digits_num == 1){
        printf("Yes\n%lld", digits[0]);
    }
    else{
        int flag = 1;
        for(int i=0; i<digits_num/2; i++){
            if(digits[i] != digits[digits_num-1-i]){
                flag = 0;
                break;
            }
        }

        if(flag == 1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }

        for(int i=digits_num-1; i>=0; i--){
            if(i == 0){
                printf("%lld", digits[i]);
            }
            else{
                printf("%lld ", digits[i]);
            }
        }
    
    }
    system("pause");

}