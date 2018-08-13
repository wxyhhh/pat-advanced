#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct student{
    char id[7];
    char name[9];
    int grade;
};

int comp1(const void* a, const void* b){
    struct student studenta = *(struct student* )a;
    struct student studentb = *(struct student* )b;

    return strcmp(studenta.id, studentb.id);
}
int comp2(const void* a, const void* b){
    struct student studenta = *(struct student* )a;
    struct student studentb = *(struct student* )b;
    if(strcmp(studenta.name, studentb.name)==0){
        return strcmp(studenta.id, studentb.id);
    }
    return strcmp(studenta.name, studentb.name);
}
int comp3(const void* a, const void* b){
    struct student studenta = *(struct student* )a;
    struct student studentb = *(struct student* )b;
    if(studenta.grade - studentb.grade==0){
        return strcmp(studenta.id, studentb.id);
    }
    return studenta.grade - studentb.grade;
}



int main()
{
    int N, C;
    struct student* records;
    char id[7];
    char name[9];
    int grade;

    scanf("%d%d", &N, &C);

    records = (struct student*)malloc(N*sizeof(struct student));
    for(int i=0; i<N; i++){
        scanf("%s%s%d", id, name, &grade);
        strcpy(records[i].id, id);
        strcpy(records[i].name, name);
        records[i].grade = grade;
    }

    switch(C)
    {
        case 1: qsort(records, N, sizeof(struct student), comp1);break;
        case 2: qsort(records, N, sizeof(struct student), comp2);break;
        case 3: qsort(records, N, sizeof(struct student), comp3);break;
    }

    for(int i=0; i<N; i++){
        printf("%s %s %d", records[i].id, records[i].name, records[i].grade);
        if(i != N-1){
            printf("\n");
        }
    }
    system("pause");

    return 0;
}