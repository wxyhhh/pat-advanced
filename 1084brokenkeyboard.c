#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    char a[81];
    char b[81];
    int known[37] = {0};

    scanf("%s", a);
    scanf("%s", b);

    int j=0;
    for(int i=0; a[i]!=0; i++)
    {
        if(a[i]!=b[j])
        {
            int tmp;
            if(a[i]>='0' && a[i]<='9')
            {
                tmp = a[i]-'0';
            }
            else if(a[i]>='a' && a[i]<='z')
            {
                tmp = 10 + a[i]-'a';
            }
            else if(a[i]>='A' && a[i]<= 'Z')
            {
                tmp = 10 + a[i]-'A';
            }
            else if(a[i] == '_'){
                tmp = 36;
            }

            if(known[tmp] == 1)
            {
                continue;
            }
            else{
                if(a[i]>='a' && a[i]<='z')
                    printf("%c", 'A' + a[i]-'a');
                else
                    printf("%c", a[i]);
                known[tmp] = 1;
            }
        }
        else{
            j++;
        }
    }

    system("pause");
}