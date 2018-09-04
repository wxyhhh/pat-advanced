#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <map>

using namespace std;

map<string, int> speeches;
string max_str;
int max_num;


int main()
{
	string input;
	
	getline(cin, input);
	
	for(int i=0; i<input.length(); i++)
	{
		if(!(isalpha(input[i])||isdigit(input[i]))){
			continue;
		}
		int count =0;
		int pos = i;
		string tmp;
		while(isalpha(input[i])||isdigit(input[i])){
			input[i] = tolower(input[i]);
			count++;
			i++;
		}
		tmp = input.substr(pos, count);
		speeches[tmp]++;
		int current = speeches[tmp];
		if(current > max_num){
			max_num = current;
			max_str = tmp;
		}
		else if(current == max_num){
			if(tmp < max_str){
				max_num = current;
				max_str = tmp;
			}
		}
		else{
			continue;
		}
	}
	
	cout << max_str << " " << max_num;
	
 } 
