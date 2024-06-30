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
const int N = 100100;
struct node{
    int x,y;
    ll len;
    node(int x_ = 0,int y_ = 0,ll len_ = 0) {x = x_,y = y_,len = len_;}
}
struct edge{
    int to,nex;
}e[N * 2]
struct pair{
    int st,en,id;
}q[N];
int las[N],tot,v[N];
int Log[N];
int n,tot_e,tot;
int fa[N * 2][22],dep[N];
void link(int x,int y)
{
    e[++ tot_e].to = y,e[tot].nex = las[x],las[x] = tot;
}
void dfs_fir(int now,int f,ll dist)
{
    dep[now] = dep[f] + 1,dis[now] = dist;
    sn[++ sn[0]] = now;
    dfn[++ tot] = now,q[now].st = sum,q[now].id = sn[0];
    //tot sum
    //dfn Tbh
    //sn ap 
    //q.st,en st & en
    //fir id
    for (int tmp = las[now];tmp;tmp = e[tmp].nex)
    {
        dfs_fir(e[tmp].to,now,s + v[e[tmp].to]);
        sn[++ sn[0]] = now;
    }
    q[now].en = tot;
}
void Build(int now,int l,int r)
{
    if (l == r) 
    {
        tr[now].x = tr[now].y = dfn[l];
        tr[now].len = v[];
        return;
    }
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    n = read();
    fo(i,1,n) v[i] = read(),Log[i] = log(i)/log(2);
    fo(i,1,n - 1)
    {
        int x = read(),y = read();
        link(x,y),link(y,x);
    }
    dfs_fir(1,0,0);
    fo(i,1,sn[0]) fa[i][0] = sn[i];
    fo(l,1,22) fo(i,1,sn[0])
    {
        fa[i][l] = fa[i][l - 1];
        if (i + (1 << (l - 1)) <= sn[0] && dep[fa[i + (1 << (l - 1))]] < dep[fa[i][j]])
            fa[i][j] = fa[i + (1 << (l - 1))][j - 1];
    }
    Build(1,1,n);
}












