#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
#define fd(i,x,y) for (ll i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const ll N=100100;
ll n;
ll b[N],a,ans[N];
vector<ll> c[66];
ll fi(ll x)
{
	fd(j,60,0)
	if(x&(1ll<<j))
		return j;
	return 0;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%I64d",&n);
	fo(i,1,n) 
	{
		scanf("%I64d",&b[i]);
		c[fi(b[i])].push_back(b[i]);
		a^=b[i];
	}
	fo(i,1,n)
	{
		ll fl=-1,tp;
		fo(l,0,60)
		if(((1ll<<l)&a) && (tp=c[l].size()))
		{
			ll g=c[l][tp-1];c[l].pop_back();
			a^=g;
			fl=l;
			ans[n-i+1]=g;
			break;
		}
		if(fl<0)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	fo(i,1,n)
	{
		printf("%I64d ",ans[i]);
	}
	return 0;

}











