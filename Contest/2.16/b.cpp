#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=500500,mo=1e9+7;
ll n,k,q,a[N];
ll qsm(ll a,ll b)
{
	ll rt=1;
	while(b)
	{
		if(b&1) rt=rt*a%mo;
		a=a*a%mo;b/=2;
	}
	return rt;
}
int main()
{
	// freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%lld%lld%lld",&n,&k,&q);
	ll ans=qsm(qsm(2,q),(n*(n-1)-1)%(mo-1));
	printf("%lld\n",ans);
	return 0;
}








