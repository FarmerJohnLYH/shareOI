#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1e8+10;
int bz[N],n,p[N],p0;
int mu[N];
void init(int n)
{
	int cnt=0;
	bz[1]=1;mu[1]=1;
	fo(i,2,n)
	{
		if(!bz[i]) p[++p0]=i,mu[i]=-1;
		fo(j,1,p0)
		{
			if(1ll*i*p[j]>n) break;
			bz[i*p[j]]=1;
			if(i%p[j]==0) 
			{
				mu[i*p[j]]=0;
				break;
			}else mu[i*p[j]]=mu[i]*mu[p[j]];
		}
		if(mu[i]!=0)
			++cnt;
	}
	printf("%d\n",cnt);
}
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	init(1e7);
	return 0;
}








