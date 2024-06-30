#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
ll lowbit(ll x) {return((x)&(-x));}
ll min(ll x,ll y){return (x>y)?(y):(x);}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const ll N = 1e9,Mo = 1e9 + 7;
ll a,b;
ll qsm(ll a,ll b,ll Mo)
{
    ll x = 1;
    a %= Mo;
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
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	scanf("%lld%lld", &a, &b);
	ll tmp = qsm(a,b-1,Mo-1);
	ll ans = qsm(a,tmp,Mo);
	printf("%lld", ans);
	return 0;
}
