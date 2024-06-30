#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=10010;
int n,ans;
int f[N],sum[N];
int bz[N],p[N],p0;
int bc[N],sm[N];
void init(int n)
{
	bz[1]=1,p0=0;bc[1]=1;
	sum[1]=1;
	fo(i,2,n)
	{
		if(!bz[i])
		{
			p[++p0]=i;
			sm[i]=sum[i]=i+1;
			bc[i]=i;
		}
		fo(j,1,p0)
		{
			if(1ll*p[j]*i>n)break;
			bz[p[j]*i]=1;
			if(i%p[j]==0)
			{
				bc[p[j]*i]=bc[i]*p[j];sm[p[j]*i]=sm[i]+bc[p[j]*i];
				sum[p[j]*i]=sum[i]*(sm[i*p[j]])/(sm[i]);
				break;
			}
			bc[p[j]*i]=p[j];sm[p[j]*i]=1+bc[p[j]*i];
			sum[p[j]*i]=sum[i]*(sm[i*p[j]]);	
		}
	}
}
int main()
{
//	freopen("D:/LiuYuanhao/a.in","r",stdin);
	scanf("%d",&n);
	init(n);
	fo(i,1,n) sum[i]-=i;
	fo(i,1,n) fd(j,n,1)
	{
		if(j>=i)f[j]=max(f[j],f[j-i]+sum[i]);
		ans=max(ans,f[j]);
	}
	printf("%d\n",ans);
	return 0;
}
