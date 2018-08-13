#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    int* a;
    int b;
    int count_a;
    int count_b;

    scanf("%d", &count_a);
    a = (int*)malloc(count_a*sizeof(int));
    for(int j=0; j<count_a; j++)
    {
        scanf("%d", &a[j]);
    }

    a[count_a] = INT_MAX;

    scanf("%d", &count_b);

    int i=0, j=0;
    int count=0;
    int index = (count_a + count_b - 1)/ 2;

    if(count_b == 0){
        printf("%d", a[index]);
        system("pause");
        return 0;
    }
    scanf("%d", &b);
    for(;count < index;){
        if(b > a[i]){
            i++;
        }
        else{
            j++;
            if(j < count_b){
                scanf("%d", &b);
            }
            else if(j == count_b){
                b = INT_MAX;
            }
            else{
                break;
            }
        }

        count++;
    }

    if(a[i] > b){
        printf("%d", b);
    }
    else{
        printf("%d", a[i]);
    }

    system("pause");
    return 0;
}