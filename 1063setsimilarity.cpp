#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


set<int>allsets[50];

int main()
{
    int N, M;
    int query_num;

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        set<int> tmp;
        scanf("%d", &M);
        for(int j=0; j<M; j++){
            int ele;
            scanf("%d", &ele);
            tmp.insert(ele);
        }
		allsets[i] = tmp; 
    }
    
    scanf("%d", &query_num);
    
    for(int i=0; i<query_num; i++)
    {
    	int a, b;
		int count = 0;
    	scanf("%d%d", &a, &b);
    	
    	for(set<int>::iterator i = allsets[a-1].begin(); i!=allsets[a-1].end(); i++)
    	{
    		if(allsets[b-1].find(*i)!= allsets[b-1].end())
    		{
    			count++;
			}
		}
    	
    	printf("%.1lf\%\n", (double)(count) / (allsets[a-1].size()+ allsets[b-1].size() -count) * 100);
	}
}
