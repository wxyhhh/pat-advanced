#include <stdlib.h>
#include <stdio.h>

struct node
{
    int next_addr;
    int value;
};


int main()
{
    struct node ll[100000];

    int N;
    int node_num = 0;
    int start_addr;
    int K;
    int addr, value, next_addr;

    scanf("%d%d%d", &start_addr, &N, &K);

    for(int i=0; i<N; i++)
    {
        scanf("%d%d%d", &addr, &value, &next_addr);
        ll[addr].value = value;
        ll[addr].next_addr = next_addr;
    }
    for(int i=start_addr; i!=-1; i=ll[i].next_addr){
        node_num++;
    }
    int reverse_time = node_num / K;

    int current_addr = start_addr;
    int count = 0;
    int reverse_count = 0;
    int tail = start_addr;
    int head;
    int last = -1;
    int flag = 0;
    while(1)
    {
        if(count == K){
            if(flag == 0){
                start_addr = last;
                head = current_addr;
                flag = 1;
            }
            else{
                ll[tail].next_addr = last;
                tail = head;
                head = current_addr;
            }
            if(current_addr == -1){
                ll[tail].next_addr = -1;
                break;
            }
            reverse_count ++;
            if(reverse_count == reverse_time){
                ll[tail].next_addr = current_addr;
                break;
            }
            count = 0;
            last = current_addr;
            current_addr = ll[current_addr].next_addr;
            count++;
        }
        // else if(count <K && ll[current_addr].next_addr == -1){
        //     if(flag == 0){
        //         start_addr = current_addr;
        //         ll[current_addr].next_addr = last;
        //         ll[tail].next_addr = -1;
        //     }
        //     else{
        //         ll[head].next_addr = -1;
        //         ll[tail].next_addr = current_addr;
        //         ll[current_addr].next_addr = last;
        //     }
        //     break;
        // }
        else{
            if(current_addr == -1){
                break;
            }
            int tmp = ll[current_addr].next_addr;
            ll[current_addr].next_addr = last;
            last = current_addr;
            current_addr = tmp;
            count ++;
        }
        
    }

    for(int i=start_addr; i!=-1; i=ll[i].next_addr){
        printf("%05d %d ", i, ll[i].value);
        if(ll[i].next_addr == -1){
            printf("-1\n");
        }
        else{
            printf("%05d\n", ll[i].next_addr);
        }
    }
    system("pause");
}