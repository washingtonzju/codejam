#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

//Definition of node.
struct node {
    int val;
    node *nb[3]; // pointers to neighbor.
    node():val(-1){ nb[0]=nb[1]=nb[2]=NULL;}
};

typedef pair<node*, node*> edge; // represent an edge.

void add_nb(node *n1, node *n2)
{
    int idx = 0;
    // remove duplicates
    for(idx=0;idx < 3;++idx)
        if(n2==n1->nb[idx])break;

    // insert into neighbor list.
    if(idx == 3)
    {
        for(int i=0;i<3;++i)
            if(n1->nb[i]==NULL) {
                n1->nb[i] = n2;
                break;
            }
    }
}

int dfs(node *n1, set<edge> &check){   
    int max = 0, tmp = 0;
    // for each nodes, the max route is generated from three branches.
    // or 0 if no one is available.
    for(int i=0;i<3;++i) {
        if(n1->nb[i]!=NULL&&check.find(edge(n1, n1->nb[i]))==check.end()
           && check.find(edge(n1->nb[i], n1))==check.end()) {
            check.insert(edge(n1, n1->nb[i]));
            tmp = dfs(n1->nb[i], check) + 1;
            if(tmp > max)
                max = tmp;
            check.erase(edge(n1, n1->nb[i]));
        }
    }
    return max;
}

int main()
{
    int n, m;
    int a, b;
    while(scanf("%d%d", &n, &m)!=EOF && !(n==0 && m==0))
    {
        vector<node> nds(n, node()); // nodes data structure
        // loading nodes.
        for(int i=0;i<m;++i){
            scanf("%d%d", &a, &b);
            add_nb(&(nds[a]), &(nds[b]));
            add_nb(&(nds[b]), &(nds[a]));
        }

        // try every node as starter
        int max = 0, tmp = 0;
        for(int i=0;i<n;++i) {
            set<edge> check;
            tmp = dfs(&(nds[i]), check);
            if(tmp > max) max = tmp;
        }
        printf("%d\n", max);
    }
    return 0;
}
