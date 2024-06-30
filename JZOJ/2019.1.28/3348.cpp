#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=440,M=2002000,eps=1010;
int n,m;
ll a[M];
int to[M],nex[M],las[M],tot;
int hd,tl,d[M],vis[M];
ll ddis[M],dis[M],v[M];
void link(int x,int y,ll c)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot,v[tot]=c;
}
void spfa()
{
	memset(dis,127,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[1]=0;d[1]=1;
	hd=0,tl=1;vis[1]=1;
	while(hd++<tl)
	{
		int x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(tp[to][dis]>dis[x]+tp[v])
		{
			dis[to[tp]]=dis[x]+v[tp];
			if(!vis[to[tp]])vis[d[++tl]=to[tp]]=1;
		}
		vis[x]=0;
	}
}
void sspfa()
{
	memset(ddis,127,sizeof dis);
	memset(vis,0,sizeof vis);
	ddis[n]=0;d[1]=n;
	hd=0,tl=1;vis[n]=1;
	while(hd++<tl)
	{
		int x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(tp[to][ddis]>ddis[x]+tp[v])
		{
			ddis[to[tp]]=ddis[x]+v[tp];
			if(!vis[to[tp]])vis[d[++tl]=to[tp]]=1;
		}
		vis[x]=0;
	}
}
int ctt;
int lnk[M];
struct network{
	int to[M],tot,las[M],nex[M];
	int S,T;
	ll v[M];
	int d[M],g[M];
	ll pa[M];
	void link(int x,int y,ll v1,ll v2)
	{
		to[++tot]=y,nex[tot]=las[x],las[x]=tot,pa[tot]=v[tot]=v1*eps;
		to[++tot]=x,nex[tot]=las[y],las[y]=tot,pa[tot]=v[tot]=v2*eps;
	}
	ll dfs(int x,ll fw)
	{
		if(x==T)return fw;
		ll fwt=0;
		for(int tp=las[x];tp;tp=tp[nex])
		if(tp[v]>0&&d[tp[to]]==d[x]-1)
		{
			ll r=dfs(tp[to],min(fw-fwt,v[tp]));
			v[tp]-=r,v[tp^1]+=r,fwt+=r;
			if(fwt==fw)return fw;
		}
		if(!(--g[d[x]++])) d[S]=n+ctt;
		++g[d[x]];
		return fwt;
	}
	ll solve()
	{
		ll rt=0;
		memset(g,0,sizeof g),memset(d,0,sizeof d);
		g[0]=n+ctt;
		while(d[S]<n+ctt) rt+=dfs(S,oo);
		return rt;
	}
	int bz[M];
	int check()
	{
		memset(bz,0,sizeof bz); 
		int hd=0,tl=1;d[1]=S;bz[S]=1;
		while(hd++<tl)
		{
			int x=d[hd];
			for(int tp=las[x];tp;tp=tp[nex])
			if(tp[v]>0&&!bz[tp[to]])
			{
				bz[tp[to]]=1;
				d[++tl]=tp[to];
			}
		}
		ll cnt=0;
		fo(i,1,tl)
		{
			int x=d[i];
			for(int tp=las[x];tp;tp=tp[nex])
			if(!tp[to][bz]&&pa[tp]>0) 
				++v[tp],++cnt;
		}
		if(solve()<cnt) return 0;
		else return 1;
	}
}nt;
int Q;
int main()
{
//	freopen("D:/LiuYuanHao/b1.in","r",stdin);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&n,&m);
		memset(las,0,sizeof las);
		memset(nt.las,0,sizeof nt.las);
		tot=0;nt.tot=1;
		nt.S=1,nt.T=n;
		a[n]=oo;
		fo(i,1,n-1) scanf("%d",&a[i]);
		fo(i,1,m) 
		{
			int x,y;ll c;
			scanf("%d%d%lld",&x,&y,&c);
			link(x,y,c),link(y,x,c);
		}
		spfa();sspfa();
		ctt=0;
		fo(i,1,n) for(int tp=las[i];tp;tp=tp[nex])
		{
			int j=tp[to],md=(i-1)*n+j+n;
			if(dis[n]==dis[i]+tp[v]+ddis[j]) 
			{
				nt.link(i,md,a[i],0),nt.link(md,j,a[j],0),++ctt;
				lnk[nt.tot]=nt.tot-2,lnk[nt.tot-2]=nt.tot;
				lnk[nt.tot-1]=nt.tot-3,lnk[nt.tot-3]=nt.tot-1;
			}
		}
		ll ans=nt.solve()/eps;
		if(nt.check()) printf("Yes ");
		else printf("No ");
		printf("%lld\n",ans);
	}
	return 0;
}











