#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

char in[10000];

bool is_red(vector<string> &tab, int col)
{
    for(int i=0;i<tab.size();++i)
        if(tab[i][col] != 'R')
            return false;
    return true;
}

bool is_blue(string &line)
{
    for(int i=0;i<line.length();++i)
        if(line[i]!='B')
            return false;
    return true;
}

bool lock_win(vector<string> &tab, int r_cnt, c_cnt)
{
    
}


int check_sum(vector<string> &tab)
{
    int r_cnt=0, b_cnt=0;
    int winner = -1;
    for(int i=0;i<tab.size();++i)
        for(int j=0;j<tab[i].length();++j)
            if(tab[i][j]!='R' && tab[i][j]!='B' && tab[i][j]!='.')
                return 1;
    
    for(int i=0;i<tab.size();++i)
        for(int j=0;j<tab[i].length();++j)
            if(tab[i][j]=='R')
                ++r_cnt;
            else if(tab[i][j]=='B')
                ++b_cnt;

    int win_cnt=0;
    int i=0;
    
    for(i=0;i<tab.size();++i)
        if(is_blue(tab[i]))
        {
            ++win_cnt;
            winner = 0;
        }   

    for(i=0;i<tab[0].length();++i)
        if(is_red(tab, i))
        {
            ++win_cnt;
            winner = 1;
        }
        
    if(abs(r_cnt - b_cnt) > 1 || win_cnt > 1 || (winner == 0 && r_cnt >= b_cnt) || (winner==1 && b_cnt >= r_cnt))
        return 1;
    else
        return 0;
}

int who_win(vector<string> &tab)
{
    int n = tab.size();
    if(n==0) return 3;

    int status = 0;
    int m = tab[0].length();

    for(int i=0;i<n;++i)
        if(is_blue(tab[i]))
        {
            status = 1;
            break;
        }

    for(int i=0;i<m;++i)
        if(is_red(tab, i))
        {
            status = 2;
        }

    int sub_status = check_sum(tab);
    if(sub_status==1) return 3;
    return status;    
}

int main()
{
    int T, B;
    vector<string> tab;
    char messg[][25] = {"Nobody wins", "Blue wins", "Red wins", "Impossible"};
    scanf("%d", &T);

    for(int ic=1;ic<=T;++ic)
    {
        tab.clear();
        scanf("%d", &B);
        for(int i=0;i<B;++i)
        {
            scanf("%s", in);
            tab.push_back(string(in));
        }
        int status = who_win(tab);       
        //int status = 0;
        printf("Case #%d: %s\n", ic, messg[status]);
    }
    return 0;
}
