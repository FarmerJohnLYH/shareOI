#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=44;
int n,m,mo;
int a[N][N],bz[N][N];
ll ans=0;
int solve()
{
	int rt=0;
	fo(i,1,n) fo(j,1,m) bz[i][j]=0;
	fo(i,1,n) bz[i][m+1]=1;fo(j,1,m) bz[n+1][j]=1;
	fo(i,1,n)
		fo(j,1,m)
		{
			if(bz[i][j]) continue;
			if(a[i][j]==1) 
			{
				if(!bz[i][j+1])bz[i][j]=2,bz[i][j+1]=1,++rt;
				else
				if(!bz[i+1][j])bz[i][j]=2,bz[i+1][j]=1,++rt;
			}
			if(a[i][j]==2) 
			{
				if(!bz[i+1][j])bz[i][j]=2,bz[i+1][j]=1,++rt;
				else
				if(!bz[i][j+1])bz[i][j]=2,bz[i][j+1]=1,++rt;
			}
		}
	return rt;
}
void dfs(int x,int y)
{
	if(y>m)dfs(x+1,1);
	else if(x>n) ans+=solve();
	else
	{
		a[x][y]=1;
		dfs(x,y+1);
		a[x][y]=2;
		dfs(x,y+1);
	}
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	// scanf("%d%d%d",&n,&m,&mo);
	fo(nn,1,5) fo(mm,1,5)
	{
		n=nn,m=mm;ans=0;
		dfs(1,1);
		printf("mp[%d][%d]=%lld;",n,m,ans);	
	}
	return 0;
}








