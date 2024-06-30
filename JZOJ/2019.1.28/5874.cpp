#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=2020,M=10010;
int f[N][N],g[N][N];
int n,v[N],dfn[N],sz[N],dep[N];
int fa[N],cnt;
vector<int> to[N];
void dfs(int x)
{
	dfn[x]=++cnt;
	dep[x]=fa[x][dep]+1,sz[x]=1;
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	{
		to[x][i][fa]=x;
		dfs(to[x][i]);
		sz[x]+=sz[to[x][i]];
	}
}
int ans;
int vca(int x,int y)
{
	if(x==0) return 0;
	x=fa[x],y=fa[y];
	if(x==y) return(v[x]);
	int rt=max(v[x],v[y]);
	while(x!=y)
	{
		if(dep[x]<dep[y])swap(x,y);
		rt=max(rt,v[x=fa[x]]);
	}
	return rt;
}
void solve(int x,int pr,int val)
{
	if(x>n) 
	{
		ans=max(ans,val);
		return;
	}
	if(sz[x]!=1)
		solve(x+1,pr,val);
	int tp=v[x]-vca(pr,x);
	solve(x+sz[x],x,val+tp);
}
int main()
{
	freopen("temmie.in","r",stdin);
	freopen("temmie.out","w",stdout);
	// freopen("D:/LiuYuanHao/c1.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)
	{
		int p,x;
		scanf("%d%d",&v[i],&p);
		fo(j,1,p)
		{
			scanf("%d",&x);
			to[i].push_back(x);
		}
	}
	dfs(1);
	solve(1,0,0);
	printf("%d\n",ans);
	return 0;
}








