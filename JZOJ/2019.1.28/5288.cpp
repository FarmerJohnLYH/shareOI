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
const int N = 2020;
int n,m;
int a[N];
struct node{
    int idx,idy;
    ll val;
    node(int idx_ = 0,int idy_ = 0,ll val_ = 0){idx = idx_,idy = idy_,val = val_}
}c[N * N];
bool cmp(node x,node y)
{
    return x.val < y.val;
}
int t[N],y[N * N];
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    int T = read();
    while (T --)
    {
        n = read();
        fo(i,1,n) a[i] = read();
        fo(i,1,n) fo(j,i + 1,n)
        {
            c[++ m] = node(i,j,1ll * a[i] * a[j]);
        }
        sort(c + 1,c + 1 + m,cmp)
        ll ans = 0;
        memset(t,0,sizeof t);
        fo(i,1,m)
        {
            ans = (ans + 1ll * c[i].val * (i - 1 - t[c[i].idx] - t[c[i].idy])) % Mo;
            ++ t[c[i].idx], ++ t[c[i].idy];
        }
        memset(t,0,sizeof t);
        fd(i,m,1)
        {
            ans = (ans + Mo - ((1ll * c[i].val * (m - i - t[c[i].idx] - t[c[i].idy])) % Mo)) % Mo;
            ++ t[c[i].idx], ++ t[c[i].idy];
        }
        printf("%lld\n", ans);
    }
}











