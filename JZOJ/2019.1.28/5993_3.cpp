#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=15005000,mo=998244353;//1e9+9;
ll n,m;
ll all,ans;
ll jc[N],ny[N];
ll qsm(ll x,ll y=mo-2)
{
	ll rt=1;
	while(y)
	{
		if(y&1) rt=rt*x%mo;
		y/=2,x=x*x%mo;
	}
	return rt;
}
ll C(ll n,ll m)
{
	return(jc[n]*ny[m]%mo*ny[n-m]%mo);
}
int main()
{
//	freopen("exodus.in","r",stdin);
//	freopen("exodus.out","w",stdout);
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	 freopen("D:/LiuYuanHao/b.ans","w",stdout);
	scanf("%lld%lld",&n,&m);
	fo(nn,1,20)
	{
		n=nn;
		ans=0;
		all=qsm(2,n);
		jc[0]=1;
		fo(i,1,n+4) jc[i]=jc[i-1]*i%mo;
		ny[n+4]=qsm(jc[n+4]);
		fd(i,n+3,0) ny[i]=ny[i+1]*(i+1)%mo;
	
	
		fo(i,0,(n+1)/2) 
		{
			ll tp=(n+1-2*i+mo)%mo;tp=tp*tp%mo*tp%mo;
			ans=(ans+C(n+1,i)*tp%mo)%mo;
		}
		ans=ans*qsm(n+1)%mo;
		printf("%lld %lld\n",ans/all,ans%all);
	}
	return 0;
}








