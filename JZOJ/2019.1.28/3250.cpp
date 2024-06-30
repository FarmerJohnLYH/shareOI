#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=600600;
int n;
int to[N*2],nex[N*2],las[N],fa[N],tot;
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
void dfs(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=fa[x])
	{
		fa[to[tp]]=x;
		to[tp][dep]=dep[x]+1;
		dfs(to[tp]);
	}
}
int p[N];
int main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	// freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y),link(x,y),link(y,x);	
	} 
	fo(i,1,n) 
	{
		int x;
		scanf("%d",&x),p[x]=i;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}

