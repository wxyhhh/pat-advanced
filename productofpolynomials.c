#include <stdlib.h>
#include <stdio.h>

int main()
{
    double a[1001];
    double result[2001];
    int exp;
    double coe;
    int count = 0;

    int K1, K2;
    for(int i=0; i<1001; i++){
        a[i] = 0;
    }
    for(int i=0; i<2001; i++){
        result[i] = 0;
    }
    scanf("%d", &K1);
    for(int i=0; i<K1; i++){
        scanf("%d%lf", &exp, &coe);
        a[exp] = coe;
    }

    scanf("%d", &K2);
    for(int i=0; i<K2; i++){
        scanf("%d%lf", &exp, &coe);
        for(int j=0; j<1001;j++){
            if(a[j] != 0){
                result[exp+j] += coe*a[j];
            }
        }
    }

    for(int i=2000; i>=0; i--){
        if(result[i] != 0){
            count++;
        }
    }

    printf("%d", count);

    for(int i=2000; i>=0; i--){
        if(result[i] != 0){
            printf(" %d %.1lf", i, result[i]);
        }
    }

    system("pause");
}