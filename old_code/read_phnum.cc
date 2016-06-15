/* Cost 1 hour and 25 mins*/
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;
char digits[11][15] = {"zero ","one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
char times[12][15] = {"", "", "double ", "triple ", "quadruple ", "quintuple ", "sextuple ", "septuple ", "octuple ", "nonuple ", "decuple "};

void read2ans(char *in, char *ans, int start, int end)
{
    int cnt=1;
    if(start == end-1)
    {
        strcat(ans, digits[in[start]-'0']);
        return;
    }
    for(int i=start+1;i<end;++i)
    {
        if(in[i]==in[i-1]) {
            ++cnt;            
        }
        else{               
            if(cnt==1)
                strcat(ans, digits[in[i-1]-'0']);
            else if(cnt < 11) {                       
                strcat(ans, times[cnt]);
                strcat(ans, digits[in[i-1]-'0']);
            }else{
                while(cnt > 0){
                    strcat(ans, digits[in[end-1]-'0']);
                    --cnt;
                }
            }
            cnt=1;            
        }
    }
    
    if(cnt==1)
        strcat(ans, digits[in[end-1]-'0']);
    else if(cnt < 11) {        
        strcat(ans, times[cnt]);
        strcat(ans, digits[in[end-1]-'0']);
    }else{
        while(cnt > 0){
            strcat(ans, digits[in[end-1]-'0']);
            --cnt;
        }
    }
}

void read(char *in, char *fmt, char *ans)
{
    int idx = 0;
    int upper = 0;    

    int i=0;
    while(fmt[i]!='\0')
    {
        sscanf(fmt+i, "%d", &upper);
        //printf("upper = %d\n", upper);
        read2ans(in, ans, idx, upper+idx);
        idx = idx+upper;
        while(fmt[i]!='\0' && fmt[i]!='-') ++i;
        if(fmt[i]=='\0') break;        
        ++i;
    }
    int len = strlen(ans);
    ans[len-1] = '\0';
}

int main()
{
    int T;
    scanf("%d", &T);
    char num[202], fmt[402];
    char ans[4000];
    for(int i=1;i<T+1;++i)
    {
        memset(ans, 0, sizeof(ans));
        scanf("%s %s", num, fmt);
        read(num, fmt, ans);
        printf("Case #%d: %s\n", i, ans);
    }
    return 0;
}
