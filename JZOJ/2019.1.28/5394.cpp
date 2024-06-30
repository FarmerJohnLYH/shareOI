#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N = 100100,K = 300300;
int n,m,k;
struct edge{
	int to,nex;
}e[N * 2];
int las[N];
struct xy{
	int x,y;
	int lca;
}c[K];
int dep[N],fa[N],siz[N];
int hvy[N],p[N];
void dfs(int x,int f)
{
	siz[x] = 1;
	dep[x] = dep[f] + 1,fa[x] = f;
	for (int tmp = las[x];tmp;tmp = e[tmp].nex)
	if (e[tmp].to != f)
	{
		DFS(e[tmp].to,x);
		if(siz[e[tmp].to]>siz[hvy[x]])hvy[x]=e[tmp].to;
	}
	siz[f] += siz[x];
}
int tot;
void link(int x,int y)
{
	e[++ tot].to = y,e[tot].nex = las[x];
	las[x] = tot;
}
int loc[N],total;
int build(int x)
{
	loc[x] = ++ total;
	if (!top[x]) top[x] = x;
	if (!top[hvy[x]]) top[hvy[x]]=top[x],build(hvy[x]);
	for (int tmp = las[x];tmp;tmp = e[tmp].nex)
		if (e[tmp].to != fa[x] && e[tmp].to != hvy[x]) 
			build(e[tmp].to);
}
int lca(int x,int y)
{
	while (top[x] != top[y]) 
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return (dep[x]>dep[y])?(y):(x)
}
bool cmp(xy x,xy y)
{
	return (dep[x.lca]>dep[y.lca]);
}
int main()
{
	freopen("ping.in","r",stdin);
	freopen("ping.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d", &n, &m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d", &x, &y);
		link(x,y),link(y,x);
	}
	dfs(1,0);
	build(1);
	scanf("%d", &k);
	fo(i,1,k) 
	{
		scanf("%d%d", &c[i].x,&c[i].y);
		c[i].lca = lca(c[i].x,c[i].y);
	}
	sort(c+1,c+1+k,cmp);
	fo(i,1,k)
		if (query(c[i].lca,c[i].x) + query(c[i].lca,c[i].y)<=0) 
			change(c[i].lca),ans[++ ans[0]] = c[i].lca; 	
	i
	return 0;
}
