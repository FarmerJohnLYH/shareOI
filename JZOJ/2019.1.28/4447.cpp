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
const int N = 2525,M = 5050,Mo = 1e9+7;
int n,m,T,tot,tail;
int dis[N][N];//路径边数i
struct edge{
    int to,nex;
    int val;
}e[N * 3];
int las[N];
int d[2][M * 2];
bool vis[N];
int sta[N][2];
void link(int x,int y,int t)
{
    e[++ tot].to = y,e[tot].val = t,e[tot].nex = las[x];
    las[x] = tot;
}
int main()
{
    //("D:/LiuYuanHao/b2.in","r",stdin);
    scanf("%d%d%d", &n, &m, &T);
    fo(i,1,m)
    {
        int x,y,t;
        scanf("%d%d%d", &x, &y, &t);
        link(x,y,t),link(y,x,t);
    }
    memset(dis,127,sizeof dis);
    dis[0][1] = 0;
    int hd[2] = {0},tl[2] = {1,0};
    int o = 0;
    d[o][1] = 1;
    fo(i,0,n)
    {
        hd[o] = 0,hd[o ^ 1] = tl[o ^ 1] = 0;
        memset(vis,0,sizeof vis);
        if (i) fo(j,1,n) dis[i][j] = min(dis[i][j],dis[i - 1][j]);
        while (hd[o] ++ != tl[o])
        {
            int now = d[o][hd[o]];
            for (int tmp = las[now];tmp;tmp = e[tmp].nex)
            {
                int to = e[tmp].to;
                if (dis[i + 1][to] > dis[i][now] + e[tmp].val)
                    dis[i + 1][to] = dis[i][now] + e[tmp].val;
            }
        }
        o = o ^ 1;
        fo(j,1,n)
            if (dis[i + 1][j] != oo)
               d[o][++ tl[o]] = j;
    }
    ll ans = 0;
    fo(i,2,n) fd(j,n-1,1)
    {
        sta[tail]
    }
    printf("%lld", ans);
}






