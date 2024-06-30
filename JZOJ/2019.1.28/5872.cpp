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
ll ans,sg,flag;
ll p[N],q[N];
ll read()
{
    char ch=' ';ll q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10ll+ch-48;ll n=q*w;return n;
}
int main()
{
	freopen("problem.in","r",stdin);
	freopen("problem.out","w",stdout);
	// freopen("D:/LiuYuanHao/a1.in","r",stdin);
	// scanf("%lld",&n);
	n=read();
	fo(i,1,n) 
	{
		a[i]=read();
		// scanf("%lld",&a[i]);
		if(a[1]!=a[i]) flag=1;
		p[i]=qsm(a[i],mo-2),q[i]=a[i]*a[i]%mo;
		sg=(sg+q[i])%mo;
		ans=(ans+3ll*n%mo*n%mo*a[i]%mo)%mo;
	}
	fo(i,1,n) ans=(ans+6ll*n%mo*p[i]%mo*sg%mo)%mo;
	printf("%lld\n",ans);
	if(!flag)printf("0\n");
	else printf("%lld\n",n);
	return 0;
}








