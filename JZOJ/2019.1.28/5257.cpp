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
const int N = 200200;
int n,q,NUM;
struct edge{
    int to,nex;
}e[N * 2];
int las[N];
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
        Build(e[tmp].to,x);
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
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d%d%d", &n, &q, &NUM);
    fo(i,1,n - 1)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        link(x,y),link(y,x);
    }
    build(1,0);
    while (q --)
    {
        int A,B,C;
        scanf("%d%d%d", &A, &B, &C);
        int x = Lca(A,B),y = Lca(A,C),z = Lca(B,C);
        if (x == z) swap(y,z);
        printf("%d\n", abs(dep[x] - dep[z]) + 1);
    }
}






