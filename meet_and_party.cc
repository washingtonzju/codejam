#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

long long calculateDis(int ax, int ay, int bx, int by)
{
    return (long long)(abs(bx - ax) + abs(by - ay));
}

long long calSum(vector<vector<int> > &region, int x, int y)
{
    long long sum = 0L;
    for(int j=0;j<region.size();++j)
    {
        for(int l=region[j][0];l<=region[j][2];++l)
        {
            for(int m=region[j][1];m<=region[j][3];++m)
            {
                long long temp = calculateDis(l, m, x, y);
                sum+=temp;
            }
        }
    }
    return sum;
}

void findPosition(vector<vector<int> > &region, int &x, int &y, long long &dis)
{
    double temp_x=0, temp_y=0;
    long long weight_sum = 0;

    for(int i=0;i<region.size();++i)
    {
        temp_x = (region[i][2]+region[i][0])/2.0;
        temp_y = (region[i][3]+region[i][1])/2.0;
        weight_sum += (region[i][2]-region[i][0]+1)*(region[i][3]-region[i][1]+1);
    }

    temp_x/=weight_sum;
    temp_y/=weight_sum;

    printf("%lf ------- %lf\n", temp_x, temp_y);
    vector<pair<int, int> > cands;

    for(int i=0;i<1;++i)
        for (int j=0;j<1;++j)
        {
            int intx = (i%2==0)?floor(temp_x):ceil(temp_x);
            int inty = (j%2==0)?floor(temp_y):ceil(temp_y);
            cands.push_back(pair<int, int>(intx, inty));
        }

    vector<pair<int, int> > res;

    for(int i=0;i<cands.size();++i)
    {
        int fit_x, fit_y;
        long long dd = 100000000000000L;;
        for(int j=0;j<region.size();++j)
        {
            for(int l=region[j][0];l<=region[j][2];++l)
            {
                for(int m=region[j][1];m<=region[j][3];++m)
                {
                    long long temp = calculateDis(l,m,cands[i].first, cands[i].second);
                    if(temp < dd)
                    {
                        dd = temp;
                        fit_x = l;
                        fit_y = m;
                    }
                }
            }
        }
        res.push_back(pair<int, int>(fit_x, fit_y));        
    }

    weight_sum = 1000000000000L;
    for(int i=0;i<res.size();++i)
    {
        long long temp_sum = calSum(region, res[i].first, res[i].second);
        if(temp_sum < weight_sum){
            weight_sum = temp_sum;
            x = res[i].first;
            y = res[i].second;
        }
    }
}

int main()
{
    int T, B;
    int x, y;
    long long dis;
    vector<vector<int> > region;
    scanf("%d", &T);

    for(int ic=1;ic<=T;++ic)
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
        printf("Case #%d: %d %d %lld\n", ic, x, y, dis);
    }
    return 0;
}
