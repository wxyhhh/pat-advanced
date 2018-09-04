#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    char number[100000];

    scanf("%s", number);
    int i;
    int integer = 0;
    double appendix = 0.0;
    double result;
    int appe_num = 0;
    int sig_num=0;
    int exponent = 0;
    int little_digits;
    for(i=1; number[i]!='.'&&number[i]!='E';i++)
    {
        integer = integer*10 + number[i] - '0';
    }

    if(number[i] == '.'){
        double factor = 0.1;
        for(i+=1; number[i]!='E'; i++)
        {
            appendix += factor * (number[i]-'0');
            factor /= 10;
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
        if(exponent > appe_num){
            appe_num = 0;
        }
        else{
            appe_num -= exponent;
        }
    }
    else{
        appe_num += -(exponent);
    }
    result = (integer + appendix) * pow(10, exponent);
    if(number[0] == '-')
    {
        result = -result;
    }

    printf("%.*lf", appe_num, result);

    system("pause");
}