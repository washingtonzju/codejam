#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int, int> point;

char dirs[] = {'W','N','E','S'};
int s_types[] = {1, 2, 4, 8};
void maze_venture(vector<vector<char> >&maze, int &cnt, string &ans, point s, point e)
{
    cnt = 0;
    ans = "";
    int N = maze.size();
    // The status of robot through
    point rbt;
    // left point
    point lp;
    // left ahead point
    point lhp;
    // next point, the objection;
    point np;
    int direct = 0;
    
    rbt = s;
    vector<vector<int> > stat = vector<vector<int> >(N, vector<int>(N, 0));
    do
    {
        int it=0;
        for(it = 0; it < 4; ++it)
        {
            lp = rbt;
            lhp = rbt;
            np = rbt;
            switch(direct)
            {
            case 0:
                np.second = rbt.second - 1;
                lp.first = rbt.first + 1;
                lhp.first = lp.first;
                lhp.second = np.second;
                break;
            case 1:
                np.first = rbt.first - 1;
                lp.second = rbt.second - 1;
                lhp.second = lp.second;
                lhp.first = np.first;
                break;
            case 2:
                np.second = rbt.second + 1;
                lp.first = rbt.first - 1;
                lhp.first = lp.first;
                lhp.second = np.second;
                break;
            case 3:
                break;
            default:
                break;
            }
        }
    }while(rbt.first != e.first || rbt.second != e.second);
}

int main()
{
    int T, N;
    point s, e;
    string buf;
    int cnt;
    string ans;
    vector<vector<char> > maze;
    cin >> T;
    for(int i=1;i<T+1;++i)
    {
        cin >> N;
        maze.clear();
        maze = vector<vector<char> >(N+2, vector<char>(N+2, '#'));
        for(int j=1;j<N+1;++j) {
            cin >> buf;
            for(int k=1;k<N+1;++k)
                maze[j][k] = buf[k-1];
        }
        cin >> s.first >> s.second >> e.first >> e.second;
    }
    return 0;
}
