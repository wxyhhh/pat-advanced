#include <stdlib.h>
#include <stdio.h>

struct serve_window{
    int customers[1001];
    int front, rear;
    int num;
    int leavetime;
    int finishtime;
};
int main()
{
    int T[1001];
    int startT[1001];
    struct serve_window windows[20];
    int N, M, K, Q;
    int next;

    scanf("%d%d%d%d", &N, &M, &K, &Q);
    next = 1;

    for(int i=1; i<=K; i++){
        scanf("%d", &T[i]);
    }
    for(int i=0; i<N; i++){
        windows[i].front = 0;
        windows[i].rear = 0;
        windows[i].num = windows[i].leavetime = windows[i].finishtime = 0;
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(next > K){
                break;
            }
            if(i==0){
                startT[next] = 0;
                windows[j].leavetime = windows[j].finishtime = 0+T[next];
            }
            else{
                startT[next] =windows[j].finishtime;
                windows[j].finishtime += T[next];
            }
            windows[j].customers[windows[j].rear] = next;
            windows[j].rear++;
            windows[j].num++;
            next++;
        }
    }

    while(next <= K){
        int earliest = windows[0].leavetime;
        int choice = 0;

        for(int i=1; i<N; i++){
            if(windows[i].leavetime < earliest){
                earliest = windows[i].leavetime;
                choice = i;
            }
        }

        //pop
        windows[choice].front++;
        windows[choice].leavetime += T[windows[choice].customers[windows[choice].front]];
        windows[choice].customers[windows[choice].rear] = next;
        windows[choice].rear++;
        startT[next] = windows[choice].finishtime;
        windows[choice].finishtime += T[next];
        next++;

    }

    for(int i=0; i<Q; i++){
        int query;
        scanf("%d", &query);

        if(startT[query] >= 540){
            printf("Sorry");
        }
        else{
            printf("%02d:%02d", 8+(startT[query]+T[query])/60, (startT[query]+T[query])%60);
        }

        if(i!=Q-1){
            printf("\n");
        }
    }

    system("pause");

}