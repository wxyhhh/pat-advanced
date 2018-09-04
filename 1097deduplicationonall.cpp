#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std; 

struct node
{
    int value;
    int next;
    bool flag;
};

node ll[100000];
int exist[10001] = {0};

int main()
{
    int start_addr, N;
    int r_start_addr=-1, r_current_addr=-1;
    scanf("%d%d", &start_addr, &N);

    int current, next, value;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d%d", &current, &value, &next);
        ll[current].value = value;
        ll[current].next = next;
    }

    current = start_addr;
    int last = -1;
    int abso = abs(ll[current].value);
    exist[abso] = 1;
    last = current;
    current = ll[current].next;
    while(current!=-1)
    {
        abso = abs(ll[current].value);
        if(exist[abso])
        {
            ll[last].next = ll[current].next;
            if(r_start_addr == -1)
            {
                r_start_addr = current;
                r_current_addr = current;
                ll[current].next = -1;
            }
            else
            {
                ll[r_current_addr].next = current;
                ll[current].next = -1;
                r_current_addr = current;
            }
            current = ll[last].next;
        }
        else
        {
            exist[abso] += 1;
            last = current;
            current = ll[current].next;
        }
    }

    for(int i= start_addr; i!=-1; i=ll[i].next)
    {
        printf("%05d %d ", i, ll[i].value);
        if(ll[i].next == -1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%05d\n", ll[i].next);
        }
    }

    for(int i= r_start_addr; i!=-1; i=ll[i].next)
    {
        printf("%05d %d ", i, ll[i].value);
        if(ll[i].next == -1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%05d\n", ll[i].next);
        }
    }
}
