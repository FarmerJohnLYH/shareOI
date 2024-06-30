#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100;
int n;
int p[N],bz[N];
int p0;
void init(int n)
{
	bz[1]=1;
	fo(i,2,n)
	{
		if(!bz[i]) p[++p0]=i;
		fo(j,1,p0)
		{
			if(1ll*p[j]*i>n) break;
			bz[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
int check(int x)
{
	fo(i,1,p0)
	{
		if(1ll*p[i]*p[i]>x) break;
		while(x%p[i]==0)
		{
			printf("%d ",p[i]);
			x/=p[i];		
		}
	}
	if(x>1) printf("%d ",x);
	printf("\n\n");
}
int main()
{
	// freopen("D:/LiuYuanHao/","r",stdin);
	init(N-10);
	check(437367875);
	check(262203414);
	check(10007);
	return 0;
}











