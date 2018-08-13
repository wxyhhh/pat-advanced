#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, vector<string> >title;
map<string, vector<string> >author;
map<string, vector<string> >keyword;
map<string, vector<string> >publisher;
map<string,  vector<string> >year;


int main()
{
	int N, M;
	
	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		string tmp_id, tmp_title, tmp_author, tmp_keyword, tmp_publisher;
		string keywords;
		string tmp_year;
		cin >> tmp_id;
		cin.ignore();
		getline(cin, tmp_title);
		title[tmp_title].push_back(tmp_id);
		getline(cin, tmp_author);
		author[tmp_author].push_back(tmp_id);
		getline(cin, keywords);
		stringstream ss;
		ss << keywords;
		while(ss>>tmp_keyword){
			keyword[tmp_keyword].push_back(tmp_id);
		}
		getline(cin, tmp_publisher);
		publisher[tmp_publisher].push_back(tmp_id);
		getline(cin, tmp_year);
		year[tmp_year].push_back(tmp_id);
	}
	
	cin >> M;
	cin.ignore();
	
	for(int i=0; i<M; i++){
		string query;
		map<string, vector<string> >::iterator result;
		getline(cin, query);
		cout << query << endl;
		switch(query[0]){
			case '1': 
				result = title.find(query.substr(3, query.size()-3));
				if(result == title.end()){
					printf("Not Found\n");
					continue;
				}
				break;
			case '2': 
				result = author.find(query.substr(3, query.size()-3));
				if(result == author.end()){
					printf("Not Found\n");
					continue;
				}
				break;
			case '3': 
				result = keyword.find(query.substr(3, query.size()-3));
				if(result == keyword.end()){
					printf("Not Found\n");
					continue;
				}
				break;
			case '4': 
				result = publisher.find(query.substr(3, query.size()-3));
				if(result == publisher.end()){
					printf("Not Found\n");
					continue;
				}
				break;
			case '5': 
				result = year.find(query.substr(3, query.size()-3));
				if(result == year.end()){
					printf("Not Found\n");
					continue;
				}
				break;
		}
		if(result->second.size() == 0){
			cout << "Not Found" << endl;
			continue;
		}
		sort(result->second.begin(), (result->second).end());
		for(int i=0; i<(result->second).size(); i++){
			cout << result->second[i]<<endl;
		}
		
	}
	
	return 0;
}
