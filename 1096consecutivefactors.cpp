#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

bool isprime(int N)
{
	
	if(N==2)
	{
		return true;
	}
	
	for(int i=2; i<=(int)sqrt(N); i++)
	{
		if(N%i==0)
		{
			return false;
		}
	}
	return true;
}


int main()
{
    int N;
    scanf("%d", &N);
    
    if(isprime(N))
    {
    	printf("1\n%d", N);
    	return 0;
	}
	int max_c = 0;
	int start_c = 0;
	int end = sqrt(N);
    for(int i=2; i<=end; i++)
    {
    	int result=1;
    	if(N%i!=0)
    	{
    		continue;
		}
		int j;
    	for(j=i; ;j++)
    	{
    		result *= j;
    		if(N%result!=0)
    		{
    			break;
			}
		}
		if(j-i > max_c)
		{
			max_c = j-i;
			start_c = i;
		}
	}
	
	printf("%d\n", max_c);
	for(int i=start_c; i<start_c+max_c; i++)
	{
		if(i!=start_c)
		{
			printf("*");
		}
		printf("%d", i);
	}
	
	return 0;
}
