#include <stdlib.h>
#include <stdio.h>

int main()
{
    char a[61];
    char b[61];
    char c[61];
    char d[61];

    scanf("%s%s%s%s", a, b, c, d);
    int count = 0;
    for(int i=0; a[i]!=0&&b[i]!=0; i++)
    {
        if(a[i] == b[i])
        {
            if(count == 0){
                switch(a[i])
                {
                    case 'A': printf("MON");break;
                    case 'B': printf("TUE");break;
                    case 'C': printf("WED");break;
                    case 'D': printf("THU");break;
                    case 'E': printf("FRI");break;
                    case 'F': printf("SAT");break;
                    case 'G': printf("SUN");break;
                    default: count--;break;
                }

                count++;
            }
            else{
                if(a[i]>='0' && a[i]<='9'){
                    printf(" %02d:", a[i]-'0');
                }
                else if(a[i]>='A' && a[i]<='N'){
                    printf(" %02d:", a[i]-'A' + 10);
                }
                else{
                    continue;
                }
                break;
            }

        }
        else{
            continue;
        }
    }

    for(int i=0; c[i]!=0 && d[i]!=0; i++)
    {
        if(c[i]==d[i] ){
            if((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z')){
                printf("%02d", i);
                break;
            }
        }
    }

    system("pause");
}