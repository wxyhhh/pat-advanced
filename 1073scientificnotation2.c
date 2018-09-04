#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//数字非常长，所以不能直接转化为浮点数，而应该转化成字符串输出。

int main()
{
    char number[10005];

    scanf("%s", number);
    int i;
    
    char result[10005];

    int pos=0;
    int dot_pos;
    int flag;
    int appe_num = 0;
    int exponent = 0;
    result[pos++] = number[0];
    for(i=1; number[i]!='.'&&number[i]!='E';i++)
    {
        result[pos++] = number[i];
    }

    if(number[i] == '.'){
        dot_pos = i;
        for(i+=1; number[i]!='E'; i++)
        {
            result[pos++] = number[i];
            appe_num ++;
        }
    }
    for(int j=i+2; number[j]!=0; j++){
        exponent = exponent*10 + number[j]-'0';
    }
    if(number[i+1] == '-'){
        exponent = -exponent;
    }

    if(exponent > 0){
        flag = 0;
        if(exponent > appe_num){
            for(int k=0; k<exponent-appe_num; k++){
                result[pos++] = '0';
            }
            appe_num = 0;
            dot_pos = -1;
        }
        else{
            appe_num -= exponent;
            dot_pos += exponent;
        }
    }
    else{
        appe_num += -(exponent);
        dot_pos += exponent;
        flag = 1;
    }

    result[pos] = 0;
    if(result[0] == '-')
        printf("%c", result[0]);
    if(flag == 0){
        int k=1;
        if(dot_pos != -1){
            while(result[k]=='0'){
                k++;
            }
        }
        else{
            while(result[k]=='0' && dot_pos!=k+1){
                k++;
            }
        }
        for(; result[k]!=0; k++){
            if(k==dot_pos){
                printf(".");
            }
            printf("%c", result[k]);
        }
    }
    else{
        if(dot_pos <2){
            //+1.234 -4
            //+0.0001234
            //+0.1234
            //+0.00001234
            printf("0.");
            for(int k=dot_pos; k<=0; k++){
                printf("0");
            }
            for(int k=1; result[k]!=0; k++){
                printf("%c", result[k]);
            }
        }
        else{
            for(int k=1; result[k]!=0; k++){
                if(k==dot_pos){
                    printf(".");
                }
                printf("%c", result[k]);
            }
        }
    }

    system("pause");
}