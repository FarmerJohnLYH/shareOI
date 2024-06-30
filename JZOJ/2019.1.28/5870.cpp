#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo;
using namespace std;
const int N=2020,mo=998244353;
int c[2];
int n,f[N][N];
int C(int x)
{
	return((1ll*x*(x-1)/2)%mo);
}
int main()
{
	freopen("map.in","r",stdin);
	freopen("map.out","w",stdout);
	// freopen("D:/LiuYuanHao/b1.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)
	{
		int v;
		scanf("%d",&v);
		++c[v-1];
	}
	f[0][0]=1;
	fo(sm,0,n)fd(x,sm,0)
   	{
   		int y=sm-x;
		if(y==0&&x>=1) add(f[x+1][y],1ll*f[x-1][y]*x%mo);
		if(x>=2) add(f[x][y+1],1ll*f[x-2][y]*C(x)%mo);
		if(y>=2) add(f[x][y+1],1ll*f[x+2][y-2]*C(y)%mo);
		if(sm*x) add(f[x][y+1],1ll*f[x][y-1]*x%mo*y%mo);
	}
	printf("%d\n",f[c[0]][c[1]]);
	return 0;
}











