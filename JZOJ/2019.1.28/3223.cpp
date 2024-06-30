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
const int N = 1010,Q = 300300,NUM = 1000;
int n,q;
int a[N],b[N],c[N];
int f[N][N],g[N][N]
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%d%d", &n, &q);
    fo(i,1,n)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    fo(i,1,n) fd(j,NUM,0)
    {
        f[i][j] = f[i - 1][j];
        fo(l,1,c[i])
            if (j >= l * a[i]) 
                f[i][j] = max(f[i][j],f[i - 1][j - l * a[i]] + l * b[i]); 
            else break;
    }
    fd(i,n,1) fd(j,1000,0)
    {
        g[i][j] = g[i + 1][j];
        fo(l,1,c[i])
            if (j >= l * a[i])
                g[i][j] = max(g[i][j],g[i + 1][j - l * a[i]] + l * b[i]);
            else break;
    }
    scanf("%d", &q);
    while (q --)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        ans = 0;
        fo(i,0,y) ans = max(ans,f[x][y - i] + g[x + 2][i]);
        printf("%d\n", ans);
    }
}


