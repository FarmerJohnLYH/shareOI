#pragma GCC optimize(2) 
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=50500,M=100100*2;
int n,m;
int to[M],las[N],nex[M],tot;
ll ans[N];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
int dfn[N],low[N],bz[N];
ll sz[N],sub[N];
int cnt=0;
void tarjan(int x,int f)
{
	sz[x]=bz[x]=1;
	dfn[x]=low[x]=++cnt;
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp[to]!=f)
	{
		if(bz[tp[to]]) low[x]=min(low[x],low[tp[to]]);
		else
		{
			tarjan(tp[to],x);
			low[x]=min(low[x],low[tp[to]]);
			sz[x]+=sz[tp[to]];
			if (tp[to][low]>=dfn[x])
			{
				ans[x]=ans[x]+(n-sz[tp[to]]-1)*sz[tp[to]];
				sub[x]+=sz[tp[to]];
			}
		}
	}
}
int main()
{
	// freopen("D:/LiuYuanHao/c.in","r",stdin);
	// freopen("D:/LiuYuanHao/c.ans","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	tarjan(1,0);
	fo(i,1,n)
	{
		ans[i]=(ans[i]+(n-sub[i]-1)*sub[i])/2+n-1;
		printf("%lld\n",ans[i]);
	}
	return 0;
}











