#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1001000;
int n,a[N],fi[N];
int f[N],flag;
ll ans;
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("building.in","r",stdin);
	freopen("building.out","w",stdout);
	memset(fi,255,sizeof fi);
	scanf("%d",&n);--n;
	fo(i,1,n) scanf("%d",&a[i]);
	ans=1;fi[0]=0;
	fo(i,1,n)
	{
		f[i]=max(a[i]+1,f[i-1]);
		if(fi[a[i]]==-1)fi[a[i]]=i;
		if(fi[a[i]-1]==-1) 
		{
			if(fi[a[i]-2]==-1)
				flag=1;
			if(flag)
			{
				printf("0\n");
				return 0;
			}
			flag=1;
			fi[a[i]-1]=0;
			ans=i-fi[a[i]-2];
		}
		if(!flag)
		{
			ans=ans+f[i];
			if(a[i+1]<=f[i]) --ans;
		}
	}
	printf("%lld\n",ans);
	return 0;
}











