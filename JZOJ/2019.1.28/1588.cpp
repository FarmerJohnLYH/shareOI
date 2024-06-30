#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=2002000;
int n,p;
ll ans,jc[N],ny[N];
ll f[N],s[N];
ll C(ll x,ll y)
{
	if(x>y) return(0);
	if(x<p&&y<p) return(jc[y]*ny[x]%p*ny[y-x]%p);
	return(C(x/p,y/p)*C(x%p,y%p)%p);
}
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=rt*x%p;
		x=x*x%p;
	}
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&p);
	int mx=min(p-1,N-100);
	jc[0]=1;fo(i,1,mx) jc[i]=jc[i-1]*i%p;
	ny[mx]=qsm(jc[mx],p-2);
	fd(i,mx-1,0) ny[i]=ny[i+1]*(i+1)%p;
	fo(i,1,N-100) f[i]=1;
	fd(i,n,1)
	{
		s[i]=s[i<<1]+s[i<<1|1]+1;
		f[i]=f[i<<1]*f[i<<1|1]%p*C(s[i<<1],s[i]-1)%p;
	}
	printf("%lld\n",f[1]);
	return 0;
}








