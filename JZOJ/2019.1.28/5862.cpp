#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define add(x,y) x=(x+(y))%mo
using namespace std;
typedef long long ll;
const ll N=22,M=100100,S=(1048576+100)*2;
const ll mo=1e9+7;
ll a[M],n,m,k;
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,60)
	{
		if((1ll<<i)&y) rt=rt*x%mo;;
		x=x*x%mo;
	}
	return rt;
}
ll ans;
ll f[S],c[S];
ll d[S],bz[S];
ll va[M];
ll lowbit(ll x)
{
	return(x&(-x));
}
ll C(ll x)
{
	ll ret=0;
	while(x) x-=lowbit(x),++ret;
	return (ret&1)?(1):(-1);
}
int main()
{
	freopen("loneliness.in","r",stdin);
	freopen("loneliness.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	ll ppp;scanf("%lld",&ppp);
	scanf("%lld%lld%lld",&n,&m,&k);
	d[1]=(1<<n)-1;
	ll hd=0,tl=1;
	fo(i,0,n) va[i]=qsm(i,k);
	fo(i,1,m)
	{
		scanf("%lld",&a[i]);
		++f[a[i]];
	}
	fo(i,0,n-1) fo(j,0,d[1])
		if(j&(1<<i)) add(f[j^(1<<i)],f[j]); 

	fo(j,1,d[1]) 
		add(ans,qsm(f[j],k)*C(j));
	printf("%lld\n",(ans+mo)%mo);
	return 0;
}











