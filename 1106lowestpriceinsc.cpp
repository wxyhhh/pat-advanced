#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <queue>
#include <cmath>

using namespace std;

vector<int>followers[100000];
int final_count = 0;
int least_level = INT_MAX;

void bfs()
{
    queue<int>Q;
    Q.push(0);
    int current_level = 0;

    while(Q.size()!=0)
    {
        int current_size = Q.size();
        int flag = 0;
        for(int i=0; i<current_size; i++)
        {
            int tmp = Q.front();
            Q.pop();
            if(followers[tmp].size() == 0)
            {
                least_level = current_level;
                final_count ++;
                flag = 1;
            }
            for(int j=0; j<followers[tmp].size(); j++)
            {
                Q.push(followers[tmp][j]);
            }
        }
        if(flag == 1)
        {
            break;
        }
        current_level++;
    }
}

int main()
{
    int N;
    double p, r;
    int count, follower;

    scanf("%d%lf%lf", &N, &p, &r);
    for(int i=0; i<N;i++)
    {
        scanf("%d", &count);
        for(int j=0; j<count; j++)
        {
            scanf("%d", &follower);
            followers[i].push_back(follower);
        }
    }

    bfs();

    printf("%.4lf %d", p*pow(1+r/100, least_level), final_count);
}
