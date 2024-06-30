#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=11;
ll p[N],a[N];
ll n;
ll c[N];
ll qsm(ll x,ll y,ll mo)
{
	ll rt=1;
	fo(i,0,31)
	{
		if(y&(1ll<<i)) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
void crt(ll *a,ll *p,ll &x,ll &y)
{
	x=0,y=1;
	fo(i,1,n) y=y*p[i]; 	
	fo(i,1,n)
	{
		ll tp=y/p[i];
		c[i]=(tp*qsm(tp,p[i]-2,p[i])*a[i])%y;
		x=(x+c[i])%y;
	}
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n) scanf("%lld%lld",&p[i],&a[i]);
	ll v=0,m=0;
	crt(a,p,v,m);
	printf("%lld\n",v);
	return 0;
}











