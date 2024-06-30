#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=100010000;
int n;
ll p[N],p0;
int bz[N];
void judge(ll x)
{
	fo(i,1,p0)
	{
		if(p[i]>x)break;
		while(x%p[i]==0) 
		{
			printf("%lld ",p[i]);
			x/=p[i];	
		}
	}
	if(x!=1) printf("%lld\n",x);
}
ll abs(ll x)
{
	return(x>0)?x:(-x);
}
int main()
{
	// freopen("D:/LiuYuanHao/c.in","r",stdin);
	freopen("D:/LiuYuanHao/c.ans","w",stdout);
	n=1e8;
	bz[1]=1;
	fo(i,2,n)
	{
		if(!bz[i]) p[++p0]=i;
		fo(j,1,p0)
		{
			if(p[j]*i>=N)break;
			bz[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
	fo(i,1,p0)
	{
		if(p[i]>=4e6&&p[i]-4e6<=1e6
			)
			printf("%lld\n",p[i]);
	}
	printf("\n");
	return 0;
}








