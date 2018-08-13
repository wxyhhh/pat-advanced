#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer{
    int arrive_time;
    int serve_time;
    int need_time;
    int wait_time;
    int ifvip;
};

struct table{
    int serve_num;
    int finish_time;
    int ifvip;
};

int comp(const void*a, const void*b){
    struct customer customer_a = *(struct customer*)a;
    struct customer customer_b = *(struct customer*)b;

    return customer_a.arrive_time - customer_b.arrive_time;
}

int main()
{
    struct customer* c;
    int count_c = 0;
    struct customer* vc;
    int count_vc = 0;
    struct table* t;
    int N, K, M;

    scanf("%d", &N);

    c = (struct customer*)malloc(N*sizeof(*c));
    vc = (struct customer*)malloc(N*sizeof(*vc));
    
    for(int i=0; i<N; i++){
        int flag;
        int hh, mm, ss;
        int duration;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &duration, &flag);

        if(flag == 0){
            c[count_c].arrive_time = hh*3600+mm*60+ss;
            c[count_c].need_time = duration*60;
            c[count_c].ifvip = 0;
            count_c++;
        }
        else{
            vc[count_vc].arrive_time = hh*3600+mm*60+ss;
            vc[count_vc].need_time = duration*60;
            vc[count_vc].ifvip = 1;
            count_vc++;
        }
    }
    qsort(c, count_c, sizeof(struct customer), comp);
    qsort(vc, count_vc, sizeof(struct customer), comp);

    scanf("%d", &K);
    t = (struct table *)malloc((K+1)*sizeof(struct table));
    for(int i=1; i<=K; i++){
        t[i].finish_time = 8 * 3600;
        t[i].ifvip = 0;
        t[i].serve_num = 0;
    }
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int tmp;
        scanf("%d", &tmp);
        t[tmp].ifvip = 1; 
    }

    int this_arrive_time;
    int this_need_time;
    int table_choice;
    int tmp_finish_time;
    int vip_choice;
    int tmp_vip_finish_time;
    int vip_flag;
    for(int i=0, j=0; i<count_c||j<count_vc;){
        table_choice = 1;
        vip_choice = 1;
        tmp_finish_time = 21*3600;
        tmp_vip_finish_time = 21*3600;
        for(int k=1; k<=K; k++){
            if(t[k].finish_time < tmp_finish_time){
                table_choice = k;
                tmp_finish_time = t[k].finish_time;
            }
            if(t[k].finish_time < tmp_vip_finish_time && t[k].ifvip == 1){
                tmp_vip_finish_time = t[k].finish_time;
                vip_choice = k;
            }
        }
        if(tmp_finish_time >= 21*3600){
            break;
        }
        if(i >= count_c){
            this_arrive_time = vc[j].arrive_time;
            this_need_time = vc[j].need_time;
            j++;
            vip_flag = 1;
        }
        else if(j >= count_vc){
            this_arrive_time = c[i].arrive_time;
            this_need_time = c[i].need_time;
            i++;
            vip_flag = 0;
        }
        else{
            if(t[table_choice].ifvip == 1){
                if(c[i].arrive_time > vc[j].arrive_time || t[table_choice].finish_time >= vc[j].arrive_time){
                    this_arrive_time = vc[j].arrive_time;
                    this_need_time = vc[j].need_time;
                    j++;
                    vip_flag = 1;
                }
                else{
                    this_arrive_time = c[i].arrive_time;
                    this_need_time = c[i].need_time;
                    i++;
                    vip_flag = 0;
                }
            }
            else{
                if(c[i].arrive_time > vc[j].arrive_time){
                    this_arrive_time = vc[j].arrive_time;
                    this_need_time = vc[j].need_time;
                    j++;
                    vip_flag = 1;
                }
                else{
                    this_arrive_time = c[i].arrive_time;
                    this_need_time = c[i].need_time;
                    i++;
                    vip_flag = 0;
                }
            }
        } 
        if(this_arrive_time >= 21*3600){
            break;
        }
        //下一个是vip时，如果他到达的时间晚于最早的vip桌空闲，才选择vip桌子
        if(vip_flag == 1 && this_arrive_time >= t[vip_choice].finish_time){
            table_choice = vip_choice;
        }
        printf("%02d:%02d:%02d ", this_arrive_time/3600, this_arrive_time/60%60, this_arrive_time%60);
        int wait_time, serve_time;
        if(t[table_choice].finish_time < this_arrive_time)
            serve_time = this_arrive_time;
        else{
            serve_time = t[table_choice].finish_time;
        }
        wait_time = serve_time - this_arrive_time;
        printf("%02d:%02d:%02d ", serve_time/3600, serve_time/60%60, serve_time%60);
        printf("%d\n", (wait_time+30)/60);
        t[table_choice].serve_num++;
        if(this_need_time > 120*60){
            this_need_time = 120 * 60;
        }
        t[table_choice].finish_time = serve_time + this_need_time;
    }

    for(int i=1; i<=K; i++){
        printf("%d", t[i].serve_num);
        if(i!=K){
            printf(" ");
        }
    }

    system("pause");

}