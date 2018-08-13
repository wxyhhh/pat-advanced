#include <stdlib.h>
#include <stdio.h>


int main()
{
    int r, g, b;
    char red[3] = "00";
    char green[3] = "00";
    char blue[3] = "00";

    scanf("%d%d%d", &r, &g, &b);

    printf("#");

    int end = 1;
    while(r!=0){
        int tmp = r%13;
        if(tmp<10){
            tmp = '0' + tmp;
        }
        else{
            tmp = 'A' + tmp -10;
        }
        red[end--] = tmp;
        r = r/13;
    }
    printf("%s", red);
    end = 1;
    while(g!=0){
        int tmp = g%13;
        if(tmp<10){
            tmp = '0' + tmp;
        }
        else{
            tmp = 'A' + tmp -10;
        }
        green[end--] = tmp;
        g = g/13;
    }
    printf("%s", green);
    end = 1;
    while(b!=0){
        int tmp = b%13;
        if(tmp<10){
            tmp = '0' + tmp;
        }
        else{
            tmp = 'A' + tmp -10;
        }
        blue[end--] = tmp;
        b = b/13;
    }
    printf("%s", blue);
    system("pause");

    return 0;

}