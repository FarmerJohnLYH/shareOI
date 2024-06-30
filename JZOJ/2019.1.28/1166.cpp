#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=10010;
int to[N*2],nex[N*2],las[N],d[N*2];
int n,tot,len;
int dep[N],vis[N];
int root;
void link(int x,int y,int v)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot,d[tot]=v;
}
int ans;
int mxs[N],all;
int qu[N],q0,siz[N];
void findrt(int x,int fa)
{
	mxs[x]=0,siz[x]=1;
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp[to]!=fa&&!tp[to][vis]) 
	{
		findrt(tp[to],x);
		mxs[x]=max(mxs[x],siz[tp[to]]);
		siz[x]+=siz[tp[to]];
	}
	mxs[x]=max(mxs[x],all-siz[x]);
	if(mxs[x]<mxs[root]) root=x;
}
void gtdep(int x,int fa)
{
	qu[++q0]=dep[x];
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp[to]!=fa&&!vis[tp[to]])
	{
		dep[tp[to]]=dep[x]+tp[d];
		gtdep(tp[to],x);
	}
}
int cal(int x,int dp0)
{
	int rt=0;q0=0;
	dep[x]=dp0;
	gtdep(x,0);
	sort(qu+1,qu+1+q0);
	int r=q0;
	fo(l,1,q0)
	{
		while(qu[r]+qu[l]>len) --r;
		if(l>=r)break;
		rt+=(r-l);
	}
	return rt;
}
void solve(int x)
{
	if(vis[x])return;
	vis[x]=1;
	ans+=cal(x,0);
	for(int tp=las[x];tp;tp=tp[nex])
	if(!tp[to][vis])
	{
		ans-=cal(tp[to],d[tp]);
		all=siz[tp[to]];root=0;
		findrt(tp[to],x);
		solve(root);
	}
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&len);
	fo(i,1,n-1)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		link(x,y,c),link(y,x,c);
	}
	all=n;mxs[root=0]=oo;
	findrt(1,0);
	solve(root);
	printf("%d\n",ans);
	return 0;
}











