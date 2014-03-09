#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

typedef map<char, char> table;
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
    if(tb.size() == 26 || idx == wds.size()) {
        flg = true;
        return;
    }
    string type = get_type(wds[idx]);
    vector<string> &cands = dic[type];
    int len = wds[idx].size();
    for(int i=0;i<cands.size();++i) {
        int k=0;
        table tmp(tb.begin(), tb.end());        
        for(k=0;k<len;++k)
            if(tb.find(wds[idx][k])!=tb.end() && tb[wds[idx][k]]!=cands[i][k]) break;
            else tb[wds[idx][k]] = cands[i][k];
        if(k==len) {
            decode(wds, tb, dic, idx+1);
            if(flg==true) return;
        }
        tb=table(tmp.begin(), tmp.end());
    }
}

int main()
{
    int N;
    dictionary dic;
    string word;
    
    cin >> N;
    // build the dictionary: category with word length.
    for(int i=0; i<N; ++i)
    {
        cin >> word;
        string type = get_type(word);
        if(dic.find(type)==dic.end()) dic[type] = vector<string>();
        dic[type].push_back(word);
    }

    string line;
    while(getline(cin, line)){
        //turn line into words
        std::stringstream ss(line);
        vector<string> wds;
        while(ss >> word) {
            wds.push_back(word);
        }
        table tb;
        flg = false;

        decode(wds, tb, dic, 0);
        if(flg==true) {
            for(int i=0;i<line.size();++i)
                if(tb.find(line[i])!=tb.end()) line[i] = tb[line[i]];
        }
        else {
            for(int i=0;i<line.size();++i)
                if(line[i]!=' ') line[i] = '*';
        }
        cout << line << endl;
    }
    return 0;
}
