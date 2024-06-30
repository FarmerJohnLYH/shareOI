#include <cstdio>
#include <cstring>
#include <iostream>
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define oo 2139062143
using namespace std;
typedef double db;
const int N=11;
db a[N][N],ans=0.000000;
int bz[N][N];
int n,m;
int g[N],f[N];
int solve(int x)
{
	fo(i,1,m)
	{
		if(bz[x][i])
		if(g[i]==0 || !f[g[i]])
		{
			f[g[i]]=1;
			if(!g[i] || (solve(g[i]))) 
			{
				g[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
void dfs(int x,int y,db al)
{
	if(x>n)
	{
		int rt=0;
		memset(g,0,sizeof g);
		fo(i,1,n)
		{
			memset(f,0,sizeof f);
			if(solve(i)) ++rt;
		}
		ans=(ans+(db)rt*al);
		return;
	}
	if(y>m) 
	{
		dfs(x+1,1,al);
		return;
	}
	bz[x][y]=1;
	dfs(x,y+1,al*(a[x][y]));
	bz[x][y]=0;
	dfs(x,y+1,al*(1-a[x][y]));
}
int main()
{
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	 freopen("shilingol.in","r",stdin);
	 freopen("shilingol.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,n)
		fo(j,1,m) scanf("%lf",&a[i][j]);
	dfs(1,1,1);
	printf("%.6lf\n",ans);
	return 0;
}






