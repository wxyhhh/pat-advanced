#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

vector <int> children[100000];
int count = 1;
int max_level = 0;

void dfs(int parent, int level)
{
    if(children[parent].size()==0)
    {
        if(level!=0)
        {
            if(level>max_level)
            {
                max_level = level;
                count = 1;
            }
            else if(level == max_level)
            {
                count++;
            }
        }
        return;
    }

    for(int i=0; i<children[parent].size(); i++)
    {
        dfs(children[parent][i], level+1);
    }
}

int main()
{
    int N;
    double p, r;
    int supplier;
    int root;

    scanf("%d%lf%lf", &N, &p, &r);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &supplier);
        if(supplier!= -1)
            children[supplier].push_back(i);
        else
            root = i;
    }

    dfs(root, 0);

    printf("%.2lf %d", p*pow(1+r/100, max_level), count);

    system("pause");
}
