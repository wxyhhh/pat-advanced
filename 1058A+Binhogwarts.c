#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a[3];
    int b[3];
    int result[3];

    scanf("%d.%d.%d", &a[0], &a[1], &a[2]);

    scanf("%d.%d.%d", &b[0], &b[1], &b[2]);

    int carry = 0;
    if(a[2] + b[2] >= 29){
        result[2] = a[2] + b[2] - 29;
        carry = 1;
    }
    else{
        result[2] = a[2] + b[2];
        carry = 0;
    }
    if(a[1] + b[1] + carry >= 17){
        result[1] = a[1] + b[1] + carry - 17;
        carry = 1;
    }
    else{
        result[1] = a[1] + b[1] + carry;
        carry = 0;
    }

    result[0] = carry + a[0] + b[0];

    for(int i=0; i<3; i++){
        printf("%d", result[i]);
        if(i!=2){
            printf(".");
        }
    }
    system("pause");

    return 0;
}