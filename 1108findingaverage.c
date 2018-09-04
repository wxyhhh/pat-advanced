#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    char str[100];
    double sum = 0;
    int count = 0;
    scanf("%d", &N);

    for(int i=0; i<N; i++)
    {
        scanf("%s", str);
        int length = strlen(str);
        int dot = length;
        int flag = 0;
        int dot_flag = 0;
        for(int j=0; j<length; j++)
        {
            if((str[j] <'0' || str[j] >'9')&&str[j]!='-'&&str[j]!='.')
            {
                flag = 1;
                break;
            }
            else if(str[j] == '-' && j!=0)
            {
                flag = 1;
                break;
            }
            else if(str[j] == '.')
            {
                if(dot_flag)
                {
                    flag = 1;
                    break;
                }
                else{
                    dot_flag = 1;
                }
                if(length-j-1 > 2)
                {
                    flag = 1;
                    break;
                }
                dot = j;
            }            
        }
        if(flag == 1)
        {
            printf("ERROR: %s is not a legal number\n", str);
            continue;
        }
        double fraction = 0;
        double integer = 0;
        int start = 0;
        if(str[0] == '-')
        {
            start = 1;
        }
        for(int j= start; j<dot; j++)
        {
            integer = integer *10+ str[j]-'0';
        }
        for(int j=length-1; j>dot;j--)
        {
            fraction = fraction /10 +str[j]-'0';
        }
        fraction /= 10;
        double value = integer + fraction;
        if(start == 1)
        {
            value = -value;
        }
        if(value < -1000 || value > 1000)
        {
            printf("ERROR: %s is not a legal number\n", str);
            continue;
        }
        count++;
        sum += value;
    }

    if(count == 1)
    {
        printf("The average of 1 number is %.2lf", sum/count);
    }
    else if(count == 0)
    {
        printf("The average of 0 numbers is Undefined");
    }
    else
    {
        printf("The average of %d numbers is %.2lf", count, sum/count);
    }

    system("pause");
}