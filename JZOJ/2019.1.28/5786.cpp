#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=800800;
int n,q;
int top[N],fg[N],sz[N],tsz[N];
int to[N],son[N],le[N],ri[N];
vector<int> a[N];
void init(int x)
{
	int mx=0;sz[x]=1;
	for(int p=a[x].size(),i=0;i<p;++i)
	{
		init(a[x][i]);
		sz[x]+=sz[a[x][i]];
		if(sz[a[x][i]]>sz[mx])
			mx=a[x][i];
	}
	son[x]=mx;
}
void dfs(int x,int tp)
{
	++tsz[tp];
	top[x]=tp;
	dfs(son[x],tp);
	for(int p=a[x].size()-1,i=0;i<=p;++i)
		dfs(a[x][i],a[x][i]);
}
int bz[N];
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d%d",&n,&q);
	fo(i,2,n)
	{
		int x;
		scanf("%d",&x);
		a[x].push_back(i);
	}
	init(1);
	dfs(1,1);
	fo(i,1,n)
		if(top[x]==x)to[x]=++cnt,
			le[cnt]=ri[cnt-1]+1,ri[cnt]=le[cnt]+tsz[x]-1;
	fo(i,1,n)if(top[x]!=x)to[x]=to[top[x]];
	while(q--)
	{
		int tp,x;
		scanf("%d%d",&tp,&x);
		if(tp==0)
		{
			bz[x]^=1;
			if(bz[x]) di[ to[x].
		}
	}
	return 0;
}











