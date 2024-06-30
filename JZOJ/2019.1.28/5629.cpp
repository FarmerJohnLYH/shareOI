#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100,M=2*150150,A=1000100;
int n,m,a[N],a0,v[N],ti[A];
int q;
struct qry{
	int t,x,y,an;
}p[N];int nx[N],la[N];
int tot,nex[M],to[M],las[N];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int bz[M],vis[N],fa[N],pr[N];
void dfs(int x,int f)
{
	vis[x]=1;
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp!=f)
	{
		if(to[tp][vis])
		{
			for(int p=x;p!=to[tp];p=pr[p]) fa[p]=to[tp];
		} 	
		else 
		{
			pr[to[tp]]=x;fa[to[tp]]=x;
			dfs(to[tp],tp^1);
		}
	}
}
int sz[N],gs[N];
void run(int x)
{
	sz[x]=1;
	for(int tp=las[x];tp;tp=tp[nex])
	{
		run(to[tp]),sz[x]+=sz[to[tp]];
		if(to[tp][sz]>gs[x][sz]||gs[x]==0) gs[x]=to[tp];
	}
}
void solve(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
		if(to[tp]!=gs[x]) solve(to[tp]);
	if(gs[x]) solve(gs[x]);
	for(int tp=las[x];tp;tp=tp[nex])
		if(to[tp]!=gs[x]) go(to[tp],1);
	for(int tp=la[x];tp;tp=tp[nx]) p[tp].an=que(p[tp].y,p[tp].t);
	if(gs[fa[x]]!=) go(to[tp],-1);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n) scanf("%d",&v[i]),a[i]=v[i];
	tot=1;
	sort(a+1,a+1+n);
	a[0]=-1;
	fo(i,1,n) if(a[i]!=a[i-1]) a[++a0]=a[i],ti[a[i]]=a0;
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	dfs(1,0);
	tot=0;memset(las,0,sizeof las); 
	fo(i,2,n) link(fa[i],i);
	scanf("%d",&q);
	fo(i,1,q)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		p[i].t=t,p[i].x=x,p[i].y=y;
		nx[i]=la[x],la[x]=i;
	}
	run(1);
	solve(1);
	fo(i,1,q) printf("%d\n",p[i].an);
	return 0;
}








