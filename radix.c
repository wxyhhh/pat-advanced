#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char N1[20];
    char N2[20];
    char temp[20];
    int tag;
    long long int target_value = 0, temp_value = 0;
    long long int radix;
    long long int result_radix = 0;
    long long int bottom, top, middle;

    scanf("%s%s%d%lld", N1, N2, &tag, &radix);

    if(tag == 2){
        strcpy(temp, N1);
        strcpy(N1, N2);
        strcpy(N2, temp);
    }

    for(int i=0; N1[i]!=0; i++){
        if(N1[i]>='0' && N1[i] <= '9'){
            target_value = target_value * radix + N1[i] - '0';
        }
        else{
            target_value = target_value * radix + N1[i] - 'a' + 10;
        }
    }
    bottom = 2;
    for(int i=0; N2[i]!=0; i++){
        if(N2[i]>='0'&&N2[i] <= '9'){
            if(N2[i]-'0'+1 > bottom){
                bottom = N2[i]-'0'+1;
            }
        }
        else{
            if(N2[i]-'a'+10+1 > bottom){
                bottom = N2[i]-'a'+10+1;
            }
        }
    }
    top = target_value + 1;
    if(target_value == 0){
        top = 2;
    }
    //printf("%lld %lld %lld", target_value, bottom, top);
    while(bottom <= top){
        middle = (top + bottom)/2;
        temp_value = 0;
        for(int i=0; N2[i]!=0; i++){
            if(N2[i]>='0' && N2[i] <= '9'){
                temp_value = temp_value * middle + N2[i] - '0';
            }
            else{
                temp_value = temp_value * middle + N2[i] - 'a' + 10;
            }
            if(temp_value < 0){
                temp_value = -1;
                break;
            }
        }
        if(temp_value < 0 ||temp_value > target_value){
            top = middle - 1;
        }
        else if(temp_value < target_value){
            bottom = middle + 1;
        }
        else{
            result_radix = middle;
            break;
        }
    }

    if(result_radix != 0){
        printf("%lld", result_radix);
    }
    else {
        printf("Impossible");
    }

    system("pause");

}