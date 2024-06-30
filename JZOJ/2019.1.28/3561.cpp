#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PI;
const ll N=100100;
ll n,m;
ll a[N];
ll tp,ql,qr,val;
ll mo;
ll t[N*4];PI lz[N*4];
void down(ll x,ll l,ll r)
{
	ll mid=(l+r)>>1;
	fo(y,x<<1,x<<1|1)
	{
		ll len=(y&1)?(r-mid):(mid+1-l);
		t[y]=(t[y]*lz[x].se+lz[x].fi*len)%mo;
		lz[y].fi=(lz[y].fi*lz[x].se+lz[x].fi)%mo;
		lz[y].se=(lz[y].se*lz[x].se)%mo;
	}
	lz[x].fi=0,lz[x].se=1;
}
ll query(ll x,ll l,ll r)
{
	if((lz[x].fi||lz[x].se!=1)&&l!=r) down(x,l,r);
	if(ql<=l&&r<=qr) 
		return(t[x]);
	ll mid=(l+r)>>1,rt=0;
	if(ql<=mid) rt=(rt+query(x<<1,l,mid))%mo;
	if(qr>mid) rt=(rt+query(x<<1|1,mid+1,r))%mo;
	return rt;
}
void add(ll x,ll l,ll r)
{
	if((lz[x].fi||lz[x].se!=1)&&l!=r) down(x,l,r);
	if(ql<=l&&r<=qr)
	{
		t[x]=(t[x]+(r-l+1)*val)%mo;
		lz[x].fi=(lz[x].fi+val)%mo;
		return;
	}
	ll mid=(l+r)>>1;
	if(ql<=mid) add(x<<1,l,mid);
	if(qr>mid) add(x<<1|1,mid+1,r);
	t[x]=(t[x<<1]+t[x<<1|1])%mo;
}
void mul(ll x,ll l,ll r)
{
	if((lz[x].fi||lz[x].se!=1)&&l!=r) down(x,l,r); 
	if(ql<=l&&r<=qr)
	{
		t[x]=(1ll*t[x]*val)%mo;
		lz[x].se=lz[x].se*val%mo;
		return;
	}
	ll mid=(l+r)>>1;
	if(ql<=mid) mul(x<<1,l,mid);
	if(qr>mid) mul(x<<1|1,mid+1,r);
	t[x]=(t[x<<1]+t[x<<1|1])%mo;
}
int main()
{
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%lld%lld",&n,&mo);
	fo(i,1,4*n) lz[i].fi=0,lz[i].se=1;
	fo(i,1,n)
	{
		scanf("%lld",&a[i]);
		ql=qr=i;tp=1,val=a[i]%mo;
		add(1,1,n);
	}
	scanf("%lld",&m);
	fo(i,1,m)
	{
		scanf("%lld%lld%lld",&tp,&ql,&qr);
		tp=3-tp;
		if(tp==1) scanf("%lld",&val),add(1,1,n);
		if(tp==2) scanf("%lld",&val),mul(1,1,n);
		if(tp==0) printf("%lld\n",query(1,1,n));
	}
	return 0;
}











