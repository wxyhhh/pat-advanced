#include <stdlib.h>
#include <stdio.h>

int LCS[201][10001]={0};

int main()
{
    int N;
    int favorite_num;
    int given_num;
    int favorite[200];
    int given[10000];

    scanf("%d", &N);

    scanf("%d", &favorite_num);

    for(int i=0; i<favorite_num; i++){
        scanf("%d", &favorite[i]);
    }

    scanf("%d", &given_num);
    
    for(int i=0; i<given_num; i++){
        scanf("%d", &given[i]);
    }

    for(int i=1; i<=favorite_num; i++){
        for(int j=1; j<=given_num; j++){
            int tmp_max = LCS[i-1][j-1];
            if(tmp_max < LCS[i-1][j]){
                tmp_max = LCS[i-1][j];
            }
            if(tmp_max < LCS[i][j-1]){
                tmp_max = LCS[i][j-1];
            }
            if(favorite[i-1] == given[j-1]){
                LCS[i][j] = tmp_max + 1;
            }
            else{
                LCS[i][j] = tmp_max;
            }
        }
    }

    printf("%d", LCS[favorite_num][given_num]);

    system("pause");

    return 0;
}