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
const int Mo = 1e9 + 7,N = 200200;
struct edge{
    int to,nex;
}e[N];
int las[N],tot;
int n,cnt[N];
void link(int x,int y)
{
    e[++ tot].to = y,e[tot].nex = las[x];
    las[x] = totl
}
int dfs(int x)
{
    cnt[x] = 1;
    for (int tmp = las[x];tmp;tmp = e[tmp].nex)
    {
        dfs(e[tmp].to);
        cnt[x] += cnt[e[tmp].to];
    }
}
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    n = read();
    fo(i,1,n)
    {
        int x = read();
        link(x,i);
    }
    dfs(0);
    fo(i,1,n) ans = (1ll * ans * cnt[i]) % Mo;
    ans = qsm(ans,Mo - 2);
    fo(i,1,n) ans = (1ll * ans * i) % Mo;
    printf("%lld\n", ans);
}