#include <iostream>
#include <map>

using namespace std; 

int main()
{
    int M, N;

    map<int, int> colors;
    int max_num = 0;
    int max_color;
    int color;

    scanf("%d%d", &M, &N);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &color);
            colors[color]++;
            if(colors[color] > max_num){
                max_color = color;
                max_num = colors[color];
            }
        }
    }

    printf("%d", max_color);

    system("pause");
}
