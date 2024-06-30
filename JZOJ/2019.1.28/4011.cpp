#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=500500;
ll a[N];
int n,bz[N];
ll ans;
int main()
{
	// freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	fd(i,n,1)
	if(!bz[i])
	{
		bz[i]=1;
		fd(j,i-1,1)
		if(a[j]!=a[i])
		{
			bz[j]=1;
			break;
		}
		ans+=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}











