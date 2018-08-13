#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

struct grade
{
    char name[20];
    char gender[2];
    char id[20];
    int score;
};

int main()
{
    int total;
    int lowest_boy = -1;
    int lowest_boy_score = INT_MAX;
    int highest_girl = -1;
    int highest_girl_score = -1;
    struct grade* students;

    scanf("%d", &total);
    students = (struct grade*)malloc(total * sizeof(struct grade));

    for(int i=0; i<total; i++)
    {
        scanf("%s%s%s%d", students[i].name, students[i].gender, students[i].id, &students[i].score);
        if(strcmp(students[i].gender, "F")==0 && students[i].score > highest_girl_score){
            highest_girl = i;
            highest_girl_score = students[i].score;
        }
        if(strcmp(students[i].gender, "M")==0 && students[i].score < lowest_boy_score){
            lowest_boy = i;
            lowest_boy_score = students[i].score;
        }
    }
    if(highest_girl == -1){
        printf("Absent");
    }
    else{
        printf("%s %s", students[highest_girl].name, students[highest_girl].id);
    }
    printf("\n");
    if(lowest_boy == -1){
        printf("Absent");
    }
    else{
        printf("%s %s", students[lowest_boy].name, students[lowest_boy].id);
    }
    printf("\n");

    if(lowest_boy == -1 || highest_girl == -1){
        printf("NA");
    }
    else{
        printf("%d", highest_girl_score - lowest_boy_score);
    }

    system("pause");
    return 0;
}