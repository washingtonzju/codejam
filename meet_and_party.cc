#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void calculateCenter(vector<vector<int> > &region, double &ax, double &ay, long long &weight_sum)
{
    for(int i=0;i<region.size();++i)
    {
        long long temp_weight = (region[i][2] - region[i][0] + 1)*(region[i][3] - region[i][1] +1);
        ax = temp_weight*(region[i][0]+region[i][2])/2;
        ay = temp_weight*(region[i][1]+region[i][3])/2;
        weight_sum += temp_weight;
    }
    ax /= weight_sum;
    ay /= weight_sum;
}

double calculateDis(double ax, double ay, double bx, double by)
{
    return (ax - bx)*(ax - bx) + (ay - by)*(ay - by);
}

void findNearestInRegion(double ax, double ay, int &temp_x, int &temp_y, vector<int> &square)
{
    if( ax >= square[0] && ax <= square[2])
    {
        temp_x = floor(ax + 0.5);
    }else if( ax < square[0]) {
        temp_x = square[0];
    } else{
        temp_x = square[2];
    }

    if( ay >= square[1] && ay <= square[3])
    {
        temp_y = floor(ay + 0.5);
        
    }else if( ay < square[1]) {
        temp_y = square[1];
    } else{
        temp_y = square[3];
    }
}

void findPosition(vector<vector<int> > &region, int &x, int &y, int &dis)
{
    double ava_x=0.0, ava_y=0.0;
    long long weight_sum = 0;
    calculateCenter(region, ava_x, ava_y, weight_sum);

    double delta = 1000000000000000000.0;
    vector<pair<int, int> > cands;
    
    for(int i=0;i<region.size();++i)
    {
        int temp_x, temp_y;
        findNearestInRegion(ava_x, ava_y, temp_x, temp_y, region[i]);
        cands.push_back(pair<int, int>(temp_x, temp_y));
    }
    sort(cands.begin(), cands.end());
    for(int i=0;i<region.size();++i)
    {
        double temp_dis = calculateDis(cands[i].first, cands[i].second, ava_x, ava_y);
        if(temp_dis < delta)
        {      
            x = cands[i].first;
            y = cands[i].second;
            delta = temp_dis;
        }
    }
    dis = (int)(sqrt(delta));
}

int main()
{
    int T, B;
    int x, y, dis;
    vector<vector<int> > region;
    scanf("%d", &T);

    for(int i=1;i<=T;++i)
    {
        scanf("%d", &B);
        region.clear();
        for(int i=0;i<B;++i)
        {
            vector<int> tmp = vector<int>(4);
            for(int j=0;j<4;++j)
                scanf("%d", &tmp[j]);
            region.push_back(tmp);            
        }
        findPosition(region, x, y, dis);
        printf("Case #%d: %d %d %d\n", i, x, y, dis);
    }
    return 0;
}
