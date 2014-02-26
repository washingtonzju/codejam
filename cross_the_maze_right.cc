/*damn, more than 2 hours! */
#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int, int> point;

char dirs[] = {'W', 'S', 'E', 'N'};

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
    do
    {
        int it=0;
        for(it = 0; it < 4; ++it)
        {
            lp = rbt;
            //lhp = rbt;
            np = rbt;            
            switch((direct + it)%4)
            {
            case 0:
                np.second = rbt.second - 1;
                lp.first = rbt.first + 1;
                //lhp.first = lp.first;
                //lhp.second = np.second;
                break;
            case 1:
                np.first = rbt.first + 1;
                lp.second = rbt.second + 1;
                //lhp.first = np.first;
                //lhp.second = lp.second;
                break;                                
            case 2:
                np.second = rbt.second + 1;
                lp.first = rbt.first - 1;
                //lhp.first = lp.first;
                //lhp.second = np.second;
                break;
            case 3:
                np.first = rbt.first - 1;
                lp.second = rbt.second - 1;
                //lhp.second = lp.second;
                //lhp.first = np.first;
                break;
            default:
                break;                
            }
                        
            if(maze[lp.first][lp.second]!='#' && lp.first!=lhp.first && lp.second != lhp.second) continue;
            if(maze[np.first][np.second]=='#') continue;
            direct = (direct + it)%4;
            break;
        }
        cnt++;
        if(cnt > 10000 || it > 3){
            //ans = "";
            cnt = 10001;
            return;
        }
        ans += dirs[direct];
        lhp = rbt;
        rbt = np;        
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
        maze_venture(maze, cnt, ans, s, e);
        //cout << cnt << " " << ans << endl;
        cout << "Case #" << i << ": ";
        if(cnt > 10000)
            cout << "Edison ran out of energy." << endl;
        else
        {
            cout << cnt << endl;
            cout << ans << endl;
        }
    }
    return 0;
}
