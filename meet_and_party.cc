#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> pnt;

bool comp(const pnt &a, const pnt &b)
{
    if(a.first==b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

long long calculateDis(int ax, int ay, int bx, int by)
{
    return (long long)(abs(bx - ax) + abs(by - ay));
}

double tinyDis(double ax, double ay, double bx, double by)
{
    return fabs(bx - ax) + fabs(by - ay);
}

long long calSum(vector<pnt > &region, int x, int y)
{
    long long sum = 0L;
    for(int i=0;i<region.size();++i)
        sum+=calculateDis(region[i].first, region[i].second, x, y);
    return sum;
}

void findPosition(vector<pnt > &region, int &x, int &y, long long &dis)
{
    if(region.size()==1){
        x=region[0].first;
        y=region[0].second;
        dis = 0L;
        return;        
    }
    
    double temp_x=0, temp_y=0;
    for(int i=0;i<region.size();++i)
    {
        temp_x += region[i].first;
        temp_y += region[i].second;        
    }
    
    sort(region.begin(), region.end(), comp);

    double temp_dis = 1000000000000;
    for(int i=0;i<region.size();++i)
    {
        double in_x = (temp_x - region[i].first)/(region.size()-1);
        double in_y = (temp_y - region[i].second)/(region.size()-1);
        double in_dis = tinyDis(in_x, in_y, region[i].first, region[i].second);
        printf("distance is %lf\n", in_dis);
        if(in_dis - temp_dis < 0.00000001)
        {
            temp_dis = in_dis;
            x = region[i].first;
            y = region[i].second;
        }
    }

    dis = calSum(region, x, y);
}

int main()
{
    int T, B;
    int x, y;
    long long dis;
    vector<pnt > region;
    vector<int> tmp = vector<int>(4);
    scanf("%d", &T);

    for(int ic=1;ic<=T;++ic)
    {
        scanf("%d", &B);
        region.clear();
        for(int i=0;i<B;++i)
        {
            
            for(int j=0;j<4;++j)
                scanf("%d", &tmp[j]);
            for(int l=tmp[0];l<=tmp[2];++l)
                for(int m=tmp[1];m<=tmp[3];++m)
                    region.push_back(pnt(l, m));
        }
        findPosition(region, x, y, dis);
        printf("Case #%d: %d %d %lld\n", ic, x, y, dis);
    }
    return 0;
}
