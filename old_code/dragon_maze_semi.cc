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
#define MAXL 110
typedef pair<int, int> pnt;

int tt[MAXL][MAXL];
int dd[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
pnt eng[MAXL][MAXL];
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
            REP(j, M+2) tt[i][j] = -1, eng[i][j].F = -1, eng[i][j].S = 0;
        REPP(i, 1, N+1)
            REPP(j, 1, M+1) RI(tt[i][j]);
        queue<pnt> stk;
        eng[sx][sy].F = 0;
        eng[sx][sy].S = tt[sx][sy];
        //int base = 0, end = 0;
        stk.push(MP(sx, sy));
        //++end;
        int cnt = 0;
        int flg = 0;
        while(stk.size() > 0){
            int cx = stk.front().F;
            int cy = stk.front().S;
            stk.pop();
            REP(i, 4) {
                int tx = cx + dd[i][0];
                int ty = cy + dd[i][1];
                //cout << tx << " " << ty << " " << tt[tx][ty] << " "<< eng[tx][ty] << endl; 
                if(tt[tx][ty]!= -1) {
                    if(eng[tx][ty].F == -1)
                        eng[tx][ty].F = eng[cx][cy].F + 1;
                    else if(eng[tx][ty].F<eng[cx][cy].F+1) continue;
                    if(eng[tx][ty].S == 0)
                        stk.push(MP(tx,ty));
                    int tmp = eng[cx][cy].S + tt[tx][ty];
                    eng[tx][ty].S = (tmp>eng[tx][ty].S?tmp:eng[tx][ty].S);
                }
            }                       
        }
        
        printf("Case #%d: ", case_n);
        if(eng[ex][ey].S==0)
            printf("Mission Impossible.\n");
        else
            printf("%d\n", eng[ex][ey].S);
        case_n++;
    }
    return 0;
}
