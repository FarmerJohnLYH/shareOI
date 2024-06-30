#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (ll pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (ll pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
ll lowbit(ll x) {return((x)&(-x));}
ll min(ll x,ll y){return (x>y)?(y):(x);}
ll max(ll x,ll y){return (x>y)?(x):(y);}
const ll N=100100,V=1000000000100000000;
ll n,q;
struct edge{
	ll fr,to,nex;
	ll v;
}e[N*2];
ll f[N],fa[N];
ll las[N],tot;
ll gf(ll x)
{
	return(f[x]==x?x:f[x]=gf(f[x]));
}
void link(ll x,ll y,ll v)
{
	e[++tot].to=y,e[tot].v=v;
	e[tot].fr=x;
	e[tot].nex=las[x];
	las[x]=tot;
}
ll tp,dfn[N];
ll d[N],dep[N];
void dfs(ll x,ll fatr)
{
	fa[x]=fatr,dfn[x]=++tp;
	dep[x]=dep[fa[x]]+1;
	for (ll tmp=las[x];tmp;tmp=e[tmp].nex)
	if(!(e[tmp].to==fatr))
	{
		ll to=e[tmp].to;
		if(e[tmp].v==1)
		{
			ll fx=gf(x),fy=gf(to);
			f[fy]=fx;
		}
		d[to]=e[tmp].v;
		dfs(to,x);
	}
}
ll a[N],b[N];
int main()
{
	freopen("D:/LiuYuanHao/w.in","r",stdin);
	scanf("%lld%lld",&n,&q);
	fo(i,1,n-1)
	{
		f[i]=i;
		ll x,y,v;
		scanf("%lld%lld%lld",&x,&y,&v);
		link(x,y,v),link(y,x,v);
	}
	f[n]=n;
	dfs(1,0);
	fo(i,1,n)
	if(f[i]!=i)
	{
		e[las[i]].nex=las[f[i]];
		las[f[i]]=las[i];
	}
	while(q--)
	{
		ll typ,x,y,v;
		scanf("%lld%lld%lld",&typ,&x,&y);
		if(typ-1)
		{
			ll v;
			scanf("%lld",&v);
			x=gf(x),y=gf(y);
			ll limit=log(v)/log(2)+1;
			if(dep[x]<dep[y]) swap(x,y);
			a[0]=b[0]=0;
			while(a[0]+b[0]<=limit && dep[x]!=dep[y])
			{
				a[++a[0]]=d[x];
				x=gf(x);
			}
			while(x!=y && a[0]+b[0]<=limit)
			{
				a[++a[0]]=d[x],b[++b[0]]=d[y];
				x=gf(x),y=gf(y);
			}
			if(a[0]+b[0]>limit)	v=0;
			else
			{
				fo(i,1,a[0]) v=v/a[i];
				fo(i,1,b[0]) v=v/b[i];
			}
			printf("%lld\n",v);
		}
		else
		{
			int tmp=x*2;
			if(f[e[tmp].to]!=e[tmp].fr) --tmp;
			d[e[tmp].to]=y;
			if(y==1) 
			{
				ll fx=gf(e[tmp].fr),fy=gf(e[tmp].to);
				f[fy]=fx;	
			}
		}
	}
	return 0;
}
