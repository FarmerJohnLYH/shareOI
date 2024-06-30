#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second
using namespace std;
const int N=200200;
int n;
int dfn[N],sz[N];
vector<int> to[N];
int fa[N];
pair<int,int> a[N];
int tot;
void dfs(int x)
{
	dfn[x]=++tot;
	int szt=to[x].size();
	fo(i,0,szt-1) 
	if(to[x][i]!=fa[x])
	{
		to[x][i][fa]=x;
		dfs(to[x][i]);
		sz[x]+=to[x][i][sz];
	}
	sz[x]++;
}
int check(int x,int y)
{
	return(dfn[y]>=dfn[x]&&dfn[y]<dfn[x]+sz[x]);
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n-1) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		to[x].push_back(y),to[y].push_back(x);
		a[i].fi=x,a[i].se=y;
	}
	dfs(1);
	fo(i,1,n-1)
	if(fa[a[i].se]==a[i].fi) swap(a[i].fi,a[i].se);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y,p;
		scanf("%d%d%d",&x,&y,&p);
		if(((check(a[p].fi,x)+check(a[p].fi,y))&1)==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}











