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
const int N = 1010,NM = 10010;
int n,p;
int a[N],b[N],c[N];
int ans;
//1~5 
void dfs(int now,int A,int B,int C)
{
    if (A > p || C > ans) return;
    if (now > n && B >= p)
    {
        ans = min(ans,C);
    }
    dfs(now + 1,A + a[now],B + b[now],C + c[now]);
    dfs(now + 1,A,B,C);
}
void work1()
{
    dfs(1,0,0,0);
}
//6~10
int f[N][110][110];
void work2()
{
    memset(f,127,sizeof f);
    f[0][0][0] = 0;
    fo(i,0,n - 1)
    {
        fo(j,0,p) fo(k,0,p)
        if (f[i][j][k] < oo)
        {
            if (j + a[i + 1] <= p)
                f[i + 1][j + a[i + 1]][min(k + b[i + 1],p)] = min(f[i][j][k] + c[i + 1],f[i + 1][j + a[i + 1]][min(k + b[i + 1],p)]);
            f[i + 1][j][k] = min(f[i + 1][j][k],f[i][j][k]);
        }
    }
    fo(i,0,p) ans = min(ans,f[n][i][p]);
}
//11~14
int f[N][10100];
void work3()
{
    memset(f,0,sizeof f)
    fo(i,0,n - 1)
    {
        fo(j,0,p) 
        {
            if (j + a[i + 1] <= p)
                f[i + 1][j + a[i + 1]] = max(min(f[i][j] + b[i + 1],p),f[i + 1][j + a[i + 1]]);
            f[i + 1][j] = max(f[i + 1][j],f[i][j]);
        }
    }
    fo(i,0,p) 
        if (f[n][i] >= p) ans = 0;
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%d", &T);
    while (T --)
    {
        scanf("%d%d", &n, &p);
        ans = oo;
        if (11 <= n && n <= 15) work1();
        if (986 <= n && n <= 990) work2();
        if (991 <= n && n <= 1000) work3();
        if (ans >= oo) printf("IMPOSSIBLE!!!\n");
        else printf("%d\n", ans);
    }
}






