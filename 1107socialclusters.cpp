#include<iostream>
#include<algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int N;
bool known[1001] = {false};
map<int, vector<int> >hobbies;
vector<int>people[1001];
vector<int>clusters;

bool comp(int a, int b)
{
    return b < a;
}

int main()
{
    scanf("%d", &N);

    for(int i=1; i<=N; i++)
    {
        int count;
        scanf("%d:", &count);
        for(int j=0; j<count; j++)
        {
            int x;
            scanf("%d", &x);
            people[i].push_back(x);
            hobbies[x].push_back(i);
        }
    }

    for(int i=1; i<=N; i++)
    {
        bool h_known[1001] = {false};
        if(known[i] == true)
        {
            continue;
        }
        known[i] = true;
        int count = 0;
        queue<int> Q;
        count++;
        for(int j=0; j<people[i].size(); j++)
        {
            if(h_known[people[i][j]] == false)
            {
                Q.push(people[i][j]);
                h_known[people[i][j]] = true;
            }
        }
        while(Q.size()!=0)
        {
            int tmp = Q.front();
            Q.pop();
            for(int j = 0;j<hobbies[tmp].size(); j++)
            {
            	int tmp2 = hobbies[tmp][j];
            	if(known[tmp2] == true)
            	{
            		continue;
				}
				known[tmp2] = true;
                count++;
                for(int k=0; k<people[tmp2].size(); k++)
                {
                    if(h_known[people[tmp2][k]] == false)
                    {
                        Q.push(people[tmp2][k]);
                        h_known[people[tmp2][k]] = true;
                    }
                }
            }
        }
        clusters.push_back(count);
    }

    sort(clusters.begin(), clusters.end(), comp);

    printf("%d\n", clusters.size());

    for(int i=0; i<clusters.size(); i++)
    {
        printf("%d", clusters[i]);
        if(i!=clusters.size()-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}
