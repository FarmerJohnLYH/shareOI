#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define sqr(now) ((now)*(now))
#define lowbit(now) ((now)&(-now))
#define abs(now) (((now)>=0)?(now):(-(now)))
#define max(now,y) (((now)>(y))?(now):(y))
#define min(now,y) (((now)<(y))?(now):(y))
#define fo(i,now,y) for (int i = (now);i <= (y);++ i)
#define fd(i,now,y) for (int i = (now);i >= (y);-- i)
using namespace std;
typedef double db;
typedef long long ll;
const ll N=1e3+5,Mo=1e9+7;
ll f[N][N],g[N][N];
char s[N],t[N];
ll m,n;
int main()
{
    scanf("%s\n%s\n", s + 1, t + 1);
    n = strlen(s + 1),m = strlen(t + 1);
    fo(i,0,max(m,n)) g[0][i] = g[i][0] = 1;
    fo(i,1,n)
    {
        ll now = -1;
        fo(j,1,m)
        {
            if (s[i] == t[j]) now = j;
            f[i][j] = max(f[i][j - 1],f[i - 1][j - 1]);
            if (f[i - 1][j] > f[i][j]) f[i][j] = f[i - 1][j],g[i][j] = g[i - 1][j];
            if (now == j && now > 0 && f[i - 1][j - 1] + 1 > f[i][j]) g[i][j] = (g[i][j] + g[i - 1][j - 1]) % Mo,f[i][j] = f[i - 1][j - 1] + 1;
        }
    } 
    printf("%lld\n", g[n][m]);
}