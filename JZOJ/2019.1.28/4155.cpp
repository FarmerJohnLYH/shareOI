#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fi first
#define se second
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef int ll;
typedef pair<ll,ll> PI;
const ll N=65536*2+10,M=22,mo=998244353;
ll n,l;
PI a[N];
ll b0;
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if(y&(1<<i)) rt=1ll*rt*x%mo;
		x=1ll*x*x%mo;
	}
	return rt;
}
ll tp[N];
	ll w[N],wz[N];
	ll c[N];
struct ffst{
	ll cs,a[N],rcs;
	void dft(ll flag)
	{
		rcs=qsm(cs,mo-2);
		wz[0]=0;fo(i,1,cs-1) wz[i]=(wz[i>>1]>>1)+((i&1)*(cs>>1));
		w[0]=1,w[1]=qsm(3,(mo-1)/cs);
		fo(i,2,cs) w[i]=1ll*w[i-1]*w[1]%mo;
		fo(i,0,cs-1) c[wz[i]]=a[i];
		ll tmp;
		for (ll wv=2,hf=1;wv<=cs;hf=wv,wv<<=1)
		fo(i,0,hf-1) for(ll j=i;j<cs;j+=wv) 
		{
			tmp=1ll*((flag==1)?(w[cs/wv*i]):(w[cs-(cs/wv*i)]))*c[j+hf]%mo,
//			printf("%d\n",tmp);
			c[j+hf]=(c[j]+mo-tmp)%mo,c[j]=(c[j]+tmp)%mo;
//			tmp=1ll*w[cs*i/wv]*c[j+i+hf]%mo,
//			c[j+i+hf]=(c[j+i]+mo-tmp)%mo,c[j+i]=(c[j+i]+tmp)%mo;
//			printf("");
		}
		fo(i,0,cs-1)
		{
			a[i]=c[i];
			if(flag==-1) a[i]=1ll*a[i]*rcs%mo;
		}
	}
	void fft(ffst &g,ll v)
	{
		dft(1);
		fo(i,0,cs-1) tp[i]=qsm(g.a[i],v),a[i]=1ll*a[i]*tp[i]%mo;
		dft(-1);
	}
}g,f;
bool cmp(PI a,PI b)
{
	return(a.fi<b.fi||(a.se<b.se&&a.fi==b.fi));
}
int m;
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&n,&l,&m);
	fo(i,1,m) scanf("%d%d",&a[i].fi,&a[i].se);
	a[++m].fi=l,a[m].se=n+1;
	sort(a+1,a+1+m,cmp);
	scanf("%d",&b0);
	fo(i,1,b0)
	{
		ll x;
		scanf("%d",&x),++g.a[x];	
	} 
	g.cs=n;
	g.dft(1);
	f.cs=n;f.a[0]=1;
	ll las=0;
	fo(i,1,m)
	{
		f.fft(g,a[i].fi-las);//f*=g^{c}
		las=a[i].fi;
		f.a[a[i].se]=0;
	}
	printf("%d\n",f.a[0]);
	return 0;
}











