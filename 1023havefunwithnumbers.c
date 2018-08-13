#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char number[21];
    char newnumber;
    int times[10];
    int end;
    int carry = 0;
    int sum;

    scanf("%s", number);
    end= strlen(number);

    for(int i=0; i<10; i++){
        times[i] = 0;
    }

    for(int i=end-1; i>=0; i--){
        times[number[i]-'0'] += 1;
        sum = (number[i]-'0') * 2+carry;
        carry = sum / 10;
        if(sum >= 10){
            number[i] = sum-10+'0';
        }
        else{
            number[i] = sum+'0';
        }
        times[number[i]-'0'] -= 1;
    }

    if(carry > 0){
        printf("No\n");
        printf("%d%s", carry, number);
        return 0;
    }
    for(int i = 0; i< 10; i++){
        if(times[i] != 0){
            printf("No\n");
            printf("%s", number);
            system("pause");
            return 0;
        }
    }

    printf("Yes\n");
    printf("%s", number);
    system("pause");

}