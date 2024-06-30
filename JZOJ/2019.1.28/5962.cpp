#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=110,M=25025;
int a[N],f[M];
int n,T,ans,m;
int main()
{
	// freopen("D:/LiuYuanHao/a.in","r",stdin);
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		m=ans=0;
		scanf("%d",&n);
		fo(i,1,n) scanf("%d",&a[i]),m=max(m,a[i]);
		sort(a+1,a+1+n);
		fo(i,1,m) f[i]=0;
		f[0]=1;
		fo(i,1,n)
			if(!f[a[i]]) 
			{
				++ans;
				fo(j,a[i],m) f[j]|=f[j-a[i]];
			}
		printf("%d\n",ans);
	}
	return 0;
}








