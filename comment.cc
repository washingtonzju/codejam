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

int main()
{
    printf("Case #1:\n");
    int mode = 0;
    int semi = 0;
    int semj = 0;
    char t;
    do{
        t = getchar();
        switch(t) {
        case '/':
            if(semi==1){
                if(mode==0)
                    putchar('/');
                --semi;
            }
            if(semj==1) {
                if(mode > 0){
                    --mode;                    
                }else{
                    putchar('*');
                    putchar('/');
                }
                semj=0;
            }else{
                semi = 1;
            }
            break;
        case '*':
            if(semj==1){
                if(mode==0)
                    putchar('*');
                --semj;
            }
            if(semi==1) {
                ++mode;
                semi = 0;
            }else{
                if(mode < 1)
                    putchar('*');
                else{
                    semj = 1;
                }
            }
            break;
        case EOF:
            break;
        default:            
            if(semi==1){
                if(mode==0)
                    putchar('/');
                --semi;
            }
            if(semj==1){
                if(mode==0)
                    putchar('*');
                --semj;
            }
            if(mode==0)
                putchar(t);
            break;
        }
    }while(t!=EOF);    
    if(semi==1){
        if(mode==0)
            putchar('/');
        --semi;
    }
    if(semj==1){
        if(mode==0)
            putchar('*');
        --semj;
    }
    return 0;
}
