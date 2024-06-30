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
#define fo(i,x,y) for (register int asDfg = (y),i = (x);i <= asDfg;++ i)
#define fd(i,x,y) for (register int asDfg = (y),i = (x);i >= asDfg;-- i)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 100100;
int n;
int p[2][N];
struct edge{
    int to,nex;
}e[2][N];
int dep[2][N],fa[2][N][18],tot[2],las[2][N];
int ans;
void Build(int typ,int x,int f)
{
    fa[x][0] = f,dep[x] = dep[f] + 1;
    int y = f,i = 1;
    while (y > 0)
    {
        fa[x][i] = fa[y][i - 1],
        y = fa[y][i - 1];
        i ++;
    }
    fm(tmp,x)
    if (e[tmp].to != f)
        Build(e[tmp].to,x);
}
int Lca(int typ,int x,int y)
{
    if (dep[typ][x] > dep[typ][y]) swap(x,y);
    int i = 0;
    for (int dis = dep[typ][y] - dep[typ][x];dis;dis >>= 1,i ++)
        if ((dis & 1) == 1) y = fa[typ][y][i];
    if (x == y) return x;
    i = 0;
    while (fa[typ][x][i] != fa[typ][y][i]) i ++;
    i --;
    while (i >= 0)
    {
        while (i >= 0 && fa[typ][x][i] == fa[typ][y][i]) i --;
        if (i >= 0)
            x = fa[typ][x][i],y = fa[typ][y][i];
    }   
    return fa[x][0];
}
void link(int typ,int x,int y)
{
    e[typ][++ tot[typ]].to = y,e[typ][tot[typ]].nex = las[typ][x];
    las[typ[x]] = tot[typ];
}
int main()
{
    freopen("D:/LiuYuanHao/c.in","r",stdin);
    scanf("%d", &n);
    fo(i,1,n) scanf("%d", &p[0][i]),p[1][p[0][i]] = i;
    fo(i,2,n)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        link(0,i,x),link(1,i,y);
    }
    dep[0] = -1;
    Build(0,1,0),Build(1,p[1],0);
    if (n <= 100)
    {
        fo(i,1,n) fo(j,1,n)
        if (i != j)
        {
            int p = Lca(0,i,j),q = Lca(1,p[0][i],p[0][j]);
            ans = max(ans,dep[p] + dep[q]);
        }
        printf("%d", ans);
        return 0;
    }
    fo(o,0,1)
    {
        fo(i,1,n)
        {
            for (int tmp = fa[o][i][0];tmp;tmp = fa[o][tmp][0])
            {
                int p = Lca(o,i,tmp),q = Lca(1 - o,p[o][i],p[o][tmp]);
                ans = max(ans,dep[p] + dep[q]);
            }
        }
    }   
    printf("%d", ans);
}






