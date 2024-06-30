#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll M=32768+100,mo=1004535809/* 998244353*/;
ll g[M],f[M],a[M],W[M],b[M];
ll m,n,O,S,U,sz,rev,wz[M];
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
ll p;
void init(ll x)
{
	for(sz=1;sz<=x;sz<<=1);rev=qsm(sz,mo-2);
	fo(i,1,sz-1) wz[i]=(wz[i>>1]>>1)+((i&1)*(sz>>1));
	W[0]=1;W[1]=qsm(3,(mo-1)/sz);
	fo(i,2,sz) W[i]=(W[i-1]*W[1])%mo;
}
void dft(ll *c,ll flag)
{
	fo(i,0,sz-1) b[wz[i]]=c[i];ll tp;
	for (ll wv=2,hf=1;wv<=sz;hf=wv,wv<<=1)
	fo(i,0,hf-1) for(ll j=i;j<sz;j+=wv)
	tp=(((flag==1)?W[i*sz/wv]:W[sz-(i*sz/wv)])*b[j+hf])%mo,b[j+hf]=(b[j]-tp+mo)%mo,b[j]=(b[j]+tp)%mo; 
	fo(i,0,sz-1) 
	{
		c[i]=b[i];
		if(flag==-1)c[i]=c[i]*rev%mo;
	}
}
void solve(ll n)
{
	if(n==0)
	{
		g[0]=1;
		return;	
	}
	if(n%2)
	{
		solve(n-1);
		dft(g,1);
		fo(i,0,sz-1)g[i]=(g[i]*a[i])%mo;
		dft(g,-1);
		fo(i,0,sz-1)f[i]=(f[i]+g[i])%p;
		fo(i,m+1,sz-1) g[i]=0;
		return;
	}
	solve(n/2);
	dft(f,1),dft(g,1);
	fo(i,0,sz-1) b[i]=(g[i]*f[i])%mo;
	fo(i,0,sz-1) g[i]=(g[i]*g[i])%mo;
	dft(f,-1),dft(g,-1),dft(b,-1);
	fo(i,0,sz-1)f[i]=(f[i]+b[i])%p;
	fo(i,m+1,sz-1) g[i]=0;
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%lld%lld%lld%lld%lld%lld",&m,&p,&n,&O,&S,&U);
	init(2*m);
	fo(i,0,sz-1) a[i]=(0ll+i*i*O+i*S+U)%p;
	dft(a,1);
	solve(n);
	printf("%lld\n",f[n]);
	return 0;
}











