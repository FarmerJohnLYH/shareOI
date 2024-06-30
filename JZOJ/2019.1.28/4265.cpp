#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=1001000,mo=998244353;
ll n,m,T;
ll f[N],v[N],mu[N];
ll p[N],bz[N],p0;
ll s[N];
void init(ll nn)
{
	mu[1]=1;
	p0=0,bz[1]=1;
	fo(i,2,nn) 
	{
		if(!bz[i]) p[++p0]=i,mu[i]=-1;
		fo(j,1,p0)
		{
			if(p[j]*i>nn)break;
			bz[p[j]*i]=1;
			if(i%p[j]==0)
			{
				mu[p[j]*i]=0;
				break;
			}
			else mu[p[j]*i]=-mu[i];
		}
	}
}
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,31)
	{
		if(y&(1ll<<i)) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n>m) swap(n,m);
	fo(i,1,n) scanf("%lld",&v[i]),v[i]%=mo;
	init(N/2);
	ll ans=1;
	fo(d,1,n)
	{
		f[d]=0;
		fo(i,1,n/d)
		{
			ll a=n/(i*d),b=m/(i*d);
			f[d]=(f[d]+(mo-1+mu[i])*(a*b%(mo-1))%(mo-1))%(mo-1);
		}
		s[d]=(s[d-1]+f[d])%(mo-1);
		ans=ans*qsm(v[d],f[d])%mo;
	}
	printf("%lld\n",ans);
	scanf("%lld",&T);
	while(T--)
	{
		ll l,r,u;
		scanf("%lld%lld%lld",&l,&r,&u);u%=mo;
		ll rt=(mo-1+s[r]-s[l-1])%(mo-1);
		ans=ans*qsm(u,rt)%mo;
		printf("%lld\n",ans);
	}
	return 0;
}











