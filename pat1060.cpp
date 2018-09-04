#include <cstdio>
#include <cstring>
int tran(char *s, char *r, int n){
    char *p, *pr;
    int len, fr = 0, t = 0;
    if (p = strchr(s, '.')){ 
        char *tp = s + strlen(s) - 1;
        while (tp != p && *tp == '0'){ //清理小数部分末尾0
            *tp = '\0';
            --tp;
        }
        len = p - s;
        while (*p){
            *p = *(p+1);
            ++p;
        }
    }else{
        len = strlen(s);
    }
    p = s;
    while (*p){
        if (*p == '0'){
            ++fr;
        }else{
            break;
        }
        ++p;
    }
    strcpy(r, "0.");
    pr = &r[2];
    while (*p && t < n){
        *pr++ = *p++;
        ++t;
    }
    while (t++ < n){
        *pr++ = '0';
    }
    sprintf(pr, "*10^%d", len - fr);
    return len;
}
int main()
{
    int n;
    char s1[200], s2[200], rs1[200], rs2[200];
    scanf("%d%s%s", &n, s1, s2);
    int len1 = tran(s1, rs1, n);
    int len2 = tran(s2, rs2, n);
    if (0 == strcmp(rs1, rs2)){
        printf("YES %s\n", rs1);
    }else{
        printf("NO %s %s\n", rs1, rs2);
    }
    return 0;
}
