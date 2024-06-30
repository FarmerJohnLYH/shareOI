#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> PI;
const int N=100100,M=500500;
int w[N],n,m,Q;
struct edge{int u,v,c;}e[M];
vector<PI> to[N];
int abs(int x){return(x>0)?(x):(-x);}
bool cmp(edge a,edge b){return(a.c<b.c);}
int f[N],bz[M],fa[20][N],g[20][N];
int dep[N];
int gf(int x)
{
	return(f[x]==x)?(x):(f[x]=gf(f[x]));
}
int vis[N];
void dfs(int x)
{
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i].fi!=fa[0][x])
	{
		int tt=to[x][i].fi;
		dep[tt]=dep[x]+1;
		fa[0][tt]=x,g[0][tt]=to[x][i].se;
		dfs(tt);
	}
}
int query(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int d=(dep[x]-dep[y]),rt=0;
	fo(l,0,18)if((1<<l)&d)
		rt=max(rt,g[l][x]),x=fa[l][x];
	if(x==y)return(rt);
	fd(l,18,0)
		if(fa[l][x]!=fa[l][y]) 
		{
			rt=max(rt,max(g[l][x],g[l][y]));
			x=fa[l][x],y=fa[l][y];
		}
	rt=max(rt,max(g[0][x],g[0][y]));
	return(rt);
}
int main()
{
//	freopen("city.in","r",stdin);
//	freopen("city.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	fo(i,1,n) scanf("%d",&w[i]);
	fo(i,1,m)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[i].u=x,e[i].v=y,e[i].c=abs(w[x]-w[y]);
	}
	sort(e+1,e+1+m,cmp);
	fo(i,1,n)f[i]=i;
	fo(i,1,m)
	{
		int fx=gf(e[i].u),fy=gf(e[i].v);
		if(fx!=fy)
		{
			bz[i]=1;
			f[fx]=fy;
			to[e[i].u].push_back(make_pair(e[i].v,e[i].c));
			to[e[i].v].push_back(make_pair(e[i].u,e[i].c));
		}
	}
	dep[1]=1;
	dfs(1);
	fo(i,1,n)f[i]=i;
	fo(i,1,m)if(!bz[i])
	{
		int fx=gf(e[i].u),fy=gf(e[i].v);
		if(fx!=fy)
		{
//			f[fx]=fy;
			int x=e[i].u,y=e[i].v;
			while(x!=y)
			{
				if(dep[x]<dep[y])swap(x,y);
				if(!vis[x])
				{
					g[0][x]=e[i].c;
					f[x]=gf(fa[0][x]);
					vis[x]=1;	
				}
				x=fa[0][x];
			}
		}
	}
	fo(l,1,18) fo(x,1,n) 
		fa[l][x]=fa[l-1][fa[l-1][x]],g[l][x]=max(g[l-1][x],g[l-1][fa[l-1][x]]);
	fo(i,1,Q)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=gf(x),fy=gf(y);
		if(fx!=fy) printf("infinitely\n");
		else printf("%d\n",query(x,y));
	}
	return 0;
}











