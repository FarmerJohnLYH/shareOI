#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=110,mo=10007;
int n,m,s;
int f[N][N][110];
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("greedhead.in","r",stdin);
	freopen("greedhead.out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	f[1][1][0]=1;
	fo(i,1,n) fo(j,1,m)
	fo(k,0,s)
	{
		if(i==1&&j==1) continue;
		fo(l,0,k)
		{
			if(j==m) f[i][j][k]=(f[i][j][k]+f[i-1][j][k-l])%mo;
			else f[i][j][k]=(f[i][j][k]+f[i-1][j][k-l]*l)%mo; 
			if(i==n) f[i][j][k]=(f[i][j][k]+f[i][j-1][k-l])%mo;
			else f[i][j][k]=(f[i][j][k]+f[i][j-1][k-l]*(l+1))%mo; 
		}
	}
	printf("%d\n",f[n][m][s]);
	return 0;
}











