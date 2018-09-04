#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N, L, T;
int total = 0;
bool known[60][1286][128] = {false};
int image[60][1286][128];

int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

struct position
{
    int x;
    int y;
    int z;
    position(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

int BFS(int x, int y, int z)
{
    int count = 0;
    known[x][y][z] = true;
    count ++;
    queue<position> Q;
    Q.push(position(x, y, z));

    while(Q.size()!=0)
    {
        position tmp = Q.front();
        Q.pop();

        for(int i=0; i<6; i++)
        {
            int tmpx = tmp.x+X[i];
            int tmpy = tmp.y+Y[i];
            int tmpz = tmp.z+Z[i];

            if(tmpx < 0 || tmpx >= L || tmpy < 0 || tmpy >=M || tmpz <0 || tmpz >=N)
            {
                continue;
            }
            if(known[tmpx][tmpy][tmpz] == 1)
            {
                continue;
            }
            if(image[tmpx][tmpy][tmpz] == 0)
            {
                continue;
            }
            Q.push(position(tmpx, tmpy, tmpz));
            count++;
            known[tmpx][tmpy][tmpz] = 1;
        }
        
    }

    if(count >= T)
    {
        return count;
    }
    else
    {
        return 0;
    }
}


int main()
{

    scanf("%d%d%d%d", &M, &N, &L, &T);

    for(int i=0; i<L; i++)
    {
        for(int j=0; j<M; j++)
        {
            for(int k=0; k<N; k++)
            {
                scanf("%d", &image[i][j][k]);
            }
        }
    }

    for(int i=0; i<L; i++)
    {
        for(int j=0; j<M; j++)
        {
            for(int k=0; k<N; k++)
            {
                if(image[i][j][k] == 1 && known[i][j][k] != true)
                {
                    total += BFS(i, j, k);
                }
            }
        }
    }

    printf("%d", total);

    system("pause");
}
