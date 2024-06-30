#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=1100*110,M=110,E=N*4*2;
ll n,m;
ll a[N],b[N],c[N],d[N];
ll w(ll x,ll y){return((x-1)*m+y);}
struct network{
	ll n;
	ll to[E],nex[E],cap[E];
	ll las[N];
	ll S,T;
	ll tot;
	void link(ll x,ll y,ll v)
	{
		to[++tot]=y,tot[nex]=las[x],las[x]=tot;cap[tot]=v;
		to[++tot]=x,tot[nex]=las[y],las[y]=tot;cap[tot]=0;
	}
	ll lev[N],mem[N];
	ll dfs(ll x,ll fw)
	{
		if(x==T)return(fw);
		ll cnt=0;
		for (ll tp=mem[x];tp;tp=tp[nex])
		{ 
			mem[x]=tp;
			if(tp[to][lev]==x[lev]+1&&tp[cap]>0)
			{
				ll tt=tp[to];
				ll gt=dfs(tt,min(fw-cnt,tp[cap]));
				cap[tp]-=gt,cap[tp^1]+=gt,cnt+=gt;
				if(cnt==fw)return(cnt);
			}
		} 
		return(cnt);
	}
	ll bfs()
	{
		fo(i,1,n) lev[i]=-1,mem[i]=las[i];
		lev[S]=1;
		queue<ll> q;
		while(!q.empty()) q.pop();
		q.push(S);
		while(!q.empty())
		{
			ll x=q.front();q.pop();
			for (ll tp=las[x];tp;tp=tp[nex])
			if(cap[tp]>0&&lev[tp[to]]<0)
			{
				lev[tp[to]]=lev[x]+1;
				q.push(tp[to]);
			}
		}
		return(!(lev[T]==-1));
	}
	ll solve()
	{
		S=++n,T=++n;
		ll ans=0;
		fo(x,1,n) link(S,x,(a[x]*2+c[x])),link(x,T,(b[x]*2+d[x]));
		while(bfs()) ans+=dfs(S,oo);
		if(ans&1)
		{
			printf("ERR\n");
		}
		return(ans/2);
		
	}
}net;
void link(ll *g,ll x,ll y,ll v)
{
	g[x]+=v,g[y]+=v;
	net.link(x,y,v),net.link(y,x,v);
}
ll cnt;
void init()
{
	net.tot=1;
	scanf("%lld%lld",&n,&m);
	fo(i,1,n) fo(j,1,m)
	{
		ll v;
		scanf("%lld",&v);cnt+=v;
		a[w(i,j)]=v;
	}
	fo(i,1,n) fo(j,1,m)
	{
		ll v;
		scanf("%lld",&v);cnt+=v;
		b[w(i,j)]=v;
	}
	fo(i,1,n-1) fo(j,1,m)
	{
		ll v;
		scanf("%lld",&v);cnt+=v;
		link(c,w(i,j),w(i+1,j),v);
	}
	fo(i,1,n-1) fo(j,1,m)
	{
		ll v;
		scanf("%lld",&v);cnt+=v;
		link(d,w(i,j),w(i+1,j),v);
	}
	fo(i,1,n) fo(j,1,m-1)
	{
		ll v;
		scanf("%lld",&v);cnt+=v;
		link(c,w(i,j),w(i,j+1),v);
	}
	fo(i,1,n) fo(j,1,m-1)
	{
		ll v;
		scanf("%lld",&v);cnt+=v;
		link(d,w(i,j),w(i,j+1),v);
	}
	net.n=w(n,m);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	init();
	printf("%lld\n",cnt-(net.solve()));
	return 0;
}












