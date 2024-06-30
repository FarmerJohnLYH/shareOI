#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=40040;
int p[N],bz[N];
int n,phi[N],p0,al[N];
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	bz[1]=1;
	fo(i,2,n)
	{
		if(!bz[i]) p[++p0]=i,phi[i]=i-1;		
		fo(j,1,p0)
		{
			if(i*p[j]>n)break;
			bz[i*p[j]]=1;
			if(i%p[j]==0)
			{
				phi[p[j]*i]=p[j]*phi[i];
				break;
			}else phi[p[j]*i]=phi[p[j]]*phi[i];
		}
	}
	int ans=0;
	fo(i,1,n-1) ans+=phi[i];
	printf("%d\n",ans*2+3);
	return 0;
}











