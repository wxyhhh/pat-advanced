#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int n1, n2;

    int N;
    char str[100];
    char str1[50];
    char str3[50];
    char str2[100];

    scanf("%s", str);

    N = strlen(str);

    for(int i=3; i<=N;i++){
        if((N+2-i)%2 == 0 && (N+2-i)/2 <= i){
            n1 = (N+2-i)/2 - 1;
            n2 = i;
            break;
        }
    }
    int i = 0;
    for(i=0; i<n1; i++){
        str1[i] = str[i];
        str3[i] = str[N-1-i];
    }

    str1[i] = str3[i] = 0;

    for(i=0; i<n2; i++){
        str2[i] = str[n1+i];
    }
    str2[i] = 0;

    for(i=0; i<n1; i++){
        printf("%c", str1[i]);
        for(int j=0; j<n2-2; j++){
            printf(" ");
        }
        printf("%c\n", str3[i]);
    }
    printf("%s", str2);

    system("pause");
    return 0;
}