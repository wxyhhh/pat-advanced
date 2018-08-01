#include <stdlib.h>
#include <stdio.h>

struct customer{
    int arrive_time;
    int process_time;
};

struct window{
    int finish_time;
};

int compare(const void* a, const void* b){
    return (*(struct customer*)a).arrive_time - (*(struct customer*)b).arrive_time;
}

int main()
{
    int hh, mm, ss;
    struct customer *c;
    struct window *w;
    int N, K;
    int serve_num = 0;
    int total_time = 0;

    scanf("%d%d", &N, &K);

    c = (struct customer*)malloc(N*sizeof(*c));
    w = (struct window*)malloc(K*sizeof(*w));
    for(int i=0; i<N; i++){
        scanf("%d:%d:%d", &hh, &mm, &ss);
        c[i].arrive_time = hh*3600+mm*60+ss;
        scanf("%d", &mm);
        if(mm > 60){
            c[i].process_time = 3600;
        }
        else{
            c[i].process_time = mm * 60;
        }
    }

    for(int i=0; i<K; i++){
        w[i].finish_time = 8 * 60 * 60;
    }

    qsort(c, N, sizeof(struct customer), compare);
    for(int i=0; i<N; i++){
        if(c[i].arrive_time > 17*3600){
            continue;
        }
        int choice = 0;
        int earliest = w[0].finish_time;
        for(int j=1; j<K; j++){
            if(w[j].finish_time < earliest){
                choice = j;
                earliest = w[j].finish_time;
            }
            else{
                continue;
            }
        }

        //printf("early: %d\n", earliest);
        if(earliest < c[i].arrive_time){
            total_time += 0;
            w[choice].finish_time = c[i].arrive_time + c[i].process_time;
        }
        else{
            total_time += earliest - c[i].arrive_time;
            w[choice].finish_time += c[i].process_time;
        }
        //printf("第%d个 arrive%d total:%d\n", i, c[i].arrive_time, total_time);
        serve_num ++;

    }

    printf("%.1lf", (double)total_time/60/serve_num);
    system("pause");



}