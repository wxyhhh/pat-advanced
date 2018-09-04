#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct app
{
    int ge;
    int gi;
    double avg;
    int index;
    int target[5];
    int rank;
};

bool comp(app a, app b)
{
    if(a.avg != b.avg)
    {
        return a.avg > b.avg;
    }
    return a.ge > b.ge;
}

bool comp2(int a, int b)
{
    return a<b;
}

struct school
{
    int last_rank;
    vector <int> admit;
    int quota;
};


int main()
{
    int N, M, K;
    app apps[40000];
    school school_list[100];
    scanf("%d%d%d", &N, &M, &K);

    for(int i=0; i<M; i++)
    {
        scanf("%d", &school_list[i].quota); 
    }

    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &apps[i].ge, &apps[i].gi);
        apps[i].avg = (apps[i].ge + apps[i].gi) / 2.0;
        apps[i].index = i;

        for(int j=0; j<K; j++)
        {
            scanf("%d", &apps[i].target[j]);
        }
    }

    sort(apps, apps+N, comp);

    int c_rank = 1;
    double c_avg = apps[0].avg;
    int c_ge = apps[0].ge;
    for(int i=0; i<N; i++)
    {
        if(apps[i].avg == c_avg && apps[i].ge == c_ge){
            apps[i].rank = c_rank;
        }
        else{
            apps[i].rank = i+1;
            c_rank = i+1;
            c_avg = apps[i].avg;
            c_ge = apps[i].ge;
        }

        for(int j=0; j<K; j++)
        {
            int tmp = apps[i].target[j];
            int tmp_size = school_list[tmp].admit.size();
            if(tmp_size < school_list[tmp].quota)
            {
                school_list[tmp].admit.push_back(apps[i].index);
                if(tmp_size+1 == school_list[tmp].quota)
                {
                    school_list[tmp].last_rank = apps[i].rank;
                }
                break;
            }
            else if(apps[i].rank == school_list[tmp].last_rank){
                school_list[tmp].admit.push_back(apps[i].index);
                break;
            }
            else{
                continue;
            }
        }
    }

    for(int i=0; i<M; i++)
    {
        if(school_list[i].admit.size() != 0)
        {
            sort(school_list[i].admit.begin(), school_list[i].admit.end(), comp2);
            printf("%d", school_list[i].admit[0]);
            for(int j=1; j<school_list[i].admit.size(); j++)
            {
                printf(" %d", school_list[i].admit[j]);
            }
        }
        printf("\n");
        
    }
    
}
