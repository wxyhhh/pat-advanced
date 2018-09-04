#include <stdlib.h>
#include <stdio.h>

int main()
{
    int stucked[300] = {0};
    char find[1001];
    int findcount = 0;
    char result[1001];
    int resultcount = 0;
    //0为判断 1 有可能是 2 不可能是
    int k;

    scanf("%d", &k);

    char str[1001];

    scanf("%s", str);

    for(int i=0; str[i]!=0; )
    {
        int j=i;
        int count = 0;
        while(str[j] == str[i])
        {
            j++;
            count++;
        }
        if(count % k == 0 && stucked[str[i]] == 0)
        {
            stucked[str[i]] = 1;
            find[findcount++] = str[i];
        }
        else if(count % k !=0)
        {
            stucked[str[i]] = 2;
        }
        i=j;
    }
    find[findcount] = 0;

    for(int i=0; find[i]!=0; i++)
    {
        if(stucked[find[i]] == 1)
        {
            printf("%c", find[i]);
        }
    }
    printf("\n");

    for(int i=0; str[i]!=0; )
    {
        int j=i;
        int count = 0;
        while(str[j] == str[i])
        {
            j++;
            count++;
        }
        if(stucked[str[i]] == 1)
        {
            for(int l=0; l<count/k; l++)
            {
                printf("%c", str[i]);
            }
        }
        else
        {
            for(int l=0; l<count; l++)
            {
                printf("%c", str[i]);
            }
        }
        i=j;
    }

    printf("\n");

    system("pause");
}