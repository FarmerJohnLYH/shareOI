#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=1001000;
int dn[N],tp[N],g[N],sz[N];
int n,m;
int fa[N];
int ls[N*2],t[N*2],nx[N*2],tot;
void link(int x,int y)
{
	(++tot)[t]=y,nx[tot]=x[ls];
	ls[x]=tot;
}
void dfs1(int x,int f)
{
	fa[x]=fa[f];
	int mx=0,mt=0;
	for(int i=ls[x];i;i=nx[i])
	if(i[t]!=f)
	{
		int to=t[i];
		dfs1(to,x);
		sz[x]+=sz[to];
		if(sz[to]>mx)mx=sz[to],mt=to;
	}
	++sz[x];
	if(!mt) g[x]=mt;
}
int tl;
void dfs2(int x)
{
	dfn[x]=++tl;
	if(g[x])dfs2(g[x]),tp[g[x]]=tp[x];
	for (int i=ls[x];i;i=nx[i])
	if(i[t]!=fa[i]&&t[i]!=g[i])
	{
		dfs2(t[i]);
		tp[t[i]]=t[i];
	}
}
void col(int f,int x)
{
	
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
 	scanf("%d%d",&n,&m);
 	fo(i,1,n-1)
 	{
 		int x,y;
 		scanf("%d%d",&x,&y);
 		link(x,y),link(y,x);	
 	}
 	dfs1(1,0);
 	tp[1]=1;dfs2(1);
 	fo(i,1,q)
 	{
 		int ty,x,y;
 		scanf("%d",&ty);
 		if(ty==1)
 		{
 			scanf("%d%d",&x,&y);
 			int la=lca(x,y);
 			col(la,x),col(la,y);
 		}
 		if(ty==2)
 		{
 			scanf("%d",&x);
 			gt(x);
 		}
 	}
	return 0;
}




