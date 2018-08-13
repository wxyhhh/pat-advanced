#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct richman
{
    char name[10];
    int age;
    int money;
};

int comp(const void* a, const void* b)
{
    struct richman* p1 = (struct richman*)a;
    struct richman* p2 = (struct richman*)b;

    if(p1->money != p2->money){
        return p2->money - p1->money;
    }
    if(p1->age != p2->age){
        return p1->age - p2->age;
    }
    return strcmp(p1->name, p2->name);
}

int main()
{
    struct richman* ranklist;
    int people_n, query_n;

    scanf("%d%d", &people_n, &query_n);

    ranklist = (struct richman*)malloc(people_n*sizeof(struct richman));

    for(int i=0; i<people_n; i++)
    {
        scanf("%s%d%d", ranklist[i].name, &ranklist[i].age, &ranklist[i].money);
    }

    qsort(ranklist, people_n, sizeof(struct richman), comp);

    for(int i=0; i<query_n; i++){
        int l_bound, h_bound;
        int num;
        int flag = 0;
        int count = 0;
        scanf("%d%d%d", &num, &l_bound, &h_bound);

        printf("Case #%d:\n", i+1);
        for(int j=0; j<people_n; j++){
            if(ranklist[j].age >= l_bound && ranklist[j].age <= h_bound){
                printf("%s %d %d\n", ranklist[j].name, ranklist[j].age, ranklist[j].money);
                count++;
                if(count == num){
                    break;
                }
            }
        }

        if(count == 0){
            printf("None\n");
        }
    }

    system("pause");
}