#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (ll i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<ll,ll> PI;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll N=200200,mo=998244353;
ll qsm(ll a,ll b)
{
	ll x=1;
	a%=mo,b%=(mo-1);
	while(b)
	{
		x=((b&1))?((x*(a))%mo):(x);
		b>>=1,a=(a*a)%mo;
	}
	return x;
}
ll m,n,p,q,a,b,A,B,iva,ivb;
ll c[N],d[N],iv[N],fac[N],inv[N];
ll C(ll m,ll n)
{
	return (m<n||n<0||m<0)?0:fac[m]*inv[n]%mo*inv[m-n]%mo;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	freopen("table.in","r",stdin);
	freopen("table.out","w",stdout);
	fac[0]=inv[0]=iv[0]=1;
	fo(i,1,N-100) fac[i]=fac[i-1]*i%mo,iv[i]=qsm(i,mo-2);
	inv[N-100]=qsm(fac[N-100],mo-2);
	fd(i,N-101,1) inv[i]=inv[i+1]*(i+1)%mo;
	scanf("%lld%lld%lld%lld%lld%lld",&m,&n,&a,&b,&p,&q);
	iva=qsm(a,mo-2),ivb=qsm(b,mo-2);
	A=iva,B=mo-b*iva%mo;
	fo(i,1,n) scanf("%lld",&c[i]),d[i]=c[i];
	fd(i,n,1) d[i]=(c[i]-B*c[i-1]%mo+mo)%mo;
	for(;q;q--)
	{
		ll ans=0,x,y;
		scanf("%lld%lld",&x,&y);
		if(x==p) ans=c[y];
		else if(x<p)
		{
			ll tb=1,tc=1;
			fo(l,0,y-1)
			{
				ans=(ans+tc*tb%mo*d[y-l]%mo)%mo;
				tb=tb*B%mo,tc=tc*(p-x+l+1)%mo*iv[l+1]%mo;
			}
			ans=ans*qsm(A,p-x)%mo;
		}
		else
		{
			ll ta=qsm(a,x-p),tb=1,tc=1;
			fo(l,0,min(y-1,x-p))
			{
				ans=(ans+tc*ta%mo*tb%mo*c[y-l]%mo)%mo;
				ta=ta*iva%mo,tb=tb*b%mo,tc=tc*(x-p-l)%mo*iv[l+1]%mo;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
