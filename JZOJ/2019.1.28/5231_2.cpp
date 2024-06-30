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
const int mn = 500500,mo = 1e9 + 7;
int n,ans,a[mn],f[mn],g[mn];
ll ans; 
int max(int x,int y){return (x >y)?x:y;}
int min(int x,int y){return (x<y)?x:y;}
void solve(int l,int r)
{
    if (l == r) ans = (ans + 1ll * a[l] * a[l]) % mo;    
    if (l >= r) return;
    int md = (l + r) >> 1;
    solve(l,md),solve(md+1,r);
    int mx = 0,mi = inf,j = md,k = md,sum = 0,su2 = 0;
    f[md + 1] = 0,g[md + 1] = inf;
    fd(i,md,l)
        f[i] = max(f[i + 1],a[i]),g[i] = min(g[i + 1],a[i]),
    sum = (sum + 1ll * f[i] * g[i]) % mo;
    int tmp = ans;
    fo(i,md + 1,r)
    {
        mx = max(mx,a[i]);
        mi = min(mi,a[i]);
        while ((j >= l) && (f[j] < mx))
        {
            if ((-- j) < k) sum = (sum - 1ll * f[j + 1] * g[j + 1]) % mo,su2 = (su2 + g[j + 0]) % mo;
            else su2 = (su2 - f[j + 1]) % mo;
        }
        while ((k >= l) && (g[k] > mi))
        {
            if (j < k) su2 = (su2 - g[k]) % mo;
            else sum = (sum - 1ll * f[k] * g[k]) % mo,su2 = (su2 + f[k]) % mo;
            -- k;
        }
        ans = (ans + sum + 1ll * su2 * ((j < k) ? mx : mi) % mo + 1ll * mx * mi % mo * (md - max(j,k))) % mo;
    }
}
int main()
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    scanf("%d", &n);
    fo(i,1,n) scanf("%d", &a[i]);
    solve(1,n);
    printf("%lld", (ans + Mo) % Mo);
}