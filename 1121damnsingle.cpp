#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person
{
    int companion;
    bool present;

    person()
    {
        companion = -1;
        present = false;
    }
}p[100000];

vector <int> dog;

int main()
{
    int N, M;
    int b, g;
    int guests[10000];

    scanf("%d", &N); 
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &b, &g);
        p[b].companion = g;
        p[g].companion = b;
    }

    scanf("%d", &M);

    for(int i=0; i<M; i++)
    {
        scanf("%d", &guests[i]);
        p[guests[i]].present = true;
    }

    for(int i=0; i<M; i++)
    {
        int c = p[guests[i]].companion;
        if(c==-1)
        {
            dog.push_back(guests[i]);
        }
        else if(p[c].present == false)
        {
            dog.push_back(guests[i]);
        }
        else
        {
            continue;
        }
    }
    sort(dog.begin(), dog.end());
    printf("%d\n", dog.size());
    for(int i=0; i<dog.size(); i++)
    {
        printf("%05d", dog[i]);
        if(i!=dog.size()-1)
        {
            printf(" ");
        }
    }
}
