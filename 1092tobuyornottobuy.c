#include <stdlib.h>
#include <stdio.h>

int main()
{
    int ch[62] = {0};

    char a[1001];
    char b[1001];

    scanf("%s", a);
    scanf("%s", b);

    for(int i=0; b[i]!=0; i++)
    {
        if(b[i]>='0' && b[i]<='9')
        {
            ch[0+b[i]-'0'] += 1;
        }
        else if(b[i]>='a' && b[i]<='z')
        {
            ch[10+b[i]-'a'] += 1;
        }
        else if(b[i]>='A' && b[i]<='Z')
        {
            ch[36+b[i]-'A'] += 1;
        }
    }

    for(int i=0; a[i]!=0; i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            ch[0+a[i]-'0'] -= 1;
        }
        if(a[i]>='a' && a[i]<='z')
        {
            ch[10+a[i]-'a'] -= 1;
        }
        if(a[i]>='A' && a[i]<='Z')
        {
            ch[36+a[i]-'A'] -= 1;
        }
    }

    int flag = 1;
    int extra = 0;
    int lack = 0;
    for(int i=0; i<62; i++)
    {
        if(ch[i] > 0)
        {
            flag = 0;
            lack += ch[i];
        }
        else
        {
            extra += -ch[i];
        }
    }

    if(flag == 1)
    {
        printf("Yes %d", extra);
    }
    else
    {
        printf("No %d", lack);
    }

    system("pause");
}