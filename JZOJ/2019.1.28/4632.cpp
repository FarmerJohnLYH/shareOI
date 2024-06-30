#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=20020,C=66;//2^15>N
int n,Q;
vector<int> to[N];
ll pw[C];
struct node{
	ll a[C];
	void add(ll v)
	{
		fd(i,60,0)
		if(v&pw[i])
		{
			if(!a[i]) 
			{
				a[i]=v;
				return;
			}
			else v^=a[i];
		}
	}
}f[18][N],q;
void merge(node &c,node &a,node &b)
{
	fo(i,0,60)q.a[i]=a.a[i];
	fo(i,0,60)if(b.a[i]) q.add(b.a[i]);
	fo(i,0,60)c.a[i]=q.a[i];
}
ll g[N];
int fa[18][N],dep[N];
void dfs(int x)
{
	for(int p=to[x].size()-1,i=0;i<=p;++i)
	if(to[x][i]!=fa[0][x])
	{
		int tt=to[x][i];
		dep[tt]=dep[x]+1;
		fa[0][tt]=x;f[0][tt].add(g[tt]);
		dfs(tt);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int d=dep[x]-dep[y];
	fo(i,0,16) if(d&pw[i])
		x=fa[i][x];
	if(x==y)return(x);
	fd(i,16,0)if(fa[i][x]!=fa[i][y]) 
		x=fa[i][x],y=fa[i][y];
	return(fa[0][x]);
}
node gt(int x,int len)
{
	fo(i,0,60) q.a[i]=0;
	fo(i,0,16) if(len&pw[i])
		merge(q,q,f[i][x]),x=fa[i][x];
	return q;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	pw[0]=1;
	fo(i,1,60)pw[i]=pw[i-1]<<1;
	scanf("%d%d",&n,&Q);
	fo(i,1,n)scanf("%lld",&g[i]);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		to[x].push_back(y),to[y].push_back(x);
	}
	dep[1]=1;
	dfs(1);
	fo(l,1,16) fo(i,1,n) 
		fa[l][i]=fa[l-1][fa[l-1][i]],
		merge(f[l][i],f[l-1][i],f[l-1][fa[l-1][i]]);
	node ans;
	fo(i,1,Q)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int k=lca(x,y);
		node a=gt(x,dep[x]-dep[k]),b=gt(y,dep[y]-dep[k]);
		merge(ans,a,b);
		ans.add(g[k]);
		ll rt=0;
		fd(l,60,0)
		if((rt^ans.a[l])>rt) rt^=ans.a[l];
		printf("%lld\n",rt);
	}
	return 0;
}











