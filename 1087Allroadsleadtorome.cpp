#include <iostream>
#include <map>
#include <vector>
#include <climits>

using namespace std;

map<int, string> i2str;
map<string, int> str2i;

int happiness[200];

struct city
{
    int known;
    int count;
    int dist;
    int cost;
    int total_h;
    double avg_h;
    int path;
}c[200];

int N, K;

int getMinVertex()
{
    int choice = -1;
    int c_cost = INT_MAX;
    for(int i=0; i<N; i++)
    {
        if(c[i].known != 1)
        {
            if(c[i].cost < c_cost)
            {
                choice = i;
                c_cost = c[i].cost;
            }
        }
    }

    return choice;
}

int main()
{
    int graph[200][200];
    scanf("%d%d", &N, &K);
    getchar();
    string start;
    string tmp_city, tmp_city1;
    int tmp_cost;
    cin >> start;
    i2str[0] = start;
    str2i[start] = 0;

    for(int i=1; i<=N-1; i++ )
    {
        cin >> tmp_city >> happiness[i];
        i2str[i] = tmp_city;
        str2i[tmp_city] = i;
    }

    for(int i=0; i<N; i++)
    {
        c[i].known = 0;
        c[i].count = 0;
        c[i].dist = 0;
        c[i].cost = INT_MAX;
        for(int j=0; j<N; j++)
        {
            graph[i][j] = -1; 
        }
    }
    c[0].known = 1;
    c[0].count = 1;
    c[0].total_h = 0;
    c[0].avg_h = 0;
    c[0].cost = 0;
    c[0].path = -1;
    for(int i=0; i<K; i++)
    {
        cin >> tmp_city >> tmp_city1 >> tmp_cost;
        int v = str2i[tmp_city];
        int w = str2i[tmp_city1];
        graph[v][w] = graph[w][v] = tmp_cost;
    }
    int rome = str2i["ROM"];
    for(int v=0; v!=-1; v = getMinVertex())
    {
        c[v].known = 1;

        if(v==rome)
        {
            break;
        }
        for(int w=0; w<N; w++)
        {
            if(c[w].known == 1)
            {
                continue;
            }
            if(graph[v][w] >= 0)
            {
                if(c[v].cost + graph[v][w] < c[w].cost)
                {
                    c[w].count = c[v].count;
                    c[w].dist = c[v].dist + 1;
                    c[w].cost = c[v].cost + graph[v][w];
                    c[w].total_h = c[v].total_h + happiness[w];
                    c[w].avg_h = (double)c[w].total_h / c[w].dist;
                    c[w].path = v;
                }
                else if(c[v].cost + graph[v][w] == c[w].cost)
                {
                	//注意迪杰斯特拉中统计路径数要加上上一个点的路径条数，而不是只加一！
					 
                    c[w].count += c[v].count;
                    if(c[v].total_h + happiness[w] > c[w].total_h)
                    {
                        c[w].dist = c[v].dist + 1;
                        c[w].total_h = c[v].total_h + happiness[w];
                        c[w].avg_h = (double)c[w].total_h / c[w].dist;
                        c[w].path = v;
                    }
                    else if(c[v].total_h + happiness[w] == c[w].total_h)
                    {
                        if(c[w].avg_h < (double)c[w].total_h/(c[v].dist+1))
                        {
                            c[w].dist = c[v].dist + 1;
                            c[w].avg_h = (double)c[w].total_h / c[w].dist;
                            c[w].path = v;

                        }
                    }
                }
            }
        }
    }

    printf("%d %d %d %d\n", c[rome].count, c[rome].cost, c[rome].total_h, (int)c[rome].avg_h);
    vector <string> fullpath;
    while(rome!=-1)
    {
        fullpath.push_back(i2str[rome]);
        rome = c[rome].path;
    }

    for(int i=fullpath.size()-1; i>=0; i--)
    {
        cout << fullpath[i];

        if(i!=0)
        {
            cout << "->";
        }
    }
}

