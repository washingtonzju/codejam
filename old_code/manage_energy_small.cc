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
#define SLL long long
using namespace std;

SLL ans = 0LL;
int el, rl;
void dfs(int e, int idx, vector<int> &v, SLL val)
{   
    if(idx == v.size()) {
        if(val > ans)
            ans = val;
        return;
    }
    for(int i=0;i<e+1;++i){
        int next_e = e - i + rl;
        if(next_e > el) next_e = el;
        dfs(next_e, idx + 1, v, val + i*(SLL)v[idx]);
    }
}

int main()
{
    CASET {
        DRIII(E, R, N);
        el = E, rl = R;
        vector<int> v(N);
        REP(i, N){
            scanf("%d", &v[i]);
        }
        ans = 0LL;
        dfs(E, 0, v, 0LL);
        printf("Case #%d: %lld\n", case_n, ans);
        ++case_n;
    }
    return 0;
}
