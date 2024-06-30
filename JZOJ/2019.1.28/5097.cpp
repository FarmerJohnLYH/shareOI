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
#define fm(i,x) for (int i = las[x];i;i = e[i].nex)
using namespace std;
typedef double db;
typedef long long ll;
const int N = 1001000,NUM = 1001000;
int T,n,m,tot;
int a[N],las[N];
int la[NUM],p[N];//a[i]值 前项星nex 
int ans[N];
struct node{
  int nex,to;
}e[N * 2];
int fa[N][22],dep[N];
void Build(int x,int f)
{
    fa[x][0] = f,dep[x] = dep[f] + 1;
    int y = f,i = 1;
    for (int y = f,i = 1;y;++ i)
        fa[x][i] = fa[y][i - 1],y = fa[y][i - 1];

    fm(tmp,x)
    if (e[tmp].to != f)
        Build(e[tmp].to,x);
}
int Lca(int x,int y)
{
    if (dep[x] > dep[y]) swap(x,y);
    int i = 0;
    for (int dis = dep[y] - dep[x];dis;dis >>= 1,++ i)
        if (dis & 1) y = fa[y][i];
    if (x == y) return x;
  i = -1; while (fa[x][i + 1] != fa[y][i + 1]) ++ i;
    
  while (i + 1)
    {
        while ((i + 1) && fa[x][i] == fa[y][i]) -- i;
        if (i + 1) x = fa[x][i],y = fa[y][i];
    }   
    return fa[x][0];
}
void link(int x,int y)
{
  e[++ tot].to = y,e[tot].nex = las[x];
  las[x] = tot;
}
int main()
{
  // freopen("D:/LiuYuanHao/5097.in","r",stdin);
  scanf("%d", &T);
  while (T --)
  {
    int mn = oo,mx = -oo;
    tot = 0;
    memset(las,0,sizeof las);
    memset(la,0,sizeof la);
    memset(ans,127,sizeof ans);
    scanf("%d%d", &n, &m);
    fo(i,1,n) 
    {
      scanf("%d", &a[i]);
      p[i] = la[a[i]],la[a[i]] = i; 
      mn = min(mn,a[i]),mx = max(mx,a[i]);
    }
    fo(i,1,n) ans[i] = mx;
    fo(i,1,m)
    {
      int x,y;
      scanf("%d%d", &x, &y);
      link(x,y);
    }    
    Build(1,0);
    if (mn != 0) memset(ans,0,sizeof ans);
    fo(i,mn,mx)
    {
      int LCA = la[i];
      for (int tmp = la[i];tmp;tmp = p[tmp])
        LCA = Lca(LCA,tmp);
      for (int f = tmp;f;f = fa[tmp][0])
        if (ans[f] < i) break; else ans[f] = i;
    }
    fo(i,1,n) printf("%d", ans[i]);
  }
}





