#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (ll i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<ll,ll> PI;
ll abs(ll x) {return(((x)>=0)?(x):(-(x)));}
ll max(ll x,ll y) {return(((x)>(y))?(x):(y));}
ll min(ll x,ll y) {return(((x)<(y))?(x):(y));}
ll lowbit(ll x) {return((x)&(-x));}
const ll N=4*100100,mo=10007;
ll n,C;
ll a[N],b[N],q;
struct node{
	ll f[22];
}t[N];
void comb(ll a,ll b,ll c)
{
//	memset(t[a].f,0,sizeof t[a].f);
	fo(i,0,C) t[a].f[i]=0;
	fo(i,0,C)
	{
		fo(j,0,C)
		{
			if(i+j>C)break;
			ll l=i+j;
			t[a].f[l]=(t[b].f[i]*t[c].f[j]+t[a].f[l])%mo;
		}
	}
}
ll qsm(ll a,ll b)
{
	ll x=1;
	a%=mo,b%=(mo-1);
	while(b)
	{
		x=((b&1))?((x*(a))%mo):(x);
		b>>=1,a=(a*a)%mo;
	}
	return x;
}
void change(ll x,ll l,ll r,ll p,ll va,ll vb)
{
	if(l==r)
	{
		t[x].f[0]=vb,t[x].f[1]=va;
		return;
	}
	ll mid=(l+r)>>1;
	if(p<=mid) change(x<<1,l,mid,p,va,vb);
	else change(x<<1|1,mid+1,r,p,va,vb);
	comb(x,x<<1,x<<1|1);
}
int main()
{
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	scanf("%lld%d",&n,&C);
	fo(i,1,n) scanf("%lld",&a[i]),a[i]%=mo;
	fo(i,1,n) scanf("%lld",&b[i]),b[i]%=mo;
	ll all=1;
	fo(i,1,n) 
	{
		all=(all*(a[i]+b[i])%mo);
		change(1,1,n,i,a[i],b[i]);
	}
	scanf("%lld",&q);
	fo(i,1,q)
	{
		ll tp,x,y; 
		scanf("%lld%lld%lld",&tp,&x,&y);
		x%=mo,y%=mo;
		//a[t]=x%mo,b[t]=y%mo;
		all=all*(x+y)%mo*qsm(a[tp]+b[tp],mo-2)%mo;
		a[tp]=x,b[tp]=y;
		change(1,1,n,tp,a[tp],b[tp]);
		ll ans=0;
		fo(i,0,C-1) ans=(ans+t[1].f[i])%mo;
		ans=(mo+all-ans)%mo;
		printf("%lld\n",ans);
	}
	return 0;
}











