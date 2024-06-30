#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=550,Q=200200,M=55;
int n,q;
int g[M][M][M];
int f[N][M][M];
const int mo=1e9+7;
void add(int &x,int y)
{
	x=(x+y)%mo;
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&q);
	fo(i,1,q)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g[x][y][z]=1;g[x][z][y]=1;
		g[y][x][z]=1;g[y][z][x]=1;
		g[z][x][y]=1;g[z][y][x]=1;
	}
	int m=49;
	if(n<=2)
	{
		int ans=1;
		fo(i,1,n) ans*=49;
		printf("%d\n",ans);
		return 0;
	}
	fo(j,1,m) fo(l,1,m)
		f[2][j][l]=1;
	fo(i,3,n)
	{
		fo(j,1,m) fo(l,1,m) fo(k,1,m)
		if(!g[k][j][l])
			add(f[i][j][l],f[i-1][k][j]);
	}
	int ans=0;
	fo(j,1,m) fo(l,1,m)
		add(ans,f[n][j][l]);
	printf("%d\n",ans);
	return 0;
}








