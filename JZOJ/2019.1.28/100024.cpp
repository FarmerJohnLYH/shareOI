#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1010;
int n,m;
int f[N][N];
int main()
{
//	 freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);printf("%d\n",n-2);
	f[1][0]=2;f[2][0]=3;
	f[1][1]=1,f[1][2]=2;
	f[2][1]=1,f[2][2]=3,f[2][3]=4;
	m=4;
	if((n&1))
	{
		++m;
		f[m-2][0]=4;	
		f[m-2][1]=2,f[m-2][2]=3,f[m-2][3]=4,f[m-2][4]=5;
	}
	for(;m<n;)
	{
		m+=2;
		f[m-3][f[m-3][0]=1]=m-1;
		fo(i,1,m-3)
			f[i][++f[i][0]]=m;
		fo(i,1,m-1) f[m-2][++f[m-2][0]]=i;
	}
	fo(i,1,m-2)
	{
		printf("%d ",f[i][0]);
		fo(j,1,f[i][0]) printf("%d ",f[i][j]);
		printf("\n");
	}
	return 0;
}











