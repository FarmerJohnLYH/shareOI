#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=10001000,mo=20101009;
int n,m;
bool bz[N];
int p[N],mu[N],f[N];
ll ans;
ll qsm(ll x,int y)
{
	ll rt=1;
	fo(i,0,27)
	{
		if((1<<i)&y) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
void init(int n)
{
	mu[1]=1;
	fo(i,2,n)
	{
		if(!bz[i])p[++p[0]]=i,mu[i]=-1;
		fo(j,1,p[0])
		{
			int t=i*p[j];
			if(t>n)break;
			bz[t]=1;
			if(i%p[j]==0)
			{
				mu[t]=0;
				break;
			}
			mu[t]=-mu[i];
		}
	}
	fo(i,1,n)f[i]=(1ll*mu[i]*i%mo*i%mo+(ll)f[i-1])%mo;
}
ll solve(int d)
{
	ll ans=0;
	ll l=1,nd=n/d,md=m/d;
	while(l<=nd)
	{
		ll r=min(nd/(ll)(nd/l),md/(ll)(md/l));
		ll t=(nd/l)*(nd/l+1)%mo*(md/l)%mo*(md/l+1)%mo;
		ans=(ans+t*(((ll)f[r]-f[l-1])%mo+mo))%mo;
		l=r+1;
	}
	return ans*qsm(4,mo-2)%mo;
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	init(n);
	ll l=1;
	while(l<=n)
	{
		ll r=min(n/(ll)(n/l),m/(ll)(m/l));
		ans=((ll)ans+solve(l)*((l+r)*(r-l+1)%mo*qsm(2,mo-2)%mo)%mo)%mo;
		l=r+1;
	}
	printf("%lld\n",(ans+mo)%mo);
	return 0;
}
