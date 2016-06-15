#include<cstdio>
#include<vector>
using namespace std;

struct Segment
{
    int st, ed;
};

vector<Segment> generate(vector<int> sums, int K)
{
    vector<int> x(sums.size() + K - 1);
    vector<Segment> segs(K);
    for(int i=0;i<K-1;++i)
    {
        segs[i].st = 0;
        segs[i].ed = 0;
        x[i] = 0;
    }

    segs[K-1].st = sums[0];
    segs[K-1].ed = sums[0];
    x[K-1] = sums[0];
    
    int id = 0;
    for(int i=1;i<sums.size();++i)
    {
        id = (i+K-1)%K;
        x[i+K-1] = sums[i] - sums[i-1] + x[i-1];
        if(x[i+K-1] > segs[id].ed)
            segs[id].ed = x[i+K-1];
        if(x[i+K-1] < segs[id].st)
            segs[id].st = x[i+K-1];
    }
    for(int i=0;i<x.size();++i)
    {
        printf("\t%d", x[i]);
    }
    printf("\n");
    return segs;
}

bool needAdjust(vector<Segment>& input, int average, int max)
{
    int N = input.size();
    average %= N;
    for(int i=1;i<N;++i)
    {
        if(average%i) continue;
        int count = 0;
        for(int j=0;j<N;++j)
            if(input[j].ed + i <= max)
                count++;
        if(count >= average)
        {
            return false;
        }
    }
    return true;
}

int answer(vector<Segment>& input)
{
    //TODO should check if this adjust solution is right.
    int N = input.size();
    int average = 0;
    
    for(int i=0;i<N;++i){
        average += input[i].st/N;        
    }

    int max = 0;
    for(int i=0;i<N;++i){
        input[i].ed -= input[i].st;
        input[i].st = 0;
        if(max < input[i].ed)
            max = input[i].ed;
    }
    
    if(needAdjust(input, average, max))
    {
        return max + 1;
    }
    return max;
}

int main()
{
    int T, N, K;
    scanf("%d", &T);
    for(int i=1;i<T+1;++i)
    {
        scanf("%d%d", &N, &K);
        vector<int> sums(N-K+1);
        for(int j=0;j<sums.size();++j)
        {
            scanf("%d", &sums[j]);
        }
        vector<Segment> segs = generate(sums, K);
        int ans = answer(segs);
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;    
}
