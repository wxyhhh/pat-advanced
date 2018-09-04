#include<iostream>
#include<cstdlib>
#include<vector>
#include <cmath>
#include <algorithm>
//DFS暴力搜索，但是要注意剪枝。
using namespace std;
int N, K, P;
vector<int> final;
int final_sum = 0;
bool dfs(int difference, vector<int>&factors, int sum, int start, int count)
{
    if(count == K)
    {
        if(difference == 0)
        {
            if(sum >= final_sum)
            {
                final = factors;
                final_sum = sum;
            }
            return true;
        }
        else{
            return false;
        }
    }
    int end = sqrt(difference);
    bool flag = false;
    for(int i=start; i<= end; i++)
    {
        int current = difference - pow(i, P);
        if(current < 0)
        {
            return flag;
        }
        factors[count] = i;
        if(dfs(current, factors, sum+i, i, count+1))
        {
            flag = true;
        } 
    }

    return flag;
}

bool comp(int a, int b)
{
    return a>b;
}

int main()
{
    scanf("%d%d%d", &N, &K, &P);
    vector<int>factors(K);
    int flag = dfs(N, factors, 0, 1, 0);
    reverse(final.begin(), final.end());
    if(flag)
    {
        printf("%d = %d^%d", N, final[0], P);
        if(K>1)
        {
            for(int i=1; i<K; i++)
            {
                printf(" + %d^%d", final[i], P);
            }
        }
    }

    else
    {
        printf("Impossible");
    }
}
