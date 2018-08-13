#include <iostream>
#include <map>
#include <string>
#include <vector> 
#include <algorithm>

using namespace std;
vector <vector<int> >students(26*26*26*10);

int main()
{
    int query_num, course_num;

    scanf("%d%d", &query_num, &course_num);

    for(int i=0; i<course_num;i++){
        int course_index;
        int student_num;
        char student_name[10];
        scanf("%d%d", &course_index, &student_num);
        for(int j=0; j<student_num; j++){
            scanf("%s", student_name);
            students[(((student_name[0]-'A')*26+student_name[1]-'A')*26+student_name[2]-'A')*10+student_name[3]-'0'].push_back(course_index);
        }
    }

    for(int i=0; i<query_num; i++){
        char query_name[10];
        scanf("%s", query_name);
        printf("%s ", query_name);
        int query_id = (((query_name[0]-'A')*26+query_name[1]-'A')*26+query_name[2]-'A')*10+query_name[3]-'0';
        printf("%d", students[query_id].size());
        sort(students[query_id].begin(), students[query_id].end());
        for(int j=0; j<students[query_id].size(); j++){
            printf(" %d", students[query_id][j]);
        }

        printf("\n");
    }


    return 0;

}
