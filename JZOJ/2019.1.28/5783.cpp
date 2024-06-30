#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=300300;
ll n,q;
ll w[N];
ll nex[N*2],las[N],to[N*2];
ll fa[22][N];
ll dfn[N],tot;
void link(ll x,ll y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
ll cnt;
ll dep[N],sz[N];
void init(ll x,ll f)
{
	dfn[x]=++cnt;fa[0][x]=f;
	dep[x]=dep[f]+1;sz[x]=1;
	for(ll tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=f) init(to[tp],x),sz[x]+=sz[to[tp]];
}
ll root,t[N*4],lz[N*4],tt[N*4];
void down(ll x)
{
	t[x<<1]+=lz[x]*tt[x<<1],lz[x<<1]+=lz[x],
	t[x<<1|1]+=lz[x]*tt[x<<1|1],lz[x<<1|1]+=lz[x];
	lz[x]=0;	
} 
void build(ll x,ll l,ll r)
{
	tt[x]=r-l+1;
	if(l==r)return;
	ll mid=(l+r)>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
}
void add(ll x,ll l,ll r,ll ql,ll qr,ll v)
{
	if(ql>qr)return;
	if(ql<=l&&r<=qr)
	{
		t[x]+=v*tt[x];
		lz[x]+=v;	
		return;
	}
	ll mid=(l+r)>>1;
	if(lz[x])down(x);
	if(ql<=mid)add(x<<1,l,mid,ql,qr,v);
	if(qr>mid)add(x<<1|1,mid+1,r,ql,qr,v);
	t[x]=t[x<<1]+t[x<<1|1];
}
ll query(ll x,ll l,ll r,ll ql,ll qr)
{
	if(ql>qr)return 0;
	if(ql<=l&&r<=qr)
		return(t[x]);
	ll mid=(l+r)>>1,rt=0;
	if(lz[x])down(x);
	if(ql<=mid)rt+=query(x<<1,l,mid,ql,qr);
	if(qr>mid)rt+=query(x<<1|1,mid+1,r,ql,qr);
	return rt;
}
ll ica(ll x,ll y)
{
	if(dep[x]<dep[y])swap(x,y);
	ll d=dep[x]-dep[y];--d;
	if(d>=0)
	{
		fo(i,0,20)if(d&(1<<i)) x=fa[i][x];
		if(fa[0][x]==y)return x;else x=fa[0][x];
	}
	fd(i,20,0)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return(x);
}
ll lca(ll x,ll y)
{
	if(dep[x]<dep[y])swap(x,y);
	ll d=dep[x]-dep[y];
	fo(i,0,20)if(d&(1<<i)) x=fa[i][x];
	if(x==y)return x;
	fd(i,20,0)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return(fa[0][x]);
}
int main()
{
//	freopen("D:/LiuYuanhao/a.in","r",stdin);
//	freopen("a.in","r",stdin);
//	freopen("D:/LiuYuanhao/a.out","w",stdout);
	  freopen("tree.in","r",stdin);
	  freopen("tree.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	fo(i,1,n) scanf("%lld",&w[i]);
	fo(i,1,n-1)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		link(x,y),link(y,x);
	}
	build(1,1,n);
	root=1;
	dep[1]=1;
	init(1,0);
	fo(i,1,n) add(1,1,n,dfn[i],dfn[i],w[i]);
	fo(l,1,20) fo(i,1,n) fa[l][i]=fa[l-1][fa[l-1][i]];
	int ppp=0;
	while(q--)
	{
		ll tp,x,y,v;
		scanf("%lld%lld",&tp,&x);
		if(tp==1) root=x;
		if(tp==2)
		{
			scanf("%lld%lld",&y,&v);
			ll la=lca(x,y),l2=lca(x,root),l3=lca(y,root);
			if(dep[la]<dep[l2])swap(la,l2);
			if(dep[la]<dep[l3])swap(la,l3);
			if(lca(root,la)==la)
			{
				add(1,1,n,1,n,v);
				if(la!=root)
				{
					ll lp=ica(root,la);
					if(lp!=0) add(1,1,n,dfn[lp],dfn[lp]+sz[lp]-1,-v);
				}
			}else 
			add(1,1,n,dfn[la],dfn[la]+sz[la]-1,v);
		}
		if(tp==3)
		{
			ll ans;
			if(lca(root,x)==x)
			{
				ans=query(1,1,n,1,n);
				if(root!=x)
				{ 
					ll lp=ica(root,x); 
					if(lp!=0)ans-=query(1,1,n,dfn[lp],dfn[lp]+sz[lp]-1);
				} 
			}
			else
			ans=query(1,1,n,dfn[x],dfn[x]+sz[x]-1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}











