#include <stdlib.h>
#include <stdio.h>

struct node
{
    int address;
    int key;
    int next;
};

int comp(const void* a, const void* b)
{
    return (*(struct node*)a).key - (*(struct node*)b).key;
}

int main()
{
    struct node ll[100000];
    int real_num = 0;
    struct node *origin;

    int N, head;

    scanf("%d%d", &N, &head);

    if(N == 0 || head == -1){
        printf("0 -1");
        return 0;
    }
    origin = (struct node*)malloc(100000*sizeof(struct node));
    for(int i=0; i<N; i++){
        int address, next, key;
        scanf("%d", &address);
        origin[address].address = address;
        scanf("%d%d", &origin[address].key, &origin[address].next);
    }

    int k = head;
    while(k!=-1){
        ll[real_num].address = k;
        ll[real_num].key = origin[k].key;
        ll[real_num].next = origin[k].next;
        real_num ++;
        k = origin[k].next;
    }

    qsort(ll, real_num, sizeof(struct node), comp);
    printf("%d %05d\n", real_num, ll[0].address);
    for(int i=0; i<real_num; i++){
        if(i!=real_num-1){
            ll[i].next = ll[i+1].address;
        }
        else{
            ll[i].next = -1;
        }

        printf("%05d %d ", ll[i].address, ll[i].key);

        if(i == real_num-1){
            printf("-1");
        }
        else{
            printf("%05d\n", ll[i].next);
        }
    }

    system("pause");
}