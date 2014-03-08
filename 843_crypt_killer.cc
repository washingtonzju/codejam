#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

typedef map<char, char> table;
typedef map<int, vector<string> > dictionary;

bool flg = false;

void decode(vector<string> &wds, table &tb, dictionary &dic, int idx)
{
    // return conditions
    if(flg==true) return;
    if(idx == wds.size()) {
        flg = true;
        return;
    }

    // try all the possible combination: the words ( in dic ) with same length
    int len = wds[idx].size();
    for(int i=0;i<dic[len].size();++i) {
        int k=0;
        table tmp(tb.begin(), tb.end());
        for(k=0;k<len;++k)
            if(tb.find(wds[idx][k])!=tb.end() && tb[wds[idx][k]]!=dic[len][i][k]) break;
            else tb[wds[idx][k]] = dic[len][i][k];
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
        int idx = word.size();
        if(dic.find(idx)==dic.end()) dic[idx] = vector<string>();
        dic[idx].push_back(word);
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
        // brute-force decode by trying the dictionary.
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

