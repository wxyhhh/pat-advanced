#include<iostream>
#include<cstdlib>
#include<vector> 

using namespace std;

string numbers1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

string numbers2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


void earthToMars(string num)
{
    int sum = 0;
    vector<int>marsnum;

    for(int i=0; i<num.size(); i++)
    {
        sum = sum*10 + num[i]-'0';
    }
    while(sum!=0)
    {
        marsnum.push_back(sum%13);
        sum /= 13;
    }
    if(marsnum.size() == 0)
    {
      cout << "tret" <<endl;
    }
    else if(marsnum.size() == 1)
    {
        cout << numbers1[marsnum[0]]<<endl;
    }
    else
    {
    	if(marsnum[0] == 0)
    	{
    		cout << numbers2[marsnum[1]] <<endl;
		}
		else
        	cout << numbers2[marsnum[1]] << " " << numbers1[marsnum[0]] << endl;
    }
}


void marsToEarth(string num)
{
    vector <string> marsnum;
    int start = 0;
    for(int i=0; i<num.size(); i++)
    {
        if(num[i]==' ')
        {
            marsnum.push_back(num.substr(start, i-start));
            start = i+1;
        }
        else if(i == num.size()-1)
        {
            marsnum.push_back(num.substr(start, i-start+1));
        }
    }
    int sum = -1;
    if(marsnum.size() == 1)
    {
        for(int i=0; i<13;i++)
        {
            if(marsnum[0] == numbers1[i])
            {
                sum = i;
                break;
            }
        }
        if(sum == -1)
        {
        	for(int i=0; i<13;i++)
        {
            if(marsnum[0] == numbers2[i])
            {
                sum = i*13;
                break;
            }
        }
		}
    }
    else
    {
        for(int i=0; i<13;i++)
        {
            if(marsnum[0] == numbers2[i])
            {
                sum = i;
                break;
            }
        }
        for(int i=0; i<13;i++)
        {
            if(marsnum[1] == numbers1[i])
            {
                sum = sum * 13 + i;
                break;
            }
        }
    }

    printf("%d\n", sum);
}

int main()
{
    string num;

    int N;
    scanf("%d", &N);
    getchar();
    for(int i=0; i<N; i++)
    {
        getline(cin, num);
        if(num[0]>='0' && num[0]<='9')
        {
            earthToMars(num);
        }
        else
        {
            marsToEarth(num);
        }
    }
}
