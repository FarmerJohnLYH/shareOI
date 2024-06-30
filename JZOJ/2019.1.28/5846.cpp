#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=100100*4,mo=1004535809;
int n;
ll jc[N];
ll g[N],f[N];
int m;
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=rt*x%mo;
		x=x*x%mo;	
	}
	return rt;
} 
int wz[N];
void init(int n)
{
	while(m=1;m<=n;m<<=1);
	fo(i,1,m) wz[i]=(wz[i>>1]>>1)+w*(i&1);
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d",&n);
	jc[0]=1;fo(i,1,n) jc[i]=jc[i-1]*i%mo;
	ny[n]=qsm(jc[n],mo-2);fd(i,n-1,0) ny[i]=ny[i+1]*i%mo;
	fo(i,0,n)
	{
		g[i]=(i&1)?(-1):1;
		f[i]=qsm(i,n)*ny[i]%mo;
	}
	init(n);
	ntt(g,1),gtt(f,1);
	fo(i,0,m-1)
		f[i]=f[i]*g[i]%mo;
	ntt(f,-1);
	ll ans=0;
	fo(i,0,n)
		ans=(ans+(f[i]*jc[i]%mo))%mo;
	printf("%lld\n",ans);
	return 0;
}











