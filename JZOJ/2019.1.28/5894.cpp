#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int mo=998244353;
ll lx,rx,ly,ry;
int m;ll tw[66];
ll calc(ll x,ll y)
{
	ll rt=y/m+1;
	if(x>0) rt-=(x-1)/m+1;
	return(rt+mo)%mo; 
}
ll Ans(ll r1,ll r2)
{
	ll rt=0,val=r1^r2;if(val%m==0)++rt;
	fd(i,60,0) if(r1&tw[i]) fd(j,60,0) if(r2&tw[j])
	{
		int p=min(i,j),q=max(i,j);
		val=(r1-tw[i])^(r2-tw[j]);
		ll nw=val/tw[q];nw*=tw[q];
		ll mx=nw+tw[q]-1;
		rt=(rt+tw[p]%mo*calc(nw,mx)%mo)%mo;
	}
	fd(i,60,0) 
	{
		if(r1&tw[i])
		{
			val=(r1-tw[i])^r2;
			ll nw=val/tw[i];nw*=tw[i];
			ll mx=nw+tw[i]-1;
			rt=(rt+calc(nw,mx)%mo)%mo;
		}
		if(r2&tw[i])
		{
			val=(r2-tw[i])^r1;
			ll nw=val/tw[i];nw*=tw[i];
			ll mx=nw+tw[i]-1;
			rt=(rt+calc(nw,mx)%mo)%mo;
		}
	}
	return (rt+mo)%mo;
}
int main()
{
	 freopen("mod.in","r",stdin);
	 freopen("mod.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%lld%lld%lld%lld%d",&lx,&rx,&ly,&ry,&m);
	tw[0]=1;fo(i,1,60) tw[i]=tw[i-1]*2ll;
	printf("%lld\n",((Ans(rx,ry)-Ans(rx,ly-1)-Ans(lx-1,ry)+Ans(lx-1,ly-1))%mo+mo)%mo);
	return 0;
}






