#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=10001000,M=100010000;
ll n,m,q;
ll w[N],Phi[N],p0,p[N],bz[N];
ll le,ri;
map<ll,ll> qa;
void init(ll n)
{
	bz[1]=1;Phi[1]=1;
	fo(i,2,n)
	{
		if(!bz[i]) p[++p0]=1,Phi[i]=i-1;
		fo(j,1,p0)
		{
			if(1ll*i*p[j]>n)break;
			bz[i*p[j]]=1;
			if(i%p[j]==0) 
			{
				Phi[i*p[j]]=Phi[i]*p[j];
				break;
			}else Phi[i*p[j]]=Phi[i]*Phi[p[j]];
		}
	}
}
ll phi(ll n)
{
	if(n<=1e7) return Phi[n];
	else
	{
		if(qa[n]!=0) return qa[n];
		ll rt=n;
		fo(i,1,p0)
		{
			if(1ll*p[j]*p[j]>n)break;
			if(n%p[j]==0)
				rt=rt/p[j]*(p[j]-1);
		}
		return qa[n]=rt;
	}
}
ll qsm(ll x,ll y,ll mo)
{
	ll rt=1;
	while(y)
	{
		if(y&1)rt=rt*x%mo;
		y/=2,x=x*x%mo;
	}
	return(rt);
}
ll run(ll l,ll r,ll mo)
{
	ll rt=0;
	
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	init(1e7);
	scanf("%lld%lld",&n,&m);
	fo(i,1,n) scanf("%lld",&w[i]);
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&le,&ri);
		printf("%lld\n",run(le,ri,m));
	}
	return 0;
}








