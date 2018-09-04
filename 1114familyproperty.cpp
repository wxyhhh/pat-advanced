#include<iostream>
#include<vector>
#include<queue>
#include<algorithm> 

using namespace std;
int known[10000] = {0};

struct family
{
    int id;
    int sets_num;
    double avg_set;
    double avg_area;
};
vector <family> f;
vector <int> record;
struct person
{
    int father;
    int mother;
    vector <int>parents;
    vector<int> children;
    int set;
    int area;
}p[10000]; 

void bfs(int per)
{
    family fam;
    int fid = per;
    int sets_num = 0;
    int pnum = 0;
    int total_area = 0;
    queue<int> Q;
    Q.push(per);

    while(Q.size()!=0)
    {
        int tmp = Q.front();
        Q.pop();
        if(known[tmp] == 1)
        {
            continue;
        }
        known[tmp] = 1;
        if(tmp < fid)
        {
            fid = tmp;
        }
        sets_num += p[tmp].set;
        pnum ++;
        total_area += p[tmp].area;
        if(p[tmp].father != -1 && known[p[tmp].father] ==0 )
        {   
            Q.push(p[tmp].father);
        }
        if(p[tmp].mother != -1 && known[p[tmp].mother] ==0 )
        {   
            Q.push(p[tmp].mother);
        }
        for(int i=0; i<p[tmp].parents.size(); i++)
        {
            if(known[p[tmp].parents[i]] == 0)
            {
                Q.push(p[tmp].parents[i]);
            }
        }
        for(int i=0; i<p[tmp].children.size(); i++)
        {
            if(known[p[tmp].children[i]] == 0)
            {
                Q.push(p[tmp].children[i]);
            }
        }
    }

    fam.id = fid;
    fam.sets_num = pnum;
    fam.avg_set = sets_num / (double)pnum;
    fam.avg_area = total_area / (double)pnum;

    f.push_back(fam);
}

bool comp(family a, family b)
{
	if(a.avg_area != b.avg_area)
	{
		return b.avg_area < a.avg_area;
	}
	
	return a.id < b.id; 
} 

int main()
{
    int N;
    int id;
    int child_count;
    scanf("%d", &N);
	
	for(int i=0; i<10000; i++)
	{
		p[i].father = -1;
		p[i].mother = -1;
		p[i].area = 0;
		p[i].set = 0;
	}
    for(int i=0; i<N; i++)
    {
        scanf("%d", &id);
        record.push_back(id);
        scanf("%d%d", &p[id].father, &p[id].mother);
        p[p[id].father].children.push_back(id);
        p[p[id].mother].children.push_back(id);
        scanf("%d", &child_count);
        for(int i=0; i<child_count; i++)
        {
            int x;
            scanf("%d", &x);
            p[id].children.push_back(x);
            p[x].parents.push_back(id);
        }
        scanf("%d%d", &p[id].set, &p[id].area);
    }

    for(int i=0; i<record.size(); i++)
    {
        if(known[record[i]] == 1)
        {
            continue;
        }
        bfs(record[i]);
    }

    sort(f.begin(), f.end(), comp);
	
	printf("%d\n", f.size());
    for(int i=0; i<f.size(); i++)
    {
        printf("%04d %d %.3lf %.3lf\n", f[i].id, f[i].sets_num, f[i].avg_set, f[i].avg_area);
    }

}
