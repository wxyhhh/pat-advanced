#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector <char*> a;
	char* str;
	
	for(int i=0; i<2; i++){
		str = new char[10];
		scanf("%s", str);
		a.push_back(str);
	}
	
	for(int i=0; i<2; i++){
		printf("%s\n", a[i]);
	}
}
