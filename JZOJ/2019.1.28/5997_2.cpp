#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=10001000/2,mo=998244353;
ll n,k;
ll jc[N],ny[N];
ll qsm(ll x,ll y=mo-2)
{
	y%=mo-1;
	ll rt=1;while(y)
	{
		if(y&1) rt=rt*x%mo;
		y/=2,x=x*x%mo;
	}
	return rt;
}
#define C(n,m) (jc[n]*ny[n-(m)]%mo*ny[m]%mo)
int main()
{
	// freopen("graph.in","r",stdin);
	// freopen("graph.out","w",stdout);
	 freopen("D:/LiuYuanHao/c.ans","w",stdout);
	n=N-100;
	jc[0]=1;
	fo(i,1,n) jc[i]=jc[i-1]*i%mo;
	ny[n]=qsm(jc[n]);
	fd(i,n-1,0) ny[i]=ny[i+1]*(i+1)%mo;  
	fo(kk,0,2) fo(nn,kk+1,10000)
	{
		k=kk,n=nn;
	// scanf("%lld%lld",&n,&k);
	ll ans=0,all=qsm(2ll,(((n-1)*n/2)-(n-1)))*n%mo;
		if(n>k&&k==0)
		{
			// ans=(qsm(2,n-1))*all;
			ans=qsm(2,(n*(n-1)/2))*n%mo;
			printf("%lld\n",ans%mo);
			// return 0;
		}
		if(n>k&&k==1)
		{
			ans=qsm(2,n-2)*(n-1)%mo;
			// printf("%lld\n",ans*all%mo);
			// return 0;
		}
		if(n>k&&k==2)
		{
			ans=qsm(2,n-2)*(((n-1)*n/2)%mo)%mo;
			// printf("%lld\n",ans*all%mo);
			return 0;
		}
		ll qans=0;
		fo(i,1,n-1) 
			qans=(qans+C(n-1,i)*qsm(i,k)%mo)%mo;	
		qans=qans%mo;
		if(qans!=ans) printf("err\n%d %d %lld %lld",n,k,ans,qans);	
		// puts("");
	}
	return 0;
}







