#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=2020,mo=998244353;
int n,k;
ll f[N],g[N],jc[N],ny[N],tw[N];
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y)rt=rt*x%mo;
		x=x*x%mo;	
	}
	return rt;
}
ll gg[N];
ll C(int x,int y)
{
	return(jc[x]*ny[y]%mo*ny[x-y]%mo);
}
ll all[N],inv[N];
void init()
{
	jc[0]=1;fo(i,1,N-10) jc[i]=jc[i-1]*i%mo;
	ny[N-10]=qsm(jc[N-10],mo-2);
	fd(i,N-11,0) ny[i]=ny[i+1]*(i+1)%mo;
	tw[0]=1;fo(i,1,N-10) tw[i]=tw[i-1]*2%mo;
	fo(i,0,N-10) gg[i]=qsm(2,C(i,2));
	g[1]=1;inv[1]=all[1]=1;
	fo(i,2,N-10) 
	{
		ll cn2=1ll*i*(i-1)/2,c=1,sum=0;
		all[i]=qsm(2,cn2),inv[i]=qsm(i,mo-2);
		fo(j,1,i-1)
		{
			(sum+=(c*g[j]%mo*all[i-j]%mo))%=mo;
			(c*=(i-j))%=mo;
			(c*=(inv[j]))%=mo;
		}
		g[i]=(all[i]+mo-sum)%mo;
	}
}
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	// freopen("D:/LiuYuanHao/b1.in","r",stdin);
	init();
	scanf("%d%d",&n,&k);
	f[0]=1;
	fo(i,1,n)
	{
		fo(l,1,min(i,k))
			f[i]=(f[i]+f[i-l]*g[l]%mo*C(i-1,l-1)%mo)%mo;
	}
	ll ans=f[n];
	memset(f,0,sizeof f);--k;
	f[0]=1;
	fo(i,1,n)
	{
		fo(l,1,min(i,k))
			f[i]=(f[i]+f[i-l]*g[l]%mo*C(i-1,l-1)%mo)%mo;
	}
	ans-=f[n];
	printf("%lld\n",(ans%mo+mo)%mo);
	return 0;
}








