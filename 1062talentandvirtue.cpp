#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std; 

struct person
{
    char id[10];
    int virtue;
    int talent;
};

vector <person> sage;
vector <person> nobleman;
vector <person> foolman;
vector <person> rest;

bool comp(person a, person b)
{
    int suma = a.virtue + a.talent;
    int sumb = b.virtue + b.talent;

    if(suma != sumb){
    	return sumb < suma;
	}
	else if(a.virtue != b.virtue){
		return b.virtue < a.virtue;
	}
	else{
		if(strcmp(a.id, b.id)<0)
		  return true;
		else
		  return false;
	}
}

int main()
{
    int N, H, L;
    int count = 0;

    scanf("%d%d%d", &N, &L, &H);

    for(int i=0; i<N; i++)
    {
        person tmp;
        scanf("%s%d%d", tmp.id, &tmp.virtue, &tmp.talent);
        if(tmp.virtue < L || tmp.talent < L){
            continue;
        }
        count++;
        if(tmp.virtue >= H && tmp.talent >= H){
            sage.push_back(tmp);
        }
        else if(tmp.virtue >= H && tmp.talent < H){
            nobleman.push_back(tmp);
        }
        else if(tmp.virtue < H && tmp.talent < H && tmp.talent <= tmp.virtue){
            foolman.push_back(tmp);
        }
        else{
            rest.push_back(tmp);
        }      
    }

    sort(sage.begin(), sage.end(), comp);
    sort(nobleman.begin(), nobleman.end(), comp);
    sort(foolman.begin(), foolman.end(), comp);
    sort(rest.begin(), rest.end(), comp);
	
	printf("%d\n", count);
    for(int i=0; i<sage.size(); i++){
        printf("%s %d %d\n", sage[i].id, sage[i].virtue, sage[i].talent);
    }

    for(int i=0; i<nobleman.size(); i++){
        printf("%s %d %d\n", nobleman[i].id, nobleman[i].virtue, nobleman[i].talent);
    }

    for(int i=0; i<foolman.size(); i++){
        printf("%s %d %d\n", foolman[i].id, foolman[i].virtue, foolman[i].talent);
    }
	
    for(int i=0; i<rest.size(); i++){
        printf("%s %d %d\n", rest[i].id, rest[i].virtue, rest[i].talent);
    }

}
