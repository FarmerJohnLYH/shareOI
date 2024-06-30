#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=500500,mo=998244353;
ll n,q,t,p[N],A,B,tp;
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=1ll*rt*x%mo;
		x=1ll*x*x%mo;
	}
	return rt;
}
ll c[N],tag;
ll query(ll l,ll r)
{
	ll ans=0;
	c[l-1]=0;
	fo(i,l,r)
	{
		c[i]=(1ll*c[i-1]*t%mo*(1+mo-p[i])%mo + 1ll*p[i]*(c[i-1]+1)%mo)%mo;
		ans=(ans+1ll*p[i]*(A+1ll*B*(c[i-1]+1)%mo)%mo)%mo;	
	}
	return ans;
}
int main()
{
	freopen("omeed.in","r",stdin);
	freopen("omeed.out","w",stdout);
//	freopen("D:/LiuYuanHao/c2.in","r",stdin);
	scanf("%lld",&tag);
	scanf("%lld%lld%lld%lld%lld%lld",&n,&q,&t,&tp,&A,&B);
	t=1ll*t*qsm(tp,mo-2)%mo;
	tp=A*qsm(2,mo-2)%mo*qsm(4,mo-2)%mo*B%mo;
	fo(i,1,n)
	{
		scanf("%lld%lld",&p[i],&tp);
		p[i]=1ll*p[i]*qsm(tp,mo-2)%mo;
	}
	while(q--)
	{
		ll x,w,l,r;
		scanf("%lld",&tp);
		if(tp)
		{
			scanf("%lld%lld",&l,&r);
 			printf("%lld\n",query(l,r));
		}
		else
		{
			scanf("%lld%lld%lld",&x,&w,&tp);
			w=1ll*w*qsm(tp,mo-2)%mo;
			p[x]=w;
		}
	}
	return 0;
}











