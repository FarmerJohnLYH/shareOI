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
int n,m,q;
struct edge{
    int to,nex,val;
}e[N];
int tot,las[N];
int fa[N][22],dep[N],dis[N];
void Build(int x,int f)
{
    fa[x][0] = f,dep[x] = dep[f] + 1;
    int y = f,i = 1;
    while (y > 0)
    {
        fa[x][i] = fa[y][i - 1],
        y = fa[y][i - 1];
        i ++;
    }
    for (int tmp = las[x];tmp;tmp = e[tmp].nex)
    if (e[tmp].to != f)
        dis[e[tmp].to] = dis[x] + e[tmp].val,Build(e[tmp].to,x);
}
int Lca(int x,int y)
{
    if (dep[x] > dep[y]) swap(x,y);
    int i = 0;
    for (int dis = dep[y] - dep[x];dis;dis >>= 1,i ++)
        if ((dis & 1) == 1) y = fa[y][i];
    if (x == y) return x;
    i = 0;
    while (fa[x][i] != fa[y][i]) i ++;
    i --;
    while (i >= 0)
    {
        while (i >= 0 && fa[x][i] == fa[y][i]) i --;
        if (i >= 0)
            x = fa[x][i],y = fa[y][i];
    }   
    return fa[x][0];
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    n = read(),m = read(),q = read();
    fo(i,1,m) 
    {
        int x = read(),y = read(),t = read();
        link(x,y,t),link(y,x,t);
    }
    Build(1,0);
    fo(i,1,q)
    {
        int x = read(),y = read();
        int l = Lca(x,y);
        printf("%d\n", dis[x] + dis[y] - 2 * dis[l]);
    }
}











