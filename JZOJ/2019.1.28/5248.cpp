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
const int N = 100100;
int n,m;
struct edge{
    int to,nex;
}e[N];
struct node{
    int val,id,cost,to;
    int nex;
}c[N],d[N];
int lasE[N],lasC[N],totE,totC;
int f[N][3]/*时间轴 更新后值 更新来源*/,dis[N]/*1~i距离*/;
int fa[22][N],dep[N];
void link(int x,int y)
{
    e[++ totE].to = y,e[totE].nex = lasE[x];
    lasE[x] = totE;
}
void add(int v,int k,int w)
{
    c[++ totC].val = k,c[totC].id = v,c[totC].cost = w;
    int now = v;
    fo(i,0,20)
        if (k & (1 << i)) now = fa[i][now];
    c[totC].to = now;
    lasC[v] = totC;
}
void dfs(int now,int f)
{
    fa[now][0] = f,dep[now] = dep[f] + 1;
    for (int tmp = las[now];tmp;tmp = e[tmp].nex)
        dfs(e[tmp].to,now);
}
void push(node p)
{
    while (d[tl].cost + f[d[tl].fr][1] > p.cost + f[p.fr][1] && tl > 0) -- t;
    d[tl] = p;
}
int dp(int st)
{
    f[st][1] = 0,f[st][2] = 0;
    int hd = 1,tl = 0;
    for (int tmp = lasC[st];tmp;tmp = c[tmp].nex) push(c[tmp]);
    int now = fa[st][0];
    for (;now;now = fa[now][0])
    {
        while (dep[now] < dep[d[hd].to]) ++ hd;
        f[now][1] = d[hd].cost + f[d[hd].id][1];
        f[now][2] = d[hd].id;
        for (int tmp = lasC[now];tmp;tmp = c[tmp].nex) push(c[tmp]);
        if (dis[now]) break;
    }
    int rt = dis[now] + f[now][1];
    for (;now;now = f[now][2])
        dis[now] = dis[fa[now][0]] + (f[fa[now][0]][1] - f[now][1]);
    return (rt);
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    n = read(),m = read();
    fo(i,1,n-1)
    {
        int x = read(),y = read();
        link(y,x);
    }
    dfs(1,0);
    fo(i,1,20) fo(j,1,n)
    {
        fa[i][j] = fa[i - 1][fa[i - 1][j]];
        if (!fa[i][j]) fa[i][j] = 1;
    }
    fo(i,1,m)
    {
        int v = read(),k = read(),w = read();
        add(v,k,w);
    }
    memset(dis,127,sizeof dis);
    dis[1] = 0;
    int q = read();
    while (q --)
    {
        int st = read();
        write(dp(st)),putchar('\n');
    }
}






