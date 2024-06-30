#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=200400;
int n,q;
int to[N],nex[N],las[N];
int tot,fa[20][N],dep[N];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
void dfs(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[0][x])
	{
		int tt=to[tp];
		fa[0][tt]=x,dep[tt]=dep[x]+1;
		dfs(tt);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int p=dep[x]-dep[y];
	fo(l,0,18)if((1<<l)&p) x=fa[l][x];
	if(x==y)return(x);
	fd(l,18,0)if(fa[l][x]!=fa[l][y]) x=fa[l][x],y=fa[l][y];
	return(fa[0][x]);
}
int pd(int x,int fx,int y,int fy)
{
	if(dep[fx]<dep[fy])swap(x,y),swap(fx,fy);
	if(lca(x,fy)!=fy)return(0);
	y=lca(y,x);
	if(dep[y]<=dep[x]&&dep[y]>=dep[fx]) return(1);
	else return(0);
}
int main()
{
	freopen("inter.in","r",stdin);
	freopen("inter.out","w",stdout);
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	// freopen("a.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n-1)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		link(u,v),link(v,u);
	}
	dep[1]=1;
	dfs(1);
	fo(i,1,18) fo(x,1,n) fa[i][x]=fa[i-1][fa[i-1][x]];
	scanf("%d",&q);
	while(q--)
	{
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&b,&x,&y);
		int le=lca(a,b),ri=lca(x,y);
		if(pd(a,le,x,ri)||pd(a,le,y,ri)||pd(b,le,x,ri)||pd(b,le,y,ri))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}











