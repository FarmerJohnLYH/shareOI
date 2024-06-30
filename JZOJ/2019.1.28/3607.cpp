#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=200100,mo=1000000007;
ll n,k;
ll f[N];
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1ll<<i)&y) rt=1ll*rt*x%mo;
		x=1ll*x*x%mo;
	}
	return rt;
}
ll gcd(ll x,ll y)
{
	return(y==0)?(x):(gcd(y,x%y));
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld%lld",&n,&k);
//	f[0]=1;
	fo(i,k,2*k-1) f[i]=i;
	fo(i,2*k,n) f[i]=(f[i-1]+f[i-k]+1)%mo;
	printf("%d\n",f[n]);
	ll ans=0;
	fo(i,1,n)
		ans=(ans+f[gcd(i,n)])%mo;
	printf("%lld\n",(ll)(1ll*ans*qsm(n,mo-2)%mo));
	return 0;
}











