#include <stdlib.h>
#include <stdio.h>

struct student
{
    char name[11];
    char id[11];
    int grade;
};

int comp(const void* a, const void* b)
{
    return ((struct student*)b)->grade - ((struct student*)a)->grade;
}
int main()
{
    long long int N;
    struct student* grade_list;
    int lower, upper;

    scanf("%lld", &N);
    grade_list = (struct student*)malloc(N*sizeof(struct student));

    for(long long int i=0; i<N; i++)
    {
        scanf("%s%s%d", grade_list[i].name, grade_list[i].id, &grade_list[i].grade);
    }

    qsort(grade_list, N, sizeof(struct student), comp);

    scanf("%d%d", &lower, &upper);

    int count = 0;
    for(long long int i=0; i<N; i++)
    {
        if(grade_list[i].grade > upper)
        {
            continue;
        }
        else if(grade_list[i].grade < lower)
        {
            break;
        }
        printf("%s %s\n", grade_list[i].name, grade_list[i].id);
        count++;
    }

    if(count == 0)
    {
        printf("NONE");
    }

    system("pause");
}