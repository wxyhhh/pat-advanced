#include <stdlib.h>
#include <stdio.h>


int main()
{
    char a[10005];
    char b[10005];
    int existed[1000] = {0};

    gets(a);
    gets(b);

    for(int i=0; b[i]!=0; i++){
        existed[b[i]] = 1;
    }

    for(int i=0; a[i]!=0; i++){
        if(existed[a[i]]!=1){
            printf("%c", a[i]);
        }
    }

    system("pause");
}