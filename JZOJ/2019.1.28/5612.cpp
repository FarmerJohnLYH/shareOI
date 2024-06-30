#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=550;
int n,m,a[N][N][N];
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("D:/LiuYuanHao/a.out","w",stdout);
	a[0][1][13]=1;
	int ans=0;
	fo(i,0,11)
	{
		fo(x,0,27) fo(y,0,27)
		{
			a[i+1][x+1][y-1]+=a[i][x][y];
			a[i+1][x+1][y+1]+=a[i][x][y];
			a[i+1][x+2][y]+=a[i][x][y];
		}
		ans+=a[i+1][1+6][13+4];
	}
	printf("%d\n",ans);/*
	fo(i,1,12)
	{
		printf("%d:\n",i);
		fo(x,0,27) 
		{
			fo(y,0,27)
			{
				printf("%d ",a[i][x][y]);
			}
			printf("\n");
		}
		printf("\n");
	}
*/
	return 0;
}








