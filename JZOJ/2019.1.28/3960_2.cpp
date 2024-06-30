#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),GG=(y);i<=GG;++i)
#define fd(i,x,y) for (int i=(x),GG=(y);i>=GG;--i)
using namespace std;
typedef long long ll;
const int N=50500*2*2,M=100100*2*2;
int n,m,fj;
vector<int> t[N];
struct tarj{
	int n,tot;
	int to[M],nex[M],las[M];	
	void link(int x,int y)
	{
		to[++tot]=y,nex[tot]=las[x],las[x]=tot;
		to[++tot]=x,nex[tot]=las[y],las[y]=tot;
	}
	int low[N],dfn[N],cnt;
	int st[N],s0,f[N];
	void dfs(int x,int fa)
	{
		st[++s0]=x;
		low[x]=dfn[x]=++cnt;
		fo(i,0,t[x].size()-1)	
		
		{
			int tt=t[x][i];
			if(dfn[tt]) 
			{
				if(t[x][i]!=fa)low[x]=min(low[x],dfn[tt]);
			}
			else
			{
				dfs(tt,x);
				low[x]=min(low[x],low[tt]);
				if(low[tt]>=dfn[x])
				{
					++n;
					while(st[s0]!=tt)link(st[s0--],n);
					link(st[s0--],n);link(x,n);
				}
			}
		}
	}
	int dis[N],fa[24][N],dep[N];
	void init(int x,int f)
	{
		for(int tp=las[x];tp;tp=tp[nex])
		if(tp[to]!=f)
		{
			int tt=tp[to];
			dis[tt]=dis[x]+((tt>fj)?0:1);
			dep[tt]=dep[x]+1;
			fa[0][tt]=x;
			init(tt,x);
		}
	}
	void pre()
	{
		fo(j,1,22) fo(i,1,n)
			fa[j][i]=fa[j-1][fa[j-1][i]];
	} 
	int lca(int x,int y)
	{
		if(dep[x]<dep[y])swap(x,y);
		int d=dep[x]-dep[y];	
		fo(i,0,22)if(d&(1<<i)) x=fa[i][x];
		if(x==y)return(x);
		fd(i,22,0)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
		return(fa[0][x]);
	}
}tj;
int main()
{
//	 freopen("D:/LiuYuanHao/c1.in","r",stdin);
//	 freopen("D:/LiuYuanHao/c.out","w",stdout);
	scanf("%d%d",&n,&m);
	tj.n=n+m;fj=n;
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		t[x].push_back(i+fj),t[i+fj].push_back(x);
		t[y].push_back(i+fj),t[i+fj].push_back(y);
	}
	tj.dfs(1,0);
	tj.dis[1]=tj.dep[1]=1;
	tj.init(1,0);
	tj.pre();
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);x+=fj,y+=fj;
		int md=tj.lca(x,y);
		printf("%d\n",tj.dis[x]+tj.dis[y]-tj.dis[md]-tj.dis[tj.fa[0][md]]);
	}
	return 0;
}














