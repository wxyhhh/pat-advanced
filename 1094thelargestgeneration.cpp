#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std; 

struct node
{
    int id;
    vector<int>children;
};

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);

    node family[N+1];
    int v;
    int count;
    int x;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &v, &count);
        for(int j=0; j<count; j++)
        {
            scanf("%d", &x);
            family[v].children.push_back(x);
        }
    }

    queue<node> Q;
    int max_gen = 1;
    int max_pop = 0;
    int current_gen = 1;
    Q.push(family[1]);
    while(Q.size()!=0)
    {
        int current_pop = Q.size();
        if(current_pop > max_pop)
        {
            max_pop = current_pop;
            max_gen = current_gen;
        }
        current_gen++;

        for(int i=0; i<current_pop; i++)
        {
            node tmpnode = Q.front();
            Q.pop();
            for(int j=0; j<tmpnode.children.size(); j++)
            {
                Q.push(family[tmpnode.children[j]]);
            }
        }
    }

    printf("%d %d", max_pop, max_gen);

    system("pause");
}
