#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=10001000,mo=1e9+7;
ll a[N],n;
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
ll ans;
ll sg,sa;
ll flag,p[N],q[N];
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n) 
	{
		scanf("%lld",&a[i]);
		if(a[1]!=a[i]) flag=1;
		p[i]=qsm(a[i],mo-2),q[i]=a[i]*a[i]%mo;
		sg+=q[i];
	}
	fo(a,1,n) 
			ans=(ans+p[a]*sg*2%mo+a*n*n%mo)%mo;
	printf("%lld\n",ans*3ll%mo);
	if(!flag)printf("0\n");
	else printf("%lld\n",n);
	return 0;
}








