#include <stdlib.h>
#include <stdio.h>

int main()
{
    int* word;
    int* known;
    int start1, start2;
    int N;
    int this, next;
    char tmp[2];
    int result = -1;

    word = (int*)malloc(100001*sizeof(int));
    known = (int*)malloc(100001*sizeof(int));

    for(int i=0; i<100001; i++){
        word[i] = -1;
        known[i] = 0;
    }

    scanf("%d%d%d", &start1, &start2, &N);

    for(int i=0; i<N; i++)
    {
        scanf("%d%s%d", &this, tmp, &next);
        word[this] = next;
    }

    for(int i=start1; i != -1; i=word[i]){
        known[i] = 1;
    }

    for(int i=start2; i != -1; i=word[i]){
        if(known[i] == 1 && result == -1){
            result = i;
        }
        else if(known[i]!= 1){
            result = -1;
        }
    }
    if(result == -1){
        printf("-1");
    }
    else{
        printf("%05d", result);
    }

    system("pause");
}