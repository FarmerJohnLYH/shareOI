#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=10001000;
ll L,R,k;
ll p[N],bz[N],p0,pb[N];
void shai(ll x,ll n)
{
	fo(i,max(L/x-1,1ll),R/x+1) 
	{
		ll tp=i*x;
		if(tp>=L&&tp<=R) pb[tp-L]=1;
	}
}
void init(ll n)
{
	ll g=sqrt(R)+1;
	bz[1]=1;
	fo(i,2,n)
	{
		if(!bz[i]) 
		{
			p[++p0]=i;	
			shai(i,n);
		}
		fo(j,1,p0)
		{
			ll tp=1ll*p[j]*i;
			if(tp>n) break;
			bz[tp]=1;
			if(i%p[j]==0) break;
		}
	}
}
ll gg;
int check(ll x)
{
	if(x<=gg) return(!bz[x]);
	return(!pb[x-L]);
	fo(i,1,p0)
	{
		if(p[i]*p[i]>x) return 1;
		if(x%p[i]==0) return 0;
	}
	return 1;
}
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld%lld%lld",&L,&R,&k);
	 gg=min(k,(ll)sqrt(R)+1);
	init(min(k,(ll)sqrt(R)+1));
	ll ans=0;
	fo(i,L,R)
		if(check(i)) ans^=i;
	printf("%lld\n",ans);
	return 0;
}











