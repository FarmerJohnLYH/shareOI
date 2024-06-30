#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define ll long long
using namespace std;
ll n,m,q,p;
ll ans;
int main()
{
	// freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%lld",&n);ans=m=n;
	fo(i,2,sqrt(n))
	if(n%i==0)
	{
		m=m/i*(i-1);
		while(n%i==0) n/=i;
	}
	if(n>1) m=m/n*(n-1);
	ans=ans*(m/2);
	printf("%lld\n",ans);
	return 0;
}











