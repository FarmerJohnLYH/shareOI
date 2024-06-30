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
const int N = 1010,M = 10001000;
int n,T,num,tot,ans;
int a[N][N],f[N][N],fa[N],cnt[2][N];
int ga[N],col[N];
bool flag;
struct edge{
    int to,nex;
}e[M];
int las[N];
void link(int x,int y)
{
    e[++ tot].to = y,e[tot].nex = las[x];
    las[x] = tot;
}
int gf(int x)
{
    return ((fa[x] == x)?(x):(gf(fa[x])));
}
void dfs(int now,int fat)
{
    ++ cnt[num][col[now]];
    for (int tmp = las[now];tmp;tmp = e[tmp].nex)
    {
        int to = e[tmp].to;
        if (to == fat) continue;
        if (col[to] != -1 && col[to] == col[now])
        if (col[to] != -1) continue;
        col[to] = col[now] ^ 1;
        dfs(to,now);
        if (flag) return;
    }
}
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d", &T);
    while (T --)
    {
        scanf("%d", &n);
        flag = 0;
        fo(i,1,n) fo(j,1,n)
            scanf("%d", &a[i][j]);
        fo(i,1,n)
        {
            if (a[i][i]) flag = 1;
            fa[i] = i;
        }
        tot = num = 0;
        fo(i,1,n - 1) fo(j,i + 1,n)
        if (a[i][j])
        {
            link(i,j),link(j,i);
            int fx = gf(i),fy = gf(j);
            if (fx != fy) fa[fx] = fy;
        }
        memset(col,255,sizeof col);
        memset(cnt,0,sizeof cnt);
        memset(f,127,sizeof f);
        fo(i,1,n)
        if (gf(i) == i)
        {
            ++ num;
            col[i] = 0;
            dfs(i,0);
            if (flag) break;
        }
        if (flag)
        {
            printf("-1");
            continue;
        }
        f[0][0] = 0;
        int ans = 0;
        fo(i,1,num) fo(j,0,n)
        {
            int nx = cnt[i][0],ny = cnt[i][1];
            if (j >= nx) f[i][j] = max(f[i][j], f[i - 1][j - nx] + ny);
            if (j >= ny) f[i][j] = max(f[i][j], f[i - 1][j - ny] + nx);
            if (i == num) ans = max(ans,f[i][j] * j);
        }
    }
    printf("%d\n", ans * 2 - tot);
}





