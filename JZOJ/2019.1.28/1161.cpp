#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=1010,mo=10000;
int n,k,p[N],e[N];
int all;
int gcd(int x,int y)
{
	return(y==0)?x:(gcd(y,x%y));
}
int qsm(int x,int y)
{
	int rt=1;
	if(gcd(x,mo)==1)y%=4000;
	fo(i,0,11)
	{
		if(y&(1<<i)) 
			rt=(rt*x)%mo;
		x=(x*x)%mo;
	}
	return rt;
}
int f[N];
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&k);
	all=1;
	fo(i,1,k)
	{
		++n;
		scanf("%d%d",&p[n],&e[n]);
		all=(all*qsm(p[n],e[n]))%mo;	
		if(p[n]==2) --n;
	}
	f[0]=1;
	fo(i,1,n) fd(j,n,1)
		f[j]=(f[j]+f[j-1]*(p[i]-1))%mo;
	int ans[2];ans[0]=ans[1]=0;
	fo(i,1,n)ans[i&1]=(ans[i&1]+f[i])%mo;
	printf("%d\n%d\n%d\n",ans[0],ans[1],(all-1-ans[0]-ans[1]+mo*10)%mo);
	return 0;
}











