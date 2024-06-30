#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=1001000*2;
ll read()
{
	char ch=getchar();
	ll rt=0,tp=1;
	while(!((ch>='0'&&ch<='9')||ch=='-')) ch=getchar();
	if(ch=='-') ch=getchar(),tp=-1;
	while((ch>='0'&&ch<='9')) rt=rt*10+ch-'0',ch=getchar();
	return rt*tp;
}
ll n,m,qq;
struct node{
	ll t,x,w;ll tp,id,v/*0insert 1query*/;
}q[N*2];ll cnt;
ll to[N],fa[N],las[N],nex[N],dfn[N];
ll a[N],tot,sz[N],dep[N];
ll ans[N];
void link(ll x,ll y)
{
	to[++tot]=y,tot[nex]=las[x],las[x]=tot;
}
void dfs(ll x)
{
	dfn[x]=++tot;
	for (ll tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x])
	{
		dep[to[tp]]=dep[x]+1;fa[to[tp]]=x;
		dfs(to[tp]);
		sz[x]+=sz[to[tp]];
	}
	++sz[x];
}
bool cmp(node a,node b)
{
	return(a.t<b.t||(a.t==b.t&&a.tp>b.tp));
}
bool cmp1(node a,node b)
{
	return((a.tp^1)+a.t+dep[a.x]>(b.tp^1)+b.t+dep[b.x])||((a.tp^1)+a.t+dep[a.x]==(b.tp^1)+b.t+dep[b.x]&&a.tp<b.tp);
}
ll tr[N*4];/*
void build(ll x,ll l,ll r)
{
	tr[x]=0;
	if(l>=r) return; 
	ll mid=(l+r)>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
}*/
void insert(ll x,ll l,ll r,ll p,ll v)
{
	if(l==r)
	{
		tr[x]+=v;
		return;
	}
	ll mid=(l+r)>>1;
	if(p<=mid) insert(x<<1,l,mid,p,v);
	else insert(x<<1|1,mid+1,r,p,v);
	tr[x]=tr[x<<1]+tr[x<<1|1];
}
ll query(ll x,ll l,ll r,ll ql,ll qr)
{
	if(l>=ql&&r<=qr)return(tr[x]);
	ll mid=(l+r)>>1,rt=0;
	if(ql<=mid) rt+=query(x<<1,l,mid,ql,qr);
	if(qr>mid) rt+=query(x<<1|1,mid+1,r,ql,qr);
	return rt;
}
node nw[N];
void cdq(ll l,ll r)
{
	if(l>=r)return;
	ll mid=(l+r)>>1;
	//clear
	ll n0=0;
	fo(i,mid+1,r)
	if(q[i].tp==1)
		nw[++n0]=q[i];
	if(n0)
	{
		fo(i,l,mid)
		if(q[i].tp==0)
		{
			if(q[i].t>=nw[1].t)break;
			nw[++n0]=q[i];
		}
		sort(nw+1,nw+1+n0,cmp1);
//		build(1,1,n);//clear
		fo(i,1,n0)
		{
			if(nw[i].tp==0) 
				insert(1,1,n,dfn[nw[i].x],nw[i].w);
			if(nw[i].tp==1)
				ans[nw[i].id]+=query(1,1,n,dfn[nw[i].x],dfn[nw[i].x]+sz[nw[i].x]-1);
		}
		fo(i,1,n0)
		{
			if(nw[i].tp==0) 
				insert(1,1,n,dfn[nw[i].x],-nw[i].w);
		}
	}
	cdq(l,mid),
	cdq(mid+1,r);
}
int main()
{
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	// freopen("appletree.in","r",stdin);
	 freopen("D:/LiuYuanHao/appletree.out","w",stdout);
	n=read(),m=read(),qq=read();
	fo(i,1,n) a[i]=read();
	fo(i,1,n-1)
	{
		ll x=read(),y=read();
		link(x,y),link(y,x);
	}
tot=0;
//return 0;
	dfs(1);
	fo(i,1,n)
		q[++cnt].t=0,q[cnt].tp=0,q[cnt].x=i,q[cnt].w=a[i],q[cnt].v=1;	
	fo(i,1,m)
	{
		ll t=read(),x=read(),w=read();
		q[++cnt].tp=0,q[cnt].t=t,q[cnt].x=x,q[cnt].w=w;
	}
	fo(i,1,qq)
	{
		ll t=read(),x=read();
		q[++cnt].tp=1;q[cnt].t=t,q[cnt].x=x;
		q[cnt].id=i;
	}
	sort(q+1,q+1+cnt,cmp);
	//clear(a)
	cdq(1,cnt);
	fo(i,1,qq)
		printf("%lld\n",ans[i]);
	return 0;
}
