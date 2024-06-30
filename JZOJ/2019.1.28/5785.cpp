#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int mo=998244353,N=30030;
int n,k;
ll fi(ll x)
{
	ll w;
	for(w=1;w<x;w<<=1);
	return w;
}
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,60)
	{
		if((1ll<<i)>y)return rt;
		if((1ll<<i)&y) rt=(rt*x)%mo;
		x=x*x%mo;
	}
	return rt;
}
struct ve{
	int sz;
	ll a[N*4];
}a,b,c,d;
ll jc[N],ny[N];
ll w[N*4];int wz[N*4];
ll tt[N*4];
void dft(ve &a,int flag)
{
	wz[0]=0;
	fo(i,1,a.sz-1)wz[i]=(wz[i>>1]>>1)+((i&1)*(a.sz>>1));
	fo(i,0,a.sz-1)tt[wz[i]]=a.a[i];
	fo(i,0,a.sz-1)a.a[i]=tt[i];
	w[0]=1,w[1]=qsm(3,(mo-1)/a.sz);
	fo(i,2,a.sz) w[i]=(w[i-1]*w[1])%mo;
	if(flag)fo(i,1,a.sz/2)swap(w[i],w[a.sz-i]);
	ll tp;
	for(int wh=2,hf=1;wh<=a.sz;hf=wh,wh<<=1)
	fo(i,0,hf-1) for(int j=i;j<a.sz;j+=wh)
		tp=w[a.sz/wh*i]*a.a[j+hf]%mo,a.a[j+hf]=(a.a[j]-tp+mo)%mo,a.a[j]=(a.a[j]+tp)%mo;
	if(flag)
	{
		ll nys=qsm(a.sz,mo-2);
		fo(i,0,a.sz-1) a.a[i]=(a.a[i]*nys)%mo;
	}
}
void ntt(ve &a,ve b)
{
	a.sz=b.sz=fi(a.sz+b.sz);
	dft(a,0),
	dft(b,0);
	fo(i,0,a.sz-1) a.a[i]=(b.a[i]*a.a[i])%mo;
	dft(a,1);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	 freopen("or.in","r",stdin);
	 freopen("or.out","w",stdout);
	jc[0]=1;fo(i,1,N-30)jc[i]=(jc[i-1]*i)%mo;
	ny[N-30]=qsm(jc[N-30],mo-2);fd(i,N-31,0)ny[i]=(ny[i+1]*(i+1))%mo;
	scanf("%d%d",&n,&k);
	int size=fi(k+1);
	a.sz=1;a.a[0]=1;
	c.sz=b.sz=size;fo(i,1,k)b.a[i]=ny[i];
	int now=0;
	fo(i,0,18)
	{
		int qw=(1<<i);
		if(qw>n)break;
		fo(j,0,c.sz-1)c.a[j]=(b.a[j]*qsm(2,j*now))%mo;
		if(qw&n)
		{
			ntt(a,c);
			fo(j,k+1,a.sz-1)a.a[j]=0;
			a.sz=size;
			now+=qw;
		}
		fo(j,0,c.sz-1)c.a[j]=(b.a[j]*qsm(2,j*qw))%mo;
		fo(j,k+1,b.sz-1)b.a[j]=0;b.sz=size;
		ntt(b,c);
	}
	ll ans=0;
	fo(i,n,k) 
		ans=(ans+a.a[i]*jc[i]%mo*jc[k]%mo*ny[i]%mo*ny[k-i]%mo)%mo;
	printf("%lld\n",ans);
	return 0;
}











