#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1005];

    int* check[1001];
    int length;
    int max_sym = 1;

    gets(str);

    length = strlen(str);

    if(length == 1){
        max_sym = 1;
    }
    else if(length == 2){
        if(str[0] == str[1]){
            max_sym = 1;
        }
    }
    else{
        for(int i=0; i<length; i++){
            check[i] = (int*)malloc(length * sizeof(int));
        }
        for(int i=0; i<length; i++){
            for(int j=0; j<length; j++){
                check[i][j] = 0;
            }
            check[i][i] = 1;
            if(i!=length-1 && str[i] == str[i+1]){
                check[i][i+1] = 1;
                max_sym = 2;
            }
        }
        for(int i=2; i<length;i++){
            for(int j=0; j<length; j++){
                if(j + i <length){
                    if(str[j+i] == str[j] && check[j+1][j+i-1] == 1){
                        check[j][j+i] = 1;
                        if(i+1 > max_sym){
                            max_sym = i+1;
                        }
                    }
                }
            }
        }
    }

    printf("%d", max_sym);
    system("pause");
    return 0;
}