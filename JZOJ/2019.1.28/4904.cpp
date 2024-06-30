#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef pair<int,int> PI;
const int N=300030;
int n,m;
int w[N],a[N*3],b[N*3];
int s[N],t[N],la[N];
int ans[N];
int nex[N*2],to[N*2],las[N];
int tot,fa[22][N];
struct node{int x,y,v;};
vector<node> bz[N*2];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int dep[N];
void dfs(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[0][x])
	{
		dep[to[tp]]=dep[x]+1;
		fa[0][to[tp]]=x;
		dfs(to[tp]);
	}
}
int lca(int x,int y,int &v)
{
	if(x==y)
	{
		v=0;
		return x;
	}
	int bz=0;
	if(dep[x]<dep[y])swap(x,y),bz=1;
	int d=dep[x]-dep[y];
	if(d)
	{
		--d; 
		fo(i,0,20)if(d&(1<<i))
			x=fa[i][x];
		if(fa[0][x]==y) 
		{
			if(bz)v=x;
			return y;
		}x=fa[0][x];
	}
	fd(i,20,0) if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	if(bz)v=x;else v=y;
	return(fa[0][x]);
}
void solve(int x)
{
	int val=a[dep[x]+w[x]]+b[dep[x]-w[x]+N];
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp[to]!=fa[0][x])
		solve(to[tp]);
	for(int p=bz[x].size()-1,i=0;i<=p;++i)
	if(bz[x][i].x==1) a[bz[x][i].y]+=bz[x][i].v;
	else if(bz[x][i].x==2) b[bz[x][i].y+N]+=bz[x][i].v;
	ans[x]=a[dep[x]+w[x]]+b[dep[x]-w[x]+N]-val;
	for(int p=bz[x].size()-1,i=0;i<=p;++i)
	if(bz[x][i].x==3) a[bz[x][i].y]+=bz[x][i].v;
	else if(bz[x][i].x==4) b[bz[x][i].y+N]+=bz[x][i].v;
}
int main()
{
	freopen("running.in","r",stdin);
	freopen("running.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	fo(i,1,n) scanf("%d",&w[i]);
	dep[1]=1;
	dfs(1);
	fo(l,1,20) fo(x,1,n) fa[l][x]=fa[l-1][fa[l-1][x]];
	fo(i,1,m)
	{
		scanf("%d%d",&s[i],&t[i]);
		int py=0;
		la[i]=lca(s[i],t[i],py);
		bz[s[i]].push_back((node){1,dep[s[i]],1});
		bz[la[i]].push_back((node){3,dep[s[i]],-1});
		if(la[i]!=t[i])
		{
			bz[t[i]].push_back((node){2,2ll*dep[la[i]]-dep[s[i]],1});
			if(py)bz[py].push_back((node){4,2ll*dep[la[i]]-dep[s[i]],-1});
		}
	}
	int p=bz[0].size();
	solve(1);
	fo(i,1,n) 
		printf("%d ",ans[i]);
	return 0;
}






















