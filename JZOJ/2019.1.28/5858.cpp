#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=400400*4,M=N/8;
const ll mo=998244353;
ll n,m,k;
ll f[N],g[N];
ll jc[N],p[N],bz[N],p0;
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,61)
	{
		if((1ll<<i)&y) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
void init(ll n)
{
	bz[0]=bz[1]=1;p0=0;
	fo(i,2,n)
	{
		if(!bz[i]) p[++p0]=i;	
		fo(j,1,p0)
		{
			if(p[j]*i>n) break;
			bz[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
ll f0,g0;
ll get(ll n)
{
	ll w=1;
	for(;w<n;w*=2);
	return w;
}
ll sz;
ll wz[N],w[N];
ll a[N];
void dft(ll *c,ll typ)
{
	w[0]=1,w[1]=qsm(3,(mo-1)/sz);
	fo(i,2,sz-1) w[i]=w[i-1]*w[1]%mo;
	if(typ==1) fo(i,1,sz/2) swap(w[i],w[sz-i]);
	fo(i,0,sz-1) a[i]=c[wz[i]]%mo;
	ll tp;
	for(ll wh=2,hf=1;wh<=sz;hf=wh,wh<<=1)
	fo(j,0,hf-1) for(int i=j;i+hf<=sz-1;i+=wh)
		tp=w[sz/wh*j]*a[i+hf]%mo,a[i+hf]=(a[i]-tp+mo)%mo,a[i]=(a[i]+tp)%mo;
	if(typ==1) 
	{
		ll p=qsm(sz,mo-2);
		fo(i,0,sz-1) a[i]=a[i]*p%mo;
	}
	fo(i,0,sz-1) c[i]=(a[i]+mo)%mo;
}
ll ny[N];
ll C(ll x,ll y)
{
	return(jc[x]*ny[y]%mo*ny[x-y]%mo);
}
int main()
{
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	jc[0]=1;fo(i,1,N-100) jc[i]=jc[i-1]*i%mo;
	ny[N-100]=qsm(jc[N-100],mo-2);fd(i,N-101,0) ny[i]=ny[i+1]*(i+1)%mo;
	scanf("%d%d%d",&n,&m,&k);
	init(n);
	fo(i,-m-n,k) if(-i>=0)g[i+M]=ny[-i];
	fo(i,0,min(n,k)) if(!bz[i])
		f[i]=ny[k-i]*C(n,i)%mo;
	g0=get(k-m+M+1);f0=get(min(n,k)+1);
	sz=get(g0+f0);fo(i,1,sz) wz[i]=(wz[i>>1]>>1)+((i&1)*(sz>>1));
	dft(f,0),dft(g,0);
	fo(i,0,sz-1) f[i]=f[i]*g[i]%mo;
	dft(f,1);
	fo(i,0,m) printf("%lld\n",(jc[i]*f[k-i+M]%mo*qsm(C(n+i,k),mo-2))%mo);
	return 0;
}











