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
const int N = 200200,M = 400400,Mo = 200020;
int n,m;
int b[N];
struct edge{
    int to,nex,val;
}e[2][M];
int dis[2][N];
int las[2][N],tot[2];
int d[N];
bool vis[N];
void spfa(int typ)
{
    memset(dis[typ],127,sizeof dis[typ]);
    memset(vis,0,sizeof vis);
    int hd = 0,tl = 1;
    if (typ) d[tl] = 1;
    else d[tl] = n;
    dis[typ][d[tl]] = 0,vis[d[tl]] = 1;
    while (hd != tl)
    {
        hd = hd % Mo + 1;
        int now = d[hd];
        for (int tmp = las[typ][now];tmp;tmp = e[typ][tmp].nex)
        {
            if (e[typ][tmp].val + dis[typ][now] < dis[typ][e[typ][tmp].to])
            {
                dis[typ][e[typ][tmp].to] = e[typ][tmp].val + dis[typ][now];
                if (!vis[e[typ][tmp].to])
                {
                    vis[e[typ][tmp].to] = 1;
                    tl = tl % Mo + 1;
                    d[tl] = e[typ][tmp].to;
                }
            }
        }
        vis[now] = 0;
    }
}
void link(int typ,int x,int y,int v)
{
    e[typ][++ tot[typ]].to = y,e[typ][tot[typ]].val = v;
    e[typ][tot[typ]].nex = las[typ][x];
    las[typ][x] = tot[typ];
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    n = read(),m = read();
    fo(i,1,n) b[i] = read();
    fo(i,1,m)
    {
        int x = read(),y = read(),z = read();
        link(1,x,y,z),link(0,y,x,z);
    }
    spfa(0),spfa(1);
    int ans = dis[1][n],now = 1,typ = 1;
    d[1] = 1;
    while (d[now] != n)
    {
        int x = d[now],mn = oo,p = 0;
        for (int tmp = las[typ][x];tmp;tmp = e[typ][tmp].nex)
        {
            if (e[typ][tmp].val + dis[typ][x] == dis[typ][e[typ][tmp].to] && dis[1][e[typ][tmp].to] + dis[0][e[typ][tmp].to] == ans)
            {
                if (d[e[typ][tmp].to] < mn)
                {
                    mn = d[e[typ][tmp].to];
                    p = tmp;
                }
            }
        }
        d[++ now] = p;
    }
    printf("%d\n", ans);
    fo(i,1,now) printf("%d ", d[i]);
}











