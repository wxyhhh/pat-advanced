#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int f[10001][101];
int has[10001][101];
int coins[10001];
int coins_num = 0;

int comp(const void* a, const void* b)
{
    return *(int*)b -*(int*)a  ;
}

int main()
{  
    memset(has, 0, sizeof(int) * 10001 * 101);
    memset(f, 0, sizeof(int) * 10001 * 101);

    int N, M;
    int sequence[10001];
    scanf("%d%d", &N, &M);

    for(int i=1; i<=N; i++){
        scanf("%d", &sequence[i]);
    }
    qsort(sequence+1, N, sizeof(int), comp);

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++){
            f[i][j] = f[i-1][j];
            if(j-sequence[i]>=0 && f[i-1][j-sequence[i]] + sequence[i] >= f[i][j])
            {
                f[i][j] = f[i-1][j-sequence[i]] + sequence[i];
                has[i][j] = 1;
            }
        }
    }

    if(f[N][M] != M){
        printf("No Solution");
    }
    else{
        for(int i=N; i>=1; i--)
        {
            if(has[i][M] == 1){
                coins[coins_num++] = sequence[i];
                M -= sequence[i];
            }
            else{
                continue;
            }
        }

        for(int i=0; i<coins_num; i++)
        {
            printf("%d", coins[i]);
            if(i!= coins_num-1)
            {
                printf(" ");
            }
        }
    }

    system("pause");

}