#include <stdlib.h>
#include <stdio.h>

int main()
{
    long long int total = 0;
    char str[100001];

    scanf("%s", str);

    long long pnum=0;
    long long tnum=0;

    for(int i=0; str[i]!=0; i++)
    {
        if(str[i] == 'P')
        {
            pnum++;
        }
        else if(str[i] == 'T')
        {
            tnum++;
        }
    }
    long long current_p = 0;
    long long current_t = tnum;
    for(int i=0; str[i]!=0; i++)
    {
        if(str[i] == 'P')
        {
            current_p++;
        }
        else if(str[i] == 'T')
        {
            current_t--;
        }
        else
        {
            total += current_p * current_t;
            total = total%1000000007;
        }
    }

    printf("%d", total);

    system("pause");
}


/*#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	cin>>s;
	long long p,pa,pat;
	p = pa = pat = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] == 'P')
			p++;
		else if(s[i] == 'A'){
			pa += p;
		}
		else if(s[i] == 'T'){
			pat += pa;
		}
	}
	cout<<pat%1000000007;
	return 0;
}*/