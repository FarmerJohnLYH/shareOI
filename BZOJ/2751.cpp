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
const ll K = 100100,Mo = 1000000007;
ll n,m,k;
ll sum,ans,s;
struct node{
    ll x,y;
}a[K];
bool cmp(node a,node b)
{
    return(a.x < b.x);
}
ll Qsm(ll a,ll b)
{
    ll x = 1;
    while (b)
    {
          if (b & 1) x = (x * a) % Mo;
          b >>= 1;
          a = (a * a) % Mo;
    }
    return x;
} 
int main()
{
    freopen("D:/LiuYuanHao/a.in","r",stdin);
    scanf("%lld%lld%lld", &n, &m, &k);
    sum =  (n * (n + 1) / 2) % Mo;
    fo(i,1,k)
        scanf("%lld%lld", &a[i].x, &a[i].y);
    a[++ k].x = 1e9 + 1;
    sort(a + 1,a + 1 + k,cmp);
    ans = 1;
    int las = 0;
    fo(i,1,k)
    {
        if (las != a[i].x)
        {   
            ans = (ans * (sum - s)) % Mo;
            s = 0,las = a[i].x;
            -- m;
        }
        s += a[i].y;
    }
    ans = (ans * Qsm(sum,m)) % Mo;
    printf("%lld", ans);
}





