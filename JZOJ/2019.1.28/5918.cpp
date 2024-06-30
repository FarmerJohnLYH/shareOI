#pragma GCC optimize(2) 
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define mp make_pair
#define fi first
#define se second
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=200200;
int n,m,q;
int fa[20][N],dep[N];
vector<int> to[N],b[N],g[N];
int f[20][N],ans[N];
vector< pair<int,int> > c[N];
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	fo(i,0,18) if(d&(1<<i)) x=fa[i][x];
	if(x==y)return x;
	fd(i,18,0) if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return (fa[0][x]);
}
int t[N*4],md,lz[N*4];
int vmn(int x,int y)
{
	if(x*y==0)return(x^y);
	return(dep[x]<dep[y])?x:y;
}
void down(int x)
{
	lz[x<<1]=vmn(lz[x<<1],lz[x]),lz[x<<1|1]=vmn(lz[x<<1|1],lz[x]);
	t[x<<1]=vmn(t[x<<1],lz[x]),t[x<<1|1]=vmn(t[x<<1|1],lz[x]);
	lz[x]=0;
}
void add(int x,int l,int r,int ql,int qr,int v)
{
	if(lz[x]) down(x);
	if(ql<=l&&r<=qr)
	{
		t[x]=vmn(t[x],v);
		lz[x]=v;
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) add(x<<1,l,mid,ql,qr,v);
	if(qr>mid) add(x<<1|1,mid+1,r,ql,qr,v);
	t[x]=vmn(t[x<<1],t[x<<1|1]);
}
int qry(int x,int l,int r,int p)
{
	if(lz[x]) down(x);
	if(l==r)
		return(t[x]);
	int mid=(l+r)>>1;
	if(p<=mid) return(qry(x<<1,l,mid,p));
	else return(qry(x<<1|1,mid+1,r,p));
}
int dfn[N],sz[N],cnt;
void cl(int x,int l,int r,int p)
{
	if(lz[x]) down(x);
	if(l==r) 
	{
		t[x]=0;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) cl(x<<1,l,mid,p);
	else cl(x<<1|1,mid+1,r,p);
	t[x]=vmn(t[x<<1],t[x<<1|1]);
}
void dfs(int x)
{
	sz[x]=1;dfn[x]=++cnt;
	for(int p=g[x].size()-1,i=0;i<=p;++i)
		add(1,1,md,dep[g[x][i]],dep[x],g[x][i]);
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	{
		dfs(to[x][i]);
		sz[x]+=to[x][i][sz];
	}	
	f[0][x]=qry(1,1,md,dep[x]);
	cl(1,1,md,dep[x]);
}
int tr[N];
int lowbit(int x)
{
	return(x&(-x));
}
void ad(int x,int v)
{
	for(;x<=n;x+=lowbit(x))
		tr[x]+=v;
}
int query(int x)
{
	int rt=0;
	for(;x;x-=lowbit(x)) rt+=tr[x];
	return rt;
}
int ck[N];
void run(int x)
{
	for(int p=c[x].size()-1,i=0;i<=p;++i)
		ck[c[x][i].se]+=query(c[x][i].fi[dfn]-1)-query(dfn[c[x][i].fi]+c[x][i].fi[sz]-1);
	for(int p=b[x].size()-1,i=0;i<=p;++i)
		ad(dfn[b[x][i]],1);
	for(int p=to[x].size()-1,i=0;i<=p;++i)
		run(to[x][i]);
	for(int p=c[x].size()-1,i=0;i<=p;++i)
		ck[c[x][i].se]-=query(c[x][i].fi[dfn]-1)-query(dfn[c[x][i].fi]+c[x][i].fi[sz]-1);
}
void pre(int &x,int &y,int p,int q)
{
	fd(i,18,0) if(f[i][x][dep]>dep[p]) x=f[i][x],ans[q]+=(1<<i);
	fd(i,18,0) if(f[i][y][dep]>dep[p]) y=f[i][y],ans[q]+=(1<<i);
	if(ans[q]>n||(f[0][x]*f[0][y]==0&&x!=y)) ans[q]=-oo;
}
int bz[N];
int main()
{
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d",&n);
	dep[1]=1;
	fo(i,2,n)
	{
		int x;scanf("%d",&x);
		fa[0][i]=x;to[x].push_back(i);
		dep[i]=dep[x]+1;md=max(md,dep[i]);
	}
	fo(l,1,18) fo(x,1,n) fa[l][x]=fa[l-1][fa[l-1][x]];
	scanf("%d",&m);
	fo(i,1,m)
	{
		int x,y,c;
		scanf("%d%d",&x,&y);
		b[x].push_back(y),b[y].push_back(x);
		c=lca(x,y);
		g[x].push_back(c),g[y].push_back(c);
	}
	dfs(1);
	fo(l,1,18) fo(x,1,n) f[l][x]=f[l-1][f[l-1][x]];
	scanf("%d",&q);
	fo(i,1,q)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int p=lca(x,y);
		if(x==y)ans[i]=-1;
		pre(x,y,p,i);
		if(x==p||y==p)bz[i]=1;
		c[x].push_back(mp(y,i));
	}
	run(1);
	fo(i,1,q)
	{
		if(ans[i]==-oo)printf("-1\n");
		else 
		{
			if(bz[i]) printf("%d\n",ans[i]+1);
			else printf("%d\n",ans[i]+((ck[i]==0)?2:1));
		}
	}
	return 0;
}











