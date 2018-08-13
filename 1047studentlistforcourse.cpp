#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;


vector<string> courses[2505];

int student_num;
int course_num;

bool comp(string str1, string str2)
{
	return str1 < str2;
}

int main()
{

    scanf("%d", &student_num);
    scanf("%d", &course_num);

    for(int i=0; i<student_num; i++){
        int tmp_num;
        char str[10];
        string student_name;
        scanf("%s", str);
        student_name = str;
        scanf("%d", &tmp_num);
        for(int j=0; j<tmp_num; j++){
            int tmp_course;
            scanf("%d", &tmp_course);
            courses[tmp_course].push_back(student_name);
        }
    }

    for(int i=1; i<=course_num; i++){
        printf("%d %d\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end(), comp);
        for( vector<string>::iterator j=courses[i].begin(); j!=courses[i].end(); j++){
            printf("%s\n", (*j).c_str());
        }
    }
    system("pause");
}
