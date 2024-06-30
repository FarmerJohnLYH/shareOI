#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int mo=998244353,N=2002000;
ll phi[N],ans;
int n;
int p0,p[N],bz[N];
ll qsm(ll x,ll y)
{
	ll rt=1;
	while(y)
	{
		if(y&1) rt=rt*x%mo;
		x=x*x%mo,y/=2;
	}
	return rt;
}
ll jc[N],ny[N];
void init(int n)
{
	bz[1]=1;
	phi[1]=1;
	fo(i,2,n)
	{
		if(!bz[i]) p[++p0]=i,phi[i]=i-1;
 		fo(j,1,n)
		{
			if(1ll*i*p[j]>n) break;
			bz[i*p[j]]=1;
			if(i%p[j]==0) 
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;	
			}
			else phi[i*p[j]]=phi[p[j]]*phi[i];
		}
	}
	jc[0]=1;
	fo(i,1,n)jc[i]=jc[i-1]*i%mo;
	ny[n]=qsm(jc[n],mo-2);
	fd(i,n-1,0) ny[i]=ny[i+1]*(i+1)%mo;
}
ll C(ll n,ll m)
{
	return(jc[n]*ny[m]%mo*ny[n-m]%mo);
}
int main()
{
//	 freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	init(2e6+20);
	scanf("%d",&n);
	fo(d,1,n)
		if(n%d==0) 
			ans=(ans+phi[n/d]*C(2*d,d)%mo)%mo;
	ans=ans*qsm(2*n,mo-2)%mo;
	printf("%lld\n",ans);
	return 0;
}








