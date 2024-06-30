#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
ll lowbit(ll x) {return((x)&(-x));}
ll min(ll x,ll y){return (x>y)?(y):(x);}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const ll N=100100,V=55,mo=998244353;
ll n,k;
ll qa[N],a[N];
ll jc[N],ny[N];
ll qsm(ll a,ll b)
{
	ll x=1;
	a%=mo,b%=(mo-1);
	while(b)
	{
		x=((b&1))?((1ll*x*(a))%mo):(x);
		b>>=1,a=(1ll*a*a)%mo;
	}
	return x;
}
ll C(ll x,ll y)
{
	if(x<y)return 0;
	return((1ll*jc[x]*(1ll*ny[y]*ny[x-y]%mo)%mo)%mo);
}
ll ans=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("D:/LiuYuanHao/b2.in","r",stdin);
	scanf("%lld%lld",&n,&k);
	fo(i,1,n)
		scanf("%lld",&qa[i]);
	jc[0]=1;fo(i,1,100001) jc[i]=(1ll*jc[i-1]*i)%mo;
	ny[100001]=qsm(jc[100001],mo-2);fd(i,100000,1) ny[i]=(1ll*ny[i+1]*(i+1))%mo;
	ny[0]=1;
	fo(o,0,35)
	{
		int g1=0,g0=0;
		fo(i,1,n) if(qa[i]&(1ll<<o)) ++g1;
		g0=n-g1;
		ll sum=0;
		fo(i,0,k)
		{
			if(i&1)
				sum=(sum+C(g1,i)*C(g0,k-i)%mo)%mo;	
		}
		ans=(ans+sum*(1ll<<o))%mo;
	}
	printf("%lld\n",ans);
	return 0;
}









