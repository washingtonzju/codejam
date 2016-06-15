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

int binary_find(vector<long long> &array, long long val)
{
    int st = 0, ed = array.size() - 1, md;
    while(st <= ed)
    {
        md = (st + ed)/2;
        if(array[md]==val) return md;
        else if(array[md] > val) ed = md - 1;
        else st = md + 1;                                    
    }
    return md;
}

int binary_find2(vector<long long> &array, long long val)
{
    int st = 0, ed = array.size()-1, md;
    long long value;
    while(st<=ed)
    {
        md = (st+ed)/2;
        value = array[md] - array[md-1];
        if(val > value) st = md + 1;
        else if(val < value) ed = md - 1;
        else return md;            
    }
    return md;
}

// the small brute force solution.
void findPosition2(vector<pnt > &region, int &x, int &y, long long &dis)
{
    dis = 10000000000000L;
    sort(region.begin(), region.end(), comp);
    for(int i=0;i<region.size();++i)
    {
        long long sample = calSum(region, region[i].first, region[i].second);
        if(sample<dis)
        {
            dis = sample;
            x = region[i].first;
            y = region[i].second;
        }
    }
}

// Wrong test
void findPosition(vector<pnt > &region, int &x, int &y, long long &dis)
{
    vector<long long> sum_x;
    vector<long long> sum_y;

    vector<long long> xset;
    vector<long long> yset;
    sort(region.begin(), region.end(), comp);
    
    for(int i=0;i<region.size();++i)
    {
        sum_x.push_back(region[i].first);
        sum_y.push_back(region[i].second);
    }   
    
    sort(sum_x.begin(), sum_x.end());
    sort(sum_y.begin(), sum_y.end());

    for(int i=0;i<sum_x.size();++i)
        xset.push_back(sum_x[i]);
    for(int i=0;i<sum_y.size();++i)
        yset.push_back(sum_y[i]);
    
    for(int i=1;i<region.size();++i)
    {
        sum_x[i] = sum_x[i-1]+sum_x[i];
        sum_y[i] = sum_y[i-1]+sum_y[i];
    }

    dis = 10000000000000L;
    long long tmp;

    int ix = 0;
    int iy = 0;
    
    for(int i=0;i<region.size();++i)
    {
        tmp = 0L;
        ix = binary_find(xset, (long long)region[i].first);
        iy = binary_find(yset, (long long)region[i].second);
        
        tmp+=(ix+1)*region[i].first - sum_x[ix];
        tmp+=(iy+1)*region[i].second - sum_y[iy];
        tmp+=sum_x[region.size()-1] - sum_x[ix] - (region.size()-ix-1)*region[i].first;
        tmp+=sum_y[region.size()-1] - sum_y[iy] - (region.size()-iy-1)*region[i].second;
        
        if(tmp<dis)
        {
            dis = tmp;
            x = region[i].first;
            y = region[i].second;
        }
    }
}

// This is the right solution for the big data.
void findPosition3(vector<pnt > &region, int &x, int &y, long long &dis)
{
    vector<long long> sum_x;
    vector<long long> sum_y;
    
    sort(region.begin(), region.end(), comp);

    sum_x.push_back(0L);
    sum_y.push_back(0L);
    for(int i=0;i<region.size();++i)
    {
        sum_x.push_back((long long)region[i].first);
        sum_y.push_back((long long)region[i].second);
    }   
    
    sort(sum_x.begin()+1, sum_x.end());
    sort(sum_y.begin()+1, sum_y.end());

    for(int i=1;i<sum_x.size();++i)
    {
        sum_x[i] = sum_x[i-1]+sum_x[i];
        sum_y[i] = sum_y[i-1]+sum_y[i];
    }
    
    dis = 100000000000000000L;
    long long tmp;

    int ix = 0;
    int iy = 0;

    for(int i=0;i<region.size();++i)
    {
        tmp = 0L;
        ix = binary_find2(sum_x, (long long)region[i].first);
        iy = binary_find2(sum_y, (long long)region[i].second);

        long long rsum_x = sum_x[sum_x.size()-1] - sum_x[ix];
        long long rsum_y = sum_y[sum_y.size()-1] - sum_y[iy];
        
        long long left_size_x = (long long)ix - 1;
        long long left_size_y = (long long)iy - 1;
        long long right_size_x = (long long)(region.size()) - left_size_x - 1;
        long long right_size_y = (long long)(region.size()) - left_size_y - 1;
        tmp += left_size_x*region[i].first - sum_x[ix-1];
        tmp += left_size_y*region[i].second - sum_y[iy-1];
        tmp += rsum_x - right_size_x*region[i].first;
        tmp += rsum_y - right_size_y*region[i].second;

        if(tmp<dis)
        {
            dis = tmp;
            x = region[i].first;
            y = region[i].second;
        }
    }
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
        findPosition3(region, x, y, dis);
        printf("Case #%d: %d %d %lld\n", ic, x, y, dis);
    }
    return 0;
}
