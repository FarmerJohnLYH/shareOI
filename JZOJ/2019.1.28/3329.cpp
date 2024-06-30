#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=5050;
int n,m;
int a[N*N],dis[N],dep[N],a0;
int fa[16][N];
int to[N*2],nex[N*2],las[N],v[N*2];
int tot;
int du[N];
void link(int x,int y,int c)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot,v[tot]=c;
	++du[x];
}
void dfs(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp[to]!=fa[0][x])
	{
		fa[0][tp[to]]=x;
		dep[tp[to]]=dep[x]+1;
		dis[tp[to]]=dis[x]+v[tp];
		dfs(tp[to]);
	}
}
int g[N*N],g0;
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	fo(i,0,14)if(d&(1<<i)) x=fa[i][x];
	if(x==y)return(x);
	fd(i,14,0)if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return(fa[0][x]);
}
int main()
{
	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n-1)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		link(x,y,c),link(y,x,c);	
	}
	dep[1]=1,dis[1]=0;
	dfs(1);
	fo(i,1,14) fo(j,1,n) fa[i][j]=fa[i-1][fa[i-1][j]];
	if(n<=N-20)
	{
		fo(i,1,n) fo(j,i+1,n)
		{
			int d=dis[i]+dis[j]-2*dis[lca(i,j)];
			a[++a0]=d;
		}
	}
	else
	{
		fo(i,1,n)
		if(du[i]==1) g[++g0]=i;
		fo(ii,1,g0) fo(jj,ii+1,g0)
		{
			int i=g[ii],j=g[jj];
			int d=dis[i]+dis[j]-2*dis[lca(i,j)];
			a[++a0]=d;
		}
	}
	sort(a+1,a+1+a0);
	fd(i,a0,a0-m+1) printf("%d\n",a[i]);
	return 0;
}











