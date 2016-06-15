/* Cost 41 + 25 + 63 already */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
char steps[] = {'W', 'N', 'E', 'S'};
void judge(vector<vector<char> > &maze, string &answer, int &cnt,
           int sx, int sy, int ex, int ey)
{
    int direct = 0;
    int x, y, nx, ny, lx, ly, llx, lly;
    int i;
    answer = "";
    cnt = 0;
    x = sx, y = sy;
    do
    {        
        for(i = 0; i < 4; ++i)
        {            
            nx = x, ny = y;
            lx = x, ly = y;
            llx = x, lly = y;
            direct = (direct + 1) % 4;
            switch(direct)
            {
            case 0:
                ny = y - 1;
                lx = x + 1;
                llx = x + 1;
                lly = y - 1;
                break;
            case 1:
                nx = x - 1;
                ly = y - 1;
                lly = y - 1;
                llx = x - 1;
                break;
            case 2:
                ny = y + 1;
                lx = x - 1;
                llx = x - 1;
                lly = y + 1;
                break;
            case 3:
                nx = x + 1;
                ly = y + 1;
                lly = y + 1;
                llx = x + 1;
                break;
            default:
                break;
            }
            if(maze[lx][ly]!='#') continue;
            if(maze[nx][ny]=='#') continue;
            break;
        }
        if(i > 3 || cnt > 10000)
        {
            cnt = 10001;
            cout << answer << endl;
            answer = "Edison ran out of energy.";
            return;
        }
        /*
        if(maze[x][y]=='.')
            maze[x][y] = 'o';
        else
            maze[x][y]='O';
        */
        x = nx, y = ny;
        ++cnt;
        answer += steps[direct];
    }while(x != ex || y != ey);
}

int main()
{
    int T,N;
    int sx, sy, ex, ey;
    int cnt;
    string answer;
    string buf;
    cin >> T;
    vector<vector<char> > maze;
    for(int i=1;i<T+1;++i)
    {
        maze.clear();
        cin >> N;
        maze = vector<vector<char> >(N+2, vector<char>(N+2, '#'));
        for(int j=1;j<N+1;++j)
        {
            cin >> buf;
            for(int k=1;k<N+1;++k)
                maze[j][k] = buf[k-1];            
        }
        cin >> sx >> sy >> ex >> ey;
        judge(maze, answer, cnt, sx, sy, ex, ey);
        if(cnt > 10000)
            printf("Case #%d: %s\n", i, answer.c_str());
        else{
            printf("Case #%d: %d\n",i, cnt);
            printf("%s\n", answer.c_str());
        }
    }
    return 0;
}
