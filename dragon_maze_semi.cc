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
#define MAXL 101
typedef pair<int, int> pnt;

int tt[MAXL][MAXL];
int dd[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int eng[MAXL][MAXL];
bool comp(pnt a, pnt b) {
    return eng[a.F][a.S] > eng[b.F][b.S];
}

int main()
{
    CASET {
        DRII(N, M);
        DRII(sx, sy);
        DRII(ex, ey);
        sx++; sy++; ex++; ey++;
        REP(i, N+2)
            REP(j, M+2) tt[i][j] = -1, eng[i][j] = -1;
        REPP(i, 1, N+1)
            REPP(j, 1, M+1) RI(tt[i][j]);
        vector<pnt> stk;
        eng[sx][sy] = tt[sx][sy];
        int base = 0, end = 0;
        stk.push_back(MP(sx, sy));
        //++end;
        int cnt = 0;
        int flg = 0;
        do{
            REPP(cur, base, end+1) {
                if(stk[cur].F == ex && stk[cur].S == ey){ flg = 1; break; }            
                vector<pnt> cands;
                REP(i, 4) {
                    int tx = stk[cur].F + dd[i][0];
                    int ty = stk[cur].S + dd[i][1];
                    //cout << tx << " " << ty << " " << tt[tx][ty] << " "<< eng[tx][ty] << endl; 
                    if(tt[tx][ty]!= -1 && eng[tx][ty] == -1) {
                        cands.PB(MP(tx, ty));
                        eng[tx][ty] = eng[stk[cur].F][stk[cur].S] + tt[tx][ty];
                    }
                }
                sort(ALL(cands), comp);
                REP(i, SZ(cands)) stk.PB(cands[i]);
            }
            if(flg == 1) break;
            base = end + 1;
            end = stk.size() - 1;
            ++cnt;
        }while(base <= end);
        printf("Case #%d: ", case_n);
        if(flg == 0)
            printf("Mission Impossible.\n");
        else
            printf("%d\n", eng[ex][ey]);
        case_n++;
    }
    return 0;
}
