#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
	double coe[10001];
	int i, j, k;
	int K;
	int N;
	double a;
	double temp_a;
	int temp_N;	
	int tail = 0;
	int count;
	
	
	for(i = 0; i<2;i++){
		scanf("%d", &K);
		
		for (j = 0; j < K; j++){
			scanf("%d%lf", &N, &a);
			if(coe[N] == 0)
				tail += 1;
			coe[N] += a;
			if(coe[N] == 0)
				tail -=1;
		}
	}
	
	
	if(tail == 0){
	  printf("%d", tail);
	  return 0;
	}
	else
	 printf("%d ", tail);
	 
	count = 0;
	for(i=1000;i>=0;i--){
		if (coe[i] == 0){
			continue;
		}
		count++;
		if(count == tail)
			printf("%d %.1lf", i, coe[i]);
		else
			printf("%d %.1lf ", i, coe[i]);
	}

	return 0;
}
