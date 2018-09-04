#include <stdlib.h>
#include <stdio.h>


int main()
{
    long long int a, b, c;
    int T;
    long long int res;

    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        res = a+b;
        
        printf("Case #%d: ", i+1);
        if(a>0 && b>0 &&res<=0){
            printf("true\n");
        }
        else if(a<0 && b<0 && res>=0){
            printf("false\n");
        }
        else if(res>c) {
            printf("true\n");
        }
        else{
            printf("false\n");
        }
    }

    system("pause");

}