#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct account
{
    char name[20];
    char password[20];
};

int modify_pwd(char str[20]){
    int flag = 0;

    for(int i=0; i<strlen(str); i++){
        switch(str[i]){
            case '1': str[i] = '@'; flag = 1;break;
            case '0': str[i] = '%'; flag = 1;break;
            case 'O': str[i] = 'o'; flag = 1;break;
            case 'l': str[i] = 'L'; flag = 1;break;
            default: break;
        }
    }

    return flag;
}

int main()
{
    int team_num, mod_num=0;
    struct account* teams;
    int mod_teams[1000];
    scanf("%d", &team_num);

    teams = (struct account*)malloc(team_num*sizeof(struct account));
    for(int i=0; i<team_num; i++)
    {
        scanf("%s%s", teams[i].name, teams[i].password);
    }

    for(int i=0; i<team_num; i++){
        if(modify_pwd(teams[i].password)){
            mod_teams[mod_num] = i;
            mod_num++;
        }
    }

    if(mod_num > 0){
        printf("%d\n", mod_num);

        for(int i=0; i<mod_num; i++){
            printf("%s %s\n", teams[mod_teams[i]].name, teams[mod_teams[i]].password);
        }
    }
    else{
        if(team_num == 1)
            printf("There is %d account and no account is modified", team_num);
        else
            printf("There are %d accounts and no account is modified", team_num);
    }

    system("pause");
}