#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (register int asDfg = (y),i = (x);i <= asDfg;++ i)
#define fd(i,x,y) for (register int asDfg = (y),i = (x);i >= asDfg;-- i)
using namespace std;
typedef double db;
typedef long long ll;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N = 20200, NUM = 30,S[NUM] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777};
struct node
{
    int tag,num[N],l,r;
}h[1010/*sqrt(n)*/];
//
char s[10];
int l,r,v,n,m,size;
int a[N];
bool judge(int x)
{
    while (x % 10 == 4 || x % 10 == 7) x /= 10;
    return !x;
}
void build()
{
    fo(i,0,n / size + 1)
    {
        int j = 1;
        h[i].tag = 0;
        h[i].l = i * size + 1;
        fo(j,1,min(size,n - size * i)) ++ h[i].num[a[i * size + j]];
        h[i].r = i * size + j - 1;
    }
}
void add(int l,int r,int val)
{
    int j = l % size == 0 ? l / size - 1: l / size, k = r % size == 0 ? r / size - 1 : r / size;
    if (j == k)
    {
        fo(i,l,r)
            -- h[j].num[a[i]],a[i] += val,++ h[j].num[a[i]];
        return;
    }
    fo(i,l,h[j].r)
        -- h[j].num[a[i]],a[i] += val,++ h[j].num[a[i]];
    fo(i,j + 1,k - 1) h[i].tag += val;
    fo(i,h[k].l,r)
        -- h[k].num[a[i]],a[i] += val,++ h[k].num[a[i]];
}
int query(int l,int r)
{
    int ret = 0;
    int j = l % size == 0 ? l / size - 1 : l / size,k = r % size == 0 ? r / size - 1 : r / size;
    if (j == k)
    {
        fo(i,l,r)
        {
            int tmp = a[i] + h[j].tag;
            fo(j,0,NUM - 1)
            if (S[j] == tmp)
            {
                ++ ret;
                break;
            }
        }
        return ret;
    }
    fo(i,l,h[j].r)
    {
        int tmp = a[i] + h[j].tag;
        fo(i,0,NUM - 1)
            if (S[i] == tmp)
            {
                ++ ret;
                break;
            }
    }
    fo(i,j + 1,k - 1)
    {
        fo(l,0,NUM - 1)
        {
            int tmp = S[l] - h[i].tag < 0 ? 0 : S[l] - h[i].tag;
            ret += h[i].num[tmp];
        }
    }
    fo(i,h[k].l,r)
    {
        int tmp = a[i] + h[k].tag;
        fo(l,0,NUM - 1)
            if (S[l] == tmp)
            {
                ++ ret;
                break;
            }
    }
    return ret;
}
int main()
{
    scanf("%d%d", &n, &m);
    fo(i,1,n) scanf("%d", a[i]);
    //a[i] a+i    
    size = sqrt(n);
    build();
    while (m --)
    {
        scanf("%s%d%d", s, &l, &r);
        if (s[0] == 'a')
        {
            scanf("%d",&v);
            add(l,r,v);
        }
        else
        {
            int ans = query(l,r);
            printf("%d\n",ans); 
        }
    }
}