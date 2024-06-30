#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef double db;
typedef long long ll;
const ll N=1000100*10;
ll bz[N],n,m;
ll x0,a,b,c;
ll d[N],p;
ll mul(ll x,ll y,ll mo)
{
	ll tp=((ll)((db)x*y/mo+1e-7)*mo);
	ll rt=x*y-tp;
	while(rt<0)rt+=mo;
	return rt;
}
ll qsm(ll x,ll y,ll mo)
{
	x%=mo;ll rt=1;
	fo(i,0,34)
	{
		if((1ll<<i)&y) rt=mul(rt,x,mo);
		x=mul(x,x,mo);
	}
	return rt;
}
int main()
{
	// freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%lld%lld%lld%lld%lld%lld",&x0,&a,&b,&c,&n,&m);
	x0%=m,a%=m,b%=m,c%=m;
	d[0]=x0;
	if(n<N)
	{
		fo(i,1,n) 
			d[i]=(1ll*(a*d[i-1]%m)*d[i-1]+b*d[i-1]+c)%m;
		printf("%lld\n",d[n]);
		return 0;
	}
	if(m<N)
	{
		memset(bz,255,sizeof bz);
		bz[x0]=0;
		fo(i,1,n)
		{
			d[i]=(1ll*a*d[i-1]*d[i-1]+b*d[i-1]+c)%m;
			if(bz[d[i]]>=0) 
			{
				int p=i-bz[d[i]],q=n-i;
				q%=p;
				printf("%lld\n",d[bz[d[i]]+q]);
				return 0;
			}
			else bz[d[i]]=i;
		}
		printf("%lld\n",d[n]);
		return 0;	
	}
	ll k=b/(2*a),p=a*(x0+k);
	ll ans=qsm(p,qsm(2,n,m-1),m);
	printf("%lld\n",((ans*qsm(a,m-2,m)%m)+m-k)%m);
}











