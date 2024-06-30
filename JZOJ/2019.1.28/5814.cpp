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
const ll mo=1e9+7;
int n,Q;
ll du[N];
ll qsm(ll x,int y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1ll<<i)&y) rt=1ll*rt*x%mo;
		x=1ll*x*x%mo;
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
		f[x]=(f[x]+to[x][i][f])%mo;
	}
}
void work(int x)
{
	ll cnt=0;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[0][x])
		cnt=(cnt+f[to[x][i]])%mo;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[0][x])
	{
		g[to[x][i]]=(du[x]+g[x]+cnt+mo-to[x][i][f])%mo;
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
int main()
{
	 freopen("tree.in","r",stdin);
	 freopen("tree.out","w",stdout);
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&Q);
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
		F[l][i]=(F[l-1][i]+F[l-1][fa[l-1][i]])%mo,
		G[l][i]=(G[l-1][i]+G[l-1][fa[l-1][i]])%mo,
		fa[l][i]=fa[l-1][fa[l-1][i]];
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int l=lca(x,y);ll ans=0;
		fd(i,18,0) if(dep[fa[i][x]]>=dep[l])
			ans=(ans+F[i][x])%mo,x=fa[i][x];
		fd(i,18,0) if(dep[fa[i][y]]>=dep[l])
			ans=(ans+G[i][y])%mo,y=fa[i][y];
		printf("%lld\n",ans);
	}
	return 0;
}











