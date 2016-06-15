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

int main()
{
    CASET {
        DRIII(E, R, N);
        vector<int> v(N);
        vector<bool> ck(N, false);
        vector<int> ev(N, 0);
        REP(i, N) RI(v[i]);
        while(1) {
            int i;
            int max = 0, idx = -1;
            for(i=0;i<N;++i)
                if(ck[i]==false && v[i] > max){
                    max = v[i];
                    idx = i;
                }
            if(idx == -1) break;
            ck[idx]=true;
            int cur = idx-1;
            int eng = E;
            //ev[idx] = 0;
            while(cur>-1 && ck[cur]==false) {
                //ck[cur]=true;
                if(idx==cur+1)
                    eng = E - R;
                else
                    eng = ev[cur+1] - R;
                if(eng < 0) eng = 0;
                if(ev[cur] < eng)
                    ev[cur] = eng;                
                --cur;
            }
        }
        //REP(i, N) printf("%d ", ev[i]);
        //printf("\n");
        int eng = E;
        SLL ans = 0LL;
        REP(i, N){
            if(eng > ev[i]) {
                ans += ((SLL)(eng-ev[i]))*v[i]; eng=ev[i];
            }
            eng = eng + R;
            if(eng > E)
                eng = E;
        }
        printf("Case #%d: %lld\n", case_n, ans);
        ++case_n;
    }
    return 0;
}
