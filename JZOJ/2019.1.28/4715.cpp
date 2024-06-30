#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100*2;
int n,st,en;
int to[N],nex[N],las[N],va[N];
int qu[2][N],q0[2];
int tot,rot,mx;
int sz[N],ps[N];
int dis[N],all;
int bz[N],vis[N];
int ans;
void gtsz(int x,int f,int t)
{
	sz[x]=1;ps[x]=0;
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp[to]!=f&&!vis[tp[to]])
	{
		dis[tp[to]]=dis[x]+tp[va];
		if(dis[tp[to]]>=st) ans=min(ans,dis[tp[to]]);
		gtsz(tp[to],x,t);
		sz[x]+=sz[tp[to]];
		ps[x]=max(ps[x],sz[tp[to]]);
	}
	ps[x]=max(ps[x],all-sz[x]);
	qu[t][++q0[t]]=x;
	if(t==0) bz[x]=1;
}
int gtmx(int x,int f)
{
	int rt=x;
	for(int tp=las[x];tp;tp=tp[nex])
		if(tp[to]!=f&&!vis[tp[to]])
		{
			int tmp=gtmx(tp[to],x);
			if(ps[tmp]<ps[rt]) rt=tmp;
		}
	return rt;
}
void link(int x,int y,int v)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
	va[tot]=v;
}
bool cmp(int x,int y)
{
	return(dis[x]<dis[y]);
}
int cnt;
void calc()
{
	++cnt;
	int i=1;
	if(dis[qu[0][q0[0]]]+dis[qu[1][q0[1]]]<st) 
		return;
	fd(j,q0[0],1)
	{
		while((bz[qu[1][i]]||(dis[qu[1][i]]+dis[qu[0][j]]<st))&&i<=n) ++i;
		if(i>n)return;
		if((dis[qu[1][i]]+dis[qu[0][j]]>=st)) 
			ans=min(ans,dis[qu[1][i]]+dis[qu[0][j]]);
	}
}
void solve(int x)
{
	vis[x]=1;
	q0[1]=0;
	for(int tp=las[x];tp;tp=tp[nex])
		if(!vis[tp[to]])
		{
			dis[tp[to]]=tp[va];
			all=sz[tp[to]];
			gtsz(tp[to],0,1);
		}
	sort(qu[1]+1,qu[1]+1+q0[1],cmp);
	for(int tp=las[x];tp;tp=tp[nex])
		if(!vis[tp[to]])
		{
			dis[tp[to]]=tp[va];
			all=sz[tp[to]];
			q0[0]=0;
			gtsz(tp[to],0,0);
			sort(qu[0]+1,qu[0]+1+q0[0],cmp);
			calc();
			fo(i,1,q0[0]) bz[qu[0][i]]=0;
		}
	for(int tp=las[x];tp;tp=tp[nex])
		if(!vis[tp[to]])
		{
			dis[tp[to]]=tp[va];
			all=sz[tp[to]];
			gtsz(tp[to],0,1);
			int rot=gtmx(tp[to],0);
			solve(rot);
		}
}
int main()
{
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
	scanf("%d%d%d",&n,&st,&en);
	all=n;ans=en+1;
	fo(i,1,n-1)
	{
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		link(x,y,v),link(y,x,v);
		if(v>=st)ans=min(ans,v);
	}
	gtsz(1,0,1); 
	rot=gtmx(1,0);
	solve(rot);
	if(ans==en+1) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}











