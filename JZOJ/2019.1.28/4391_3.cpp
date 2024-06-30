#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=220,mo=1e9+7;
int f[2][N][N][3];
int a,b,c,m,o;
int main()
{
//	freopen("D:/LiuYuanHao/b.in","r",stdin);  
	scanf("%d%d%d%d",&m,&a,&b,&c);
	a=m-a,b=m-b,c=m-c,o=0;
	f[o][0][0][0]=1,f[o][0][0][1]=1,f[o][0][0][2]=1;
	fo(i,1,m)
	{
		o=1^o;
		memset(f[o],0,sizeof f[o]);
		fo(x,0,a) fo(y,0,b)
		{
			int z=i-x-y;
			if(z>=0)
			fo(l,0,2) fo(lp,0,2)
			if(lp!=l&&(x-(l==0))>=0&&(y-(l==1))>=0&&(z-(l==2))>=0)
				(f[o][x][y][l]+=f[o^1][x-(l==0)][y-(l==1)][lp])%=mo;
		}
	}
	int ans=0;
	fo(i,0,2) (ans+=f[o][a][b][i])%=mo;
	printf("%d\n",ans);
	return 0;
}











