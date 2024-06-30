#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define abs(x) (((x)>=0)?(x):(-(x)))
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define fo(i,x,y) for (int i = (x);i <= (y);++ i)
#define fd(i,x,y) for (int i = (x);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
using namespace std;
const int N = 100100;
int n,m,tot;
struct edge{
    int to,nex;
}e[N * 2];
int las[N];
int f[N],d[N];
bool bz[N];
void add(int x,int y)
{
    e[++ tot].t = y,
    e[tot].nex = las[x],
    las[x] = tot,
    ++ d[y];
}
void dfs(int x,int y)
{
    int s[3] = {0};
    rep(i,x) 
        if (e[i].t != y)
        {
            dfs(e[i].t,x);
            ++ s[f[e[i].t]];
        }
        if (bz[x])
        {
            ans += s[1];
            f[x] = 2;
        }
        else
        if (s[1] && s[2])
        {
            ++ ans;
            f[x] = 0;
        }
        else if (s[1]) f[x] = 1;
        else if (s[2]) f[x] = 2;
        else if (s[0]) f[x] = 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    ++ n;
    fo(i,1,n-1)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        ++ x,++ y;
        add(x,y),add(y,x);
    }
    fo(i,1,n) f[i] = 1;
    fo(i,1,m) 
    {
        scanf("%d", &x),++ x;
        if (d[x] == 1)
        {
            printf("-1\n");
            return 0;
        }
        bz[x] = 1;
    }
    fo(i,1,n)
    if (d[i] == 1)
    {
        dfs(i,0);
        if (f[i] == 2) ++ ans;
        printf("%d\n", ans);   
        return 0;
    }
}