#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    char a[300];
    char b[300];
    int la, lb;
    int k_length;
    int count;

    int N;

    scanf("%d", &N);
    getchar();
    gets(a);
    la = strlen(a);
    k_length = strlen(a);
    for(int i=0; i<N-1; i++)
    {
        count = 0;
        gets(b);
        lb = strlen(b);

        for(int j=la-1, k=lb-1; j>=0 && k>=0; j--, k--)
        {
            if(a[j] == b[k])
            {
                count++;
            }
            else{
                break;
            }
        }

        if(count < k_length)
        {
            k_length = count;
        }

        strcpy(a, b);
        la = lb;
    }

    if(k_length > 0)
    {
        for(int i=0; i<k_length; i++)
        {
            printf("%c", a[la-k_length+i]);
        }
    }

    else{
        printf("nai");
    }

    system("pause");
}