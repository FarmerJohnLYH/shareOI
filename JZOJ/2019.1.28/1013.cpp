#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1e9+100;
ll d,lm;
ll c,ans;
ll gcd(ll x,ll y)
{
	return(y==0)?(x):(gcd(y,x%y));
}
int main()
{
	// freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%lld%lld",&d,&lm);c=d*lm;
	ans=724189742189435ll;
	for(ll a=d;a*a<=c;a+=d)
	{
		if(c%a==0&&gcd(c/a,a)==d)
			ans=min(ans,(c/a)-a);
	}
	printf("%lld\n",ans);
	return 0;
}











