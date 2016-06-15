#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

typedef string table;
typedef map<string, vector<string> > dictionary;

bool flg = false;
string get_type(string word)
{
    char tt = 'a';
    map<char, char> has;
    string ans = "";
    for(int i=0;i<word.size();++i) {
        if(has.find(word[i])==has.end())
            has[word[i]]= (tt++);
        ans += has[word[i]];
    }
    return ans;
}

void decode(vector<string> &wds, table &tb, dictionary &dic, int idx)
{
    // return conditions
    if(flg==true) return;
    for(int i=0;i<26;++i)
        for(int j=i+1;j<26;++j)
            if(tb[i]==tb[j] && tb[i]!='*')
                return;
    if(idx == wds.size()) {        
        flg = true;
        return;
    }    
    string type = get_type(wds[idx]);
    vector<string> &cands = dic[type];
    int len = wds[idx].size();
    for(int i=0;i<cands.size();++i) {
        int k=0;
        table tmp = tb;
        for(k=0;k<len;++k)
            if(tmp[wds[idx][k]-'a']!='*' && tmp[wds[idx][k]-'a']!=cands[i][k]) break;
            else tmp[wds[idx][k]-'a'] = cands[i][k];        
        if(k==len) {            
            decode(wds, tmp, dic, idx+1);
            if(flg==true) {
                tb = tmp;
                return;
            }
        }
    }
}

int main()
{
    int N;
    dictionary dic;
    string word;
    
    cin >> N;
    // build the dictionary: category with word length.
    set<string> dup;
    for(int i=0; i<N; ++i)
    {
        cin >> word;
        
        if(dup.find(word)!=dup.end()) continue;
        string type = get_type(word);
        if(dic.find(type)==dic.end()) dic[type] = vector<string>();
        dic[type].push_back(word);
        dup.insert(word);
    }

    string line;
    getline(cin, line);
    while(getline(cin, line)){
        //turn line into words
        if(line.length()==0) {cout << endl; continue;}
        std::stringstream ss(line);
        vector<string> wds;
        set<string> uniq;
        while(ss >> word) {
            if(uniq.find(word)!=uniq.end())
                continue;
            uniq.insert(word);
            wds.push_back(word);
        }
        table tb = "**************************";
        flg = false;

        decode(wds, tb, dic, 0);
        if(flg==true) {
            for(int i=0;i<line.size();++i)
                if(line[i]!=' ') line[i] = tb[line[i]-'a'];
        }
        else {
            for(int i=0;i<line.size();++i)
                if(line[i]!=' ') line[i] = '*';
        }
        cout << line << endl;
    }
    return 0;
}
