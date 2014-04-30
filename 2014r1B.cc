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

int N;
int dp[1002][1002];
int dd[1002][1002];

int delnd(int a, int pr, vector<vector<int> > &aj) {
    if(dd[a][pr]!=-1) return dd[a][pr];
    int as = 1;
    REP(i, aj[a].size()) {
        if(aj[a][i]==pr) continue;
        as += delnd(aj[a][i], a, aj);
    }
    dd[a][pr] = as;
    return dd[a][pr];
}

int ans(int a, int pr, vector<vector<int> > &aj)
{
    if(dp[a][pr]!=-1) return dp[a][pr];
    if(aj[a].size() == 1) {        
        if(pr == 0){
            dp[a][pr] = delnd(aj[a][0], a, aj);
            return dp[a][pr];
        }else{
            dp[a][pr] = 0;
            return 0;
        }
    }
    else if(aj[a].size() == 2) {
        if(pr==0) {
            dp[a][pr] = ans(aj[a][1], a, aj) + ans(aj[a][0], a, aj);
            return dp[a][pr];
        }else{
            int tmp = 0;
            REP(i, 2) {
                if(aj[a][i]==pr) continue;
                tmp += delnd(aj[a][i], a, aj);
            }
            dp[a][pr] = tmp;
            return dp[a][pr];
        }
    }
    int mx = N+1;
    REP(i, aj[a].size()-1) {
        if(aj[a][i]==pr) continue;
        int tmp = ans(aj[a][i], a, aj);
        //printf("input %d %d %d ************** %d %d %d\n", aj[a][i], a, aj[a].size(), aj[a][i], tmp, mx);
        REPP(j, i+1, aj[a].size()) {
            if(aj[a][j]==pr) continue;
            REP(k, aj[a].size()) {
                if(k==i || k==j || aj[a][k]==pr) continue;
                tmp += delnd(aj[a][k], a, aj);
            }
            tmp += ans(aj[a][j], a, aj);
        }        
        if(tmp < mx)
            mx = tmp;
    }
    dp[a][pr] = mx;
    return dp[a][pr];
}

int main()
{
    CASET {
        RI(N);
        vector<vector<int> > aj(N+1);
        //MS0(v);
        REP(i, N-1) {
            DRII(a,b);
            aj[a].PB(b);
            aj[b].PB(a);
        }
        // REPP(i, 1, N+1) {
        //     cout << "Size of aj: " << i << " " << aj[i].size() << endl;
        // }
        int mx = N + 1;
        REPP(i, 1, N+1) {
            REP(x, N+1) REP(y, N+1) {
                dp[x][y] = -1;
                dd[x][y] = -1;
            }
                
            int tmp = ans(i, 0, aj);
            printf("%d %d\n", i, tmp);
            if(tmp < mx) mx = tmp;
        }
        printf("%d\n", mx);
        ++case_n;
    }
}
