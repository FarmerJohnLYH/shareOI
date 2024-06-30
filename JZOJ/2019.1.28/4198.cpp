#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (register int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (register int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N = 5050,Mo = 1e9 + 7;
int bz[N];
struct edge{
    int nex,to;
}e[100292];
int las[N],tot;
ll ans = 0;
int n,m;
void dfs(int now)
{
    if (now > n)
    {
        ans = (ans + 1) % Mo;
        return;
    }
    dfs(now + 1);
    if (!bz[now])
    {
        for (int tmp = las[now];tmp;tmp = e[tmp].nex)
            ++ bz[e[tmp].to];
        dfs(now + 1);
        for (int tmp = las[now];tmp;tmp = e[tmp].nex)
            -- bz[e[tmp].to];
    }
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%d%d", &n, &m);
    fo(i,1,m)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        link(x,y),link(y,x);
    }
    dfs(1);
    printf("%lld", ans);
}











