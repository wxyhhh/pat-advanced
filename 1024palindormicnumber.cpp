#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getreversed(string origin)
{
	string result = origin;
	reverse(result.begin(), result.end());
	
	return result;
}

string bigadd(string a, string b){
	int carry =0;
	string sum = "";
	
	for(int i=0; i<a.size(); i++){
		int tmp = a[i]-'0' + b[i]-'0' + carry;
		sum.insert(sum.begin(), tmp%10+'0');
		carry = tmp /10;
		
	}
	if(carry > 0){
		sum.insert(sum.begin(), carry%10+'0');
	}
	return sum;
}

int main()
{
	int K;
	string N;
	string tmp;
	
	cin >>N;
	cin >>K;
	
	int i = 0;
	for(i=0; i<=K; i++){
		tmp = getreversed(N);
		if(tmp == N){
			cout <<N<<endl;
			cout <<i;
            break;
		}
		else{
			if(i != K){
				N = bigadd(N, tmp); 
				//cout << N<<endl;
			}	
		}
	}
	
	if(i == K+1){
		cout << N<<endl;
		cout << K;
	}
 } 
