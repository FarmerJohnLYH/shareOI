#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for (int pq = (y),i = (x);i <= pq;++ i)
#define fd(i,x,y) for (int pq = (y),i = (x);i >= pq;-- i)
#define oo 2139062143
using namespace std;
typedef double db;
typedef long long ll;
int lowbit(int x) {return((x)&(-x));}
int min(int x,int y){return (x>y)?(y):(x);}
int max(int x,int y){return (x>y)?(x):(y);}
const int N=55;
int n,d;
int ans;
int fa[N][10],dep[N];
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int dx=x,dy=y,dt=dep[x]-dep[y];
	fo(i,0,8)
	if(dt&(1<<i)) dx=fa[dx][i];
	fd(i,8,0)
	if(fa[dx][i]!=fa[dy][i]) dx=fa[dx][i],dy=fa[dy][i];
	while(dx!=dy) 
		dx=fa[dx][0],dy=fa[dy][0];
	return dx;
}
bool bz[N];
int ff[1000000][N];
void dfs(int pt,int x,int y,int s) 
{
	if(s+(n-pt)<d) return;
	if(pt==n&&s==d)
	{
		int fl=0;
		fo(i,1,ans)
		{
			int flag=0;
			fo(j,1,n)
			{
				if(ff[i][j]!=fa[j][0]) flag=1;
				if(flag) break;
			}
			if(!flag)
			{
				fl=1; 
				break;
			}
		}
		if(!fl)
		{
			++ans;
			fo(j,1,n)
				ff[ans][j]=fa[j][0];
		}
		return;
	}
	if(pt>=n) return;
	fo(l,1,n)
	if(!bz[l])
	{
		fo(i,1,n)
		if(bz[i])
		{
			bz[l]=1;
			fa[l][0]=i;
			dep[l]=dep[i]+1;
			fo(j,1,8) fa[l][j]=fa[fa[l][j-1]][j-1];
			int dx=dep[x]+dep[l]-2*dep[lca(l,x)],dy=dep[y]+dep[l]-2*dep[lca(l,y)];
				 if(dx>=dy&&dx>=s) dfs(pt+1,x,l,dx);
			else if(dx<=dy&&dy>=s) dfs(pt+1,y,l,dy);
			else dfs(pt+1,x,y,s);
			bz[l]=0;
		}
		memset(fa[l],0,sizeof fa[l]);
		dep[l]=0;
	}
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
//	while(scanf("%d%d",&n,&d)!=EOF)
	for(n=2;n<=10;++n)
	{
		for(d=1;d<=n-1;++d)
		{
			memset(fa,0,sizeof fa);
			memset(dep,0,sizeof dep);
			memset(bz,0,sizeof bz);
			bz[1]=1;
			ans=0;
			fo(i,0,8) fa[1][i]=1;
			dep[1]=1;
			dfs(1,1,1,0);
			printf("%d ",ans);
		}
		printf("\n");
	}
	return 0;
}









