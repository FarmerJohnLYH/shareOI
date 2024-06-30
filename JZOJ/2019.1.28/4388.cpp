#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PI;
const ll N=100100*2;
ll n,m,d[N],f[N];
ll b[N];
ll tot,to[N],nex[N],las[N];
void link(ll x,ll y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
ll sz[N],dfn[N],tson[N],top[N];
ll gt(ll x)
{
	return(top[x]==x)?(x):(top[x]=gt(top[x]));
}
void dfs(ll x)
{
	PI mx=make_pair(0,0);
	sz[x]=1;top[x]=x;
	for(ll tp=las[x];tp;tp=tp[nex])
	{
		dfs(to[tp]);
		sz[x]+=to[tp][sz];
		if(sz[to[tp]]>mx.fi) mx.fi=sz[to[tp]],mx.se=to[tp];
	}
	tson[x]=mx.se;if(mx.fi)top[mx.se]=top[x];
}
ll cnt;
ll vl[N],dis[N];
void work(ll x,ll vll)
{
	dfn[x]=++cnt;vl[cnt]=d[x];
	dis[x]=vll;
	if(tson[x]) work(tson[x],vll+tson[x][d]);
	for(ll tp=las[x];tp;tp=tp[nex])
	if(tp[to]!=tson[x])
		work(to[tp],vll+to[tp][d]);
}
struct seg{
	ll a[N*4],lz[N*4],w[N*4];
	void build(ll x,ll l,ll r)
	{
		if(l==r)
		{
			a[x]=lz[x]=0,w[x]=vl[l];
			return;
		}
		ll mid=(l+r)>>1;
		build(x<<1,l,mid),build(x<<1|1,mid+1,r);
		a[x]=a[x<<1]+a[x<<1|1];
		w[x]=w[x<<1]+w[x<<1|1];
	}
	void add(ll x,ll l,ll r,ll ql,ll qr,ll v)
	{
		if(ql<=l&&r<=qr)
		{
			a[x]+=v*w[x],lz[x]+=v;
			return;
		}
		if(lz[x])down(x);
		ll mid=(l+r)>>1;
		if(ql<=mid) add(x<<1,l,mid,ql,qr,v);
		if(qr>mid) add(x<<1|1,mid+1,r,ql,qr,v);
		a[x]=a[x<<1]+a[x<<1|1];
	}
	void down(ll x)
	{
		lz[x<<1]+=lz[x],lz[x<<1|1]+=lz[x];
		a[x<<1]+=lz[x]*w[x<<1],a[x<<1|1]+=lz[x]*w[x<<1|1];
		lz[x]=0;
	}
	ll query(ll x,ll l,ll r,ll ql,ll qr)
	{
		if(ql<=l&&r<=qr)return(a[x]);
		if(lz[x])down(x);
		ll rt=0;ll mid=(l+r)>>1;
		if(ql<=mid) rt+=query(x<<1,l,mid,ql,qr);
		if(qr>mid) rt+=query(x<<1|1,mid+1,r,ql,qr);
		return rt;
	}
}t;
ll all,ctt;
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	fo(i,2,n) 
	{
		scanf("%lld",&f[i]),++f[i];
		link(f[i],i);
	}
	fo(i,2,n) scanf("%lld",&d[i]);
	dfs(1);work(1,0);
	t.build(1,1,cnt);
	fo(i,1,m)
	{
		ll tp,x;
		scanf("%lld%lld",&tp,&x); ++x;
		if(tp==1&&b[x]) continue;
		if(tp==1)
		{
			all+=(ll)dis[x],++ctt;
			b[x]=1;
			ll la=gt(x);
			while(la!=1)
			{
				t.add(1,1,cnt,dfn[la],dfn[x],1);		
				x=f[la],la=gt(x); 
			}
				t.add(1,1,cnt,dfn[la],dfn[x],1);
		}
		else
		if(tp==2)
		{	
			ll la=gt(x);ll rt=0,ans=all+dis[x]*ctt;
			while(la!=1)
			{
				rt+=t.query(1,1,cnt,dfn[la],dfn[x]);		
				x=f[la],la=gt(x);
			}
				rt+=t.query(1,1,cnt,dfn[la],dfn[x]);
			ans-=2*rt;
			printf("%lld\n",ans);
		}
	}
	return 0;
}











