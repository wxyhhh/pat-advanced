#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int M, N;
int hashtable[20000];
int pos[20000];
int isprime(int number)
{
    int flag = 1;
    int end = (int)sqrt(number);

    if(number == 1){
        return 0;
    }
    if(number == 2){
        return 1;
    }
    for(int i=2; i<=end; i++){
        if(number % i == 0)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}

int findprime(int start)
{
    for(int i=start+1; i<=20000; i++)
    {
        if(isprime(i)){
            return i;
        }
        else{
            continue;
        }
    }
}

void hashInsert(int number, int index)
{
    int position = number % M;
    int i=0;
    int flag = 0;
    while(i < M){
        if(hashtable[(position + i*i)%M] > 0){
            i++;
        }
        else{
            hashtable[(position + i*i)%M] = number;
            pos[index] = (position + i*i)%M;
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        pos[index] = -1;
    }
}

int main()
{
    int num;

    scanf("%d%d", &M, &N);

    if(!isprime(M)){
        M = findprime(M);
    }

    for(int i=0; i<M; i++)
    {
        hashtable[i] = -1;
    }

    for(int i=0; i<N; i++)
    {
        pos[i] = -1;
    }
    
    for(int i=0; i<N; i++)
    {
        scanf("%d", &num);
        hashInsert(num, i);
    }

    for(int i=0; i<N; i++)
    {
        if(pos[i] != -1)
        {
            printf("%d", pos[i]);
        }
        else{
            printf("-");
        }

        if(i!=N-1)
        {
            printf(" ");
        }
    }

    system("pause");
}