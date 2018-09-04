#include <stdlib.h>
#include <stdio.h>

struct rational
{
    long n;
    long d;
};

long gcd(long a, long b)
{
    if(a<0)
		a=-a;
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void r_print(struct rational x)
{
    if(x.n!=0 && x.d != 0)
    {
        int tmp = gcd(x.n, x.d);
        x.n /= tmp;
        x.d /= tmp;
    }
    long integer = x.n / x.d;
    int n_flag = 0;
    if(x.n == 0)
    {
        printf("0");
        return;
    }
    if(x.n < 0)
    {
        n_flag = 1;
    }
    if(n_flag == 1)
    {
        printf("(");
    }
    if(integer!= 0 && x.n%x.d != 0)
    {
        if(n_flag)
        {
            printf("%ld %ld/%ld", integer, -x.n%x.d, x.d);
        }
        else{
            printf("%ld %ld/%ld", integer, x.n%x.d, x.d);
        }
    }
    else if(integer != 0)
    {
        printf("%ld", integer);
    }
    else{
        printf("%ld/%ld", x.n, x.d);
    }

    if(n_flag == 1)
    {
        printf(")");
    }
}

int main()
{
    struct rational first;
    struct rational second;
    struct rational result[4];
    int flag = 0;

    scanf("%ld/%ld %ld/%ld", &first.n, &first.d, &second.n, &second.d);

    long factor = gcd(first.d, second.d);
    long lct = first.d * second.d* factor;

    result[0].n = first.n*(lct/first.d) + second.n*(lct/second.d);
    result[0].d = lct;

    result[1].n = first.n*(lct/first.d) - second.n*(lct/second.d);
    result[1].d = lct;


    result[2].n = first.n * second.n;
    result[2].d = first.d * second.d;

    if(second.n == 0)
    {
        flag =1;
    }
    else if(first.n == 0)
    {
        result[3].n = 0;
        result[3].d = 1;
    }
    else{
        if(second.n < 0)
        {
            second.d = -second.d;
            second.n = -second.n;
            result[3].n = first.n * second.d;
            result[3].d = first.d * second.n;
            second.d = -second.d;
            second.n = -second.n;
        }
        else{
            result[3].n = first.n * second.d;
            result[3].d = first.d * second.n;
        }

    }

    for(int i=0; i<4; i++)
    {
        r_print(first);

        if(i == 0)
        {
            printf(" + ");
        }
        else if(i == 1)
        {
            printf(" - ");
        }
        else if(i == 2)
        {
            printf(" * ");
        }
        else if(i == 3)
        {
            printf(" / ");
        }

        r_print(second);

        printf(" = ");
        if(i==3 && flag == 1)
        {
            printf("Inf");
        }
        else{
            r_print(result[i]);
        }

        if(i != 3)
        {
            printf("\n");
        }
    }

    system("pause");
}