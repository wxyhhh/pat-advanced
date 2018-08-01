#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    char input[200];
    int sum = 0;
    int i;
    int factor = 1;
    int count = 0;
    scanf("%s", input);

    i = 0;
    while(input[i] != 0){
        sum += input[i]-'0';
        i++;
    }
    if(sum == 0){
        printf("zero");
        return 0;
    }
    while(sum / factor != 0){
        factor *= 10;
        count ++;
    }

    while(count!=0){
        switch(sum/(factor/10)){
            case 0:printf("zero");break;
            case 1:printf("one");break;
            case 2:printf("two");break;
            case 3:printf("three");break;
            case 4:printf("four");break;
            case 5:printf("five");break;
            case 6:printf("six");break;
            case 7:printf("seven");break;
            case 8:printf("eight");break;
            case 9:printf("nine");break;
            default: printf("hhh"); break;
        }
        sum = sum%(factor/10);
        factor = factor/10;
        count --;
        if(count != 0){
            printf(" ");
        }
    }

    system("pause");
}