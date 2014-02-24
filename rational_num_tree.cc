/*Cost 39 mins */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

void n2pq(unsigned long long n, unsigned long long &p, unsigned long long &q)
{
    unsigned long long mask = 1LL;
    p = 1LL;
    q = 1LL;
    while (mask <= n && mask != (1LL << 62)) mask = (mask << 1);
    if(mask > n)
        mask = (mask >> 1);
    if(mask > (n>>1))
        mask = (mask >> 1);
    //printf("n=%lu and mask = %lu\n",n, mask);
    while(mask > 0LL)
    {
        if((mask & n) > 0LL)
            p = p + q;
        else
            q = p + q;
        mask = (mask >> 1);
    }
}

unsigned long long pq2n(unsigned long long p, unsigned long long q)
{
    unsigned long long n=0LL;
    unsigned long long pow = 1LL;
    if(p==q) return 1LL;
    do{
        if(p>q){
            n |= pow;
            p = p - q;
        }else{
            q = q - p;            
        }
        pow = (pow << 1LL);
    }while(p>1LL || q>1LL);
    n += pow;
    return n;
}
int main()
{
    int T;
    int id;
    unsigned long long n, p, q;
    scanf("%d", &T);
    for(int i=1;i<T+1;++i)
    {
        scanf("%d", &id);
        switch(id)
        {
        case 1:
            scanf("%lu", &n);
            n2pq(n, p, q);
            printf("Case #%d: %lu %lu\n", i, p, q);
            break;
        case 2:
            scanf("%lu%lu", &p, &q);
            n = pq2n(p, q);
            printf("Case #%d: %lu\n", i, n);
            break;
        }
    }
    return 0;
}
