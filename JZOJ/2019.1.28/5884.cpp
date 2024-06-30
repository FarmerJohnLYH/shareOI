#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=1001000;
int mo,n;
int a[N],b[N],c[N];
int ans[N];
int qsm(int x,int y)
{
	int rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=1ll*rt*x%mo;
		x=1ll*x*x%mo;
	}
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/c.in","r",stdin);	
//	freopen("D:/LiuYuanHao/c.out","w",stdout);						
	 freopen("dandelion.in","r",stdin);								
	 freopen("dandelion.out","w",stdout);
	scanf("%d",&mo);
	while(1)
	{
		++n;
		if(scanf("%d%d",&a[n],&c[n])==EOF)
			break;
	}--n;
	fd(i,n-1,1)
	{
		ans[i]=b[i+1]^c[i+1];
		b[i]=qsm(a[i],ans[i]);
	}
	fo(i,1,n-1) printf("%d\n",ans[i]);
	return 0;
}








