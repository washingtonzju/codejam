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
#define LL long long    
using namespace std;

LL cost(LL md, LL r)
{
    return ((md*md)<<1) + (2*r-1LL)*md;
}

int main()
{
    CASET {
        LL r, t;
        scanf("%lld%lld", &r, &t);        
        LL st=0LL, ed = 1, md;
        while(cost(ed, r) < t) ed=(ed << 1);
        while(st <= ed) {
            md = ((st + ed)/2LL);
            LL tmp = cost(md, r);
            if(tmp > t)
                ed = md - 1;
            else if( tmp < t)
                st = md + 1;
            else
                break;
        }
        if(cost(md - 1, r ) > t) md -= 2;
        else if(cost(md, r) > t) md--;
        printf("Case #%d: %lld\n", case_n, md);
        case_n++;
    }
    return 0;
}
