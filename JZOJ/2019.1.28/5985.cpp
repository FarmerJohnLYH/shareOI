#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll D=1010,N=100100,mo=1000109107;
ll S,T,n,m;
ll f[N],jc[N],ny[N];
ll C(ll n,ll m){if(n<m)return 0;return(jc[n]*ny[m]%mo*ny[n-m]%mo);}
ll P(ll n,ll m){return(C(n+m,m));}
ll v(ll p){return(p&1)?(-1):(1);}
ll ans;
ll qsm(ll x,ll y)
{
	ll rt=1;
	while(y)
	{
		if(y&1)rt=rt*x%mo;
		y/=2,x=x*x%mo;
	}
	return rt;
}
int main()
{
	freopen("D:/LiuYuanHao/c.in","r",stdin);
//	freopen("polynomial.in","r",stdin);
//	freopen("polynomial.out","w",stdout);
	scanf("%lld%lld%lld%lld",&S,&T,&n,&m);
	jc[0]=1;fo(i,1,N-10) jc[i]=jc[i-1]*i%mo;
	ny[N-10]=qsm(jc[N-10],mo-2);
	fd(i,N-11,0) ny[i]=ny[i+1]*(i+1)%mo;
	fo(j,1,S) 
	{
		fo(i,0,n) 
		if(j>i*T)f[j]=(f[j]+v(i)*C(j-i*T-1,n-1)*C(n,i)%mo)%mo;
	}
	ll p=S;
	fo(S,1,p)
		fo(k,n,S-(m-n))
		{
	 		ans=(ans+f[k]*C(S-k-1,m-n-1)%mo)%mo;
		}
	printf("%lld\n",ans);
	return 0;
}








