#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define ULL unsigned long long

using namespace std;
typedef pair<int, int> pnt;
bool comp(pnt a, pnt b)
{
    if(a.F == b.F)
        return a.S < b.S;
    return a.F < b.F;
}

int fidx(vector<int> &v, int val)
{
    int s = 0, e = v.size() -1;
    int m;
    while(s <= e){
        m = ((s + e)>>1);
        if(v[m] > val) e = m - 1;
        else if(v[m]<val) s = m + 1;
        else return m;
    }
    return -1;
}

int main()
{    
    CASET {
        DRI(B);
        vector<pnt> ps;
        vector<int> x;
        vector<int> y;
        REP(i, B){
            DRII(a, b);
            DRII(c, d);
            REPP(xi, a, c+1){
                REPP(yi, b, d+1){
                    ps.PB(pnt(xi, yi));
                    x.PB(xi);
                    y.PB(yi);
                }
            }
        }
        sort(ALL(x));
        sort(ALL(y));
        sort(ALL(ps), comp);
        vector<long long> sumx(ALL(x));
        vector<long long> sumy(ALL(y));
        REPP(i, 1, sumx.size()) {
            sumx[i]=sumx[i-1] + sumx[i];
            sumy[i]=sumy[i-1] + sumy[i];
        }
        long long min = 111LL << 59;
        int ans;
        //long long value = -1LL;
        REP(i, ps.size()) {
            int i_x = fidx(x, ps[i].F);
            int i_y = fidx(y, ps[i].S);
            long long dis = (i_x+1LL)*ps[i].F - sumx[i_x] + (sumx.back() - sumx[i_x]) - (x.size() - i_x - 1LL)*ps[i].F;
            dis += (i_y+1LL)*ps[i].S - sumy[i_y] + (sumy.back() - sumy[i_y]) - (y.size() - i_y -1LL)*ps[i].S;
            if(dis < min){
                min = dis;
                ans = i;
            }
        }
        printf("Case #%d: %d %d %lld\n", case_n, ps[ans].F, ps[ans].S, min);
        ++case_n;
    }
    return 0;
}
