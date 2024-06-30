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
const int N = 44,TW = 1111111;
int n;
ll f[2][TW],m,p[N],ans;
int it[2],tot[2];
bool check(int x,int y)
{
    if (x == 0)
    {
        if (y > (n >> 1)) return 0;
        else return 1;
    }
    else
    {
        if (y > n) return 0;
        else return 1;
    }
}
void dfs(int typ,int now,ll sum)
{
    if (sum > m) return;
    if (!check(typ,now))
    {
        f[typ][++ tot[typ]] = sum;
        return;
    }
    dfs(typ,now + 1,sum);
    dfs(typ,now + 1,sum + p[now]);
}
int main()
{
    freopen("D:/LiuYuanHao/","r",stdin);
    scanf("%d%lld", &n, &m);
    fo(i,1,n) scanf("%lld", &p[i]);
    dfs(0,1,0),dfs(1,(n>>1)+1,0);
    sort(f[0] + 1,f[0] + 1 + tot[0]);
    sort(f[1] + 1,f[1] + 1 + tot[1]);
    int l = tot[1];
    fo(i,1,tot[0])
    {
        while (f[1][l] + f[0][i] > m && l > 0) -- l;
        if (l == 0) break;
        ans = ans + l;
    }
    printf("%lld", ans);
}






