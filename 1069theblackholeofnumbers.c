#include <stdlib.h>
#include <stdio.h>

int comp(const void*a, const void*b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int N;
    int a[4];
    int number1, number2, difference;
    
    scanf("%d", &N);

    if(N==0 || N%1111 == 0){
        printf("%d - %d = 0000", N, N);
    }
    else{
        for(int i=0; i<4; i++)
        {
            a[i] = N % 10;
            N = N/10;
        }
        qsort(a, 4, sizeof(int), comp);
        do{
            qsort(a, 4, sizeof(int), comp);
            number1 = number2 = 0;
            for(int i=0; i<4; i++)
            {
                number2 = number2 * 10 + a[i];
                number1 = number1 * 10 + a[3-i];
            }

            printf("%04d - %04d = %04d\n", number1, number2, number1-number2);
            difference = number1 - number2;
            for(int i=0; i<4; i++)
            {
                a[i] = (difference) % 10;
                difference = difference/10;
            }
        }while(number1 - number2 != 6174);

    }

    system("pause");
}