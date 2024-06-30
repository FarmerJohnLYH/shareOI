#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
using namespace std;
const int N=200200,mo=998244353;
typedef long long ll;
ll n,ans;
ll p[N],a[N],b[N],k[N];
ll jc[N],ny[N],c[N],all;
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
int main()
{
//	freopen("operation.in","r",stdin);
//	freopen("operation.out","w",stdout);
	freopen("D:/LiuYuanHao/b3.in","r",stdin);
	scanf("%lld",&n);
	fo(i,1,n) 
	{
		scanf("%lld%lld%lld",&p[i],&a[i],&b[i]);
		k[i]=((mo-(p[i]*b[i]%mo)+p[i])%mo+b[i])%mo;	
		b[i]=a[i]*p[i]%mo;
	}
	//n=3;
	fo(i,1,n)
	{
		int a0=0;
		fo(j,1,n) if(j!=i) a[++a0]=j;
		ans=(ans+b[i]*(((k[a[1]]+1)*(k[a[2]]+1)%mo+k[a[1]]*k[a[2]]%mo+1)%mo)%mo)%mo;
	}
	printf("%lld\n",ans*qsm(6)%mo);
	return 0;
}







