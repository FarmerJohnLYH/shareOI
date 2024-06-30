#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=13,mo=1e9+7;
int n,m,k;
int f[N*2][N][2048+10];
int a[N][N];
int hd,tl,ans;
int mi(int x)
{
	return(1<<(x-1));
}
int check(int x,int y)
{
	return(1<=x&&x<=n&&1<=y&&y<=m);
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	int mp=mi(k+1)-1;
	if(n+m>k+1) 
	{
		printf("0\n");
		return 0;
	}
	fo(i,1,n) fo(j,1,m) scanf("%d",&a[i][j]);
	if(a[1][1])f[(1+1)-1][1][mi(a[1][1])]=1;
	else fo(i,1,k) f[1][1][mi(i)]=1;
	fo(i,2,n+m-1)
	{
		fo(x,1,i)
		{
			int y=i+1-x;
			if(check(x,y))
			{
				if(a[x][y]) 
				{
					fo(s,0,mp)if(!(s&mi(a[x][y])))
					{
						if(x-1)f[i][x][s|mi(a[x][y])]=(f[i][x][s|mi(a[x][y])]+f[i-1][x-1][s])%mo;
						if(i-x)f[i][x][s|mi(a[x][y])]=(f[i][x][s|mi(a[x][y])]+f[i-1][x][s])%mo;
					}
				}
				else
				fo(l,1,k)
					fo(s,0,mp)if(!(s&mi(l)))
					{
						if(x-1)f[i][x][s|mi(l)]=(f[i][x][s|mi(l)]+f[i-1][x-1][s])%mo;
						if(i-x)f[i][x][s|mi(l)]=(f[i][x][s|mi(l)]+f[i-1][x][s])%mo;
					}
			}
		}
	}
	fo(s,0,mp) ans=(ans+f[n+m-1][n][s])%mo;
	printf("%d\n",ans);
	return 0;
}











