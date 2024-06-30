#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1001000;
int n,a[N];
int b[N];
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("farm.in","r",stdin);
	freopen("farm.out","w",stdout);
	scanf("%d\n",&n);
	fo(i,1,n) 
	{
		scanf("%d",&a[i]);a[i]+=a[i-1];
		b[a[i]]=1;
	}
	fo(i,1,a[n])
	if(a[n]%i==0&&b[i])
	{
		int j=i,flag=1;
		while(j+i<=n) 
		{
			if(!b[j+=i])flag=0;
			if(!flag)break;
		}
		if(flag)
		{
			printf("%d\n",a[n]/i);
			return 0;
		}
	}
	return 0;
}











