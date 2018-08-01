#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct TableEntry
{
	int known;
	int dist;
	int path;
	int count;
	int max_people;
};

int getMinVertex(struct TableEntry *T, int Vnum);

int main()
{
	int Graph[500][500];
	int Pnum[500];
	int Vnum, Enum;
	int C1, C2;
	int c1, c2, l;
	struct TableEntry* T;
	int v;
	
	
	
	scanf("%d%d%d%d", &Vnum, &Enum, &C1, &C2);
	
	for(int i = 0; i < Vnum; i++){
		for(int j = 0; j < Vnum; j++){
			Graph[i][j] = -1;
		}
	}
	T = (struct TableEntry*)malloc(5*sizeof(struct TableEntry));
	
	
	for(int i = 0; i < Vnum; i++){
		scanf("%d", &Pnum[i]);
	}  
	
	for(int i = 0; i < Enum; i++){
		scanf("%d%d%d", &c1, &c2, &l);
		Graph[c1][c2] = Graph[c2][c1] = l;
	}
	for(int i = 0; i < Vnum; i++){
		T[i].count = 0;
		T[i].dist = INT_MAX;
		T[i].known = 0;
		T[i].path = -1;
		T[i].max_people = Pnum[i];
	}
	T[C1].count = 1;
	T[C1].max_people = Pnum[C1];
	T[C1].dist = 0;
	
	for(v = getMinVertex(T, Vnum); v != -1; v = getMinVertex(T, Vnum)){
		T[v].known = 1;
		for(int i = 0; i < Vnum; i++){
			if(Graph[v][i] >= 0){
				if(T[v].dist + Graph[v][i] < T[i].dist){
					T[i].dist = T[v].dist + Graph[v][i];
					T[i].path = v;
					T[i].count = T[v].count;
					T[i].max_people = T[v].max_people + Pnum[i];
				}
				else if(T[v].dist + Graph[v][i] == T[i].dist){
					T[i].count += T[v].count;
					if(T[i].max_people < T[v].max_people + Pnum[i])
						T[i].max_people = T[v].max_people + Pnum[i];
				}
				else{
					continue;
				}
			}
			else{
				continue;
			}
		}
	}
	
	printf("%d %d", T[C2].count, T[C2].max_people);
	system("pause");
	free(T);
	return 0;
} 

int getMinVertex(struct TableEntry *T, int Vnum){
	int min_dist = INT_MAX;
	int choice = -1;
	
	for(int i = 0; i < Vnum; i++){
		if(T[i].known == 0){
			if(T[i].dist < min_dist){
				choice = i;
				min_dist = T[i].dist;
			}
			else{
				continue;
			}
		}
		else{
			continue;
		}
	}
	
	return choice;
}
