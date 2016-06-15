/* About 30 mins */
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
using namespace std;

typedef pair<int, int> tunnel;

void cal_distance(map<string, int> &belongs, map<tunnel, int> &turbolifts, vector<vector<int> > &dis)
{
    dis.clear();
    int N = belongs.size();
    dis = vector<vector<int> >(N, vector<int> (N, -1));

    int tmp;
    //for(int i=0;i<N;++i)
    //    dis[i][i]=0;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(turbolifts.find(tunnel(i, j))!=turbolifts.end())
            {
                dis[i][j]=turbolifts[tunnel(i,j)];
            }
        }
    }
            
                
    for(int k=0;k<N;++k)
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                //if(k==i || k==j) continue;
                if(dis[i][k]!=-1 && dis[k][j]!=-1)
                {
                    if(dis[i][j]==-1 || dis[i][j] > dis[i][k] + dis[k][j])
                        dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }       
    }
}

int main()
{
    int T, N, M, S;
    int a, b, t;
    int p,q;
    vector<string> rooms;
    map<string, int> belongs;
    map<tunnel, int> turbolifts;
    vector<vector<int> > dis;
    cin >> T;
    
    for(int i=1;i<T+1;++i)
    {
        cin >> N;
        rooms.clear();
        turbolifts.clear();
        belongs.clear();
        rooms = vector<string>(N);
        int cnt = 0;
        for(int j=0;j<N;++j)
        {
            cin >> rooms[j];
            if(belongs.find(rooms[j])==belongs.end())
                belongs[rooms[j]] = cnt++;            
        }
        
        cin >> M;
        int za, zb;
        for(int j=0;j<M;++j)
        {
            cin >> a >> b >> t;
            //cout << a << " " << b << endl;
            a--;
            b--;
            //cout << rooms[a] << " " << rooms[b] << endl;
            za = belongs[rooms[a]];
            zb = belongs[rooms[b]];
            if(turbolifts.find(tunnel(za, zb))==turbolifts.end() || t < turbolifts[tunnel(za, zb)])
                turbolifts[tunnel(za,zb)] = t;
        }
        
        cal_distance(belongs, turbolifts, dis);
        cout << "Case #" << i << ":" << endl;
        
        cin >> S;
        for(int j=0;j<S;++j)
        {
            cin >> p >> q;
            p--;
            q--;
            za = belongs[rooms[p]];
            zb = belongs[rooms[q]];
            //cout << za << " " << zb << endl;
            if(za == zb)
                cout << 0 << endl;
            else
                cout << dis[za][zb] << endl;
        }       
    }
    return 0;
}
