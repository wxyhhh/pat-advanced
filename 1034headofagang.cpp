#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int person_num = 0;
map<string, int>name_number;
map<int, string>number_name;
int gang[2000];
map<int, int>members;
int gang_num = 0;
int graph[2000][2000];
int weight[2000];
int visited[2000];

bool comp_name(int a, int b){
    return number_name[a] < number_name[b];
}

void dfs(int person, int &total_weight, int &head, int &member_num){
    member_num++;
    total_weight += weight[person];
    visited[person] = 1;
    for(int i=0; i<person_num; i++){
        if(graph[person][i] > 0){
            if(weight[i] > weight[person]){
                head = i;
            }
            if(visited[i] != 1)
            	dfs(i, total_weight, head, member_num);
        }
    }
}


int main()
{
    int call_num;
    int threshold;
    string name1, name2;
    int length;

    cin >> call_num >> threshold;

    for(int i=0; i<1000; i++){
        weight[i] = 0;
        visited[i] = 0;
        for(int j=0; j<1000; j++){
            graph[i][j] = 0;
        }
    }
    for(int i=0; i<call_num; i++){
        
        cin >> name1 >> name2 >> length;
        int a, b;
        //cout << name1 << name2<<endl;
        if(name_number.find(name1) != name_number.end()){
            a = name_number[name1];
        }
        else{
            name_number[name1] = person_num;
            number_name[person_num] = name1;
            a = person_num++;
        }
        if(name_number.find(name2) != name_number.end()){
            b = name_number[name2];
        }
        else{
            name_number[name2] = person_num;
            number_name[person_num] = name2;
            b = person_num++;
        }
		//cout << a << b <<endl;
		
        graph[a][b] += length;
        graph[b][a] += length;
        weight[b] += length;
        weight[a] += length;
    }

    for(int i=0; i<person_num; i++){
        if(visited[i] == 0){
            int total_weight = 0, head = i, member_num = 0;
            dfs(i, total_weight, head, member_num);
            if(member_num > 2 && total_weight/2 > threshold ){
                gang[gang_num] = head;
                members[head] = member_num;
                gang_num++;
            }
        }
        
    }
    sort(gang, gang+gang_num, comp_name);

    cout<<gang_num<<endl;
    for(int i=0; i<gang_num; i++)
    {
        cout<<number_name[gang[i]]<<" "<<members[gang[i]]<<endl;
    }

    system("pause");
}
