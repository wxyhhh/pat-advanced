#include <iostream>
#include <cstdio>
#include <string>
#include <vector>


using namespace std;

string number[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main()
{
    int N;
    int digits[9];
    vector <string> chn;

    scanf("%d", &N);

    if(N < 0)
    {
        printf("Fu ");
        N = -N;
    }

    if(N== 0)
    {
        printf("ling");
        return 0;
    }
    for(int i=0; i<9; i++)
    {
        digits[8-i] = N%10;
        N = N/10;
    }
    int has0 = 0;
    int hassomething = 0;
    int haswan = 0;
    for(int i=0; i<9; i++)
    {
        if(digits[i] > 0)
        {
            hassomething = 1;
            if(i>=1 && i<=4)
            {
            	haswan = 1;
			}
            if(has0 == 1)
            {
                chn.push_back(number[0]);
                has0 = 0;
            }
            chn.push_back(number[digits[i]]);
            if(i == 1 || i == 5)
            {
                chn.push_back("Qian");
            }
            else if(i == 2 || i == 6)
            {
                chn.push_back("Bai");
            }
            else if(i == 3 || i == 7)
            {
                chn.push_back("Shi");
            }
            else if(i==0){
                chn.push_back("Yi");
            }
        }
        else{
            if(hassomething == 1)
                has0 = 1;
        }
        
        if(i == 4 && haswan == 1)
        	chn.push_back("Wan");
    }

    for(int i=0; i<chn.size(); i++)
    {
        cout << chn[i];
        if(i != chn.size()-1)
        {
            cout << " ";
        }
    }

}
