#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int tolls[24];
int daily_cost;
struct record
{
    char name[30];
    int month;
    int dd;
    int hh;
    int mm;
    int line_type;
};

int compare(const void* a, const void* b){
    struct record recordA = *((struct record*)a);
    struct record recordB = *((struct record*)b);

    if(strcmp(recordA.name, recordB.name)!=0){
        return strcmp(recordA.name, recordB.name);
    }
    else{
        if(recordA.month != recordB.month){
            return recordA.month - recordB.month;
        }
        if(recordA.dd != recordB.dd){
            return recordA.dd - recordB.dd;
        }
        if(recordA.hh != recordB.hh){
            return recordA.hh - recordB.hh;
        }
        if(recordA.mm != recordB.mm){
            return recordA.mm - recordB.mm;
        }
    }
}

double calculate_amount(struct record start, struct record end){
    double amount1 = 0;
    double amount2 = 0;
    
    amount1 += start.dd * daily_cost;
    for(int i=0; i< start.hh; i++){
        amount1 += tolls[i]*60;
    }
    amount1 += tolls[start.hh]*start.mm;

    amount2 += end.dd * daily_cost;
    for(int i=0; i< end.hh; i++){
        amount2 += tolls[i]*60;
    }
    amount2 += tolls[end.hh]*end.mm;

    return amount2 - amount1;
}

int calculate_time(struct record start, struct record end){
    double length1;
    double length2;
    length1 = start.dd*24*60 + start.hh * 60 + start.mm;
    length2 = end.dd*24*60 + end.hh * 60 + end.mm;

    return length2 - length1;
}


int check_ok(struct record *r,int index,int n){
	char pname[30];
	int i,flag=0,has=0;
	strcpy(pname,r[index].name);
	for(i=index;i<n;i++){
		if(strcmp(r[i].name,pname)==0){
			if(r[i].line_type == 1){
				flag=1;
			}
			else if(r[i].line_type ==0&&1==flag){
				flag=0;
				has=1;
			}
		}
		else
			break;
	}
	return has;
}

int main()
{
    int N;
    struct record* recordlist;

    daily_cost = 0;
    for(int i=0; i<24; i++){
        scanf("%d", &tolls[i]);
        daily_cost += tolls[i] * 60;
    }

    scanf("%d", &N);
    recordlist = (struct record*)malloc(N*sizeof(*recordlist));
    for(int i=0; i<N; i++){
        char tmp[10];
        scanf("%s", recordlist[i].name);
        scanf("%d:%d:%d:%d", &recordlist[i].month, &recordlist[i].dd, &recordlist[i].hh, &recordlist[i].mm);
        scanf("%s", tmp);
        if(tmp[1] == 'n')
            recordlist[i].line_type = 1;
        else
            recordlist[i].line_type = 0;
    }

    qsort(recordlist, N, sizeof(struct record), compare);

    char current_name[30] = "";
    int has_online = 0;
    int has = 0;
    double total_amount;
    double this_amount;
    int time_length;
    for(int i=0; i<N;){
        has = check_ok(recordlist, i, N);

        if( has == 1){
            printf("%s %02d\n", recordlist[i].name, recordlist[i].month);
            strcpy(current_name, recordlist[i].name);
            total_amount = 0;
            has_online = 0;
            struct record tmp;
            while(strcmp(current_name, recordlist[i].name)==0){
                if(recordlist[i].line_type == 1){
                    has_online = 1;
                    tmp.month = recordlist[i].month;
                    tmp.dd = recordlist[i].dd;
                    tmp.hh = recordlist[i].hh;
                    tmp.mm = recordlist[i].mm;
                }
                else{
                    if(has_online == 1){
                        has_online = 0;
                        this_amount = calculate_amount(tmp, recordlist[i]);
                        time_length = calculate_time(tmp,recordlist[i]);
                        total_amount += this_amount;

                        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", tmp.dd, tmp.hh, tmp.mm, recordlist[i].dd, recordlist[i].hh, recordlist[i].mm, time_length, this_amount/100.0);
                    }
                }

                i++;
            }
            printf("Total amount: $%.2lf\n", total_amount/100.0);
        }

        else{
            i++;
        }

    }

    system("pause");

}