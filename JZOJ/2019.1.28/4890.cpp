#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=100100;
int n;
ll du[N];
ll qsm(ll x,int y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1ll<<i)&y) rt=1ll*rt*x;
		x=1ll*x*x;
	}
	return rt;
}
vector<int> to[N];
ll f[N],g[N];
ll F[20][N],G[20][N];
int dep[N],fa[20][N];
void dfs(int x)
{
	f[x]=du[x];
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[0][x])
	{
		fa[0][to[x][i]]=x,dep[to[x][i]]=x[dep]+1;
		dfs(to[x][i]);
		f[x]=(f[x]+to[x][i][f]);
	}
}
void work(int x)
{
	ll cnt=0;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[0][x])
		cnt=(cnt+f[to[x][i]]);
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[0][x])
	{
		g[to[x][i]]=(du[x]+g[x]+cnt-to[x][i][f]);
		work(to[x][i]);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int d=(dep[x]-dep[y]);
	fd(i,18,0)if((1<<i)&d) 
		x=fa[i][x];
	if(x==y)return(x);
	fd(i,18,0)if(fa[i][x]!=fa[i][y])
		x=fa[i][x],y=fa[i][y];
	return(fa[0][x]);
}
ll ans;
ll mxf[N],mxg[N];
void solve(int x)
{
	ll f1=0,ff1=0,f2=0,ff2=0,g1=0,fg1=0,g2=0,fg2=0;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[0][x])
	{
		int tt=to[x][i];
		solve(tt);
		if(mxf[tt]>f1) f2=f1,ff2=ff1,f1=mxf[tt],ff1=tt;
		else if(mxf[tt]>f2) f2=mxf[tt],ff2=tt;
		if(mxg[tt]>g1) g2=g1,fg2=fg1,g1=mxg[tt],fg1=tt;
		else if(mxg[tt]>g2) g2=mxg[tt],fg2=tt;
	}
	mxf[x]=f1+f[x],mxg[x]=g1+g[x];
	if(fg1!=ff1) ans=max(ans,f1+g1);
	else ans=max(ans,max(f2+g1,f1+g2));
}
int main()
{
//	 freopen("rw.in","r",stdin);
//	 freopen("rw.out","w",stdout);
	freopen("D:/LiuYuanHao/a1.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y); 
		to[x].push_back(y),to[y].push_back(x);
		++du[x],++du[y];
	}
	dep[1]=1;
	dfs(1);
	work(1);
	fo(i,1,n) F[0][i]=f[i],G[0][i]=g[i];
	fo(l,1,18) fo(i,1,n)
		F[l][i]=(F[l-1][i]+F[l-1][fa[l-1][i]]),
		G[l][i]=(G[l-1][i]+G[l-1][fa[l-1][i]]),
		fa[l][i]=fa[l-1][fa[l-1][i]];
	solve(1);
	printf("%lld.00000\n",ans);
	return 0;
}











