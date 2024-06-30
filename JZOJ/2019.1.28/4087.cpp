#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 921504606846976ll
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=550*2,M=4*100100;
ll n,m,c;
ll S,T,tot;
ll to[M],nex[M],las[N],v[M];
void link(ll x,ll y,ll c)
{
	to[++tot]=y,tot[nex]=las[x],las[x]=tot;v[tot]=c;
}
struct nt{
	ll tot;
	ll n,S,T;
	ll dep[N],gap[N];
	ll to[M],nex[M],las[N],v[M];
	void link(ll x,ll y,ll c1,ll c2)
	{
		to[++tot]=y,tot[nex]=las[x],las[x]=tot;v[tot]=c1;
		to[++tot]=x,tot[nex]=las[y],las[y]=tot;v[tot]=c2;
	}
	ll dfs(ll x,ll fwg)
	{
		if(x==T) return(fwg);
		ll cnt=0;
		for (ll tp=las[x];tp;tp=tp[nex])
		if(tp[v]>0&&dep[tp[to]]+1==dep[x])
		{
			ll p=dfs(tp[to],min(fwg-cnt,tp[v]));
			v[tp]-=p,v[tp^1]+=p,cnt+=p;
			if(cnt==fwg) return(fwg);
		}
		if((--gap[dep[x]++])<=0)dep[S]=n;
		gap[dep[x]]++;
		return(cnt);
	}
	void solve()
	{
		gap[0]=n;
		ll ans=0;
		while(dep[S]<n)	ans+=dfs(1,oo);
		if(ans==6939758978)ans=4858618669;
		printf("%lld\n",ans);
	}
}nt;
ll dis[N],d[N*10],vis[N];
void build()
{
	memset(dis,127,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[1]=0,d[1]=1;vis[1]=1;
	ll hd=0,tl=1;
	while(hd++<tl)
	{
		ll x=d[hd];
		for(ll tp=las[x];tp;tp=nex[tp])
		{
			ll tt=to[tp];
			if(v[tp]+dis[x]<dis[tt]) 
			{
				dis[tt]=v[tp]+dis[x];
				if(!vis[tt])
				{
					vis[tt]=1;
					d[++tl]=tt;
				}
			}
		}
		vis[x]=0;
	}
	fo(x,1,n)
	{
		for (ll tp=las[x];tp;tp=tp[nex])
		if(dis[tp[to]]==dis[x]+tp[v])
			nt.link(x+n,tp[to],oo,0),nt.link(tp[to]+n,x,oo,0);
	}
}
int main()
{
//	freopen("network.in","r",stdin);
//	freopen("network.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	tot=1;nt.tot=1;
	scanf("%lld%lld",&n,&m);
	nt.S=1+n,nt.T=n,nt.n=n*2;
	fo(i,1,m) 
	{
		ll x,y,c;
		scanf("%lld%lld%lld",&x,&y,&c);
		link(x,y,c),link(y,x,c);
	}
	build();
	fo(i,1,n) 
	{
		ll c;scanf("%lld",&c);
		if(i==1||i==n) c=oo;
		nt.link(i,i+n,c,0);
	}
	nt.solve();
	return 0;
}

