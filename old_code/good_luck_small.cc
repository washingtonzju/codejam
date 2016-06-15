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

bool flg = false;

void dfs_check(vector<int> &p, vector<int> &c, int cnt, int res, int &stat)
{
    if(cnt == c.size()){
        REP(i, SZ(p))
            if(p[i]==res){
                stat = (stat | (1<<i));
                break;
            }
        return;
    }
    dfs_check(p, c, cnt+1, res, stat);
    dfs_check(p, c, cnt+1, res*(c[cnt]), stat);
}

void dfs(vector<int> &p, vector<int> &c, int N, int M)
{
    if(flg == true) return;
    if(c.size()==N) {
        int stat = 0;
        dfs_check(p, c, 0, 1, stat);
        //printf("%d %d\n", stat, ((1<<p.size())-1));
        if(stat==((1<<p.size())-1))
            flg=true;
        return;
    }
    for(int i=2;i<=M;++i) {
        c.PB(i);
        dfs(p, c, N, M);
        if(flg == true) return;
        c.pop_back();
    }
}

int main()
{
    CASET {
        DRII(R, N); DRII(M, K);
        printf("Case #%d:\n", case_n);
        REP(i, R) {
             vector<int> pros;
             vector<int> ans;
             flg = false;
             REP(j, K) {
                 DRI(tmp); //cout << tmp << endl;                 
                 if(tmp!=1 && find(ALL(pros), tmp)==pros.end()) pros.PB(tmp);
             }
             dfs(pros, ans, N, M);
             //cout << "p size "  << pros.size() << endl;
             REP(j, SZ(ans))
                 printf("%d", ans[j]);
             printf("\n");
        }
        ++case_n;
    }
    return 0;
}
