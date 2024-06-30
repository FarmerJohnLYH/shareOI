#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100;
int n,m;
int r[N],f[N],fa[20][N],dep[N];
vector<int> to[N];
struct qry{
	int op,x,y;
}a[N];
int q;
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int d=dep[x]-dep[y];
	fo(i,0,18) if(d&(1<<i)) x=fa[i][x];
	if(x==y)return x;
	fd(i,18,0)
	if(fa[i][x]!=fa[i][y]) 
		x=fa[i][x],y=fa[i][y];
	return(fa[0][x]); 
}
int vis[N];
void dfs(int x)
{
	vis[x]=1;
	dep[x]=dep[fa[0][x]]+1;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[0][x])
	{
		fa[0][to[x][i]]=x;
		dfs(to[x][i]);
	}
}
int g[N];
int gg(int x)
{
	return(g[x]==x)?(x):(g[x]=gg(g[x]));
} 
int gf(int x)
{
	if(f[x]==x)return(x);
	else
	{
		f[x]=gf(f[x]);
		r[x]=f[x][r];
		return f[x];
	}
}
int ro[N];
void comb(int x,int y)
{
	int fx=gf(x),fy=gf(y);
	r[fy]=r[fx];f[fy]=f[fx];
}
void work(int x,int f)
{
	comb(f,x);
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=f)
		work(to[x][i],x);
}
int main()
{
//	 freopen("D:/LiuYuanHao/b2.in","r",stdin);
//	 freopen("D:/LiuYuanHao/b.out","w",stdout);
	freopen("arrival.in","r",stdin);
	freopen("arrival.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n) f[i]=i,r[i]=i,g[i]=i;
	fo(i,1,m) scanf("%d",&ro[i]);
	fo(i,1,n-m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(gg(x)!=gg(y)) 
		{
			to[x].push_back(y),to[y].push_back(x);
			g[gg(x)]=gg(y);	
		}
	}
	fo(i,1,m)
	{
		int x=ro[i];
		for(int p=to[x].size()-1,i=0;i<=p;++i)
			work(to[x][i],x);
	}
	scanf("%d",&q);
	fo(i,1,q)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) 
		{
			if(gg(x)!=gg(y)) 
			{
				to[x].push_back(y),to[y].push_back(x);
				g[gg(x)]=gg(y);	
			}
		}
		a[i].op=op,a[i].x=x,a[i].y=y;
	}
	fo(i,1,n) if(!vis[i]) 
		dfs(i);
	fo(i,1,18) fo(x,1,n)
		fa[i][x]=fa[i-1][fa[i-1][x]];
	int cnt=0;
	fo(i,1,q)
	{
		if(a[i].op==1) 
		{
			if(gf(a[i].x)!=gf(a[i].y))comb(a[i].x,a[i].y);	
		}
		else 
		{
			++cnt;
			if(cnt==600)
				printf("");
			if(gf(a[i].x)!=gf(a[i].y))
			{
				printf("orzorz\n");
				continue;
			}
			int x=a[i].x,y=a[i].y,rt=r[gf(x)];
			int ta=lca(x,y),tb=lca(y,rt),tc=lca(x,rt);
			if(dep[ta]<dep[tb]) ta=tb;
			if(dep[ta]<dep[tc]) ta=tc;
			printf("%d\n",ta);
		}
	}
	return 0;
}








