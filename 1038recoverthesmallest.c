#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int comp(const void*a, const void*b){
    char str_a[20];
    char str_b[20];
    char tmp[10];

    strcpy(str_a, (char*)a);
    strcpy(str_b, (char*)b);

    strcpy(tmp, str_a);
    strcat(str_a, str_b);
    strcat(str_b, tmp);

    return strcmp(str_a, str_b);
}

int main()
{
    int N;
    char number[10005][10];
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%s", number[i]);
    }

    qsort(number, N, 10*sizeof(char), comp);

    int flag = 0;
    for(int i=0; i<N; i++){
        for(int j=0; number[i][j]!=0; j++){
            if(number[i][j] !='0' || flag !=0){
                flag = 1;
                printf("%c", number[i][j]);
            }
        }
    }
    if(flag == 0){
        printf("0");
    }
    system("pause");

    return 0;
}